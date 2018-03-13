<?php

abstract class Ark_Router_Father implements Ark_Router_Contract
{

    /**
     * 路由数据准备
     *
     * @return mixed
     */
    abstract function ready();

    /**
     * 路由是否准备就绪
     *
     * @return bool
     */
    abstract function isReady();

    /**
     * 路由调度
     *
     * @return mixed
     */
    function dispatch()
    {
        $config = Ark_Core::getInstance()->config->router;
        //自动加载目录下引导文件
        if ($interceptor = $config->interceptor) {
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

    /**
     * 获取控制器名称
     *
     * @return mixed
     */
    abstract function getController();


}