/*
   +----------------------------------------------------------------------+
   | PHP Version 7                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2017 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Andi Gutmans <andi@zend.com>                                |
   |          Zeev Suraski <zeev@zend.com>                                |
   +----------------------------------------------------------------------+
 */

/* $Id$ */

#ifndef PHP_MAIN_H
#define PHP_MAIN_H

#include "zend_globals.h"
#include "php_globals.h"
#include "SAPI.h"

BEGIN_EXTERN_C()
PHPAPI int php_request_startup(void);
PHPAPI void php_request_shutdown(void *dummy);
PHPAPI void php_request_shutdown_for_exec(void *dummy);
PHPAPI int php_module_startup(sapi_module_struct *sf, zend_module_entry *additional_modules, uint32_t num_additional_modules);
PHPAPI void php_module_shutdown(void);
PHPAPI void php_module_shutdown_for_exec(void);
PHPAPI int php_module_shutdown_wrapper(sapi_module_struct *sapi_globals);

PHPAPI int php_register_extensions(zend_module_entry * const * ptr, int count);

PHPAPI int php_execute_script(zend_file_handle *primary_file);
PHPAPI int php_execute_simple_script(zend_file_handle *primary_file, zval *ret);
PHPAPI int php_handle_special_queries(void);
PHPAPI int php_lint_script(zend_file_handle *file);

PHPAPI void php_handle_aborted_connection(void);
PHPAPI int php_handle_auth_data(const char *auth);

PHPAPI void php_html_puts(const char *str, size_t siz);
PHPAPI int php_stream_open_for_zend_ex(const char *filename, zend_file_handle *handle, int mode);

/* environment module */
extern int php_init_environ(void);
extern int php_shutdown_environ(void);
END_EXTERN_C()

#endif
/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 fdm=marker
 * vim<600: sw=4 ts=4
 */
