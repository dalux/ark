
extern zend_class_entry *brisk_vendor_cache_cacheadapter_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Cache_CacheAdapter);

PHP_METHOD(Brisk_Vendor_Cache_CacheAdapter, getDriver);
PHP_METHOD(Brisk_Vendor_Cache_CacheAdapter, getDriverFromConfig);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_cacheadapter_getdriver, 0, 0, 2)
	ZEND_ARG_INFO(0, driver)
	ZEND_ARG_INFO(0, save_path)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_cacheadapter_getdriverfromconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_cache_cacheadapter_method_entry) {
	PHP_ME(Brisk_Vendor_Cache_CacheAdapter, getDriver, arginfo_brisk_vendor_cache_cacheadapter_getdriver, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Vendor_Cache_CacheAdapter, getDriverFromConfig, arginfo_brisk_vendor_cache_cacheadapter_getdriverfromconfig, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
