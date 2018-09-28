
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


ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_Delete_Sqlite) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Vendor\\Querier\\Delete, Sqlite, brisk, vendor_querier_delete_sqlite, brisk_vendor_querier_delete_ce, NULL, 0);

	zend_declare_property_string(brisk_vendor_querier_delete_sqlite_ce, SL("_db_type"), "sqlite", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

