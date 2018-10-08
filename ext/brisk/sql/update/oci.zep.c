
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Sql_Update_Oci) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Sql\\Update, Oci, brisk, sql_update_oci, brisk_sql_update_ce, brisk_sql_update_oci_method_entry, 0);

	zend_declare_property_string(brisk_sql_update_oci_ce, SL("_db_type"), "oci", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Put quotation marks on a field
 *
 * @param mixed value
 * @return string
 */
PHP_METHOD(Brisk_Sql_Update_Oci, quote) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool _0;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_1 = NULL, *_7, _8, _9, *key$$3 = NULL, *val$$3 = NULL, **_4$$3, *_5$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);


	_0 = Z_TYPE_P(value) == IS_LONG;
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_float", NULL, 1, value);
		zephir_check_call_status();
		_0 = zephir_is_true(_1);
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		zephir_is_iterable(value, &_3$$3, &_2$$3, 1, 0, "brisk/Sql/Update/Oci.zep", 23);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(key$$3, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(val$$3, _4$$3);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "quote", &_6, 128, val$$3);
			zephir_check_call_status();
			zephir_array_update_zval(&value, key$$3, &_5$$4, PH_COPY | PH_SEPARATE);
		}
		zend_hash_destroy(_3$$3);
		FREE_HASHTABLE(_3$$3);
		zephir_fast_join_str(return_value, SL(","), value TSRMLS_CC);
		RETURN_MM();
	} else if (_0) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "'", 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "''", 0);
	zephir_fast_str_replace(&_7, &_8, &_9, value TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "'", _7, "'");
	RETURN_MM();

}

