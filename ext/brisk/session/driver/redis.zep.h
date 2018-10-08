
extern zend_class_entry *brisk_session_driver_redis_ce;

ZEPHIR_INIT_CLASS(Brisk_Session_Driver_Redis);

PHP_METHOD(Brisk_Session_Driver_Redis, __construct);
PHP_METHOD(Brisk_Session_Driver_Redis, start);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_driver_redis___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_session_driver_redis_start, 0, 0, 0)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_session_driver_redis_method_entry) {
	PHP_ME(Brisk_Session_Driver_Redis, __construct, arginfo_brisk_session_driver_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Session_Driver_Redis, start, arginfo_brisk_session_driver_redis_start, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
