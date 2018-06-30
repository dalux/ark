
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

PHP_METHOD(Brisk_Kernel_Server, isCli) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "php_sapi_name", NULL, 52);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "cli"));

}

PHP_METHOD(Brisk_Kernel_Server, getDomain) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *reduce_param = NULL, domain, _0, _1, _3, _4, _5, pattern$$3, matches$$3, matched$$3, _7$$4, _8$$4, _9$$4, _10$$4, _11$$4;
	zend_bool reduce, _2, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&pattern$$3);
	ZVAL_UNDEF(&matches$$3);
	ZVAL_UNDEF(&matched$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &reduce_param);

	if (!reduce_param) {
		reduce = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(reduce_param) != IS_TRUE && Z_TYPE_P(reduce_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'reduce' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	reduce = (Z_TYPE_P(reduce_param) == IS_TRUE);
	}


	zephir_read_static_property_ce(&_0, brisk_kernel_server_ce, SL("_data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("HTTP_HOST"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 17 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&domain);
	zephir_fast_strtolower(&domain, &_1);
	_2 = !ZEPHIR_IS_STRING(&domain, "localhost");
	if (_2) {
		ZEPHIR_INIT_VAR(&_3);
		ZEPHIR_INIT_VAR(&_4);
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "/\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}/");
		zephir_preg_match(&_4, &_5, &domain, &_3, 0, 0 , 0  TSRMLS_CC);
		_2 = !zephir_is_true(&_4);
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&pattern$$3);
		ZVAL_STRING(&pattern$$3, "/^(.*?)\.([^\.]+?)\.(dev|com|cn|net|com.cn|org|org\.cn|cc|de|net\.cn|co|tv|hk|me|info|name|biz|so|mobi|gov\.cn|wang)?$/");
		ZEPHIR_INIT_VAR(&matches$$3);
		array_init(&matches$$3);
		ZEPHIR_INIT_VAR(&matched$$3);
		zephir_preg_match(&matched$$3, &pattern$$3, &domain, &matches$$3, 1, 0 , 0  TSRMLS_CC);
		_6$$3 = reduce;
		if (_6$$3) {
			_6$$3 = ZEPHIR_GT_LONG(&matched$$3, 0);
		}
		if (_6$$3) {
			zephir_array_fetch_long(&_7$$4, &matches$$3, 2, PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 23 TSRMLS_CC);
			zephir_array_fetch_long(&_8$$4, &_7$$4, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 23 TSRMLS_CC);
			zephir_array_fetch_long(&_9$$4, &matches$$3, 3, PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 23 TSRMLS_CC);
			zephir_array_fetch_long(&_10$$4, &_9$$4, 0, PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 23 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_11$$4);
			ZVAL_STRING(&_11$$4, "%s.%s");
			ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 4, &_11$$4, &_8$$4, &_10$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	RETURN_CCTOR(&domain);

}

PHP_METHOD(Brisk_Kernel_Server, getSubDomain) {

	zval domain, _0, _1, host, _2, prefix, _3, _4, _5, _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, brisk_kernel_server_ce, SL("_data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("HTTP_HOST"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 31 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&domain);
	zephir_fast_strtolower(&domain, &_1);
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_SELF(&host, "getdomain", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "");
	zephir_fast_str_replace(&_3, &host, &_4, &domain TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, ".");
	ZEPHIR_INIT_VAR(&prefix);
	zephir_fast_trim(&prefix, &_3, &_5, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	if (!ZEPHIR_IS_STRING(&prefix, "")) {
		ZEPHIR_CPY_WRT(&_6, &prefix);
	} else {
		ZVAL_STRING(&_6, "www");
	}
	RETURN_CCTOR(&_6);

}

PHP_METHOD(Brisk_Kernel_Server, initCli) {

	zephir_fcall_cache_entry *_9 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *_GET, arg, argv, data, key, val, info, _0, *_1, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _10$$4, _11$$5, _12$$5, _13$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arg);
	ZVAL_UNDEF(&argv);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_SERVER, SL("_SERVER"));

	zend_update_static_property(brisk_kernel_server_ce, ZEND_STRL("_data"), _SERVER);
	ZEPHIR_CPY_WRT(&data, _GET);
	zephir_read_static_property_ce(&_0, brisk_kernel_server_ce, SL("_data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&argv);
	zephir_array_fetch_string(&argv, &_0, SL("argv"), PH_NOISY, "brisk/Kernel/Server.zep", 43 TSRMLS_CC);
	ZEPHIR_MAKE_REF(&argv);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 7, &argv);
	ZEPHIR_UNREF(&argv);
	zephir_check_call_status();
	zephir_is_iterable(&argv, 0, "brisk/Kernel/Server.zep", 64);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&argv), _1)
	{
		ZEPHIR_INIT_NVAR(&arg);
		ZVAL_COPY(&arg, _1);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "--");
		zephir_fast_trim(&_2$$3, &arg, &_3$$3, ZEPHIR_TRIM_LEFT TSRMLS_CC);
		ZEPHIR_CPY_WRT(&arg, &_2$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "=");
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_fast_strpos(&_4$$3, &arg, &_2$$3, 0 );
		ZVAL_LONG(&_5$$3, 0);
		ZEPHIR_INIT_NVAR(&key);
		zephir_substr(&key, &arg, 0 , zephir_get_intval(&_4$$3), 0);
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "=");
		ZEPHIR_INIT_NVAR(&_7$$3);
		zephir_fast_strpos(&_7$$3, &arg, &_6$$3, 0 );
		ZVAL_LONG(&_8$$3, (zephir_get_numberval(&_7$$3) + 1));
		ZEPHIR_INIT_NVAR(&val);
		zephir_substr(&val, &arg, zephir_get_intval(&_8$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (ZEPHIR_IS_STRING(&key, "url")) {
			ZEPHIR_CALL_FUNCTION(&info, "parse_url", &_9, 20, &val);
			zephir_check_call_status();
			zephir_array_fetch_string(&_10$$4, &info, SL("host"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 51 TSRMLS_CC);
			zephir_update_static_property_array_multi_ce(brisk_kernel_server_ce, SL("_data"), &_10$$4 TSRMLS_CC, SL("s"), 2, SL("HTTP_HOST"));
			zephir_array_fetch_string(&_10$$4, &info, SL("path"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 52 TSRMLS_CC);
			zephir_update_static_property_array_multi_ce(brisk_kernel_server_ce, SL("_data"), &_10$$4 TSRMLS_CC, SL("s"), 2, SL("REQUEST_URI"));
			zephir_array_fetch_string(&_10$$4, &info, SL("query"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 53 TSRMLS_CC);
			if (!ZEPHIR_IS_STRING(&_10$$4, "")) {
				zephir_array_fetch_string(&_11$$5, &info, SL("path"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 54 TSRMLS_CC);
				zephir_array_fetch_string(&_12$$5, &info, SL("query"), PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 54 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_13$$5);
				ZEPHIR_CONCAT_VSV(&_13$$5, &_11$$5, "?", &_12$$5);
				zephir_update_static_property_array_multi_ce(brisk_kernel_server_ce, SL("_data"), &_13$$5 TSRMLS_CC, SL("s"), 2, SL("REQUEST_URI"));
			}
		} else if (ZEPHIR_IS_STRING(&key, "uri")) {
			zephir_update_static_property_array_multi_ce(brisk_kernel_server_ce, SL("_data"), &val TSRMLS_CC, SL("s"), 2, SL("REQUEST_URI"));
		} else if (ZEPHIR_IS_STRING(&key, "domain")) {
			zephir_update_static_property_array_multi_ce(brisk_kernel_server_ce, SL("_data"), &val TSRMLS_CC, SL("s"), 2, SL("HTTP_HOST"));
		} else {
			zephir_array_update_zval(&data, &key, &val, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arg);
	ZEPHIR_CALL_CE_STATIC(NULL, brisk_kernel_request_ce, "setdata", &_14, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Server, getItem) {

	zval *item_param = NULL, *_SERVER, _0, _2, _3, _1$$4, _4$$5, _5$$5;
	zval item;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 0, 1, &item_param);

	if (!item_param) {
		ZEPHIR_INIT_VAR(&item);
		ZVAL_STRING(&item, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(item_param) != IS_STRING && Z_TYPE_P(item_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'item' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(item_param) == IS_STRING)) {
		zephir_get_strval(&item, item_param);
	} else {
		ZEPHIR_INIT_VAR(&item);
		ZVAL_EMPTY_STRING(&item);
	}
	}


	zephir_read_static_property_ce(&_0, brisk_kernel_server_ce, SL("_data"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) < 1) {
		zend_update_static_property(brisk_kernel_server_ce, ZEND_STRL("_data"), _SERVER);
	}
	if (ZEPHIR_IS_STRING(&item, "")) {
		zephir_read_static_property_ce(&_1$$4, brisk_kernel_server_ce, SL("_data"), PH_NOISY_CC | PH_READONLY);
		RETURN_CTOR(&_1$$4);
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strtoupper(&_2, &item);
	zephir_get_strval(&item, &_2);
	zephir_read_static_property_ce(&_3, brisk_kernel_server_ce, SL("_data"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_3, &item)) {
		zephir_read_static_property_ce(&_4$$5, brisk_kernel_server_ce, SL("_data"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_5$$5, &_4$$5, &item, PH_NOISY | PH_READONLY, "brisk/Kernel/Server.zep", 77 TSRMLS_CC);
		RETURN_CTOR(&_5$$5);
	} else {
		RETURN_MM_BOOL(0);
	}

}

void zephir_init_static_properties_Brisk_Kernel_Server(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(brisk_kernel_server_ce, ZEND_STRL("_data"), &_0);
	ZEPHIR_MM_RESTORE();

}

