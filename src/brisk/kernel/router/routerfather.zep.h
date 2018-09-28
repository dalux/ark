
extern zend_class_entry *brisk_kernel_router_routerfather_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Router_RouterFather);

PHP_METHOD(Brisk_Kernel_Router_RouterFather, ready);
PHP_METHOD(Brisk_Kernel_Router_RouterFather, dispatch);

ZEPHIR_INIT_FUNCS(brisk_kernel_router_routerfather_method_entry) {
	PHP_ME(Brisk_Kernel_Router_RouterFather, ready, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Kernel_Router_RouterFather, dispatch, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_FE_END
};
