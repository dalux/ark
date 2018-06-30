
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Brisk_Contract_IView) {

	ZEPHIR_REGISTER_INTERFACE(Brisk\\Contract, IView, brisk, contract_iview, brisk_contract_iview_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Brisk_Contract_IView, set);

ZEPHIR_DOC_METHOD(Brisk_Contract_IView, get);

ZEPHIR_DOC_METHOD(Brisk_Contract_IView, display);

