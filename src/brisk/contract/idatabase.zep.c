
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Brisk_Contract_IDatabase) {

	ZEPHIR_REGISTER_INTERFACE(Brisk\\Contract, IDatabase, brisk, contract_idatabase, brisk_contract_idatabase_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Brisk_Contract_IDatabase, query);

ZEPHIR_DOC_METHOD(Brisk_Contract_IDatabase, fetchAll);

ZEPHIR_DOC_METHOD(Brisk_Contract_IDatabase, fetchRow);

ZEPHIR_DOC_METHOD(Brisk_Contract_IDatabase, fetchOne);

ZEPHIR_DOC_METHOD(Brisk_Contract_IDatabase, beginTransaction);

ZEPHIR_DOC_METHOD(Brisk_Contract_IDatabase, commit);

ZEPHIR_DOC_METHOD(Brisk_Contract_IDatabase, rollback);

ZEPHIR_DOC_METHOD(Brisk_Contract_IDatabase, lastInsertId);

ZEPHIR_DOC_METHOD(Brisk_Contract_IDatabase, lastRowCount);

ZEPHIR_DOC_METHOD(Brisk_Contract_IDatabase, getDriverName);

ZEPHIR_DOC_METHOD(Brisk_Contract_IDatabase, getInstance);

