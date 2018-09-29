
extern zend_class_entry *brisk_kernel_toolkit_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Toolkit);

PHP_METHOD(Brisk_Kernel_Toolkit, sprintr);
PHP_METHOD(Brisk_Kernel_Toolkit, printr);
PHP_METHOD(Brisk_Kernel_Toolkit, svardump);
PHP_METHOD(Brisk_Kernel_Toolkit, vardump);
PHP_METHOD(Brisk_Kernel_Toolkit, mkDir);
PHP_METHOD(Brisk_Kernel_Toolkit, copyDir);
PHP_METHOD(Brisk_Kernel_Toolkit, removeDir);
PHP_METHOD(Brisk_Kernel_Toolkit, includeOnce);
PHP_METHOD(Brisk_Kernel_Toolkit, classDeclared);
PHP_METHOD(Brisk_Kernel_Toolkit, fileIncluded);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_toolkit_sprintr, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_toolkit_printr, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_toolkit_svardump, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_toolkit_vardump, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

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

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_toolkit_includeonce, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_toolkit_classdeclared, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_toolkit_fileincluded, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_toolkit_method_entry) {
	PHP_ME(Brisk_Kernel_Toolkit, sprintr, arginfo_brisk_kernel_toolkit_sprintr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, printr, arginfo_brisk_kernel_toolkit_printr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, svardump, arginfo_brisk_kernel_toolkit_svardump, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, vardump, arginfo_brisk_kernel_toolkit_vardump, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, mkDir, arginfo_brisk_kernel_toolkit_mkdir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, copyDir, arginfo_brisk_kernel_toolkit_copydir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, removeDir, arginfo_brisk_kernel_toolkit_removedir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, includeOnce, arginfo_brisk_kernel_toolkit_includeonce, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, classDeclared, arginfo_brisk_kernel_toolkit_classdeclared, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Toolkit, fileIncluded, arginfo_brisk_kernel_toolkit_fileincluded, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
