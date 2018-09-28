
extern zend_class_entry *brisk_vendor_querier_querierfather_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_QuerierFather);

PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, quote);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, where);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, whereIn);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, whereNotIn);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, whereExists);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, whereNotExists);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, whereLike);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, whereNotLike);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, pickWherePart);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, getSQL);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, getRealSQL);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, getBind);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, __toString);
PHP_METHOD(Brisk_Vendor_Querier_QuerierFather, _parseExpr);
zend_object_value zephir_init_properties_Brisk_Vendor_Querier_QuerierFather(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querierfather_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querierfather_where, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querierfather_wherein, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querierfather_wherenotin, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querierfather_whereexists, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querierfather_wherenotexists, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querierfather_wherelike, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querierfather_wherenotlike, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querierfather__parseexpr, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_querier_querierfather_method_entry) {
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, quote, arginfo_brisk_vendor_querier_querierfather_quote, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, where, arginfo_brisk_vendor_querier_querierfather_where, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, whereIn, arginfo_brisk_vendor_querier_querierfather_wherein, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, whereNotIn, arginfo_brisk_vendor_querier_querierfather_wherenotin, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, whereExists, arginfo_brisk_vendor_querier_querierfather_whereexists, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, whereNotExists, arginfo_brisk_vendor_querier_querierfather_wherenotexists, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, whereLike, arginfo_brisk_vendor_querier_querierfather_wherelike, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, whereNotLike, arginfo_brisk_vendor_querier_querierfather_wherenotlike, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, pickWherePart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, getSQL, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, getRealSQL, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, getBind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierFather, _parseExpr, arginfo_brisk_vendor_querier_querierfather__parseexpr, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
