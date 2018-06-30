
extern zend_class_entry *brisk_toolkit_sqlbuilder_updatebuilder_ce;

ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_UpdateBuilder);

PHP_METHOD(Brisk_Toolkit_SQLBuilder_UpdateBuilder, set);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_UpdateBuilder, getSQL);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_updatebuilder_set, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, updates, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_toolkit_sqlbuilder_updatebuilder_method_entry) {
	PHP_ME(Brisk_Toolkit_SQLBuilder_UpdateBuilder, set, arginfo_brisk_toolkit_sqlbuilder_updatebuilder_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_UpdateBuilder, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
