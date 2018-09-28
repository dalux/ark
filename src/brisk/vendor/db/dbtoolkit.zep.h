
extern zend_class_entry *brisk_vendor_db_dbtoolkit_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Db_DbToolkit);

PHP_METHOD(Brisk_Vendor_Db_DbToolkit, parseConnectUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_db_dbtoolkit_parseconnecturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_db_dbtoolkit_method_entry) {
	PHP_ME(Brisk_Vendor_Db_DbToolkit, parseConnectUrl, arginfo_brisk_vendor_db_dbtoolkit_parseconnecturl, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
