
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
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Event) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Event, brisk, kernel_event, brisk_kernel_event_method_entry, 0);

	zend_declare_property_null(brisk_kernel_event_ce, SL("_listener"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Kernel_Event, addListener) {

	zval *event_param = NULL, *listener, listener_sub, *name_param = NULL, _0, _1$$3;
	zval event, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&listener_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event_param, &listener, &name_param);

	if (UNEXPECTED(Z_TYPE_P(event_param) != IS_STRING && Z_TYPE_P(event_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'event' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(event_param) == IS_STRING)) {
		zephir_get_strval(&event, event_param);
	} else {
		ZEPHIR_INIT_VAR(&event);
		ZVAL_EMPTY_STRING(&event);
	}
	if (UNEXPECTED(zephir_is_callable(listener TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'listener' must be a callable") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
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
	}


	zephir_read_static_property_ce(&_0, brisk_kernel_event_ce, SL("_listener"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &event))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_static_property_array_multi_ce(brisk_kernel_event_ce, SL("_listener"), &_1$$3 TSRMLS_CC, SL("z"), 1, &event);
	}
	if (ZEPHIR_IS_STRING(&name, "")) {
		zephir_update_static_property_array_multi_ce(brisk_kernel_event_ce, SL("_listener"), listener TSRMLS_CC, SL("za"), 2, &event);
	} else {
		zephir_update_static_property_array_multi_ce(brisk_kernel_event_ce, SL("_listener"), listener TSRMLS_CC, SL("zz"), 2, &event, &name);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Event, getListener) {

	zval *event_param = NULL, *name_param = NULL, _0$$3, _1$$4, _2$$4, _3$$5, _4$$5, _5$$5;
	zval event, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &event_param, &name_param);

	if (!event_param) {
		ZEPHIR_INIT_VAR(&event);
		ZVAL_STRING(&event, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(event_param) != IS_STRING && Z_TYPE_P(event_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'event' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(event_param) == IS_STRING)) {
		zephir_get_strval(&event, event_param);
	} else {
		ZEPHIR_INIT_VAR(&event);
		ZVAL_EMPTY_STRING(&event);
	}
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
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
	}


	if (ZEPHIR_IS_STRING(&event, "")) {
		zephir_read_static_property_ce(&_0$$3, brisk_kernel_event_ce, SL("_listener"), PH_NOISY_CC | PH_READONLY);
		RETURN_CTOR(&_0$$3);
	} else if (ZEPHIR_IS_STRING(&name, "")) {
		zephir_read_static_property_ce(&_1$$4, brisk_kernel_event_ce, SL("_listener"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$4, &_1$$4, &event, PH_NOISY | PH_READONLY, "brisk/Kernel/Event.zep", 27 TSRMLS_CC);
		RETURN_CTOR(&_2$$4);
	} else {
		zephir_read_static_property_ce(&_3$$5, brisk_kernel_event_ce, SL("_listener"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$5, &_3$$5, &event, PH_NOISY | PH_READONLY, "brisk/Kernel/Event.zep", 29 TSRMLS_CC);
		zephir_array_fetch(&_5$$5, &_4$$5, &name, PH_NOISY | PH_READONLY, "brisk/Kernel/Event.zep", 29 TSRMLS_CC);
		RETURN_CTOR(&_5$$5);
	}

}

PHP_METHOD(Brisk_Kernel_Event, removeListener) {

	zval *event_param = NULL, *name_param = NULL, _0$$3, _1$$4, _2$$4;
	zval event, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &event_param, &name_param);

	if (UNEXPECTED(Z_TYPE_P(event_param) != IS_STRING && Z_TYPE_P(event_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'event' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(event_param) == IS_STRING)) {
		zephir_get_strval(&event, event_param);
	} else {
		ZEPHIR_INIT_VAR(&event);
		ZVAL_EMPTY_STRING(&event);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
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
	}


	if (ZEPHIR_IS_STRING(&name, "")) {
		zephir_read_static_property_ce(&_0$$3, brisk_kernel_event_ce, SL("_listener"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_0$$3, &event, PH_SEPARATE);
	} else {
		zephir_read_static_property_ce(&_1$$4, brisk_kernel_event_ce, SL("_listener"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$4, &_1$$4, &event, PH_NOISY | PH_READONLY, "brisk/Kernel/Event.zep", 38 TSRMLS_CC);
		zephir_array_unset(&_2$$4, &name, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Event, onListening) {

	zend_string *_4;
	zend_ulong _3;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data, _9$$5, _15$$6;
	zval *event_param = NULL, *data_param = NULL, _0, listener, _1, name, item, *_2, ori_keys$$4, _5$$4, now_keys$$4, diff$$4, _6$$5, _7$$5, _10$$5, _13$$6, _14$$6, _16$$6;
	zval event;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&listener);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&ori_keys$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&now_keys$$4);
	ZVAL_UNDEF(&diff$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_15$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &event_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(event_param) != IS_STRING && Z_TYPE_P(event_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'event' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(event_param) == IS_STRING)) {
		zephir_get_strval(&event, event_param);
	} else {
		ZEPHIR_INIT_VAR(&event);
		ZVAL_EMPTY_STRING(&event);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	}


	zephir_read_static_property_ce(&_0, brisk_kernel_event_ce, SL("_listener"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &event))) {
		RETURN_CTOR(&data);
	}
	zephir_read_static_property_ce(&_1, brisk_kernel_event_ce, SL("_listener"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&listener);
	zephir_array_fetch(&listener, &_1, &event, PH_NOISY, "brisk/Kernel/Event.zep", 47 TSRMLS_CC);
	zephir_array_update_string(&data, SL("event"), &event, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(&listener, 0, "brisk/Kernel/Event.zep", 63);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&listener), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&name, _4);
		} else {
			ZVAL_LONG(&name, _3);
		}
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _2);
		zephir_array_update_string(&data, SL("name"), &name, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&ori_keys$$4);
		zephir_array_keys(&ori_keys$$4, &data TSRMLS_CC);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_5$$4, &item, NULL, 0, &data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&data, &_5$$4);
		if (!(Z_TYPE_P(&data) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(&_6$$5);
			object_init_ex(&_6$$5, brisk_exception_eventexception_ce);
			ZEPHIR_INIT_NVAR(&_9$$5);
			zephir_create_array(&_9$$5, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_9$$5, &event);
			ZEPHIR_INIT_NVAR(&_10$$5);
			ZVAL_STRING(&_10$$5, "event.data_must_array");
			ZEPHIR_CALL_CE_STATIC(&_7$$5, brisk_kernel_language_ce, "get", &_8, 0, &_10$$5, &_9$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_11, 3, &_7$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$5, "brisk/Kernel/Event.zep", 55 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&now_keys$$4);
		zephir_array_keys(&now_keys$$4, &data TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&diff$$4, "array_diff", &_12, 29, &ori_keys$$4, &now_keys$$4);
		zephir_check_call_status();
		if (zephir_fast_count_int(&diff$$4 TSRMLS_CC) > 0) {
			ZEPHIR_INIT_NVAR(&_13$$6);
			object_init_ex(&_13$$6, brisk_exception_eventexception_ce);
			ZEPHIR_INIT_NVAR(&_15$$6);
			zephir_create_array(&_15$$6, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_15$$6, &event);
			ZEPHIR_INIT_NVAR(&_16$$6);
			ZVAL_STRING(&_16$$6, "event.data_key_must_equal");
			ZEPHIR_CALL_CE_STATIC(&_14$$6, brisk_kernel_language_ce, "get", &_8, 0, &_16$$6, &_15$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_13$$6, "__construct", &_11, 3, &_14$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_13$$6, "brisk/Kernel/Event.zep", 60 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&data);

}

void zephir_init_static_properties_Brisk_Kernel_Event(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(brisk_kernel_event_ce, ZEND_STRL("_listener"), &_0);
	ZEPHIR_MM_RESTORE();

}

