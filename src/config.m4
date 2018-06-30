PHP_ARG_ENABLE(brisk, whether to enable brisk, [ --enable-brisk   Enable Brisk])

if test "$PHP_BRISK" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, BRISK_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_BRISK, 1, [Whether you have Brisk])
	brisk_sources="brisk.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c brisk/toolkit/sqlbuilder/builderfather.zep.c
	brisk/exception/runtimeexception.zep.c
	brisk/contract/idatabase.zep.c
	brisk/database/databasefather.zep.c
	brisk/database/pdodriver.zep.c
	brisk/toolkit/sqlbuilder/deletebuilder.zep.c
	brisk/toolkit/sqlbuilder/insertbuilder.zep.c
	brisk/toolkit/sqlbuilder/selectbuilder.zep.c
	brisk/toolkit/sqlbuilder/updatebuilder.zep.c
	brisk/contract/icache.zep.c
	brisk/contract/irouter.zep.c
	brisk/contract/isession.zep.c
	brisk/cache/cachefather.zep.c
	brisk/contract/iview.zep.c
	brisk/router/routerfather.zep.c
	brisk/session/sessionfather.zep.c
	brisk/view/viewfather.zep.c
	brisk/cache/filecache.zep.c
	brisk/cache/memcache.zep.c
	brisk/database/databasetoolkit.zep.c
	brisk/database/pdodriver/mysql.zep.c
	brisk/database/pdodriver/oci.zep.c
	brisk/database/pdodriver/pgsql.zep.c
	brisk/database/pdodriver/sqlite.zep.c
	brisk/database/pdodriver/sqlsrv.zep.c
	brisk/exception/cacheexception.zep.c
	brisk/exception/databaseexception.zep.c
	brisk/exception/eventexception.zep.c
	brisk/exception/kernelexception.zep.c
	brisk/exception/proxyexception.zep.c
	brisk/exception/routerexception.zep.c
	brisk/exception/sessionexception.zep.c
	brisk/exception/toolkitexception.zep.c
	brisk/exception/viewexception.zep.c
	brisk/kernel/adapter.zep.c
	brisk/kernel/app.zep.c
	brisk/kernel/config.zep.c
	brisk/kernel/container.zep.c
	brisk/kernel/event.zep.c
	brisk/kernel/handler.zep.c
	brisk/kernel/language.zep.c
	brisk/kernel/loader.zep.c
	brisk/kernel/request.zep.c
	brisk/kernel/response.zep.c
	brisk/kernel/server.zep.c
	brisk/kernel/timer.zep.c
	brisk/kernel/toolkit.zep.c
	brisk/kernel/trace.zep.c
	brisk/proxy/cacheproxy.zep.c
	brisk/router/classicrouter.zep.c
	brisk/router/rewriterouter.zep.c
	brisk/session/filesession.zep.c
	brisk/session/usersession.zep.c
	brisk/toolkit/querier.zep.c
	brisk/toolkit/sqlbuilder.zep.c
	brisk/toolkit/sqlbuilder/deletebuilder/mysql.zep.c
	brisk/toolkit/sqlbuilder/deletebuilder/oci.zep.c
	brisk/toolkit/sqlbuilder/deletebuilder/pgsql.zep.c
	brisk/toolkit/sqlbuilder/deletebuilder/sqlite.zep.c
	brisk/toolkit/sqlbuilder/deletebuilder/sqlsrv.zep.c
	brisk/toolkit/sqlbuilder/insertbuilder/mysql.zep.c
	brisk/toolkit/sqlbuilder/insertbuilder/oci.zep.c
	brisk/toolkit/sqlbuilder/insertbuilder/pgsql.zep.c
	brisk/toolkit/sqlbuilder/insertbuilder/sqlite.zep.c
	brisk/toolkit/sqlbuilder/insertbuilder/sqlsrv.zep.c
	brisk/toolkit/sqlbuilder/selectbuilder/mysql.zep.c
	brisk/toolkit/sqlbuilder/selectbuilder/oci.zep.c
	brisk/toolkit/sqlbuilder/selectbuilder/pgsql.zep.c
	brisk/toolkit/sqlbuilder/selectbuilder/sqlite.zep.c
	brisk/toolkit/sqlbuilder/selectbuilder/sqlsrv.zep.c
	brisk/toolkit/sqlbuilder/updatebuilder/mysql.zep.c
	brisk/toolkit/sqlbuilder/updatebuilder/oci.zep.c
	brisk/toolkit/sqlbuilder/updatebuilder/pgsql.zep.c
	brisk/toolkit/sqlbuilder/updatebuilder/sqlite.zep.c
	brisk/toolkit/sqlbuilder/updatebuilder/sqlsrv.zep.c
	brisk/view/nativeview.zep.c "
	PHP_NEW_EXTENSION(brisk, $brisk_sources, $ext_shared,, )
	PHP_SUBST(BRISK_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([brisk], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([brisk], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/brisk], [php_BRISK.h])

fi
