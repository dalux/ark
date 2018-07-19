
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
#include "kernel/require.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Language) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Language, brisk, kernel_language, brisk_kernel_language_method_entry, 0);

	zend_declare_property_string(brisk_kernel_language_ce, SL("_language"), "en_us", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_language_ce, SL("_package"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Kernel_Language, addPackage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *language_param = NULL, *path_param = NULL, package, _0, _2, _1$$3, _3$$5, _4$$5, _5$$5;
	zval language, path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&language);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&package);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &language_param, &path_param);

	if (UNEXPECTED(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(&language, language_param);
	} else {
		ZEPHIR_INIT_VAR(&language);
		ZVAL_EMPTY_STRING(&language);
	}
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	ZEPHIR_INIT_VAR(&package);
	array_init(&package);
	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 42, &path);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_1$$3);
		if (zephir_require_zval_ret(&_1$$3, &path TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CPY_WRT(&package, &_1$$3);
		if (!(Z_TYPE_P(&package) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(&package);
			array_init(&package);
		}
	}
	zephir_read_static_property_ce(&_2, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_2, &language)) {
		ZEPHIR_INIT_VAR(&_3$$5);
		zephir_read_static_property_ce(&_4$$5, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_5$$5, &_4$$5, &language, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 99 TSRMLS_CC);
		zephir_fast_array_merge(&_3$$5, &_5$$5, &package TSRMLS_CC);
		zephir_update_static_property_array_multi_ce(brisk_kernel_language_ce, SL("_package"), &_3$$5 TSRMLS_CC, SL("z"), 1, &language);
	} else {
		zephir_update_static_property_array_multi_ce(brisk_kernel_language_ce, SL("_package"), &package TSRMLS_CC, SL("z"), 1, &language);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Language, getPackage) {

	zval *language_param = NULL, _0, _1;
	zval language;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&language);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &language_param);

	if (!language_param) {
		ZEPHIR_INIT_VAR(&language);
		ZVAL_STRING(&language, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(&language, language_param);
	} else {
		ZEPHIR_INIT_VAR(&language);
		ZVAL_EMPTY_STRING(&language);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_STRING(&language, "")) {
		zephir_read_static_property_ce(&_0, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC);
	} else {
		zephir_read_static_property_ce(&_1, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_1, &language, PH_NOISY, "brisk/Kernel/Language.zep", 107 TSRMLS_CC);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(Brisk_Kernel_Language, setLanguage) {

	zval *language_param = NULL;
	zval language;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&language);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &language_param);

	if (UNEXPECTED(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(&language, language_param);
	} else {
		ZEPHIR_INIT_VAR(&language);
		ZVAL_EMPTY_STRING(&language);
	}


	zend_update_static_property(brisk_kernel_language_ce, ZEND_STRL("_language"), &language);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_Kernel_Language, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *label_param = NULL, *params_param = NULL, language, result, _0, _1, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4;
	zval label;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&language);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &label_param, &params_param);

	if (UNEXPECTED(Z_TYPE_P(label_param) != IS_STRING && Z_TYPE_P(label_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'label' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(label_param) == IS_STRING)) {
		zephir_get_strval(&label, label_param);
	} else {
		ZEPHIR_INIT_VAR(&label);
		ZVAL_EMPTY_STRING(&label);
	}
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	}


	ZEPHIR_OBS_VAR(&language);
	zephir_read_static_property_ce(&language, brisk_kernel_language_ce, SL("_language"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_BOOL(&result, 0);
	zephir_read_static_property_ce(&_0, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, &language, PH_READONLY, "brisk/Kernel/Language.zep", 119 TSRMLS_CC);
	if (zephir_array_isset(&_1, &label)) {
		zephir_read_static_property_ce(&_2$$3, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &language, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 120 TSRMLS_CC);
		zephir_array_fetch(&_4$$3, &_3$$3, &label, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 120 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&result, "vsprintf", NULL, 43, &_4$$3, &params);
		zephir_check_call_status();
	}
	if (!zephir_is_true(&result)) {
		zephir_read_static_property_ce(&_5$$4, brisk_kernel_language_ce, SL("_package"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_6$$4, &_5$$4, &language, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 123 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&result);
		zephir_array_fetch(&result, &_6$$4, &label, PH_NOISY, "brisk/Kernel/Language.zep", 123 TSRMLS_CC);
	}
	RETURN_CCTOR(&result);

}

void zephir_init_static_properties_Brisk_Kernel_Language(TSRMLS_D) {

	zval _0, _1;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 63, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_1, SL("core.framework_not_ready"), SL("Framework not initialized"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_app_name"), SL("Application name not set"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_app_path"), SL("Invalid application directory"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_controller_path"), SL("Invalid controller directory"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_configuration"), SL("No valid configuration information found"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_config_format"), SL("Configuration file [%s] must return array format data"));
	add_assoc_stringl_ex(&_1, SL("core.object_not_found"), SL("Unable to find a membe"));
	add_assoc_stringl_ex(&_1, SL("core.invalid_autoloader"), SL("The auto loader cannot be called"));
	add_assoc_stringl_ex(&_1, SL("core.format_path_failed"), SL("Unable to format specified path[%s]"));
	add_assoc_stringl_ex(&_1, SL("core.class_path_notfound"), SL("The file corresponding to classname[%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("core.invlid_custom_member"), SL("Custom member[%s] must return a valid object"));
	add_assoc_stringl_ex(&_1, SL("core.invlid_custom_method"), SL("Custom methods[%s] must be callable"));
	add_assoc_stringl_ex(&_1, SL("core.custom_method_notfound"), SL("Cannot find custom method[%s]"));
	add_assoc_stringl_ex(&_1, SL("core.config_not_found"), SL("Unable to find a configuration item[%s]"));
	add_assoc_stringl_ex(&_1, SL("com.invalid_view_template"), SL("No valid view template file"));
	add_assoc_stringl_ex(&_1, SL("http.request_not_ready"), SL("Http request data not ready"));
	add_assoc_stringl_ex(&_1, SL("http.method_not_found"), SL("The called method[%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("http.property_not_found"), SL("The called attribute object[%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("event.struct_check_failed"), SL("Event listener[%s] return value structure check failure[%s]"));
	add_assoc_stringl_ex(&_1, SL("event.data_must_array"), SL("Event listener[%s] must return an array"));
	add_assoc_stringl_ex(&_1, SL("event.data_key_must_equal"), SL("Event listener[%s] array returns incomplete key values"));
	add_assoc_stringl_ex(&_1, SL("cache.driver_not_found"), SL("Cache drive class[%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("cache.driver_implement_error"), SL("Cache drive class[%s] must inherit from the class[%s]"));
	add_assoc_stringl_ex(&_1, SL("cache.dir_create_failed"), SL("Unable to create cache file to save directory[%s]"));
	add_assoc_stringl_ex(&_1, SL("cache.dir_permission_error"), SL("The cache directory[%s] has insufficient access to read and write"));
	add_assoc_stringl_ex(&_1, SL("cache.extension_load_failed"), SL("Load extension[%s] failure"));
	add_assoc_stringl_ex(&_1, SL("cache.cacher_create_failed"), SL("Cache object[%s] failed to create"));
	add_assoc_stringl_ex(&_1, SL("cache.path_mustbe_notnull"), SL("The return value of the formatted path function cannot be null"));
	add_assoc_stringl_ex(&_1, SL("db.parse_sql_failed"), SL("SQL statement parsing failure"));
	add_assoc_stringl_ex(&_1, SL("db.connect_failed"), SL("Database connection failure"));
	add_assoc_stringl_ex(&_1, SL("db.driver_not_found"), SL("Database driver class[%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("db.driver_implement_error"), SL("The database driver class[%s] must realize the interface between[%s] and [%s]."));
	add_assoc_stringl_ex(&_1, SL("db.extension_load_failed"), SL("Load extension[%s] failure"));
	add_assoc_stringl_ex(&_1, SL("db.querier_type_missing"), SL("Missing database type parameters"));
	add_assoc_stringl_ex(&_1, SL("db.invalid_conn_string"), SL("Invalid database connection string[%s]"));
	add_assoc_stringl_ex(&_1, SL("router.uri_parse_failed"), SL("Routing parsing result anomaly[%s]"));
	add_assoc_stringl_ex(&_1, SL("router.invalid_controller_name"), SL("No valid controller name"));
	add_assoc_stringl_ex(&_1, SL("router.class_not_found"), SL("The requested controller classname[%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("router.action_not_found"), SL("Controller behavior[%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("router.controller_not_found"), SL("The requested controller[%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("router.invalid_driver_name"), SL("No valid routing drive name"));
	add_assoc_stringl_ex(&_1, SL("router.driver_not_found"), SL("Routing driver class[%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("router.driver_implement_error"), SL("The routing driver class[%s] must implement the interface[%s]"));
	add_assoc_stringl_ex(&_1, SL("router.call_func_failed"), SL("Unable to call custom Uri rewriting function[%s]"));
	add_assoc_stringl_ex(&_1, SL("router.uri_must_string"), SL("The rewritten Uri must be a string"));
	add_assoc_stringl_ex(&_1, SL("router.controller_is_protected"), SL("Access to a closed controller[%s]"));
	add_assoc_stringl_ex(&_1, SL("sess.invalid_driver_name"), SL("No valid session drive name"));
	add_assoc_stringl_ex(&_1, SL("sess.driver_not_found"), SL("The session driver class[%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("sess.driver_implement_error"), SL("The session driver class[%s] must implement the interface[%s]"));
	add_assoc_stringl_ex(&_1, SL("sess.cacher_implement_error"), SL("The session memory must implement the interface[%s]"));
	add_assoc_stringl_ex(&_1, SL("view.invalid_driver_name"), SL("No valid view drive name"));
	add_assoc_stringl_ex(&_1, SL("view.driver_not_found"), SL("The view drive class[%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("view.driver_implement_error"), SL("The view driver class[%s] must implement the interface[%s]"));
	add_assoc_stringl_ex(&_1, SL("view.template_not_found"), SL("The template file [%s] does not exist"));
	add_assoc_stringl_ex(&_1, SL("view.include_file_not_found"), SL("The file[%s] to include does not exist"));
	add_assoc_stringl_ex(&_1, SL("tbox.invalid_db_connstr"), SL("Invalid database connection string[%s]"));
	add_assoc_stringl_ex(&_1, SL("tbox.invalid_create_path"), SL("No directory path to create specified"));
	add_assoc_stringl_ex(&_1, SL("tbox.invalid_db_connection"), SL("The database connection object must implement the [\\Brisk\\Contract\\IDatabase] interface"));
	add_assoc_stringl_ex(&_1, SL("tbox.invalid_cache_object"), SL("The cache object must implement the [\\Brisk\\Contract\\ICache] interface"));
	add_assoc_stringl_ex(&_1, SL("tbox.parse_string_failed"), SL("Unable to parse string[%s]:[%s]"));
	add_assoc_stringl_ex(&_1, SL("tbox.no_db_instance"), SL("Database connection object instance not set"));
	add_assoc_stringl_ex(&_1, SL("proxy.target_not_callable"), SL("The specified object or method cannot be invoked"));
	add_assoc_stringl_ex(&_1, SL("proxy.invalid_cacher_object"), SL("Proxy cache must implement interface"));
	zephir_array_update_string(&_0, SL("en_us"), &_1, PH_COPY | PH_SEPARATE);
	zend_update_static_property(brisk_kernel_language_ce, ZEND_STRL("_package"), &_0);
	ZEPHIR_MM_RESTORE();

}

