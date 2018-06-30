
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

PHP_METHOD(Brisk_Kernel_Container, __construct) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, __$null, _0$$3, key$$3, val$$3, *_1$$3, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&key$$3);
	ZVAL_UNDEF(&val$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval(this_ptr, SL("_container"), &_0$$3);
		zephir_is_iterable(data, 0, "brisk/Kernel/Container.zep", 16);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _2$$3, _3$$3, _1$$3)
		{
			ZEPHIR_INIT_NVAR(&key$$3);
			if (_3$$3 != NULL) { 
				ZVAL_STR_COPY(&key$$3, _3$$3);
			} else {
				ZVAL_LONG(&key$$3, _2$$3);
			}
			ZEPHIR_INIT_NVAR(&val$$3);
			ZVAL_COPY(&val$$3, _1$$3);
			ZEPHIR_INIT_NVAR(&_4$$4);
			object_init_ex(&_4$$4, brisk_kernel_container_ce);
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", &_5, 24, &val$$3);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("_container"), &key$$3, &_4$$4 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val$$3);
		ZEPHIR_INIT_NVAR(&key$$3);
	} else if (Z_TYPE_P(data) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("_container"), data);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Container, hasKey) {

	zend_string *_14;
	zend_ulong _13;
	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _2, _3, _4, _5, _6, nodes, node, _10, instance, v, _11, *_12, _7$$3, _8$$3, _9$$3, _15$$5, _16$$5;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&nodes);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ">");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, ".");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, ">");
	zephir_fast_str_replace(&_0, &_1, &_2, &key TSRMLS_CC);
	zephir_get_strval(&key, &_0);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, ">");
	zephir_fast_trim(&_3, &key, &_4, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_get_strval(&key, &_3);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, ">");
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_strpos(&_6, &key, &_5, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_6)) {
		ZEPHIR_INIT_VAR(&_7$$3);
		zephir_read_property(&_8$$3, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8$$3) == IS_ARRAY) {
			zephir_read_property(&_9$$3, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
			ZVAL_BOOL(&_7$$3, zephir_array_isset(&_9$$3, &key));
		} else {
			ZVAL_BOOL(&_7$$3, 0);
		}
		RETURN_CCTOR(&_7$$3);
	}
	ZEPHIR_INIT_VAR(&nodes);
	array_init(&nodes);
	ZEPHIR_INIT_NVAR(&nodes);
	zephir_fast_explode_str(&nodes, SL(">"), &key, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(&nodes);
	ZEPHIR_CALL_FUNCTION(&node, "array_shift", NULL, 7, &nodes);
	ZEPHIR_UNREF(&nodes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "haskey", NULL, 28, &node);
	zephir_check_call_status();
	if (!zephir_is_true(&_10)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(&instance);
	zephir_read_property_zval(&instance, this_ptr, &node, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_11);
	zephir_is_iterable(&nodes, 0, "brisk/Kernel/Container.zep", 45);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&nodes), _13, _14, _12)
	{
		ZEPHIR_INIT_NVAR(&_11);
		if (_14 != NULL) { 
			ZVAL_STR_COPY(&_11, _14);
		} else {
			ZVAL_LONG(&_11, _13);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _12);
		ZEPHIR_CALL_METHOD(&_15$$5, &instance, "haskey", NULL, 0, &v);
		zephir_check_call_status();
		if (!zephir_is_true(&_15$$5)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_OBS_NVAR(&_16$$5);
		zephir_read_property_zval(&_16$$5, &instance, &v, PH_NOISY_CC);
		ZEPHIR_CPY_WRT(&instance, &_16$$5);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&_11);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Brisk_Kernel_Container, hasValue) {

	zval _0, _2, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);


	zephir_read_property(&_0, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		zephir_read_property(&_1$$3, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
		RETURN_BOOL(zephir_fast_count_int(&_1$$3 TSRMLS_CC) > 0);
	}
	zephir_read_property(&_2, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_2) != IS_NULL);

}

PHP_METHOD(Brisk_Kernel_Container, getValue) {

	zend_string *_4$$3;
	zend_ulong _3$$3;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *in_loop_param = NULL, result, _0, _11, k$$3, v$$3, _1$$3, *_2$$3, _5$$5, _6$$5, _13$$8;
	zend_bool in_loop, _8, _9, _10, _12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&k$$3);
	ZVAL_UNDEF(&v$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_13$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &in_loop_param);

	if (!in_loop_param) {
		in_loop = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(in_loop_param) != IS_TRUE && Z_TYPE_P(in_loop_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'in_loop' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	in_loop = (Z_TYPE_P(in_loop_param) == IS_TRUE);
	}


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_read_property(&_0, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		zephir_read_property(&_1$$3, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "brisk/Kernel/Container.zep", 68);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$3), _3$$3, _4$$3, _2$$3)
		{
			ZEPHIR_INIT_NVAR(&k$$3);
			if (_4$$3 != NULL) { 
				ZVAL_STR_COPY(&k$$3, _4$$3);
			} else {
				ZVAL_LONG(&k$$3, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&v$$3);
			ZVAL_COPY(&v$$3, _2$$3);
			if (zephir_instance_of_ev(&v$$3, brisk_kernel_container_ce TSRMLS_CC)) {
				ZVAL_BOOL(&_6$$5, 1);
				ZEPHIR_CALL_METHOD(&_5$$5, &v$$3, "getvalue", &_7, 0, &_6$$5);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &k$$3, &_5$$5, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&result, &k$$3, &v$$3, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v$$3);
		ZEPHIR_INIT_NVAR(&k$$3);
	} else {
		ZEPHIR_OBS_NVAR(&result);
		zephir_read_property(&result, this_ptr, SL("_container"), PH_NOISY_CC);
	}
	_8 = Z_TYPE_P(&result) == IS_ARRAY;
	if (_8) {
		_8 = zephir_fast_count_int(&result TSRMLS_CC) == 1;
	}
	_9 = _8;
	if (_9) {
		_9 = zephir_array_isset_long(&result, 0);
	}
	_10 = _9;
	if (_10) {
		zephir_array_fetch_long(&_11, &result, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/Container.zep", 74 TSRMLS_CC);
		_10 = !(Z_TYPE_P(&_11) == IS_ARRAY);
	}
	_12 = _10;
	if (_12) {
		_12 = !in_loop;
	}
	if (_12) {
		zephir_array_fetch_long(&_13$$8, &result, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/Container.zep", 76 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&result, &_13$$8);
	}
	RETURN_CCTOR(&result);

}

PHP_METHOD(Brisk_Kernel_Container, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1$$3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "haskey", NULL, 0, &name);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &name, PH_NOISY | PH_READONLY, "brisk/Kernel/Container.zep", 84 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	} else {
		object_init_ex(return_value, brisk_kernel_container_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 24);
		zephir_check_call_status();
		RETURN_MM();
	}

}

PHP_METHOD(Brisk_Kernel_Container, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub, _0, _2, _1$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("_container"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_zval(this_ptr, SL("_container"), &_1$$3);
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, brisk_kernel_container_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 24, value);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_container"), &name, &_2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

