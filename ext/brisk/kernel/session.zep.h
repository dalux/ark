
extern zend_class_entry *brisk_kernel_session_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Session);

PHP_METHOD(Brisk_Kernel_Session, start);
PHP_METHOD(Brisk_Kernel_Session, get);
PHP_METHOD(Brisk_Kernel_Session, set);
PHP_METHOD(Brisk_Kernel_Session, delete);
PHP_METHOD(Brisk_Kernel_Session, clean);
PHP_METHOD(Brisk_Kernel_Session, __get);
PHP_METHOD(Brisk_Kernel_Session, __set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_session_start, 0, 0, 0)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_session_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_session_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_session_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_session___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_session___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_session_method_entry) {
	PHP_ME(Brisk_Kernel_Session, start, arginfo_brisk_kernel_session_start, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Session, get, arginfo_brisk_kernel_session_get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Session, set, arginfo_brisk_kernel_session_set, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Session, delete, arginfo_brisk_kernel_session_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Session, clean, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Session, __get, arginfo_brisk_kernel_session___get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Session, __set, arginfo_brisk_kernel_session___set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
