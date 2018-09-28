
extern zend_class_entry *brisk_kernel_handler_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Handler);

PHP_METHOD(Brisk_Kernel_Handler, setHandler);
PHP_METHOD(Brisk_Kernel_Handler, _getSource);
PHP_METHOD(Brisk_Kernel_Handler, usortfunc);
PHP_METHOD(Brisk_Kernel_Handler, display);
PHP_METHOD(Brisk_Kernel_Handler, _getWebTpl);
PHP_METHOD(Brisk_Kernel_Handler, _getCliTpl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_handler_sethandler, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_handler__getsource, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, trace, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_handler_usortfunc, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_handler_display, 0, 0, 1)
	ZEND_ARG_INFO(0, e)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_handler_method_entry) {
	PHP_ME(Brisk_Kernel_Handler, setHandler, arginfo_brisk_kernel_handler_sethandler, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Handler, _getSource, arginfo_brisk_kernel_handler__getsource, ZEND_ACC_PRIVATE)
	PHP_ME(Brisk_Kernel_Handler, usortfunc, arginfo_brisk_kernel_handler_usortfunc, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Handler, display, arginfo_brisk_kernel_handler_display, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Handler, _getWebTpl, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Brisk_Kernel_Handler, _getCliTpl, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
