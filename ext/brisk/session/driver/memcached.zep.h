
extern zend_class_entry *brisk_session_driver_memcached_ce;

ZEPHIR_INIT_CLASS(Brisk_Session_Driver_Memcached);

PHP_METHOD(Brisk_Session_Driver_Memcached, __construct);
PHP_METHOD(Brisk_Session_Driver_Memcached, start);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_driver_memcached___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_driver_memcached_start, 0, 0, 0)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_session_driver_memcached_method_entry) {
	PHP_ME(Brisk_Session_Driver_Memcached, __construct, arginfo_brisk_session_driver_memcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Session_Driver_Memcached, start, arginfo_brisk_session_driver_memcached_start, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
