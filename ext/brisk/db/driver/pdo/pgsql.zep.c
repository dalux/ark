
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Brisk_Db_Driver_Pdo_Pgsql) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Db\\Driver\\Pdo, Pgsql, brisk, db_driver_pdo_pgsql, brisk_db_driver_pdofather_ce, brisk_db_driver_pdo_pgsql_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Brisk_Db_Driver_Pdo_Pgsql, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL;
	zval *config_param = NULL, *setting_param = NULL, *dsn = NULL, *params = NULL, *charset = NULL, *_0, *_1, *_2, _3, *_10, *_11, _5$$3, *_6$$3 = NULL, *_7$$3, *_8$$4;
	zval *config = NULL, *setting = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &config_param, &setting_param);

	config = config_param;
	if (!setting_param) {
		ZEPHIR_INIT_VAR(setting);
		array_init(setting);
	} else {
	setting = setting_param;
	}


	zephir_array_fetch_string(&_0, config, SL("host"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Pgsql.zep", 11 TSRMLS_CC);
	zephir_array_fetch_string(&_1, config, SL("port"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Pgsql.zep", 11 TSRMLS_CC);
	zephir_array_fetch_string(&_2, config, SL("dbname"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Pgsql.zep", 11 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "pgsql:host=%s;port=%s;dbname=%s;", 0);
	ZEPHIR_CALL_FUNCTION(&dsn, "sprintf", &_4, 11, &_3, _0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(charset);
	zephir_array_fetch_string(&charset, config, SL("charset"), PH_NOISY, "brisk/Db/Driver/Pdo/Pgsql.zep", 12 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(charset, "")) {
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_STRING(&_5$$3, "charset=%s", 0);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", &_4, 11, &_5$$3, charset);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_CONCAT_VV(_7$$3, dsn, _6$$3);
		ZEPHIR_CPY_WRT(dsn, _7$$3);
	}
	ZEPHIR_INIT_VAR(params);
	zephir_create_array(params, 3, 0 TSRMLS_CC);
	add_index_long(params, 3, 2);
	add_index_long(params, 11, 1);
	zephir_array_update_long(&params, 20, &ZEPHIR_GLOBAL(global_false), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	if (zephir_fast_count_int(setting TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_8$$4);
		zephir_fast_array_merge(_8$$4, &(params), &(setting) TSRMLS_CC);
		ZEPHIR_CPY_WRT(params, _8$$4);
	}
	zephir_array_fetch_string(&_10, config, SL("username"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Pgsql.zep", 24 TSRMLS_CC);
	zephir_array_fetch_string(&_11, config, SL("password"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Pgsql.zep", 24 TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, brisk_db_driver_pdo_pgsql_ce, getThis(), "__construct", &_9, 41, dsn, _10, _11, params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

