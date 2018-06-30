
extern zend_class_entry *brisk_database_pdodriver_sqlite_ce;

ZEPHIR_INIT_CLASS(Brisk_Database_PdoDriver_Sqlite);

PHP_METHOD(Brisk_Database_PdoDriver_Sqlite, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_pdodriver_sqlite___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_database_pdodriver_sqlite_method_entry) {
	PHP_ME(Brisk_Database_PdoDriver_Sqlite, __construct, arginfo_brisk_database_pdodriver_sqlite___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
