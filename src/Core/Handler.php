<?php

namespace Ark\Core;

class Handler
{

    /**
     * 异常类型句柄
     *
     * @var int
     */
    const TYPE_EXCEPTION = 1;

    /**
     * 获取异常处理句柄对象
     *
     * @access public
     * @static
     * @param $type
     * @param array $handler example: array(new \Exception(), 'display')
     */
    static function setHandler($type, $handler = null)
    {
        if ($type == self::TYPE_EXCEPTION) {
            restore_exception_handler();
            if (is_null($handler) || !is_callable($handler)) {
                $handler = array(new self(), 'display');
            }
            set_exception_handler($handler);
        }
    }

    /**
     * 根据传入的跟踪信息取得程序源代码
     *
     * @access private
     * @param array $trace
     * @return string
     */
    private function _getSource(array $trace)
    {
        $source = '';
        if ($file = $trace['file']) {
            $line = $trace['line'];
            $lines = file($file);
            $lines_offset = 8;
            $b_line = max($line - $lines_offset-1, 0);
            $e_line = min($line + $lines_offset, count($lines));
            for ($i = $b_line; $i < $e_line; $i++) {
                $source .= ($i === $line-1)
                    ? '<div class="error">' . htmlspecialchars(sprintf("%04d：%s", $i+1, str_replace("\t", "    ", $lines[$i]))) . '</div>'
                    : htmlspecialchars(sprintf("%04d：%s", $i+1, str_replace("\t", "    ", $lines[$i])));

            }
        }
        return $source;
    }

    /**
     * 显示异常调试信息
     *
     * @access public
     * @static
     * @param \Throwable $e
     * @return string
     */
    function display($e)
    {
        //错误信息
        $message = $e->getMessage();
        //包含文件
        $includes = '';
        foreach (get_included_files() as $k=> $v) {
            $includes.= sprintf("#%02d：%s\r\n", $k+1, str_replace("\t", "    ", Loader::reducePath($v)));
        }
        //底部信息
        $footerinfo = strftime('%Y-%m-%d %H:%M:%S', time());
        if (isset($_SERVER['SERVER_SOFTWARE'])) {
            $footerinfo.= ' '. $_SERVER['SERVER_SOFTWARE'];
        }
        $footerinfo.= ' Provider by Ark.';
        $exception_name = get_class($e);
        $namespaces = array_keys(Loader::getNameSpace());
        usort($namespaces, function($a, $b) {
            return strlen($a) > strlen($b) ? $a : $b;
        });
        $exception_name = array_map(function($item) {
            return ucfirst($item);
        }, explode('_', $exception_name));
        $exception_name = implode('.', $exception_name);
        //跟踪信息
        if (!Server::isCli()) {
            $trace_array = $e->getTrace();
            $trace_string = explode("\n", $e->getTraceAsString());
            $trace = array();
            foreach ($trace_array as $k=> $v) {
                $trace[] = array(
                    'description'=> $trace_string[$k],
                    'source'=> $this->_getSource($v)
                );
            }
            $trace[] = array('description'=> '{main}', 'source'=> '0001：[internel]');
            $stack_trace = '';
            $max = count($trace);
            foreach ($trace as $k=> $v) {
                $v['description'] = Loader::reducePath($v['description']);
                $v['description'] = sprintf("#%02d：%s", $max, trim(preg_replace('/^\#\d+/', '', $v['description'])));
                $stack_trace.= '<div id="trace_title_'. ($k+1). '" class="trace_title" title="点击可显示或折叠具体代码" onclick="codeview(\'trace_source_'. $k. '\')">'. $v['description']. '</div>';
                $stack_trace.= '<div id="trace_source_'. $k. '" class="trace_source"';
                $stack_trace.= '>'. $v['source']. '</div>';
                $max -= 1;
            }
            //模板文件
            $tplcontent = $this->_getWebTpl();
            if (Core::getInst()->config->global->debug) {
                $content = str_replace(array('<{detail}>', '<{/detail}>'), '', $tplcontent);
            } else {
                $content = preg_replace("/\\<\\{detail\\}\\>[\\s\\S]*?\\<\\{\\/detail\\}\\>/", '', $tplcontent);
            }
            $content = str_replace('<{e}>', $exception_name, $content);
            $content = str_replace('<{description}>', $message, $content);
            $content = str_replace('<{stacktrace}>', $stack_trace, $content);
            $content = str_replace('<{includefiles}>', $includes, $content);
            $content = str_replace('<{footerinfo}>', $footerinfo, $content);
        } else {
            $stack_trace = Loader::reducePath($e->getTraceAsString());
            //模板文件
            $tplcontent = $this->_getCliTpl();
            $content = str_replace(array('<{detail}>', '<{/detail}>'), '', $tplcontent);
            $content = str_replace('<{e}>', $exception_name, $content);
            $content = str_replace('<{description}>', $message, $content);
            $content = str_replace('<{stacktrace}>', $stack_trace, $content);
            $content = str_replace('<{includefiles}>', $includes, $content);
            $content = str_replace('<{footerinfo}>', $footerinfo, $content);
        }

        echo $content;
        exit;

    }

    private function _getWebTpl()
    {
        $str = <<<str
<!Doctype html>
<html>

    <head>
        <title>Debugger</title>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <style type="text/css">
        body {font-family:Courier New,Tahoma;font-weight:normal;color:black;background-color:white;}
        h1 {font-size:18pt;color:red;font-family:微软雅黑,Courier New,Tahoma,sans-serif; padding-bottom: 12px; }
        h2 {font-size:14pt;color:maroon }
        h3 {font-weight:bold;font-size:10pt;margin:20px 0;font-family:微软雅黑,Tahoma,sans-serif; }
        p {color:black;font-size:9pt;margin-top:-5px; }
        code,pre {font-family:Courier New;font-size:9pt;}
        td,.version {color:gray;font-size:8pt;border-top:1px solid #aaaaaa;padding-top:3px;}
        .source {background-color:#ffffee;}
        .error {background-color: #ffeeee;}
        .trace_title { cursor: pointer; }
        .trace_source { background-color:#fff; padding: 8px; display:none; }
        </style>
        <script>
        function codeview(id)
        {
            var target = document.getElementById(id);
            var isopen = target.style.display == 'block';
            target.style.display = isopen ? 'none' : 'block';
        }
        </script>
    </head>

    <body>

        <h1><{e}></h1>

        <h3>Description：</h3>
        <p style="color:maroon"><{description}></p>
        <{detail}>

        <h3>Backtrace：</h3>
        <div class="source"><code><pre><{stacktrace}></pre></code></div>

        <h3>Include files：</h3>
        <div class="source"><code><pre><{includefiles}></pre></code></div>
        <{/detail}>
        <div class="version">
        <{footerinfo}>
        </div>

    </body>

</html>
str;
        return $str;
    }

    private function _getCliTpl()
    {
        $str = <<<str

====== <{e}> ======

Description：

<{description}>

Backtrace：

<{stacktrace}>

Include files：

<{includefiles}>
<{footerinfo}>


str;
        return $str;

    }

}