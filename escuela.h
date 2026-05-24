#include <stdio.h>
#include <stdlib.h>

#ifndef ESCUELA_H
#define ESCUELA_H

float calcularPromedio(float calificaciones[], int numMaterias) {
    float suma = 0.0;
    for (int i = 0; i < numMaterias; i++) {
        suma += calificaciones[i];
    }
    return suma / numMaterias;
}

#endif 
