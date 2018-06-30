
extern zend_class_entry *brisk_kernel_event_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Event);

PHP_METHOD(Brisk_Kernel_Event, addListener);
PHP_METHOD(Brisk_Kernel_Event, getListener);
PHP_METHOD(Brisk_Kernel_Event, removeListener);
PHP_METHOD(Brisk_Kernel_Event, onListening);
void zephir_init_static_properties_Brisk_Kernel_Event(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_event_addlistener, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, listener)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_event_getlistener, 0, 0, 0)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_event_removelistener, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_event_onlistening, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_event_method_entry) {
	PHP_ME(Brisk_Kernel_Event, addListener, arginfo_brisk_kernel_event_addlistener, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Event, getListener, arginfo_brisk_kernel_event_getlistener, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Event, removeListener, arginfo_brisk_kernel_event_removelistener, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Event, onListening, arginfo_brisk_kernel_event_onlistening, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
