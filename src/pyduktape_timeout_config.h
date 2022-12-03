#define DUK_USE_INTERRUPT_COUNTER 1
#define DUK_USE_EXEC_TIMEOUT_CHECK pyduktape_stopped

int pyduktape_stopped(void* heap_udata);