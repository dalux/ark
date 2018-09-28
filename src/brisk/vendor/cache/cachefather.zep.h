
extern zend_class_entry *brisk_vendor_cache_cachefather_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Cache_CacheFather);

PHP_METHOD(Brisk_Vendor_Cache_CacheFather, setFlag);
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, setFormat);
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, setCaching);
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, set);
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, get);
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, delete);
PHP_METHOD(Brisk_Vendor_Cache_CacheFather, getCachePath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_cachefather_setflag, 0, 0, 1)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_cachefather_setformat, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_cachefather_setcaching, 0, 0, 0)
	ZEND_ARG_INFO(0, caching)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_cachefather_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_cachefather_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_cachefather_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_cachefather_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_cache_cachefather_method_entry) {
	PHP_ME(Brisk_Vendor_Cache_CacheFather, setFlag, arginfo_brisk_vendor_cache_cachefather_setflag, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Cache_CacheFather, setFormat, arginfo_brisk_vendor_cache_cachefather_setformat, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Cache_CacheFather, setCaching, arginfo_brisk_vendor_cache_cachefather_setcaching, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Cache_CacheFather, set, arginfo_brisk_vendor_cache_cachefather_set, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Cache_CacheFather, get, arginfo_brisk_vendor_cache_cachefather_get, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Cache_CacheFather, delete, arginfo_brisk_vendor_cache_cachefather_delete, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Cache_CacheFather, getCachePath, arginfo_brisk_vendor_cache_cachefather_getcachepath, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_FE_END
};
