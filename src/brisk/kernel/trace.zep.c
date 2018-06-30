
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Trace) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Trace, brisk, kernel_trace, brisk_kernel_trace_method_entry, 0);

	zend_declare_property_null(brisk_kernel_trace_ce, SL("_trace"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Kernel_Trace, set) {

	zval _4$$3, _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *flag_param = NULL, *data, data_sub, _0, _6, _7, _1$$3, _2$$3, _3$$3, _8$$5, _9$$5, _10$$5, _11$$5;
	zval flag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&flag);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &flag_param, &data);

	if (UNEXPECTED(Z_TYPE_P(flag_param) != IS_STRING && Z_TYPE_P(flag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'flag' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(flag_param) == IS_STRING)) {
		zephir_get_strval(&flag, flag_param);
	} else {
		ZEPHIR_INIT_VAR(&flag);
		ZVAL_EMPTY_STRING(&flag);
	}


	zephir_read_static_property_ce(&_0, brisk_kernel_trace_ce, SL("_trace"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &flag)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_static_property_ce(&_2$$3, brisk_kernel_trace_ce, SL("_trace"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &flag, PH_NOISY | PH_READONLY, "brisk/Kernel/Trace.zep", 11 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_4$$3, data);
		zephir_fast_array_merge(&_1$$3, &_3$$3, &_4$$3 TSRMLS_CC);
		zephir_update_static_property_array_multi_ce(brisk_kernel_trace_ce, SL("_trace"), &_1$$3 TSRMLS_CC, SL("z"), 1, &flag);
	} else {
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_create_array(&_5$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_5$$4, data);
		zephir_update_static_property_array_multi_ce(brisk_kernel_trace_ce, SL("_trace"), &_5$$4 TSRMLS_CC, SL("z"), 1, &flag);
	}
	zephir_read_static_property_ce(&_6, brisk_kernel_trace_ce, SL("_trace"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_7, &_6, &flag, PH_NOISY | PH_READONLY, "brisk/Kernel/Trace.zep", 15 TSRMLS_CC);
	if (zephir_fast_count_int(&_7 TSRMLS_CC) > 1000) {
		zephir_read_static_property_ce(&_8$$5, brisk_kernel_trace_ce, SL("_trace"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_9$$5, &_8$$5, &flag, PH_NOISY | PH_READONLY, "brisk/Kernel/Trace.zep", 16 TSRMLS_CC);
		ZVAL_LONG(&_10$$5, -1000);
		ZEPHIR_CALL_FUNCTION(&_11$$5, "array_slice", NULL, 67, &_9$$5, &_10$$5);
		zephir_check_call_status();
		zephir_update_static_property_array_multi_ce(brisk_kernel_trace_ce, SL("_trace"), &_11$$5 TSRMLS_CC, SL("z"), 1, &flag);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Trace, get) {

	zval *flag_param = NULL, _0$$3, _1, _2$$4, _3$$4;
	zval flag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&flag);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &flag_param);

	if (!flag_param) {
		ZEPHIR_INIT_VAR(&flag);
		ZVAL_STRING(&flag, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(flag_param) != IS_STRING && Z_TYPE_P(flag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'flag' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(flag_param) == IS_STRING)) {
		zephir_get_strval(&flag, flag_param);
	} else {
		ZEPHIR_INIT_VAR(&flag);
		ZVAL_EMPTY_STRING(&flag);
	}
	}


	if (ZEPHIR_IS_STRING(&flag, "")) {
		zephir_read_static_property_ce(&_0$$3, brisk_kernel_trace_ce, SL("_trace"), PH_NOISY_CC | PH_READONLY);
		RETURN_CTOR(&_0$$3);
	}
	zephir_read_static_property_ce(&_1, brisk_kernel_trace_ce, SL("_trace"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &flag)) {
		zephir_read_static_property_ce(&_2$$4, brisk_kernel_trace_ce, SL("_trace"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$4, &_2$$4, &flag, PH_NOISY | PH_READONLY, "brisk/Kernel/Trace.zep", 26 TSRMLS_CC);
		RETURN_CTOR(&_3$$4);
	}
	RETURN_MM_NULL();

}

void zephir_init_static_properties_Brisk_Kernel_Trace(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(brisk_kernel_trace_ce, ZEND_STRL("_trace"), &_0);
	ZEPHIR_MM_RESTORE();

}

