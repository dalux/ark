
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/time.h"
#include "kernel/object.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Handler) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Handler, brisk, kernel_handler, brisk_kernel_handler_method_entry, 0);

	return SUCCESS;

}

/**
 * Set system exception handling handle
 *
 * @param string type
 * @param mixed handler
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Handler, setHandler) {

	zend_bool _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *handler = NULL, *_1$$4 = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &type_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	if (!handler) {
		ZEPHIR_CPY_WRT(handler, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(handler);
	}


	if (ZEPHIR_IS_STRING(type, "exception")) {
		ZEPHIR_CALL_FUNCTION(NULL, "restore_exception_handler", NULL, 35);
		zephir_check_call_status();
		_0$$3 = Z_TYPE_P(handler) == IS_NULL;
		if (!(_0$$3)) {
			_0$$3 = !(zephir_is_callable(handler TSRMLS_CC));
		}
		if (_0$$3) {
			ZEPHIR_INIT_NVAR(handler);
			zephir_create_array(handler, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_1$$4);
			object_init_ex(_1$$4, brisk_kernel_handler_ce);
			if (zephir_has_constructor(_1$$4 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			zephir_array_fast_append(handler, _1$$4);
			ZEPHIR_INIT_NVAR(_1$$4);
			ZVAL_STRING(_1$$4, "display", 1);
			zephir_array_fast_append(handler, _1$$4);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 36, handler);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Handler, _getSource) {

	zend_bool _2$$3;
	zephir_fcall_cache_entry *_12 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, lines_offset$$3;
	zval *trace_param = NULL, *source = NULL, *trace_file = NULL, *line$$3 = NULL, *lines$$3 = NULL, *b_line$$3 = NULL, *_0$$3 = NULL, *_1$$3 = NULL, *e_line$$3 = NULL, *i$$3 = NULL, *source$$3 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, *_5$$5 = NULL, *_6$$5, _7$$5 = zval_used_for_init, _8$$5 = zval_used_for_init, _9$$5 = zval_used_for_init, _10$$5 = zval_used_for_init, *_11$$5 = NULL, *_13$$5 = NULL, *_15$$5 = NULL, *_16$$6 = NULL, *_17$$6, _18$$6 = zval_used_for_init, _19$$6 = zval_used_for_init, _20$$6 = zval_used_for_init, _21$$6 = zval_used_for_init, *_22$$6 = NULL, *_23$$6 = NULL, *_24$$6 = NULL;
	zval *trace = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &trace_param);

	trace = trace_param;


	ZEPHIR_INIT_VAR(source);
	ZVAL_STRING(source, "", 1);
	ZEPHIR_OBS_VAR(trace_file);
	zephir_array_fetch_string(&trace_file, trace, SL("file"), PH_NOISY, "brisk/Kernel/Handler.zep", 27 TSRMLS_CC);
	if (zephir_is_true(trace_file)) {
		ZEPHIR_OBS_VAR(line$$3);
		zephir_array_fetch_string(&line$$3, trace, SL("line"), PH_NOISY, "brisk/Kernel/Handler.zep", 29 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&lines$$3, "file", NULL, 37, trace_file);
		zephir_check_call_status();
		lines_offset$$3 = 8;
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_LONG(_0$$3, (((zephir_get_numberval(line$$3) - lines_offset$$3) - 1)));
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_LONG(_1$$3, 0);
		ZEPHIR_CALL_FUNCTION(&b_line$$3, "max", NULL, 38, _0$$3, _1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0$$3);
		ZVAL_LONG(_0$$3, ((zephir_get_numberval(line$$3) + lines_offset$$3)));
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_LONG(_1$$3, zephir_fast_count_int(lines$$3 TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&e_line$$3, "min", NULL, 39, _0$$3, _1$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(_4$$3, e_line$$3);
		ZEPHIR_CPY_WRT(_3$$3, b_line$$3);
		_2$$3 = 0;
		if (ZEPHIR_LE(_3$$3, _4$$3)) {
			while (1) {
				if (_2$$3) {
					ZEPHIR_SEPARATE(_3$$3);
					zephir_increment(_3$$3);
					if (!(ZEPHIR_LE(_3$$3, _4$$3))) {
						break;
					}
				} else {
					_2$$3 = 1;
				}
				ZEPHIR_CPY_WRT(i$$3, _3$$3);
				ZEPHIR_INIT_NVAR(source$$3);
				if (ZEPHIR_IS_LONG(i$$3, ((zephir_get_numberval(line$$3) - 1)))) {
					ZEPHIR_INIT_NVAR(_5$$5);
					zephir_array_fetch(&_6$$5, lines$$3, i$$3, PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 38 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_7$$5);
					ZVAL_STRING(&_7$$5, "\t", 0);
					ZEPHIR_SINIT_NVAR(_8$$5);
					ZVAL_STRING(&_8$$5, "    ", 0);
					zephir_fast_str_replace(&_5$$5, &_7$$5, &_8$$5, _6$$5 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_9$$5);
					ZVAL_STRING(&_9$$5, "%04d：%s", 0);
					ZEPHIR_SINIT_NVAR(_10$$5);
					ZVAL_LONG(&_10$$5, (zephir_get_numberval(i$$3) + 1));
					ZEPHIR_CALL_FUNCTION(&_11$$5, "sprintf", &_12, 40, &_9$$5, &_10$$5, _5$$5);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_13$$5, "htmlspecialchars", &_14, 41, _11$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_15$$5);
					ZEPHIR_CONCAT_VSVS(_15$$5, source$$3, "<div class='error'>", _13$$5, "</div>");
					ZEPHIR_CPY_WRT(source$$3, _15$$5);
				} else {
					ZEPHIR_INIT_NVAR(_16$$6);
					zephir_array_fetch(&_17$$6, lines$$3, i$$3, PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 40 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_18$$6);
					ZVAL_STRING(&_18$$6, "\t", 0);
					ZEPHIR_SINIT_NVAR(_19$$6);
					ZVAL_STRING(&_19$$6, "    ", 0);
					zephir_fast_str_replace(&_16$$6, &_18$$6, &_19$$6, _17$$6 TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_20$$6);
					ZVAL_STRING(&_20$$6, "%04d：%s", 0);
					ZEPHIR_SINIT_NVAR(_21$$6);
					ZVAL_LONG(&_21$$6, (zephir_get_numberval(i$$3) + 1));
					ZEPHIR_CALL_FUNCTION(&_22$$6, "sprintf", &_12, 40, &_20$$6, &_21$$6, _16$$6);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_23$$6, "htmlspecialchars", &_14, 41, _22$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_24$$6);
					ZEPHIR_CONCAT_VV(_24$$6, source$$3, _23$$6);
					ZEPHIR_CPY_WRT(source$$3, _24$$6);
				}
			}
		}
	}
	RETURN_CCTOR(source);

}

PHP_METHOD(Brisk_Kernel_Handler, usortfunc) {

	zval *a, *b, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a, &b);



	ZEPHIR_INIT_VAR(_0);
	if (zephir_fast_strlen_ev(a) > zephir_fast_strlen_ev(b)) {
		ZEPHIR_CPY_WRT(_0, a);
	} else {
		ZEPHIR_CPY_WRT(_0, b);
	}
	RETURN_CCTOR(_0);

}

/**
 * Rendering system Exception Trace information
 *
 * @param object e
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Handler, display) {

	zend_bool _57$$6;
	zval *_21, *_35$$6, *_33$$7 = NULL, *_58$$9, *_70$$11;
	HashTable *_1, *_24, *_31$$6, *_37$$6;
	HashPosition _0, _23, _30$$6, _36$$6;
	zephir_fcall_cache_entry *_5 = NULL, *_11 = NULL, *_20 = NULL, *_28 = NULL, *_46 = NULL, *_53 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _51$$8;
	zval *e, *_SERVER, *message = NULL, *includes = NULL, *k = NULL, *v = NULL, *included = NULL, **_2, *footerinfo = NULL, *_13, _14, *_18, *exception_name = NULL, *namespaces = NULL, *_19 = NULL, *_22 = NULL, **_25, *content = NULL, *_27 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, _6$$3 = zval_used_for_init, _7$$3 = zval_used_for_init, _8$$3 = zval_used_for_init, _9$$3 = zval_used_for_init, *_10$$3 = NULL, *_12$$3 = NULL, *_15$$4, *_16$$4, *_17$$4, *_26$$5 = NULL, *trace_array$$6 = NULL, *trace_string$$6 = NULL, *_29$$6 = NULL, *trace$$6 = NULL, *k$$6 = NULL, *v$$6 = NULL, **_32$$6, *stack_trace$$6 = NULL, *max$$6 = NULL, **_38$$6, *debug$$6 = NULL, *tplcontent$$6 = NULL, *_52$$6 = NULL, *_54$$6, *_55$$6, *_56$$6, *_63$$6 = NULL, _64$$6, _65$$6, _66$$6, _67$$6, _68$$6, *_34$$7 = NULL, *_39$$8 = NULL, *_40$$8, *_41$$8 = NULL, *_42$$8, *_43$$8 = NULL, *_44$$8 = NULL, *_45$$8 = NULL, _47$$8 = zval_used_for_init, *_48$$8 = NULL, *_49$$8, *_50$$8 = NULL, *_59$$9 = NULL, _60$$9, *_61$$10, *_62$$10, *stack_trace$$11 = NULL, *_69$$11 = NULL, *tplcontent$$11 = NULL, *_71$$11 = NULL, _72$$11, _73$$11, _74$$11, _75$$11, _76$$11, _77$$11;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &e);



	ZEPHIR_CALL_METHOD(&message, e, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(includes);
	ZVAL_STRING(includes, "", 1);
	ZEPHIR_CALL_FUNCTION(&included, "get_included_files", NULL, 42);
	zephir_check_call_status();
	zephir_is_iterable(included, &_1, &_0, 0, 0, "brisk/Kernel/Handler.zep", 71);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_INIT_NVAR(_3$$3);
		ZEPHIR_CALL_CE_STATIC(&_4$$3, brisk_kernel_loader_ce, "reducepath", &_5, 0, v);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_6$$3);
		ZVAL_STRING(&_6$$3, "\t", 0);
		ZEPHIR_SINIT_NVAR(_7$$3);
		ZVAL_STRING(&_7$$3, "    ", 0);
		zephir_fast_str_replace(&_3$$3, &_6$$3, &_7$$3, _4$$3 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_8$$3);
		ZVAL_STRING(&_8$$3, "#%02d：%s\r\n", 0);
		ZEPHIR_SINIT_NVAR(_9$$3);
		ZVAL_LONG(&_9$$3, ((zephir_get_numberval(k) + 1)));
		ZEPHIR_CALL_FUNCTION(&_10$$3, "sprintf", &_11, 40, &_8$$3, &_9$$3, _3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_12$$3);
		ZEPHIR_CONCAT_VV(_12$$3, includes, _10$$3);
		ZEPHIR_CPY_WRT(includes, _12$$3);
	}
	ZEPHIR_INIT_VAR(_13);
	zephir_time(_13);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_STRING(&_14, "%Y-%m-%d %H:%M:%S", 0);
	ZEPHIR_CALL_FUNCTION(&footerinfo, "strftime", NULL, 43, &_14, _13);
	zephir_check_call_status();
	if (zephir_array_isset_string(_SERVER, SS("SERVER_SOFTWARE"))) {
		zephir_array_fetch_string(&_15$$4, _SERVER, SL("SERVER_SOFTWARE"), PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 74 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_16$$4);
		ZEPHIR_CONCAT_SV(_16$$4, " ", _15$$4);
		ZEPHIR_INIT_VAR(_17$$4);
		ZEPHIR_CONCAT_VV(_17$$4, footerinfo, _16$$4);
		ZEPHIR_CPY_WRT(footerinfo, _17$$4);
	}
	ZEPHIR_INIT_VAR(_18);
	ZEPHIR_CONCAT_VSSSS(_18, footerinfo, " Provider by ", "Brisk", " ", "1.0.0");
	ZEPHIR_CPY_WRT(footerinfo, _18);
	ZEPHIR_INIT_VAR(exception_name);
	zephir_get_class(exception_name, e, 0 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_19, brisk_kernel_loader_ce, "getnamespace", &_20, 44);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(namespaces);
	zephir_array_keys(namespaces, _19 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_21);
	zephir_create_array(_21, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_21, this_ptr);
	ZEPHIR_INIT_VAR(_22);
	ZVAL_STRING(_22, "usortfunc", 1);
	zephir_array_fast_append(_21, _22);
	ZEPHIR_MAKE_REF(namespaces);
	ZEPHIR_CALL_FUNCTION(NULL, "usort", NULL, 45, namespaces, _21);
	ZEPHIR_UNREF(namespaces);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_22);
	zephir_fast_explode_str(_22, SL("\\"), exception_name, LONG_MAX TSRMLS_CC);
	ZEPHIR_CPY_WRT(exception_name, _22);
	zephir_is_iterable(exception_name, &_24, &_23, 1, 0, "brisk/Kernel/Handler.zep", 84);
	for (
	  ; zend_hash_get_current_data_ex(_24, (void**) &_25, &_23) == SUCCESS
	  ; zend_hash_move_forward_ex(_24, &_23)
	) {
		ZEPHIR_GET_HMKEY(k, _24, _23);
		ZEPHIR_GET_HVALUE(v, _25);
		ZEPHIR_INIT_NVAR(_26$$5);
		zephir_ucfirst(_26$$5, v);
		zephir_array_update_zval(&exception_name, k, &_26$$5, PH_COPY | PH_SEPARATE);
	}
	zend_hash_destroy(_24);
	FREE_HASHTABLE(_24);
	ZEPHIR_INIT_NVAR(_22);
	zephir_fast_join_str(_22, SL("."), exception_name TSRMLS_CC);
	ZEPHIR_CPY_WRT(exception_name, _22);
	ZEPHIR_CALL_CE_STATIC(&_27, brisk_kernel_server_ce, "iscli", &_28, 20);
	zephir_check_call_status();
	if (!zephir_is_true(_27)) {
		ZEPHIR_CALL_METHOD(&trace_array$$6, e, "gettrace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_29$$6, e, "gettraceasstring", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(trace_string$$6);
		zephir_fast_explode_str(trace_string$$6, SL("\n"), _29$$6, LONG_MAX TSRMLS_CC);
		ZEPHIR_INIT_VAR(trace$$6);
		array_init(trace$$6);
		zephir_is_iterable(trace_array$$6, &_31$$6, &_30$$6, 0, 0, "brisk/Kernel/Handler.zep", 99);
		for (
		  ; zend_hash_get_current_data_ex(_31$$6, (void**) &_32$$6, &_30$$6) == SUCCESS
		  ; zend_hash_move_forward_ex(_31$$6, &_30$$6)
		) {
			ZEPHIR_GET_HMKEY(k$$6, _31$$6, _30$$6);
			ZEPHIR_GET_HVALUE(v$$6, _32$$6);
			ZEPHIR_INIT_NVAR(_33$$7);
			zephir_create_array(_33$$7, 2, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_34$$7);
			zephir_array_fetch(&_34$$7, trace_string$$6, k$$6, PH_NOISY, "brisk/Kernel/Handler.zep", 95 TSRMLS_CC);
			zephir_array_update_string(&_33$$7, SL("description"), &_34$$7, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(_33$$7, SS("source"), SL(""), 1);
			zephir_array_append(&trace$$6, _33$$7, PH_SEPARATE, "brisk/Kernel/Handler.zep", 97);
		}
		ZEPHIR_INIT_VAR(_35$$6);
		zephir_create_array(_35$$6, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_35$$6, SS("description"), SL("[main]"), 1);
		add_assoc_stringl_ex(_35$$6, SS("source"), SL("0001：[internel]"), 1);
		zephir_array_append(&trace$$6, _35$$6, PH_SEPARATE, "brisk/Kernel/Handler.zep", 99);
		ZEPHIR_INIT_VAR(stack_trace$$6);
		ZVAL_STRING(stack_trace$$6, "", 1);
		ZEPHIR_INIT_VAR(max$$6);
		ZVAL_LONG(max$$6, zephir_fast_count_int(trace$$6 TSRMLS_CC));
		zephir_is_iterable(trace$$6, &_37$$6, &_36$$6, 0, 0, "brisk/Kernel/Handler.zep", 110);
		for (
		  ; zend_hash_get_current_data_ex(_37$$6, (void**) &_38$$6, &_36$$6) == SUCCESS
		  ; zend_hash_move_forward_ex(_37$$6, &_36$$6)
		) {
			ZEPHIR_GET_HMKEY(k$$6, _37$$6, _36$$6);
			ZEPHIR_GET_HVALUE(v$$6, _38$$6);
			zephir_array_fetch_string(&_40$$8, v$$6, SL("description"), PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 104 TSRMLS_CC);
			ZEPHIR_CALL_CE_STATIC(&_39$$8, brisk_kernel_loader_ce, "reducepath", &_5, 0, _40$$8);
			zephir_check_call_status();
			zephir_array_update_string(&v$$6, SL("description"), &_39$$8, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_41$$8);
			zephir_array_fetch_string(&_42$$8, v$$6, SL("description"), PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 105 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_43$$8);
			ZVAL_STRING(_43$$8, "~^#\\d+~", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_44$$8);
			ZVAL_STRING(_44$$8, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_45$$8, "preg_replace", &_46, 4, _43$$8, _44$$8, _42$$8);
			zephir_check_temp_parameter(_43$$8);
			zephir_check_temp_parameter(_44$$8);
			zephir_check_call_status();
			zephir_fast_trim(_41$$8, _45$$8, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_47$$8);
			ZVAL_STRING(&_47$$8, "#%02d：%s", 0);
			ZEPHIR_CALL_FUNCTION(&_48$$8, "sprintf", &_11, 40, &_47$$8, max$$6, _41$$8);
			zephir_check_call_status();
			zephir_array_update_string(&v$$6, SL("description"), &_48$$8, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_47$$8);
			ZVAL_LONG(&_47$$8, ((zephir_get_numberval(k$$6) + 1)));
			zephir_array_fetch_string(&_49$$8, v$$6, SL("description"), PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 106 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_50$$8);
			ZEPHIR_CONCAT_VSVSVS(_50$$8, stack_trace$$6, "<div id=trace_title_", &_47$$8, " class=trace_title>", _49$$8, "</div>");
			ZEPHIR_CPY_WRT(stack_trace$$6, _50$$8);
			_51$$8 = (zephir_get_numberval(max$$6) - 1);
			ZEPHIR_INIT_NVAR(max$$6);
			ZVAL_LONG(max$$6, _51$$8);
		}
		ZEPHIR_CALL_CE_STATIC(&_52$$6, brisk_kernel_app_ce, "getinstance", &_53, 46);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_54$$6);
		zephir_read_property(&_54$$6, _52$$6, SL("config"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_55$$6);
		zephir_read_property(&_55$$6, _54$$6, SL("global"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_56$$6);
		zephir_read_property(&_56$$6, _55$$6, SL("debug"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&debug$$6, _56$$6, "getvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&tplcontent$$6, this_ptr, "_getwebtpl", NULL, 47);
		zephir_check_call_status();
		_57$$6 = zephir_is_true(debug$$6);
		if (!(_57$$6)) {
			_57$$6 = Z_TYPE_P(debug$$6) == IS_NULL;
		}
		if (_57$$6) {
			ZEPHIR_INIT_VAR(_58$$9);
			zephir_create_array(_58$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_59$$9);
			ZVAL_STRING(_59$$9, "{detail}", 1);
			zephir_array_fast_append(_58$$9, _59$$9);
			ZEPHIR_INIT_NVAR(_59$$9);
			ZVAL_STRING(_59$$9, "{/detail}", 1);
			zephir_array_fast_append(_58$$9, _59$$9);
			ZEPHIR_SINIT_VAR(_60$$9);
			ZVAL_STRING(&_60$$9, "", 0);
			ZEPHIR_INIT_VAR(content);
			zephir_fast_str_replace(&content, _58$$9, &_60$$9, tplcontent$$6 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_61$$10);
			ZVAL_STRING(_61$$10, "/{detail}[\\s\\S]*?{\\/detail}/i", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_62$$10);
			ZVAL_STRING(_62$$10, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&content, "preg_replace", &_46, 4, _61$$10, _62$$10, tplcontent$$6);
			zephir_check_temp_parameter(_61$$10);
			zephir_check_temp_parameter(_62$$10);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_63$$6);
		ZEPHIR_SINIT_VAR(_64$$6);
		ZVAL_STRING(&_64$$6, "{e}", 0);
		zephir_fast_str_replace(&_63$$6, &_64$$6, exception_name, content TSRMLS_CC);
		ZEPHIR_CPY_WRT(content, _63$$6);
		ZEPHIR_INIT_NVAR(_63$$6);
		ZEPHIR_SINIT_VAR(_65$$6);
		ZVAL_STRING(&_65$$6, "{description}", 0);
		zephir_fast_str_replace(&_63$$6, &_65$$6, message, content TSRMLS_CC);
		ZEPHIR_CPY_WRT(content, _63$$6);
		ZEPHIR_INIT_NVAR(_63$$6);
		ZEPHIR_SINIT_VAR(_66$$6);
		ZVAL_STRING(&_66$$6, "{stacktrace}", 0);
		zephir_fast_str_replace(&_63$$6, &_66$$6, stack_trace$$6, content TSRMLS_CC);
		ZEPHIR_CPY_WRT(content, _63$$6);
		ZEPHIR_INIT_NVAR(_63$$6);
		ZEPHIR_SINIT_VAR(_67$$6);
		ZVAL_STRING(&_67$$6, "{includefiles}", 0);
		zephir_fast_str_replace(&_63$$6, &_67$$6, includes, content TSRMLS_CC);
		ZEPHIR_CPY_WRT(content, _63$$6);
		ZEPHIR_INIT_NVAR(_63$$6);
		ZEPHIR_SINIT_VAR(_68$$6);
		ZVAL_STRING(&_68$$6, "{footerinfo}", 0);
		zephir_fast_str_replace(&_63$$6, &_68$$6, footerinfo, content TSRMLS_CC);
		ZEPHIR_CPY_WRT(content, _63$$6);
	} else {
		ZEPHIR_CALL_METHOD(&_69$$11, e, "gettraceasstring", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&stack_trace$$11, brisk_kernel_loader_ce, "reducepath", &_5, 0, _69$$11);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&tplcontent$$11, this_ptr, "_getclitpl", NULL, 48);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_70$$11);
		zephir_create_array(_70$$11, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_71$$11);
		ZVAL_STRING(_71$$11, "{detail}", 1);
		zephir_array_fast_append(_70$$11, _71$$11);
		ZEPHIR_INIT_NVAR(_71$$11);
		ZVAL_STRING(_71$$11, "{/detail}", 1);
		zephir_array_fast_append(_70$$11, _71$$11);
		ZEPHIR_SINIT_VAR(_72$$11);
		ZVAL_STRING(&_72$$11, "", 0);
		ZEPHIR_INIT_NVAR(content);
		zephir_fast_str_replace(&content, _70$$11, &_72$$11, tplcontent$$11 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_71$$11);
		ZEPHIR_SINIT_VAR(_73$$11);
		ZVAL_STRING(&_73$$11, "{e}", 0);
		zephir_fast_str_replace(&_71$$11, &_73$$11, exception_name, content TSRMLS_CC);
		ZEPHIR_CPY_WRT(content, _71$$11);
		ZEPHIR_INIT_NVAR(_71$$11);
		ZEPHIR_SINIT_VAR(_74$$11);
		ZVAL_STRING(&_74$$11, "{description}", 0);
		zephir_fast_str_replace(&_71$$11, &_74$$11, message, content TSRMLS_CC);
		ZEPHIR_CPY_WRT(content, _71$$11);
		ZEPHIR_INIT_NVAR(_71$$11);
		ZEPHIR_SINIT_VAR(_75$$11);
		ZVAL_STRING(&_75$$11, "{stacktrace}", 0);
		zephir_fast_str_replace(&_71$$11, &_75$$11, stack_trace$$11, content TSRMLS_CC);
		ZEPHIR_CPY_WRT(content, _71$$11);
		ZEPHIR_INIT_NVAR(_71$$11);
		ZEPHIR_SINIT_VAR(_76$$11);
		ZVAL_STRING(&_76$$11, "{includefiles}", 0);
		zephir_fast_str_replace(&_71$$11, &_76$$11, includes, content TSRMLS_CC);
		ZEPHIR_CPY_WRT(content, _71$$11);
		ZEPHIR_INIT_NVAR(_71$$11);
		ZEPHIR_SINIT_VAR(_77$$11);
		ZVAL_STRING(&_77$$11, "{footerinfo}", 0);
		zephir_fast_str_replace(&_71$$11, &_77$$11, footerinfo, content TSRMLS_CC);
		ZEPHIR_CPY_WRT(content, _71$$11);
	}
	zend_print_zval(content, 0);
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Handler, _getWebTpl) {

	zval *str = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(str);
	ZVAL_STRING(str, "<!Doctype html><html><head><title>Debugger</title>", 1);
	zephir_concat_self_str(&str, SL("<style type='text/css'>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("body {font-family:Courier New,Tahoma;font-weight:normal;color:black;background-color:white;}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("h1 {font-size:18pt;color:red;font-family:Tahoma,Courier New,sans-serif; padding-bottom: 12px; }") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("h2 {font-size:14pt;color:maroon }") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("h3 {font-weight:bold;font-size:10pt;margin:20px 0;font-family:Tahoma,sans-serif; }") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("p {color:black;font-size:9pt;margin-top:-5px; }") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("code,pre {font-family:Courier New;font-size:9pt;}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("td,.version {color:gray;font-size:8pt;border-top:1px solid #aaaaaa;padding-top:3px;}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL(".source {background-color:#ffffee;}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL(".error {background-color: #ffeeee;}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL(".trace_source { background-color:#fff; padding: 8px; display:none; }") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("</style>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("</head>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<body>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<h1>{e}</h1>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<h3>Description: </h3>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<p style=color:maroon>{description}</p>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("{detail}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<h3>Backtrace: </h3>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<div class=source><code><pre>{stacktrace}</pre></code></div>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<h3>Include files: </h3>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<div class=source><code><pre>{includefiles}</pre></code></div>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("{/detail}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<div class=version>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("{footerinfo}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("</div></body></html>") TSRMLS_CC);
	RETURN_CCTOR(str);

}

PHP_METHOD(Brisk_Kernel_Handler, _getCliTpl) {

	zval *str = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(str);
	ZVAL_STRING(str, "====== {e} ======\n", 1);
	zephir_concat_self_str(&str, SL("Description: \n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("{description}\n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("Backtrace: \n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("{stacktrace}\n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("Include files: \n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("{includefiles}\n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("{footerinfo}\n") TSRMLS_CC);
	RETURN_CCTOR(str);

}

