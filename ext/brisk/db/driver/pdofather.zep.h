
extern zend_class_entry *brisk_db_driver_pdofather_ce;

ZEPHIR_INIT_CLASS(Brisk_Db_Driver_PdoFather);

PHP_METHOD(Brisk_Db_Driver_PdoFather, __construct);
PHP_METHOD(Brisk_Db_Driver_PdoFather, query);
PHP_METHOD(Brisk_Db_Driver_PdoFather, fetchAll);
PHP_METHOD(Brisk_Db_Driver_PdoFather, fetchOne);
PHP_METHOD(Brisk_Db_Driver_PdoFather, fetchRow);
PHP_METHOD(Brisk_Db_Driver_PdoFather, beginTransaction);
PHP_METHOD(Brisk_Db_Driver_PdoFather, commit);
PHP_METHOD(Brisk_Db_Driver_PdoFather, rollback);
PHP_METHOD(Brisk_Db_Driver_PdoFather, inTransaction);
PHP_METHOD(Brisk_Db_Driver_PdoFather, nextInsertId);
PHP_METHOD(Brisk_Db_Driver_PdoFather, lastInsertId);
PHP_METHOD(Brisk_Db_Driver_PdoFather, lastRowCount);
PHP_METHOD(Brisk_Db_Driver_PdoFather, setFetchMode);
PHP_METHOD(Brisk_Db_Driver_PdoFather, getDriverName);
PHP_METHOD(Brisk_Db_Driver_PdoFather, getInstance);
PHP_METHOD(Brisk_Db_Driver_PdoFather, _query);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_driver_pdofather___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_driver_pdofather_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_driver_pdofather_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_driver_pdofather_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_driver_pdofather_fetchrow, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_driver_pdofather_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, seq)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_driver_pdofather_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_driver_pdofather__query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_db_driver_pdofather_method_entry) {
	PHP_ME(Brisk_Db_Driver_PdoFather, __construct, arginfo_brisk_db_driver_pdofather___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Db_Driver_PdoFather, query, arginfo_brisk_db_driver_pdofather_query, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, fetchAll, arginfo_brisk_db_driver_pdofather_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, fetchOne, arginfo_brisk_db_driver_pdofather_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, fetchRow, arginfo_brisk_db_driver_pdofather_fetchrow, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, beginTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, inTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, nextInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, lastInsertId, arginfo_brisk_db_driver_pdofather_lastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, lastRowCount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, setFetchMode, arginfo_brisk_db_driver_pdofather_setfetchmode, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, getDriverName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, getInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_Driver_PdoFather, _query, arginfo_brisk_db_driver_pdofather__query, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
