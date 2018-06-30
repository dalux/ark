
extern zend_class_entry *brisk_kernel_response_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Response);

PHP_METHOD(Brisk_Kernel_Response, status);
PHP_METHOD(Brisk_Kernel_Response, cookie);
PHP_METHOD(Brisk_Kernel_Response, redirect);
PHP_METHOD(Brisk_Kernel_Response, alert);
PHP_METHOD(Brisk_Kernel_Response, noCache);
PHP_METHOD(Brisk_Kernel_Response, expires);
PHP_METHOD(Brisk_Kernel_Response, header);
zend_object *zephir_init_properties_Brisk_Kernel_Response(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_response_status, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_response_cookie, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, val)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, httponly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_response_redirect, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, script)
	ZEND_ARG_INFO(0, msg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_response_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_response_expires, 0, 0, 0)
	ZEND_ARG_INFO(0, sec)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_response_header, 0, 0, 0)
	ZEND_ARG_INFO(0, item)
	ZEND_ARG_INFO(0, val)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_response_method_entry) {
	PHP_ME(Brisk_Kernel_Response, status, arginfo_brisk_kernel_response_status, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Response, cookie, arginfo_brisk_kernel_response_cookie, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Response, redirect, arginfo_brisk_kernel_response_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Response, alert, arginfo_brisk_kernel_response_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Response, noCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Response, expires, arginfo_brisk_kernel_response_expires, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Response, header, arginfo_brisk_kernel_response_header, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
