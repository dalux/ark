
extern zend_class_entry *brisk_cache_driver_redis_ce;

ZEPHIR_INIT_CLASS(Brisk_Cache_Driver_Redis);

PHP_METHOD(Brisk_Cache_Driver_Redis, __construct);
PHP_METHOD(Brisk_Cache_Driver_Redis, set);
PHP_METHOD(Brisk_Cache_Driver_Redis, get);
PHP_METHOD(Brisk_Cache_Driver_Redis, delete);
PHP_METHOD(Brisk_Cache_Driver_Redis, getCachePath);
PHP_METHOD(Brisk_Cache_Driver_Redis, getInstance);
PHP_METHOD(Brisk_Cache_Driver_Redis, __set);
PHP_METHOD(Brisk_Cache_Driver_Redis, __get);
PHP_METHOD(Brisk_Cache_Driver_Redis, _formatPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_redis___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, save_path)
	ZEND_ARG_ARRAY_INFO(0, setting, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_redis_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_redis_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_redis_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_redis_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_redis___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_redis___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_redis__formatpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_cache_driver_redis_method_entry) {
	PHP_ME(Brisk_Cache_Driver_Redis, __construct, arginfo_brisk_cache_driver_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Cache_Driver_Redis, set, arginfo_brisk_cache_driver_redis_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Redis, get, arginfo_brisk_cache_driver_redis_get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Redis, delete, arginfo_brisk_cache_driver_redis_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Redis, getCachePath, arginfo_brisk_cache_driver_redis_getcachepath, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Redis, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Redis, __set, arginfo_brisk_cache_driver_redis___set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Redis, __get, arginfo_brisk_cache_driver_redis___get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_Redis, _formatPath, arginfo_brisk_cache_driver_redis__formatpath, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
