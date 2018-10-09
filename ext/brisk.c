
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

// TODO: Deprecated. Will be removed in future
#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "brisk.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *brisk_sql_sqlfather_ce;
zend_class_entry *brisk_exception_runtimeexception_ce;
zend_class_entry *brisk_db_dbfather_ce;
zend_class_entry *brisk_db_driver_pdofather_ce;
zend_class_entry *brisk_sql_delete_ce;
zend_class_entry *brisk_sql_insert_ce;
zend_class_entry *brisk_sql_select_ce;
zend_class_entry *brisk_sql_update_ce;
zend_class_entry *brisk_session_sessionfather_ce;
zend_class_entry *brisk_cache_cachefather_ce;
zend_class_entry *brisk_router_routerfather_ce;
zend_class_entry *brisk_view_viewfather_ce;
zend_class_entry *brisk_cache_cacheadapter_ce;
zend_class_entry *brisk_cache_cacheproxy_ce;
zend_class_entry *brisk_cache_driver_file_ce;
zend_class_entry *brisk_cache_driver_memcached_ce;
zend_class_entry *brisk_cache_driver_redis_ce;
zend_class_entry *brisk_db_dbadapter_ce;
zend_class_entry *brisk_db_dquery_ce;
zend_class_entry *brisk_db_driver_pdo_mysql_ce;
zend_class_entry *brisk_db_driver_pdo_oci_ce;
zend_class_entry *brisk_db_driver_pdo_pgsql_ce;
zend_class_entry *brisk_db_driver_pdo_sqlite_ce;
zend_class_entry *brisk_db_driver_pdo_sqlsrv_ce;
zend_class_entry *brisk_exception_actionnotfoundexception_ce;
zend_class_entry *brisk_exception_classnotfoundexception_ce;
zend_class_entry *brisk_exception_configurationexception_ce;
zend_class_entry *brisk_exception_controllerexception_ce;
zend_class_entry *brisk_exception_controllernotfoundexception_ce;
zend_class_entry *brisk_exception_dbexception_ce;
zend_class_entry *brisk_exception_drivernotfoundexception_ce;
zend_class_entry *brisk_exception_eventexception_ce;
zend_class_entry *brisk_exception_methodnotfoundexception_ce;
zend_class_entry *brisk_exception_pdoexception_ce;
zend_class_entry *brisk_exception_routerexception_ce;
zend_class_entry *brisk_exception_sqlcompileexception_ce;
zend_class_entry *brisk_http_request_ce;
zend_class_entry *brisk_http_response_ce;
zend_class_entry *brisk_kernel_app_ce;
zend_class_entry *brisk_kernel_config_ce;
zend_class_entry *brisk_kernel_container_ce;
zend_class_entry *brisk_kernel_event_ce;
zend_class_entry *brisk_kernel_handler_ce;
zend_class_entry *brisk_kernel_language_ce;
zend_class_entry *brisk_kernel_loader_ce;
zend_class_entry *brisk_kernel_server_ce;
zend_class_entry *brisk_kernel_timer_ce;
zend_class_entry *brisk_kernel_toolkit_ce;
zend_class_entry *brisk_kernel_trace_ce;
zend_class_entry *brisk_router_driver_classic_ce;
zend_class_entry *brisk_router_driver_native_ce;
zend_class_entry *brisk_router_driver_rewrite_ce;
zend_class_entry *brisk_router_routeradapter_ce;
zend_class_entry *brisk_session_driver_filecache_ce;
zend_class_entry *brisk_session_driver_files_ce;
zend_class_entry *brisk_session_driver_memcached_ce;
zend_class_entry *brisk_session_driver_redis_ce;
zend_class_entry *brisk_session_sessionadapter_ce;
zend_class_entry *brisk_session_userhandler_ce;
zend_class_entry *brisk_sql_delete_mysql_ce;
zend_class_entry *brisk_sql_delete_oci_ce;
zend_class_entry *brisk_sql_delete_pgsql_ce;
zend_class_entry *brisk_sql_delete_sqlite_ce;
zend_class_entry *brisk_sql_delete_sqlsrv_ce;
zend_class_entry *brisk_sql_insert_mysql_ce;
zend_class_entry *brisk_sql_insert_oci_ce;
zend_class_entry *brisk_sql_insert_pgsql_ce;
zend_class_entry *brisk_sql_insert_sqlite_ce;
zend_class_entry *brisk_sql_insert_sqlsrv_ce;
zend_class_entry *brisk_sql_select_mysql_ce;
zend_class_entry *brisk_sql_select_oci_ce;
zend_class_entry *brisk_sql_select_pgsql_ce;
zend_class_entry *brisk_sql_select_sqlite_ce;
zend_class_entry *brisk_sql_select_sqlsrv_ce;
zend_class_entry *brisk_sql_sqlbuilder_ce;
zend_class_entry *brisk_sql_update_mysql_ce;
zend_class_entry *brisk_sql_update_oci_ce;
zend_class_entry *brisk_sql_update_pgsql_ce;
zend_class_entry *brisk_sql_update_sqlite_ce;
zend_class_entry *brisk_sql_update_sqlsrv_ce;
zend_class_entry *brisk_view_driver_native_ce;
zend_class_entry *brisk_view_viewadapter_ce;

ZEND_DECLARE_MODULE_GLOBALS(brisk)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(brisk)
{
// TODO: Deprecated. Will be removed in future
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Brisk_Sql_SqlFather);
	ZEPHIR_INIT(Brisk_Exception_RuntimeException);
	ZEPHIR_INIT(Brisk_Db_DbFather);
	ZEPHIR_INIT(Brisk_Db_Driver_PdoFather);
	ZEPHIR_INIT(Brisk_Sql_Delete);
	ZEPHIR_INIT(Brisk_Sql_Insert);
	ZEPHIR_INIT(Brisk_Sql_Select);
	ZEPHIR_INIT(Brisk_Sql_Update);
	ZEPHIR_INIT(Brisk_Session_SessionFather);
	ZEPHIR_INIT(Brisk_Cache_CacheFather);
	ZEPHIR_INIT(Brisk_Router_RouterFather);
	ZEPHIR_INIT(Brisk_View_ViewFather);
	ZEPHIR_INIT(Brisk_Cache_CacheAdapter);
	ZEPHIR_INIT(Brisk_Cache_CacheProxy);
	ZEPHIR_INIT(Brisk_Cache_Driver_File);
	ZEPHIR_INIT(Brisk_Cache_Driver_Memcached);
	ZEPHIR_INIT(Brisk_Cache_Driver_Redis);
	ZEPHIR_INIT(Brisk_Db_DQuery);
	ZEPHIR_INIT(Brisk_Db_DbAdapter);
	ZEPHIR_INIT(Brisk_Db_Driver_Pdo_Mysql);
	ZEPHIR_INIT(Brisk_Db_Driver_Pdo_Oci);
	ZEPHIR_INIT(Brisk_Db_Driver_Pdo_Pgsql);
	ZEPHIR_INIT(Brisk_Db_Driver_Pdo_Sqlite);
	ZEPHIR_INIT(Brisk_Db_Driver_Pdo_Sqlsrv);
	ZEPHIR_INIT(Brisk_Exception_ActionNotFoundException);
	ZEPHIR_INIT(Brisk_Exception_ClassNotFoundException);
	ZEPHIR_INIT(Brisk_Exception_ConfigurationException);
	ZEPHIR_INIT(Brisk_Exception_ControllerException);
	ZEPHIR_INIT(Brisk_Exception_ControllerNotFoundException);
	ZEPHIR_INIT(Brisk_Exception_DbException);
	ZEPHIR_INIT(Brisk_Exception_DriverNotFoundException);
	ZEPHIR_INIT(Brisk_Exception_EventException);
	ZEPHIR_INIT(Brisk_Exception_MethodNotFoundException);
	ZEPHIR_INIT(Brisk_Exception_PdoException);
	ZEPHIR_INIT(Brisk_Exception_RouterException);
	ZEPHIR_INIT(Brisk_Exception_SqlCompileException);
	ZEPHIR_INIT(Brisk_Http_Request);
	ZEPHIR_INIT(Brisk_Http_Response);
	ZEPHIR_INIT(Brisk_Kernel_App);
	ZEPHIR_INIT(Brisk_Kernel_Config);
	ZEPHIR_INIT(Brisk_Kernel_Container);
	ZEPHIR_INIT(Brisk_Kernel_Event);
	ZEPHIR_INIT(Brisk_Kernel_Handler);
	ZEPHIR_INIT(Brisk_Kernel_Language);
	ZEPHIR_INIT(Brisk_Kernel_Loader);
	ZEPHIR_INIT(Brisk_Kernel_Server);
	ZEPHIR_INIT(Brisk_Kernel_Timer);
	ZEPHIR_INIT(Brisk_Kernel_Toolkit);
	ZEPHIR_INIT(Brisk_Kernel_Trace);
	ZEPHIR_INIT(Brisk_Router_Driver_Classic);
	ZEPHIR_INIT(Brisk_Router_Driver_Native);
	ZEPHIR_INIT(Brisk_Router_Driver_Rewrite);
	ZEPHIR_INIT(Brisk_Router_RouterAdapter);
	ZEPHIR_INIT(Brisk_Session_Driver_FileCache);
	ZEPHIR_INIT(Brisk_Session_Driver_Files);
	ZEPHIR_INIT(Brisk_Session_Driver_Memcached);
	ZEPHIR_INIT(Brisk_Session_Driver_Redis);
	ZEPHIR_INIT(Brisk_Session_SessionAdapter);
	ZEPHIR_INIT(Brisk_Session_UserHandler);
	ZEPHIR_INIT(Brisk_Sql_Delete_Mysql);
	ZEPHIR_INIT(Brisk_Sql_Delete_Oci);
	ZEPHIR_INIT(Brisk_Sql_Delete_Pgsql);
	ZEPHIR_INIT(Brisk_Sql_Delete_Sqlite);
	ZEPHIR_INIT(Brisk_Sql_Delete_Sqlsrv);
	ZEPHIR_INIT(Brisk_Sql_Insert_Mysql);
	ZEPHIR_INIT(Brisk_Sql_Insert_Oci);
	ZEPHIR_INIT(Brisk_Sql_Insert_Pgsql);
	ZEPHIR_INIT(Brisk_Sql_Insert_Sqlite);
	ZEPHIR_INIT(Brisk_Sql_Insert_Sqlsrv);
	ZEPHIR_INIT(Brisk_Sql_Select_Mysql);
	ZEPHIR_INIT(Brisk_Sql_Select_Oci);
	ZEPHIR_INIT(Brisk_Sql_Select_Pgsql);
	ZEPHIR_INIT(Brisk_Sql_Select_Sqlite);
	ZEPHIR_INIT(Brisk_Sql_Select_Sqlsrv);
	ZEPHIR_INIT(Brisk_Sql_SqlBuilder);
	ZEPHIR_INIT(Brisk_Sql_Update_Mysql);
	ZEPHIR_INIT(Brisk_Sql_Update_Oci);
	ZEPHIR_INIT(Brisk_Sql_Update_Pgsql);
	ZEPHIR_INIT(Brisk_Sql_Update_Sqlite);
	ZEPHIR_INIT(Brisk_Sql_Update_Sqlsrv);
	ZEPHIR_INIT(Brisk_View_Driver_Native);
	ZEPHIR_INIT(Brisk_View_ViewAdapter);
	

// TODO: Deprecated. Will be removed in future
#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(brisk)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_brisk_globals *brisk_globals TSRMLS_DC)
{
	brisk_globals->initialized = 0;

	/* Memory options */
	brisk_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	brisk_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	brisk_globals->cache_enabled = 1;

	/* Recursive Lock */
	brisk_globals->recursive_lock = 0;

	/* Static cache */
	memset(brisk_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_brisk_globals *brisk_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(brisk)
{
	zend_brisk_globals *brisk_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(brisk_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);
	zephir_initialize_memory(brisk_globals_ptr TSRMLS_CC);

		zephir_init_static_properties_Brisk_Http_Request(TSRMLS_C);
		zephir_init_static_properties_Brisk_Http_Response(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_App(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Event(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Language(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Loader(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Server(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Timer(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Trace(TSRMLS_C);
		zephir_init_static_properties_Brisk_Router_Driver_Classic(TSRMLS_C);
		zephir_init_static_properties_Brisk_Router_Driver_Rewrite(TSRMLS_C);
	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(brisk)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(brisk)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_BRISK_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_BRISK_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_BRISK_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_BRISK_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_BRISK_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(brisk)
{
	php_zephir_init_globals(brisk_globals TSRMLS_CC);
	php_zephir_init_module_globals(brisk_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(brisk)
{
	
}


zend_function_entry php_brisk_functions[] = {
	ZEND_FE_END

};

zend_module_entry brisk_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_BRISK_EXTNAME,
	php_brisk_functions,
	PHP_MINIT(brisk),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(brisk),
#else
	NULL,
#endif
	PHP_RINIT(brisk),
	PHP_RSHUTDOWN(brisk),
	PHP_MINFO(brisk),
	PHP_BRISK_VERSION,
	ZEND_MODULE_GLOBALS(brisk),
	PHP_GINIT(brisk),
	PHP_GSHUTDOWN(brisk),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(brisk),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_BRISK
ZEND_GET_MODULE(brisk)
#endif
