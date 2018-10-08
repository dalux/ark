
extern zend_class_entry *brisk_router_driver_classic_ce;

ZEPHIR_INIT_CLASS(Brisk_Router_Driver_Classic);

PHP_METHOD(Brisk_Router_Driver_Classic, openModuleSupport);
PHP_METHOD(Brisk_Router_Driver_Classic, addRule);
PHP_METHOD(Brisk_Router_Driver_Classic, addInterceptor);
PHP_METHOD(Brisk_Router_Driver_Classic, getInterceptors);
PHP_METHOD(Brisk_Router_Driver_Classic, ready);
PHP_METHOD(Brisk_Router_Driver_Classic, dispatch);
PHP_METHOD(Brisk_Router_Driver_Classic, todoUKSort);
PHP_METHOD(Brisk_Router_Driver_Classic, _parseUri);
PHP_METHOD(Brisk_Router_Driver_Classic, _rewrite);
void zephir_init_static_properties_Brisk_Router_Driver_Classic(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_driver_classic_openmodulesupport, 0, 0, 0)
	ZEND_ARG_INFO(0, default_module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_driver_classic_addrule, 0, 0, 2)
	ZEND_ARG_INFO(0, rule)
	ZEND_ARG_INFO(0, redirect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_driver_classic_addinterceptor, 0, 0, 2)
	ZEND_ARG_INFO(0, ns_space)
	ZEND_ARG_INFO(0, operator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_driver_classic_getinterceptors, 0, 0, 1)
	ZEND_ARG_INFO(0, ns_space)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_driver_classic_todouksort, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_driver_classic__parseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_router_driver_classic__rewrite, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_router_driver_classic_method_entry) {
	PHP_ME(Brisk_Router_Driver_Classic, openModuleSupport, arginfo_brisk_router_driver_classic_openmodulesupport, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Router_Driver_Classic, addRule, arginfo_brisk_router_driver_classic_addrule, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Router_Driver_Classic, addInterceptor, arginfo_brisk_router_driver_classic_addinterceptor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Router_Driver_Classic, getInterceptors, arginfo_brisk_router_driver_classic_getinterceptors, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Router_Driver_Classic, ready, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Router_Driver_Classic, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Router_Driver_Classic, todoUKSort, arginfo_brisk_router_driver_classic_todouksort, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Router_Driver_Classic, _parseUri, arginfo_brisk_router_driver_classic__parseuri, ZEND_ACC_PRIVATE)
	PHP_ME(Brisk_Router_Driver_Classic, _rewrite, arginfo_brisk_router_driver_classic__rewrite, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
