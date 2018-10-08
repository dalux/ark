
extern zend_class_entry *brisk_cache_driver_memcached_ce;

ZEPHIR_INIT_CLASS(Brisk_Cache_Driver_Memcached);

PHP_METHOD(Brisk_Cache_Driver_Memcached, __construct);
PHP_METHOD(Brisk_Cache_Driver_Memcached, set);
PHP_METHOD(Brisk_Cache_Driver_Memcached, get);
PHP_METHOD(Brisk_Cache_Driver_Memcached, delete);
PHP_METHOD(Brisk_Cache_Driver_Memcached, __set);
PHP_METHOD(Brisk_Cache_Driver_Memcached, __get);
PHP_METHOD(Brisk_Cache_Driver_Memcached, getCachePath);
PHP_METHOD(Brisk_Cache_Driver_Memcached, getInstance);
PHP_METHOD(Brisk_Cache_Driver_Memcached, _formatPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_memcached___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, setting, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_memcached_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_memcached_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_memcached_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_memcached___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_memcached___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_memcached_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_memcached__formatpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_cache_driver_memcached_method_entry) {
	PHP_ME(Brisk_Cache_Driver_Memcached, __construct, arginfo_brisk_cache_driver_memcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Cache_Driver_Memcached, set, arginfo_brisk_cache_driver_memcached_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Memcached, get, arginfo_brisk_cache_driver_memcached_get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Memcached, delete, arginfo_brisk_cache_driver_memcached_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Memcached, __set, arginfo_brisk_cache_driver_memcached___set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Memcached, __get, arginfo_brisk_cache_driver_memcached___get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Memcached, getCachePath, arginfo_brisk_cache_driver_memcached_getcachepath, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Memcached, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Memcached, _formatPath, arginfo_brisk_cache_driver_memcached__formatpath, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
