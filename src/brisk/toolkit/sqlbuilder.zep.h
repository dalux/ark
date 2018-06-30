
extern zend_class_entry *brisk_toolkit_sqlbuilder_ce;

ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder);

PHP_METHOD(Brisk_Toolkit_SQLBuilder, setDbType);
PHP_METHOD(Brisk_Toolkit_SQLBuilder, quote);
PHP_METHOD(Brisk_Toolkit_SQLBuilder, select);
PHP_METHOD(Brisk_Toolkit_SQLBuilder, insert);
PHP_METHOD(Brisk_Toolkit_SQLBuilder, update);
PHP_METHOD(Brisk_Toolkit_SQLBuilder, delete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_setdbtype, 0, 0, 1)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_select, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_insert, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_update, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_delete, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_toolkit_sqlbuilder_method_entry) {
	PHP_ME(Brisk_Toolkit_SQLBuilder, setDbType, arginfo_brisk_toolkit_sqlbuilder_setdbtype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder, quote, arginfo_brisk_toolkit_sqlbuilder_quote, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder, select, arginfo_brisk_toolkit_sqlbuilder_select, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder, insert, arginfo_brisk_toolkit_sqlbuilder_insert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder, update, arginfo_brisk_toolkit_sqlbuilder_update, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder, delete, arginfo_brisk_toolkit_sqlbuilder_delete, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
