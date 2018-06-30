
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Brisk_Contract_ISession) {

	ZEPHIR_REGISTER_INTERFACE(Brisk\\Contract, ISession, brisk, contract_isession, brisk_contract_isession_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Brisk_Contract_ISession, start);

ZEPHIR_DOC_METHOD(Brisk_Contract_ISession, get);

ZEPHIR_DOC_METHOD(Brisk_Contract_ISession, set);

ZEPHIR_DOC_METHOD(Brisk_Contract_ISession, delete);

