
extern zend_class_entry *brisk_http_server_ce;

ZEPHIR_INIT_CLASS(Brisk_Http_Server);

PHP_METHOD(Brisk_Http_Server, isCli);
PHP_METHOD(Brisk_Http_Server, getDomain);
PHP_METHOD(Brisk_Http_Server, getSubDomain);
PHP_METHOD(Brisk_Http_Server, initCli);
PHP_METHOD(Brisk_Http_Server, getItem);
void zephir_init_static_properties_Brisk_Http_Server(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_server_getdomain, 0, 0, 0)
	ZEND_ARG_INFO(0, reduce)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_http_server_getitem, 0, 0, 0)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_http_server_method_entry) {
	PHP_ME(Brisk_Http_Server, isCli, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Server, getDomain, arginfo_brisk_http_server_getdomain, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Server, getSubDomain, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Server, initCli, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Http_Server, getItem, arginfo_brisk_http_server_getitem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
