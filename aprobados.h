#include <stdio.h>

int verificarAprobacion(float calificacion) {
    
    
    if (calificacion >= 6) {
        printf("El estudiante aprueba.\n");
    } else {
        printf("El estudiante reprueba.\n");
    }
    
    return 0;
}