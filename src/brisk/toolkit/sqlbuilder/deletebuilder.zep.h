
extern zend_class_entry *brisk_toolkit_sqlbuilder_deletebuilder_ce;

ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_DeleteBuilder);

PHP_METHOD(Brisk_Toolkit_SQLBuilder_DeleteBuilder, from);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_DeleteBuilder, getSQL);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_deletebuilder_from, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_toolkit_sqlbuilder_deletebuilder_method_entry) {
	PHP_ME(Brisk_Toolkit_SQLBuilder_DeleteBuilder, from, arginfo_brisk_toolkit_sqlbuilder_deletebuilder_from, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_DeleteBuilder, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
