
extern zend_class_entry *brisk_session_usersession_ce;

ZEPHIR_INIT_CLASS(Brisk_Session_UserSession);

PHP_METHOD(Brisk_Session_UserSession, __construct);
PHP_METHOD(Brisk_Session_UserSession, open);
PHP_METHOD(Brisk_Session_UserSession, close);
PHP_METHOD(Brisk_Session_UserSession, read);
PHP_METHOD(Brisk_Session_UserSession, write);
PHP_METHOD(Brisk_Session_UserSession, destroy);
PHP_METHOD(Brisk_Session_UserSession, gc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_usersession_open, 0, 0, 2)
	ZEND_ARG_INFO(0, save_path)
	ZEND_ARG_INFO(0, session_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_usersession_read, 0, 0, 1)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_usersession_write, 0, 0, 2)
	ZEND_ARG_INFO(0, session_id)
	ZEND_ARG_INFO(0, session_data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_usersession_destroy, 0, 0, 1)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_usersession_gc, 0, 0, 1)
	ZEND_ARG_INFO(0, max_lifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_session_usersession_method_entry) {
	PHP_ME(Brisk_Session_UserSession, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Session_UserSession, open, arginfo_brisk_session_usersession_open, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_UserSession, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_UserSession, read, arginfo_brisk_session_usersession_read, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_UserSession, write, arginfo_brisk_session_usersession_write, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_UserSession, destroy, arginfo_brisk_session_usersession_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_UserSession, gc, arginfo_brisk_session_usersession_gc, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
