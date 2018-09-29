PHP_ARG_ENABLE(brisk, whether to enable brisk, [ --enable-brisk   Enable Brisk])

if test "$PHP_BRISK" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, BRISK_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_BRISK, 1, [Whether you have Brisk])
	brisk_sources="brisk.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c brisk/vendor/querier/querierfather.zep.c
	brisk/exception/runtimeexception.zep.c
	brisk/vendor/querier/delete.zep.c
	brisk/vendor/querier/insert.zep.c
	brisk/vendor/querier/select.zep.c
	brisk/vendor/querier/update.zep.c
	brisk/vendor/cache/cachefather.zep.c
	brisk/kernel/router/routerfather.zep.c
	brisk/vendor/database/dbfather.zep.c
	brisk/vendor/view/viewfather.zep.c
	brisk/exception/actionnotfoundexception.zep.c
	brisk/exception/classnotfoundexception.zep.c
	brisk/exception/configurationexception.zep.c
	brisk/exception/controllerexception.zep.c
	brisk/exception/controllernotfoundexception.zep.c
	brisk/exception/drivernotfoundexception.zep.c
	brisk/exception/eventexception.zep.c
	brisk/exception/methodnotfoundexception.zep.c
	brisk/exception/pdoexception.zep.c
	brisk/exception/routerexception.zep.c
	brisk/kernel/app.zep.c
	brisk/kernel/config.zep.c
	brisk/kernel/container.zep.c
	brisk/kernel/event.zep.c
	brisk/kernel/handler.zep.c
	brisk/kernel/language.zep.c
	brisk/kernel/loader.zep.c
	brisk/kernel/request.zep.c
	brisk/kernel/router/classic.zep.c
	brisk/kernel/router/rewrite.zep.c
	brisk/kernel/router/routeradapter.zep.c
	brisk/kernel/server.zep.c
	brisk/kernel/session.zep.c
	brisk/kernel/timer.zep.c
	brisk/kernel/toolkit.zep.c
	brisk/kernel/trace.zep.c
	brisk/vendor/cache/cacheadapter.zep.c
	brisk/vendor/cache/cacheproxy.zep.c
	brisk/vendor/cache/file.zep.c
	brisk/vendor/cache/memcached.zep.c
	brisk/vendor/cache/redis.zep.c
	brisk/vendor/database/dbadapter.zep.c
	brisk/vendor/database/dbquerier.zep.c
	brisk/vendor/database/dbtoolkit.zep.c
	brisk/vendor/database/pdo.zep.c
	brisk/vendor/querier/delete/mysql.zep.c
	brisk/vendor/querier/delete/oci.zep.c
	brisk/vendor/querier/delete/pgsql.zep.c
	brisk/vendor/querier/delete/sqlite.zep.c
	brisk/vendor/querier/delete/sqlsrv.zep.c
	brisk/vendor/querier/insert/mysql.zep.c
	brisk/vendor/querier/insert/oci.zep.c
	brisk/vendor/querier/insert/pgsql.zep.c
	brisk/vendor/querier/insert/sqlite.zep.c
	brisk/vendor/querier/insert/sqlsrv.zep.c
	brisk/vendor/querier/querieradapter.zep.c
	brisk/vendor/querier/select/mysql.zep.c
	brisk/vendor/querier/select/oci.zep.c
	brisk/vendor/querier/select/pgsql.zep.c
	brisk/vendor/querier/select/sqlite.zep.c
	brisk/vendor/querier/select/sqlsrv.zep.c
	brisk/vendor/querier/update/mysql.zep.c
	brisk/vendor/querier/update/oci.zep.c
	brisk/vendor/querier/update/pgsql.zep.c
	brisk/vendor/querier/update/sqlite.zep.c
	brisk/vendor/querier/update/sqlsrv.zep.c
	brisk/vendor/view/native.zep.c
	brisk/vendor/view/viewadapter.zep.c "
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
