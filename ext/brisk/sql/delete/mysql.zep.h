
extern zend_class_entry *brisk_sql_delete_mysql_ce;

ZEPHIR_INIT_CLASS(Brisk_Sql_Delete_Mysql);

PHP_METHOD(Brisk_Sql_Delete_Mysql, compile);

ZEPHIR_INIT_FUNCS(brisk_sql_delete_mysql_method_entry) {
	PHP_ME(Brisk_Sql_Delete_Mysql, compile, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
