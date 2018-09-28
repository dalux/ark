
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


ZEPHIR_INIT_CLASS(Brisk_Kernel_Router_RouterFather) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Kernel\\Router, RouterFather, brisk, kernel_router_routerfather, brisk_kernel_router_routerfather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Routing ready
 *
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_RouterFather, ready) {

}

/**
 * Routing path distribution
 *
 * @return null
 */
PHP_METHOD(Brisk_Kernel_Router_RouterFather, dispatch) {

}

