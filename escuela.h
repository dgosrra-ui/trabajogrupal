#include <stdio.h>
#include <stdlib.h>

#ifndef ESCUELA_H
#define ESCUELA_H
typedef struct {
    int numAlumnos;
    int numMaterias;
    float *calificaciones;
} Escuela;

float calcularPromedio(float *calificaciones, int numMaterias) {
    float suma = 0.0;
    for (int i = 0; i < numMaterias; i++) {
        suma += *(calificaciones + i);
    }
    return suma / numMaterias;
}

float calcularPromedioTotal(float *calificaciones, int numAlumnos, int numMaterias) {
    float sumaTotal = 0.0;
    for (int i = 0; i < numAlumnos; i++) {
        for (int j = 0; j < numMaterias; j++) {
            sumaTotal += *(calificaciones + i * numMaterias + j);
        }
    }
    return sumaTotal / (numAlumnos * numMaterias);
}

#endif
