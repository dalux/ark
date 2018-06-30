
extern zend_class_entry *brisk_router_rewriterouter_ce;

ZEPHIR_INIT_CLASS(Brisk_Router_RewriteRouter);

PHP_METHOD(Brisk_Router_RewriteRouter, addRule);
PHP_METHOD(Brisk_Router_RewriteRouter, addInterceptor);
PHP_METHOD(Brisk_Router_RewriteRouter, getInterceptors);
PHP_METHOD(Brisk_Router_RewriteRouter, ready);
PHP_METHOD(Brisk_Router_RewriteRouter, dispatch);
PHP_METHOD(Brisk_Router_RewriteRouter, todoUKSort);
PHP_METHOD(Brisk_Router_RewriteRouter, _rewrite);
void zephir_init_static_properties_Brisk_Router_RewriteRouter(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_rewriterouter_addrule, 0, 0, 2)
	ZEND_ARG_INFO(0, rule)
	ZEND_ARG_INFO(0, redirect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_rewriterouter_addinterceptor, 0, 0, 2)
	ZEND_ARG_INFO(0, ns_space)
	ZEND_ARG_INFO(0, operator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_rewriterouter_getinterceptors, 0, 0, 1)
	ZEND_ARG_INFO(0, ns_space)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_rewriterouter_todouksort, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_rewriterouter__rewrite, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_router_rewriterouter_method_entry) {
	PHP_ME(Brisk_Router_RewriteRouter, addRule, arginfo_brisk_router_rewriterouter_addrule, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Router_RewriteRouter, addInterceptor, arginfo_brisk_router_rewriterouter_addinterceptor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Router_RewriteRouter, getInterceptors, arginfo_brisk_router_rewriterouter_getinterceptors, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Router_RewriteRouter, ready, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Router_RewriteRouter, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Router_RewriteRouter, todoUKSort, arginfo_brisk_router_rewriterouter_todouksort, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Router_RewriteRouter, _rewrite, arginfo_brisk_router_rewriterouter__rewrite, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
