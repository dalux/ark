
extern zend_class_entry *brisk_router_routeradapter_ce;

ZEPHIR_INIT_CLASS(Brisk_Router_RouterAdapter);

PHP_METHOD(Brisk_Router_RouterAdapter, getDriverFromConfig);

ZEPHIR_INIT_FUNCS(brisk_router_routeradapter_method_entry) {
	PHP_ME(Brisk_Router_RouterAdapter, getDriverFromConfig, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
