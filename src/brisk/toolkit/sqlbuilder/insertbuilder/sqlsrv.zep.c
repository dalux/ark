
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


ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_InsertBuilder_Sqlsrv) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Toolkit\\SQLBuilder\\InsertBuilder, Sqlsrv, brisk, toolkit_sqlbuilder_insertbuilder_sqlsrv, brisk_toolkit_sqlbuilder_insertbuilder_ce, NULL, 0);

	zend_declare_property_string(brisk_toolkit_sqlbuilder_insertbuilder_sqlsrv_ce, SL("_db_type"), "sqlsrv", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

