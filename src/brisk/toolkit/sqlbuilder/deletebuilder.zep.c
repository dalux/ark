
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Toolkit_SQLBuilder_DeleteBuilder) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Toolkit\\SQLBuilder, DeleteBuilder, brisk, toolkit_sqlbuilder_deletebuilder, brisk_toolkit_sqlbuilder_builderfather_ce, brisk_toolkit_sqlbuilder_deletebuilder_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_DeleteBuilder, from) {

	zval *table, table_sub, tables, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &table);



	if (!(Z_TYPE_P(table) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&tables);
		zephir_create_array(&tables, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&tables, table);
	} else {
		ZEPHIR_CPY_WRT(&tables, table);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "from");
	zephir_update_property_array(this_ptr, SL("_parts"), &_0, &tables TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Toolkit_SQLBuilder_DeleteBuilder, getSQL) {

	zval from, _0, alias$$3, table$$3, _1$$3, delete$$3, where$$3, _2$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&alias$$3);
	ZVAL_UNDEF(&table$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&delete$$3);
	ZVAL_UNDEF(&where$$3);
	ZVAL_UNDEF(&_2$$6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_parts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&from);
	zephir_array_fetch_string(&from, &_0, SL("from"), PH_NOISY, "brisk/Toolkit/SQLBuilder/DeleteBuilder.zep", 21 TSRMLS_CC);
	if (zephir_fast_count_int(&from TSRMLS_CC) > 0) {
		ZEPHIR_MAKE_REF(&from);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "each", NULL, 5, &from);
		ZEPHIR_UNREF(&from);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&from, &_1$$3);
		ZEPHIR_OBS_VAR(&alias$$3);
		zephir_array_fetch_string(&alias$$3, &from, SL("key"), PH_NOISY, "brisk/Toolkit/SQLBuilder/DeleteBuilder.zep", 25 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&table$$3);
		zephir_array_fetch_string(&table$$3, &from, SL("value"), PH_NOISY, "brisk/Toolkit/SQLBuilder/DeleteBuilder.zep", 26 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "is_integer", NULL, 6, &alias$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&delete$$3);
		if (zephir_is_true(&_1$$3)) {
			ZEPHIR_CONCAT_SV(&delete$$3, "DELETE FROM ", &table$$3);
		} else {
			ZEPHIR_CONCAT_SVSV(&delete$$3, "DELETE FROM ", &table$$3, " ", &alias$$3);
		}
		ZEPHIR_CALL_METHOD(&where$$3, this_ptr, "pickwherepart", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING(&where$$3, "")) {
			ZEPHIR_INIT_VAR(&_2$$6);
			ZEPHIR_CONCAT_VSV(&_2$$6, &delete$$3, " WHERE ", &where$$3);
			ZEPHIR_CPY_WRT(&delete$$3, &_2$$6);
		}
		RETURN_CCTOR(&delete$$3);
	}
	RETURN_MM_NULL();

}

