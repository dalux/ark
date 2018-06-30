
extern zend_class_entry *brisk_toolkit_sqlbuilder_selectbuilder_oci_ce;

ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_SelectBuilder_Oci);

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder_Oci, pickLimitPart);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder_Oci, getSQL);

ZEPHIR_INIT_FUNCS(brisk_toolkit_sqlbuilder_selectbuilder_oci_method_entry) {
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder_Oci, pickLimitPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder_Oci, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
