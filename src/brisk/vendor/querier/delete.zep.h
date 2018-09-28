
extern zend_class_entry *brisk_vendor_querier_delete_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_Delete);

PHP_METHOD(Brisk_Vendor_Querier_Delete, from);
PHP_METHOD(Brisk_Vendor_Querier_Delete, getSQL);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_delete_from, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_querier_delete_method_entry) {
	PHP_ME(Brisk_Vendor_Querier_Delete, from, arginfo_brisk_vendor_querier_delete_from, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_Delete, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
