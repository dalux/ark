
extern zend_class_entry *brisk_db_dbadapter_ce;

ZEPHIR_INIT_CLASS(Brisk_Db_DbAdapter);

PHP_METHOD(Brisk_Db_DbAdapter, getDriverFromConfig);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_dbadapter_getdriverfromconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_db_dbadapter_method_entry) {
	PHP_ME(Brisk_Db_DbAdapter, getDriverFromConfig, arginfo_brisk_db_dbadapter_getdriverfromconfig, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
