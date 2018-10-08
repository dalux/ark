
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


ZEPHIR_INIT_CLASS(Brisk_Db_DbFather) {

	ZEPHIR_REGISTER_CLASS(Brisk\\Db, DbFather, brisk, db_dbfather, brisk_db_dbfather_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Execute a sql with bind options
 *
 * @param string sql
 * @param array bind
 * @return mixed
 */
PHP_METHOD(Brisk_Db_DbFather, query) {

}

/**
 * Execute fetchAll method with bind options
 *
 * @param string sql
 * @param array bind
 * @return array
 */
PHP_METHOD(Brisk_Db_DbFather, fetchAll) {

}

/**
 * Execute fetchRow method with bind options
 *
 * @param string sql
 * @param array bind
 * @return mixed
 */
PHP_METHOD(Brisk_Db_DbFather, fetchRow) {

}

/**
 * Execute fetchOne method with bind options
 *
 * @param string sql
 * @param array bind
 * @return mixed
 */
PHP_METHOD(Brisk_Db_DbFather, fetchOne) {

}

/**
 * Start a new Transaction
 *
 * @return bool
 */
PHP_METHOD(Brisk_Db_DbFather, beginTransaction) {

}

/**
 * Commit a Transaction
 *
 * @return bool
 */
PHP_METHOD(Brisk_Db_DbFather, commit) {

}

/**
 * Rollback a Transaction
 *
 * @return bool
 */
PHP_METHOD(Brisk_Db_DbFather, rollback) {

}

/**
 * Check if the current sql is in a transaction
 *
 * @return bool
 */
PHP_METHOD(Brisk_Db_DbFather, inTransaction) {

}

/**
 * Get last insert id
 *
 * @param string seq
 * @return int
 */
PHP_METHOD(Brisk_Db_DbFather, lastInsertId) {

}

/**
 * Gets the number of rows as a result of the last sql execution
 *
 * @return int
 */
PHP_METHOD(Brisk_Db_DbFather, lastRowCount) {

}

/**
 * Get current driver name
 *
 * @return string
 */
PHP_METHOD(Brisk_Db_DbFather, getDriverName) {

}

/**
 * Get pdo instance
 *
 * @return \PDO
 */
PHP_METHOD(Brisk_Db_DbFather, getInstance) {

}

