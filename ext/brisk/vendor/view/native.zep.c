
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_View_Native) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Vendor\\View, Native, brisk, vendor_view_native, brisk_vendor_view_viewfather_ce, brisk_vendor_view_native_method_entry, 0);

	zend_declare_property_null(brisk_vendor_view_native_ce, SL("_storage"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(brisk_vendor_view_native_ce, SL("_template_ext"), ".phtml", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_vendor_view_native_ce, SL("_template_dir"), ZEND_ACC_PRIVATE TSRMLS_CC);

	brisk_vendor_view_native_ce->create_object = zephir_init_properties_Brisk_Vendor_View_Native;
	return SUCCESS;

}

/**
 * Construct
 *
 * @param array options
 * @return mixed
 */
PHP_METHOD(Brisk_Vendor_View_Native, __construct) {

	zval *options_param = NULL, *_0$$3, *_1$$4, *_2$$4, _3$$4;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
	options = options_param;
	}


	if (zephir_array_isset_string(options, SS("template_ext"))) {
		zephir_array_fetch_string(&_0$$3, options, SL("template_ext"), PH_NOISY | PH_READONLY, "brisk/Vendor/View/Native.zep", 27 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_template_ext"), _0$$3 TSRMLS_CC);
	}
	if (zephir_array_isset_string(options, SS("template_dir"))) {
		ZEPHIR_INIT_VAR(_1$$4);
		zephir_array_fetch_string(&_2$$4, options, SL("template_dir"), PH_NOISY | PH_READONLY, "brisk/Vendor/View/Native.zep", 30 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_3$$4);
		ZVAL_STRING(&_3$$4, "/", 0);
		zephir_fast_trim(_1$$4, _2$$4, &_3$$4, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_template_dir"), _1$$4 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set template data
 *
 * @param string name
 * @param mixed val
 * @return Native
 */
PHP_METHOD(Brisk_Vendor_View_Native, set) {

	zval *name_param = NULL, *val = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &val);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!val) {
		val = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_array(this_ptr, SL("_storage"), name, val TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get template data
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_Vendor_View_Native, get) {

	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_STRING(name, "", 1);
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	if (ZEPHIR_IS_STRING(name, "")) {
		zephir_read_property_this(&_0, this_ptr, SL("_storage"), PH_NOISY_CC);
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_storage"), PH_NOISY_CC);
		zephir_array_fetch(&_0, _1, name, PH_NOISY, "brisk/Vendor/View/Native.zep", 55 TSRMLS_CC);
	}
	RETURN_CCTOR(_0);

}

/**
 * Rendering template data
 *
 * @param string template
 * @param bool output
 * @return string
 */
PHP_METHOD(Brisk_Vendor_View_Native, display) {

	zval *_10$$4;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool output;
	zval *template_param = NULL, *output_param = NULL, *_0, *_1, *_4, *_5, *_6 = NULL, *data = NULL, *_14 = NULL, *_16 = NULL, *_17, *_18 = NULL, *_20, *_2$$3, *_3$$3, *_7$$4, *_8$$4 = NULL, *_11$$4 = NULL, *_13$$4, *_19$$5;
	zval *template = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &template_param, &output_param);

	if (UNEXPECTED(Z_TYPE_P(template_param) != IS_STRING && Z_TYPE_P(template_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'template' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(template_param) == IS_STRING)) {
		zephir_get_strval(template, template_param);
	} else {
		ZEPHIR_INIT_VAR(template);
		ZVAL_EMPTY_STRING(template);
	}
	if (!output_param) {
		output = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(output_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'output' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	output = Z_BVAL_P(output_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_template_ext"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, template, _0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_template_ext"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_VV(_3$$3, template, _2$$3);
		zephir_get_strval(template, _3$$3);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_template_dir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VSV(_5, _4, "/", template);
	zephir_get_strval(template, _5);
	ZEPHIR_CALL_FUNCTION(&_6, "is_file", NULL, 48, template);
	zephir_check_call_status();
	if (!zephir_is_true(_6)) {
		ZEPHIR_INIT_VAR(_7$$4);
		object_init_ex(_7$$4, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_10$$4);
		zephir_create_array(_10$$4, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&_11$$4, brisk_kernel_loader_ce, "reducepath", &_12, 109, template);
		zephir_check_call_status();
		zephir_array_fast_append(_10$$4, _11$$4);
		ZEPHIR_INIT_VAR(_13$$4);
		ZVAL_STRING(_13$$4, "view.template_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_8$$4, brisk_kernel_language_ce, "get", &_9, 26, _13$$4, _10$$4);
		zephir_check_temp_parameter(_13$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _7$$4, "__construct", NULL, 27, _8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$4, "brisk/Vendor/View/Native.zep", 72 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(data);
	zephir_create_array(data, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&data, SL("template"), &template, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(data, SS("driver"), SL("Native"), 1);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_STRING(_16, "event.view.before", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_14, brisk_kernel_event_ce, "fire", &_15, 31, _16, data);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _14);
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("_storage"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_16);
	ZVAL_LONG(_16, 256);
	ZEPHIR_MAKE_REF(_17);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 110, _17, _16);
	ZEPHIR_UNREF(_17);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 79);
	zephir_check_call_status();
	if (zephir_require_zval(template TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&_14, "ob_get_clean", NULL, 81);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("content"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_16);
	ZVAL_STRING(_16, "event.view.finish", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_18, brisk_kernel_event_ce, "fire", &_15, 31, _16, data);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _18);
	if (output) {
		zephir_array_fetch_string(&_19$$5, data, SL("content"), PH_NOISY | PH_READONLY, "brisk/Vendor/View/Native.zep", 86 TSRMLS_CC);
		zend_print_zval(_19$$5, 0);
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
	zephir_array_fetch_string(&_20, data, SL("content"), PH_NOISY | PH_READONLY, "brisk/Vendor/View/Native.zep", 89 TSRMLS_CC);
	RETURN_CTOR(_20);

}

/**
 * Import template file
 *
 * @param string path
 * @param array params
 * @param bool output
 * @return string
 */
PHP_METHOD(Brisk_Vendor_View_Native, import) {

	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool output;
	zval *params = NULL, *_9$$4;
	zval *path_param = NULL, *params_param = NULL, *output_param = NULL, *_0, *_1, *template = NULL, *_4, *_5 = NULL, *_13, *_14 = NULL, *content = NULL, *_2$$3, *_3$$3, *_6$$4, *_7$$4 = NULL, *_10$$4 = NULL, *_12$$4;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path_param, &params_param, &output_param);

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
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
	params = params_param;
	}
	if (!output_param) {
		output = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(output_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'output' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	output = Z_BVAL_P(output_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_template_ext"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, path, _0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_template_ext"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_VV(_3$$3, path, _2$$3);
		zephir_get_strval(path, _3$$3);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_template_dir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(template);
	ZEPHIR_CONCAT_VSV(template, _4, "/", path);
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", NULL, 48, template);
	zephir_check_call_status();
	if (!zephir_is_true(_5)) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, brisk_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_9$$4);
		zephir_create_array(_9$$4, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&_10$$4, brisk_kernel_loader_ce, "reducepath", &_11, 109, template);
		zephir_check_call_status();
		zephir_array_fast_append(_9$$4, _10$$4);
		ZEPHIR_INIT_VAR(_12$$4);
		ZVAL_STRING(_12$$4, "view.include_file_not_found", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&_7$$4, brisk_kernel_language_ce, "get", &_8, 26, _12$$4, _9$$4);
		zephir_check_temp_parameter(_12$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 27, _7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "brisk/Vendor/View/Native.zep", 108 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("_storage"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_LONG(_14, 256);
	ZEPHIR_MAKE_REF(_13);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", &_15, 110, _13, _14);
	ZEPHIR_UNREF(_13);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_14);
	ZVAL_LONG(_14, 1);
	ZEPHIR_MAKE_REF(params);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", &_15, 110, params, _14);
	ZEPHIR_UNREF(params);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 79);
	zephir_check_call_status();
	if (zephir_require_zval(template TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&content, "ob_get_clean", NULL, 81);
	zephir_check_call_status();
	if (output) {
		zend_print_zval(content, 0);
	}
	RETURN_CCTOR(content);

}

zend_object_value zephir_init_properties_Brisk_Vendor_View_Native(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_storage"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_storage"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

