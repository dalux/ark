
extern zend_class_entry *brisk_session_sessionfather_ce;

ZEPHIR_INIT_CLASS(Brisk_Session_SessionFather);

PHP_METHOD(Brisk_Session_SessionFather, start);
PHP_METHOD(Brisk_Session_SessionFather, get);
PHP_METHOD(Brisk_Session_SessionFather, set);
PHP_METHOD(Brisk_Session_SessionFather, delete);
PHP_METHOD(Brisk_Session_SessionFather, clean);
PHP_METHOD(Brisk_Session_SessionFather, __get);
PHP_METHOD(Brisk_Session_SessionFather, __set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_sessionfather_start, 0, 0, 0)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_sessionfather_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_sessionfather_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_sessionfather_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_sessionfather___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_sessionfather___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_session_sessionfather_method_entry) {
	PHP_ME(Brisk_Session_SessionFather, start, arginfo_brisk_session_sessionfather_start, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_SessionFather, get, arginfo_brisk_session_sessionfather_get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_SessionFather, set, arginfo_brisk_session_sessionfather_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_SessionFather, delete, arginfo_brisk_session_sessionfather_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_SessionFather, clean, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_SessionFather, __get, arginfo_brisk_session_sessionfather___get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Session_SessionFather, __set, arginfo_brisk_session_sessionfather___set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
