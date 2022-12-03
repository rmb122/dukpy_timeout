#include "pyduktape_timeout.h"
#include <stdio.h>

pyduktape_timeout_context *pyduktape_get_timeout(duk_context *ctx) {
    duk_memory_functions funcs;
    duk_get_memory_functions(ctx, &funcs);
    return (pyduktape_timeout_context *) funcs.udata;
}

int pyduktape_stopped(void* heap_udata) {
    pyduktape_timeout_context *timeout_ctx = (pyduktape_timeout_context *) heap_udata;
    // skip check when module not init yet

    if (timeout_ctx->module_init_done && timeout_ctx->stop_time != 0 && time(NULL) > timeout_ctx->stop_time) {
        // stop duktape when time up
        return 1;
    } else {
        return 0;
    }
}
