
extern zend_class_entry *brisk_kernel_router_routeradapter_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Router_RouterAdapter);

PHP_METHOD(Brisk_Kernel_Router_RouterAdapter, getDriver);

ZEPHIR_INIT_FUNCS(brisk_kernel_router_routeradapter_method_entry) {
	PHP_ME(Brisk_Kernel_Router_RouterAdapter, getDriver, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
