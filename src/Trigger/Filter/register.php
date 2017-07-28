<?php

use Ark\Core\Event;
use Ark\Core\Exception;

return function() {

    //请求初始化时过滤攻击威胁
    Event::addListener('event.request.ready', function($data) {
        foreach ($data as $key=> $val) {
            $pattern = '';
            switch($key) {
                case 'get':
                    $pattern = "'|(and|or)\\b.+?(>|<|=|in|like)|\\/\\*.+?\\*\\/|<\\s*script\\b|\\bEXEC\\b|UNION.+?Select|Update.+?SET|Insert\\s+INTO.+?VALUES|(Select|Delete).+?FROM|(Create|Alter|Drop|TRUNCATE)\\s+(TABLE|DATABASE)" ;
                    break;
                case 'post':
                    $pattern = "\\b(and|or)\\b.{1,6}?(=|>|<|\\bin\\b|\\blike\\b)|\\/\\*.+?\\*\\/|<\\s*script\\b|\\bEXEC\\b|UNION.+?Select|Update.+?SET|Insert\\s+INTO.+?VALUES|(Select|Delete).+?FROM|(Create|Alter|Drop|TRUNCATE)\\s+(TABLE|DATABASE)";
                    break;
                case 'cookie':
                    $pattern = "\\b(and|or)\\b.{1,6}?(=|>|<|\\bin\\b|\\blike\\b)|\\/\\*.+?\\*\\/|<\\s*script\\b|\\bEXEC\\b|UNION.+?Select|Update.+?SET|Insert\\s+INTO.+?VALUES|(Select|Delete).+?FROM|(Create|Alter|Drop|TRUNCATE)\\s+(TABLE|DATABASE)";
                    break;
            }
            if ($pattern) {
                foreach ($val as $k => $v) {
                    if (preg_match("/$pattern/is", $v)) {
                        throw new Exception(sprintf('无效的%s参数:[%s],IP已记录,请勿尝试注入', strtoupper($key), $k));
                    }
                }
            }
        }
        return $data;
    }, 'request.filter');

};