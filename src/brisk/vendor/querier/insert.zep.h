
extern zend_class_entry *brisk_vendor_querier_insert_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_Insert);

PHP_METHOD(Brisk_Vendor_Querier_Insert, into);
PHP_METHOD(Brisk_Vendor_Querier_Insert, pickInsertPart);
PHP_METHOD(Brisk_Vendor_Querier_Insert, pickValuesPart);
PHP_METHOD(Brisk_Vendor_Querier_Insert, getSQL);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_insert_into, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_querier_insert_method_entry) {
	PHP_ME(Brisk_Vendor_Querier_Insert, into, arginfo_brisk_vendor_querier_insert_into, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_Insert, pickInsertPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_Insert, pickValuesPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_Insert, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
