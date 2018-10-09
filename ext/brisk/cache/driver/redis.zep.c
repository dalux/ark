
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Cache_Driver_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Cache\\Driver, Redis, brisk, cache_driver_redis, brisk_cache_cachefather_ce, brisk_cache_driver_redis_method_entry, 0);

	zend_declare_property_null(brisk_cache_driver_redis_ce, SL("_container"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造器
 *
 * @param string save_path
 * @param array setting
 * @return null
 */
PHP_METHOD(Brisk_Cache_Driver_Redis, __construct) {

	zephir_fcall_cache_entry *_4 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *setting = NULL, *_5$$3, *_16$$7;
	zval *save_path, *setting_param = NULL, _0, *_1 = NULL, *_12, *_13 = NULL, *_2$$3, *_3$$3 = NULL, *_6$$3 = NULL, *host$$4 = NULL, *port$$4 = NULL, *server$$4 = NULL, *timeout$$4 = NULL, *_7$$4, *_8$$4, *_9$$6, *_10$$6, *_14$$7, *_15$$7 = NULL, *_17$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &save_path, &setting_param);

	if (!setting_param) {
		ZEPHIR_INIT_VAR(setting);
		array_init(setting);
	} else {
	setting = setting_param;
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "redis", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 34, &_0);
	zephir_check_call_status();
	if (!zephir_is_true(_1)) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_create_array(_5$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "php_redis", 1);
		zephir_array_fast_append(_5$$3, _6$$3);
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_STRING(_6$$3, "cache.extension_load_failed", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_3$$3, brisk_kernel_language_ce, "get", &_4, 12, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 7, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "brisk/Cache/Driver/Redis.zep", 22 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(server$$4);
		zephir_fast_explode_str(server$$4, SL(":"), save_path, LONG_MAX TSRMLS_CC);
		ZEPHIR_OBS_VAR(host$$4);
		zephir_array_fetch_long(&host$$4, server$$4, 0, PH_NOISY, "brisk/Cache/Driver/Redis.zep", 27 TSRMLS_CC);
		ZEPHIR_OBS_VAR(port$$4);
		zephir_array_fetch_long(&port$$4, server$$4, 1, PH_NOISY, "brisk/Cache/Driver/Redis.zep", 28 TSRMLS_CC);
		ZEPHIR_INIT_VAR(timeout$$4);
		ZVAL_LONG(timeout$$4, 5);
		if (zephir_array_isset_string(setting, SS("connect_timeout"))) {
			ZEPHIR_OBS_NVAR(timeout$$4);
			zephir_array_fetch_string(&timeout$$4, setting, SL("connect_timeout"), PH_NOISY, "brisk/Cache/Driver/Redis.zep", 31 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(_7$$4);
		object_init_ex(_7$$4, zephir_get_internal_ce(SS("redis") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _7$$4, "__construct", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_update_property_this(getThis(), SL("_container"), _7$$4 TSRMLS_CC);
		_8$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _8$$4, "connect", NULL, 0, host$$4, port$$4, timeout$$4);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_array_isset_string(setting, SS("password"))) {
			_9$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
			zephir_array_fetch_string(&_10$$6, setting, SL("password"), PH_NOISY | PH_READONLY, "brisk/Cache/Driver/Redis.zep", 36 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, _9$$6, "auth", NULL, 0, _10$$6);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_CALL_PARENT(NULL, brisk_cache_driver_redis_ce, getThis(), "__construct", &_11, 30, setting);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(_12);
		ZEPHIR_CPY_WRT(_12, EG(exception));
		ZEPHIR_INIT_VAR(_13);
		if (zephir_instance_of_ev(_12, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(_13, _12);
			ZEPHIR_INIT_VAR(_14$$7);
			object_init_ex(_14$$7, brisk_exception_runtimeexception_ce);
			ZEPHIR_INIT_VAR(_16$$7);
			zephir_create_array(_16$$7, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_17$$7);
			ZVAL_STRING(_17$$7, "Redis", 1);
			zephir_array_fast_append(_16$$7, _17$$7);
			ZEPHIR_INIT_NVAR(_17$$7);
			ZVAL_STRING(_17$$7, "cache.cacher_create_failed", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_CE_STATIC(&_15$$7, brisk_kernel_language_ce, "get", &_4, 12, _17$$7, _16$$7);
			zephir_check_temp_parameter(_17$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _14$$7, "__construct", NULL, 7, _15$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_14$$7, "brisk/Cache/Driver/Redis.zep", 40 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 缓存器设值
 *
 * @param string name
 * @param mixed value
 * @param null expire
 * @return bool
 */
PHP_METHOD(Brisk_Cache_Driver_Redis, set) {

	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, *expire_param = NULL, *path = NULL, *expire_time = NULL, *_0, *_1 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &value, &expire_param);

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
	if (!expire_param) {
		expire = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(expire_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expire' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	expire = Z_LVAL_P(expire_param);
	}


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getcachepath", NULL, 0, name);
	zephir_check_call_status();
	if (expire <= 0) {
		ZEPHIR_OBS_VAR(expire_time);
		zephir_read_property_this(&expire_time, this_ptr, SL("_expire_time"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_NVAR(expire_time);
		ZVAL_LONG(expire_time, expire);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "serialize", NULL, 25, value);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "set", NULL, 0, path, _1, expire_time);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 缓存器取值
 *
 * @param string name
 * @return bool
 */
PHP_METHOD(Brisk_Cache_Driver_Redis, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *data = NULL, *path = NULL, *_0, *_1$$3, *_2$$4 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	ZEPHIR_INIT_VAR(data);
	ZVAL_NULL(data);
	ZEPHIR_CALL_METHOD(&path, this_ptr, "getcachepath", NULL, 0, name);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_caching"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&data, _1$$3, "get", NULL, 0, path);
		zephir_check_call_status();
		if (zephir_is_true(data)) {
			ZEPHIR_CALL_FUNCTION(&_2$$4, "unserialize", NULL, 32, data);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(data, _2$$4);
		}
	}
	RETURN_CCTOR(data);

}

/**
 * 删除缓存数据
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Cache_Driver_Redis, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *path = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getcachepath", NULL, 0, name);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_container"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "delete", NULL, 0, path);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * 格式化变量名
 *
 * @param string name
 * @return string
 */
PHP_METHOD(Brisk_Cache_Driver_Redis, getCachePath) {

	zval *_7, *_4$$4;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *path = NULL, *_0, *_3, *part = NULL, *result = NULL, *_6, *_1$$3, *_2$$3, *_5$$4, *_8$$5, *_9$$5 = NULL, *_11$$5;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	ZEPHIR_INIT_VAR(path);
	ZVAL_STRING(path, "", 1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
	if (!(Z_TYPE_P(_0) == IS_NULL)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_flag"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_VVS(_2$$3, path, _1$$3, "_");
		ZEPHIR_CPY_WRT(path, _2$$3);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_format"), PH_NOISY_CC);
	if (!(zephir_is_callable(_3 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_4$$4);
		zephir_create_array(_4$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_4$$4, this_ptr);
		ZEPHIR_INIT_VAR(_5$$4);
		ZVAL_STRING(_5$$4, "_formatPath", 1);
		zephir_array_fast_append(_4$$4, _5$$4);
		zephir_update_property_this(getThis(), SL("_format"), _4$$4 TSRMLS_CC);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_format"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_7, name);
	ZEPHIR_INIT_VAR(part);
	ZEPHIR_CALL_USER_FUNC_ARRAY(part, _6, _7);
	zephir_check_call_status();
	if (Z_TYPE_P(part) == IS_NULL) {
		ZEPHIR_INIT_VAR(_8$$5);
		object_init_ex(_8$$5, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_11$$5);
		ZVAL_STRING(_11$$5, "cache.path_mustbe_notnull", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_9$$5, brisk_kernel_language_ce, "get", &_10, 12, _11$$5);
		zephir_check_temp_parameter(_11$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _8$$5, "__construct", NULL, 7, _9$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$5, "brisk/Cache/Driver/Redis.zep", 117 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(result);
	ZEPHIR_CONCAT_VV(result, path, part);
	RETURN_CCTOR(result);

}

/**
 * 返回redis实例
 *
 * @return \Redis
 */
PHP_METHOD(Brisk_Cache_Driver_Redis, getInstance) {

	

	RETURN_MEMBER(getThis(), "_container");

}

PHP_METHOD(Brisk_Cache_Driver_Redis, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Cache_Driver_Redis, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Brisk_Cache_Driver_Redis, _formatPath) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	zephir_md5(return_value, name);
	RETURN_MM();

}

