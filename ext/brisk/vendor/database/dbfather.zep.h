
extern zend_class_entry *brisk_vendor_database_dbfather_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Database_DbFather);

PHP_METHOD(Brisk_Vendor_Database_DbFather, query);
PHP_METHOD(Brisk_Vendor_Database_DbFather, fetchAll);
PHP_METHOD(Brisk_Vendor_Database_DbFather, fetchRow);
PHP_METHOD(Brisk_Vendor_Database_DbFather, fetchOne);
PHP_METHOD(Brisk_Vendor_Database_DbFather, beginTransaction);
PHP_METHOD(Brisk_Vendor_Database_DbFather, commit);
PHP_METHOD(Brisk_Vendor_Database_DbFather, rollback);
PHP_METHOD(Brisk_Vendor_Database_DbFather, inTransaction);
PHP_METHOD(Brisk_Vendor_Database_DbFather, lastInsertId);
PHP_METHOD(Brisk_Vendor_Database_DbFather, lastRowCount);
PHP_METHOD(Brisk_Vendor_Database_DbFather, getDriverName);
PHP_METHOD(Brisk_Vendor_Database_DbFather, getInstance);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbfather_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbfather_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbfather_fetchrow, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbfather_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_database_dbfather_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, seq)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_database_dbfather_method_entry) {
	PHP_ME(Brisk_Vendor_Database_DbFather, query, arginfo_brisk_vendor_database_dbfather_query, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Database_DbFather, fetchAll, arginfo_brisk_vendor_database_dbfather_fetchall, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Database_DbFather, fetchRow, arginfo_brisk_vendor_database_dbfather_fetchrow, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Database_DbFather, fetchOne, arginfo_brisk_vendor_database_dbfather_fetchone, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Database_DbFather, beginTransaction, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Database_DbFather, commit, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Database_DbFather, rollback, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Database_DbFather, inTransaction, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Database_DbFather, lastInsertId, arginfo_brisk_vendor_database_dbfather_lastinsertid, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Database_DbFather, lastRowCount, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Database_DbFather, getDriverName, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Vendor_Database_DbFather, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_FE_END
};
