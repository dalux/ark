
extern zend_class_entry *brisk_sql_sqlbuilder_ce;

ZEPHIR_INIT_CLASS(Brisk_Sql_SqlBuilder);

PHP_METHOD(Brisk_Sql_SqlBuilder, setDbType);
PHP_METHOD(Brisk_Sql_SqlBuilder, getDbType);
PHP_METHOD(Brisk_Sql_SqlBuilder, getSelect);
PHP_METHOD(Brisk_Sql_SqlBuilder, getDelete);
PHP_METHOD(Brisk_Sql_SqlBuilder, getInsert);
PHP_METHOD(Brisk_Sql_SqlBuilder, getUpdate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlbuilder_setdbtype, 0, 0, 1)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlbuilder_getselect, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlbuilder_getdelete, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlbuilder_getinsert, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_brisk_sql_sqlbuilder_getupdate, 0, 0, 0)
	ZEND_ARG_INFO(0, dbtype)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(brisk_sql_sqlbuilder_method_entry) {
	PHP_ME(Brisk_Sql_SqlBuilder, setDbType, arginfo_brisk_sql_sqlbuilder_setdbtype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Sql_SqlBuilder, getDbType, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Sql_SqlBuilder, getSelect, arginfo_brisk_sql_sqlbuilder_getselect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Sql_SqlBuilder, getDelete, arginfo_brisk_sql_sqlbuilder_getdelete, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Sql_SqlBuilder, getInsert, arginfo_brisk_sql_sqlbuilder_getinsert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Brisk_Sql_SqlBuilder, getUpdate, arginfo_brisk_sql_sqlbuilder_getupdate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
