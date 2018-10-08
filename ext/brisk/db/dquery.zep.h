
extern zend_class_entry *brisk_db_dquery_ce;

ZEPHIR_INIT_CLASS(Brisk_Db_DQuery);

PHP_METHOD(Brisk_Db_DQuery, setConnection);
PHP_METHOD(Brisk_Db_DQuery, getConnection);
PHP_METHOD(Brisk_Db_DQuery, __construct);
PHP_METHOD(Brisk_Db_DQuery, init);
PHP_METHOD(Brisk_Db_DQuery, cache);
PHP_METHOD(Brisk_Db_DQuery, insert);
PHP_METHOD(Brisk_Db_DQuery, update);
PHP_METHOD(Brisk_Db_DQuery, delete);
PHP_METHOD(Brisk_Db_DQuery, fetchRow);
PHP_METHOD(Brisk_Db_DQuery, fetchOne);
PHP_METHOD(Brisk_Db_DQuery, fetchAll);
zend_object_value zephir_init_properties_Brisk_Db_DQuery(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_dquery_setconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, conn, Brisk\\Db\\DbFather, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_dquery___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, tb)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_dquery_init, 0, 0, 1)
	ZEND_ARG_INFO(0, tb)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_dquery_cache, 0, 0, 2)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_OBJ_INFO(0, cache, Brisk\\Cache\\CacheFather, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_dquery_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, return_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_dquery_update, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, condition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_dquery_delete, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, condition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_dquery_fetchrow, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, condition, 0)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_dquery_fetchone, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, condition, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_db_dquery_fetchall, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, condition, 1)
	ZEND_ARG_ARRAY_INFO(0, order, 1)
	ZEND_ARG_INFO(0, count)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_db_dquery_method_entry) {
	PHP_ME(Brisk_Db_DQuery, setConnection, arginfo_brisk_db_dquery_setconnection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Db_DQuery, getConnection, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Db_DQuery, __construct, arginfo_brisk_db_dquery___construct, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Brisk_Db_DQuery, init, arginfo_brisk_db_dquery_init, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Db_DQuery, cache, arginfo_brisk_db_dquery_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_DQuery, insert, arginfo_brisk_db_dquery_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_DQuery, update, arginfo_brisk_db_dquery_update, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_DQuery, delete, arginfo_brisk_db_dquery_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_DQuery, fetchRow, arginfo_brisk_db_dquery_fetchrow, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_DQuery, fetchOne, arginfo_brisk_db_dquery_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Brisk_Db_DQuery, fetchAll, arginfo_brisk_db_dquery_fetchall, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
