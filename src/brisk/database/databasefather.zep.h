
extern zend_class_entry *brisk_database_databasefather_ce;

ZEPHIR_INIT_CLASS(Brisk_Database_DatabaseFather);

PHP_METHOD(Brisk_Database_DatabaseFather, query);
PHP_METHOD(Brisk_Database_DatabaseFather, fetchAll);
PHP_METHOD(Brisk_Database_DatabaseFather, fetchRow);
PHP_METHOD(Brisk_Database_DatabaseFather, fetchOne);
PHP_METHOD(Brisk_Database_DatabaseFather, beginTransaction);
PHP_METHOD(Brisk_Database_DatabaseFather, commit);
PHP_METHOD(Brisk_Database_DatabaseFather, rollback);
PHP_METHOD(Brisk_Database_DatabaseFather, inTransaction);
PHP_METHOD(Brisk_Database_DatabaseFather, lastInsertId);
PHP_METHOD(Brisk_Database_DatabaseFather, lastRowCount);
PHP_METHOD(Brisk_Database_DatabaseFather, getDriverName);
PHP_METHOD(Brisk_Database_DatabaseFather, getInstance);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_databasefather_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_databasefather_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_databasefather_fetchrow, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_databasefather_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_databasefather_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, seq)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_database_databasefather_method_entry) {
	PHP_ME(Brisk_Database_DatabaseFather, query, arginfo_brisk_database_databasefather_query, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Database_DatabaseFather, fetchAll, arginfo_brisk_database_databasefather_fetchall, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Database_DatabaseFather, fetchRow, arginfo_brisk_database_databasefather_fetchrow, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Database_DatabaseFather, fetchOne, arginfo_brisk_database_databasefather_fetchone, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Database_DatabaseFather, beginTransaction, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Database_DatabaseFather, commit, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Database_DatabaseFather, rollback, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Database_DatabaseFather, inTransaction, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Database_DatabaseFather, lastInsertId, arginfo_brisk_database_databasefather_lastinsertid, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Database_DatabaseFather, lastRowCount, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Database_DatabaseFather, getDriverName, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Brisk_Database_DatabaseFather, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_FE_END
};
