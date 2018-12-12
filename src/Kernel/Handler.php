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
        //包含文件
        $includes = '';
		$included = get_included_files();
        foreach ($included as $k=> $v) {
            $includes = $includes. sprintf('#%02d: %s%s', ($k+1), str_replace('\t', '    ', Loader::reducePath($v)), $eol);
        }
        //底部信息
        $footerinfo = strftime('%Y-%m-%d %H:%M:%S', time());
        if (isset($_SERVER['SERVER_SOFTWARE'])) {
            $footerinfo = $footerinfo. (' '. $_SERVER['SERVER_SOFTWARE']);
        }
        $footerinfo = $footerinfo. ' Provider by '. App::NAME. ' '. App::VERSION;
        $exception_name = get_class($e);
        $namespaces = array_keys(Loader::getNameSpaces());
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
            foreach ($trace_array as $k=> $v) {
                $trace[] = [
                    'description'=> $trace_string[$k],
					'source'=> ''
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
                $v['description'] = sprintf('#%02d: %s', $max, trim(preg_replace('~^#\d+~', '', $v['description'])));
                $stack_trace = $stack_trace. '<div id=trace_title_'. ($k+1). ' class=trace_title>'. $v['description']. '</div>';
                $max = $max - 1;
            }
            //模板文件
            $debug = App::init()->config->get('global/debug');
            $tplcontent = $this->_getWebTpl();
            if ($debug || is_null($debug)) {
                $content = str_replace(['{detail}', '{/detail}'], '', $tplcontent);
            } else {
                $content = preg_replace('/{detail}[\\s\\S]*?{\\/detail}/i', '', $tplcontent);
            }
            $content = str_replace('{e}', $exception_name, $content);
            $content = str_replace('{description}', $message, $content);
            $content = str_replace('{stacktrace}', $stack_trace, $content);
            $content = str_replace('{includefiles}', $includes, $content);
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
                $trace[$k] = sprintf('#%02d: %s', $max, trim(preg_replace('~^#\d+~', '', $v)));
                $max = $max - 1;
            }
            $stack_trace = implode(PHP_EOL, $trace);
            //模板文件
            $tplcontent = $this->_getCliTpl();
			$content = str_replace(['{detail}', '{/detail}'], '', $tplcontent);
            $content = str_replace('{e}', $exception_name, $content);
            $content = str_replace('{description}', $message, $content);
            $content = str_replace('{stacktrace}', $stack_trace, $content);
            $content = str_replace('{includefiles}', $includes, $content);
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

    /**
     *
     * @return string
     */
    private function _getWebTpl()
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
        $str.= '.trace_source { background-color:#fff; padding: 8px; display:none; }';
        $str.= '</style>';
		$str.= '</head>';
		$str.= '<body>';
		$str.= '<h1>{e}</h1>';
		$str.= '<h3>Description: </h3>';
        $str.= '<p style=color:maroon>{description}</p>';
        $str.= '{detail}';
        $str.= '<h3>Backtrace: </h3>';
        $str.= '<div class=source><code><pre>{stacktrace}</pre></code></div>';
        $str.= '<h3>Include files: </h3>';
        $str.= '<div class=source><code><pre>{includefiles}</pre></code></div>';
        $str.= '{/detail}';
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
		$str.= 'Include files: '. PHP_EOL;
		$str.= '{includefiles}'. PHP_EOL;
		$str.= '{footerinfo}'. PHP_EOL. PHP_EOL;
        return $str;
    }

}