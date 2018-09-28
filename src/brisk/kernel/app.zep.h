
extern zend_class_entry *brisk_kernel_app_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_App);

PHP_METHOD(Brisk_Kernel_App, setConfig);
PHP_METHOD(Brisk_Kernel_App, __construct);
PHP_METHOD(Brisk_Kernel_App, getInstance);
PHP_METHOD(Brisk_Kernel_App, setAlias);
PHP_METHOD(Brisk_Kernel_App, setNameSpace);
PHP_METHOD(Brisk_Kernel_App, addLanguageFile);
PHP_METHOD(Brisk_Kernel_App, setLanguage);
PHP_METHOD(Brisk_Kernel_App, addEvent);
PHP_METHOD(Brisk_Kernel_App, start);
PHP_METHOD(Brisk_Kernel_App, setComponent);
PHP_METHOD(Brisk_Kernel_App, getComponent);
PHP_METHOD(Brisk_Kernel_App, __get);
PHP_METHOD(Brisk_Kernel_App, setMethod);
PHP_METHOD(Brisk_Kernel_App, callMethod);
PHP_METHOD(Brisk_Kernel_App, __call);
PHP_METHOD(Brisk_Kernel_App, __destruct);
void zephir_init_static_properties_Brisk_Kernel_App(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_setconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_setalias, 0, 0, 2)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_setnamespace, 0, 0, 2)
	ZEND_ARG_INFO(0, nspace)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_addlanguagefile, 0, 0, 2)
	ZEND_ARG_INFO(0, language)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_setlanguage, 0, 0, 1)
	ZEND_ARG_INFO(0, language)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_app_addevent, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, listener)
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
	PHP_ME(Brisk_Kernel_App, setConfig, arginfo_brisk_kernel_app_setconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Kernel_App, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_App, setAlias, arginfo_brisk_kernel_app_setalias, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, setNameSpace, arginfo_brisk_kernel_app_setnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, addLanguageFile, arginfo_brisk_kernel_app_addlanguagefile, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, setLanguage, arginfo_brisk_kernel_app_setlanguage, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, addEvent, arginfo_brisk_kernel_app_addevent, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, setComponent, arginfo_brisk_kernel_app_setcomponent, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, getComponent, arginfo_brisk_kernel_app_getcomponent, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, __get, arginfo_brisk_kernel_app___get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, setMethod, arginfo_brisk_kernel_app_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, callMethod, arginfo_brisk_kernel_app_callmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, __call, arginfo_brisk_kernel_app___call, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_App, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
