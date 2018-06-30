
extern zend_class_entry *brisk_kernel_adapter_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Adapter);

PHP_METHOD(Brisk_Kernel_Adapter, getCacheDriver);
PHP_METHOD(Brisk_Kernel_Adapter, getDatabaseDriver);
PHP_METHOD(Brisk_Kernel_Adapter, getRouterDriver);
PHP_METHOD(Brisk_Kernel_Adapter, getSessionDriver);
PHP_METHOD(Brisk_Kernel_Adapter, getViewDriver);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_adapter_getcachedriver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_adapter_getdatabasedriver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_adapter_method_entry) {
	PHP_ME(Brisk_Kernel_Adapter, getCacheDriver, arginfo_brisk_kernel_adapter_getcachedriver, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Adapter, getDatabaseDriver, arginfo_brisk_kernel_adapter_getdatabasedriver, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Adapter, getRouterDriver, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Adapter, getSessionDriver, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Adapter, getViewDriver, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
