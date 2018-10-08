
extern zend_class_entry *brisk_sql_insert_oci_ce;

ZEPHIR_INIT_CLASS(Brisk_Sql_Insert_Oci);

PHP_METHOD(Brisk_Sql_Insert_Oci, quote);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_insert_oci_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_sql_insert_oci_method_entry) {
	PHP_ME(Brisk_Sql_Insert_Oci, quote, arginfo_brisk_sql_insert_oci_quote, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
