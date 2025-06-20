#include <stdio.h>

int esPrimo(int num) {
	int i ;
    if (num <= 1) return 0; // No son primos 0, 1 y negativos
    for ( i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Si tiene otro divisor, no es primo
    }
    return 1;
}

int main() {
    int numero, opcion;
    int posicionActual = 0;
    int mayor, posMayor = 0;
    int primeraVez = 1;

    // Estadísticas
    int contPrimos = 0, sumaPrimos = 0;
    int contNoPrimos = 0, sumaNoPrimos = 0;

    do {
        printf("\nIngrese un numero entero: ");
        scanf("%i", &numero);
        posicionActual++;

        // Evaluar si es el mayor
        if (primeraVez || numero > mayor) {
            mayor = numero;
            posMayor = posicionActual;
            primeraVez = 0;
        }

        // Evaluar si es primo
        if (esPrimo(numero)) {
            printf("El número %d es un Numero Primo.\n", numero);
            contPrimos++;
            sumaPrimos += numero;
        } else {
            printf("El número %d No es un Numero Primo.\n", numero);
            contNoPrimos++;
            sumaNoPrimos += numero;
        }

        // Repetir
        printf("¿Desea ingresar otro numero? (1 = Si, 0 = No): ");
        scanf("%d", &opcion);

    } while (opcion == 1);

    // Resultados Finales
    printf("\n--- ESTADISTICAS FINALES ---\n");
    printf("Numero Mayor Ingresado: %d en la posicion %d\n", mayor, posMayor);

    if (contPrimos > 0) {
        printf("Cantidad de Numeros Primos: %d\n", contPrimos);
        printf("Sumatoria de los Numeros Primos: %d\n", sumaPrimos);
        printf("Promedio de los Numeros Primos: %.2f\n", sumaPrimos / contPrimos);
    } else {
        printf("No se ingresaron numeros primos.\n");
    }

    if (contNoPrimos > 0) {
        printf("Cantidad de Numeros No Primos: %d\n", contNoPrimos);
        printf("Sumatoria Numeros No Primos: %d\n", sumaNoPrimos);
        printf("Promedio de los Numeros No Primos: %.2f\n", sumaNoPrimos / contNoPrimos);
    } else {
        printf("No se ingresaron numeros no primos.\n");
    }

    return 0;
}

