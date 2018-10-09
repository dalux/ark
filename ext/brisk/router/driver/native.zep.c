
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Brisk_Router_Driver_Native) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Router\\Driver, Native, brisk, router_driver_native, brisk_router_routerfather_ce, brisk_router_driver_native_method_entry, 0);

	return SUCCESS;

}

/**
 * Routing ready
 *
 * @return null
 */
PHP_METHOD(Brisk_Router_Driver_Native, ready) {

	zval *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_http_request_ce, "setready", &_0, 105, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Routing path distribution
 *
 * @return null
 */
PHP_METHOD(Brisk_Router_Driver_Native, dispatch) {

	HashTable *_17$$4;
	HashPosition _16$$4;
	zval *trace = NULL, *caller = NULL, *path_now = NULL, *auto_include = NULL, *_0 = NULL, *_2 = NULL, *_4, *_5 = NULL, *_6, *_7$$3 = NULL, *_8$$3, *_9$$3, *path_nodes$$4 = NULL, *path_root$$4 = NULL, *_10$$4 = NULL, *_12$$4 = NULL, _13$$4, *_15$$4 = NULL, *node$$4 = NULL, *file$$4 = NULL, *output$$4 = NULL, **_18$$4, *curr_path$$5 = NULL, *_14$$6 = NULL, *_19$$8 = NULL, *_21$$9 = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_11 = NULL, *_20 = NULL, *_22 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&trace, "debug_backtrace", NULL, 54);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(trace);
	ZEPHIR_CALL_FUNCTION(&_0, "end", NULL, 86, trace);
	ZEPHIR_UNREF(trace);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(&caller, "current", NULL, 3, _0);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&path_now, "dirname", &_1, 33, caller);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_2, brisk_kernel_app_ce, "getinstance", &_3, 21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, _2, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "router/option/auto_include", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_5, _4, "haskey", NULL, 0, _6);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_CALL_CE_STATIC(&_7$$3, brisk_kernel_app_ce, "getinstance", &_3, 21);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_8$$3);
		zephir_read_property(&_8$$3, _7$$3, SL("config"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_STRING(_9$$3, "router/option/auto_include", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&auto_include, _8$$3, "get", NULL, 0, _9$$3);
		zephir_check_temp_parameter(_9$$3);
		zephir_check_call_status();
	}
	if (!(Z_TYPE_P(auto_include) == IS_NULL)) {
		ZEPHIR_INIT_VAR(path_nodes$$4);
		zephir_create_array(path_nodes$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(path_nodes$$4, path_now);
		ZEPHIR_INIT_VAR(_12$$4);
		ZVAL_STRING(_12$$4, "./", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_10$$4, brisk_kernel_loader_ce, "realpath", &_11, 111, _12$$4);
		zephir_check_temp_parameter(_12$$4);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_13$$4);
		ZVAL_STRING(&_13$$4, "/", 0);
		ZEPHIR_INIT_VAR(path_root$$4);
		zephir_fast_trim(path_root$$4, _10$$4, &_13$$4, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		if (!ZEPHIR_IS_EQUAL(path_now, path_root$$4)) {
			ZEPHIR_CPY_WRT(curr_path$$5, path_now);
			while (1) {
				if (!(1)) {
					break;
				}
				ZEPHIR_CALL_FUNCTION(&_14$$6, "dirname", &_1, 33, curr_path$$5);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(curr_path$$5, _14$$6);
				if (zephir_fast_strlen_ev(curr_path$$5) < zephir_fast_strlen_ev(path_root$$4)) {
					break;
				}
				zephir_array_append(&path_nodes$$4, curr_path$$5, PH_SEPARATE, "brisk/Router/Driver/Native.zep", 50);
			}
		}
		ZEPHIR_CALL_FUNCTION(&_15$$4, "array_unique", NULL, 112, path_nodes$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&path_nodes$$4, "array_reverse", NULL, 93, _15$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_12$$4);
		zephir_is_iterable(path_nodes$$4, &_17$$4, &_16$$4, 0, 0, "brisk/Router/Driver/Native.zep", 67);
		for (
		  ; zend_hash_get_current_data_ex(_17$$4, (void**) &_18$$4, &_16$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_17$$4, &_16$$4)
		) {
			ZEPHIR_GET_HMKEY(_12$$4, _17$$4, _16$$4);
			ZEPHIR_GET_HVALUE(node$$4, _18$$4);
			ZEPHIR_INIT_NVAR(file$$4);
			ZEPHIR_CONCAT_VSV(file$$4, node$$4, "/", auto_include);
			ZEPHIR_CALL_FUNCTION(&_19$$8, "is_file", &_20, 82, file$$4);
			zephir_check_call_status();
			if (zephir_is_true(_19$$8)) {
				ZEPHIR_CALL_FUNCTION(&_21$$9, "dirname", &_1, 33, file$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "chdir", &_22, 113, _21$$9);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&output$$4, brisk_kernel_toolkit_ce, "includeonce", &_23, 0, file$$4);
				zephir_check_call_status();
				if (Z_TYPE_P(output$$4) == IS_STRING) {
					zend_print_zval(output$$4, 0);
					ZEPHIR_MM_RESTORE();
					zephir_exit_empty();
				}
			}
		}
		ZEPHIR_CALL_FUNCTION(NULL, "chdir", &_22, 113, path_now);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

