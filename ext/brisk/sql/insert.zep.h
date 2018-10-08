
extern zend_class_entry *brisk_sql_insert_ce;

ZEPHIR_INIT_CLASS(Brisk_Sql_Insert);

PHP_METHOD(Brisk_Sql_Insert, into);
PHP_METHOD(Brisk_Sql_Insert, pickInsertPart);
PHP_METHOD(Brisk_Sql_Insert, pickValuesPart);
PHP_METHOD(Brisk_Sql_Insert, compile);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_insert_into, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_sql_insert_method_entry) {
	PHP_ME(Brisk_Sql_Insert, into, arginfo_brisk_sql_insert_into, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Insert, pickInsertPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Insert, pickValuesPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Insert, compile, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
