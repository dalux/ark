
extern zend_class_entry *brisk_toolkit_sqlbuilder_insertbuilder_ce;

ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_InsertBuilder);

PHP_METHOD(Brisk_Toolkit_SQLBuilder_InsertBuilder, into);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_InsertBuilder, pickInsertPart);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_InsertBuilder, pickValuesPart);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_InsertBuilder, getSQL);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_insertbuilder_into, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_toolkit_sqlbuilder_insertbuilder_method_entry) {
	PHP_ME(Brisk_Toolkit_SQLBuilder_InsertBuilder, into, arginfo_brisk_toolkit_sqlbuilder_insertbuilder_into, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_InsertBuilder, pickInsertPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_InsertBuilder, pickValuesPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_InsertBuilder, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
