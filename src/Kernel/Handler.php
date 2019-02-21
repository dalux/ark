<?php

namespace Brisk\Kernel;

use Exception;

class Handler
{

    /**
     * Set system exception handling handle
     *
     * @param mixed $handler
     * @return null
     */
    public static function setHandler(callable $handler = null)
    {
        if (is_null($handler)) {
            $handler = [new Handler(), 'display'];
        }
        restore_exception_handler();
        set_exception_handler($handler);
    }

    /**
     * Rendering system Exception Trace information
     *
     * @param Exception $e
     * @return null
     */
    public function display(Exception $e)
    {
        //错误信息
		$message = $e->getMessage();
		$is_cli = Server::isCli();
		$eol = $is_cli ? PHP_EOL : '<br/>';
        //底部信息
        $footerinfo = ' Provider by '. App::NAME. ' '. App::VERSION;
        $exception_name = get_class($e);
        $namespaces = array_keys(Loader::getNameSpace());
        usort($namespaces, function($a, $b) {
            return strlen($a) > strlen($b) ? $a : $b;
        });
		$exception_name = explode('\\', $exception_name);
        foreach ($exception_name as $k=> $v) {
			$exception_name[$k] = ucfirst($v);
		}
        $exception_name = implode('.', $exception_name);
		$content = '';
        //跟踪信息
        if (!$is_cli) {
			$trace_array = $e->getTrace();
            $trace_string = explode(PHP_EOL, $e->getTraceAsString());
            $trace = [];
            /*
            $trace[] = [
                'description'=> $e->getFile(). '('. $e->getLine(). '):',
                'source'=> $this->_getSource(['file'=> $e->getFile(), 'line'=> $e->getLine()])
            ];
            */
            foreach ($trace_array as $k=> $v) {
                $trace[] = [
                    'description'=> $trace_string[$k],
					'source'=> $this->_getSource($v),
                ];
            }
            $trace[] = ['description'=> '[main]', 'source'=> '0001: [internel]'];
            $stack_trace = '';
            $max = count($trace);
            foreach ($trace as $k=> $v) {
                $v['description'] = Loader::reducePath($v['description']);
                $v['description'] = preg_replace_callback('/(?<=\)[\:]\s).*?(?=[\:\-])/', function($matched) {
                    return str_replace('/', '\\', $matched[0]);
                }, $v['description']);
                $v['description'] = sprintf('%02d: %s', $max, trim(preg_replace('~^#\d+~', '', $v['description'])));
                $stack_trace = $stack_trace. '<div id="trace_title_'. ($k+1). '" class="trace_title" title="点击可显示或折叠具体代码" onclick="codeview(\'trace_source_'. $k. '\')">'. $v['description']. '</div>';
                $stack_trace.= '<div id="trace_source_'. $k. '" class="trace_source"';
                //if ($k == 0) {
                //    $stack_trace.= ' style="display:block"';
                //}
                $stack_trace.= '>'. $v['source']. '</div>';
                $max = $max - 1;
            }
            //模板文件
            $debug = App::init()->config->get('global/debug');
            $tplcontent = $this->_getWebTpl2();
            if ($debug || is_null($debug)) {
                $content = str_replace(['{detail}', '{/detail}'], '', $tplcontent);
            } else {
                $content = preg_replace('/{detail}[\\s\\S]*?{\\/detail}/i', 'Traceback cannot be displayed in non-debug mode.', $tplcontent);
            }
            $content = str_replace('{e}', $exception_name, $content);
            $content = str_replace('{description}', $message, $content);
            $content = str_replace('{stacktrace}', $stack_trace, $content);
            $content = str_replace('{footerinfo}', $footerinfo, $content);
        } else {
            $trace_array = $e->getTrace();
            $trace_string = explode(PHP_EOL, $e->getTraceAsString());
            $trace = [];
            foreach ($trace_array as $k=> $v) {
                $trace[] = $trace_string[$k];
            }
            $trace[] = '{main}';
            $max = count($trace);
            $stack_trace = '';
            foreach ($trace as $k=> $v) {
                $v = Loader::reducePath($v);
                $v = preg_replace_callback('/(?<=\)[\:]\s).*?(?=[\:\-])/', function($matched) {
                    return str_replace('/', '\\', $matched[0]);
                }, $v);
                $trace[$k] = $v;
                $trace[$k] = sprintf('%02d: %s', $max, trim(preg_replace('~^#\d+~', '', $v)));
                $max -= 1;
            }
            $stack_trace = implode(PHP_EOL, $trace);
            //模板文件
            $tplcontent = $this->_getCliTpl();
			$content = str_replace(['{detail}', '{/detail}'], '', $tplcontent);
            $content = str_replace('{e}', $exception_name, $content);
            $content = str_replace('{description}', $message, $content);
            $content = str_replace('{stacktrace}', $stack_trace, $content);
            $content = str_replace('{footerinfo}', $footerinfo, $content);
        }

        echo $content;
        exit;

    }

    /**
     *
     * @param array $trace
     * @return string
     */
    private function _getSource(array $trace)
    {
        $source = '';
        $trace_file = $trace['file'];
        if ($trace_file) {
            $line = $trace['line'];
            $lines = file($trace_file);
            $lines_offset = 8;
            $b_line = max(($line - $lines_offset - 1), 0);
            $e_line = min(($line + $lines_offset), count($lines));
            foreach (range($b_line, $e_line) as $i) {
                if ($i == ($line - 1)) {
                    $source = $source. '<div class="error">' . htmlspecialchars(sprintf('%04d: %s', $i+1, str_replace('\t', '    ', $lines[$i]))) . '</div>';
                } else {
                    $source = $source. htmlspecialchars(sprintf('%04d: %s', $i+1, str_replace('\t', '    ', $lines[$i])));
                }
            }
        }
        return $source;
    }

    private function _getWebTpl2()
    {
        $str = '<!DOCTYPE html><html><head>';
        $str.= '<meta http-equiv="Content-Type" content="text/html;charset=utf-8" />';
        $str.= '<title>Brisk debugger</title>';
        $str.= '<style>';
        $str.= 'body { font-family: "Ubuntu", "Lucida Grande", "Lucida Sans Unicode", "Geneva", "Verdana", sans-serif; }';
        $str.= 'h1 { font-size: 36px; margin: 0 0 0.3em 0; display: block; font-size: 2em; font-weight: bold; }';
        $str.= 'h2 { font-size: 16px; font-weight: normal; margin: 1.3em 0 0.0 0; padding: 9px; background-color: #11557C; color: white; }';
        $str.= 'div.detail p { margin: 0 0 8px 0px; font-size: 14px; white-space: pre-wrap; font-family: monospace; color: red; }';
        $str.= 'div.debugger { text-align: left; padding: 12px; margin: auto; background-color: white; }';
        $str.= 'div.traceback { border: 1px solid #ddd; line-height: 140%; font-size: 15px; margin: 0 0 1em 0; padding:15px; }';
        $str.= 'div.footer { font-size: 13px; text-align: left; margin: 15px 0; color: #444; }';
        $str.= 'pre { margin: 0; }';
        $str.= '.trace_title { cursor: pointer; }';
        $str.= '.error { color: red;}';
        $str.= '.trace_source { background-color:#f2f2f2; padding: 8px; display:none; font-size: 14px; }';
        $str.= '</style>';
        $str.= '<script>';
        $str.= 'function codeview(id) {';
        $str.= 'var target = document.getElementById(id);';
        $str.= 'var isopen = target.style.display == "block";';
        $str.= 'target.style.display = isopen ? "none" : "block";';
        $str.= '}';
        $str.= '</script>';
        $str.= '</head>';
        $str.= '<body>';
        $str.= '<div class="debugger">';
        $str.= '<h1>{e}</h1>';
        $str.= '<div class="detail"><p class="errormsg">{description}</p></div>';
        $str.= '<h2 class="traceback">Traceback</h2>';
        $str.= '<div class="traceback">{detail}<code><pre>{stacktrace}</pre></code>{/detail}</div>';
        $str.= '<div class="footer">{footerinfo}</div>';
        $str.= '</div>';
        $str.= '</body>';
        $str.= '</html>';
        return $str;
    }

    /**
     *
     * @return string
     */
    private function _getWebTpl1()
    {
        $str = '<!Doctype html><html><head><title>Debugger</title>';
        $str.= '<style type="text/css">';
		$str.= 'body {font-family:Courier New,Tahoma;font-weight:normal;color:black;background-color:white;}';
		$str.= 'h1 {font-size:18pt;color:red;font-family:Tahoma,Courier New,sans-serif; padding-bottom: 12px; }';
        $str.= 'h2 {font-size:14pt;color:maroon }';
        $str.= 'h3 {font-weight:bold;font-size:10pt;margin:20px 0;font-family:Tahoma,sans-serif; }';
        $str.= 'p {color:black;font-size:9pt;margin-top:-5px; }';
        $str.= 'code,pre {font-family:Courier New;font-size:9pt;}';
        $str.= 'td,.version {color:gray;font-size:8pt;border-top:1px solid #aaaaaa;padding-top:3px;}';
        $str.= '.source {background-color:#ffffee;}';
        $str.= '.error {background-color: #ffeeee;}';
        $str.= '.trace_title { cursor: pointer; }';
        $str.= '.trace_source { background-color:#fff; padding: 8px; display:none; }';
        $str.= '</style>';
        $str.= '<script>';
        $str.= 'function codeview(id) {';
        $str.= 'var target = document.getElementById(id);';
        $str.= 'var isopen = target.style.display == "block";';
        $str.= 'target.style.display = isopen ? "none" : "block";';
        $str.= '}';
        $str.= '</script>';        
		$str.= '</head>';
		$str.= '<body>';
		$str.= '<h1>{e}</h1>';
		$str.= '<h3>Description: </h3>';
        $str.= '<p style=color:maroon>{description}</p>';
        $str.= '<h3>Backtrace: </h3>';
        $str.= '<div class=source><code><pre>{detail}{stacktrace}{/detail}</pre></code></div>';
        $str.= '<div class=version>';
        $str.= '{footerinfo}';
        $str.= '</div></body></html>';
        return $str;
    }

    /**
     *
     * @return string
     */
    private function _getCliTpl()
    {
        $str = PHP_EOL. '======= {e} ===================================='. PHP_EOL. PHP_EOL;
		$str.= 'Description: '. PHP_EOL;
		$str.= '{description}'. PHP_EOL. PHP_EOL;
		$str.= 'Backtrace: '. PHP_EOL;
		$str.= '{stacktrace}'. PHP_EOL. PHP_EOL;
		$str.= '{footerinfo}'. PHP_EOL. PHP_EOL;
        return $str;
    }

}