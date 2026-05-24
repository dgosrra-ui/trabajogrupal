#include <stdio.h>
#include <stdlib.h>

int main() {
    int numAlumnos, numMaterias;
    
    printf("Ingrese el número de alumnos: ");
    scanf("%d", &numAlumnos);
    
    numMaterias = 3;
    float calificaciones[numAlumnos][numMaterias];
    
    
    for (int i = 0; i < numAlumnos; i++) {
        for (int j = 0; j < numMaterias; j++) {
            printf("Ingrese la calificación del alumno %d en la materia %d: ", i + 1, j + 1);
            scanf("%f", &calificaciones[i][j]);
        }
    }
           
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

    return 0;
}