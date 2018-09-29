
extern zend_class_entry *brisk_vendor_view_viewfather_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_View_ViewFather);

PHP_METHOD(Brisk_Vendor_View_ViewFather, set);
PHP_METHOD(Brisk_Vendor_View_ViewFather, get);
PHP_METHOD(Brisk_Vendor_View_ViewFather, display);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_view_viewfather_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_view_viewfather_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_view_viewfather_display, 0, 0, 1)
	ZEND_ARG_INFO(0, template)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_view_viewfather_method_entry) {
	PHP_ME(Brisk_Vendor_View_ViewFather, set, arginfo_brisk_vendor_view_viewfather_set, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_View_ViewFather, get, arginfo_brisk_vendor_view_viewfather_get, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_View_ViewFather, display, arginfo_brisk_vendor_view_viewfather_display, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_FE_END
};
