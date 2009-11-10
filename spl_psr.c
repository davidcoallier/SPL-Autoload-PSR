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

PHP_FUNCTION(spl_autoload_psr)
{
	RETURN_TRUE;;
}
