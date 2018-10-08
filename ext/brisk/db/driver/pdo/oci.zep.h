
extern zend_class_entry *brisk_db_driver_pdo_oci_ce;

ZEPHIR_INIT_CLASS(Brisk_Db_Driver_Pdo_Oci);

PHP_METHOD(Brisk_Db_Driver_Pdo_Oci, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_driver_pdo_oci___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
	ZEND_ARG_ARRAY_INFO(0, setting, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_db_driver_pdo_oci_method_entry) {
	PHP_ME(Brisk_Db_Driver_Pdo_Oci, __construct, arginfo_brisk_db_driver_pdo_oci___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
