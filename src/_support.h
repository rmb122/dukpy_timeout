#ifndef __DUKPY_SUPPORT_H__
#define __DUKPY_SUPPORT_H__

#include "pyduktape_timeout.h"

extern __thread PyThreadState *pyduktape_save;

duk_ret_t stack_json_encode(duk_context *ctx, void *ptr);
void duktape_fatal_error_handler(void *ctx, const char *msg);
duk_context *get_context_from_capsule(PyObject* pyctx);
PyObject *make_capsule_for_context(duk_context *ctx);
int call_py_function(duk_context *ctx);
int require_set_module_id(duk_context *ctx);

#if PY_MAJOR_VERSION >= 3
#define CONDITIONAL_PY3(three, two) (three)
#else
#define CONDITIONAL_PY3(three, two) (two)
#endif


#endif
