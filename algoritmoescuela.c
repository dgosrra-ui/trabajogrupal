#include <stdio.h>
#include <stdlib.h>
#include "escuela.h"        
#include "aprobados.h"
//implementacion de struct 
typedef struct algoritmoescuela
{
    int numAlumnos;
    int numMaterias;
    float *calificaciones;
} algoritmoescuela;
typedef struct alumno
{
    char nombre[50];
    float calificaciones[3];
} alumno;
int main(void) {
    int numAlumnos, numMaterias;
    
    printf("Ingrese el número de alumnos: ");
    scanf("%d", &numAlumnos);
    //inclusion de estructuras en los punteros
    algoritmoescuela escuela;
    escuela.numAlumnos = numAlumnos;
    escuela.numMaterias = 3;
    escuela.calificaciones = (float *)malloc(numAlumnos * 3 * sizeof(float));
    float *pCalif = escuela.calificaciones;
    // Ingreso de calificaciones
    
    for (int i = 0; i < numAlumnos; i++) {
        float *fila = pCalif + i * numMaterias;
        for (int j = 0; j < numMaterias; j++) {
            printf("Ingrese la calificación del alumno %d en la materia %d: ", i + 1, j + 1);
            scanf("%f", fila + j);
        }
    }
     //calculo de calificaciones mas alta y mas baja      
    printf("\nCalificaciones mas alta :\n");
    for (int i = 0; i < numAlumnos; i++) {
        float *fila = pCalif + i * numMaterias;
        float maxCalificacion = *fila;
        for (int j = 1; j < numMaterias; j++) {
            if (*(fila + j) > maxCalificacion) {
                maxCalificacion = *(fila + j);
            }
        }
        printf("Alumno %d: %.2f\n", i + 1, maxCalificacion);
    }
    printf("\nCalificaciones mas baja :\n");
    for (int i = 0; i < numAlumnos; i++) {
        float *fila = pCalif + i * numMaterias;
        float minCalificacion = *fila;
        for (int j = 1; j < numMaterias; j++) {
            if (*(fila + j) < minCalificacion) {
                minCalificacion = *(fila + j);
            }
        }
        printf("Alumno %d: %.2f\n", i + 1, minCalificacion);
    }
    //calculo mediante la funcion <escuela.h>
    printf("\nPromedio de calificaciones:\n");
    for (int i = 0; i < numAlumnos; i++) {
        float *fila = pCalif + i * numMaterias;
        float promedio = calcularPromedio(fila, numMaterias);
        printf("Alumno %d: %.2f\n", i + 1, promedio);
    }
    //calculo del promedio total
    float promedioTotal = calcularPromedioTotal(pCalif, numAlumnos, numMaterias);
    printf("\nPromedio total: %.2f\n", promedioTotal);
    //calculo de aprobados y reprobados mediante el uso de la funcion <aprobados.h>
    printf("\nResultados de los estudiantes:\n");
    for (int i = 0; i < numAlumnos; i++) {
        float *fila = pCalif + i * numMaterias;
        float promedio = calcularPromedio(fila, numMaterias);
        printf("Alumno %d: ", i + 1);
        verificarAprobacion(&promedio);
    }
    printf("\n----------------------------------------------------------------------------------\n");
 printf("| Alumno | Materia1 | Materia2 | Materia3 | Promedio |\n");
 printf("----------------------------------------------------------------------------------\n");

 for (int i = 0; i < numAlumnos; i++) {
    float *fila = pCalif + i * numMaterias;
    float promedio = calcularPromedio(fila, numMaterias);

    printf("|   %2d    ", i + 1);

    for (int j = 0; j < numMaterias; j++) {
        printf("|   %6.2f  ", *(fila + j));
    }

    printf("|   %6.2f |\n", promedio);
    printf("----------------------------------------------------------------------------------\n");
}

 printf("| Promedio Total                                         |   %6.2f |\n", promedioTotal);
 printf("----------------------------------------------------------------------------------\n");

    return 0;
}