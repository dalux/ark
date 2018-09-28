
extern zend_class_entry *brisk_vendor_querier_update_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_Update);

PHP_METHOD(Brisk_Vendor_Querier_Update, set);
PHP_METHOD(Brisk_Vendor_Querier_Update, getSQL);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_update_set, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, updates, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_querier_update_method_entry) {
	PHP_ME(Brisk_Vendor_Querier_Update, set, arginfo_brisk_vendor_querier_update_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_Update, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
