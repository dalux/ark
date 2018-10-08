
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Brisk_Db_Driver_Pdo_Oci) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Db\\Driver\\Pdo, Oci, brisk, db_driver_pdo_oci, brisk_db_driver_pdofather_ce, brisk_db_driver_pdo_oci_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Brisk_Db_Driver_Pdo_Oci, __construct) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_7 = NULL, *_12 = NULL;
	zval *config_param = NULL, *setting_param = NULL, *dsn = NULL, *params = NULL, *charset = NULL, *_0, *_2, _5, *_6 = NULL, *_13, *_14, *port$$3 = NULL, *_3$$3, *_4$$3, _8$$5, *_9$$5 = NULL, *_10$$5, *_11$$6;
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


	ZEPHIR_OBS_VAR(dsn);
	zephir_array_fetch_string(&dsn, config, SL("host"), PH_NOISY, "brisk/Db/Driver/Pdo/Oci.zep", 11 TSRMLS_CC);
	zephir_array_fetch_string(&_0, config, SL("host"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Oci.zep", 12 TSRMLS_CC);
	_1 = !ZEPHIR_IS_STRING(_0, "");
	if (_1) {
		zephir_array_fetch_string(&_2, config, SL("dbname"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Oci.zep", 12 TSRMLS_CC);
		_1 = !ZEPHIR_IS_STRING(_2, "");
	}
	if (_1) {
		ZEPHIR_OBS_VAR(port$$3);
		zephir_array_fetch_string(&port$$3, config, SL("port"), PH_NOISY, "brisk/Db/Driver/Pdo/Oci.zep", 14 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(port$$3, "")) {
			ZEPHIR_INIT_NVAR(port$$3);
			ZVAL_LONG(port$$3, 1521);
		}
		zephir_array_fetch_string(&_3$$3, config, SL("host"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Oci.zep", 18 TSRMLS_CC);
		zephir_array_fetch_string(&_4$$3, config, SL("dbname"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Oci.zep", 18 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(dsn);
		ZEPHIR_CONCAT_SVSVSV(dsn, "//", _3$$3, ":", port$$3, "/", _4$$3);
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "oci:dbname=%s;", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_7, 12, &_5, dsn);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dsn, _6);
	ZEPHIR_OBS_VAR(charset);
	zephir_array_fetch_string(&charset, config, SL("charset"), PH_NOISY, "brisk/Db/Driver/Pdo/Oci.zep", 21 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(charset, "")) {
		ZEPHIR_SINIT_VAR(_8$$5);
		ZVAL_STRING(&_8$$5, "charset=%s", 0);
		ZEPHIR_CALL_FUNCTION(&_9$$5, "sprintf", &_7, 12, &_8$$5, charset);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_10$$5);
		ZEPHIR_CONCAT_VV(_10$$5, dsn, _9$$5);
		ZEPHIR_CPY_WRT(dsn, _10$$5);
	}
	ZEPHIR_INIT_VAR(params);
	zephir_create_array(params, 4, 0 TSRMLS_CC);
	add_index_long(params, 3, 2);
	add_index_long(params, 11, 1);
	add_index_long(params, 8, 2);
	zephir_array_update_long(&params, 20, &ZEPHIR_GLOBAL(global_false), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	if (zephir_fast_count_int(setting TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_11$$6);
		zephir_fast_array_merge(_11$$6, &(params), &(setting) TSRMLS_CC);
		ZEPHIR_CPY_WRT(params, _11$$6);
	}
	zephir_array_fetch_string(&_13, config, SL("username"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Oci.zep", 34 TSRMLS_CC);
	zephir_array_fetch_string(&_14, config, SL("password"), PH_NOISY | PH_READONLY, "brisk/Db/Driver/Pdo/Oci.zep", 34 TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, brisk_db_driver_pdo_oci_ce, getThis(), "__construct", &_12, 42, dsn, _13, _14, params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

