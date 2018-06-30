
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

PHP_METHOD(Brisk_Kernel_Handler, setHandler) {

	zend_bool _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *handler = NULL, handler_sub, __$null, _1$$4;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &type_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}
	if (!handler) {
		handler = &handler_sub;
		ZEPHIR_CPY_WRT(handler, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(handler);
	}


	if (ZEPHIR_IS_STRING(&type, "exception")) {
		ZEPHIR_CALL_FUNCTION(NULL, "restore_exception_handler", NULL, 30);
		zephir_check_call_status();
		_0$$3 = Z_TYPE_P(handler) == IS_NULL;
		if (!(_0$$3)) {
			_0$$3 = !(zephir_is_callable(handler TSRMLS_CC));
		}
		if (_0$$3) {
			ZEPHIR_INIT_NVAR(handler);
			zephir_create_array(handler, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, brisk_kernel_handler_ce);
			if (zephir_has_constructor(&_1$$4 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			zephir_array_fast_append(handler, &_1$$4);
			ZEPHIR_INIT_NVAR(&_1$$4);
			ZVAL_STRING(&_1$$4, "display");
			zephir_array_fast_append(handler, &_1$$4);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 31, handler);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Handler, _getSource) {

	zend_bool _2$$3;
	zephir_fcall_cache_entry *_12 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, lines_offset$$3;
	zval *trace_param = NULL, source, trace_file, line$$3, lines$$3, b_line$$3, _0$$3, _1$$3, e_line$$3, i$$3, source$$3, _3$$3, _4$$3, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5, _13$$5, _15$$5, _16$$6, _17$$6, _18$$6, _19$$6, _20$$6, _21$$6, _22$$6, _23$$6, _24$$6;
	zval trace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&trace_file);
	ZVAL_UNDEF(&line$$3);
	ZVAL_UNDEF(&lines$$3);
	ZVAL_UNDEF(&b_line$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&e_line$$3);
	ZVAL_UNDEF(&i$$3);
	ZVAL_UNDEF(&source$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &trace_param);

	ZEPHIR_OBS_COPY_OR_DUP(&trace, trace_param);


	ZEPHIR_INIT_VAR(&source);
	ZVAL_STRING(&source, "");
	ZEPHIR_OBS_VAR(&trace_file);
	zephir_array_fetch_string(&trace_file, &trace, SL("file"), PH_NOISY, "brisk/Kernel/Handler.zep", 20 TSRMLS_CC);
	if (zephir_is_true(&trace_file)) {
		ZEPHIR_OBS_VAR(&line$$3);
		zephir_array_fetch_string(&line$$3, &trace, SL("line"), PH_NOISY, "brisk/Kernel/Handler.zep", 22 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&lines$$3, "file", NULL, 32, &trace_file);
		zephir_check_call_status();
		lines_offset$$3 = 8;
		ZVAL_LONG(&_0$$3, (((zephir_get_numberval(&line$$3) - lines_offset$$3) - 1)));
		ZVAL_LONG(&_1$$3, 0);
		ZEPHIR_CALL_FUNCTION(&b_line$$3, "max", NULL, 33, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_0$$3, ((zephir_get_numberval(&line$$3) + lines_offset$$3)));
		ZVAL_LONG(&_1$$3, zephir_fast_count_int(&lines$$3 TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&e_line$$3, "min", NULL, 34, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&_4$$3, &e_line$$3);
		ZEPHIR_CPY_WRT(&_3$$3, &b_line$$3);
		_2$$3 = 0;
		if (ZEPHIR_LE(&_3$$3, &_4$$3)) {
			while (1) {
				if (_2$$3) {
					ZEPHIR_SEPARATE(&_3$$3);
					zephir_increment(&_3$$3);
					if (!(ZEPHIR_LE(&_3$$3, &_4$$3))) {
						break;
					}
				} else {
					_2$$3 = 1;
				}
				ZEPHIR_CPY_WRT(&i$$3, &_3$$3);
				ZEPHIR_INIT_NVAR(&source$$3);
				if (ZEPHIR_IS_LONG(&i$$3, ((zephir_get_numberval(&line$$3) - 1)))) {
					ZEPHIR_INIT_NVAR(&_5$$5);
					zephir_array_fetch(&_6$$5, &lines$$3, &i$$3, PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 31 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_7$$5);
					ZVAL_STRING(&_7$$5, "\t");
					ZEPHIR_INIT_NVAR(&_8$$5);
					ZVAL_STRING(&_8$$5, "    ");
					zephir_fast_str_replace(&_5$$5, &_7$$5, &_8$$5, &_6$$5 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_9$$5);
					ZVAL_STRING(&_9$$5, "%04d：%s");
					ZVAL_LONG(&_10$$5, (zephir_get_numberval(&i$$3) + 1));
					ZEPHIR_CALL_FUNCTION(&_11$$5, "sprintf", &_12, 4, &_9$$5, &_10$$5, &_5$$5);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_13$$5, "htmlspecialchars", &_14, 35, &_11$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_15$$5);
					ZEPHIR_CONCAT_VSVS(&_15$$5, &source$$3, "<div class='error'>", &_13$$5, "</div>");
					ZEPHIR_CPY_WRT(&source$$3, &_15$$5);
				} else {
					ZEPHIR_INIT_NVAR(&_16$$6);
					zephir_array_fetch(&_17$$6, &lines$$3, &i$$3, PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 33 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_18$$6);
					ZVAL_STRING(&_18$$6, "\t");
					ZEPHIR_INIT_NVAR(&_19$$6);
					ZVAL_STRING(&_19$$6, "    ");
					zephir_fast_str_replace(&_16$$6, &_18$$6, &_19$$6, &_17$$6 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_20$$6);
					ZVAL_STRING(&_20$$6, "%04d：%s");
					ZVAL_LONG(&_21$$6, (zephir_get_numberval(&i$$3) + 1));
					ZEPHIR_CALL_FUNCTION(&_22$$6, "sprintf", &_12, 4, &_20$$6, &_21$$6, &_16$$6);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_23$$6, "htmlspecialchars", &_14, 35, &_22$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_24$$6);
					ZEPHIR_CONCAT_VV(&_24$$6, &source$$3, &_23$$6);
					ZEPHIR_CPY_WRT(&source$$3, &_24$$6);
				}
			}
		}
	}
	RETURN_CCTOR(&source);

}

PHP_METHOD(Brisk_Kernel_Handler, usortfunc) {

	zval *a, a_sub, *b, b_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&a_sub);
	ZVAL_UNDEF(&b_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a, &b);



	ZEPHIR_INIT_VAR(&_0);
	if (zephir_fast_strlen_ev(a) > zephir_fast_strlen_ev(b)) {
		ZEPHIR_CPY_WRT(&_0, a);
	} else {
		ZEPHIR_CPY_WRT(&_0, b);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(Brisk_Kernel_Handler, display) {

	zval _21, _34$$6, _32$$7, _57$$9, _68$$11;
	zend_string *_2, *_24, *_31$$6, *_37$$6;
	zend_ulong _1, _23, _30$$6, _36$$6;
	zephir_fcall_cache_entry *_5 = NULL, *_11 = NULL, *_20 = NULL, *_27 = NULL, *_45 = NULL, *_52 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _50$$8;
	zval *e, e_sub, *_SERVER, message, includes, k, v, included, *_0, footerinfo, _13, _14, _18, exception_name, namespaces, _19, *_22, content, _26, _3$$3, _4$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _12$$3, _15$$4, _16$$4, _17$$4, _25$$5, trace_array$$6, trace_string$$6, _28$$6, trace$$6, k$$6, v$$6, *_29$$6, stack_trace$$6, max$$6, *_35$$6, tplcontent$$6, _51$$6, _53$$6, _54$$6, _55$$6, _56$$6, _61$$6, _62$$6, _63$$6, _64$$6, _65$$6, _66$$6, _33$$7, _38$$8, _39$$8, _40$$8, _41$$8, _42$$8, _43$$8, _44$$8, _46$$8, _47$$8, _48$$8, _49$$8, _58$$9, _59$$10, _60$$10, stack_trace$$11, _67$$11, tplcontent$$11, _69$$11, _70$$11, _71$$11, _72$$11, _73$$11, _74$$11, _75$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&includes);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&footerinfo);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&exception_name);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&trace_array$$6);
	ZVAL_UNDEF(&trace_string$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&trace$$6);
	ZVAL_UNDEF(&k$$6);
	ZVAL_UNDEF(&v$$6);
	ZVAL_UNDEF(&stack_trace$$6);
	ZVAL_UNDEF(&max$$6);
	ZVAL_UNDEF(&tplcontent$$6);
	ZVAL_UNDEF(&_51$$6);
	ZVAL_UNDEF(&_53$$6);
	ZVAL_UNDEF(&_54$$6);
	ZVAL_UNDEF(&_55$$6);
	ZVAL_UNDEF(&_56$$6);
	ZVAL_UNDEF(&_61$$6);
	ZVAL_UNDEF(&_62$$6);
	ZVAL_UNDEF(&_63$$6);
	ZVAL_UNDEF(&_64$$6);
	ZVAL_UNDEF(&_65$$6);
	ZVAL_UNDEF(&_66$$6);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_38$$8);
	ZVAL_UNDEF(&_39$$8);
	ZVAL_UNDEF(&_40$$8);
	ZVAL_UNDEF(&_41$$8);
	ZVAL_UNDEF(&_42$$8);
	ZVAL_UNDEF(&_43$$8);
	ZVAL_UNDEF(&_44$$8);
	ZVAL_UNDEF(&_46$$8);
	ZVAL_UNDEF(&_47$$8);
	ZVAL_UNDEF(&_48$$8);
	ZVAL_UNDEF(&_49$$8);
	ZVAL_UNDEF(&_58$$9);
	ZVAL_UNDEF(&_59$$10);
	ZVAL_UNDEF(&_60$$10);
	ZVAL_UNDEF(&stack_trace$$11);
	ZVAL_UNDEF(&_67$$11);
	ZVAL_UNDEF(&tplcontent$$11);
	ZVAL_UNDEF(&_69$$11);
	ZVAL_UNDEF(&_70$$11);
	ZVAL_UNDEF(&_71$$11);
	ZVAL_UNDEF(&_72$$11);
	ZVAL_UNDEF(&_73$$11);
	ZVAL_UNDEF(&_74$$11);
	ZVAL_UNDEF(&_75$$11);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_34$$6);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_57$$9);
	ZVAL_UNDEF(&_68$$11);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &e);



	ZEPHIR_CALL_METHOD(&message, e, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&includes);
	ZVAL_STRING(&includes, "");
	ZEPHIR_CALL_FUNCTION(&included, "get_included_files", NULL, 36);
	zephir_check_call_status();
	zephir_is_iterable(&included, 0, "brisk/Kernel/Handler.zep", 58);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&included), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&k, _2);
		} else {
			ZVAL_LONG(&k, _1);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _0);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZEPHIR_CALL_CE_STATIC(&_4$$3, brisk_kernel_loader_ce, "reducepath", &_5, 0, &v);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "\t");
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "    ");
		zephir_fast_str_replace(&_3$$3, &_6$$3, &_7$$3, &_4$$3 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "#%02d：%s\r\n");
		ZVAL_LONG(&_9$$3, ((zephir_get_numberval(&k) + 1)));
		ZEPHIR_CALL_FUNCTION(&_10$$3, "sprintf", &_11, 4, &_8$$3, &_9$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_12$$3);
		ZEPHIR_CONCAT_VV(&_12$$3, &includes, &_10$$3);
		ZEPHIR_CPY_WRT(&includes, &_12$$3);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	ZEPHIR_INIT_VAR(&_13);
	zephir_time(&_13);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "%Y-%m-%d %H:%M:%S");
	ZEPHIR_CALL_FUNCTION(&footerinfo, "strftime", NULL, 37, &_14, &_13);
	zephir_check_call_status();
	if (zephir_array_isset_string(_SERVER, SL("SERVER_SOFTWARE"))) {
		zephir_array_fetch_string(&_15$$4, _SERVER, SL("SERVER_SOFTWARE"), PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 61 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_16$$4);
		ZEPHIR_CONCAT_SV(&_16$$4, " ", &_15$$4);
		ZEPHIR_INIT_VAR(&_17$$4);
		ZEPHIR_CONCAT_VV(&_17$$4, &footerinfo, &_16$$4);
		ZEPHIR_CPY_WRT(&footerinfo, &_17$$4);
	}
	ZEPHIR_INIT_VAR(&_18);
	ZEPHIR_CONCAT_VSSSS(&_18, &footerinfo, " Provider by ", "Brisk", " ", "1.0.2");
	ZEPHIR_CPY_WRT(&footerinfo, &_18);
	ZEPHIR_INIT_VAR(&exception_name);
	zephir_get_class(&exception_name, e, 0 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_19, brisk_kernel_loader_ce, "getnamespace", &_20, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&namespaces);
	zephir_array_keys(&namespaces, &_19 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_21);
	zephir_create_array(&_21, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_21, this_ptr);
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "usortfunc");
	zephir_array_fast_append(&_21, &_14);
	ZEPHIR_MAKE_REF(&namespaces);
	ZEPHIR_CALL_FUNCTION(NULL, "usort", NULL, 38, &namespaces, &_21);
	ZEPHIR_UNREF(&namespaces);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_14);
	zephir_fast_explode_str(&_14, SL("\\"), &exception_name, LONG_MAX TSRMLS_CC);
	ZEPHIR_CPY_WRT(&exception_name, &_14);
	zephir_is_iterable(&exception_name, 1, "brisk/Kernel/Handler.zep", 71);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&exception_name), _23, _24, _22)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_24 != NULL) { 
			ZVAL_STR_COPY(&k, _24);
		} else {
			ZVAL_LONG(&k, _23);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _22);
		ZEPHIR_INIT_NVAR(&_25$$5);
		zephir_ucfirst(&_25$$5, &v);
		zephir_array_update_zval(&exception_name, &k, &_25$$5, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	ZEPHIR_INIT_NVAR(&_14);
	zephir_fast_join_str(&_14, SL("."), &exception_name TSRMLS_CC);
	ZEPHIR_CPY_WRT(&exception_name, &_14);
	ZEPHIR_CALL_CE_STATIC(&_26, brisk_kernel_server_ce, "iscli", &_27, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&_26)) {
		ZEPHIR_CALL_METHOD(&trace_array$$6, e, "gettrace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_28$$6, e, "gettraceasstring", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&trace_string$$6);
		zephir_fast_explode_str(&trace_string$$6, SL("\n"), &_28$$6, LONG_MAX TSRMLS_CC);
		ZEPHIR_INIT_VAR(&trace$$6);
		array_init(&trace$$6);
		zephir_is_iterable(&trace_array$$6, 0, "brisk/Kernel/Handler.zep", 87);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&trace_array$$6), _30$$6, _31$$6, _29$$6)
		{
			ZEPHIR_INIT_NVAR(&k$$6);
			if (_31$$6 != NULL) { 
				ZVAL_STR_COPY(&k$$6, _31$$6);
			} else {
				ZVAL_LONG(&k$$6, _30$$6);
			}
			ZEPHIR_INIT_NVAR(&v$$6);
			ZVAL_COPY(&v$$6, _29$$6);
			ZEPHIR_INIT_NVAR(&_32$$7);
			zephir_create_array(&_32$$7, 2, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_33$$7);
			zephir_array_fetch(&_33$$7, &trace_string$$6, &k$$6, PH_NOISY, "brisk/Kernel/Handler.zep", 82 TSRMLS_CC);
			zephir_array_update_string(&_32$$7, SL("description"), &_33$$7, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_32$$7, SL("source"), SL(""));
			zephir_array_append(&trace$$6, &_32$$7, PH_SEPARATE, "brisk/Kernel/Handler.zep", 85);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v$$6);
		ZEPHIR_INIT_NVAR(&k$$6);
		ZEPHIR_INIT_VAR(&_34$$6);
		zephir_create_array(&_34$$6, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_34$$6, SL("description"), SL("[main]"));
		add_assoc_stringl_ex(&_34$$6, SL("source"), SL("0001：[internel]"));
		zephir_array_append(&trace$$6, &_34$$6, PH_SEPARATE, "brisk/Kernel/Handler.zep", 87);
		ZEPHIR_INIT_VAR(&stack_trace$$6);
		ZVAL_STRING(&stack_trace$$6, "");
		ZEPHIR_INIT_VAR(&max$$6);
		ZVAL_LONG(&max$$6, zephir_fast_count_int(&trace$$6 TSRMLS_CC));
		zephir_is_iterable(&trace$$6, 0, "brisk/Kernel/Handler.zep", 99);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&trace$$6), _36$$6, _37$$6, _35$$6)
		{
			ZEPHIR_INIT_NVAR(&k$$6);
			if (_37$$6 != NULL) { 
				ZVAL_STR_COPY(&k$$6, _37$$6);
			} else {
				ZVAL_LONG(&k$$6, _36$$6);
			}
			ZEPHIR_INIT_NVAR(&v$$6);
			ZVAL_COPY(&v$$6, _35$$6);
			zephir_array_fetch_string(&_39$$8, &v$$6, SL("description"), PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 92 TSRMLS_CC);
			ZEPHIR_CALL_CE_STATIC(&_38$$8, brisk_kernel_loader_ce, "reducepath", &_5, 0, &_39$$8);
			zephir_check_call_status();
			zephir_array_update_string(&v$$6, SL("description"), &_38$$8, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_40$$8);
			zephir_array_fetch_string(&_41$$8, &v$$6, SL("description"), PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 93 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_42$$8);
			ZVAL_STRING(&_42$$8, "/^\\#\\d+/");
			ZEPHIR_INIT_NVAR(&_43$$8);
			ZVAL_STRING(&_43$$8, "");
			ZEPHIR_CALL_FUNCTION(&_44$$8, "preg_replace", &_45, 2, &_42$$8, &_43$$8, &_41$$8);
			zephir_check_call_status();
			zephir_fast_trim(&_40$$8, &_44$$8, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_42$$8);
			ZVAL_STRING(&_42$$8, "#%02d：%s");
			ZEPHIR_CALL_FUNCTION(&_46$$8, "sprintf", &_11, 4, &_42$$8, &max$$6, &_40$$8);
			zephir_check_call_status();
			zephir_array_update_string(&v$$6, SL("description"), &_46$$8, PH_COPY | PH_SEPARATE);
			ZEPHIR_SINIT_NVAR(_47$$8);
			ZVAL_LONG(&_47$$8, ((zephir_get_numberval(&k$$6) + 1)));
			zephir_array_fetch_string(&_48$$8, &v$$6, SL("description"), PH_NOISY | PH_READONLY, "brisk/Kernel/Handler.zep", 94 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_49$$8);
			ZEPHIR_CONCAT_VSVSVS(&_49$$8, &stack_trace$$6, "<div id=trace_title_", &_47$$8, " class=trace_title>", &_48$$8, "</div>");
			ZEPHIR_CPY_WRT(&stack_trace$$6, &_49$$8);
			_50$$8 = (zephir_get_numberval(&max$$6) - 1);
			ZEPHIR_INIT_NVAR(&max$$6);
			ZVAL_LONG(&max$$6, _50$$8);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v$$6);
		ZEPHIR_INIT_NVAR(&k$$6);
		ZEPHIR_CALL_METHOD(&tplcontent$$6, this_ptr, "_getwebtpl", NULL, 39);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_51$$6, brisk_kernel_app_ce, "getinstance", &_52, 0);
		zephir_check_call_status();
		zephir_read_property(&_53$$6, &_51$$6, SL("config"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_54$$6, &_53$$6, SL("global"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_55$$6, &_54$$6, SL("debug"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_56$$6, &_55$$6, "getvalue", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_56$$6)) {
			ZEPHIR_INIT_VAR(&_57$$9);
			zephir_create_array(&_57$$9, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_58$$9);
			ZVAL_STRING(&_58$$9, "<{detail}>");
			zephir_array_fast_append(&_57$$9, &_58$$9);
			ZEPHIR_INIT_NVAR(&_58$$9);
			ZVAL_STRING(&_58$$9, "<{/detail}>");
			zephir_array_fast_append(&_57$$9, &_58$$9);
			ZEPHIR_INIT_NVAR(&_58$$9);
			ZVAL_STRING(&_58$$9, "");
			ZEPHIR_INIT_VAR(&content);
			zephir_fast_str_replace(&content, &_57$$9, &_58$$9, &tplcontent$$6 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_59$$10);
			ZVAL_STRING(&_59$$10, "/\\<\\{detail\\}\\>[\\s\\S]*?\\<\\{\\/detail\\}\\>/");
			ZEPHIR_INIT_VAR(&_60$$10);
			ZVAL_STRING(&_60$$10, "");
			ZEPHIR_CALL_FUNCTION(&content, "preg_replace", &_45, 2, &_59$$10, &_60$$10, &tplcontent$$6);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_61$$6);
		ZEPHIR_INIT_VAR(&_62$$6);
		ZVAL_STRING(&_62$$6, "<{e}>");
		zephir_fast_str_replace(&_61$$6, &_62$$6, &exception_name, &content TSRMLS_CC);
		ZEPHIR_CPY_WRT(&content, &_61$$6);
		ZEPHIR_INIT_NVAR(&_61$$6);
		ZEPHIR_INIT_VAR(&_63$$6);
		ZVAL_STRING(&_63$$6, "<{description}>");
		zephir_fast_str_replace(&_61$$6, &_63$$6, &message, &content TSRMLS_CC);
		ZEPHIR_CPY_WRT(&content, &_61$$6);
		ZEPHIR_INIT_NVAR(&_61$$6);
		ZEPHIR_INIT_VAR(&_64$$6);
		ZVAL_STRING(&_64$$6, "<{stacktrace}>");
		zephir_fast_str_replace(&_61$$6, &_64$$6, &stack_trace$$6, &content TSRMLS_CC);
		ZEPHIR_CPY_WRT(&content, &_61$$6);
		ZEPHIR_INIT_NVAR(&_61$$6);
		ZEPHIR_INIT_VAR(&_65$$6);
		ZVAL_STRING(&_65$$6, "<{includefiles}>");
		zephir_fast_str_replace(&_61$$6, &_65$$6, &includes, &content TSRMLS_CC);
		ZEPHIR_CPY_WRT(&content, &_61$$6);
		ZEPHIR_INIT_NVAR(&_61$$6);
		ZEPHIR_INIT_VAR(&_66$$6);
		ZVAL_STRING(&_66$$6, "<{footerinfo}>");
		zephir_fast_str_replace(&_61$$6, &_66$$6, &footerinfo, &content TSRMLS_CC);
		ZEPHIR_CPY_WRT(&content, &_61$$6);
	} else {
		ZEPHIR_CALL_METHOD(&_67$$11, e, "gettraceasstring", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&stack_trace$$11, brisk_kernel_loader_ce, "reducepath", &_5, 0, &_67$$11);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&tplcontent$$11, this_ptr, "_getclitpl", NULL, 40);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_68$$11);
		zephir_create_array(&_68$$11, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_69$$11);
		ZVAL_STRING(&_69$$11, "<{detail}>");
		zephir_array_fast_append(&_68$$11, &_69$$11);
		ZEPHIR_INIT_NVAR(&_69$$11);
		ZVAL_STRING(&_69$$11, "<{/detail}>");
		zephir_array_fast_append(&_68$$11, &_69$$11);
		ZEPHIR_INIT_NVAR(&_69$$11);
		ZVAL_STRING(&_69$$11, "");
		ZEPHIR_INIT_NVAR(&content);
		zephir_fast_str_replace(&content, &_68$$11, &_69$$11, &tplcontent$$11 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_70$$11);
		ZEPHIR_INIT_VAR(&_71$$11);
		ZVAL_STRING(&_71$$11, "<{e}>");
		zephir_fast_str_replace(&_70$$11, &_71$$11, &exception_name, &content TSRMLS_CC);
		ZEPHIR_CPY_WRT(&content, &_70$$11);
		ZEPHIR_INIT_NVAR(&_70$$11);
		ZEPHIR_INIT_VAR(&_72$$11);
		ZVAL_STRING(&_72$$11, "<{description}>");
		zephir_fast_str_replace(&_70$$11, &_72$$11, &message, &content TSRMLS_CC);
		ZEPHIR_CPY_WRT(&content, &_70$$11);
		ZEPHIR_INIT_NVAR(&_70$$11);
		ZEPHIR_INIT_VAR(&_73$$11);
		ZVAL_STRING(&_73$$11, "<{stacktrace}>");
		zephir_fast_str_replace(&_70$$11, &_73$$11, &stack_trace$$11, &content TSRMLS_CC);
		ZEPHIR_CPY_WRT(&content, &_70$$11);
		ZEPHIR_INIT_NVAR(&_70$$11);
		ZEPHIR_INIT_VAR(&_74$$11);
		ZVAL_STRING(&_74$$11, "<{includefiles}>");
		zephir_fast_str_replace(&_70$$11, &_74$$11, &includes, &content TSRMLS_CC);
		ZEPHIR_CPY_WRT(&content, &_70$$11);
		ZEPHIR_INIT_NVAR(&_70$$11);
		ZEPHIR_INIT_VAR(&_75$$11);
		ZVAL_STRING(&_75$$11, "<{footerinfo}>");
		zephir_fast_str_replace(&_70$$11, &_75$$11, &footerinfo, &content TSRMLS_CC);
		ZEPHIR_CPY_WRT(&content, &_70$$11);
	}
	zend_print_zval(&content, 0);
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Handler, _getWebTpl) {

	zval str;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&str);
	ZVAL_STRING(&str, "<!Doctype html><html><head><title>Debugger</title>");
	zephir_concat_self_str(&str, SL("<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<style type='text/css'>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("body {font-family:Courier New,Tahoma;font-weight:normal;color:black;background-color:white;}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("h1 {font-size:18pt;color:red;font-family:微软雅黑,Courier New,Tahoma,sans-serif; padding-bottom: 12px; }") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("h2 {font-size:14pt;color:maroon }") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("h3 {font-weight:bold;font-size:10pt;margin:20px 0;font-family:微软雅黑,Tahoma,sans-serif; }") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("p {color:black;font-size:9pt;margin-top:-5px; }") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("code,pre {font-family:Courier New;font-size:9pt;}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("td,.version {color:gray;font-size:8pt;border-top:1px solid #aaaaaa;padding-top:3px;}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL(".source {background-color:#ffffee;}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL(".error {background-color: #ffeeee;}") TSRMLS_CC);
	zephir_concat_self_str(&str, SL(".trace_source { background-color:#fff; padding: 8px; display:none; }") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("</style>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("</head>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<body>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<h1><{e}></h1>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<h3>Description：</h3>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<p style=color:maroon><{description}></p>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<{detail}>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<h3>Backtrace：</h3>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<div class=source><code><pre><{stacktrace}></pre></code></div>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<h3>Include files：</h3>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<div class=source><code><pre><{includefiles}></pre></code></div>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<{/detail}>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<div class=version>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<{footerinfo}>") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("</div></body></html>") TSRMLS_CC);
	RETURN_CCTOR(&str);

}

PHP_METHOD(Brisk_Kernel_Handler, _getCliTpl) {

	zval str;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&str);
	ZVAL_STRING(&str, "====== <{e}> ======\n");
	zephir_concat_self_str(&str, SL("Description：\n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<{description}>\n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("Backtrace：\n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<{stacktrace}>\n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("Include files：\n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<{includefiles}>\n") TSRMLS_CC);
	zephir_concat_self_str(&str, SL("<{footerinfo}>\n") TSRMLS_CC);
	RETURN_CCTOR(&str);

}

