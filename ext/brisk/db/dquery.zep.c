
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Db_DQuery) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Db, DQuery, brisk, db_dquery, brisk_db_dquery_method_entry, 0);

	zend_declare_property_null(brisk_db_dquery_ce, SL("_tb"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_db_dquery_ce, SL("_expire"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_db_dquery_ce, SL("_cache_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_db_dquery_ce, SL("_proxy"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(brisk_db_dquery_ce, SL("_conn"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_db_dquery_ce, SL("_where_mark"), ZEND_ACC_PROTECTED TSRMLS_CC);

	brisk_db_dquery_ce->create_object = zephir_init_properties_Brisk_Db_DQuery;
	return SUCCESS;

}

/**
 * Setting database connection objects
 *
 * @param DbFather conn
 * @return null
 */
PHP_METHOD(Brisk_Db_DQuery, setConnection) {

	zval *conn;

	zephir_fetch_params(0, 1, 0, &conn);



	zephir_update_static_property_ce(brisk_db_dquery_ce, SL("_conn"), &conn TSRMLS_CC);

}

/**
 * Get database connection objects
 *
 * @return DbFather
 */
PHP_METHOD(Brisk_Db_DQuery, getConnection) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Construct
 *
 * @return null
 */
PHP_METHOD(Brisk_Db_DQuery, __construct) {

	zval *tb_param = NULL;
	zval *tb = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tb_param);

	if (UNEXPECTED(Z_TYPE_P(tb_param) != IS_STRING && Z_TYPE_P(tb_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tb' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tb_param) == IS_STRING)) {
		zephir_get_strval(tb, tb_param);
	} else {
		ZEPHIR_INIT_VAR(tb);
		ZVAL_EMPTY_STRING(tb);
	}


	zephir_update_property_this(getThis(), SL("_tb"), tb TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the table that you want to operate on
 *
 * @param string tb
 * @return DQuery
 */
PHP_METHOD(Brisk_Db_DQuery, init) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tb_param = NULL;
	zval *tb = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tb_param);

	if (UNEXPECTED(Z_TYPE_P(tb_param) != IS_STRING && Z_TYPE_P(tb_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tb' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tb_param) == IS_STRING)) {
		zephir_get_strval(tb, tb_param);
	} else {
		ZEPHIR_INIT_VAR(tb);
		ZVAL_EMPTY_STRING(tb);
	}


	object_init_ex(return_value, brisk_db_dquery_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 37, tb);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set Cache proxy
 *
 * @param int expire
 * @param CacheFather cache
 * @param string name
 * @return DQuery
 */
PHP_METHOD(Brisk_Db_DQuery, cache) {

	zval *name = NULL;
	zval *expire_param = NULL, *cache, *name_param = NULL, *_0, *_1;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &expire_param, &cache, &name_param);

	if (UNEXPECTED(Z_TYPE_P(expire_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expire' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	expire = Z_LVAL_P(expire_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_STRING(name, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, expire);
	zephir_update_property_this(getThis(), SL("_expire"), _0 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_cache_name"), name TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, brisk_cache_cacheproxy_ce);
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(getThis(), SL("_proxy"), _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_proxy"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setcachedriver", NULL, 0, cache);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Insert new data
 *
 * @param array data
 * @param bool return_id
 * @return bool
 */
PHP_METHOD(Brisk_Db_DQuery, insert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_bool return_id;
	zval *data_param = NULL, *return_id_param = NULL, *insert = NULL, *added = NULL, *_0 = NULL, *_2, *_3 = NULL, *_4, *_5, *_6 = NULL, *_7$$4;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &return_id_param);

	data = data_param;
	if (!return_id_param) {
		return_id = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(return_id_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'return_id' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	return_id = Z_BVAL_P(return_id_param);
	}


	_2 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, _2, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_sql_sqlbuilder_ce, "getinsert", &_1, 38, _3);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_tb"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&insert, _0, "into", NULL, 0, _4, data);
	zephir_check_call_status();
	_5 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_6, insert, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&added, _5, "query", NULL, 0, _6);
	zephir_check_call_status();
	if (!zephir_is_true(added)) {
		RETURN_MM_BOOL(0);
	} else if (return_id) {
		_7$$4 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(_7$$4, "lastinsertid", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Update data with condition
 *
 * @param array data
 * @param array condition
 * @return mixed
 */
PHP_METHOD(Brisk_Db_DQuery, update) {

	zend_bool _13$$4, _20$$5, _22$$5;
	HashTable *_6;
	HashPosition _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL, *_30 = NULL, *_36 = NULL, *_38 = NULL, *_42 = NULL, *_46 = NULL, *_47 = NULL;
	zval *data_param = NULL, *condition_param = NULL, *update = NULL, *k = NULL, *v = NULL, *kk = NULL, *vv = NULL, *_0 = NULL, *_2, *_3 = NULL, *_4, **_7, *_48, *_49 = NULL, *_8$$4 = NULL, *_9$$4 = NULL, *_11$$4, *_12$$4, *_14$$5 = NULL, *_15$$5 = NULL, _16$$5 = zval_used_for_init, *_17$$5 = NULL, *_18$$5 = NULL, _19$$5 = zval_used_for_init, *_21$$5, *_23$$5, *_24$$5 = NULL, *_25$$5 = NULL, _26$$5 = zval_used_for_init, *_27$$6, *_28$$6, *_29$$6 = NULL, *_31$$7, *_32$$7, *_33$$7, *_34$$7, *_35$$7 = NULL, *_37$$8 = NULL, *_39$$8, *_40$$8, *_41$$8 = NULL, *_43$$9, *_44$$9, *_45$$9 = NULL;
	zval *data = NULL, *condition = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &condition_param);

	data = data_param;
	condition = condition_param;


	_2 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, _2, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_sql_sqlbuilder_ce, "getupdate", &_1, 39, _3);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_tb"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&update, _0, "set", NULL, 0, _4, data);
	zephir_check_call_status();
	zephir_is_iterable(condition, &_6, &_5, 0, 0, "brisk/Db/DQuery.zep", 149);
	for (
	  ; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zend_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(k, _6, _5);
		ZEPHIR_GET_HVALUE(v, _7);
		if (Z_TYPE_P(v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_8$$4);
			zephir_array_keys(_8$$4, v TSRMLS_CC);
			ZEPHIR_MAKE_REF(_8$$4);
			ZEPHIR_CALL_FUNCTION(&_9$$4, "current", &_10, 3, _8$$4);
			ZEPHIR_UNREF(_8$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(kk);
			zephir_fast_strtoupper(kk, _9$$4);
			ZEPHIR_MAKE_REF(v);
			ZEPHIR_CALL_FUNCTION(&vv, "current", &_10, 3, v);
			ZEPHIR_UNREF(v);
			zephir_check_call_status();
			_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
			zephir_array_fetch(&_12$$4, _11$$4, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 133 TSRMLS_CC);
			_13$$4 = zephir_is_true(_12$$4);
			if (_13$$4) {
				_13$$4 = !ZEPHIR_IS_STRING(vv, "");
			}
			if (_13$$4) {
				ZEPHIR_INIT_NVAR(_14$$5);
				ZEPHIR_INIT_NVAR(_15$$5);
				ZEPHIR_SINIT_NVAR(_16$$5);
				ZVAL_STRING(&_16$$5, "/^(IS|ISNOT)/i", 0);
				zephir_preg_match(_15$$5, &_16$$5, kk, _14$$5, 0, 0 , 0  TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_17$$5);
				ZEPHIR_INIT_NVAR(_18$$5);
				ZEPHIR_SINIT_NVAR(_19$$5);
				ZVAL_STRING(&_19$$5, "/^(BETWEEN)/i", 0);
				zephir_preg_match(_18$$5, &_19$$5, kk, _17$$5, 0, 0 , 0  TSRMLS_CC);
				_20$$5 = zephir_is_true(_18$$5);
				if (_20$$5) {
					zephir_array_fetch_long(&_21$$5, vv, 0, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 136 TSRMLS_CC);
					_20$$5 = !ZEPHIR_IS_STRING(_21$$5, "");
				}
				_22$$5 = _20$$5;
				if (_22$$5) {
					zephir_array_fetch_long(&_23$$5, vv, 1, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 136 TSRMLS_CC);
					_22$$5 = !ZEPHIR_IS_STRING(_23$$5, "");
				}
				ZEPHIR_INIT_NVAR(_24$$5);
				ZEPHIR_INIT_NVAR(_25$$5);
				ZEPHIR_SINIT_NVAR(_26$$5);
				ZVAL_STRING(&_26$$5, "/^(IN|NOTIN)/i", 0);
				zephir_preg_match(_25$$5, &_26$$5, kk, _24$$5, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(_15$$5)) {
					_27$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_28$$6, _27$$6, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 135 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_29$$6);
					ZEPHIR_CONCAT_VVV(_29$$6, k, _28$$6, vv);
					ZEPHIR_CALL_METHOD(NULL, update, "where", &_30, 0, _29$$6);
					zephir_check_call_status();
				} else if (_22$$5) {
					_31$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_32$$7, _31$$7, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 137 TSRMLS_CC);
					zephir_array_fetch_long(&_33$$7, vv, 0, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 137 TSRMLS_CC);
					zephir_array_fetch_long(&_34$$7, vv, 1, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 137 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_35$$7);
					ZEPHIR_CONCAT_VVVSV(_35$$7, k, _32$$7, _33$$7, " AND ", _34$$7);
					ZEPHIR_CALL_METHOD(NULL, update, "where", &_36, 0, _35$$7);
					zephir_check_call_status();
				} else if (zephir_is_true(_25$$5)) {
					ZEPHIR_CALL_METHOD(&_37$$8, update, "quote", &_38, 0, vv);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(vv, _37$$8);
					_39$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_40$$8, _39$$8, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 140 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_41$$8);
					ZEPHIR_CONCAT_VVSVS(_41$$8, k, _40$$8, "(", vv, ")");
					ZEPHIR_CALL_METHOD(NULL, update, "where", &_42, 0, _41$$8);
					zephir_check_call_status();
				} else {
					_43$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_44$$9, _43$$9, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 142 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_45$$9);
					ZEPHIR_CONCAT_VVS(_45$$9, k, _44$$9, " ?");
					ZEPHIR_CALL_METHOD(NULL, update, "where", &_46, 0, _45$$9, vv);
					zephir_check_call_status();
				}
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, update, "wherein", &_47, 0, k, v);
		zephir_check_call_status();
	}
	_48 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_49, update, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_48, "query", NULL, 0, _49);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Delete data
 *
 * @param array condition
 * @return mixed
 */
PHP_METHOD(Brisk_Db_DQuery, delete) {

	zend_bool _13$$4, _20$$5, _22$$5;
	HashTable *_6;
	HashPosition _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL, *_30 = NULL, *_36 = NULL, *_38 = NULL, *_42 = NULL, *_46 = NULL, *_47 = NULL;
	zval *condition_param = NULL, *delete = NULL, *k = NULL, *v = NULL, *kk = NULL, *vv = NULL, *_0 = NULL, *_2, *_3 = NULL, *_4, **_7, *_48, *_49 = NULL, *_8$$4 = NULL, *_9$$4 = NULL, *_11$$4, *_12$$4, *_14$$5 = NULL, *_15$$5 = NULL, _16$$5 = zval_used_for_init, *_17$$5 = NULL, *_18$$5 = NULL, _19$$5 = zval_used_for_init, *_21$$5, *_23$$5, *_24$$5 = NULL, *_25$$5 = NULL, _26$$5 = zval_used_for_init, *_27$$6, *_28$$6, *_29$$6 = NULL, *_31$$7, *_32$$7, *_33$$7, *_34$$7, *_35$$7 = NULL, *_37$$8 = NULL, *_39$$8, *_40$$8, *_41$$8 = NULL, *_43$$9, *_44$$9, *_45$$9 = NULL;
	zval *condition = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &condition_param);

	condition = condition_param;


	_2 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, _2, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, brisk_sql_sqlbuilder_ce, "getdelete", &_1, 40, _3);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_tb"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&delete, _0, "from", NULL, 0, _4);
	zephir_check_call_status();
	zephir_is_iterable(condition, &_6, &_5, 0, 0, "brisk/Db/DQuery.zep", 182);
	for (
	  ; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zend_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(k, _6, _5);
		ZEPHIR_GET_HVALUE(v, _7);
		if (Z_TYPE_P(v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_8$$4);
			zephir_array_keys(_8$$4, v TSRMLS_CC);
			ZEPHIR_MAKE_REF(_8$$4);
			ZEPHIR_CALL_FUNCTION(&_9$$4, "current", &_10, 3, _8$$4);
			ZEPHIR_UNREF(_8$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(kk);
			zephir_fast_strtoupper(kk, _9$$4);
			ZEPHIR_MAKE_REF(v);
			ZEPHIR_CALL_FUNCTION(&vv, "current", &_10, 3, v);
			ZEPHIR_UNREF(v);
			zephir_check_call_status();
			_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
			zephir_array_fetch(&_12$$4, _11$$4, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 166 TSRMLS_CC);
			_13$$4 = zephir_is_true(_12$$4);
			if (_13$$4) {
				_13$$4 = !ZEPHIR_IS_STRING(vv, "");
			}
			if (_13$$4) {
				ZEPHIR_INIT_NVAR(_14$$5);
				ZEPHIR_INIT_NVAR(_15$$5);
				ZEPHIR_SINIT_NVAR(_16$$5);
				ZVAL_STRING(&_16$$5, "/^(IS|ISNOT)/i", 0);
				zephir_preg_match(_15$$5, &_16$$5, kk, _14$$5, 0, 0 , 0  TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_17$$5);
				ZEPHIR_INIT_NVAR(_18$$5);
				ZEPHIR_SINIT_NVAR(_19$$5);
				ZVAL_STRING(&_19$$5, "/^(BETWEEN)/i", 0);
				zephir_preg_match(_18$$5, &_19$$5, kk, _17$$5, 0, 0 , 0  TSRMLS_CC);
				_20$$5 = zephir_is_true(_18$$5);
				if (_20$$5) {
					zephir_array_fetch_long(&_21$$5, vv, 0, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 169 TSRMLS_CC);
					_20$$5 = !ZEPHIR_IS_STRING(_21$$5, "");
				}
				_22$$5 = _20$$5;
				if (_22$$5) {
					zephir_array_fetch_long(&_23$$5, vv, 1, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 169 TSRMLS_CC);
					_22$$5 = !ZEPHIR_IS_STRING(_23$$5, "");
				}
				ZEPHIR_INIT_NVAR(_24$$5);
				ZEPHIR_INIT_NVAR(_25$$5);
				ZEPHIR_SINIT_NVAR(_26$$5);
				ZVAL_STRING(&_26$$5, "/^(IN|NOTIN)/i", 0);
				zephir_preg_match(_25$$5, &_26$$5, kk, _24$$5, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(_15$$5)) {
					_27$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_28$$6, _27$$6, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 168 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_29$$6);
					ZEPHIR_CONCAT_VVV(_29$$6, k, _28$$6, vv);
					ZEPHIR_CALL_METHOD(NULL, delete, "where", &_30, 0, _29$$6);
					zephir_check_call_status();
				} else if (_22$$5) {
					_31$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_32$$7, _31$$7, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 170 TSRMLS_CC);
					zephir_array_fetch_long(&_33$$7, vv, 0, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 170 TSRMLS_CC);
					zephir_array_fetch_long(&_34$$7, vv, 1, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 170 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_35$$7);
					ZEPHIR_CONCAT_VVVSV(_35$$7, k, _32$$7, _33$$7, " AND ", _34$$7);
					ZEPHIR_CALL_METHOD(NULL, delete, "where", &_36, 0, _35$$7);
					zephir_check_call_status();
				} else if (zephir_is_true(_25$$5)) {
					ZEPHIR_CALL_METHOD(&_37$$8, delete, "quote", &_38, 0, vv);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(vv, _37$$8);
					_39$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_40$$8, _39$$8, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 173 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_41$$8);
					ZEPHIR_CONCAT_VVSVS(_41$$8, k, _40$$8, "(", vv, ")");
					ZEPHIR_CALL_METHOD(NULL, delete, "where", &_42, 0, _41$$8);
					zephir_check_call_status();
				} else {
					_43$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_44$$9, _43$$9, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 175 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_45$$9);
					ZEPHIR_CONCAT_VVS(_45$$9, k, _44$$9, " ?");
					ZEPHIR_CALL_METHOD(NULL, delete, "where", &_46, 0, _45$$9, vv);
					zephir_check_call_status();
				}
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, delete, "wherein", &_47, 0, k, v);
		zephir_check_call_status();
	}
	_48 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_49, delete, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_48, "query", NULL, 0, _49);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get single-row data
 *
 * @param array condition
 * @param array fields
 * @return array
 */
PHP_METHOD(Brisk_Db_DQuery, fetchRow) {

	zend_bool _14$$5, _21$$6, _23$$6;
	HashTable *_7;
	HashPosition _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_11 = NULL, *_31 = NULL, *_37 = NULL, *_39 = NULL, *_43 = NULL, *_47 = NULL, *_48 = NULL;
	zval *condition_param = NULL, *fields_param = NULL, *select = NULL, *k = NULL, *v = NULL, *kk = NULL, *vv = NULL, *_1 = NULL, *_3, *_4 = NULL, *_5, **_8, *_49, *_57, *_58 = NULL, *_0$$3, *_9$$5 = NULL, *_10$$5 = NULL, *_12$$5, *_13$$5, *_15$$6 = NULL, *_16$$6 = NULL, _17$$6 = zval_used_for_init, *_18$$6 = NULL, *_19$$6 = NULL, _20$$6 = zval_used_for_init, *_22$$6, *_24$$6, *_25$$6 = NULL, *_26$$6 = NULL, _27$$6 = zval_used_for_init, *_28$$7, *_29$$7, *_30$$7 = NULL, *_32$$8, *_33$$8, *_34$$8, *_35$$8, *_36$$8 = NULL, *_38$$9 = NULL, *_40$$9, *_41$$9, *_42$$9 = NULL, *_44$$10, *_45$$10, *_46$$10 = NULL, *_50$$11, *_51$$11, *_53$$11 = NULL, *_54$$11, *_55$$11, *_56$$11;
	zval *condition = NULL, *fields = NULL, *_52$$11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &condition_param, &fields_param);

	condition = condition_param;
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
	fields = fields_param;
	}


	if (zephir_fast_count_int(fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(fields);
		zephir_create_array(fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "*", 1);
		zephir_array_fast_append(fields, _0$$3);
	}
	_3 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_sql_sqlbuilder_ce, "getselect", &_2, 41, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_tb"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&select, _1, "from", NULL, 0, _5, fields);
	zephir_check_call_status();
	zephir_is_iterable(condition, &_7, &_6, 0, 0, "brisk/Db/DQuery.zep", 219);
	for (
	  ; zend_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zend_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HMKEY(k, _7, _6);
		ZEPHIR_GET_HVALUE(v, _8);
		if (Z_TYPE_P(v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_9$$5);
			zephir_array_keys(_9$$5, v TSRMLS_CC);
			ZEPHIR_MAKE_REF(_9$$5);
			ZEPHIR_CALL_FUNCTION(&_10$$5, "current", &_11, 3, _9$$5);
			ZEPHIR_UNREF(_9$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(kk);
			zephir_fast_strtoupper(kk, _10$$5);
			ZEPHIR_MAKE_REF(v);
			ZEPHIR_CALL_FUNCTION(&vv, "current", &_11, 3, v);
			ZEPHIR_UNREF(v);
			zephir_check_call_status();
			_12$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
			zephir_array_fetch(&_13$$5, _12$$5, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 203 TSRMLS_CC);
			_14$$5 = zephir_is_true(_13$$5);
			if (_14$$5) {
				_14$$5 = !ZEPHIR_IS_STRING(vv, "");
			}
			if (_14$$5) {
				ZEPHIR_INIT_NVAR(_15$$6);
				ZEPHIR_INIT_NVAR(_16$$6);
				ZEPHIR_SINIT_NVAR(_17$$6);
				ZVAL_STRING(&_17$$6, "/^(IS|ISNOT)/i", 0);
				zephir_preg_match(_16$$6, &_17$$6, kk, _15$$6, 0, 0 , 0  TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_18$$6);
				ZEPHIR_INIT_NVAR(_19$$6);
				ZEPHIR_SINIT_NVAR(_20$$6);
				ZVAL_STRING(&_20$$6, "/^(BETWEEN)/i", 0);
				zephir_preg_match(_19$$6, &_20$$6, kk, _18$$6, 0, 0 , 0  TSRMLS_CC);
				_21$$6 = zephir_is_true(_19$$6);
				if (_21$$6) {
					zephir_array_fetch_long(&_22$$6, vv, 0, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 206 TSRMLS_CC);
					_21$$6 = !ZEPHIR_IS_STRING(_22$$6, "");
				}
				_23$$6 = _21$$6;
				if (_23$$6) {
					zephir_array_fetch_long(&_24$$6, vv, 1, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 206 TSRMLS_CC);
					_23$$6 = !ZEPHIR_IS_STRING(_24$$6, "");
				}
				ZEPHIR_INIT_NVAR(_25$$6);
				ZEPHIR_INIT_NVAR(_26$$6);
				ZEPHIR_SINIT_NVAR(_27$$6);
				ZVAL_STRING(&_27$$6, "/^(IN|NOTIN)/i", 0);
				zephir_preg_match(_26$$6, &_27$$6, kk, _25$$6, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(_16$$6)) {
					_28$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_29$$7, _28$$7, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 205 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_30$$7);
					ZEPHIR_CONCAT_VVV(_30$$7, k, _29$$7, vv);
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_31, 0, _30$$7);
					zephir_check_call_status();
				} else if (_23$$6) {
					_32$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_33$$8, _32$$8, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 207 TSRMLS_CC);
					zephir_array_fetch_long(&_34$$8, vv, 0, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 207 TSRMLS_CC);
					zephir_array_fetch_long(&_35$$8, vv, 1, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 207 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_36$$8);
					ZEPHIR_CONCAT_VVVSV(_36$$8, k, _33$$8, _34$$8, " AND ", _35$$8);
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_37, 0, _36$$8);
					zephir_check_call_status();
				} else if (zephir_is_true(_26$$6)) {
					ZEPHIR_CALL_METHOD(&_38$$9, select, "quote", &_39, 0, vv);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(vv, _38$$9);
					_40$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_41$$9, _40$$9, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 210 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_42$$9);
					ZEPHIR_CONCAT_VVSVS(_42$$9, k, _41$$9, "(", vv, ")");
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_43, 0, _42$$9);
					zephir_check_call_status();
				} else {
					_44$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_45$$10, _44$$10, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 212 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_46$$10);
					ZEPHIR_CONCAT_VVS(_46$$10, k, _45$$10, " ?");
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_47, 0, _46$$10, vv);
					zephir_check_call_status();
				}
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, select, "wherein", &_48, 0, k, v);
		zephir_check_call_status();
	}
	_49 = zephir_fetch_nproperty_this(this_ptr, SL("_expire"), PH_NOISY_CC);
	if (!(Z_TYPE_P(_49) == IS_NULL)) {
		_50$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_proxy"), PH_NOISY_CC);
		_51$$11 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_52$$11);
		zephir_create_array(_52$$11, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_53$$11, select, "getrealsql", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_52$$11, SL("sql"), &_53$$11, PH_COPY | PH_SEPARATE);
		_54$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_expire"), PH_NOISY_CC);
		_55$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_56$$11);
		ZVAL_STRING(_56$$11, "fetchRow", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_RETURN_CALL_METHOD(_50$$11, "doproxy", NULL, 0, _51$$11, _56$$11, _52$$11, _54$$11, _55$$11);
		zephir_check_temp_parameter(_56$$11);
		zephir_check_call_status();
		RETURN_MM();
	}
	_57 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_58, select, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_57, "fetchrow", NULL, 0, _58);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get single-row and single-colume data
 *
 * @param array condition
 * @param array fields
 * @return array
 */
PHP_METHOD(Brisk_Db_DQuery, fetchOne) {

	zend_bool _14$$5, _21$$6, _23$$6;
	HashTable *_7;
	HashPosition _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_11 = NULL, *_31 = NULL, *_37 = NULL, *_39 = NULL, *_43 = NULL, *_47 = NULL, *_48 = NULL;
	zval *condition_param = NULL, *fields_param = NULL, *select = NULL, *k = NULL, *v = NULL, *kk = NULL, *vv = NULL, *_1 = NULL, *_3, *_4 = NULL, *_5, **_8, *_49, *_57, *_58 = NULL, *_0$$3, *_9$$5 = NULL, *_10$$5 = NULL, *_12$$5, *_13$$5, *_15$$6 = NULL, *_16$$6 = NULL, _17$$6 = zval_used_for_init, *_18$$6 = NULL, *_19$$6 = NULL, _20$$6 = zval_used_for_init, *_22$$6, *_24$$6, *_25$$6 = NULL, *_26$$6 = NULL, _27$$6 = zval_used_for_init, *_28$$7, *_29$$7, *_30$$7 = NULL, *_32$$8, *_33$$8, *_34$$8, *_35$$8, *_36$$8 = NULL, *_38$$9 = NULL, *_40$$9, *_41$$9, *_42$$9 = NULL, *_44$$10, *_45$$10, *_46$$10 = NULL, *_50$$11, *_51$$11, *_53$$11 = NULL, *_54$$11, *_55$$11, *_56$$11;
	zval *condition = NULL, *fields = NULL, *_52$$11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &condition_param, &fields_param);

	if (!condition_param) {
		ZEPHIR_INIT_VAR(condition);
		array_init(condition);
	} else {
	condition = condition_param;
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
	fields = fields_param;
	}


	if (zephir_fast_count_int(fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(fields);
		zephir_create_array(fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "count(*)", 1);
		zephir_array_fast_append(fields, _0$$3);
	}
	_3 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_sql_sqlbuilder_ce, "getselect", &_2, 41, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_tb"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&select, _1, "from", NULL, 0, _5, fields);
	zephir_check_call_status();
	zephir_is_iterable(condition, &_7, &_6, 0, 0, "brisk/Db/DQuery.zep", 259);
	for (
	  ; zend_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zend_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HMKEY(k, _7, _6);
		ZEPHIR_GET_HVALUE(v, _8);
		if (Z_TYPE_P(v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_9$$5);
			zephir_array_keys(_9$$5, v TSRMLS_CC);
			ZEPHIR_MAKE_REF(_9$$5);
			ZEPHIR_CALL_FUNCTION(&_10$$5, "current", &_11, 3, _9$$5);
			ZEPHIR_UNREF(_9$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(kk);
			zephir_fast_strtoupper(kk, _10$$5);
			ZEPHIR_MAKE_REF(v);
			ZEPHIR_CALL_FUNCTION(&vv, "current", &_11, 3, v);
			ZEPHIR_UNREF(v);
			zephir_check_call_status();
			_12$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
			zephir_array_fetch(&_13$$5, _12$$5, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 243 TSRMLS_CC);
			_14$$5 = zephir_is_true(_13$$5);
			if (_14$$5) {
				_14$$5 = !ZEPHIR_IS_STRING(vv, "");
			}
			if (_14$$5) {
				ZEPHIR_INIT_NVAR(_15$$6);
				ZEPHIR_INIT_NVAR(_16$$6);
				ZEPHIR_SINIT_NVAR(_17$$6);
				ZVAL_STRING(&_17$$6, "/^(IS|ISNOT)/i", 0);
				zephir_preg_match(_16$$6, &_17$$6, kk, _15$$6, 0, 0 , 0  TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_18$$6);
				ZEPHIR_INIT_NVAR(_19$$6);
				ZEPHIR_SINIT_NVAR(_20$$6);
				ZVAL_STRING(&_20$$6, "/^(BETWEEN)/i", 0);
				zephir_preg_match(_19$$6, &_20$$6, kk, _18$$6, 0, 0 , 0  TSRMLS_CC);
				_21$$6 = zephir_is_true(_19$$6);
				if (_21$$6) {
					zephir_array_fetch_long(&_22$$6, vv, 0, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 246 TSRMLS_CC);
					_21$$6 = !ZEPHIR_IS_STRING(_22$$6, "");
				}
				_23$$6 = _21$$6;
				if (_23$$6) {
					zephir_array_fetch_long(&_24$$6, vv, 1, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 246 TSRMLS_CC);
					_23$$6 = !ZEPHIR_IS_STRING(_24$$6, "");
				}
				ZEPHIR_INIT_NVAR(_25$$6);
				ZEPHIR_INIT_NVAR(_26$$6);
				ZEPHIR_SINIT_NVAR(_27$$6);
				ZVAL_STRING(&_27$$6, "/^(IN|NOTIN)/i", 0);
				zephir_preg_match(_26$$6, &_27$$6, kk, _25$$6, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(_16$$6)) {
					_28$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_29$$7, _28$$7, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 245 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_30$$7);
					ZEPHIR_CONCAT_VVV(_30$$7, k, _29$$7, vv);
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_31, 0, _30$$7);
					zephir_check_call_status();
				} else if (_23$$6) {
					_32$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_33$$8, _32$$8, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 247 TSRMLS_CC);
					zephir_array_fetch_long(&_34$$8, vv, 0, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 247 TSRMLS_CC);
					zephir_array_fetch_long(&_35$$8, vv, 1, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 247 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_36$$8);
					ZEPHIR_CONCAT_VVVSV(_36$$8, k, _33$$8, _34$$8, " AND ", _35$$8);
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_37, 0, _36$$8);
					zephir_check_call_status();
				} else if (zephir_is_true(_26$$6)) {
					ZEPHIR_CALL_METHOD(&_38$$9, select, "quote", &_39, 0, vv);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(vv, _38$$9);
					_40$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_41$$9, _40$$9, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 250 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_42$$9);
					ZEPHIR_CONCAT_VVSVS(_42$$9, k, _41$$9, "(", vv, ")");
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_43, 0, _42$$9);
					zephir_check_call_status();
				} else {
					_44$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_45$$10, _44$$10, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 252 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_46$$10);
					ZEPHIR_CONCAT_VVS(_46$$10, k, _45$$10, " ?");
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_47, 0, _46$$10, vv);
					zephir_check_call_status();
				}
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, select, "wherein", &_48, 0, k, v);
		zephir_check_call_status();
	}
	_49 = zephir_fetch_nproperty_this(this_ptr, SL("_expire"), PH_NOISY_CC);
	if (!(Z_TYPE_P(_49) == IS_NULL)) {
		_50$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_proxy"), PH_NOISY_CC);
		_51$$11 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_52$$11);
		zephir_create_array(_52$$11, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_53$$11, select, "getrealsql", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_52$$11, SL("sql"), &_53$$11, PH_COPY | PH_SEPARATE);
		_54$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_expire"), PH_NOISY_CC);
		_55$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_56$$11);
		ZVAL_STRING(_56$$11, "fetchOne", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_RETURN_CALL_METHOD(_50$$11, "doproxy", NULL, 0, _51$$11, _56$$11, _52$$11, _54$$11, _55$$11);
		zephir_check_temp_parameter(_56$$11);
		zephir_check_call_status();
		RETURN_MM();
	}
	_57 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_58, select, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_57, "fetchone", NULL, 0, _58);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get multiple rows of data
 *
 * @param array condition
 * @param array order
 * @param int count
 * @param int offset
 * @param array fields
 * @return array
 */
PHP_METHOD(Brisk_Db_DQuery, fetchAll) {

	zend_bool _21$$6, _28$$7, _30$$7;
	HashTable *_10, *_14;
	HashPosition _9, _13;
	zephir_fcall_cache_entry *_2 = NULL, *_12 = NULL, *_18 = NULL, *_38 = NULL, *_44 = NULL, *_46 = NULL, *_50 = NULL, *_54 = NULL, *_55 = NULL;
	zend_long count, offset, ZEPHIR_LAST_CALL_STATUS;
	zval *condition_param = NULL, *order_param = NULL, *count_param = NULL, *offset_param = NULL, *fields_param = NULL, *select = NULL, *k = NULL, *v = NULL, *kk = NULL, *vv = NULL, *_1 = NULL, *_3, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8, **_11, **_15, *_56, *_64, *_65 = NULL, *_0$$3, *_16$$6 = NULL, *_17$$6 = NULL, *_19$$6, *_20$$6, *_22$$7 = NULL, *_23$$7 = NULL, _24$$7 = zval_used_for_init, *_25$$7 = NULL, *_26$$7 = NULL, _27$$7 = zval_used_for_init, *_29$$7, *_31$$7, *_32$$7 = NULL, *_33$$7 = NULL, _34$$7 = zval_used_for_init, *_35$$8, *_36$$8, *_37$$8 = NULL, *_39$$9, *_40$$9, *_41$$9, *_42$$9, *_43$$9 = NULL, *_45$$10 = NULL, *_47$$10, *_48$$10, *_49$$10 = NULL, *_51$$11, *_52$$11, *_53$$11 = NULL, *_57$$12, *_58$$12, *_60$$12 = NULL, *_61$$12, *_62$$12, *_63$$12;
	zval *condition = NULL, *order = NULL, *fields = NULL, *_59$$12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 5, &condition_param, &order_param, &count_param, &offset_param, &fields_param);

	if (!condition_param) {
		ZEPHIR_INIT_VAR(condition);
		array_init(condition);
	} else {
	condition = condition_param;
	}
	if (!order_param) {
		ZEPHIR_INIT_VAR(order);
		array_init(order);
	} else {
	order = order_param;
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
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
	fields = fields_param;
	}


	if (zephir_fast_count_int(fields TSRMLS_CC) < 1) {
		ZEPHIR_INIT_NVAR(fields);
		zephir_create_array(fields, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "*", 1);
		zephir_array_fast_append(fields, _0$$3);
	}
	_3 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "getdrivername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, brisk_sql_sqlbuilder_ce, "getselect", &_2, 41, _4);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_tb"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_5, _1, "from", NULL, 0, _6, fields);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, count);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, offset);
	ZEPHIR_CALL_METHOD(&select, _5, "limit", NULL, 0, _7, _8);
	zephir_check_call_status();
	zephir_is_iterable(order, &_10, &_9, 0, 0, "brisk/Db/DQuery.zep", 285);
	for (
	  ; zend_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zend_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(k, _10, _9);
		ZEPHIR_GET_HVALUE(v, _11);
		ZEPHIR_CALL_METHOD(NULL, select, "order", &_12, 0, k, v);
		zephir_check_call_status();
	}
	zephir_is_iterable(condition, &_14, &_13, 0, 0, "brisk/Db/DQuery.zep", 305);
	for (
	  ; zend_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
	  ; zend_hash_move_forward_ex(_14, &_13)
	) {
		ZEPHIR_GET_HMKEY(k, _14, _13);
		ZEPHIR_GET_HVALUE(v, _15);
		if (Z_TYPE_P(v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_16$$6);
			zephir_array_keys(_16$$6, v TSRMLS_CC);
			ZEPHIR_MAKE_REF(_16$$6);
			ZEPHIR_CALL_FUNCTION(&_17$$6, "current", &_18, 3, _16$$6);
			ZEPHIR_UNREF(_16$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(kk);
			zephir_fast_strtoupper(kk, _17$$6);
			ZEPHIR_MAKE_REF(v);
			ZEPHIR_CALL_FUNCTION(&vv, "current", &_18, 3, v);
			ZEPHIR_UNREF(v);
			zephir_check_call_status();
			_19$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
			zephir_array_fetch(&_20$$6, _19$$6, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 289 TSRMLS_CC);
			_21$$6 = zephir_is_true(_20$$6);
			if (_21$$6) {
				_21$$6 = !ZEPHIR_IS_STRING(vv, "");
			}
			if (_21$$6) {
				ZEPHIR_INIT_NVAR(_22$$7);
				ZEPHIR_INIT_NVAR(_23$$7);
				ZEPHIR_SINIT_NVAR(_24$$7);
				ZVAL_STRING(&_24$$7, "/^(IS|ISNOT)/i", 0);
				zephir_preg_match(_23$$7, &_24$$7, kk, _22$$7, 0, 0 , 0  TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_25$$7);
				ZEPHIR_INIT_NVAR(_26$$7);
				ZEPHIR_SINIT_NVAR(_27$$7);
				ZVAL_STRING(&_27$$7, "/^(BETWEEN)/i", 0);
				zephir_preg_match(_26$$7, &_27$$7, kk, _25$$7, 0, 0 , 0  TSRMLS_CC);
				_28$$7 = zephir_is_true(_26$$7);
				if (_28$$7) {
					zephir_array_fetch_long(&_29$$7, vv, 0, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 292 TSRMLS_CC);
					_28$$7 = !ZEPHIR_IS_STRING(_29$$7, "");
				}
				_30$$7 = _28$$7;
				if (_30$$7) {
					zephir_array_fetch_long(&_31$$7, vv, 1, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 292 TSRMLS_CC);
					_30$$7 = !ZEPHIR_IS_STRING(_31$$7, "");
				}
				ZEPHIR_INIT_NVAR(_32$$7);
				ZEPHIR_INIT_NVAR(_33$$7);
				ZEPHIR_SINIT_NVAR(_34$$7);
				ZVAL_STRING(&_34$$7, "/^(IN|NOTIN)/i", 0);
				zephir_preg_match(_33$$7, &_34$$7, kk, _32$$7, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(_23$$7)) {
					_35$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_36$$8, _35$$8, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 291 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_37$$8);
					ZEPHIR_CONCAT_VVV(_37$$8, k, _36$$8, vv);
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_38, 0, _37$$8);
					zephir_check_call_status();
				} else if (_30$$7) {
					_39$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_40$$9, _39$$9, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 293 TSRMLS_CC);
					zephir_array_fetch_long(&_41$$9, vv, 0, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 293 TSRMLS_CC);
					zephir_array_fetch_long(&_42$$9, vv, 1, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 293 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_43$$9);
					ZEPHIR_CONCAT_VVVSV(_43$$9, k, _40$$9, _41$$9, " AND ", _42$$9);
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_44, 0, _43$$9);
					zephir_check_call_status();
				} else if (zephir_is_true(_33$$7)) {
					ZEPHIR_CALL_METHOD(&_45$$10, select, "quote", &_46, 0, vv);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(vv, _45$$10);
					_47$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_48$$10, _47$$10, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 296 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_49$$10);
					ZEPHIR_CONCAT_VVSVS(_49$$10, k, _48$$10, "(", vv, ")");
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_50, 0, _49$$10);
					zephir_check_call_status();
				} else {
					_51$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
					zephir_array_fetch(&_52$$11, _51$$11, kk, PH_NOISY | PH_READONLY, "brisk/Db/DQuery.zep", 298 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_53$$11);
					ZEPHIR_CONCAT_VVS(_53$$11, k, _52$$11, " ?");
					ZEPHIR_CALL_METHOD(NULL, select, "where", &_54, 0, _53$$11, vv);
					zephir_check_call_status();
				}
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, select, "wherein", &_55, 0, k, v);
		zephir_check_call_status();
	}
	_56 = zephir_fetch_nproperty_this(this_ptr, SL("_expire"), PH_NOISY_CC);
	if (!(Z_TYPE_P(_56) == IS_NULL)) {
		_57$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_proxy"), PH_NOISY_CC);
		_58$$12 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_59$$12);
		zephir_create_array(_59$$12, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_60$$12, select, "getrealsql", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_59$$12, SL("sql"), &_60$$12, PH_COPY | PH_SEPARATE);
		_61$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_expire"), PH_NOISY_CC);
		_62$$12 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_63$$12);
		ZVAL_STRING(_63$$12, "fetchAll", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_RETURN_CALL_METHOD(_57$$12, "doproxy", NULL, 0, _58$$12, _63$$12, _59$$12, _61$$12, _62$$12);
		zephir_check_temp_parameter(_63$$12);
		zephir_check_call_status();
		RETURN_MM();
	}
	_64 = zephir_fetch_static_property_ce(brisk_db_dquery_ce, SL("_conn") TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_65, select, "getrealsql", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_64, "fetchall", NULL, 0, _65);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object_value zephir_init_properties_Brisk_Db_DQuery(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_where_mark"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 19, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1$$3, SS("="), SL(" = "), 1);
			add_assoc_stringl_ex(_1$$3, SS("EQ"), SL(" = "), 1);
			add_assoc_stringl_ex(_1$$3, SS("!="), SL(" != "), 1);
			add_assoc_stringl_ex(_1$$3, SS("NEQ"), SL(" != "), 1);
			add_assoc_stringl_ex(_1$$3, SS(">"), SL(">"), 1);
			add_assoc_stringl_ex(_1$$3, SS("GT"), SL(" > "), 1);
			add_assoc_stringl_ex(_1$$3, SS(">="), SL(" >= "), 1);
			add_assoc_stringl_ex(_1$$3, SS("GTE"), SL(" >= "), 1);
			add_assoc_stringl_ex(_1$$3, SS("<"), SL(" < "), 1);
			add_assoc_stringl_ex(_1$$3, SS("LT"), SL(" < "), 1);
			add_assoc_stringl_ex(_1$$3, SS("<="), SL(" <= "), 1);
			add_assoc_stringl_ex(_1$$3, SS("LTE"), SL(" <= "), 1);
			add_assoc_stringl_ex(_1$$3, SS("LIKE"), SL(" LIKE "), 1);
			add_assoc_stringl_ex(_1$$3, SS("NOTLIKE"), SL(" NOT LIKE "), 1);
			add_assoc_stringl_ex(_1$$3, SS("BETWEEN"), SL(" BETWEEN "), 1);
			add_assoc_stringl_ex(_1$$3, SS("IN"), SL(" IN "), 1);
			add_assoc_stringl_ex(_1$$3, SS("NOTIN"), SL(" NOT IN "), 1);
			add_assoc_stringl_ex(_1$$3, SS("IS"), SL(" IS "), 1);
			add_assoc_stringl_ex(_1$$3, SS("ISNOT"), SL(" IS NOT "), 1);
			zephir_update_property_this(getThis(), SL("_where_mark"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

