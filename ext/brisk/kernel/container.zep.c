
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Container) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Container, brisk, kernel_container, brisk_kernel_container_method_entry, 0);

	zend_declare_property_null(brisk_kernel_container_ce, SL("_container"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * construct
 *
 * @param mixed data
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Container, __construct) {

	HashTable *_2$$3;
	HashPosition _1$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *_0$$3, *key$$3 = NULL, *val$$3 = NULL, **_3$$3, *_4$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		array_init(_0$$3);
		zephir_update_property_this(getThis(), SL("_container"), _0$$3 TSRMLS_CC);
		zephir_is_iterable(data, &_2$$3, &_1$$3, 0, 0, "brisk/Kernel/Container.zep", 22);
		for (
		  ; zend_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(key$$3, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(val$$3, _3$$3);
			ZEPHIR_INIT_NVAR(_4$$4);
			object_init_ex(_4$$4, brisk_kernel_container_ce);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", &_5, 51, val$$3);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("_container"), key$$3, _4$$4 TSRMLS_CC);
		}
	} else if (Z_TYPE_P(data) != IS_NULL) {
		zephir_update_property_this(getThis(), SL("_container"), data TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if key exists
 *
 * @param string key
 * @return bool
 */
PHP_METHOD(Brisk_Kernel_Container, hasKey) {

	HashTable *_13;
	HashPosition _12;
	zval *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0, *_2 = NULL, _3, _4, _5, *_6, *nodes = NULL, *node = NULL, *_10 = NULL, *instance = NULL, *v = NULL, *_11 = NULL, **_14, *_7$$3, *_8$$3, *_9$$3, *_15$$5 = NULL, *_16$$5 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, ">", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, ".", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "/", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, ">", 0);
	zephir_fast_str_replace(&_0, _1, &_3, key TSRMLS_CC);
	zephir_get_strval(key, _0);
	ZEPHIR_INIT_NVAR(_2);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, ">", 0);
	zephir_fast_trim(_2, key, &_4, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_get_strval(key, _2);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, ">", 0);
	ZEPHIR_INIT_VAR(_6);
	zephir_fast_strpos(_6, key, &_5, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(_6)) {
		ZEPHIR_INIT_VAR(_7$$3);
		_8$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
		if (Z_TYPE_P(_8$$3) == IS_ARRAY) {
			_9$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
			ZVAL_BOOL(_7$$3, zephir_array_isset(_9$$3, key));
		} else {
			ZVAL_BOOL(_7$$3, 0);
		}
		RETURN_CCTOR(_7$$3);
	}
	ZEPHIR_INIT_VAR(nodes);
	array_init(nodes);
	ZEPHIR_INIT_NVAR(nodes);
	zephir_fast_explode_str(nodes, SL(">"), key, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(nodes);
	ZEPHIR_CALL_FUNCTION(&node, "array_shift", NULL, 15, nodes);
	ZEPHIR_UNREF(nodes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "haskey", NULL, 66, node);
	zephir_check_call_status();
	if (!zephir_is_true(_10)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(instance);
	zephir_read_property_zval(&instance, this_ptr, node, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_11);
	zephir_is_iterable(nodes, &_13, &_12, 0, 0, "brisk/Kernel/Container.zep", 57);
	for (
	  ; zend_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
	  ; zend_hash_move_forward_ex(_13, &_12)
	) {
		ZEPHIR_GET_HMKEY(_11, _13, _12);
		ZEPHIR_GET_HVALUE(v, _14);
		ZEPHIR_CALL_METHOD(&_15$$5, instance, "haskey", NULL, 0, v);
		zephir_check_call_status();
		if (!zephir_is_true(_15$$5)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_OBS_NVAR(_16$$5);
		zephir_read_property_zval(&_16$$5, instance, v, PH_NOISY_CC);
		ZEPHIR_CPY_WRT(instance, _16$$5);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check whether data exists at the current node
 *
 * @return bool
 */
PHP_METHOD(Brisk_Kernel_Container, hasValue) {

	zval *_0, *_2, *_1$$3;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
		RETURN_BOOL(zephir_fast_count_int(_1$$3 TSRMLS_CC) > 0);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	RETURN_BOOL(Z_TYPE_P(_2) != IS_NULL);

}

/**
 * Get data from the current node
 *
 * @return mixed
 */
PHP_METHOD(Brisk_Kernel_Container, getValue) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool _7, _8, _9;
	zval *result = NULL, *_0, *_10, *k$$3 = NULL, *v$$3 = NULL, *_1$$3, **_4$$3, *_5$$5 = NULL, *_11$$8;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(result);
	array_init(result);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
		zephir_is_iterable(_1$$3, &_3$$3, &_2$$3, 0, 0, "brisk/Kernel/Container.zep", 90);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(k$$3, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(v$$3, _4$$3);
			if (zephir_instance_of_ev(v$$3, brisk_kernel_container_ce TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&_5$$5, v$$3, "getvalue", &_6, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&result, k$$3, &_5$$5, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&result, k$$3, &v$$3, PH_COPY | PH_SEPARATE);
			}
		}
	} else {
		ZEPHIR_OBS_NVAR(result);
		zephir_read_property_this(&result, this_ptr, SL("_container"), PH_NOISY_CC);
	}
	_7 = Z_TYPE_P(result) == IS_ARRAY;
	if (_7) {
		_7 = zephir_fast_count_int(result TSRMLS_CC) == 1;
	}
	_8 = _7;
	if (_8) {
		_8 = zephir_array_isset_long(result, 0);
	}
	_9 = _8;
	if (_9) {
		zephir_array_fetch_long(&_10, result, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/Container.zep", 96 TSRMLS_CC);
		_9 = !(Z_TYPE_P(_10) == IS_ARRAY);
	}
	if (_9) {
		zephir_array_fetch_long(&_11$$8, result, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/Container.zep", 97 TSRMLS_CC);
		ZEPHIR_CPY_WRT(result, _11$$8);
	}
	RETURN_CCTOR(result);

}

/**
 * Get the data corresponding to the specified key
 *
 * @param string key
 * @return mixed
 */
PHP_METHOD(Brisk_Kernel_Container, get) {

	HashTable *_8$$3;
	HashPosition _7$$3;
	zval *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0, *_2 = NULL, _3, _4, *nodes = NULL, *node = NULL, *instance = NULL, *_5 = NULL, *v$$3 = NULL, *_6$$3 = NULL, **_9$$3, *_10$$4 = NULL, *_11$$5 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, ">", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, ".", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "/", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, ">", 0);
	zephir_fast_str_replace(&_0, _1, &_3, key TSRMLS_CC);
	zephir_get_strval(key, _0);
	ZEPHIR_INIT_NVAR(_2);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, ">", 0);
	zephir_fast_trim(_2, key, &_4, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_get_strval(key, _2);
	ZEPHIR_INIT_VAR(nodes);
	zephir_fast_explode_str(nodes, SL(">"), key, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(nodes);
	ZEPHIR_CALL_FUNCTION(&node, "array_shift", NULL, 15, nodes);
	ZEPHIR_UNREF(nodes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "haskey", NULL, 0, node);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_OBS_VAR(instance);
		zephir_read_property_zval(&instance, this_ptr, node, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_is_iterable(nodes, &_8$$3, &_7$$3, 0, 0, "brisk/Kernel/Container.zep", 125);
		for (
		  ; zend_hash_get_current_data_ex(_8$$3, (void**) &_9$$3, &_7$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_8$$3, &_7$$3)
		) {
			ZEPHIR_GET_HMKEY(_6$$3, _8$$3, _7$$3);
			ZEPHIR_GET_HVALUE(v$$3, _9$$3);
			ZEPHIR_CALL_METHOD(&_10$$4, instance, "haskey", NULL, 0, v$$3);
			zephir_check_call_status();
			if (zephir_is_true(_10$$4)) {
				ZEPHIR_OBS_NVAR(_11$$5);
				zephir_read_property_zval(&_11$$5, instance, v$$3, PH_NOISY_CC);
				ZEPHIR_CPY_WRT(instance, _11$$5);
			} else {
				RETURN_MM_NULL();
			}
		}
		ZEPHIR_RETURN_CALL_METHOD(instance, "getvalue", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Brisk_Kernel_Container, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0 = NULL, *_1$$3, *_2$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "haskey", NULL, 0, key);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
		zephir_array_fetch(&_2$$3, _1$$3, key, PH_NOISY | PH_READONLY, "brisk/Kernel/Container.zep", 133 TSRMLS_CC);
		RETURN_CTOR(_2$$3);
	} else {
		object_init_ex(return_value, brisk_kernel_container_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 51);
		zephir_check_call_status();
		RETURN_MM();
	}

}

PHP_METHOD(Brisk_Kernel_Container, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *_0, *_2, *_1$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1$$3);
		array_init(_1$$3);
		zephir_update_property_this(getThis(), SL("_container"), _1$$3 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, brisk_kernel_container_ce);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 51, value);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_container"), key, _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

