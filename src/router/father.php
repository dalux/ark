<?php

abstract class Ark_Router_Father implements Ark_Router_Contract
{

    /**
     * 控制器名称
     *
     * @var string
     */
    protected $_controller;

    /**
     * 路由是否就绪
     *
     * @var bool
     */
    protected $_ready = false;

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
     * @throws Ark_Router_Exception
     * @throws Exception
     */
    function dispatch()
    {
        global $ark;
        $config = Ark_Core::getInst()->config;
        //自动加载目录下引导文件
        if ($interceptor = $config->router->controller->interceptor) {
            if (basename($this->_controller) == $interceptor) {
                throw new Ark_Router_Exception(Ark_Language::get('router.controller_is_protected', $interceptor));
            }
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