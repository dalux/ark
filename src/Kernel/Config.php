<?php

namespace Brisk\Kernel;

class Config
{

    /**
     * 全局配置
     *
     * @var array
     */
    private static $_global = [
        'debug'=> true,
        'timezone'=> 'Asia/Shanghai',
        'error_reporting'=> E_ALL^E_NOTICE^E_WARNING^E_DEPRECATED
    ];

    /**
     * 路由配置，单选
     *
     * @var array
     */
    private static $_router = [
        'classic'=> [
            'driver'=> 'Brisk\Router\Driver\Classic',
            'option'=> [
				'base_namespace'=> 'App\Controller',
                'auto_method'=> '__init',
                'default_controller'=> 'Index',
                'default_action'=> 'index',
			    'url_suffix'=> '.html'
            ]
        ],
        'native'=> [
            'driver'=> 'Brisk\Router\Driver\Native',
            'option'=> [
                'auto_include'=> 'init.php'
            ]
        ],
        'rewrite'=> [
            'driver'=> 'Brisk\Router\Driver\Rewrite',
            'option'=> [
                'base_namespace'=> 'App\Controller',
                'auto_method'=> '__init',
                'default_controller'=> 'Index',
                'default_action'=> 'index',
                'url_suffix'=> '.html'
            ]
        ]
    ];

    /**
     * 会话配置，单选
     *
     * @var array
     */
    private static $_session = [
        'memcache'=> [
            'driver'=> 'Brisk\Session\Driver\Memcached',
            'option'=> [
                'config'=> [
                    'host'=> '127.0.0.1',
                    'port'=> 11211,
                ],
                'setting'=> []
            ]
        ],
        'redis'=> [
            'driver'=> 'Brisk\Session\Driver\Redis',
            'option'=> [
                'config'=> [
                    'host'=> '127.0.0.1',
                    'port'=> 6379,
                    'password'=> '123456',	//for redis
                ],
                'setting'=> []
            ]
        ],
        'filecache'=> [
            'driver'=> 'Brisk\Session\Driver\FileCache',
            'option'=> [
                'config'=> [
                    'path'=> '/path/to/session_path'
                ],
                'setting'=> []
            ]
        ],
        'files'=> [
            'driver'=> 'Brisk\Session\Driver\Files',
            'option'=> [
                'config'=> [],
                'setting'=> []
            ]
        ]
    ];

    /**
     * 数据库配置，多选
     *
     * @var array
     */
    private static $_database = [
        'default'=> [
            'driver'=> 'Brisk\Db\Driver\Pdo\Mysql',
            'option'=> [
                'config'=> [
                    'host'		=> '127.0.0.1',
                    'username'	=> 'user',
                    'password'	=> 'pass',
                    'port'		=> 1521,
                    'dbname'	=> 'dbname',
                    'charset'	=> 'utf8'
                ],
                'setting'=> ['type'=> 'new']
            ]
        ]
    ];

    /**
     * 缓存器配置，多选
     *
     * @var array
     */
    private static $_cache = [
        'file'=> [
            'driver'=> 'Brisk\Cache\Driver\File',
            'option'=> [
                'path'=> '/path/to/cachedir',
                'setting'=> ['ext_name'=> '.cache']
            ]
        ],
        'memcache'=> [
            'driver'=> 'Brisk\Cache\Driver\Memcached',
            'option'=> [
                'path'=> ['127.0.0.1:11211'],
                'setting'=> []
            ]
        ],
        'redis'=> [
            'driver'=> 'Brisk\Cache\Driver\Redis',
            'option'=> [
                'path'=> '127.0.0.1:6379',
                'setting'=> []
            ]
        ]
    ];

    /**
     * 视图组件配置，单选
     *
     * @var array
     */
    private static $_view = [
        'native'=> [
            'driver'=> 'Brisk\View\Driver\Native',
            'option'=> [
                'template_ext'=> '.phtml',
                'template_dir'=> '/path/to/tpldir'
            ]
        ]
    ];

    /**
     * 获取配置文件模板
     *
     * @param string $router
     * @param string $session
     * @param string $view
     * @return array
     */
    public static function getConfigTpl($router = 'rewrite', $session = 'files', $view = 'native')
    {
        $result = [
            'global'    => self::$_global,
            'router'    => self::$_router[$router] ? self::$_router[$router] : [],
            'session'   => self::$_session[$session] ? self::$_session[$session] : [],
            'database'  => self::$_database,
            'cache'     => self::$_cache,
            'view'      => self::$_view[$view] ? self::$_view[$view] : []
        ];
        return $result;
    }

    /**
     *
     * @param $file
     * @param array $config
     */
    public static function saveTo($file, array $config)
    {
        $config = var_export($config, true);
        $config = preg_replace('/\'\s+\=\>\s+?array\s+?\(/', '\'=> array(', $config);
        $config = preg_replace('/\'\s+=>/', '\'=>', $config);
        $config = preg_replace('/\=\> array\(\s*?\)/', '=> array()', $config);
        $config = '<?php'. PHP_EOL. PHP_EOL. 'return '. $config. ';';
        file_put_contents($file, $config);
    }

}