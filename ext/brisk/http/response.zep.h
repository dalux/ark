
extern zend_class_entry *brisk_http_response_ce;

ZEPHIR_INIT_CLASS(Brisk_Http_Response);

PHP_METHOD(Brisk_Http_Response, status);
PHP_METHOD(Brisk_Http_Response, cookie);
PHP_METHOD(Brisk_Http_Response, redirect);
PHP_METHOD(Brisk_Http_Response, alert);
PHP_METHOD(Brisk_Http_Response, noCache);
PHP_METHOD(Brisk_Http_Response, expires);
PHP_METHOD(Brisk_Http_Response, header);
void zephir_init_static_properties_Brisk_Http_Response(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_response_status, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_response_cookie, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, httponly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_response_redirect, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, script)
	ZEND_ARG_INFO(0, msg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_response_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_response_expires, 0, 0, 0)
	ZEND_ARG_INFO(0, sec)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_response_header, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, is_replace)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_http_response_method_entry) {
	PHP_ME(Brisk_Http_Response, status, arginfo_brisk_http_response_status, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Response, cookie, arginfo_brisk_http_response_cookie, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Response, redirect, arginfo_brisk_http_response_redirect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Response, alert, arginfo_brisk_http_response_alert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Response, noCache, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Response, expires, arginfo_brisk_http_response_expires, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Response, header, arginfo_brisk_http_response_header, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
