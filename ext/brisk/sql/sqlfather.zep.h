
extern zend_class_entry *brisk_sql_sqlfather_ce;

ZEPHIR_INIT_CLASS(Brisk_Sql_SqlFather);

PHP_METHOD(Brisk_Sql_SqlFather, quote);
PHP_METHOD(Brisk_Sql_SqlFather, where);
PHP_METHOD(Brisk_Sql_SqlFather, whereIn);
PHP_METHOD(Brisk_Sql_SqlFather, whereNotIn);
PHP_METHOD(Brisk_Sql_SqlFather, whereExists);
PHP_METHOD(Brisk_Sql_SqlFather, whereNotExists);
PHP_METHOD(Brisk_Sql_SqlFather, whereLike);
PHP_METHOD(Brisk_Sql_SqlFather, whereNotLike);
PHP_METHOD(Brisk_Sql_SqlFather, pickWherePart);
PHP_METHOD(Brisk_Sql_SqlFather, getBind);
PHP_METHOD(Brisk_Sql_SqlFather, getSQL);
PHP_METHOD(Brisk_Sql_SqlFather, getRealSQL);
PHP_METHOD(Brisk_Sql_SqlFather, __toString);
PHP_METHOD(Brisk_Sql_SqlFather, compile);
PHP_METHOD(Brisk_Sql_SqlFather, _parseExpr);
zend_object_value zephir_init_properties_Brisk_Sql_SqlFather(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlfather_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlfather_where, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlfather_wherein, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlfather_wherenotin, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlfather_whereexists, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlfather_wherenotexists, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlfather_wherelike, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlfather_wherenotlike, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlfather__parseexpr, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_sql_sqlfather_method_entry) {
	PHP_ME(Brisk_Sql_SqlFather, quote, arginfo_brisk_sql_sqlfather_quote, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, where, arginfo_brisk_sql_sqlfather_where, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, whereIn, arginfo_brisk_sql_sqlfather_wherein, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, whereNotIn, arginfo_brisk_sql_sqlfather_wherenotin, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, whereExists, arginfo_brisk_sql_sqlfather_whereexists, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, whereNotExists, arginfo_brisk_sql_sqlfather_wherenotexists, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, whereLike, arginfo_brisk_sql_sqlfather_wherelike, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, whereNotLike, arginfo_brisk_sql_sqlfather_wherenotlike, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, pickWherePart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, getBind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, getSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, getRealSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Sql_SqlFather, compile, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Sql_SqlFather, _parseExpr, arginfo_brisk_sql_sqlfather__parseexpr, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
