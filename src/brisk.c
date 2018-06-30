
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

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



zend_class_entry *brisk_contract_idatabase_ce;
zend_class_entry *brisk_contract_icache_ce;
zend_class_entry *brisk_contract_irouter_ce;
zend_class_entry *brisk_contract_isession_ce;
zend_class_entry *brisk_contract_iview_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_builderfather_ce;
zend_class_entry *brisk_exception_runtimeexception_ce;
zend_class_entry *brisk_database_databasefather_ce;
zend_class_entry *brisk_database_pdodriver_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_deletebuilder_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_insertbuilder_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_selectbuilder_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_updatebuilder_ce;
zend_class_entry *brisk_cache_cachefather_ce;
zend_class_entry *brisk_router_routerfather_ce;
zend_class_entry *brisk_session_sessionfather_ce;
zend_class_entry *brisk_view_viewfather_ce;
zend_class_entry *brisk_cache_filecache_ce;
zend_class_entry *brisk_cache_memcache_ce;
zend_class_entry *brisk_database_databasetoolkit_ce;
zend_class_entry *brisk_database_pdodriver_mysql_ce;
zend_class_entry *brisk_database_pdodriver_oci_ce;
zend_class_entry *brisk_database_pdodriver_pgsql_ce;
zend_class_entry *brisk_database_pdodriver_sqlite_ce;
zend_class_entry *brisk_database_pdodriver_sqlsrv_ce;
zend_class_entry *brisk_exception_cacheexception_ce;
zend_class_entry *brisk_exception_databaseexception_ce;
zend_class_entry *brisk_exception_eventexception_ce;
zend_class_entry *brisk_exception_kernelexception_ce;
zend_class_entry *brisk_exception_proxyexception_ce;
zend_class_entry *brisk_exception_routerexception_ce;
zend_class_entry *brisk_exception_sessionexception_ce;
zend_class_entry *brisk_exception_toolkitexception_ce;
zend_class_entry *brisk_exception_viewexception_ce;
zend_class_entry *brisk_kernel_adapter_ce;
zend_class_entry *brisk_kernel_app_ce;
zend_class_entry *brisk_kernel_config_ce;
zend_class_entry *brisk_kernel_container_ce;
zend_class_entry *brisk_kernel_event_ce;
zend_class_entry *brisk_kernel_handler_ce;
zend_class_entry *brisk_kernel_language_ce;
zend_class_entry *brisk_kernel_loader_ce;
zend_class_entry *brisk_kernel_request_ce;
zend_class_entry *brisk_kernel_response_ce;
zend_class_entry *brisk_kernel_server_ce;
zend_class_entry *brisk_kernel_timer_ce;
zend_class_entry *brisk_kernel_toolkit_ce;
zend_class_entry *brisk_kernel_trace_ce;
zend_class_entry *brisk_proxy_cacheproxy_ce;
zend_class_entry *brisk_router_classicrouter_ce;
zend_class_entry *brisk_router_rewriterouter_ce;
zend_class_entry *brisk_session_filesession_ce;
zend_class_entry *brisk_session_usersession_ce;
zend_class_entry *brisk_toolkit_querier_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_deletebuilder_mysql_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_deletebuilder_oci_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_deletebuilder_pgsql_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_deletebuilder_sqlite_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_deletebuilder_sqlsrv_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_insertbuilder_mysql_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_insertbuilder_oci_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_insertbuilder_pgsql_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_insertbuilder_sqlite_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_insertbuilder_sqlsrv_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_selectbuilder_mysql_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_selectbuilder_oci_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_selectbuilder_pgsql_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_selectbuilder_sqlite_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_selectbuilder_sqlsrv_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_updatebuilder_mysql_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_updatebuilder_oci_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_updatebuilder_pgsql_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_updatebuilder_sqlite_ce;
zend_class_entry *brisk_toolkit_sqlbuilder_updatebuilder_sqlsrv_ce;
zend_class_entry *brisk_view_nativeview_ce;

ZEND_DECLARE_MODULE_GLOBALS(brisk)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(brisk)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Brisk_Contract_IDatabase);
	ZEPHIR_INIT(Brisk_Contract_ICache);
	ZEPHIR_INIT(Brisk_Contract_IRouter);
	ZEPHIR_INIT(Brisk_Contract_ISession);
	ZEPHIR_INIT(Brisk_Contract_IView);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_BuilderFather);
	ZEPHIR_INIT(Brisk_Exception_RuntimeException);
	ZEPHIR_INIT(Brisk_Database_DatabaseFather);
	ZEPHIR_INIT(Brisk_Database_PdoDriver);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_DeleteBuilder);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_InsertBuilder);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_SelectBuilder);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_UpdateBuilder);
	ZEPHIR_INIT(Brisk_Cache_CacheFather);
	ZEPHIR_INIT(Brisk_Router_RouterFather);
	ZEPHIR_INIT(Brisk_Session_SessionFather);
	ZEPHIR_INIT(Brisk_View_ViewFather);
	ZEPHIR_INIT(Brisk_Cache_FileCache);
	ZEPHIR_INIT(Brisk_Cache_MemCache);
	ZEPHIR_INIT(Brisk_Database_DatabaseToolkit);
	ZEPHIR_INIT(Brisk_Database_PdoDriver_Mysql);
	ZEPHIR_INIT(Brisk_Database_PdoDriver_Oci);
	ZEPHIR_INIT(Brisk_Database_PdoDriver_Pgsql);
	ZEPHIR_INIT(Brisk_Database_PdoDriver_Sqlite);
	ZEPHIR_INIT(Brisk_Database_PdoDriver_Sqlsrv);
	ZEPHIR_INIT(Brisk_Exception_CacheException);
	ZEPHIR_INIT(Brisk_Exception_DatabaseException);
	ZEPHIR_INIT(Brisk_Exception_EventException);
	ZEPHIR_INIT(Brisk_Exception_KernelException);
	ZEPHIR_INIT(Brisk_Exception_ProxyException);
	ZEPHIR_INIT(Brisk_Exception_RouterException);
	ZEPHIR_INIT(Brisk_Exception_SessionException);
	ZEPHIR_INIT(Brisk_Exception_ToolkitException);
	ZEPHIR_INIT(Brisk_Exception_ViewException);
	ZEPHIR_INIT(Brisk_Kernel_Adapter);
	ZEPHIR_INIT(Brisk_Kernel_App);
	ZEPHIR_INIT(Brisk_Kernel_Config);
	ZEPHIR_INIT(Brisk_Kernel_Container);
	ZEPHIR_INIT(Brisk_Kernel_Event);
	ZEPHIR_INIT(Brisk_Kernel_Handler);
	ZEPHIR_INIT(Brisk_Kernel_Language);
	ZEPHIR_INIT(Brisk_Kernel_Loader);
	ZEPHIR_INIT(Brisk_Kernel_Request);
	ZEPHIR_INIT(Brisk_Kernel_Response);
	ZEPHIR_INIT(Brisk_Kernel_Server);
	ZEPHIR_INIT(Brisk_Kernel_Timer);
	ZEPHIR_INIT(Brisk_Kernel_Toolkit);
	ZEPHIR_INIT(Brisk_Kernel_Trace);
	ZEPHIR_INIT(Brisk_Proxy_CacheProxy);
	ZEPHIR_INIT(Brisk_Router_ClassicRouter);
	ZEPHIR_INIT(Brisk_Router_RewriteRouter);
	ZEPHIR_INIT(Brisk_Session_FileSession);
	ZEPHIR_INIT(Brisk_Session_UserSession);
	ZEPHIR_INIT(Brisk_Toolkit_Querier);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_DeleteBuilder_Mysql);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_DeleteBuilder_Oci);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_DeleteBuilder_Pgsql);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_DeleteBuilder_Sqlite);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_DeleteBuilder_Sqlsrv);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_InsertBuilder_Mysql);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_InsertBuilder_Oci);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_InsertBuilder_Pgsql);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_InsertBuilder_Sqlite);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_InsertBuilder_Sqlsrv);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_SelectBuilder_Mysql);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_SelectBuilder_Oci);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_SelectBuilder_Pgsql);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_SelectBuilder_Sqlite);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_SelectBuilder_Sqlsrv);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_UpdateBuilder_Mysql);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_UpdateBuilder_Oci);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_UpdateBuilder_Pgsql);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_UpdateBuilder_Sqlite);
	ZEPHIR_INIT(Brisk_Toolkit_SQLBuilder_UpdateBuilder_Sqlsrv);
	ZEPHIR_INIT(Brisk_View_NativeView);
	
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
	zend_brisk_globals *brisk_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	brisk_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(brisk_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(brisk_globals_ptr TSRMLS_CC);

		zephir_init_static_properties_Brisk_Kernel_App(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Event(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Language(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Loader(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Request(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Server(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Timer(TSRMLS_C);
		zephir_init_static_properties_Brisk_Kernel_Trace(TSRMLS_C);
		zephir_init_static_properties_Brisk_Router_ClassicRouter(TSRMLS_C);
		zephir_init_static_properties_Brisk_Router_RewriteRouter(TSRMLS_C);
	
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
