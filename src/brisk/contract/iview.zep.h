
extern zend_class_entry *brisk_contract_iview_ce;

ZEPHIR_INIT_CLASS(Brisk_Contract_IView);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_iview_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_iview_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_contract_iview_display, 0, 0, 1)
	ZEND_ARG_INFO(0, template)
	ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_contract_iview_method_entry) {
	PHP_ABSTRACT_ME(Brisk_Contract_IView, set, arginfo_brisk_contract_iview_set)
	PHP_ABSTRACT_ME(Brisk_Contract_IView, get, arginfo_brisk_contract_iview_get)
	PHP_ABSTRACT_ME(Brisk_Contract_IView, display, arginfo_brisk_contract_iview_display)
	PHP_FE_END
};
