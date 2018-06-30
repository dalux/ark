
extern zend_class_entry *brisk_proxy_cacheproxy_ce;

ZEPHIR_INIT_CLASS(Brisk_Proxy_CacheProxy);

PHP_METHOD(Brisk_Proxy_CacheProxy, setCacher);
PHP_METHOD(Brisk_Proxy_CacheProxy, doProxy);
PHP_METHOD(Brisk_Proxy_CacheProxy, name);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_proxy_cacheproxy_setcacher, 0, 0, 1)
	ZEND_ARG_INFO(0, cacher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_proxy_cacheproxy_doproxy, 0, 0, 3)
	ZEND_ARG_INFO(0, adapter)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_proxy_cacheproxy_name, 0, 0, 3)
	ZEND_ARG_INFO(0, adapter)
	ZEND_ARG_INFO(0, func)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_proxy_cacheproxy_method_entry) {
	PHP_ME(Brisk_Proxy_CacheProxy, setCacher, arginfo_brisk_proxy_cacheproxy_setcacher, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Proxy_CacheProxy, doProxy, arginfo_brisk_proxy_cacheproxy_doproxy, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Proxy_CacheProxy, name, arginfo_brisk_proxy_cacheproxy_name, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
