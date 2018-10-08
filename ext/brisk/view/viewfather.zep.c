
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


ZEPHIR_INIT_CLASS(Brisk_View_ViewFather) {

	ZEPHIR_REGISTER_CLASS(Brisk\\View, ViewFather, brisk, view_viewfather, brisk_view_viewfather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Set template data
 *
 * @param string name
 * @param mixed val
 * @return ViewFather
 */
PHP_METHOD(Brisk_View_ViewFather, set) {

}

/**
 * Get template data
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Brisk_View_ViewFather, get) {

}

/**
 * Rendering template data
 *
 * @param string template
 * @param bool output
 * @return string
 */
PHP_METHOD(Brisk_View_ViewFather, display) {

}

