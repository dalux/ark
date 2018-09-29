
extern zend_class_entry *brisk_kernel_event_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Event);

PHP_METHOD(Brisk_Kernel_Event, add);
PHP_METHOD(Brisk_Kernel_Event, get);
PHP_METHOD(Brisk_Kernel_Event, fire);
void zephir_init_static_properties_Brisk_Kernel_Event(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_event_add, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, listener)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_event_get, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_event_fire, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_event_method_entry) {
	PHP_ME(Brisk_Kernel_Event, add, arginfo_brisk_kernel_event_add, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Event, get, arginfo_brisk_kernel_event_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Event, fire, arginfo_brisk_kernel_event_fire, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
