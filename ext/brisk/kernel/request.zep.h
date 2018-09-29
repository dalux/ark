
extern zend_class_entry *brisk_kernel_request_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Request);

PHP_METHOD(Brisk_Kernel_Request, setData);
PHP_METHOD(Brisk_Kernel_Request, setReady);
PHP_METHOD(Brisk_Kernel_Request, getInstance);
PHP_METHOD(Brisk_Kernel_Request, __construct);
PHP_METHOD(Brisk_Kernel_Request, isPost);
PHP_METHOD(Brisk_Kernel_Request, isAjax);
PHP_METHOD(Brisk_Kernel_Request, getIpAddress);
PHP_METHOD(Brisk_Kernel_Request, add);
PHP_METHOD(Brisk_Kernel_Request, del);
PHP_METHOD(Brisk_Kernel_Request, data);
PHP_METHOD(Brisk_Kernel_Request, __get);
void zephir_init_static_properties_Brisk_Kernel_Request(TSRMLS_D);
zend_object_value zephir_init_properties_Brisk_Kernel_Request(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_request_setdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_request_setready, 0, 0, 1)
	ZEND_ARG_INFO(0, state)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_request_getipaddress, 0, 0, 0)
	ZEND_ARG_INFO(0, convert)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_request_add, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_request_del, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_request_data, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, alternative)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_request___get, 0, 0, 1)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_request_method_entry) {
	PHP_ME(Brisk_Kernel_Request, setData, arginfo_brisk_kernel_request_setdata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Request, setReady, arginfo_brisk_kernel_request_setready, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Request, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Request, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Kernel_Request, isPost, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Request, isAjax, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Request, getIpAddress, arginfo_brisk_kernel_request_getipaddress, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Request, add, arginfo_brisk_kernel_request_add, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Request, del, arginfo_brisk_kernel_request_del, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Request, data, arginfo_brisk_kernel_request_data, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Request, __get, arginfo_brisk_kernel_request___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
