
extern zend_class_entry *brisk_kernel_language_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Language);

PHP_METHOD(Brisk_Kernel_Language, addPackage);
PHP_METHOD(Brisk_Kernel_Language, setLanguage);
PHP_METHOD(Brisk_Kernel_Language, get);
void zephir_init_static_properties_Brisk_Kernel_Language(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_language_addpackage, 0, 0, 2)
	ZEND_ARG_INFO(0, language)
	ZEND_ARG_ARRAY_INFO(0, package, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_language_setlanguage, 0, 0, 1)
	ZEND_ARG_INFO(0, language)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_language_get, 0, 0, 1)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_language_method_entry) {
	PHP_ME(Brisk_Kernel_Language, addPackage, arginfo_brisk_kernel_language_addpackage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Language, setLanguage, arginfo_brisk_kernel_language_setlanguage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Language, get, arginfo_brisk_kernel_language_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
