<?php declare(strict_types=1);

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
        'error_reporting'=> E_ALL //E_ALL^E_NOTICE^E_WARNING^E_DEPRECATED
    ];

    /**
     * 会话配置，单选
     *
     * @var array
     */
    private static $_session = [
        'memcache'=> [
            'driver'=> 'Brisk\Session\Driver\Memcached',
            'setting'=> [
                'save_path'=> '127.0.0.1:11211',
                'expire_time'=> 1440,
                'option'=> []
            ]
        ],
        'redis'=> [
            'driver'=> 'Brisk\Session\Driver\Redis',
            'setting'=> [
                'save_path'=> '127.0.0.1:6379',
                'password'=> '123456',	//for redis
                'expire_time'=> 1440,
                'option'=> []
            ]
        ],
        'file'=> [
            'driver'=> 'Brisk\Session\Driver\File',
            'setting'=> [
                'save_path'=> '/path/to/session_path',
                'expire_time'=> 1440,
                'option'=> []
            ]
        ],
        'native'=> [
            'driver'=> 'Brisk\Session\Driver\Native',
            'setting'=> [
                'save_path'=> '/path/to/session_path',
                'expire_time'=> 1440,
                'option'=> []
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
            'driver'=> 'Brisk\Db\Driver\Pdo',
            'setting'=> [
                'dsn'=> 'mysql:host=127.0.0.1;port=3306;dbname=test;charset=utf8',
                'username'=> '',
                'password'=> '',
                'option'=> []
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
            'setting'=> [
                'save_path'=> '/path/to/cachedir',
                'option'=> [
                    'ext_name'=> '.cache',
                    'expire_time'=> 86400,
                ]
            ]
        ],
        'memcache'=> [
            'driver'=> 'Brisk\Cache\Driver\Memcached',
            'setting'=> [
                'save_path'=> ['127.0.0.1:11211'],
                'option'=> [
                    'expire_time'=> 86400,
                    'memopt'=> [],
                ]
            ]
        ],
        'redis'=> [
            'driver'=> 'Brisk\Cache\Driver\Redis',
            'setting'=> [
                'save_path'=> '127.0.0.1:6379',
                'option'=> [
                    'expire_time'=> 86400,
                    'timeout'=> 5,
                    'password'=> '',
                ]
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
            'setting'=> [
                'template_ext'=> '.phtml',
                'template_dir'=> '/path/to/tpldir'
            ]
        ]
    ];

    /**
     * 获取配置文件模板
     *
     * @access public
     * @param string $session
     * @param string $view
     * @return array
     */
    public static function getConfigTpl($session = 'native', $view = 'native')
    {
        $result = [
            'global'    => self::$_global,
            'session'   => self::$_session[$session] ? self::$_session[$session] : [],
            'database'  => self::$_database,
            'cache'     => self::$_cache,
            'view'      => self::$_view[$view] ? self::$_view[$view] : []
        ];
        return $result;
    }

    /**
     * 保存配置到文件
     *
     * @access public
     * @param $file
     * @param array $config
     * @return void
     */
    public static function saveTo($file, array $config)
    {
        $config = var_export($config, true);
        $config = preg_replace('/\'\s+\=\>\s+?array\s+?\(/', '\'=> array(', $config);
        $config = preg_replace('/\'\s+=>/', '\'=>', $config);
        $config = preg_replace('/\=\> array\(\s*?\)/', '=> array()', $config);
        $config = '<?php declare(strict_types=1);'. PHP_EOL. PHP_EOL. 'return '. $config. ';';
        file_put_contents($file, $config);
    }

}