
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


ZEPHIR_INIT_CLASS(Brisk_Sql_Update_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Sql\\Update, Mysql, brisk, sql_update_mysql, brisk_sql_update_ce, NULL, 0);

	zend_declare_property_string(brisk_sql_update_mysql_ce, SL("_db_type"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

