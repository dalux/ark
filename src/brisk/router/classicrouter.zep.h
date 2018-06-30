
extern zend_class_entry *brisk_router_classicrouter_ce;

ZEPHIR_INIT_CLASS(Brisk_Router_ClassicRouter);

PHP_METHOD(Brisk_Router_ClassicRouter, openModuleSupport);
PHP_METHOD(Brisk_Router_ClassicRouter, addRule);
PHP_METHOD(Brisk_Router_ClassicRouter, addInterceptor);
PHP_METHOD(Brisk_Router_ClassicRouter, getInterceptors);
PHP_METHOD(Brisk_Router_ClassicRouter, ready);
PHP_METHOD(Brisk_Router_ClassicRouter, dispatch);
PHP_METHOD(Brisk_Router_ClassicRouter, todoUKSort);
PHP_METHOD(Brisk_Router_ClassicRouter, _parseUri);
PHP_METHOD(Brisk_Router_ClassicRouter, _rewrite);
void zephir_init_static_properties_Brisk_Router_ClassicRouter(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_classicrouter_openmodulesupport, 0, 0, 1)
	ZEND_ARG_INFO(0, default_module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_classicrouter_addrule, 0, 0, 2)
	ZEND_ARG_INFO(0, rule)
	ZEND_ARG_INFO(0, redirect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_classicrouter_addinterceptor, 0, 0, 2)
	ZEND_ARG_INFO(0, ns_space)
	ZEND_ARG_INFO(0, operator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_classicrouter_getinterceptors, 0, 0, 1)
	ZEND_ARG_INFO(0, ns_space)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_classicrouter_todouksort, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_classicrouter__parseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_classicrouter__rewrite, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_router_classicrouter_method_entry) {
	PHP_ME(Brisk_Router_ClassicRouter, openModuleSupport, arginfo_brisk_router_classicrouter_openmodulesupport, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Router_ClassicRouter, addRule, arginfo_brisk_router_classicrouter_addrule, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Router_ClassicRouter, addInterceptor, arginfo_brisk_router_classicrouter_addinterceptor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Router_ClassicRouter, getInterceptors, arginfo_brisk_router_classicrouter_getinterceptors, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Router_ClassicRouter, ready, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Router_ClassicRouter, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Router_ClassicRouter, todoUKSort, arginfo_brisk_router_classicrouter_todouksort, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Router_ClassicRouter, _parseUri, arginfo_brisk_router_classicrouter__parseuri, ZEND_ACC_PRIVATE)
	PHP_ME(Brisk_Router_ClassicRouter, _rewrite, arginfo_brisk_router_classicrouter__rewrite, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
