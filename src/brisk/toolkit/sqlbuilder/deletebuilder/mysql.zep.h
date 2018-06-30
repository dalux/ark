
extern zend_class_entry *brisk_toolkit_sqlbuilder_deletebuilder_mysql_ce;

ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_DeleteBuilder_Mysql);

PHP_METHOD(Brisk_Toolkit_SQLBuilder_DeleteBuilder_Mysql, getSQL);

ZEPHIR_INIT_FUNCS(brisk_toolkit_sqlbuilder_deletebuilder_mysql_method_entry) {
	PHP_ME(Brisk_Toolkit_SQLBuilder_DeleteBuilder_Mysql, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
