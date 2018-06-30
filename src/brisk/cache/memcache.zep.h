
extern zend_class_entry *brisk_cache_memcache_ce;

ZEPHIR_INIT_CLASS(Brisk_Cache_MemCache);

PHP_METHOD(Brisk_Cache_MemCache, __construct);
PHP_METHOD(Brisk_Cache_MemCache, set);
PHP_METHOD(Brisk_Cache_MemCache, get);
PHP_METHOD(Brisk_Cache_MemCache, delete);
PHP_METHOD(Brisk_Cache_MemCache, __set);
PHP_METHOD(Brisk_Cache_MemCache, __get);
PHP_METHOD(Brisk_Cache_MemCache, getCachePath);
PHP_METHOD(Brisk_Cache_MemCache, getInstance);
PHP_METHOD(Brisk_Cache_MemCache, _formatPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_memcache___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, save_path)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_memcache_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_memcache_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_memcache_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_memcache___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_memcache___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_memcache_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_memcache__formatpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_cache_memcache_method_entry) {
	PHP_ME(Brisk_Cache_MemCache, __construct, arginfo_brisk_cache_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Cache_MemCache, set, arginfo_brisk_cache_memcache_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_MemCache, get, arginfo_brisk_cache_memcache_get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_MemCache, delete, arginfo_brisk_cache_memcache_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_MemCache, __set, arginfo_brisk_cache_memcache___set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_MemCache, __get, arginfo_brisk_cache_memcache___get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_MemCache, getCachePath, arginfo_brisk_cache_memcache_getcachepath, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_MemCache, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_MemCache, _formatPath, arginfo_brisk_cache_memcache__formatpath, ZEND_ACC_PRIVATE)
	PHP_FE_END
};