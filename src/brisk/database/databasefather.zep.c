
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


ZEPHIR_INIT_CLASS(Brisk_Database_DatabaseFather) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Database, DatabaseFather, brisk, database_databasefather, brisk_database_databasefather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(brisk_database_databasefather_ce TSRMLS_CC, 1, brisk_contract_idatabase_ce);
	return SUCCESS;

}

PHP_METHOD(Brisk_Database_DatabaseFather, query) {

}

PHP_METHOD(Brisk_Database_DatabaseFather, fetchAll) {

}

PHP_METHOD(Brisk_Database_DatabaseFather, fetchRow) {

}

PHP_METHOD(Brisk_Database_DatabaseFather, fetchOne) {

}

PHP_METHOD(Brisk_Database_DatabaseFather, beginTransaction) {

}

PHP_METHOD(Brisk_Database_DatabaseFather, commit) {

}

PHP_METHOD(Brisk_Database_DatabaseFather, rollback) {

}

PHP_METHOD(Brisk_Database_DatabaseFather, inTransaction) {

}

PHP_METHOD(Brisk_Database_DatabaseFather, lastInsertId) {

}

PHP_METHOD(Brisk_Database_DatabaseFather, lastRowCount) {

}

PHP_METHOD(Brisk_Database_DatabaseFather, getDriverName) {

}

PHP_METHOD(Brisk_Database_DatabaseFather, getInstance) {

}

