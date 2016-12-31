<?php

namespace App\Controller;

class Index extends Init
{

    function index()
    {

        echo $this->querier->select('mysql')
            ->from('user', array('id', 'name', 'password', 'age'))
            ->joinLeft(array('user_detail'), 'user.id=user_detail.uid', array('account'))
            ->where('id=?', '123');

//        echo '欢迎使用Ark框架,有问题请咨询QQ:112183883';

    }

}