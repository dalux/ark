
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Brisk_Contract_ICache) {

	ZEPHIR_REGISTER_INTERFACE(Brisk\\Contract, ICache, brisk, contract_icache, brisk_contract_icache_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Brisk_Contract_ICache, set);

ZEPHIR_DOC_METHOD(Brisk_Contract_ICache, get);

ZEPHIR_DOC_METHOD(Brisk_Contract_ICache, delete);

ZEPHIR_DOC_METHOD(Brisk_Contract_ICache, getCachePath);

ZEPHIR_DOC_METHOD(Brisk_Contract_ICache, setFlag);

ZEPHIR_DOC_METHOD(Brisk_Contract_ICache, setCaching);

