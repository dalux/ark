
extern zend_class_entry *brisk_session_sessionadapter_ce;

ZEPHIR_INIT_CLASS(Brisk_Session_SessionAdapter);

PHP_METHOD(Brisk_Session_SessionAdapter, getDriverFromConfig);

ZEPHIR_INIT_FUNCS(brisk_session_sessionadapter_method_entry) {
	PHP_ME(Brisk_Session_SessionAdapter, getDriverFromConfig, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
