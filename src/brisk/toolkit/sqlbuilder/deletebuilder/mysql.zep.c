
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_DeleteBuilder_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Toolkit\\SQLBuilder\\DeleteBuilder, Mysql, brisk, toolkit_sqlbuilder_deletebuilder_mysql, brisk_toolkit_sqlbuilder_deletebuilder_ce, brisk_toolkit_sqlbuilder_deletebuilder_mysql_method_entry, 0);

	zend_declare_property_string(brisk_toolkit_sqlbuilder_deletebuilder_mysql_ce, SL("_db_type"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_DeleteBuilder_Mysql, getSQL) {

	zval from, _0, alias$$3, table$$3, _1$$3, delete$$3, where$$3, _2$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&alias$$3);
	ZVAL_UNDEF(&table$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&delete$$3);
	ZVAL_UNDEF(&where$$3);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&from);
	zephir_array_fetch_string(&from, &_0, SL("from"), PH_NOISY, "brisk/Toolkit/SQLBuilder/DeleteBuilder/Mysql.zep", 13 TSRMLS_CC);
	if (zephir_fast_count_int(&from TSRMLS_CC) > 0) {
		ZEPHIR_MAKE_REF(&from);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "each", NULL, 5, &from);
		ZEPHIR_UNREF(&from);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&from, &_1$$3);
		ZEPHIR_OBS_VAR(&alias$$3);
		zephir_array_fetch_long(&alias$$3, &from, 0, PH_NOISY, "brisk/Toolkit/SQLBuilder/DeleteBuilder/Mysql.zep", 17 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&table$$3);
		zephir_array_fetch_long(&table$$3, &from, 1, PH_NOISY, "brisk/Toolkit/SQLBuilder/DeleteBuilder/Mysql.zep", 18 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "is_integer", NULL, 6, &alias$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
			ZEPHIR_INIT_NVAR(&alias$$3);
			ZVAL_STRING(&alias$$3, "");
		}
		ZEPHIR_INIT_VAR(&delete$$3);
		ZEPHIR_CONCAT_SVSV(&delete$$3, "DELETE FROM ", &table$$3, " ", &alias$$3);
		ZEPHIR_CALL_METHOD(&where$$3, this_ptr, "pickwherepart", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING(&where$$3, "")) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZEPHIR_CONCAT_VSV(&_2$$5, &delete$$3, " WHERE ", &where$$3);
			ZEPHIR_CPY_WRT(&delete$$3, &_2$$5);
		}
		RETURN_CCTOR(&delete$$3);
	}
	RETURN_MM_NULL();

}

