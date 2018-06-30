
extern zend_class_entry *brisk_kernel_container_ce;

ZEPHIR_INIT_CLASS(Brisk_Kernel_Container);

PHP_METHOD(Brisk_Kernel_Container, __construct);
PHP_METHOD(Brisk_Kernel_Container, hasKey);
PHP_METHOD(Brisk_Kernel_Container, hasValue);
PHP_METHOD(Brisk_Kernel_Container, getValue);
PHP_METHOD(Brisk_Kernel_Container, __get);
PHP_METHOD(Brisk_Kernel_Container, __set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_container___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_container_haskey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_container_getvalue, 0, 0, 0)
	ZEND_ARG_INFO(0, in_loop)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_container___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_kernel_container___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_kernel_container_method_entry) {
	PHP_ME(Brisk_Kernel_Container, __construct, arginfo_brisk_kernel_container___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Kernel_Container, hasKey, arginfo_brisk_kernel_container_haskey, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Container, hasValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Container, getValue, arginfo_brisk_kernel_container_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Container, __get, arginfo_brisk_kernel_container___get, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Kernel_Container, __set, arginfo_brisk_kernel_container___set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
