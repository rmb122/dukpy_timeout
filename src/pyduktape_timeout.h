#include "pyduktape_timeout_config.h"
#include "duk_config.h"
#include "duktape.h"
#include <time.h>

typedef struct {
    int module_init_done;
    time_t stop_time;
} pyduktape_timeout_context;

pyduktape_timeout_context *pyduktape_get_timeout(duk_context *ctx);
