
extern zend_class_entry *brisk_vendor_view_native_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_View_Native);

PHP_METHOD(Brisk_Vendor_View_Native, __construct);
PHP_METHOD(Brisk_Vendor_View_Native, set);
PHP_METHOD(Brisk_Vendor_View_Native, get);
PHP_METHOD(Brisk_Vendor_View_Native, display);
PHP_METHOD(Brisk_Vendor_View_Native, import);
zend_object_value zephir_init_properties_Brisk_Vendor_View_Native(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_view_native___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_view_native_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_view_native_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_view_native_display, 0, 0, 1)
	ZEND_ARG_INFO(0, template)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_view_native_import, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_view_native_method_entry) {
	PHP_ME(Brisk_Vendor_View_Native, __construct, arginfo_brisk_vendor_view_native___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Vendor_View_Native, set, arginfo_brisk_vendor_view_native_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_View_Native, get, arginfo_brisk_vendor_view_native_get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_View_Native, display, arginfo_brisk_vendor_view_native_display, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_View_Native, import, arginfo_brisk_vendor_view_native_import, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
