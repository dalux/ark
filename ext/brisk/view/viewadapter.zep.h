
extern zend_class_entry *brisk_view_viewadapter_ce;

ZEPHIR_INIT_CLASS(Brisk_View_ViewAdapter);

PHP_METHOD(Brisk_View_ViewAdapter, getDriverFromConfig);

ZEPHIR_INIT_FUNCS(brisk_view_viewadapter_method_entry) {
	PHP_ME(Brisk_View_ViewAdapter, getDriverFromConfig, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
