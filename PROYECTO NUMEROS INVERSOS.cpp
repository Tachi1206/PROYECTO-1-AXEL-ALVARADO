#include <stdio.h>

int main() {
    int numero, numOriginal, inverso, digito, opcion;

    do {
        // Solicitar el numero con validacion
        do {
            printf("\nIngrese un numero entero (maximo 5 digitos): ");
            scanf("%d", &numero);

            if (numero < 1 || numero > 99999) {
                printf("   POR FAVOR INGRESE UN NUMERO VALIDO ENTRE 1 Y 99999\n");
            }
        } while (numero < 1 || numero > 99999);

        // Guardar copia del numero original
        numOriginal = numero;
        inverso = 0;

        // Calcular el inverso matematicamente
        while (numero > 0) {
            digito = numero % 10;//Cuando divides cualquier número entre 10, el residuo (% 10) siempre será el último dígito.
			inverso = inverso * 10 + digito;
            numero = numero / 10; //Cuando divides un número entero por 10, la parte decimal se descarta automáticamente 
        }

        // Mostrar resultados
        printf("Numero ingresado: %d\n", numOriginal);
        printf("Numero inverso: %d\n", inverso);

        // Preguntar si desea repetir
        printf("\nDesea ingresar otro numero (1 = Si  0 = No): ");
        scanf("%d", &opcion);

    } while (opcion == 1);

    return 0;
}

