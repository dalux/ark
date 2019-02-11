<?php

namespace Brisk\Router\Driver;

use Brisk\Kernel\App;
use Brisk\Kernel\Loader;
use Brisk\Kernel\Request;
use Brisk\Router\RouterFather;

class Native extends RouterFather
{

    /**
     * Routing ready
     *
     * @return void
     */
    public function ready()
    {
        Request::ready($_GET);
    }

    /**
     * Routing path distribution
     *
     * @return void
     */
    public function dispatch()
    {
        //自动加载目录下引导文件
        $trace = debug_backtrace();
        $caller = current(end($trace));
        $path_now = dirname($caller);
        $auto_include = null;
        if (App::init()->config->hasKey('router/option/auto_include')) {
            $auto_include = App::init()->config->get('router/option/auto_include');
        }
        if (!is_null($auto_include)) {
            //获取目录树
            $path_nodes = [$path_now];
            $path_root = rtrim(Loader::realPath('./'), DIRECTORY_SEPARATOR);
            if ($path_now != $path_root) {
                $curr_path = $path_now;
                while (true) {
                    $curr_path = dirname($curr_path);
                    if (strlen($curr_path) < strlen($path_root)) {
                        break;
                    }
                    $path_nodes[] = $curr_path;
                }
            }
            $path_nodes = array_reverse(array_unique($path_nodes));
            //加载每个目录下的默认拦截器文件
            foreach ($path_nodes as $node) {
                $file = $node . DIRECTORY_SEPARATOR . $auto_include;
                if (is_file($file)) {
                    chdir(dirname($file));
                    $output = include($file);
                    if (is_string($output)) {
                        echo $output;
                        exit;
                    }
                }
            }
            chdir($path_now);    //还原默认目录位置
        }
    }

}