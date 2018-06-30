
extern zend_class_entry *brisk_database_databasetoolkit_ce;

ZEPHIR_INIT_CLASS(Brisk_Database_DatabaseToolkit);

PHP_METHOD(Brisk_Database_DatabaseToolkit, parseConnectUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_databasetoolkit_parseconnecturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_database_databasetoolkit_method_entry) {
	PHP_ME(Brisk_Database_DatabaseToolkit, parseConnectUrl, arginfo_brisk_database_databasetoolkit_parseconnecturl, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
