
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_DeleteBuilder_Pgsql) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Toolkit\\SQLBuilder\\DeleteBuilder, Pgsql, brisk, toolkit_sqlbuilder_deletebuilder_pgsql, brisk_toolkit_sqlbuilder_deletebuilder_ce, NULL, 0);

	zend_declare_property_string(brisk_toolkit_sqlbuilder_deletebuilder_pgsql_ce, SL("_db_type"), "pgsql", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}
