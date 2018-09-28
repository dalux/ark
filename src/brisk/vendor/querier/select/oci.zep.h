
extern zend_class_entry *brisk_vendor_querier_select_oci_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_Select_Oci);

PHP_METHOD(Brisk_Vendor_Querier_Select_Oci, pickLimitPart);
PHP_METHOD(Brisk_Vendor_Querier_Select_Oci, getSQL);

ZEPHIR_INIT_FUNCS(brisk_vendor_querier_select_oci_method_entry) {
	PHP_ME(Brisk_Vendor_Querier_Select_Oci, pickLimitPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_Select_Oci, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
