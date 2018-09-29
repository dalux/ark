
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Brisk_Kernel_Language) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel, Language, brisk, kernel_language, brisk_kernel_language_method_entry, 0);

	zend_declare_property_string(brisk_kernel_language_ce, SL("_language"), "en_us", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(brisk_kernel_language_ce, SL("_package"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Add a Language Pack
 *
 * @param string language
 * @param array package
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Language, addPackage) {

	zval *package = NULL;
	zval *language_param = NULL, *package_param = NULL, *_0, *_2, *_3, *_4, *_1$$3;
	zval *language = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &language_param, &package_param);

	if (UNEXPECTED(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(language, language_param);
	} else {
		ZEPHIR_INIT_VAR(language);
		ZVAL_EMPTY_STRING(language);
	}
	if (!package_param) {
		ZEPHIR_INIT_VAR(package);
		array_init(package);
	} else {
	package = package_param;
	}


	_0 = zephir_fetch_static_property_ce(brisk_kernel_language_ce, SL("_package") TSRMLS_CC);
	if (!(zephir_array_isset(_0, language))) {
		ZEPHIR_INIT_VAR(_1$$3);
		array_init(_1$$3);
		zephir_update_static_property_array_multi_ce(brisk_kernel_language_ce, SL("_package"), &_1$$3 TSRMLS_CC, SL("z"), 1, language);
	}
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_fetch_static_property_ce(brisk_kernel_language_ce, SL("_package") TSRMLS_CC);
	zephir_array_fetch(&_4, _3, language, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 96 TSRMLS_CC);
	zephir_fast_array_merge(_2, &(_4), &(package) TSRMLS_CC);
	zephir_update_static_property_array_multi_ce(brisk_kernel_language_ce, SL("_package"), &_2 TSRMLS_CC, SL("z"), 1, language);
	ZEPHIR_MM_RESTORE();

}

/**
 * Add a Language pack file
 *
 * @param string language
 * @param string path
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Language, addPackageFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *language_param = NULL, *path_param = NULL, *package = NULL, *_0 = NULL, *_2, *_1$$3 = NULL, *_3$$5, *_4$$5, *_5$$5;
	zval *language = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &language_param, &path_param);

	if (UNEXPECTED(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(language, language_param);
	} else {
		ZEPHIR_INIT_VAR(language);
		ZVAL_EMPTY_STRING(language);
	}
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	ZEPHIR_INIT_VAR(package);
	array_init(package);
	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 49, path);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_1$$3);
		if (zephir_require_zval_ret(&_1$$3, path TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CPY_WRT(package, _1$$3);
		if (!(Z_TYPE_P(package) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(package);
			array_init(package);
		}
	}
	_2 = zephir_fetch_static_property_ce(brisk_kernel_language_ce, SL("_package") TSRMLS_CC);
	if (zephir_array_isset(_2, language)) {
		ZEPHIR_INIT_VAR(_3$$5);
		_4$$5 = zephir_fetch_static_property_ce(brisk_kernel_language_ce, SL("_package") TSRMLS_CC);
		zephir_array_fetch(&_5$$5, _4$$5, language, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 116 TSRMLS_CC);
		zephir_fast_array_merge(_3$$5, &(_5$$5), &(package) TSRMLS_CC);
		zephir_update_static_property_array_multi_ce(brisk_kernel_language_ce, SL("_package"), &_3$$5 TSRMLS_CC, SL("z"), 1, language);
	} else {
		zephir_update_static_property_array_multi_ce(brisk_kernel_language_ce, SL("_package"), &package TSRMLS_CC, SL("z"), 1, language);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the language pack for the specified language
 *
 * @param string language
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Language, getPackage) {

	zval *language_param = NULL, *_0, *_1;
	zval *language = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &language_param);

	if (!language_param) {
		ZEPHIR_INIT_VAR(language);
		ZVAL_STRING(language, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(language, language_param);
	} else {
		ZEPHIR_INIT_VAR(language);
		ZVAL_EMPTY_STRING(language);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	if (ZEPHIR_IS_STRING(language, "")) {
		zephir_read_static_property_ce(&_0, brisk_kernel_language_ce, SL("_package") TSRMLS_CC);
	} else {
		_1 = zephir_fetch_static_property_ce(brisk_kernel_language_ce, SL("_package") TSRMLS_CC);
		zephir_array_fetch(&_0, _1, language, PH_NOISY, "brisk/Kernel/Language.zep", 130 TSRMLS_CC);
	}
	RETURN_CCTOR(_0);

}

/**
 * Setting the current system language
 *
 * @param string language
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Language, setLanguage) {

	zval *language_param = NULL;
	zval *language = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &language_param);

	if (UNEXPECTED(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(language, language_param);
	} else {
		ZEPHIR_INIT_VAR(language);
		ZVAL_EMPTY_STRING(language);
	}


	zephir_update_static_property_ce(brisk_kernel_language_ce, SL("_language"), &language TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Parsing language Tags
 *
 * @param string label
 * @param array params
 * @return string
 */
PHP_METHOD(Brisk_Kernel_Language, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *label_param = NULL, *params_param = NULL, *language = NULL, *result = NULL, *_0, *_1, *_2$$3, *_3$$3, *_4$$3, *_5$$4, *_6$$4;
	zval *label = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &label_param, &params_param);

	if (UNEXPECTED(Z_TYPE_P(label_param) != IS_STRING && Z_TYPE_P(label_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'label' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(label_param) == IS_STRING)) {
		zephir_get_strval(label, label_param);
	} else {
		ZEPHIR_INIT_VAR(label);
		ZVAL_EMPTY_STRING(label);
	}
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
	params = params_param;
	}


	ZEPHIR_OBS_VAR(language);
	zephir_read_static_property_ce(&language, brisk_kernel_language_ce, SL("_language") TSRMLS_CC);
	ZEPHIR_INIT_VAR(result);
	ZVAL_BOOL(result, 0);
	_0 = zephir_fetch_static_property_ce(brisk_kernel_language_ce, SL("_package") TSRMLS_CC);
	zephir_array_fetch(&_1, _0, language, PH_READONLY, "brisk/Kernel/Language.zep", 155 TSRMLS_CC);
	if (zephir_array_isset(_1, label)) {
		_2$$3 = zephir_fetch_static_property_ce(brisk_kernel_language_ce, SL("_package") TSRMLS_CC);
		zephir_array_fetch(&_3$$3, _2$$3, language, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 156 TSRMLS_CC);
		zephir_array_fetch(&_4$$3, _3$$3, label, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 156 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&result, "vsprintf", NULL, 50, _4$$3, params);
		zephir_check_call_status();
	}
	if (!zephir_is_true(result)) {
		_5$$4 = zephir_fetch_static_property_ce(brisk_kernel_language_ce, SL("_package") TSRMLS_CC);
		zephir_array_fetch(&_6$$4, _5$$4, language, PH_NOISY | PH_READONLY, "brisk/Kernel/Language.zep", 159 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(result);
		zephir_array_fetch(&result, _6$$4, label, PH_NOISY, "brisk/Kernel/Language.zep", 159 TSRMLS_CC);
	}
	RETURN_CCTOR(result);

}

void zephir_init_static_properties_Brisk_Kernel_Language(TSRMLS_D) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 59, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("core.framework_not_ready"), SL("Framework not initialized"), 1);
	add_assoc_stringl_ex(_1, SS("core.invalid_controller_path"), SL("Invalid controller directory"), 1);
	add_assoc_stringl_ex(_1, SS("core.invalid_configuration"), SL("No valid configuration information found"), 1);
	add_assoc_stringl_ex(_1, SS("core.invalid_config_format"), SL("Configuration file [%s] must return array format data"), 1);
	add_assoc_stringl_ex(_1, SS("core.object_not_found"), SL("Unable to find a member"), 1);
	add_assoc_stringl_ex(_1, SS("core.invalid_autoloader"), SL("The auto loader cannot be called"), 1);
	add_assoc_stringl_ex(_1, SS("core.format_path_failed"), SL("Unable to format specified path[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("core.class_path_notfound"), SL("The file corresponding to classname[%s] does not exist"), 1);
	add_assoc_stringl_ex(_1, SS("core.invlid_custom_member"), SL("Custom member[%s] must return a valid object"), 1);
	add_assoc_stringl_ex(_1, SS("core.invlid_custom_method"), SL("Custom methods[%s] must be callable"), 1);
	add_assoc_stringl_ex(_1, SS("core.custom_method_notfound"), SL("Cannot find custom method[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("core.config_not_found"), SL("Unable to find a configuration item[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("core.namespace_not_defined"), SL("Unmatched namespace definition[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("http.request_not_ready"), SL("Http request data not ready"), 1);
	add_assoc_stringl_ex(_1, SS("http.method_not_found"), SL("The called method[%s] does not exist"), 1);
	add_assoc_stringl_ex(_1, SS("http.property_not_found"), SL("The called attribute object[%s] does not exist"), 1);
	add_assoc_stringl_ex(_1, SS("event.struct_check_failed"), SL("Event listener[%s] return value structure check failure[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("event.data_must_array"), SL("Event listener[%s] must return an array"), 1);
	add_assoc_stringl_ex(_1, SS("event.data_key_must_equal"), SL("Event listener[%s] array returns incomplete key values"), 1);
	add_assoc_stringl_ex(_1, SS("router.uri_parse_failed"), SL("Routing parsing result anomaly[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("router.invalid_controller_name"), SL("No valid controller name"), 1);
	add_assoc_stringl_ex(_1, SS("router.class_not_found"), SL("The requested controller classname[%s] does not exist"), 1);
	add_assoc_stringl_ex(_1, SS("router.action_not_found"), SL("Controller behavior[%s] does not exist"), 1);
	add_assoc_stringl_ex(_1, SS("router.controller_not_found"), SL("The requested controller[%s] does not exist"), 1);
	add_assoc_stringl_ex(_1, SS("router.invalid_driver_name"), SL("No valid routing drive name"), 1);
	add_assoc_stringl_ex(_1, SS("router.driver_not_found"), SL("Routing driver class[%s] does not exist"), 1);
	add_assoc_stringl_ex(_1, SS("router.driver_implement_error"), SL("The routing driver class[%s] must implement the interface[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("router.call_func_failed"), SL("Unable to call custom Uri rewriting function[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("router.uri_must_string"), SL("The rewritten Uri must be a string"), 1);
	add_assoc_stringl_ex(_1, SS("router.controller_is_protected"), SL("Access to a closed controller[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("router.configuration_missing"), SL("Routing configuration item [%s] missing"), 1);
	add_assoc_stringl_ex(_1, SS("tbox.invalid_db_connstr"), SL("Invalid database connection string[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("tbox.invalid_create_path"), SL("No directory path to create specified"), 1);
	add_assoc_stringl_ex(_1, SS("tbox.invalid_db_connection"), SL("The database connection object must implement the [\\Brisk\\Contract\\IDatabase] interface"), 1);
	add_assoc_stringl_ex(_1, SS("tbox.invalid_cache_object"), SL("The cache object must implement the [\\Brisk\\Contract\\ICache] interface"), 1);
	add_assoc_stringl_ex(_1, SS("tbox.parse_string_failed"), SL("Unable to parse string[%s]:[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("tbox.no_db_instance"), SL("Database connection object instance not set"), 1);
	add_assoc_stringl_ex(_1, SS("cache.driver_not_found"), SL("Cache drive class[%s] does not exist"), 1);
	add_assoc_stringl_ex(_1, SS("cache.driver_implement_error"), SL("Cache drive class[%s] must inherit from the class[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("cache.dir_create_failed"), SL("Unable to create cache file to save directory[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("cache.dir_permission_error"), SL("The cache directory[%s] has insufficient access to read and write"), 1);
	add_assoc_stringl_ex(_1, SS("cache.extension_load_failed"), SL("Load extension[%s] failure"), 1);
	add_assoc_stringl_ex(_1, SS("cache.cacher_create_failed"), SL("Cache object[%s] failed to create"), 1);
	add_assoc_stringl_ex(_1, SS("cache.path_mustbe_notnull"), SL("The return value of the formatted path function cannot be null"), 1);
	add_assoc_stringl_ex(_1, SS("proxy.target_not_callable"), SL("The specified object or method cannot be invoked"), 1);
	add_assoc_stringl_ex(_1, SS("proxy.invalid_cacher_object"), SL("Proxy cache must implement interface"), 1);
	add_assoc_stringl_ex(_1, SS("db.parse_sql_failed"), SL("SQL statement parsing failure"), 1);
	add_assoc_stringl_ex(_1, SS("db.connect_failed"), SL("Database connection failure"), 1);
	add_assoc_stringl_ex(_1, SS("db.driver_not_found"), SL("Database driver class[%s] does not exist"), 1);
	add_assoc_stringl_ex(_1, SS("db.driver_implement_error"), SL("The database driver class[%s] must realize the interface between[%s] and [%s]."), 1);
	add_assoc_stringl_ex(_1, SS("db.extension_load_failed"), SL("Load extension[%s] failure"), 1);
	add_assoc_stringl_ex(_1, SS("db.querier_type_missing"), SL("Missing database type parameters"), 1);
	add_assoc_stringl_ex(_1, SS("db.invalid_conn_string"), SL("Invalid database connection string[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("querier.type_not_supported"), SL("unsupported querier type [%s]"), 1);
	add_assoc_stringl_ex(_1, SS("view.invalid_driver_name"), SL("No valid view drive name"), 1);
	add_assoc_stringl_ex(_1, SS("view.driver_not_found"), SL("The view drive class[%s] does not exist"), 1);
	add_assoc_stringl_ex(_1, SS("view.driver_implement_error"), SL("The view driver class[%s] must implement the interface[%s]"), 1);
	add_assoc_stringl_ex(_1, SS("view.template_not_found"), SL("The template file [%s] does not exist"), 1);
	add_assoc_stringl_ex(_1, SS("view.include_file_not_found"), SL("The file[%s] to include does not exist"), 1);
	zephir_array_update_string(&_0, SL("en_us"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(brisk_kernel_language_ce, SL("_package"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

