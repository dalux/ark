
extern zend_class_entry *brisk_cache_driver_file_ce;

ZEPHIR_INIT_CLASS(Brisk_Cache_Driver_File);

PHP_METHOD(Brisk_Cache_Driver_File, __construct);
PHP_METHOD(Brisk_Cache_Driver_File, set);
PHP_METHOD(Brisk_Cache_Driver_File, get);
PHP_METHOD(Brisk_Cache_Driver_File, delete);
PHP_METHOD(Brisk_Cache_Driver_File, __set);
PHP_METHOD(Brisk_Cache_Driver_File, __get);
PHP_METHOD(Brisk_Cache_Driver_File, getCachePath);
PHP_METHOD(Brisk_Cache_Driver_File, _formatPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, setting, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_file_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_file_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_file_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_file___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_file___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_file_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_driver_file__formatpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_cache_driver_file_method_entry) {
	PHP_ME(Brisk_Cache_Driver_File, __construct, arginfo_brisk_cache_driver_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Cache_Driver_File, set, arginfo_brisk_cache_driver_file_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_File, get, arginfo_brisk_cache_driver_file_get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_File, delete, arginfo_brisk_cache_driver_file_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_File, __set, arginfo_brisk_cache_driver_file___set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_File, __get, arginfo_brisk_cache_driver_file___get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_File, getCachePath, arginfo_brisk_cache_driver_file_getcachepath, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_Driver_File, _formatPath, arginfo_brisk_cache_driver_file__formatpath, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
