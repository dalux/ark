
extern zend_class_entry *brisk_vendor_querier_querieradapter_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_QuerierAdapter);

PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, setDbType);
PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, getQuerier);
PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, getSelectQuerier);
PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, getInsertQuerier);
PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, getUpdateQuerier);
PHP_METHOD(Brisk_Vendor_Querier_QuerierAdapter, getDeleteQuerier);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querieradapter_setdbtype, 0, 0, 1)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querieradapter_getquerier, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querieradapter_getselectquerier, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querieradapter_getinsertquerier, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querieradapter_getupdatequerier, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_querier_querieradapter_getdeletequerier, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_querier_querieradapter_method_entry) {
	PHP_ME(Brisk_Vendor_Querier_QuerierAdapter, setDbType, arginfo_brisk_vendor_querier_querieradapter_setdbtype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierAdapter, getQuerier, arginfo_brisk_vendor_querier_querieradapter_getquerier, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierAdapter, getSelectQuerier, arginfo_brisk_vendor_querier_querieradapter_getselectquerier, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierAdapter, getInsertQuerier, arginfo_brisk_vendor_querier_querieradapter_getinsertquerier, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierAdapter, getUpdateQuerier, arginfo_brisk_vendor_querier_querieradapter_getupdatequerier, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Vendor_Querier_QuerierAdapter, getDeleteQuerier, arginfo_brisk_vendor_querier_querieradapter_getdeletequerier, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
