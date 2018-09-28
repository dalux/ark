
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_BRISK_H
#define PHP_BRISK_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_BRISK_NAME        "brisk"
#define PHP_BRISK_VERSION     "1.0.0"
#define PHP_BRISK_EXTNAME     "brisk"
#define PHP_BRISK_AUTHOR      "guodalu <112183883@qq.com>"
#define PHP_BRISK_ZEPVERSION  "0.10.10"
#define PHP_BRISK_DESCRIPTION "Brisk PHP Framework."



ZEND_BEGIN_MODULE_GLOBALS(brisk)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(brisk)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(brisk)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(brisk_globals_id, zend_brisk_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (brisk_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_brisk_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(brisk_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(brisk_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def brisk_globals
#define zend_zephir_globals_def zend_brisk_globals

extern zend_module_entry brisk_module_entry;
#define phpext_brisk_ptr &brisk_module_entry

#endif
