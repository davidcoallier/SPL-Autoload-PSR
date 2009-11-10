#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_spl_psr.h"

static function_entry spl_autoload_psr_functions[] = {
	PHP_FE(spl_autoload_psr, NULL), 
	{NULL, NULL, NULL}
};

zend_module_entry spl_autoload_psr_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_SPL_AUTOLOAD_PSR_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SPL_AUTOLOAD_PSR
ZEND_GET_MODULE(spl_autoload_psr)
#endif

/* {{{ proto string spl_autoload_psr(string $classname) U
	   proto string spl_autoload_psr(string $classname) U
	Returns the value of the file to load and from where to laod it */
PHP_FUNCTION(spl_autoload_psr)
{
	zval *cname = NULL;
	zval *namespace = NULL, *filename = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", cname) == FAILURE) {
		return;
	}

	if (Z_TYPE_P(cname) == IS_STRING) {

		if (strstr(Z_STRVAL_P(cname), "\\\\") != NULL) {

			ALLOC_INIT_ZVAL(namespace);
			ALLOC_INIT_ZVAL(filename);

			zval ns_strrpos = NULL, ns_strrpos_res = NULL;
			MAKE_STD_ZVAL(ns_strrpos);

			ZVAL_STRING(&ns_strrpos, "strrpos", 0);

			zval **params = NULL;
			zval *param1 = NULL, *param2 = NULL;

			MAKE_STD_ZVAL(param1);
			MAKE_STD_ZVAL(param2);

			ZVAL_STRING(&param1, Z_STRVAL_P(cname), 0);
			ZVAL_STRING(&param2, "\\\\", 0);

			params[0] = param1;
			params[1] = param2;
			
			if (call_user_function_ex(CG(function_table), NULL, &ns_strrpos, &ns_strrpos_res, 2, params, 1, NULL TSRMLS_CC) != FAILURE) {

				Z_STRVAL_P(namespace) = strndup(Z_STRVAL_P(cname), Z_STRVAL(ns_strrpos_res));

				zval cs_strrpos = NULL, cs_strrpos_res = NULL;
				MAKE_STD_ZVAL(cs_strrpos);

				ZVAL_STRING(&cs_strrpos, "strrpos", 0);


				if (call_user_function_ex(CG(function_table), NULL, &cs_strrpos, &cs_strrpos_res, 2, params, 1, NULL TRSMLS_CC) != FAILURE) {
					Z_STRVAL_P(cname) = strndup(Z_STRVAL_P(cname), (int *)Z_STRVAL_P(cs_strrpos_res)+1);

					zval *ret = NULL;
					MAKE_STD_ZVAL(ret);

					Z_STRVAL_P(filename) = sprintf("%s%s", strncpy(Z_STRVAL_P(namespace), "\\\\", "/"), "/");

					RETURN_STRINGL(Z_STRVAL_P(filename), Z_STRLEN_P(filename), 0);
					
				}
			}
		}
	}

	RETURN_FALSE;
} /* }}} */
