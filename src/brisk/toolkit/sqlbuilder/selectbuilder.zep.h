
extern zend_class_entry *brisk_toolkit_sqlbuilder_selectbuilder_ce;

ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_SelectBuilder);

PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, from);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, group);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, having);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, limit);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, order);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, joinLeft);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, joinInner);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, joinRight);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, _join);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickSelectPart);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickGroupPart);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickHavingPart);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickOrderPart);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickLimitPart);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_SelectBuilder, getSQL);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_selectbuilder_from, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, columns, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_selectbuilder_group, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_selectbuilder_having, 0, 0, 1)
	ZEND_ARG_INFO(0, cond)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_selectbuilder_limit, 0, 0, 0)
	ZEND_ARG_INFO(0, count)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_selectbuilder_order, 0, 0, 1)
	ZEND_ARG_INFO(0, col)
	ZEND_ARG_INFO(0, asc)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_selectbuilder_joinleft, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_selectbuilder_joininner, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_selectbuilder_joinright, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_selectbuilder__join, 0, 0, 4)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
	ZEND_ARG_INFO(0, jointype)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_toolkit_sqlbuilder_selectbuilder_method_entry) {
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, from, arginfo_brisk_toolkit_sqlbuilder_selectbuilder_from, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, group, arginfo_brisk_toolkit_sqlbuilder_selectbuilder_group, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, having, arginfo_brisk_toolkit_sqlbuilder_selectbuilder_having, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, limit, arginfo_brisk_toolkit_sqlbuilder_selectbuilder_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, order, arginfo_brisk_toolkit_sqlbuilder_selectbuilder_order, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, joinLeft, arginfo_brisk_toolkit_sqlbuilder_selectbuilder_joinleft, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, joinInner, arginfo_brisk_toolkit_sqlbuilder_selectbuilder_joininner, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, joinRight, arginfo_brisk_toolkit_sqlbuilder_selectbuilder_joinright, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, _join, arginfo_brisk_toolkit_sqlbuilder_selectbuilder__join, ZEND_ACC_PROTECTED)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickSelectPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickGroupPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickHavingPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickOrderPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, pickLimitPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_SelectBuilder, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
