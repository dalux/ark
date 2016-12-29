<?php

namespace Ark\Contract;

interface CacheProxy
{

    /**
     * 缓存代理方法
     *
     * @access public
     * @param int $expire 缓存时间
     * @param null $name 缓存名称
     * @param CacheDriver $cache
     * @return object 缓存代理器
     */
    function cache($expire, $name, CacheDriver $cache);

}