
extern zend_class_entry *brisk_cache_cacheproxy_ce;

ZEPHIR_INIT_CLASS(Brisk_Cache_CacheProxy);

PHP_METHOD(Brisk_Cache_CacheProxy, setCacheDriver);
PHP_METHOD(Brisk_Cache_CacheProxy, doProxy);
PHP_METHOD(Brisk_Cache_CacheProxy, _name);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_cacheproxy_setcachedriver, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cache, Brisk\\Cache\\CacheFather, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_cacheproxy_doproxy, 0, 0, 3)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_cacheproxy__name, 0, 0, 3)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, func)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_cache_cacheproxy_method_entry) {
	PHP_ME(Brisk_Cache_CacheProxy, setCacheDriver, arginfo_brisk_cache_cacheproxy_setcachedriver, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_CacheProxy, doProxy, arginfo_brisk_cache_cacheproxy_doproxy, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_CacheProxy, _name, arginfo_brisk_cache_cacheproxy__name, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
