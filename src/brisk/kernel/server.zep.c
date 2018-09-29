
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Server) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Server, brisk, kernel_server, brisk_kernel_server_method_entry, 0);

	zend_declare_property_null(brisk_kernel_server_ce, SL("_data"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Check if it is CLI mode
 *
 * @return bool
 */
PHP_METHOD(Brisk_Kernel_Server, isCli) {

	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "php_sapi_name", NULL, 71);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(_0, "cli"));

}

/**
 * Get current Server domain name
 *
 * @param bool reduce
 * @return string
 */
PHP_METHOD(Brisk_Kernel_Server, getDomain) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *reduce_param = NULL, *domain = NULL, *_0, *_1, *_3, *_4, _5, *pattern$$3 = NULL, *matches$$3 = NULL, *matched$$3 = NULL, *_7$$4, *_8$$4, *_9$$4, *_10$$4, _11$$4;
	zend_bool reduce, _2, _6$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &reduce_param);

	if (!reduce_param) {
		reduce = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(reduce_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'reduce' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	reduce = Z_BVAL_P(reduce_param);
	}


	_0 = zephir_fetch_static_property_ce(brisk_kernel_server_ce, SL("_data") TSRMLS_CC);
	zephir_array_fetch_string(&_1, _0, SL("HTTP_HOST"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 28 TSRMLS_CC);
	ZEPHIR_INIT_VAR(domain);
	zephir_fast_strtolower(domain, _1);
	_2 = !ZEPHIR_IS_STRING(domain, "localhost");
	if (_2) {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "/\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}/i", 0);
		zephir_preg_match(_4, &_5, domain, _3, 0, 0 , 0  TSRMLS_CC);
		_2 = !zephir_is_true(_4);
	}
	if (_2) {
		ZEPHIR_INIT_VAR(pattern$$3);
		ZVAL_STRING(pattern$$3, "/^(.*?)\\.([^\\.]+?)\\.(dev|com|cn|net|com\\.cn|org|org\\.cn|cc|de|net\\.cn|co|tv|hk|me|info|name|biz|so|mobi|gov\\.cn|wang)?$/i", 1);
		ZEPHIR_INIT_VAR(matches$$3);
		array_init(matches$$3);
		ZEPHIR_INIT_VAR(matched$$3);
		zephir_preg_match(matched$$3, pattern$$3, domain, matches$$3, 1, 0 , 0  TSRMLS_CC);
		_6$$3 = reduce;
		if (_6$$3) {
			_6$$3 = ZEPHIR_GT_LONG(matched$$3, 0);
		}
		if (_6$$3) {
			zephir_array_fetch_long(&_7$$4, matches$$3, 2, PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 34 TSRMLS_CC);
			zephir_array_fetch_long(&_8$$4, _7$$4, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 34 TSRMLS_CC);
			zephir_array_fetch_long(&_9$$4, matches$$3, 3, PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 34 TSRMLS_CC);
			zephir_array_fetch_long(&_10$$4, _9$$4, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 34 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_11$$4);
			ZVAL_STRING(&_11$$4, "%s.%s", 0);
			ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 40, &_11$$4, _8$$4, _10$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	RETURN_CCTOR(domain);

}

/**
 * Get server sub-domain name
 *
 * @return string
 */
PHP_METHOD(Brisk_Kernel_Server, getSubDomain) {

	zval *domain = NULL, *_0, *_1, *host = NULL, *_2 = NULL, *prefix = NULL, _3, _4, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(brisk_kernel_server_ce, SL("_data") TSRMLS_CC);
	zephir_array_fetch_string(&_1, _0, SL("HTTP_HOST"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 47 TSRMLS_CC);
	ZEPHIR_INIT_VAR(domain);
	zephir_fast_strtolower(domain, _1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_SELF(&host, "getdomain", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "", 0);
	zephir_fast_str_replace(&_2, host, &_3, domain TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, ".", 0);
	ZEPHIR_INIT_VAR(prefix);
	zephir_fast_trim(prefix, _2, &_4, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	if (!ZEPHIR_IS_STRING(prefix, "")) {
		ZEPHIR_CPY_WRT(_5, prefix);
	} else {
		ZVAL_STRING(_5, "www", 1);
	}
	RETURN_CCTOR(_5);

}

/**
 * Init cli mode
 *
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Server, initCli) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_11 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *_GET, *arg = NULL, *argv = NULL, *data = NULL, *key = NULL, *val = NULL, *info = NULL, *_0, **_3, *_4$$3 = NULL, _5$$3 = zval_used_for_init, _6$$3 = zval_used_for_init, _7$$3 = zval_used_for_init, _8$$3 = zval_used_for_init, *_9$$3 = NULL, _10$$3 = zval_used_for_init, *_12$$4, *_13$$5, *_14$$5, *_15$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	zephir_update_static_property_ce(brisk_kernel_server_ce, SL("_data"), &_SERVER TSRMLS_CC);
	ZEPHIR_CPY_WRT(data, _GET);
	_0 = zephir_fetch_static_property_ce(brisk_kernel_server_ce, SL("_data") TSRMLS_CC);
	ZEPHIR_OBS_VAR(argv);
	zephir_array_fetch_string(&argv, _0, SL("argv"), PH_NOISY, "brisk/Kernel/Server.zep", 64 TSRMLS_CC);
	ZEPHIR_MAKE_REF(argv);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 7, argv);
	ZEPHIR_UNREF(argv);
	zephir_check_call_status();
	zephir_is_iterable(argv, &_2, &_1, 0, 0, "brisk/Kernel/Server.zep", 85);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(arg, _3);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZEPHIR_SINIT_NVAR(_5$$3);
		ZVAL_STRING(&_5$$3, "--", 0);
		zephir_fast_trim(_4$$3, arg, &_5$$3, ZEPHIR_TRIM_LEFT TSRMLS_CC);
		ZEPHIR_CPY_WRT(arg, _4$$3);
		ZEPHIR_SINIT_NVAR(_6$$3);
		ZVAL_STRING(&_6$$3, "=", 0);
		ZEPHIR_INIT_NVAR(_4$$3);
		zephir_fast_strpos(_4$$3, arg, &_6$$3, 0 );
		ZEPHIR_SINIT_NVAR(_7$$3);
		ZVAL_LONG(&_7$$3, 0);
		ZEPHIR_INIT_NVAR(key);
		zephir_substr(key, arg, 0 , zephir_get_intval(_4$$3), 0);
		ZEPHIR_SINIT_NVAR(_8$$3);
		ZVAL_STRING(&_8$$3, "=", 0);
		ZEPHIR_INIT_NVAR(_9$$3);
		zephir_fast_strpos(_9$$3, arg, &_8$$3, 0 );
		ZEPHIR_SINIT_NVAR(_10$$3);
		ZVAL_LONG(&_10$$3, (zephir_get_numberval(_9$$3) + 1));
		ZEPHIR_INIT_NVAR(val);
		zephir_substr(val, arg, zephir_get_intval(&_10$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (ZEPHIR_IS_STRING(key, "url")) {
			ZEPHIR_CALL_FUNCTION(&info, "parse_url", &_11, 72, val);
			zephir_check_call_status();
			zephir_array_fetch_string(&_12$$4, info, SL("host"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 72 TSRMLS_CC);
			zephir_update_static_property_array_multi_ce(brisk_kernel_server_ce, SL("_data"), &_12$$4 TSRMLS_CC, SL("s"), 2, SL("HTTP_HOST"));
			zephir_array_fetch_string(&_12$$4, info, SL("path"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 73 TSRMLS_CC);
			zephir_update_static_property_array_multi_ce(brisk_kernel_server_ce, SL("_data"), &_12$$4 TSRMLS_CC, SL("s"), 2, SL("REQUEST_URI"));
			zephir_array_fetch_string(&_12$$4, info, SL("query"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 74 TSRMLS_CC);
			if (!ZEPHIR_IS_STRING(_12$$4, "")) {
				zephir_array_fetch_string(&_13$$5, info, SL("path"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 75 TSRMLS_CC);
				zephir_array_fetch_string(&_14$$5, info, SL("query"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 75 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_15$$5);
				ZEPHIR_CONCAT_VSV(_15$$5, _13$$5, "?", _14$$5);
				zephir_update_static_property_array_multi_ce(brisk_kernel_server_ce, SL("_data"), &_15$$5 TSRMLS_CC, SL("s"), 2, SL("REQUEST_URI"));
			}
		} else if (ZEPHIR_IS_STRING(key, "uri")) {
			zephir_update_static_property_array_multi_ce(brisk_kernel_server_ce, SL("_data"), &val TSRMLS_CC, SL("s"), 2, SL("REQUEST_URI"));
		} else if (ZEPHIR_IS_STRING(key, "domain")) {
			zephir_update_static_property_array_multi_ce(brisk_kernel_server_ce, SL("_data"), &val TSRMLS_CC, SL("s"), 2, SL("HTTP_HOST"));
		} else {
			zephir_array_update_zval(&data, key, &val, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_request_ce, "setdata", &_16, 59, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get current Server parameters
 *
 * @param string item
 * @return mixed
 */
PHP_METHOD(Brisk_Kernel_Server, getItem) {

	zval *item_param = NULL, *_SERVER, *_0, *_2, *_3, *_1$$4, *_4$$5, *_5$$5;
	zval *item = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 0, 1, &item_param);

	if (!item_param) {
		ZEPHIR_INIT_VAR(item);
		ZVAL_STRING(item, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(item_param) != IS_STRING && Z_TYPE_P(item_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'item' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(item_param) == IS_STRING)) {
		zephir_get_strval(item, item_param);
	} else {
		ZEPHIR_INIT_VAR(item);
		ZVAL_EMPTY_STRING(item);
	}
	}


	_0 = zephir_fetch_static_property_ce(brisk_kernel_server_ce, SL("_data") TSRMLS_CC);
	if (zephir_fast_count_int(_0 TSRMLS_CC) < 1) {
		zephir_update_static_property_ce(brisk_kernel_server_ce, SL("_data"), &_SERVER TSRMLS_CC);
	}
	if (ZEPHIR_IS_STRING(item, "")) {
		_1$$4 = zephir_fetch_static_property_ce(brisk_kernel_server_ce, SL("_data") TSRMLS_CC);
		RETURN_CTOR(_1$$4);
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_strtoupper(_2, item);
	zephir_get_strval(item, _2);
	_3 = zephir_fetch_static_property_ce(brisk_kernel_server_ce, SL("_data") TSRMLS_CC);
	if (zephir_array_isset(_3, item)) {
		_4$$5 = zephir_fetch_static_property_ce(brisk_kernel_server_ce, SL("_data") TSRMLS_CC);
		zephir_array_fetch(&_5$$5, _4$$5, item, PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 104 TSRMLS_CC);
		RETURN_CTOR(_5$$5);
	} else {
		RETURN_MM_BOOL(0);
	}

}

void zephir_init_static_properties_Brisk_Kernel_Server(TSRMLS_D) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(brisk_kernel_server_ce, SL("_data"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

