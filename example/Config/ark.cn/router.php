<?php

return array(
    'driver'=> 'base',
    'urlmode'=> \Ark\Com\Router\Driver\Base::URL_MODE_REWRITE,
    'urlsuffix'=> '',
    'urlsep'=> '/',
    'urlvar'=> array(
        'module'=> '_m',
        'controller'=> '_c',
        'action'=> '_a',
    ),
    'default'=> array(
        'module'=> '',
        'controller'=> 'index',
        'action'=> 'index',
    ),
);