
extern zend_class_entry *brisk_cache_filecache_ce;

ZEPHIR_INIT_CLASS(Brisk_Cache_FileCache);

PHP_METHOD(Brisk_Cache_FileCache, __construct);
PHP_METHOD(Brisk_Cache_FileCache, set);
PHP_METHOD(Brisk_Cache_FileCache, get);
PHP_METHOD(Brisk_Cache_FileCache, delete);
PHP_METHOD(Brisk_Cache_FileCache, __set);
PHP_METHOD(Brisk_Cache_FileCache, __get);
PHP_METHOD(Brisk_Cache_FileCache, getCachePath);
PHP_METHOD(Brisk_Cache_FileCache, _formatPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_filecache___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, save_path)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_filecache_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_filecache_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_filecache_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_filecache___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_filecache___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_filecache_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_cache_filecache__formatpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_cache_filecache_method_entry) {
	PHP_ME(Brisk_Cache_FileCache, __construct, arginfo_brisk_cache_filecache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Cache_FileCache, set, arginfo_brisk_cache_filecache_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_FileCache, get, arginfo_brisk_cache_filecache_get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_FileCache, delete, arginfo_brisk_cache_filecache_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_FileCache, __set, arginfo_brisk_cache_filecache___set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_FileCache, __get, arginfo_brisk_cache_filecache___get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_FileCache, getCachePath, arginfo_brisk_cache_filecache_getcachepath, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Cache_FileCache, _formatPath, arginfo_brisk_cache_filecache__formatpath, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
