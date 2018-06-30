
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


ZEPHIR_INIT_CLASS(Brisk_Router_RouterFather) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Router, RouterFather, brisk, router_routerfather, brisk_router_routerfather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(brisk_router_routerfather_ce TSRMLS_CC, 1, brisk_contract_irouter_ce);
	return SUCCESS;

}

PHP_METHOD(Brisk_Router_RouterFather, ready) {

}

PHP_METHOD(Brisk_Router_RouterFather, dispatch) {

}

