#ifndef VERR_H
#define VERR_H

#include <stdio.h>
#include <stdlib.h>
#include "stb_ds.h"
#include <setjmp.h>
#include <string.h>

extern char** VERR_LOG;
extern int VERR_EXIT_CODE;
extern jmp_buf VERR_ENVIORNMENT;

typedef enum VErrLevel {
    VERR_LEVEL_INFO,
    VERR_LEVEL_WARN,
    VERR_LEVEL_ERROR
} VErrLevel;

void throw_verr(VErrLevel level, char* message);
void set_verr_enviornment();
int verr_log();

#endif