
extern zend_class_entry *brisk_cache_cacheadapter_ce;

ZEPHIR_INIT_CLASS(Brisk_Cache_CacheAdapter);

PHP_METHOD(Brisk_Cache_CacheAdapter, getDriverFromConfig);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_cacheadapter_getdriverfromconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_cache_cacheadapter_method_entry) {
	PHP_ME(Brisk_Cache_CacheAdapter, getDriverFromConfig, arginfo_brisk_cache_cacheadapter_getdriverfromconfig, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
