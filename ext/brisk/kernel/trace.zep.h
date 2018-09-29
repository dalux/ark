
extern zend_class_entry *brisk_kernel_trace_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Trace);

PHP_METHOD(Brisk_Kernel_Trace, set);
PHP_METHOD(Brisk_Kernel_Trace, get);
void zephir_init_static_properties_Brisk_Kernel_Trace(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_trace_set, 0, 0, 2)
	ZEND_ARG_INFO(0, flag)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_trace_get, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_trace_method_entry) {
	PHP_ME(Brisk_Kernel_Trace, set, arginfo_brisk_kernel_trace_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Trace, get, arginfo_brisk_kernel_trace_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
