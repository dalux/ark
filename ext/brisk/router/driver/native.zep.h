
extern zend_class_entry *brisk_router_driver_native_ce;

ZEPHIR_INIT_CLASS(Brisk_Router_Driver_Native);

PHP_METHOD(Brisk_Router_Driver_Native, ready);
PHP_METHOD(Brisk_Router_Driver_Native, dispatch);

ZEPHIR_INIT_FUNCS(brisk_router_driver_native_method_entry) {
	PHP_ME(Brisk_Router_Driver_Native, ready, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Router_Driver_Native, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
