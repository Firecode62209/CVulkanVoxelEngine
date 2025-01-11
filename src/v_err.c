#include "v_err.h"

int VERR_EXIT_CODE = 0;
char** VERR_LOG = NULL;
jmp_buf VERR_ENVIORNMENT;

void throw_verr(VErrLevel level, char* message) {
    switch (level) {
        case VERR_LEVEL_INFO:
            arrpush(VERR_LOG, "|INFO| ");
            break;
        case VERR_LEVEL_WARN:
            arrpush(VERR_LOG, "!WARN! ");
            if (VERR_EXIT_CODE < 1) VERR_EXIT_CODE = 1;
            break;
        case VERR_LEVEL_ERROR:
            arrpush(VERR_LOG, "*ERROR* ");
            if (VERR_EXIT_CODE < 2) VERR_EXIT_CODE = 2;
            break;
        default:
            break;
    }
    arrpush(VERR_LOG, message);
    arrpush(VERR_LOG, "\n");

    if (level == VERR_LEVEL_ERROR) longjmp(VERR_ENVIORNMENT, VERR_EXIT_CODE);
}

int verr_log() {
    for(int i = 0; i < arrlen(VERR_LOG); i++) {
        printf("%s", VERR_LOG[i]);
    }
    arrfree(VERR_LOG);
    VERR_LOG = NULL;
    return VERR_EXIT_CODE;
}
