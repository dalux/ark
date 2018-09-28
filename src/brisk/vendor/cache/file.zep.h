
extern zend_class_entry *brisk_vendor_cache_file_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Cache_File);

PHP_METHOD(Brisk_Vendor_Cache_File, __construct);
PHP_METHOD(Brisk_Vendor_Cache_File, set);
PHP_METHOD(Brisk_Vendor_Cache_File, get);
PHP_METHOD(Brisk_Vendor_Cache_File, delete);
PHP_METHOD(Brisk_Vendor_Cache_File, __set);
PHP_METHOD(Brisk_Vendor_Cache_File, __get);
PHP_METHOD(Brisk_Vendor_Cache_File, getCachePath);
PHP_METHOD(Brisk_Vendor_Cache_File, _formatPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, save_path)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_file_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_file_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_file_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_file___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_file___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_file_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_cache_file__formatpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_cache_file_method_entry) {
	PHP_ME(Brisk_Vendor_Cache_File, __construct, arginfo_brisk_vendor_cache_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Vendor_Cache_File, set, arginfo_brisk_vendor_cache_file_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Cache_File, get, arginfo_brisk_vendor_cache_file_get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Cache_File, delete, arginfo_brisk_vendor_cache_file_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Cache_File, __set, arginfo_brisk_vendor_cache_file___set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Cache_File, __get, arginfo_brisk_vendor_cache_file___get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Cache_File, getCachePath, arginfo_brisk_vendor_cache_file_getcachepath, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Cache_File, _formatPath, arginfo_brisk_vendor_cache_file__formatpath, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
