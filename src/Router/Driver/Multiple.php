<?php

namespace Ark\Router\Driver;

use Ark\Core\Captain;
use Ark\Http\Request;
use Ark\Router\Driver as RouterDriver;

class Multiple extends RouterDriver
{

    /**
     * 准备请求数据
     *
     * @return null
     */
	function ready()
	{
        //定义常量
        $debug_trace = debug_backtrace();
        $caller = current(end($debug_trace));
        define('PATH_NOW', dirname($caller));
        //请求数据初始化完成
        Request::$ready = true;
        Captain::getInstance()->set('request', function() { return Request::getInstance(); });
	}

    /**
     * 路由调度
     *
     */
	function dispatch()
	{
        //自动加载目录下引导文件
        $interceptor = Captain::getInstance()->config->router->interceptor;
        if ($interceptor) {
            //获取目录树
            $path_nodes = array(PATH_NOW);
            if (PATH_NOW != PATH_CTRL) {
                $curr_path = PATH_NOW;
                while (($curr_path = dirname($curr_path))
                        && strlen($curr_path) >= strlen(PATH_CTRL)) {
                    $path_nodes[] = $curr_path;
                }
            }
            $path_nodes = array_reverse(array_unique($path_nodes));
            //加载每个目录下的默认拦截器文件
            foreach ($path_nodes as $node) {
                $file = $node . DIRECTORY_SEPARATOR . $interceptor;
                if (is_file($file)) {
                    chdir(dirname($file));
                    $output = include_once($file);
                    if (is_string($output)) { echo $output; exit;}
                }
            }
            chdir(PATH_NOW);    //还原默认目录位置
        }
	}

}