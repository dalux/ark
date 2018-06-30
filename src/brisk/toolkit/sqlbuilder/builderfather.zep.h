
extern zend_class_entry *brisk_toolkit_sqlbuilder_builderfather_ce;

ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_BuilderFather);

PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, where);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereIn);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereNotIn);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereExists);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereNotExists);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereLike);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, whereNotLike);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, pickWherePart);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, getSQL);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, getRealSQL);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, getBind);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, __toString);
PHP_METHOD(Brisk_Toolkit_SQLBuilder_BuilderFather, _parseExpr);
zend_object *zephir_init_properties_Brisk_Toolkit_SQLBuilder_BuilderFather(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_builderfather_where, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_builderfather_wherein, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_builderfather_wherenotin, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_builderfather_whereexists, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_builderfather_wherenotexists, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_builderfather_wherelike, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_builderfather_wherenotlike, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_sqlbuilder_builderfather__parseexpr, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_toolkit_sqlbuilder_builderfather_method_entry) {
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, where, arginfo_brisk_toolkit_sqlbuilder_builderfather_where, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, whereIn, arginfo_brisk_toolkit_sqlbuilder_builderfather_wherein, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, whereNotIn, arginfo_brisk_toolkit_sqlbuilder_builderfather_wherenotin, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, whereExists, arginfo_brisk_toolkit_sqlbuilder_builderfather_whereexists, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, whereNotExists, arginfo_brisk_toolkit_sqlbuilder_builderfather_wherenotexists, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, whereLike, arginfo_brisk_toolkit_sqlbuilder_builderfather_wherelike, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, whereNotLike, arginfo_brisk_toolkit_sqlbuilder_builderfather_wherenotlike, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, pickWherePart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, getSQL, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, getRealSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, getBind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_SQLBuilder_BuilderFather, _parseExpr, arginfo_brisk_toolkit_sqlbuilder_builderfather__parseexpr, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
