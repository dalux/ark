
extern zend_class_entry *brisk_session_userhandler_ce;

ZEPHIR_INIT_CLASS(Brisk_Session_UserHandler);

PHP_METHOD(Brisk_Session_UserHandler, __construct);
PHP_METHOD(Brisk_Session_UserHandler, open);
PHP_METHOD(Brisk_Session_UserHandler, close);
PHP_METHOD(Brisk_Session_UserHandler, read);
PHP_METHOD(Brisk_Session_UserHandler, write);
PHP_METHOD(Brisk_Session_UserHandler, destroy);
PHP_METHOD(Brisk_Session_UserHandler, gc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_userhandler___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cache, Brisk\\Session\\CacheFather, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_userhandler_open, 0, 0, 2)
	ZEND_ARG_INFO(0, save_path)
	ZEND_ARG_INFO(0, session_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_userhandler_read, 0, 0, 1)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_userhandler_write, 0, 0, 2)
	ZEND_ARG_INFO(0, session_id)
	ZEND_ARG_INFO(0, session_data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_userhandler_destroy, 0, 0, 1)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_userhandler_gc, 0, 0, 1)
	ZEND_ARG_INFO(0, max_lifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_session_userhandler_method_entry) {
	PHP_ME(Brisk_Session_UserHandler, __construct, arginfo_brisk_session_userhandler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Session_UserHandler, open, arginfo_brisk_session_userhandler_open, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_UserHandler, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_UserHandler, read, arginfo_brisk_session_userhandler_read, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_UserHandler, write, arginfo_brisk_session_userhandler_write, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_UserHandler, destroy, arginfo_brisk_session_userhandler_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_UserHandler, gc, arginfo_brisk_session_userhandler_gc, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
