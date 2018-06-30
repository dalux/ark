
extern zend_class_entry *brisk_kernel_toolkit_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Toolkit);

PHP_METHOD(Brisk_Kernel_Toolkit, sprintr);
PHP_METHOD(Brisk_Kernel_Toolkit, printr);
PHP_METHOD(Brisk_Kernel_Toolkit, svardump);
PHP_METHOD(Brisk_Kernel_Toolkit, vardump);
PHP_METHOD(Brisk_Kernel_Toolkit, mkDir);
PHP_METHOD(Brisk_Kernel_Toolkit, copyDir);
PHP_METHOD(Brisk_Kernel_Toolkit, removeDir);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_toolkit_mkdir, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_toolkit_copydir, 0, 0, 2)
	ZEND_ARG_INFO(0, src)
	ZEND_ARG_INFO(0, dst)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_toolkit_removedir, 0, 0, 1)
	ZEND_ARG_INFO(0, dir_name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_toolkit_method_entry) {
	PHP_ME(Brisk_Kernel_Toolkit, sprintr, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, printr, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, svardump, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, vardump, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, mkDir, arginfo_brisk_kernel_toolkit_mkdir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, copyDir, arginfo_brisk_kernel_toolkit_copydir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, removeDir, arginfo_brisk_kernel_toolkit_removedir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
