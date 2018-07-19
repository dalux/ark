
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/require.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Brisk_View_NativeView) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\View, NativeView, brisk, view_nativeview, brisk_view_viewfather_ce, brisk_view_nativeview_method_entry, 0);

	zend_declare_property_null(brisk_view_nativeview_ce, SL("_storage"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(brisk_view_nativeview_ce, SL("_template_ext"), ".phtml", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(brisk_view_nativeview_ce, SL("_template_dir"), ZEND_ACC_PRIVATE TSRMLS_CC);

	brisk_view_nativeview_ce->create_object = zephir_init_properties_Brisk_View_NativeView;
	return SUCCESS;

}

PHP_METHOD(Brisk_View_NativeView, __construct) {

	zval config, _0, _2, _3, _4, _8, _5$$3, _6$$3, _7$$3, _9$$4, _10$$4, _11$$4, _12$$4, _13$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, brisk_kernel_app_ce, "getinstance", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, &_0, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&config, &_2);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "view.template_ext");
	ZEPHIR_CALL_METHOD(&_3, &config, "haskey", NULL, 0, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		zephir_read_property(&_5$$3, &config, SL("view"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$3, &_5$$3, SL("template_ext"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7$$3, &_6$$3, "getvalue", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_template_ext"), &_7$$3);
	}
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "view.template_dir");
	ZEPHIR_CALL_METHOD(&_8, &config, "haskey", NULL, 0, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_8)) {
		ZEPHIR_INIT_VAR(&_9$$4);
		zephir_read_property(&_10$$4, &config, SL("view"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_11$$4, &_10$$4, SL("template_dir"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_12$$4, &_11$$4, "getvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$4);
		ZVAL_STRING(&_13$$4, "/");
		zephir_fast_trim(&_9$$4, &_12$$4, &_13$$4, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_template_dir"), &_9$$4);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Brisk_View_NativeView, set) {

	zval *name_param = NULL, *val = NULL, val_sub, __$null;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&val_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &val);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!val) {
		val = &val_sub;
		val = &__$null;
	}


	zephir_update_property_array(this_ptr, SL("_storage"), &name, val TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Brisk_View_NativeView, get) {

	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_STRING(&name, "")) {
		zephir_read_property(&_0, this_ptr, SL("_storage"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_1, this_ptr, SL("_storage"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_1, &name, PH_NOISY, "brisk/View/NativeView.zep", 39 TSRMLS_CC);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(Brisk_View_NativeView, display) {

	zval _10$$4;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool output;
	zval *template_param = NULL, *output_param = NULL, _0, _1, _4, _5, _6, data, _14, _16, _17, _18, _19, _21, _2$$3, _3$$3, _7$$4, _8$$4, _11$$4, _13$$4, _20$$5;
	zval template;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_10$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &template_param, &output_param);

	if (UNEXPECTED(Z_TYPE_P(template_param) != IS_STRING && Z_TYPE_P(template_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'template' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(template_param) == IS_STRING)) {
		zephir_get_strval(&template, template_param);
	} else {
		ZEPHIR_INIT_VAR(&template);
		ZVAL_EMPTY_STRING(&template);
	}
	if (!output_param) {
		output = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(output_param) != IS_TRUE && Z_TYPE_P(output_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'output' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	output = (Z_TYPE_P(output_param) == IS_TRUE);
	}


	zephir_read_property(&_0, this_ptr, SL("_template_ext"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &template, &_0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		zephir_read_property(&_2$$3, this_ptr, SL("_template_ext"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VV(&_3$$3, &template, &_2$$3);
		zephir_get_strval(&template, &_3$$3);
	}
	zephir_read_property(&_4, this_ptr, SL("_template_dir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VSV(&_5, &_4, "/", &template);
	zephir_get_strval(&template, &_5);
	ZEPHIR_CALL_FUNCTION(&_6, "is_file", NULL, 42, &template);
	zephir_check_call_status();
	if (!zephir_is_true(&_6)) {
		ZEPHIR_INIT_VAR(&_7$$4);
		object_init_ex(&_7$$4, brisk_exception_viewexception_ce);
		ZEPHIR_INIT_VAR(&_10$$4);
		zephir_create_array(&_10$$4, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&_11$$4, brisk_kernel_loader_ce, "reducepath", &_12, 0, &template);
		zephir_check_call_status();
		zephir_array_fast_append(&_10$$4, &_11$$4);
		ZEPHIR_INIT_VAR(&_13$$4);
		ZVAL_STRING(&_13$$4, "view.template_not_found");
		ZEPHIR_CALL_CE_STATIC(&_8$$4, brisk_kernel_language_ce, "get", &_9, 0, &_13$$4, &_10$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$4, "__construct", NULL, 3, &_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$4, "brisk/View/NativeView.zep", 49 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&data, SL("template"), &template, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&data, SL("driver"), SL("Native"));
	ZEPHIR_INIT_VAR(&_16);
	ZVAL_STRING(&_16, "event.view.before");
	ZEPHIR_CALL_CE_STATIC(&_14, brisk_kernel_event_ce, "onlistening", &_15, 0, &_16, &data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&data, &_14);
	zephir_read_property(&_17, this_ptr, SL("_storage"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_18, 256);
	ZEPHIR_MAKE_REF(&_17);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 80, &_17, &_18);
	ZEPHIR_UNREF(&_17);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 57);
	zephir_check_call_status();
	if (zephir_require_zval(&template TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&_14, "ob_get_clean", NULL, 59);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("content"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_16);
	ZVAL_STRING(&_16, "event.view.finish");
	ZEPHIR_CALL_CE_STATIC(&_19, brisk_kernel_event_ce, "onlistening", &_15, 0, &_16, &data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&data, &_19);
	if (output) {
		zephir_array_fetch_string(&_20$$5, &data, SL("content"), PH_NOISY | PH_READONLY, "brisk/View/NativeView.zep", 63 TSRMLS_CC);
		zend_print_zval(&_20$$5, 0);
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
	zephir_array_fetch_string(&_21, &data, SL("content"), PH_NOISY | PH_READONLY, "brisk/View/NativeView.zep", 66 TSRMLS_CC);
	RETURN_CTOR(&_21);

}

PHP_METHOD(Brisk_View_NativeView, import) {

	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool output;
	zval params, _9$$4;
	zval *path_param = NULL, *params_param = NULL, *output_param = NULL, _0, _1, template, _4, _5, _13, _14, content, _2$$3, _3$$3, _6$$4, _7$$4, _10$$4, _12$$4;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path_param, &params_param, &output_param);

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
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	}
	if (!output_param) {
		output = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(output_param) != IS_TRUE && Z_TYPE_P(output_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'output' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	output = (Z_TYPE_P(output_param) == IS_TRUE);
	}


	zephir_read_property(&_0, this_ptr, SL("_template_ext"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &path, &_0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		zephir_read_property(&_2$$3, this_ptr, SL("_template_ext"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VV(&_3$$3, &path, &_2$$3);
		zephir_get_strval(&path, &_3$$3);
	}
	zephir_read_property(&_4, this_ptr, SL("_template_dir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&template);
	ZEPHIR_CONCAT_VSV(&template, &_4, "/", &path);
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", NULL, 42, &template);
	zephir_check_call_status();
	if (!zephir_is_true(&_5)) {
		ZEPHIR_INIT_VAR(&_6$$4);
		object_init_ex(&_6$$4, brisk_exception_viewexception_ce);
		ZEPHIR_INIT_VAR(&_9$$4);
		zephir_create_array(&_9$$4, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&_10$$4, brisk_kernel_loader_ce, "reducepath", &_11, 0, &template);
		zephir_check_call_status();
		zephir_array_fast_append(&_9$$4, &_10$$4);
		ZEPHIR_INIT_VAR(&_12$$4);
		ZVAL_STRING(&_12$$4, "view.include_file_not_found");
		ZEPHIR_CALL_CE_STATIC(&_7$$4, brisk_kernel_language_ce, "get", &_8, 0, &_12$$4, &_9$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 3, &_7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$4, "brisk/View/NativeView.zep", 77 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_13, this_ptr, SL("_storage"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_14, 256);
	ZEPHIR_MAKE_REF(&_13);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", &_15, 80, &_13, &_14);
	ZEPHIR_UNREF(&_13);
	zephir_check_call_status();
	ZVAL_LONG(&_14, 1);
	ZEPHIR_MAKE_REF(&params);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", &_15, 80, &params, &_14);
	ZEPHIR_UNREF(&params);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 57);
	zephir_check_call_status();
	if (zephir_require_zval(&template TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&content, "ob_get_clean", NULL, 59);
	zephir_check_call_status();
	if (output) {
		zend_print_zval(&content, 0);
	}
	RETURN_CCTOR(&content);

}

zend_object *zephir_init_properties_Brisk_View_NativeView(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_storage"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_storage"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

