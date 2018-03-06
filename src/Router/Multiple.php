<?php

class Ark_Router_Multiple extends Ark_Router_Father
{

    /**
     * 模块名称
     *
     * @var string
     */
    private $_module;

    /**
     * 控制器名称
     *
     * @var string
     */
    private $_controller;

    /**
     * 行为名称
     *
     * @var string
     */
    private $_action;

    /**
     * 路由状态
     *
     * @var bool
     */
    private $_ready = false;

    /**
     * 获取模块名称
     *
     * @return string
     */
    function getModule()
    {
        return $this->_module;
    }

    /**
     * 获取控制器名称
     *
     * @return string
     */
    function getController()
    {
        return $this->_controller;
    }

    /**
     * 获取控制器名称
     *
     * @return string
     */
    function getAction()
    {
        return $this->_action;
    }

    /**
     * 路由是否就绪
     *
     * @return mixed
     */
    function isReady()
    {
        return $this->_ready;
    }

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
        $this->_controller = str_replace(PATH_WEB, '', $caller);
        //请求数据初始化完成
        Ark_Request::setReady(true);
        Ark_Core::getInstance()->setMember('request', function() { return Ark_Request::getInstance(); });
        $this->_ready = true;
	}

    /**
     * 路由调度
     *
     */
	function dispatch()
	{
        $config = Ark_Core::getInstance()->config->router;
        $global_var = $config->global_var;
        if (!is_null($global_var) && !preg_match('/^[0-9]+/', $global_var)) {
            global ${$global_var};
            ${$global_var} = Ark_Core::getInstance();
        }
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

}