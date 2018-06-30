
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Brisk_Contract_IRouter) {

	ZEPHIR_REGISTER_INTERFACE(Brisk\\Contract, IRouter, brisk, contract_irouter, brisk_contract_irouter_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Brisk_Contract_IRouter, ready);

ZEPHIR_DOC_METHOD(Brisk_Contract_IRouter, dispatch);

