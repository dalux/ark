
extern zend_class_entry *brisk_kernel_loader_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Loader);

PHP_METHOD(Brisk_Kernel_Loader, setAlias);
PHP_METHOD(Brisk_Kernel_Loader, setNameSpace);
PHP_METHOD(Brisk_Kernel_Loader, getAlias);
PHP_METHOD(Brisk_Kernel_Loader, getNameSpace);
PHP_METHOD(Brisk_Kernel_Loader, autoLoad);
PHP_METHOD(Brisk_Kernel_Loader, findClass);
PHP_METHOD(Brisk_Kernel_Loader, realPath);
PHP_METHOD(Brisk_Kernel_Loader, reducePath);
PHP_METHOD(Brisk_Kernel_Loader, _parse);
void zephir_init_static_properties_Brisk_Kernel_Loader(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_loader_setalias, 0, 0, 2)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_loader_setnamespace, 0, 0, 2)
	ZEND_ARG_INFO(0, nspace)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_loader_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_loader_findclass, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_loader_realpath, 0, 0, 1)
	ZEND_ARG_INFO(0, spacename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_loader_reducepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_loader__parse, 0, 0, 1)
	ZEND_ARG_INFO(0, nspace)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_loader_method_entry) {
	PHP_ME(Brisk_Kernel_Loader, setAlias, arginfo_brisk_kernel_loader_setalias, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Loader, setNameSpace, arginfo_brisk_kernel_loader_setnamespace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Loader, getAlias, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Loader, getNameSpace, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Loader, autoLoad, arginfo_brisk_kernel_loader_autoload, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Loader, findClass, arginfo_brisk_kernel_loader_findclass, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Loader, realPath, arginfo_brisk_kernel_loader_realpath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Loader, reducePath, arginfo_brisk_kernel_loader_reducepath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Loader, _parse, arginfo_brisk_kernel_loader__parse, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
