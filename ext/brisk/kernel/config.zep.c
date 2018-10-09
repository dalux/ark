
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/variables.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Config) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Config, brisk, kernel_config, brisk_kernel_config_method_entry, 0);

	return SUCCESS;

}

/**
 * Get configuration sample
 *
 * @return array
 */
PHP_METHOD(Brisk_Kernel_Config, getExample) {

	zval *_3 = NULL;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("debug"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_0, SS("timezone"), SL("Asia/Shanghai"), 1);
	add_assoc_stringl_ex(_0, SS("header"), SL("Content-type: text/html;charset=utf-8"), 1);
	add_assoc_long_ex(_0, SS("error_reporting"), (((32767 ^ 8) ^ 2) ^ 8192));
	zephir_array_update_string(&return_value, SL("global"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("driver"), SL("Brisk\\Router\\Driver\\Classic"), 1);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 6, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("base_namespace"), SL("App\\Controller"), 1);
	add_assoc_stringl_ex(_1, SS("auto_method"), SL("__init"), 1);
	add_assoc_stringl_ex(_1, SS("default_controller"), SL("Index"), 1);
	add_assoc_stringl_ex(_1, SS("default_action"), SL("index"), 1);
	add_assoc_stringl_ex(_1, SS("url_suffix"), SL(".html"), 1);
	add_assoc_stringl_ex(_1, SS("auto_include"), SL("init.php"), 1);
	zephir_array_update_string(&_0, SL("option"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("router"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("driver"), SL("Brisk\\Session\\Driver\\Files"), 1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_2, SS("host"), SL("127.0.0.1"), 1);
	add_assoc_long_ex(_2, SS("port"), 11211);
	add_assoc_stringl_ex(_2, SS("password"), SL("123456"), 1);
	add_assoc_stringl_ex(_2, SS("path"), SL("/path/to/session_path"), 1);
	zephir_array_update_string(&_1, SL("config"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_array_update_string(&_1, SL("setting"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("option"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("session"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("driver"), SL("Brisk\\Db\\Driver\\Pdo\\Mysql"), 1);
	ZEPHIR_INIT_NVAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 6, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_4, SS("host"), SL("127.0.0.1"), 1);
	add_assoc_stringl_ex(_4, SS("username"), SL("user"), 1);
	add_assoc_stringl_ex(_4, SS("password"), SL("pass"), 1);
	add_assoc_long_ex(_4, SS("port"), 1521);
	add_assoc_stringl_ex(_4, SS("dbname"), SL("dbname"), 1);
	add_assoc_stringl_ex(_4, SS("charset"), SL("utf8"), 1);
	zephir_array_update_string(&_2, SL("config"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_4, SS("type"), SL("new"), 1);
	zephir_array_update_string(&_2, SL("setting"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("option"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("master"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("database"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("driver"), SL("Brisk\\Cache\\Driver\\File"), 1);
	ZEPHIR_INIT_NVAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_2, SS("path"), SL("/path/to/cachedir"), 1);
	ZEPHIR_INIT_NVAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_4, SS("ext_name"), SL(".cache"), 1);
	zephir_array_update_string(&_2, SL("setting"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("option"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("file"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("driver"), SL("Brisk\\Cache\\Driver\\Memcached"), 1);
	ZEPHIR_INIT_NVAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "127.0.0.1:11211", 1);
	zephir_array_fast_append(_4, _3);
	zephir_array_update_string(&_2, SL("path"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	array_init(_3);
	zephir_array_update_string(&_2, SL("setting"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("option"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("memcache"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("cache"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("driver"), SL("Brisk\\View\\Driver\\Native"), 1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("template_ext"), SL(".phtml"), 1);
	add_assoc_stringl_ex(_1, SS("template_dir"), SL("/path/to/tpldir"), 1);
	zephir_array_update_string(&_0, SL("option"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&return_value, SL("view"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Save the configuration sample to the specified file
 *
 * @param string file
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Config, saveToFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *config = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_5, *_6 = NULL, _7, _8, _9, _10, _11, _12;
	zval *file = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(file, file_param);
	} else {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SS(_0, "<", "?php\n\n");
	ZEPHIR_CPY_WRT(config, _0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CALL_SELF(&_2, "getexample", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	zephir_var_export_ex(_1, &_2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VSVS(_3, config, "return ", _1, ";");
	ZEPHIR_CPY_WRT(config, _3);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "/=>\\s\n\\s+array/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "=> array", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_6, "preg_replace", NULL, 4, _4, _5, config);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, _6);
	ZEPHIR_INIT_NVAR(_4);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "\\\\", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "\\", 0);
	zephir_fast_str_replace(&_4, &_7, &_8, config TSRMLS_CC);
	ZEPHIR_CPY_WRT(config, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "' =>", 0);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_STRING(&_10, "'=>", 0);
	zephir_fast_str_replace(&_4, &_9, &_10, config TSRMLS_CC);
	ZEPHIR_CPY_WRT(config, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_STRING(&_11, "array (", 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "array(", 0);
	zephir_fast_str_replace(&_4, &_11, &_12, config TSRMLS_CC);
	ZEPHIR_CPY_WRT(config, _4);
	zephir_file_put_contents(NULL, file, config TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

