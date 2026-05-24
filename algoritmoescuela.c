#include <stdio.h>
#include <stdlib.h>
#include "escuela.h"        
#include "aprobados.h"
int main(void) {
    int numAlumnos, numMaterias;
    
    printf("Ingrese el número de alumnos: ");
    scanf("%d", &numAlumnos);
    
    numMaterias = 3;
    float calificaciones[numAlumnos][numMaterias];
    // Ingreso de calificaciones
    
    for (int i = 0; i < numAlumnos; i++) {
        for (int j = 0; j < numMaterias; j++) {
            printf("Ingrese la calificación del alumno %d en la materia %d: ", i + 1, j + 1);
            scanf("%f", &calificaciones[i][j]);
        }
    }
     //calculo de calificaciones mas alta y mas baja      
    printf("\nCalificaciones mas alta :\n");
    for (int i = 0; i < numAlumnos; i++) {
        float maxCalificacion = calificaciones[i][0];
        for (int j = 1; j < numMaterias; j++) {
            if (calificaciones[i][j] > maxCalificacion) {
                maxCalificacion = calificaciones[i][j];
            }
        }
        printf("Alumno %d: %.2f\n", i + 1, maxCalificacion);
    }
    printf("\nCalificaciones mas baja :\n");
    for (int i = 0; i < numAlumnos; i++) {
        float minCalificacion = calificaciones[i][0];
        for (int j = 1; j < numMaterias; j++) {
            if (calificaciones[i][j] < minCalificacion) {
                minCalificacion = calificaciones[i][j];
            }
        }
        printf("Alumno %d: %.2f\n", i + 1, minCalificacion);
    }
    //calculo mediante la funcion <escuela.h>
    printf("\nPromedio de calificaciones:\n");
    for (int i = 0; i < numAlumnos; i++) {
        float promedio = calcularPromedio(calificaciones[i], numMaterias);
        printf("Alumno %d: %.2f\n", i + 1, promedio);

    }
    //calculo del promedio total
    float promedioTotal = calcularPromedioTotal(calificaciones, numAlumnos, numMaterias);
    printf("\nPromedio total: %.2f\n", promedioTotal);
    //calculo de aprobados y reprobados mediante el uso de la funcion <aprobados.h>
    printf("\nResultados de los estudiantes:\n");
    for (int i = 0; i < numAlumnos; i++) {  
        float promedio = calcularPromedio(calificaciones[i], numMaterias);
        printf("Alumno %d: ", i + 1);
        verificarAprobacion(promedio);
    }
    printf("\n----------------------------------------------------------------------------------\n");
 printf("| Alumno | Materia1 | Materia2 | Materia3 | Promedio |\n");
 printf("----------------------------------------------------------------------------------\n");

 for (int i = 0; i < numAlumnos; i++) {

    float promedio = calcularPromedio(calificaciones[i], numMaterias);

    printf("|   %2d    ", i + 1);

    for (int j = 0; j < numMaterias; j++) {
        printf("|   %6.2f  ", calificaciones[i][j]);
    }

    printf("|   %6.2f |\n", promedio);

    printf("----------------------------------------------------------------------------------\n");
}

 printf("| Promedio Total                                         |   %6.2f |\n", promedioTotal);
 printf("----------------------------------------------------------------------------------\n");

    return 0;
}