
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Brisk_Sql_Select_Sqlite) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Sql\\Select, Sqlite, brisk, sql_select_sqlite, brisk_sql_select_ce, NULL, 0);

	zend_declare_property_string(brisk_sql_select_sqlite_ce, SL("_db_type"), "sqlite", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

