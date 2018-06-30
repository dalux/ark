
extern zend_class_entry *brisk_kernel_config_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Config);

PHP_METHOD(Brisk_Kernel_Config, getExample);
PHP_METHOD(Brisk_Kernel_Config, saveToFile);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_config_savetofile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_config_method_entry) {
	PHP_ME(Brisk_Kernel_Config, getExample, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Config, saveToFile, arginfo_brisk_kernel_config_savetofile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
