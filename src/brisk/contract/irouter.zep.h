
extern zend_class_entry *brisk_contract_irouter_ce;

ZEPHIR_INIT_CLASS(Brisk_Contract_IRouter);

ZEPHIR_INIT_FUNCS(brisk_contract_irouter_method_entry) {
	PHP_ABSTRACT_ME(Brisk_Contract_IRouter, ready, NULL)
	PHP_ABSTRACT_ME(Brisk_Contract_IRouter, dispatch, NULL)
	PHP_FE_END
};
