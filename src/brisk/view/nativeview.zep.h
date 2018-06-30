
extern zend_class_entry *brisk_view_nativeview_ce;

ZEPHIR_INIT_CLASS(Brisk_View_NativeView);

PHP_METHOD(Brisk_View_NativeView, __construct);
PHP_METHOD(Brisk_View_NativeView, set);
PHP_METHOD(Brisk_View_NativeView, get);
PHP_METHOD(Brisk_View_NativeView, display);
PHP_METHOD(Brisk_View_NativeView, import);
zend_object *zephir_init_properties_Brisk_View_NativeView(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_view_nativeview_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_view_nativeview_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_view_nativeview_display, 0, 0, 1)
	ZEND_ARG_INFO(0, template)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_view_nativeview_import, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_view_nativeview_method_entry) {
	PHP_ME(Brisk_View_NativeView, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_View_NativeView, set, arginfo_brisk_view_nativeview_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_View_NativeView, get, arginfo_brisk_view_nativeview_get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_View_NativeView, display, arginfo_brisk_view_nativeview_display, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_View_NativeView, import, arginfo_brisk_view_nativeview_import, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
