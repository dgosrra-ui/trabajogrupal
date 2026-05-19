#include <stdio.h>

int main() {
    int numAlumnos, numMaterias;
    
    printf("Ingrese el número de alumnos: ");
    scanf("%d", &numAlumnos);
    
    
    float calificaciones[numAlumnos][numMaterias];
    numMaterias = 3;
    
    for (int i = 0; i < numAlumnos; i++) {
        for (int j = 0; j < numMaterias; j++) {
            printf("Ingrese la calificación del alumno %d en la materia %d: ", i + 1, j + 1);
            scanf("%f", &calificaciones[i][j]);
        }
    }
    
    
    return 0;
}