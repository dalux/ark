
extern zend_class_entry *brisk_contract_icache_ce;

ZEPHIR_INIT_CLASS(Brisk_Contract_ICache);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_icache_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_icache_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_icache_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_icache_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_icache_setflag, 0, 0, 1)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_icache_setcaching, 0, 0, 0)
	ZEND_ARG_INFO(0, caching)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_contract_icache_method_entry) {
	PHP_ABSTRACT_ME(Brisk_Contract_ICache, set, arginfo_brisk_contract_icache_set)
	PHP_ABSTRACT_ME(Brisk_Contract_ICache, get, arginfo_brisk_contract_icache_get)
	PHP_ABSTRACT_ME(Brisk_Contract_ICache, delete, arginfo_brisk_contract_icache_delete)
	PHP_ABSTRACT_ME(Brisk_Contract_ICache, getCachePath, arginfo_brisk_contract_icache_getcachepath)
	PHP_ABSTRACT_ME(Brisk_Contract_ICache, setFlag, arginfo_brisk_contract_icache_setflag)
	PHP_ABSTRACT_ME(Brisk_Contract_ICache, setCaching, arginfo_brisk_contract_icache_setcaching)
	PHP_FE_END
};
