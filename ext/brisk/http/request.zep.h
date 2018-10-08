
extern zend_class_entry *brisk_http_request_ce;

ZEPHIR_INIT_CLASS(Brisk_Http_Request);

PHP_METHOD(Brisk_Http_Request, setData);
PHP_METHOD(Brisk_Http_Request, setReady);
PHP_METHOD(Brisk_Http_Request, getInstance);
PHP_METHOD(Brisk_Http_Request, __construct);
PHP_METHOD(Brisk_Http_Request, isPost);
PHP_METHOD(Brisk_Http_Request, isAjax);
PHP_METHOD(Brisk_Http_Request, getIpAddress);
PHP_METHOD(Brisk_Http_Request, get);
PHP_METHOD(Brisk_Http_Request, addGetData);
PHP_METHOD(Brisk_Http_Request, delGetData);
PHP_METHOD(Brisk_Http_Request, post);
PHP_METHOD(Brisk_Http_Request, addPostData);
PHP_METHOD(Brisk_Http_Request, delPostData);
PHP_METHOD(Brisk_Http_Request, cookie);
PHP_METHOD(Brisk_Http_Request, files);
PHP_METHOD(Brisk_Http_Request, data);
void zephir_init_static_properties_Brisk_Http_Request(TSRMLS_D);
zend_object_value zephir_init_properties_Brisk_Http_Request(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_setdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_setready, 0, 0, 1)
	ZEND_ARG_INFO(0, state)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_getipaddress, 0, 0, 0)
	ZEND_ARG_INFO(0, convert)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, alternative)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_addgetdata, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_delgetdata, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_post, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, alternative)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_addpostdata, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_delpostdata, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_cookie, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, alternative)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_files, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, alternative)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_request_data, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, alternative)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_http_request_method_entry) {
	PHP_ME(Brisk_Http_Request, setData, arginfo_brisk_http_request_setdata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Request, setReady, arginfo_brisk_http_request_setready, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Request, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Request, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Http_Request, isPost, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Request, isAjax, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Request, getIpAddress, arginfo_brisk_http_request_getipaddress, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Request, get, arginfo_brisk_http_request_get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Http_Request, addGetData, arginfo_brisk_http_request_addgetdata, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Http_Request, delGetData, arginfo_brisk_http_request_delgetdata, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Http_Request, post, arginfo_brisk_http_request_post, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Http_Request, addPostData, arginfo_brisk_http_request_addpostdata, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Http_Request, delPostData, arginfo_brisk_http_request_delpostdata, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Http_Request, cookie, arginfo_brisk_http_request_cookie, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Http_Request, files, arginfo_brisk_http_request_files, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Http_Request, data, arginfo_brisk_http_request_data, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
