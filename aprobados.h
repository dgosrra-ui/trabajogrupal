#ifndef APROBADOS_H
#define APROBADOS_H

#include <stdio.h>

typedef struct {
    char nombre[50];
    float calificaciones[3];
} Alumno;

int verificarAprobacion(Alumno *alumno) {
    float promedio = calcularPromedio(alumno->calificaciones, 3);
    if (promedio >= 6) {
        printf("El estudiante aprueba.\n");
    } else {
        printf("El estudiante reprueba.\n");
    }
    return 0;
}

#endif
