
extern zend_class_entry *brisk_kernel_router_rewrite_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Router_Rewrite);

PHP_METHOD(Brisk_Kernel_Router_Rewrite, addRule);
PHP_METHOD(Brisk_Kernel_Router_Rewrite, addInterceptor);
PHP_METHOD(Brisk_Kernel_Router_Rewrite, getInterceptors);
PHP_METHOD(Brisk_Kernel_Router_Rewrite, ready);
PHP_METHOD(Brisk_Kernel_Router_Rewrite, dispatch);
PHP_METHOD(Brisk_Kernel_Router_Rewrite, todoUKSort);
PHP_METHOD(Brisk_Kernel_Router_Rewrite, _rewrite);
void zephir_init_static_properties_Brisk_Kernel_Router_Rewrite(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_router_rewrite_addrule, 0, 0, 2)
	ZEND_ARG_INFO(0, rule)
	ZEND_ARG_INFO(0, redirect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_router_rewrite_addinterceptor, 0, 0, 2)
	ZEND_ARG_INFO(0, ns_space)
	ZEND_ARG_INFO(0, operator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_router_rewrite_getinterceptors, 0, 0, 1)
	ZEND_ARG_INFO(0, ns_space)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_router_rewrite_todouksort, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_router_rewrite__rewrite, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_router_rewrite_method_entry) {
	PHP_ME(Brisk_Kernel_Router_Rewrite, addRule, arginfo_brisk_kernel_router_rewrite_addrule, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Router_Rewrite, addInterceptor, arginfo_brisk_kernel_router_rewrite_addinterceptor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Router_Rewrite, getInterceptors, arginfo_brisk_kernel_router_rewrite_getinterceptors, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Router_Rewrite, ready, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Router_Rewrite, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Router_Rewrite, todoUKSort, arginfo_brisk_kernel_router_rewrite_todouksort, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Router_Rewrite, _rewrite, arginfo_brisk_kernel_router_rewrite__rewrite, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
