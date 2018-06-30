
extern zend_class_entry *brisk_database_pdodriver_ce;

ZEPHIR_INIT_CLASS(Brisk_Database_PdoDriver);

PHP_METHOD(Brisk_Database_PdoDriver, __construct);
PHP_METHOD(Brisk_Database_PdoDriver, _query);
PHP_METHOD(Brisk_Database_PdoDriver, query);
PHP_METHOD(Brisk_Database_PdoDriver, fetchAll);
PHP_METHOD(Brisk_Database_PdoDriver, fetchOne);
PHP_METHOD(Brisk_Database_PdoDriver, fetchRow);
PHP_METHOD(Brisk_Database_PdoDriver, beginTransaction);
PHP_METHOD(Brisk_Database_PdoDriver, commit);
PHP_METHOD(Brisk_Database_PdoDriver, rollback);
PHP_METHOD(Brisk_Database_PdoDriver, inTransaction);
PHP_METHOD(Brisk_Database_PdoDriver, nextInsertId);
PHP_METHOD(Brisk_Database_PdoDriver, lastInsertId);
PHP_METHOD(Brisk_Database_PdoDriver, lastRowCount);
PHP_METHOD(Brisk_Database_PdoDriver, setFetchMode);
PHP_METHOD(Brisk_Database_PdoDriver, getDriverName);
PHP_METHOD(Brisk_Database_PdoDriver, getInstance);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_pdodriver___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, pass)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_pdodriver__query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_pdodriver_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_pdodriver_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_pdodriver_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_pdodriver_fetchrow, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_pdodriver_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, seq)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_database_pdodriver_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_database_pdodriver_method_entry) {
	PHP_ME(Brisk_Database_PdoDriver, __construct, arginfo_brisk_database_pdodriver___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Database_PdoDriver, _query, arginfo_brisk_database_pdodriver__query, ZEND_ACC_PROTECTED)
	PHP_ME(Brisk_Database_PdoDriver, query, arginfo_brisk_database_pdodriver_query, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, fetchAll, arginfo_brisk_database_pdodriver_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, fetchOne, arginfo_brisk_database_pdodriver_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, fetchRow, arginfo_brisk_database_pdodriver_fetchrow, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, beginTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, inTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, nextInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, lastInsertId, arginfo_brisk_database_pdodriver_lastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, lastRowCount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, setFetchMode, arginfo_brisk_database_pdodriver_setfetchmode, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, getDriverName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Database_PdoDriver, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
