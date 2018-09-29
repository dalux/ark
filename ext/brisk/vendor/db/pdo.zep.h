
extern zend_class_entry *brisk_vendor_db_pdo_ce;

ZEPHIR_INIT_CLASS(Brisk_Vendor_Db_Pdo);

PHP_METHOD(Brisk_Vendor_Db_Pdo, __construct);
PHP_METHOD(Brisk_Vendor_Db_Pdo, query);
PHP_METHOD(Brisk_Vendor_Db_Pdo, fetchAll);
PHP_METHOD(Brisk_Vendor_Db_Pdo, fetchOne);
PHP_METHOD(Brisk_Vendor_Db_Pdo, fetchRow);
PHP_METHOD(Brisk_Vendor_Db_Pdo, beginTransaction);
PHP_METHOD(Brisk_Vendor_Db_Pdo, commit);
PHP_METHOD(Brisk_Vendor_Db_Pdo, rollback);
PHP_METHOD(Brisk_Vendor_Db_Pdo, inTransaction);
PHP_METHOD(Brisk_Vendor_Db_Pdo, nextInsertId);
PHP_METHOD(Brisk_Vendor_Db_Pdo, lastInsertId);
PHP_METHOD(Brisk_Vendor_Db_Pdo, lastRowCount);
PHP_METHOD(Brisk_Vendor_Db_Pdo, setFetchMode);
PHP_METHOD(Brisk_Vendor_Db_Pdo, getDriverName);
PHP_METHOD(Brisk_Vendor_Db_Pdo, getInstance);
PHP_METHOD(Brisk_Vendor_Db_Pdo, _query);
PHP_METHOD(Brisk_Vendor_Db_Pdo, _getConnection);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_db_pdo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_db_pdo_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_db_pdo_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_db_pdo_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_db_pdo_fetchrow, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_db_pdo_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, seq)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_db_pdo_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_db_pdo__query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_vendor_db_pdo__getconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_vendor_db_pdo_method_entry) {
	PHP_ME(Brisk_Vendor_Db_Pdo, __construct, arginfo_brisk_vendor_db_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Vendor_Db_Pdo, query, arginfo_brisk_vendor_db_pdo_query, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, fetchAll, arginfo_brisk_vendor_db_pdo_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, fetchOne, arginfo_brisk_vendor_db_pdo_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, fetchRow, arginfo_brisk_vendor_db_pdo_fetchrow, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, beginTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, inTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, nextInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, lastInsertId, arginfo_brisk_vendor_db_pdo_lastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, lastRowCount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, setFetchMode, arginfo_brisk_vendor_db_pdo_setfetchmode, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, getDriverName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Vendor_Db_Pdo, _query, arginfo_brisk_vendor_db_pdo__query, ZEND_ACC_PRIVATE)
	PHP_ME(Brisk_Vendor_Db_Pdo, _getConnection, arginfo_brisk_vendor_db_pdo__getconnection, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
