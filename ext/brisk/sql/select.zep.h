
extern zend_class_entry *brisk_sql_select_ce;

ZEPHIR_INIT_CLASS(Brisk_Sql_Select);

PHP_METHOD(Brisk_Sql_Select, from);
PHP_METHOD(Brisk_Sql_Select, group);
PHP_METHOD(Brisk_Sql_Select, having);
PHP_METHOD(Brisk_Sql_Select, limit);
PHP_METHOD(Brisk_Sql_Select, order);
PHP_METHOD(Brisk_Sql_Select, joinLeft);
PHP_METHOD(Brisk_Sql_Select, joinInner);
PHP_METHOD(Brisk_Sql_Select, joinRight);
PHP_METHOD(Brisk_Sql_Select, _join);
PHP_METHOD(Brisk_Sql_Select, pickSelectPart);
PHP_METHOD(Brisk_Sql_Select, pickGroupPart);
PHP_METHOD(Brisk_Sql_Select, pickHavingPart);
PHP_METHOD(Brisk_Sql_Select, pickOrderPart);
PHP_METHOD(Brisk_Sql_Select, pickLimitPart);
PHP_METHOD(Brisk_Sql_Select, compile);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_select_from, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, columns, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_select_group, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_select_having, 0, 0, 1)
	ZEND_ARG_INFO(0, cond)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_select_limit, 0, 0, 0)
	ZEND_ARG_INFO(0, count)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_select_order, 0, 0, 1)
	ZEND_ARG_INFO(0, col)
	ZEND_ARG_INFO(0, asc)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_select_joinleft, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_select_joininner, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_select_joinright, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_select__join, 0, 0, 4)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_ARRAY_INFO(0, fields, 0)
	ZEND_ARG_INFO(0, jointype)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_sql_select_method_entry) {
	PHP_ME(Brisk_Sql_Select, from, arginfo_brisk_sql_select_from, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, group, arginfo_brisk_sql_select_group, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, having, arginfo_brisk_sql_select_having, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, limit, arginfo_brisk_sql_select_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, order, arginfo_brisk_sql_select_order, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, joinLeft, arginfo_brisk_sql_select_joinleft, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, joinInner, arginfo_brisk_sql_select_joininner, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, joinRight, arginfo_brisk_sql_select_joinright, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, _join, arginfo_brisk_sql_select__join, ZEND_ACC_PROTECTED)
	PHP_ME(Brisk_Sql_Select, pickSelectPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, pickGroupPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, pickHavingPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, pickOrderPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, pickLimitPart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_Select, compile, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
