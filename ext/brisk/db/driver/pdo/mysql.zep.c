
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
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Brisk_Db_Driver_Pdo_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Db\\Driver\\Pdo, Mysql, brisk, db_driver_pdo_mysql, brisk_db_driver_pdofather_ce, brisk_db_driver_pdo_mysql_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Brisk_Db_Driver_Pdo_Mysql, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL;
	zval *config_param = NULL, *setting_param = NULL, *dsn = NULL, *params = NULL, *_0, *_1, *_2, _3, *_11, *_12, *_5$$3, _6$$3, *_7$$3 = NULL, *_8$$3, *_9$$4;
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


	zephir_array_fetch_string(&_0, config, SL("host"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Mysql.zep", 11 TSRMLS_CC);
	zephir_array_fetch_string(&_1, config, SL("port"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Mysql.zep", 11 TSRMLS_CC);
	zephir_array_fetch_string(&_2, config, SL("dbname"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Mysql.zep", 11 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "mysql:host=%s;port=%s;dbname=%s;", 0);
	ZEPHIR_CALL_FUNCTION(&dsn, "sprintf", &_4, 11, &_3, _0, _1, _2);
	zephir_check_call_status();
	if (zephir_array_isset_string(config, SS("charset"))) {
		zephir_array_fetch_string(&_5$$3, config, SL("charset"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Mysql.zep", 13 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_STRING(&_6$$3, "charset=%s", 0);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "sprintf", &_4, 11, &_6$$3, _5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$3);
		ZEPHIR_CONCAT_VV(_8$$3, dsn, _7$$3);
		ZEPHIR_CPY_WRT(dsn, _8$$3);
	}
	ZEPHIR_INIT_VAR(params);
	zephir_create_array(params, 3, 0 TSRMLS_CC);
	add_index_long(params, 3, 2);
	add_index_long(params, 11, 1);
	zephir_array_update_long(&params, 20, &ZEPHIR_GLOBAL(global_false), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	if (zephir_fast_count_int(setting TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_9$$4);
		zephir_fast_array_merge(_9$$4, &(params), &(setting) TSRMLS_CC);
		ZEPHIR_CPY_WRT(params, _9$$4);
	}
	zephir_array_fetch_string(&_11, config, SL("username"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Mysql.zep", 23 TSRMLS_CC);
	zephir_array_fetch_string(&_12, config, SL("password"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Mysql.zep", 23 TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, brisk_db_driver_pdo_mysql_ce, getThis(), "__construct", &_10, 41, dsn, _11, _12, params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

