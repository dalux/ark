
extern zend_class_entry *brisk_sql_update_ce;

ZEPHIR_INIT_CLASS(Brisk_Sql_Update);

PHP_METHOD(Brisk_Sql_Update, set);
PHP_METHOD(Brisk_Sql_Update, compile);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_update_set, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, updates, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_sql_update_method_entry) {
	PHP_ME(Brisk_Sql_Update, set, arginfo_brisk_sql_update_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Update, compile, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
