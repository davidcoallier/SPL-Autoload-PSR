/*
   +----------------------------------------------------------------------+
   | PHP Version 6                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2009 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Marcus Boerger <helly@php.net>                              |
   +----------------------------------------------------------------------+
 */

#ifndef PHP_SPL_PSR_H
#define PHP_SPL_PSR_H

#define PHP_SPL_AUTOLOAD_PSR_VERSION "0.1.0"
#define PHP_SPL_AUTOLOAD_PSR_EXTNAME "SPL Autoload PSR"

PHP_FUNCTION(spl_autoload_psr);

extern zend_module_entry spl_autoload_psr_module_entry;
#define phpext_spl_autoload_psr &spl_autoload_psr_module_entry

