
extern zend_class_entry *brisk_kernel_app_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_App);

PHP_METHOD(Brisk_Kernel_App, __construct);
PHP_METHOD(Brisk_Kernel_App, set);
PHP_METHOD(Brisk_Kernel_App, setName);
PHP_METHOD(Brisk_Kernel_App, setBaseDir);
PHP_METHOD(Brisk_Kernel_App, setConfig);
PHP_METHOD(Brisk_Kernel_App, setControllerDir);
PHP_METHOD(Brisk_Kernel_App, getName);
PHP_METHOD(Brisk_Kernel_App, getBaseDir);
PHP_METHOD(Brisk_Kernel_App, getControllerDir);
PHP_METHOD(Brisk_Kernel_App, init);
PHP_METHOD(Brisk_Kernel_App, getInstance);
PHP_METHOD(Brisk_Kernel_App, setAutoLoad);
PHP_METHOD(Brisk_Kernel_App, start);
PHP_METHOD(Brisk_Kernel_App, setComponent);
PHP_METHOD(Brisk_Kernel_App, getComponent);
PHP_METHOD(Brisk_Kernel_App, __get);
PHP_METHOD(Brisk_Kernel_App, setMethod);
PHP_METHOD(Brisk_Kernel_App, callMethod);
PHP_METHOD(Brisk_Kernel_App, __call);
PHP_METHOD(Brisk_Kernel_App, __destruct);
void zephir_init_static_properties_Brisk_Kernel_App(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_setbasedir, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_setconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_setcontrollerdir, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_setautoload, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_setcomponent, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_getcomponent, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_setmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_callmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app___call, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_app_method_entry) {
	PHP_ME(Brisk_Kernel_App, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Kernel_App, set, arginfo_brisk_kernel_app_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, setName, arginfo_brisk_kernel_app_setname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, setBaseDir, arginfo_brisk_kernel_app_setbasedir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, setConfig, arginfo_brisk_kernel_app_setconfig, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, setControllerDir, arginfo_brisk_kernel_app_setcontrollerdir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, getName, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, getBaseDir, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, getControllerDir, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, init, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, setAutoLoad, arginfo_brisk_kernel_app_setautoload, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, start, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, setComponent, arginfo_brisk_kernel_app_setcomponent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, getComponent, arginfo_brisk_kernel_app_getcomponent, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, __get, arginfo_brisk_kernel_app___get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, setMethod, arginfo_brisk_kernel_app_setmethod, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, callMethod, arginfo_brisk_kernel_app_callmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, __call, arginfo_brisk_kernel_app___call, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};