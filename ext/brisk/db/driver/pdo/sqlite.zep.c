
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Brisk_Db_Driver_Pdo_Sqlite) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Db\\Driver\\Pdo, Sqlite, brisk, db_driver_pdo_sqlite, brisk_db_driver_pdofather_ce, brisk_db_driver_pdo_sqlite_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Brisk_Db_Driver_Pdo_Sqlite, __construct) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, *setting_param = NULL, *dsn = NULL, *params = NULL, *_0, _1, *_4, *_5, *_2$$3;
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


	zephir_array_fetch_string(&_0, config, SL("dbname"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Sqlite.zep", 11 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "sqlite:%s", 0);
	ZEPHIR_CALL_FUNCTION(&dsn, "sprintf", NULL, 12, &_1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(params);
	zephir_create_array(params, 3, 0 TSRMLS_CC);
	add_index_long(params, 3, 2);
	add_index_long(params, 11, 1);
	zephir_array_update_long(&params, 20, &ZEPHIR_GLOBAL(global_false), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	if (zephir_fast_count_int(setting TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_fast_array_merge(_2$$3, &(params), &(setting) TSRMLS_CC);
		ZEPHIR_CPY_WRT(params, _2$$3);
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_NULL(_5);
	ZEPHIR_CALL_PARENT(NULL, brisk_db_driver_pdo_sqlite_ce, getThis(), "__construct", &_3, 42, dsn, _4, _5, params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

