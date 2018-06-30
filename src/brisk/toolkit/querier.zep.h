
extern zend_class_entry *brisk_toolkit_querier_ce;

ZEPHIR_INIT_CLASS(Brisk_Toolkit_Querier);

PHP_METHOD(Brisk_Toolkit_Querier, setConnection);
PHP_METHOD(Brisk_Toolkit_Querier, getConnection);
PHP_METHOD(Brisk_Toolkit_Querier, __construct);
PHP_METHOD(Brisk_Toolkit_Querier, forTable);
PHP_METHOD(Brisk_Toolkit_Querier, cache);
PHP_METHOD(Brisk_Toolkit_Querier, insert);
PHP_METHOD(Brisk_Toolkit_Querier, update);
PHP_METHOD(Brisk_Toolkit_Querier, delete);
PHP_METHOD(Brisk_Toolkit_Querier, fetchRow);
PHP_METHOD(Brisk_Toolkit_Querier, fetchOne);
PHP_METHOD(Brisk_Toolkit_Querier, fetchAll);
zend_object *zephir_init_properties_Brisk_Toolkit_Querier(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_querier_setconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, conn)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_querier___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, tb)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_querier_fortable, 0, 0, 1)
	ZEND_ARG_INFO(0, tb)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_querier_cache, 0, 0, 2)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, cache)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_querier_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, return_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_querier_update, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, condition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_querier_delete, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, condition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_querier_fetchrow, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, condition, 0)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_querier_fetchone, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, condition, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_toolkit_querier_fetchall, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, condition, 1)
	ZEND_ARG_ARRAY_INFO(0, order, 1)
	ZEND_ARG_INFO(0, count)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_toolkit_querier_method_entry) {
	PHP_ME(Brisk_Toolkit_Querier, setConnection, arginfo_brisk_toolkit_querier_setconnection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Toolkit_Querier, getConnection, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Toolkit_Querier, __construct, arginfo_brisk_toolkit_querier___construct, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Toolkit_Querier, forTable, arginfo_brisk_toolkit_querier_fortable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Toolkit_Querier, cache, arginfo_brisk_toolkit_querier_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_Querier, insert, arginfo_brisk_toolkit_querier_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_Querier, update, arginfo_brisk_toolkit_querier_update, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_Querier, delete, arginfo_brisk_toolkit_querier_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_Querier, fetchRow, arginfo_brisk_toolkit_querier_fetchrow, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_Querier, fetchOne, arginfo_brisk_toolkit_querier_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Toolkit_Querier, fetchAll, arginfo_brisk_toolkit_querier_fetchall, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
