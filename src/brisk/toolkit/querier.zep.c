
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Toolkit_Querier) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Toolkit, Querier, brisk, toolkit_querier, brisk_toolkit_querier_method_entry, 0);

	zend_declare_property_null(brisk_toolkit_querier_ce, SL("_tb"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_toolkit_querier_ce, SL("_expire"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_toolkit_querier_ce, SL("_cache_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_toolkit_querier_ce, SL("_proxy"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_toolkit_querier_ce, SL("_conn"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_toolkit_querier_ce, SL("_where_mark"), ZEND_ACC_PROTECTED TSRMLS_CC);

	brisk_toolkit_querier_ce->create_object = zephir_init_properties_Brisk_Toolkit_Querier;
	return SUCCESS;

}

PHP_METHOD(Brisk_Toolkit_Querier, setConnection) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *conn, conn_sub, _0$$3, _1$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conn_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &conn);



	if (!((zephir_instance_of_ev(conn, brisk_contract_idatabase_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, brisk_exception_toolkitexception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "tbox.invalid_db_connection");
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 3, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "brisk/Toolkit/Querier.zep", 43 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zend_update_static_property(brisk_toolkit_querier_ce, ZEND_STRL("_conn"), conn);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Toolkit_Querier, getConnection) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

PHP_METHOD(Brisk_Toolkit_Querier, __construct) {

	zval *tb_param = NULL;
	zval tb;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tb);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tb_param);

	if (UNEXPECTED(Z_TYPE_P(tb_param) != IS_STRING && Z_TYPE_P(tb_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tb' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tb_param) == IS_STRING)) {
		zephir_get_strval(&tb, tb_param);
	} else {
		ZEPHIR_INIT_VAR(&tb);
		ZVAL_EMPTY_STRING(&tb);
	}


	zephir_update_property_zval(this_ptr, SL("_tb"), &tb);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Toolkit_Querier, forTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tb_param = NULL;
	zval tb;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tb);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tb_param);

	if (UNEXPECTED(Z_TYPE_P(tb_param) != IS_STRING && Z_TYPE_P(tb_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tb' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tb_param) == IS_STRING)) {
		zephir_get_strval(&tb, tb_param);
	} else {
		ZEPHIR_INIT_VAR(&tb);
		ZVAL_EMPTY_STRING(&tb);
	}


	object_init_ex(return_value, brisk_toolkit_querier_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 78, &tb);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_Querier, cache) {

	zephir_fcall_cache_entry *_2 = NULL;
	zval name;
	zval *expire_param = NULL, *cache, cache_sub, *name_param = NULL, _0$$3, _1$$3, _3$$3, _4, _5, _6;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expire_param, &cache, &name_param);

	if (UNEXPECTED(Z_TYPE_P(expire_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expire' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	expire = Z_LVAL_P(expire_param);
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


	if (!((zephir_instance_of_ev(cache, brisk_contract_icache_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, brisk_exception_toolkitexception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "tbox.invalid_cache_object");
		ZEPHIR_CALL_CE_STATIC(&_1$$3, brisk_kernel_language_ce, "get", &_2, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 3, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "brisk/Toolkit/Querier.zep", 66 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, brisk_proxy_cacheproxy_ce);
	if (zephir_has_constructor(&_4 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_proxy"), &_4);
	zephir_read_property(&_5, this_ptr, SL("_proxy"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_5, "setcacher", NULL, 0, cache);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(&_6, expire);
	zephir_update_property_zval(this_ptr, SL("_expire"), &_6);
	zephir_update_property_zval(this_ptr, SL("_cache_name"), &name);
	RETURN_THIS();

}

PHP_METHOD(Brisk_Toolkit_Querier, insert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_bool return_id;
	zval *data_param = NULL, *return_id_param = NULL, insert, added, _0, _2, _3, _4, _5, _6, _7$$4;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&insert);
	ZVAL_UNDEF(&added);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &return_id_param);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	if (!return_id_param) {
		return_id = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(return_id_param) != IS_TRUE && Z_TYPE_P(return_id_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'return_id' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	return_id = (Z_TYPE_P(return_id_param) == IS_TRUE);
	}


	zephir_read_static_property_ce(&_2, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_toolkit_sqlbuilder_ce, "insert", &_1, 0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("_tb"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&insert, &_0, "into", NULL, 0, &_4, &data);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_5, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_6, &insert, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&added, &_5, "query", NULL, 0, &_6);
	zephir_check_call_status();
	if (!zephir_is_true(&added)) {
		RETURN_MM_BOOL(0);
	} else if (return_id) {
		zephir_read_static_property_ce(&_7$$4, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_7$$4, "lastinsertid", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Brisk_Toolkit_Querier, update) {

	zend_bool _13$$4, _20$$5, _22$$5;
	zend_string *_7;
	zend_ulong _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL, *_30 = NULL, *_36 = NULL, *_38 = NULL, *_42 = NULL, *_46 = NULL, *_47 = NULL;
	zval *data_param = NULL, *condition_param = NULL, update, k, v, kk, vv, _0, _2, _3, _4, *_5, _48, _49, _8$$4, _9$$4, _11$$4, _12$$4, _14$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _21$$5, _23$$5, _24$$5, _25$$5, _26$$5, _27$$6, _28$$6, _29$$6, _31$$7, _32$$7, _33$$7, _34$$7, _35$$7, _37$$8, _39$$8, _40$$8, _41$$8, _43$$9, _44$$9, _45$$9;
	zval data, condition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&update);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&kk);
	ZVAL_UNDEF(&vv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_37$$8);
	ZVAL_UNDEF(&_39$$8);
	ZVAL_UNDEF(&_40$$8);
	ZVAL_UNDEF(&_41$$8);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_44$$9);
	ZVAL_UNDEF(&_45$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &condition_param);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	ZEPHIR_OBS_COPY_OR_DUP(&condition, condition_param);


	zephir_read_static_property_ce(&_2, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_toolkit_sqlbuilder_ce, "update", &_1, 0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("_tb"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&update, &_0, "set", NULL, 0, &_4, &data);
	zephir_check_call_status();
	zephir_is_iterable(&condition, 0, "brisk/Toolkit/Querier.zep", 112);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&condition), _6, _7, _5)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_7 != NULL) { 
			ZVAL_STR_COPY(&k, _7);
		} else {
			ZVAL_LONG(&k, _6);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _5);
		if (Z_TYPE_P(&v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_array_keys(&_8$$4, &v TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_9$$4, "current", &_10, 1, &_8$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&kk);
			zephir_fast_strtoupper(&kk, &_9$$4);
			ZEPHIR_CALL_FUNCTION(&vv, "current", &_10, 1, &v);
			zephir_check_call_status();
			zephir_read_property(&_11$$4, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_12$$4, &_11$$4, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 96 TSRMLS_CC);
			_13$$4 = zephir_is_true(&_12$$4);
			if (_13$$4) {
				_13$$4 = !ZEPHIR_IS_STRING(&vv, "");
			}
			if (_13$$4) {
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZEPHIR_INIT_NVAR(&_15$$5);
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZVAL_STRING(&_16$$5, "/^(IS|ISNOT)/i");
				zephir_preg_match(&_15$$5, &_16$$5, &kk, &_14$$5, 0, 0 , 0  TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_17$$5);
				ZEPHIR_INIT_NVAR(&_18$$5);
				ZEPHIR_INIT_NVAR(&_19$$5);
				ZVAL_STRING(&_19$$5, "/^(BETWEEN)/i");
				zephir_preg_match(&_18$$5, &_19$$5, &kk, &_17$$5, 0, 0 , 0  TSRMLS_CC);
				_20$$5 = zephir_is_true(&_18$$5);
				if (_20$$5) {
					zephir_array_fetch_long(&_21$$5, &vv, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 99 TSRMLS_CC);
					_20$$5 = !ZEPHIR_IS_STRING(&_21$$5, "");
				}
				_22$$5 = _20$$5;
				if (_22$$5) {
					zephir_array_fetch_long(&_23$$5, &vv, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 99 TSRMLS_CC);
					_22$$5 = !ZEPHIR_IS_STRING(&_23$$5, "");
				}
				ZEPHIR_INIT_NVAR(&_24$$5);
				ZEPHIR_INIT_NVAR(&_25$$5);
				ZEPHIR_INIT_NVAR(&_26$$5);
				ZVAL_STRING(&_26$$5, "/^(IN|NOTIN)/i");
				zephir_preg_match(&_25$$5, &_26$$5, &kk, &_24$$5, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(&_15$$5)) {
					zephir_read_property(&_27$$6, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_28$$6, &_27$$6, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 98 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_29$$6);
					ZEPHIR_CONCAT_VVV(&_29$$6, &k, &_28$$6, &vv);
					ZEPHIR_CALL_METHOD(NULL, &update, "where", &_30, 0, &_29$$6);
					zephir_check_call_status();
				} else if (_22$$5) {
					zephir_read_property(&_31$$7, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_32$$7, &_31$$7, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 100 TSRMLS_CC);
					zephir_array_fetch_long(&_33$$7, &vv, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 100 TSRMLS_CC);
					zephir_array_fetch_long(&_34$$7, &vv, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 100 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_35$$7);
					ZEPHIR_CONCAT_VVVSV(&_35$$7, &k, &_32$$7, &_33$$7, " AND ", &_34$$7);
					ZEPHIR_CALL_METHOD(NULL, &update, "where", &_36, 0, &_35$$7);
					zephir_check_call_status();
				} else if (zephir_is_true(&_25$$5)) {
					ZEPHIR_CALL_CE_STATIC(&_37$$8, brisk_toolkit_sqlbuilder_ce, "quote", &_38, 0, &vv);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&vv, &_37$$8);
					zephir_read_property(&_39$$8, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_40$$8, &_39$$8, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 103 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_41$$8);
					ZEPHIR_CONCAT_VVSVS(&_41$$8, &k, &_40$$8, "(", &vv, ")");
					ZEPHIR_CALL_METHOD(NULL, &update, "where", &_42, 0, &_41$$8);
					zephir_check_call_status();
				} else {
					zephir_read_property(&_43$$9, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_44$$9, &_43$$9, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 105 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_45$$9);
					ZEPHIR_CONCAT_VVS(&_45$$9, &k, &_44$$9, " ?");
					ZEPHIR_CALL_METHOD(NULL, &update, "where", &_46, 0, &_45$$9, &vv);
					zephir_check_call_status();
				}
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, &update, "wherein", &_47, 0, &k, &v);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_static_property_ce(&_48, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_49, &update, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_48, "query", NULL, 0, &_49);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_Querier, delete) {

	zend_bool _13$$4, _20$$5, _22$$5;
	zend_string *_7;
	zend_ulong _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL, *_30 = NULL, *_36 = NULL, *_38 = NULL, *_42 = NULL, *_46 = NULL, *_47 = NULL;
	zval *condition_param = NULL, delete, k, v, kk, vv, _0, _2, _3, _4, *_5, _48, _49, _8$$4, _9$$4, _11$$4, _12$$4, _14$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _21$$5, _23$$5, _24$$5, _25$$5, _26$$5, _27$$6, _28$$6, _29$$6, _31$$7, _32$$7, _33$$7, _34$$7, _35$$7, _37$$8, _39$$8, _40$$8, _41$$8, _43$$9, _44$$9, _45$$9;
	zval condition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&delete);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&kk);
	ZVAL_UNDEF(&vv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_37$$8);
	ZVAL_UNDEF(&_39$$8);
	ZVAL_UNDEF(&_40$$8);
	ZVAL_UNDEF(&_41$$8);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_44$$9);
	ZVAL_UNDEF(&_45$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &condition_param);

	ZEPHIR_OBS_COPY_OR_DUP(&condition, condition_param);


	zephir_read_static_property_ce(&_2, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_toolkit_sqlbuilder_ce, "delete", &_1, 0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("_tb"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&delete, &_0, "from", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_is_iterable(&condition, 0, "brisk/Toolkit/Querier.zep", 139);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&condition), _6, _7, _5)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_7 != NULL) { 
			ZVAL_STR_COPY(&k, _7);
		} else {
			ZVAL_LONG(&k, _6);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _5);
		if (Z_TYPE_P(&v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_array_keys(&_8$$4, &v TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_9$$4, "current", &_10, 1, &_8$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&kk);
			zephir_fast_strtoupper(&kk, &_9$$4);
			ZEPHIR_CALL_FUNCTION(&vv, "current", &_10, 1, &v);
			zephir_check_call_status();
			zephir_read_property(&_11$$4, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_12$$4, &_11$$4, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 123 TSRMLS_CC);
			_13$$4 = zephir_is_true(&_12$$4);
			if (_13$$4) {
				_13$$4 = !ZEPHIR_IS_STRING(&vv, "");
			}
			if (_13$$4) {
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZEPHIR_INIT_NVAR(&_15$$5);
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZVAL_STRING(&_16$$5, "/^(IS|ISNOT)/i");
				zephir_preg_match(&_15$$5, &_16$$5, &kk, &_14$$5, 0, 0 , 0  TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_17$$5);
				ZEPHIR_INIT_NVAR(&_18$$5);
				ZEPHIR_INIT_NVAR(&_19$$5);
				ZVAL_STRING(&_19$$5, "/^(BETWEEN)/i");
				zephir_preg_match(&_18$$5, &_19$$5, &kk, &_17$$5, 0, 0 , 0  TSRMLS_CC);
				_20$$5 = zephir_is_true(&_18$$5);
				if (_20$$5) {
					zephir_array_fetch_long(&_21$$5, &vv, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 126 TSRMLS_CC);
					_20$$5 = !ZEPHIR_IS_STRING(&_21$$5, "");
				}
				_22$$5 = _20$$5;
				if (_22$$5) {
					zephir_array_fetch_long(&_23$$5, &vv, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 126 TSRMLS_CC);
					_22$$5 = !ZEPHIR_IS_STRING(&_23$$5, "");
				}
				ZEPHIR_INIT_NVAR(&_24$$5);
				ZEPHIR_INIT_NVAR(&_25$$5);
				ZEPHIR_INIT_NVAR(&_26$$5);
				ZVAL_STRING(&_26$$5, "/^(IN|NOTIN)/i");
				zephir_preg_match(&_25$$5, &_26$$5, &kk, &_24$$5, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(&_15$$5)) {
					zephir_read_property(&_27$$6, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_28$$6, &_27$$6, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 125 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_29$$6);
					ZEPHIR_CONCAT_VVV(&_29$$6, &k, &_28$$6, &vv);
					ZEPHIR_CALL_METHOD(NULL, &delete, "where", &_30, 0, &_29$$6);
					zephir_check_call_status();
				} else if (_22$$5) {
					zephir_read_property(&_31$$7, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_32$$7, &_31$$7, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 127 TSRMLS_CC);
					zephir_array_fetch_long(&_33$$7, &vv, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 127 TSRMLS_CC);
					zephir_array_fetch_long(&_34$$7, &vv, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 127 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_35$$7);
					ZEPHIR_CONCAT_VVVSV(&_35$$7, &k, &_32$$7, &_33$$7, " AND ", &_34$$7);
					ZEPHIR_CALL_METHOD(NULL, &delete, "where", &_36, 0, &_35$$7);
					zephir_check_call_status();
				} else if (zephir_is_true(&_25$$5)) {
					ZEPHIR_CALL_CE_STATIC(&_37$$8, brisk_toolkit_sqlbuilder_ce, "quote", &_38, 0, &vv);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&vv, &_37$$8);
					zephir_read_property(&_39$$8, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_40$$8, &_39$$8, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 130 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_41$$8);
					ZEPHIR_CONCAT_VVSVS(&_41$$8, &k, &_40$$8, "(", &vv, ")");
					ZEPHIR_CALL_METHOD(NULL, &delete, "where", &_42, 0, &_41$$8);
					zephir_check_call_status();
				} else {
					zephir_read_property(&_43$$9, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_44$$9, &_43$$9, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 132 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_45$$9);
					ZEPHIR_CONCAT_VVS(&_45$$9, &k, &_44$$9, " ?");
					ZEPHIR_CALL_METHOD(NULL, &delete, "where", &_46, 0, &_45$$9, &vv);
					zephir_check_call_status();
				}
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, &delete, "wherein", &_47, 0, &k, &v);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_static_property_ce(&_48, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_49, &delete, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_48, "query", NULL, 0, &_49);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_Querier, fetchRow) {

	zend_bool _14$$5, _21$$6, _23$$6;
	zend_string *_8;
	zend_ulong _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_11 = NULL, *_31 = NULL, *_37 = NULL, *_39 = NULL, *_43 = NULL, *_47 = NULL, *_48 = NULL;
	zval *condition_param = NULL, *fields_param = NULL, select, k, v, kk, vv, _1, _3, _4, _5, *_6, _49, _57, _58, _0$$3, _9$$5, _10$$5, _12$$5, _13$$5, _15$$6, _16$$6, _17$$6, _18$$6, _19$$6, _20$$6, _22$$6, _24$$6, _25$$6, _26$$6, _27$$6, _28$$7, _29$$7, _30$$7, _32$$8, _33$$8, _34$$8, _35$$8, _36$$8, _38$$9, _40$$9, _41$$9, _42$$9, _44$$10, _45$$10, _46$$10, _50$$11, _51$$11, _53$$11, _54$$11, _55$$11, _56$$11;
	zval condition, fields, _52$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_52$$11);
	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&kk);
	ZVAL_UNDEF(&vv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_51$$11);
	ZVAL_UNDEF(&_53$$11);
	ZVAL_UNDEF(&_54$$11);
	ZVAL_UNDEF(&_55$$11);
	ZVAL_UNDEF(&_56$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &condition_param, &fields_param);

	ZEPHIR_OBS_COPY_OR_DUP(&condition, condition_param);
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&fields, fields_param);
	}


	if (zephir_fast_count_int(&fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(&fields);
		zephir_create_array(&fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "*");
		zephir_array_fast_append(&fields, &_0$$3);
	}
	zephir_read_static_property_ce(&_3, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_toolkit_sqlbuilder_ce, "select", &_2, 0, &_4);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("_tb"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&select, &_1, "from", NULL, 0, &_5, &fields);
	zephir_check_call_status();
	zephir_is_iterable(&condition, 0, "brisk/Toolkit/Querier.zep", 169);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&condition), _7, _8, _6)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_8 != NULL) { 
			ZVAL_STR_COPY(&k, _8);
		} else {
			ZVAL_LONG(&k, _7);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _6);
		if (Z_TYPE_P(&v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_9$$5);
			zephir_array_keys(&_9$$5, &v TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_10$$5, "current", &_11, 1, &_9$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&kk);
			zephir_fast_strtoupper(&kk, &_10$$5);
			ZEPHIR_CALL_FUNCTION(&vv, "current", &_11, 1, &v);
			zephir_check_call_status();
			zephir_read_property(&_12$$5, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_13$$5, &_12$$5, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 153 TSRMLS_CC);
			_14$$5 = zephir_is_true(&_13$$5);
			if (_14$$5) {
				_14$$5 = !ZEPHIR_IS_STRING(&vv, "");
			}
			if (_14$$5) {
				ZEPHIR_INIT_NVAR(&_15$$6);
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZEPHIR_INIT_NVAR(&_17$$6);
				ZVAL_STRING(&_17$$6, "/^(IS|ISNOT)/i");
				zephir_preg_match(&_16$$6, &_17$$6, &kk, &_15$$6, 0, 0 , 0  TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_18$$6);
				ZEPHIR_INIT_NVAR(&_19$$6);
				ZEPHIR_INIT_NVAR(&_20$$6);
				ZVAL_STRING(&_20$$6, "/^(BETWEEN)/i");
				zephir_preg_match(&_19$$6, &_20$$6, &kk, &_18$$6, 0, 0 , 0  TSRMLS_CC);
				_21$$6 = zephir_is_true(&_19$$6);
				if (_21$$6) {
					zephir_array_fetch_long(&_22$$6, &vv, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 156 TSRMLS_CC);
					_21$$6 = !ZEPHIR_IS_STRING(&_22$$6, "");
				}
				_23$$6 = _21$$6;
				if (_23$$6) {
					zephir_array_fetch_long(&_24$$6, &vv, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 156 TSRMLS_CC);
					_23$$6 = !ZEPHIR_IS_STRING(&_24$$6, "");
				}
				ZEPHIR_INIT_NVAR(&_25$$6);
				ZEPHIR_INIT_NVAR(&_26$$6);
				ZEPHIR_INIT_NVAR(&_27$$6);
				ZVAL_STRING(&_27$$6, "/^(IN|NOTIN)/i");
				zephir_preg_match(&_26$$6, &_27$$6, &kk, &_25$$6, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(&_16$$6)) {
					zephir_read_property(&_28$$7, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_29$$7, &_28$$7, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 155 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_30$$7);
					ZEPHIR_CONCAT_VVV(&_30$$7, &k, &_29$$7, &vv);
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_31, 0, &_30$$7);
					zephir_check_call_status();
				} else if (_23$$6) {
					zephir_read_property(&_32$$8, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_33$$8, &_32$$8, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 157 TSRMLS_CC);
					zephir_array_fetch_long(&_34$$8, &vv, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 157 TSRMLS_CC);
					zephir_array_fetch_long(&_35$$8, &vv, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 157 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_36$$8);
					ZEPHIR_CONCAT_VVVSV(&_36$$8, &k, &_33$$8, &_34$$8, " AND ", &_35$$8);
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_37, 0, &_36$$8);
					zephir_check_call_status();
				} else if (zephir_is_true(&_26$$6)) {
					ZEPHIR_CALL_CE_STATIC(&_38$$9, brisk_toolkit_sqlbuilder_ce, "quote", &_39, 0, &vv);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&vv, &_38$$9);
					zephir_read_property(&_40$$9, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_41$$9, &_40$$9, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 160 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_42$$9);
					ZEPHIR_CONCAT_VVSVS(&_42$$9, &k, &_41$$9, "(", &vv, ")");
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_43, 0, &_42$$9);
					zephir_check_call_status();
				} else {
					zephir_read_property(&_44$$10, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_45$$10, &_44$$10, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 162 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_46$$10);
					ZEPHIR_CONCAT_VVS(&_46$$10, &k, &_45$$10, " ?");
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_47, 0, &_46$$10, &vv);
					zephir_check_call_status();
				}
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, &select, "wherein", &_48, 0, &k, &v);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_49, this_ptr, SL("_expire"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_49) == IS_NULL)) {
		zephir_read_property(&_50$$11, this_ptr, SL("_proxy"), PH_NOISY_CC | PH_READONLY);
		zephir_read_static_property_ce(&_51$$11, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_52$$11);
		zephir_create_array(&_52$$11, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_53$$11, &select, "getrealsql", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_52$$11, SL("sql"), &_53$$11, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_54$$11, this_ptr, SL("_expire"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_55$$11, this_ptr, SL("_cache_name"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_56$$11);
		ZVAL_STRING(&_56$$11, "fetchRow");
		ZEPHIR_RETURN_CALL_METHOD(&_50$$11, "doproxy", NULL, 0, &_51$$11, &_56$$11, &_52$$11, &_54$$11, &_55$$11);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_static_property_ce(&_57, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_58, &select, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_57, "fetchrow", NULL, 0, &_58);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_Querier, fetchOne) {

	zend_bool _14$$5, _21$$6, _23$$6;
	zend_string *_8;
	zend_ulong _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_11 = NULL, *_31 = NULL, *_37 = NULL, *_39 = NULL, *_43 = NULL, *_47 = NULL, *_48 = NULL;
	zval *condition_param = NULL, *fields_param = NULL, select, k, v, kk, vv, _1, _3, _4, _5, *_6, _49, _57, _58, _0$$3, _9$$5, _10$$5, _12$$5, _13$$5, _15$$6, _16$$6, _17$$6, _18$$6, _19$$6, _20$$6, _22$$6, _24$$6, _25$$6, _26$$6, _27$$6, _28$$7, _29$$7, _30$$7, _32$$8, _33$$8, _34$$8, _35$$8, _36$$8, _38$$9, _40$$9, _41$$9, _42$$9, _44$$10, _45$$10, _46$$10, _50$$11, _51$$11, _53$$11, _54$$11, _55$$11, _56$$11;
	zval condition, fields, _52$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_52$$11);
	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&kk);
	ZVAL_UNDEF(&vv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_44$$10);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_50$$11);
	ZVAL_UNDEF(&_51$$11);
	ZVAL_UNDEF(&_53$$11);
	ZVAL_UNDEF(&_54$$11);
	ZVAL_UNDEF(&_55$$11);
	ZVAL_UNDEF(&_56$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &condition_param, &fields_param);

	if (!condition_param) {
		ZEPHIR_INIT_VAR(&condition);
		array_init(&condition);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&condition, condition_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&fields, fields_param);
	}


	if (zephir_fast_count_int(&fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(&fields);
		zephir_create_array(&fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "count(*)");
		zephir_array_fast_append(&fields, &_0$$3);
	}
	zephir_read_static_property_ce(&_3, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_toolkit_sqlbuilder_ce, "select", &_2, 0, &_4);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("_tb"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&select, &_1, "from", NULL, 0, &_5, &fields);
	zephir_check_call_status();
	zephir_is_iterable(&condition, 0, "brisk/Toolkit/Querier.zep", 202);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&condition), _7, _8, _6)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_8 != NULL) { 
			ZVAL_STR_COPY(&k, _8);
		} else {
			ZVAL_LONG(&k, _7);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _6);
		if (Z_TYPE_P(&v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_9$$5);
			zephir_array_keys(&_9$$5, &v TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_10$$5, "current", &_11, 1, &_9$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&kk);
			zephir_fast_strtoupper(&kk, &_10$$5);
			ZEPHIR_CALL_FUNCTION(&vv, "current", &_11, 1, &v);
			zephir_check_call_status();
			zephir_read_property(&_12$$5, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_13$$5, &_12$$5, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 186 TSRMLS_CC);
			_14$$5 = zephir_is_true(&_13$$5);
			if (_14$$5) {
				_14$$5 = !ZEPHIR_IS_STRING(&vv, "");
			}
			if (_14$$5) {
				ZEPHIR_INIT_NVAR(&_15$$6);
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZEPHIR_INIT_NVAR(&_17$$6);
				ZVAL_STRING(&_17$$6, "/^(IS|ISNOT)/i");
				zephir_preg_match(&_16$$6, &_17$$6, &kk, &_15$$6, 0, 0 , 0  TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_18$$6);
				ZEPHIR_INIT_NVAR(&_19$$6);
				ZEPHIR_INIT_NVAR(&_20$$6);
				ZVAL_STRING(&_20$$6, "/^(BETWEEN)/i");
				zephir_preg_match(&_19$$6, &_20$$6, &kk, &_18$$6, 0, 0 , 0  TSRMLS_CC);
				_21$$6 = zephir_is_true(&_19$$6);
				if (_21$$6) {
					zephir_array_fetch_long(&_22$$6, &vv, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 189 TSRMLS_CC);
					_21$$6 = !ZEPHIR_IS_STRING(&_22$$6, "");
				}
				_23$$6 = _21$$6;
				if (_23$$6) {
					zephir_array_fetch_long(&_24$$6, &vv, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 189 TSRMLS_CC);
					_23$$6 = !ZEPHIR_IS_STRING(&_24$$6, "");
				}
				ZEPHIR_INIT_NVAR(&_25$$6);
				ZEPHIR_INIT_NVAR(&_26$$6);
				ZEPHIR_INIT_NVAR(&_27$$6);
				ZVAL_STRING(&_27$$6, "/^(IN|NOTIN)/i");
				zephir_preg_match(&_26$$6, &_27$$6, &kk, &_25$$6, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(&_16$$6)) {
					zephir_read_property(&_28$$7, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_29$$7, &_28$$7, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 188 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_30$$7);
					ZEPHIR_CONCAT_VVV(&_30$$7, &k, &_29$$7, &vv);
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_31, 0, &_30$$7);
					zephir_check_call_status();
				} else if (_23$$6) {
					zephir_read_property(&_32$$8, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_33$$8, &_32$$8, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 190 TSRMLS_CC);
					zephir_array_fetch_long(&_34$$8, &vv, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 190 TSRMLS_CC);
					zephir_array_fetch_long(&_35$$8, &vv, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 190 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_36$$8);
					ZEPHIR_CONCAT_VVVSV(&_36$$8, &k, &_33$$8, &_34$$8, " AND ", &_35$$8);
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_37, 0, &_36$$8);
					zephir_check_call_status();
				} else if (zephir_is_true(&_26$$6)) {
					ZEPHIR_CALL_CE_STATIC(&_38$$9, brisk_toolkit_sqlbuilder_ce, "quote", &_39, 0, &vv);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&vv, &_38$$9);
					zephir_read_property(&_40$$9, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_41$$9, &_40$$9, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 193 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_42$$9);
					ZEPHIR_CONCAT_VVSVS(&_42$$9, &k, &_41$$9, "(", &vv, ")");
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_43, 0, &_42$$9);
					zephir_check_call_status();
				} else {
					zephir_read_property(&_44$$10, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_45$$10, &_44$$10, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 195 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_46$$10);
					ZEPHIR_CONCAT_VVS(&_46$$10, &k, &_45$$10, " ?");
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_47, 0, &_46$$10, &vv);
					zephir_check_call_status();
				}
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, &select, "wherein", &_48, 0, &k, &v);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_49, this_ptr, SL("_expire"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_49) == IS_NULL)) {
		zephir_read_property(&_50$$11, this_ptr, SL("_proxy"), PH_NOISY_CC | PH_READONLY);
		zephir_read_static_property_ce(&_51$$11, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_52$$11);
		zephir_create_array(&_52$$11, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_53$$11, &select, "getrealsql", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_52$$11, SL("sql"), &_53$$11, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_54$$11, this_ptr, SL("_expire"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_55$$11, this_ptr, SL("_cache_name"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_56$$11);
		ZVAL_STRING(&_56$$11, "fetchOne");
		ZEPHIR_RETURN_CALL_METHOD(&_50$$11, "doproxy", NULL, 0, &_51$$11, &_56$$11, &_52$$11, &_54$$11, &_55$$11);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_static_property_ce(&_57, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_58, &select, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_57, "fetchone", NULL, 0, &_58);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Toolkit_Querier, fetchAll) {

	zend_bool _21$$6, _28$$7, _30$$7;
	zend_string *_11, *_15;
	zend_ulong _10, _14;
	zephir_fcall_cache_entry *_2 = NULL, *_12 = NULL, *_18 = NULL, *_38 = NULL, *_44 = NULL, *_46 = NULL, *_50 = NULL, *_54 = NULL, *_55 = NULL;
	zend_long count, offset, ZEPHIR_LAST_CALL_STATUS;
	zval *condition_param = NULL, *order_param = NULL, *count_param = NULL, *offset_param = NULL, *fields_param = NULL, select, k, v, kk, vv, _1, _3, _4, _5, _6, _7, _8, *_9, *_13, _63, _0$$3, _16$$6, _17$$6, _19$$6, _20$$6, _22$$7, _23$$7, _24$$7, _25$$7, _26$$7, _27$$7, _29$$7, _31$$7, _32$$7, _33$$7, _34$$7, _35$$8, _36$$8, _37$$8, _39$$9, _40$$9, _41$$9, _42$$9, _43$$9, _45$$10, _47$$10, _48$$10, _49$$10, _51$$11, _52$$11, _53$$11, _56$$12, _57$$12, _59$$12, _60$$12, _61$$12, _62$$12;
	zval condition, order, fields, _58$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_58$$12);
	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&kk);
	ZVAL_UNDEF(&vv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_63);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_37$$8);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_47$$10);
	ZVAL_UNDEF(&_48$$10);
	ZVAL_UNDEF(&_49$$10);
	ZVAL_UNDEF(&_51$$11);
	ZVAL_UNDEF(&_52$$11);
	ZVAL_UNDEF(&_53$$11);
	ZVAL_UNDEF(&_56$$12);
	ZVAL_UNDEF(&_57$$12);
	ZVAL_UNDEF(&_59$$12);
	ZVAL_UNDEF(&_60$$12);
	ZVAL_UNDEF(&_61$$12);
	ZVAL_UNDEF(&_62$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &condition_param, &order_param, &count_param, &offset_param, &fields_param);

	if (!condition_param) {
		ZEPHIR_INIT_VAR(&condition);
		array_init(&condition);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&condition, condition_param);
	}
	if (!order_param) {
		ZEPHIR_INIT_VAR(&order);
		array_init(&order);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&order, order_param);
	}
	if (!count_param) {
		count = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(count_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'count' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	count = Z_LVAL_P(count_param);
	}
	if (!offset_param) {
		offset = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(offset_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	offset = Z_LVAL_P(offset_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&fields, fields_param);
	}


	if (zephir_fast_count_int(&fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(&fields);
		zephir_create_array(&fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "*");
		zephir_array_fast_append(&fields, &_0$$3);
	}
	zephir_read_static_property_ce(&_3, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_toolkit_sqlbuilder_ce, "select", &_2, 0, &_4);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("_tb"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_1, "from", NULL, 0, &_6, &fields);
	zephir_check_call_status();
	ZVAL_LONG(&_7, count);
	ZVAL_LONG(&_8, offset);
	ZEPHIR_CALL_METHOD(&select, &_5, "limit", NULL, 0, &_7, &_8);
	zephir_check_call_status();
	zephir_is_iterable(&order, 0, "brisk/Toolkit/Querier.zep", 218);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&order), _10, _11, _9)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_11 != NULL) { 
			ZVAL_STR_COPY(&k, _11);
		} else {
			ZVAL_LONG(&k, _10);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _9);
		ZEPHIR_CALL_METHOD(NULL, &select, "order", &_12, 0, &k, &v);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_is_iterable(&condition, 0, "brisk/Toolkit/Querier.zep", 238);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&condition), _14, _15, _13)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_15 != NULL) { 
			ZVAL_STR_COPY(&k, _15);
		} else {
			ZVAL_LONG(&k, _14);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _13);
		if (Z_TYPE_P(&v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_16$$6);
			zephir_array_keys(&_16$$6, &v TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_17$$6, "current", &_18, 1, &_16$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&kk);
			zephir_fast_strtoupper(&kk, &_17$$6);
			ZEPHIR_CALL_FUNCTION(&vv, "current", &_18, 1, &v);
			zephir_check_call_status();
			zephir_read_property(&_19$$6, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_20$$6, &_19$$6, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 222 TSRMLS_CC);
			_21$$6 = zephir_is_true(&_20$$6);
			if (_21$$6) {
				_21$$6 = !ZEPHIR_IS_STRING(&vv, "");
			}
			if (_21$$6) {
				ZEPHIR_INIT_NVAR(&_22$$7);
				ZEPHIR_INIT_NVAR(&_23$$7);
				ZEPHIR_INIT_NVAR(&_24$$7);
				ZVAL_STRING(&_24$$7, "/^(IS|ISNOT)/i");
				zephir_preg_match(&_23$$7, &_24$$7, &kk, &_22$$7, 0, 0 , 0  TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_25$$7);
				ZEPHIR_INIT_NVAR(&_26$$7);
				ZEPHIR_INIT_NVAR(&_27$$7);
				ZVAL_STRING(&_27$$7, "/^(BETWEEN)/i");
				zephir_preg_match(&_26$$7, &_27$$7, &kk, &_25$$7, 0, 0 , 0  TSRMLS_CC);
				_28$$7 = zephir_is_true(&_26$$7);
				if (_28$$7) {
					zephir_array_fetch_long(&_29$$7, &vv, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 225 TSRMLS_CC);
					_28$$7 = !ZEPHIR_IS_STRING(&_29$$7, "");
				}
				_30$$7 = _28$$7;
				if (_30$$7) {
					zephir_array_fetch_long(&_31$$7, &vv, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 225 TSRMLS_CC);
					_30$$7 = !ZEPHIR_IS_STRING(&_31$$7, "");
				}
				ZEPHIR_INIT_NVAR(&_32$$7);
				ZEPHIR_INIT_NVAR(&_33$$7);
				ZEPHIR_INIT_NVAR(&_34$$7);
				ZVAL_STRING(&_34$$7, "/^(IN|NOTIN)/i");
				zephir_preg_match(&_33$$7, &_34$$7, &kk, &_32$$7, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(&_23$$7)) {
					zephir_read_property(&_35$$8, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_36$$8, &_35$$8, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 224 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_37$$8);
					ZEPHIR_CONCAT_VVV(&_37$$8, &k, &_36$$8, &vv);
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_38, 0, &_37$$8);
					zephir_check_call_status();
				} else if (_30$$7) {
					zephir_read_property(&_39$$9, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_40$$9, &_39$$9, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 226 TSRMLS_CC);
					zephir_array_fetch_long(&_41$$9, &vv, 0, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 226 TSRMLS_CC);
					zephir_array_fetch_long(&_42$$9, &vv, 1, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 226 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_43$$9);
					ZEPHIR_CONCAT_VVVSV(&_43$$9, &k, &_40$$9, &_41$$9, " AND ", &_42$$9);
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_44, 0, &_43$$9);
					zephir_check_call_status();
				} else if (zephir_is_true(&_33$$7)) {
					ZEPHIR_CALL_CE_STATIC(&_45$$10, brisk_toolkit_sqlbuilder_ce, "quote", &_46, 0, &vv);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&vv, &_45$$10);
					zephir_read_property(&_47$$10, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_48$$10, &_47$$10, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 229 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_49$$10);
					ZEPHIR_CONCAT_VVSVS(&_49$$10, &k, &_48$$10, "(", &vv, ")");
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_50, 0, &_49$$10);
					zephir_check_call_status();
				} else {
					zephir_read_property(&_51$$11, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_52$$11, &_51$$11, &kk, PH_NOISY | PH_READONLY, "brisk/Toolkit/Querier.zep", 231 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_53$$11);
					ZEPHIR_CONCAT_VVS(&_53$$11, &k, &_52$$11, " ?");
					ZEPHIR_CALL_METHOD(NULL, &select, "where", &_54, 0, &_53$$11, &vv);
					zephir_check_call_status();
				}
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, &select, "wherein", &_55, 0, &k, &v);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_7, this_ptr, SL("_expire"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_7) == IS_NULL)) {
		zephir_read_property(&_56$$12, this_ptr, SL("_proxy"), PH_NOISY_CC | PH_READONLY);
		zephir_read_static_property_ce(&_57$$12, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_58$$12);
		zephir_create_array(&_58$$12, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_59$$12, &select, "getrealsql", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_58$$12, SL("sql"), &_59$$12, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_60$$12, this_ptr, SL("_expire"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_61$$12, this_ptr, SL("_cache_name"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_62$$12);
		ZVAL_STRING(&_62$$12, "fetchAll");
		ZEPHIR_RETURN_CALL_METHOD(&_56$$12, "doproxy", NULL, 0, &_57$$12, &_62$$12, &_58$$12, &_60$$12, &_61$$12);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_static_property_ce(&_8, brisk_toolkit_querier_ce, SL("_conn"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_63, &select, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_8, "fetchall", NULL, 0, &_63);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Brisk_Toolkit_Querier(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_where_mark"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 19, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("="), SL(" = "));
			add_assoc_stringl_ex(&_1$$3, SL("EQ"), SL(" = "));
			add_assoc_stringl_ex(&_1$$3, SL("!="), SL(" != "));
			add_assoc_stringl_ex(&_1$$3, SL("NEQ"), SL(" != "));
			add_assoc_stringl_ex(&_1$$3, SL(">"), SL(">"));
			add_assoc_stringl_ex(&_1$$3, SL("GT"), SL(" > "));
			add_assoc_stringl_ex(&_1$$3, SL(">="), SL(" >= "));
			add_assoc_stringl_ex(&_1$$3, SL("GTE"), SL(" >= "));
			add_assoc_stringl_ex(&_1$$3, SL("<"), SL(" < "));
			add_assoc_stringl_ex(&_1$$3, SL("LT"), SL(" < "));
			add_assoc_stringl_ex(&_1$$3, SL("<="), SL(" <= "));
			add_assoc_stringl_ex(&_1$$3, SL("LTE"), SL(" <= "));
			add_assoc_stringl_ex(&_1$$3, SL("LIKE"), SL(" LIKE "));
			add_assoc_stringl_ex(&_1$$3, SL("NOTLIKE"), SL(" NOT LIKE "));
			add_assoc_stringl_ex(&_1$$3, SL("BETWEEN"), SL(" BETWEEN "));
			add_assoc_stringl_ex(&_1$$3, SL("IN"), SL(" IN "));
			add_assoc_stringl_ex(&_1$$3, SL("NOTIN"), SL(" NOT IN "));
			add_assoc_stringl_ex(&_1$$3, SL("IS"), SL(" IS "));
			add_assoc_stringl_ex(&_1$$3, SL("ISNOT"), SL(" IS NOT "));
			zephir_update_property_zval(this_ptr, SL("_where_mark"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

