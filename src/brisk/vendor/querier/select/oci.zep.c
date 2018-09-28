
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Brisk_Vendor_Querier_Select_Oci) {

	ZEPHIR_REGISTER_CLASS_EX(Brisk\\Vendor\\Querier\\Select, Oci, brisk, vendor_querier_select_oci, brisk_vendor_querier_select_ce, brisk_vendor_querier_select_oci_method_entry, 0);

	zend_declare_property_string(brisk_vendor_querier_select_oci_ce, SL("_db_type"), "oci", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Brisk_Vendor_Querier_Select_Oci, pickLimitPart) {

	

	RETURN_NULL();

}

/**
 * Get the full sql statement
 *
 * @return string
 */
PHP_METHOD(Brisk_Vendor_Querier_Select_Oci, getSQL) {

	zval *select = NULL, *where$$3 = NULL, *group$$3 = NULL, *having$$3 = NULL, *order$$3 = NULL, *limit$$3 = NULL, *_4$$3, *_0$$4, *_1$$5, *_2$$6, *_3$$7, *offset$$8 = NULL, *_5$$8, _6$$9, _7$$9, *_8$$9 = NULL, _10$$10, *_11$$10 = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&select, this_ptr, "pickselectpart", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(select, "")) {
		ZEPHIR_CALL_METHOD(&where$$3, this_ptr, "pickwherepart", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&group$$3, this_ptr, "pickgrouppart", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&having$$3, this_ptr, "pickhavingpart", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&order$$3, this_ptr, "pickorderpart", NULL, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING(where$$3, "")) {
			ZEPHIR_INIT_VAR(_0$$4);
			ZEPHIR_CONCAT_VSV(_0$$4, select, " WHERE ", where$$3);
			ZEPHIR_CPY_WRT(select, _0$$4);
		}
		if (!ZEPHIR_IS_STRING(group$$3, "")) {
			ZEPHIR_INIT_VAR(_1$$5);
			ZEPHIR_CONCAT_VSV(_1$$5, select, " GROUP BY ", group$$3);
			ZEPHIR_CPY_WRT(select, _1$$5);
		}
		if (!ZEPHIR_IS_STRING(having$$3, "")) {
			ZEPHIR_INIT_VAR(_2$$6);
			ZEPHIR_CONCAT_VSV(_2$$6, select, " HAVING ", having$$3);
			ZEPHIR_CPY_WRT(select, _2$$6);
		}
		if (!ZEPHIR_IS_STRING(order$$3, "")) {
			ZEPHIR_INIT_VAR(_3$$7);
			ZEPHIR_CONCAT_VSV(_3$$7, select, " ORDER BY ", order$$3);
			ZEPHIR_CPY_WRT(select, _3$$7);
		}
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(limit$$3);
		zephir_array_fetch_string(&limit$$3, _4$$3, SL("limit"), PH_NOISY, "brisk/Vendor/Querier/Select/Oci.zep", 43 TSRMLS_CC);
		if (!ZEPHIR_IS_STRING(limit$$3, "")) {
			_5$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_parts"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(offset$$8);
			zephir_array_fetch_string(&offset$$8, _5$$8, SL("offset"), PH_NOISY, "brisk/Vendor/Querier/Select/Oci.zep", 46 TSRMLS_CC);
			if (!ZEPHIR_IS_STRING(offset$$8, "")) {
				ZEPHIR_SINIT_VAR(_6$$9);
				zephir_add_function(&_6$$9, offset$$8, limit$$3);
				ZEPHIR_SINIT_VAR(_7$$9);
				ZVAL_STRING(&_7$$9, "select * from (select tmptable1.*, rownum tmprn from (%s) tmptable1 where rownum<=%u) where tmprn>%u", 0);
				ZEPHIR_CALL_FUNCTION(&_8$$9, "sprintf", &_9, 40, &_7$$9, select, &_6$$9, offset$$8);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(select, _8$$9);
			} else {
				ZEPHIR_SINIT_VAR(_10$$10);
				ZVAL_STRING(&_10$$10, "select tmptable1.* from (%s) tmptable1 where rownum<=%u", 0);
				ZEPHIR_CALL_FUNCTION(&_11$$10, "sprintf", &_9, 40, &_10$$10, select, limit$$3);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(select, _11$$10);
			}
		}
		RETURN_CCTOR(select);
	}
	RETURN_MM_NULL();

}

