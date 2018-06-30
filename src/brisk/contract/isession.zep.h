
extern zend_class_entry *brisk_contract_isession_ce;

ZEPHIR_INIT_CLASS(Brisk_Contract_ISession);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_isession_start, 0, 0, 0)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_isession_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_isession_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_isession_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_contract_isession_method_entry) {
	PHP_ABSTRACT_ME(Brisk_Contract_ISession, start, arginfo_brisk_contract_isession_start)
	PHP_ABSTRACT_ME(Brisk_Contract_ISession, get, arginfo_brisk_contract_isession_get)
	PHP_ABSTRACT_ME(Brisk_Contract_ISession, set, arginfo_brisk_contract_isession_set)
	PHP_ABSTRACT_ME(Brisk_Contract_ISession, delete, arginfo_brisk_contract_isession_delete)
	PHP_FE_END
};
