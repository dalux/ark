
extern zend_class_entry *brisk_contract_idatabase_ce;

ZEPHIR_INIT_CLASS(Brisk_Contract_IDatabase);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_idatabase_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_idatabase_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_idatabase_fetchrow, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_idatabase_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, bind, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_idatabase_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, seq)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_contract_idatabase_method_entry) {
	PHP_ABSTRACT_ME(Brisk_Contract_IDatabase, query, arginfo_brisk_contract_idatabase_query)
	PHP_ABSTRACT_ME(Brisk_Contract_IDatabase, fetchAll, arginfo_brisk_contract_idatabase_fetchall)
	PHP_ABSTRACT_ME(Brisk_Contract_IDatabase, fetchRow, arginfo_brisk_contract_idatabase_fetchrow)
	PHP_ABSTRACT_ME(Brisk_Contract_IDatabase, fetchOne, arginfo_brisk_contract_idatabase_fetchone)
	PHP_ABSTRACT_ME(Brisk_Contract_IDatabase, beginTransaction, NULL)
	PHP_ABSTRACT_ME(Brisk_Contract_IDatabase, commit, NULL)
	PHP_ABSTRACT_ME(Brisk_Contract_IDatabase, rollback, NULL)
	PHP_ABSTRACT_ME(Brisk_Contract_IDatabase, lastInsertId, arginfo_brisk_contract_idatabase_lastinsertid)
	PHP_ABSTRACT_ME(Brisk_Contract_IDatabase, lastRowCount, NULL)
	PHP_ABSTRACT_ME(Brisk_Contract_IDatabase, getDriverName, NULL)
	PHP_ABSTRACT_ME(Brisk_Contract_IDatabase, getInstance, NULL)
	PHP_FE_END
};
