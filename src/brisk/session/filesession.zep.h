
extern zend_class_entry *brisk_session_filesession_ce;

ZEPHIR_INIT_CLASS(Brisk_Session_FileSession);

PHP_METHOD(Brisk_Session_FileSession, __construct);

ZEPHIR_INIT_FUNCS(brisk_session_filesession_method_entry) {
	PHP_ME(Brisk_Session_FileSession, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
