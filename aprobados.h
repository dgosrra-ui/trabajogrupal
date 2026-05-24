#ifndef APROBADOS_H
#define APROBADOS_H

#include <stdio.h>

int verificarAprobacion(float *promedio) {
    if (*promedio >= 6) {
        printf("El estudiante aprueba.\n");
    } else {
        printf("El estudiante reprueba.\n");
    }
    return 0;
}

#endif
