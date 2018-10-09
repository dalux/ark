PHP_ARG_ENABLE(brisk, whether to enable brisk, [ --enable-brisk   Enable Brisk])

if test "$PHP_BRISK" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, BRISK_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_BRISK, 1, [Whether you have Brisk])
	brisk_sources="brisk.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c brisk/sql/sqlfather.zep.c
	brisk/exception/runtimeexception.zep.c
	brisk/db/dbfather.zep.c
	brisk/db/driver/pdofather.zep.c
	brisk/sql/delete.zep.c
	brisk/sql/insert.zep.c
	brisk/sql/select.zep.c
	brisk/sql/update.zep.c
	brisk/session/sessionfather.zep.c
	brisk/cache/cachefather.zep.c
	brisk/router/routerfather.zep.c
	brisk/view/viewfather.zep.c
	brisk/cache/cacheadapter.zep.c
	brisk/cache/cacheproxy.zep.c
	brisk/cache/driver/file.zep.c
	brisk/cache/driver/memcached.zep.c
	brisk/cache/driver/redis.zep.c
	brisk/db/dquery.zep.c
	brisk/db/dbadapter.zep.c
	brisk/db/driver/pdo/mysql.zep.c
	brisk/db/driver/pdo/oci.zep.c
	brisk/db/driver/pdo/pgsql.zep.c
	brisk/db/driver/pdo/sqlite.zep.c
	brisk/db/driver/pdo/sqlsrv.zep.c
	brisk/exception/actionnotfoundexception.zep.c
	brisk/exception/classnotfoundexception.zep.c
	brisk/exception/configurationexception.zep.c
	brisk/exception/controllerexception.zep.c
	brisk/exception/controllernotfoundexception.zep.c
	brisk/exception/dbexception.zep.c
	brisk/exception/drivernotfoundexception.zep.c
	brisk/exception/eventexception.zep.c
	brisk/exception/methodnotfoundexception.zep.c
	brisk/exception/pdoexception.zep.c
	brisk/exception/routerexception.zep.c
	brisk/exception/sqlcompileexception.zep.c
	brisk/http/request.zep.c
	brisk/http/response.zep.c
	brisk/http/server.zep.c
	brisk/kernel/app.zep.c
	brisk/kernel/config.zep.c
	brisk/kernel/container.zep.c
	brisk/kernel/event.zep.c
	brisk/kernel/handler.zep.c
	brisk/kernel/language.zep.c
	brisk/kernel/loader.zep.c
	brisk/kernel/timer.zep.c
	brisk/kernel/toolkit.zep.c
	brisk/kernel/trace.zep.c
	brisk/router/driver/classic.zep.c
	brisk/router/driver/native.zep.c
	brisk/router/driver/rewrite.zep.c
	brisk/router/routeradapter.zep.c
	brisk/session/driver/filecache.zep.c
	brisk/session/driver/files.zep.c
	brisk/session/driver/memcached.zep.c
	brisk/session/driver/redis.zep.c
	brisk/session/sessionadapter.zep.c
	brisk/session/userhandler.zep.c
	brisk/sql/delete/mysql.zep.c
	brisk/sql/delete/oci.zep.c
	brisk/sql/delete/pgsql.zep.c
	brisk/sql/delete/sqlite.zep.c
	brisk/sql/delete/sqlsrv.zep.c
	brisk/sql/insert/mysql.zep.c
	brisk/sql/insert/oci.zep.c
	brisk/sql/insert/pgsql.zep.c
	brisk/sql/insert/sqlite.zep.c
	brisk/sql/insert/sqlsrv.zep.c
	brisk/sql/select/mysql.zep.c
	brisk/sql/select/oci.zep.c
	brisk/sql/select/pgsql.zep.c
	brisk/sql/select/sqlite.zep.c
	brisk/sql/select/sqlsrv.zep.c
	brisk/sql/sqlbuilder.zep.c
	brisk/sql/update/mysql.zep.c
	brisk/sql/update/oci.zep.c
	brisk/sql/update/pgsql.zep.c
	brisk/sql/update/sqlite.zep.c
	brisk/sql/update/sqlsrv.zep.c
	brisk/view/driver/native.zep.c
	brisk/view/viewadapter.zep.c "
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
