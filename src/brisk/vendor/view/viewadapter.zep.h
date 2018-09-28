
extern zend_class_entry *brisk_vendor_view_viewadapter_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_View_ViewAdapter);

PHP_METHOD(Brisk_Vendor_View_ViewAdapter, getDriver);
PHP_METHOD(Brisk_Vendor_View_ViewAdapter, getDriverFromConfig);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_view_viewadapter_getdriver, 0, 0, 1)
	ZEND_ARG_INFO(0, driver)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_view_viewadapter_method_entry) {
	PHP_ME(Brisk_Vendor_View_ViewAdapter, getDriver, arginfo_brisk_vendor_view_viewadapter_getdriver, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Vendor_View_ViewAdapter, getDriverFromConfig, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
