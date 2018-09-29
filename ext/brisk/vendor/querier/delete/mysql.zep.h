
extern zend_class_entry *brisk_vendor_querier_delete_mysql_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_Delete_Mysql);

PHP_METHOD(Brisk_Vendor_Querier_Delete_Mysql, getSQL);

ZEPHIR_INIT_FUNCS(brisk_vendor_querier_delete_mysql_method_entry) {
	PHP_ME(Brisk_Vendor_Querier_Delete_Mysql, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
