
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/time.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Timer) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Timer, brisk, kernel_timer, brisk_kernel_timer_method_entry, 0);

	zend_declare_property_null(brisk_kernel_timer_ce, SL("_marks"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Mark Time Label
 *
 * @param string flag
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Timer, mark) {

	zval *flag_param = NULL, *_0$$3, *_1;
	zval *flag = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &flag_param);

	if (!flag_param) {
		ZEPHIR_INIT_VAR(flag);
		ZVAL_STRING(flag, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(flag_param) != IS_STRING && Z_TYPE_P(flag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'flag' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(flag_param) == IS_STRING)) {
		zephir_get_strval(flag, flag_param);
	} else {
		ZEPHIR_INIT_VAR(flag);
		ZVAL_EMPTY_STRING(flag);
	}
	}


	if (ZEPHIR_IS_STRING(flag, "")) {
		_0$$3 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
		RETURN_CTOR(_0$$3);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_microtime(_1, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	zephir_update_static_property_array_multi_ce(brisk_kernel_timer_ce, SL("_marks"), &_1 TSRMLS_CC, SL("z"), 1, flag);
	ZEPHIR_MM_RESTORE();

}

/**
 * Check for the presence of a time label
 *
 * @param string flag
 * @return bool
 */
PHP_METHOD(Brisk_Kernel_Timer, isMarked) {

	zval *flag_param = NULL, *_0;
	zval *flag = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &flag_param);

	if (UNEXPECTED(Z_TYPE_P(flag_param) != IS_STRING && Z_TYPE_P(flag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'flag' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(flag_param) == IS_STRING)) {
		zephir_get_strval(flag, flag_param);
	} else {
		ZEPHIR_INIT_VAR(flag);
		ZVAL_EMPTY_STRING(flag);
	}


	_0 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, flag));

}

/**
 * Get the most recent time-consuming
 *
 * @return float
 */
PHP_METHOD(Brisk_Kernel_Timer, lastUsed) {

	zval *newer = NULL, *older = NULL, *reduce = NULL, *_0, *_1, *_2, *_3, _4, _5, _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(&newer, "end", NULL, 87, _0);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	_1 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
	ZEPHIR_MAKE_REF(_1);
	ZEPHIR_CALL_FUNCTION(NULL, "prev", NULL, 88, _1);
	ZEPHIR_UNREF(_1);
	zephir_check_call_status();
	_2 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
	ZEPHIR_MAKE_REF(_2);
	ZEPHIR_CALL_FUNCTION(&older, "current", NULL, 3, _2);
	ZEPHIR_UNREF(_2);
	zephir_check_call_status();
	_3 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
	ZEPHIR_MAKE_REF(_3);
	ZEPHIR_CALL_FUNCTION(NULL, "reset", NULL, 89, _3);
	ZEPHIR_UNREF(_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(reduce);
	zephir_sub_function(reduce, newer, older);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 3);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, ".", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("number_format", NULL, 90, reduce, &_4, &_5, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get total time-consuming
 *
 * @return float
 */
PHP_METHOD(Brisk_Kernel_Timer, totalUsed) {

	zval *newest = NULL, *oldest = NULL, *reduce = NULL, *_0, *_1, *_2, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(&oldest, "current", NULL, 3, _0);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	_1 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
	ZEPHIR_MAKE_REF(_1);
	ZEPHIR_CALL_FUNCTION(&newest, "end", NULL, 87, _1);
	ZEPHIR_UNREF(_1);
	zephir_check_call_status();
	_2 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
	ZEPHIR_MAKE_REF(_2);
	ZEPHIR_CALL_FUNCTION(NULL, "reset", NULL, 89, _2);
	ZEPHIR_UNREF(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(reduce);
	zephir_sub_function(reduce, newest, oldest);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, ".", 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("number_format", NULL, 90, reduce, &_3, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get time-consuming based on specified tags
 *
 * @param string start
 * @param string end
 * @return float
 */
PHP_METHOD(Brisk_Kernel_Timer, pick) {

	zend_bool _0, _1, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *start_param = NULL, *end_param = NULL, *_2, *_4, *newer = NULL, *older = NULL, *reduce = NULL, *_5, *_6, _7, _8, _9;
	zval *start = NULL, *end = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &start_param, &end_param);

	if (UNEXPECTED(Z_TYPE_P(start_param) != IS_STRING && Z_TYPE_P(start_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'start' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(start_param) == IS_STRING)) {
		zephir_get_strval(start, start_param);
	} else {
		ZEPHIR_INIT_VAR(start);
		ZVAL_EMPTY_STRING(start);
	}
	if (UNEXPECTED(Z_TYPE_P(end_param) != IS_STRING && Z_TYPE_P(end_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'end' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(end_param) == IS_STRING)) {
		zephir_get_strval(end, end_param);
	} else {
		ZEPHIR_INIT_VAR(end);
		ZVAL_EMPTY_STRING(end);
	}


	_0 = ZEPHIR_IS_STRING(start, "");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(end, "");
	}
	_1 = _0;
	if (!(_1)) {
		_2 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
		_1 = !(zephir_array_isset(_2, start));
	}
	_3 = _1;
	if (!(_3)) {
		_4 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
		_3 = !(zephir_array_isset(_4, end));
	}
	if (_3) {
		RETURN_MM_BOOL(0);
	}
	_5 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
	ZEPHIR_OBS_VAR(newer);
	zephir_array_fetch(&newer, _5, end, PH_NOISY, "brisk/Kernel/Timer.zep", 80 TSRMLS_CC);
	_6 = zephir_fetch_static_property_ce(brisk_kernel_timer_ce, SL("_marks") TSRMLS_CC);
	ZEPHIR_OBS_VAR(older);
	zephir_array_fetch(&older, _6, start, PH_NOISY, "brisk/Kernel/Timer.zep", 81 TSRMLS_CC);
	ZEPHIR_INIT_VAR(reduce);
	zephir_sub_function(reduce, newer, older);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 3);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, ".", 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("number_format", NULL, 90, reduce, &_7, &_8, &_9);
	zephir_check_call_status();
	RETURN_MM();

}

void zephir_init_static_properties_Brisk_Kernel_Timer(TSRMLS_D) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(brisk_kernel_timer_ce, SL("_marks"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

