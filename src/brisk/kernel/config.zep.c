
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

PHP_METHOD(Brisk_Kernel_Config, getExample) {

	zval _0, _1, _2;
	zval __$true, _3;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("debug"), &__$true, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_0, SL("timezone"), SL("Asia/Shanghai"));
	add_assoc_long_ex(&_0, SL("error_reporting"), (((32767 ^ 8) ^ 2) ^ 8192));
	zephir_array_update_string(return_value, SL("global"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 5, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_0, SL("driver"), SL("\\Brisk\\Router\\ClassicRouter"));
	add_assoc_stringl_ex(&_0, SL("auto_method"), SL("__init"));
	add_assoc_stringl_ex(&_0, SL("default_controller"), SL("Index"));
	add_assoc_stringl_ex(&_0, SL("default_action"), SL("index"));
	add_assoc_stringl_ex(&_0, SL("url_suffix"), SL(".html"));
	zephir_array_update_string(return_value, SL("router"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_0, SL("driver"), SL("\\Brisk\\Session\\FileSession"));
	add_assoc_long_ex(&_0, SL("expire_time"), 1440);
	add_assoc_stringl_ex(&_0, SL("save_path"), SL("/path/to/sessiondir"));
	zephir_array_update_string(return_value, SL("session"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_1, SL("driver"), SL("\\Brisk\\Database\\PdoDriver\\Mysql"));
	add_assoc_stringl_ex(&_1, SL("dsn"), SL("mysql://username:password@127.0.0.1:3306/dbname?charset=utf8"));
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_2, SL("type"), SL("new"));
	zephir_array_update_string(&_1, SL("option"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("master"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("database"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_array(&_1, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_1, SL("driver"), SL("\\Brisk\\Cache\\FileCache"));
	add_assoc_stringl_ex(&_1, SL("save_path"), SL("/path/to/cachedir"));
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_2, SL("ext_name"), SL(".cache"));
	zephir_array_update_string(&_1, SL("option"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("file"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_array(&_1, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_1, SL("driver"), SL("\\Brisk\\Cache\\MemCache"));
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "127.0.0.1:11211");
	zephir_array_fast_append(&_2, &_3);
	zephir_array_update_string(&_1, SL("save_path"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	array_init(&_3);
	zephir_array_update_string(&_1, SL("option"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("memcache"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("cache"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_0, SL("driver"), SL("\\Brisk\\View\\NativeView"));
	add_assoc_stringl_ex(&_0, SL("template_ext"), SL(".phtml"));
	add_assoc_stringl_ex(&_0, SL("template_dir"), SL("/path/to/tpldir"));
	zephir_array_update_string(return_value, SL("view"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(Brisk_Kernel_Config, saveToFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, config, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11;
	zval file, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_EMPTY_STRING(&file);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SS(&_0, "<", "?php\n\n");
	ZEPHIR_CPY_WRT(&config, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CALL_SELF(&_2, "getexample", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	zephir_var_export_ex(&_1, &_2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSVS(&_3, &config, "return ", &_1, ";");
	ZEPHIR_CPY_WRT(&config, &_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/=>\\s\n\\s+array/");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "=> array");
	ZEPHIR_CALL_FUNCTION(&_6, "preg_replace", NULL, 2, &_4, &_5, &config);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&config, &_6);
	ZEPHIR_INIT_NVAR(&_4);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "\\\\");
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "\\");
	zephir_fast_str_replace(&_4, &_5, &_7, &config TSRMLS_CC);
	ZEPHIR_CPY_WRT(&config, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "' =>");
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "'=>");
	zephir_fast_str_replace(&_4, &_8, &_9, &config TSRMLS_CC);
	ZEPHIR_CPY_WRT(&config, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "array (");
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "array(");
	zephir_fast_str_replace(&_4, &_10, &_11, &config TSRMLS_CC);
	ZEPHIR_CPY_WRT(&config, &_4);
	zephir_file_put_contents(NULL, &file, &config TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

