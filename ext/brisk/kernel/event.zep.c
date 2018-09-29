
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Event) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Event, brisk, kernel_event, brisk_kernel_event_method_entry, 0);

	zend_declare_property_null(brisk_kernel_event_ce, SL("_listener"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Adding event listeners
 *
 * @param string event
 * @param callable listener
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Event, add) {

	zval *event_param = NULL, *listener, *_0, *_1$$3;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &event_param, &listener);

	if (UNEXPECTED(Z_TYPE_P(event_param) != IS_STRING && Z_TYPE_P(event_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'event' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(event_param) == IS_STRING)) {
		zephir_get_strval(event, event_param);
	} else {
		ZEPHIR_INIT_VAR(event);
		ZVAL_EMPTY_STRING(event);
	}
	if (UNEXPECTED(zephir_is_callable(listener TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'listener' must be a callable") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	_0 = zephir_fetch_static_property_ce(brisk_kernel_event_ce, SL("_listener") TSRMLS_CC);
	if (!(zephir_array_isset(_0, event))) {
		ZEPHIR_INIT_VAR(_1$$3);
		array_init(_1$$3);
		zephir_update_static_property_array_multi_ce(brisk_kernel_event_ce, SL("_listener"), &_1$$3 TSRMLS_CC, SL("z"), 1, event);
	}
	zephir_update_static_property_array_multi_ce(brisk_kernel_event_ce, SL("_listener"), &listener TSRMLS_CC, SL("za"), 2, event);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets all listeners for the specified event
 *
 * @param string event
 * @return array
 */
PHP_METHOD(Brisk_Kernel_Event, get) {

	zval *event_param = NULL, *_0, *_1;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event_param);

	if (UNEXPECTED(Z_TYPE_P(event_param) != IS_STRING && Z_TYPE_P(event_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'event' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(event_param) == IS_STRING)) {
		zephir_get_strval(event, event_param);
	} else {
		ZEPHIR_INIT_VAR(event);
		ZVAL_EMPTY_STRING(event);
	}


	_0 = zephir_fetch_static_property_ce(brisk_kernel_event_ce, SL("_listener") TSRMLS_CC);
	zephir_array_fetch(&_1, _0, event, PH_NOISY | PH_READONLY, "brisk/Kernel/Event.zep", 33 TSRMLS_CC);
	RETURN_CTOR(_1);

}

/**
 * Triggering listener events
 *
 * @param string event
 * @param array data
 * @return array
 */
PHP_METHOD(Brisk_Kernel_Event, fire) {

	HashTable *_4;
	HashPosition _3;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *_10$$5 = NULL, *_16$$6 = NULL;
	zval *event_param = NULL, *data_param = NULL, *_0, *listener = NULL, *_1, *item = NULL, *_2 = NULL, **_5, *ori_keys$$4 = NULL, *_6$$4 = NULL, *now_keys$$4 = NULL, *diff$$4 = NULL, *_7$$5 = NULL, *_8$$5 = NULL, *_11$$5 = NULL, *_14$$6 = NULL, *_15$$6 = NULL, *_17$$6 = NULL;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &event_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(event_param) != IS_STRING && Z_TYPE_P(event_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'event' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(event_param) == IS_STRING)) {
		zephir_get_strval(event, event_param);
	} else {
		ZEPHIR_INIT_VAR(event);
		ZVAL_EMPTY_STRING(event);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
	data = data_param;
	}


	_0 = zephir_fetch_static_property_ce(brisk_kernel_event_ce, SL("_listener") TSRMLS_CC);
	if (!(zephir_array_isset(_0, event))) {
		RETURN_CTOR(data);
	}
	_1 = zephir_fetch_static_property_ce(brisk_kernel_event_ce, SL("_listener") TSRMLS_CC);
	ZEPHIR_OBS_VAR(listener);
	zephir_array_fetch(&listener, _1, event, PH_NOISY, "brisk/Kernel/Event.zep", 48 TSRMLS_CC);
	zephir_array_update_string(&data, SL("event"), &event, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	zephir_is_iterable(listener, &_4, &_3, 0, 0, "brisk/Kernel/Event.zep", 63);
	for (
	  ; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(_2, _4, _3);
		ZEPHIR_GET_HVALUE(item, _5);
		ZEPHIR_INIT_NVAR(ori_keys$$4);
		zephir_array_keys(ori_keys$$4, data TSRMLS_CC);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_6$$4, item, NULL, 0, data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(data, _6$$4);
		if (!(Z_TYPE_P(data) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_7$$5);
			object_init_ex(_7$$5, brisk_exception_eventexception_ce);
			ZEPHIR_INIT_NVAR(_10$$5);
			zephir_create_array(_10$$5, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_10$$5, event);
			ZEPHIR_INIT_NVAR(_11$$5);
			ZVAL_STRING(_11$$5, "event.data_must_array", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_CE_STATIC(&_8$$5, brisk_kernel_language_ce, "get", &_9, 0, _11$$5, _10$$5);
			zephir_check_temp_parameter(_11$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", &_12, 27, _8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$5, "brisk/Kernel/Event.zep", 55 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(now_keys$$4);
		zephir_array_keys(now_keys$$4, data TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&diff$$4, "array_diff", &_13, 33, ori_keys$$4, now_keys$$4);
		zephir_check_call_status();
		if (zephir_fast_count_int(diff$$4 TSRMLS_CC) > 0) {
			ZEPHIR_INIT_NVAR(_14$$6);
			object_init_ex(_14$$6, brisk_exception_eventexception_ce);
			ZEPHIR_INIT_NVAR(_16$$6);
			zephir_create_array(_16$$6, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_16$$6, event);
			ZEPHIR_INIT_NVAR(_17$$6);
			ZVAL_STRING(_17$$6, "event.data_key_must_equal", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_CE_STATIC(&_15$$6, brisk_kernel_language_ce, "get", &_9, 26, _17$$6, _16$$6);
			zephir_check_temp_parameter(_17$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _14$$6, "__construct", &_12, 27, _15$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_14$$6, "brisk/Kernel/Event.zep", 60 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(data);

}

void zephir_init_static_properties_Brisk_Kernel_Event(TSRMLS_D) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(brisk_kernel_event_ce, SL("_listener"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

