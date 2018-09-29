
extern zend_class_entry *brisk_vendor_database_dbquerier_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Database_DbQuerier);

PHP_METHOD(Brisk_Vendor_Database_DbQuerier, setConnection);
PHP_METHOD(Brisk_Vendor_Database_DbQuerier, getConnection);
PHP_METHOD(Brisk_Vendor_Database_DbQuerier, __construct);
PHP_METHOD(Brisk_Vendor_Database_DbQuerier, forTable);
PHP_METHOD(Brisk_Vendor_Database_DbQuerier, cache);
PHP_METHOD(Brisk_Vendor_Database_DbQuerier, insert);
PHP_METHOD(Brisk_Vendor_Database_DbQuerier, update);
PHP_METHOD(Brisk_Vendor_Database_DbQuerier, delete);
PHP_METHOD(Brisk_Vendor_Database_DbQuerier, fetchRow);
PHP_METHOD(Brisk_Vendor_Database_DbQuerier, fetchOne);
PHP_METHOD(Brisk_Vendor_Database_DbQuerier, fetchAll);
zend_object_value zephir_init_properties_Brisk_Vendor_Database_DbQuerier(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbquerier_setconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, conn, Brisk\\Vendor\\Database\\DbFather, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbquerier___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, tb)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbquerier_fortable, 0, 0, 1)
	ZEND_ARG_INFO(0, tb)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbquerier_cache, 0, 0, 2)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_OBJ_INFO(0, cache, Brisk\\Vendor\\Cache\\CacheFather, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbquerier_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, return_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbquerier_update, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, condition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbquerier_delete, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, condition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbquerier_fetchrow, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, condition, 0)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbquerier_fetchone, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, condition, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbquerier_fetchall, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, condition, 1)
	ZEND_ARG_ARRAY_INFO(0, order, 1)
	ZEND_ARG_INFO(0, count)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_database_dbquerier_method_entry) {
	PHP_ME(Brisk_Vendor_Database_DbQuerier, setConnection, arginfo_brisk_vendor_database_dbquerier_setconnection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Vendor_Database_DbQuerier, getConnection, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Vendor_Database_DbQuerier, __construct, arginfo_brisk_vendor_database_dbquerier___construct, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Vendor_Database_DbQuerier, forTable, arginfo_brisk_vendor_database_dbquerier_fortable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Vendor_Database_DbQuerier, cache, arginfo_brisk_vendor_database_dbquerier_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Database_DbQuerier, insert, arginfo_brisk_vendor_database_dbquerier_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Database_DbQuerier, update, arginfo_brisk_vendor_database_dbquerier_update, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Database_DbQuerier, delete, arginfo_brisk_vendor_database_dbquerier_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Database_DbQuerier, fetchRow, arginfo_brisk_vendor_database_dbquerier_fetchrow, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Database_DbQuerier, fetchOne, arginfo_brisk_vendor_database_dbquerier_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Database_DbQuerier, fetchAll, arginfo_brisk_vendor_database_dbquerier_fetchall, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
