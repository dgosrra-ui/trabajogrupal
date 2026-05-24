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
//inclusion del calculo del promedio total
float calcularPromedioTotal(float calificaciones[][3], int numAlumnos, int numMaterias) {
    float sumaTotal = 0.0;
    for (int i = 0; i < numAlumnos; i++) {
        for (int j = 0; j < numMaterias; j++) {
            sumaTotal += calificaciones[i][j];
        }
    }
    return sumaTotal / (numAlumnos * numMaterias);
}