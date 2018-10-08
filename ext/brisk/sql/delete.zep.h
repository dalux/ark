
extern zend_class_entry *brisk_sql_delete_ce;

ZEPHIR_INIT_CLASS(Brisk_Sql_Delete);

PHP_METHOD(Brisk_Sql_Delete, from);
PHP_METHOD(Brisk_Sql_Delete, compile);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_delete_from, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_sql_delete_method_entry) {
	PHP_ME(Brisk_Sql_Delete, from, arginfo_brisk_sql_delete_from, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Delete, compile, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
