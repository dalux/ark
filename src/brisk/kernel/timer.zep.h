
extern zend_class_entry *brisk_kernel_timer_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Timer);

PHP_METHOD(Brisk_Kernel_Timer, mark);
PHP_METHOD(Brisk_Kernel_Timer, isMarked);
PHP_METHOD(Brisk_Kernel_Timer, lastUsed);
PHP_METHOD(Brisk_Kernel_Timer, totalUsed);
PHP_METHOD(Brisk_Kernel_Timer, pick);
void zephir_init_static_properties_Brisk_Kernel_Timer(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_timer_mark, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_timer_ismarked, 0, 0, 1)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_timer_pick, 0, 0, 2)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_timer_method_entry) {
	PHP_ME(Brisk_Kernel_Timer, mark, arginfo_brisk_kernel_timer_mark, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Timer, isMarked, arginfo_brisk_kernel_timer_ismarked, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Timer, lastUsed, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Timer, totalUsed, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Kernel_Timer, pick, arginfo_brisk_kernel_timer_pick, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
