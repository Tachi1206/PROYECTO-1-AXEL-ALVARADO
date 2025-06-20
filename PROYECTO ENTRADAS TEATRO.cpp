#include <stdio.h>

int main() {
    int factura = 1, opcion;
    int tipoCliente, tipoTiquete, cantidad;
    int montoUnitario, montoVenta, descuento, subtotal, impuesto, totalPagar;
    int cedula;
    int tipoClienteAux, tipoTiqueteAux;

    // Estadisticas
    int cantGaleria = 0, cantPalco = 0, totalEntradas = 0;
    int acumGaleria = 0, acumPalco = 0, acumGeneral = 0;
    int totalVentas = 0;

    do {
        printf("\n--- SISTEMA DE VENTA DE ENTRADAS AL TEATRO ---\n");
        printf("Factura numero %d\n", factura);

        // Datos del cliente
        printf("Ingrese la cedula del cliente (solo numeros) ");
        scanf("%d", &cedula);

        // Tipo de cliente con validacion
        do {
            printf("Tipo de cliente (1=Nino o Adulto Mayor  2=Adulto) ");
            scanf("%d", &tipoCliente);
            if (tipoCliente < 1 || tipoCliente > 2) {
                printf("   POR FAVOR INGRESE UNA OPCION VALIDA \n");
            }
        } while (tipoCliente < 1 || tipoCliente > 2);

        tipoClienteAux = tipoCliente;

        // Tipo de tiquete con validacion
        do {
            printf("Tipo de tiquete (1=Galeria - 6000 colones  2=Palco - 12000 colones) ");
            scanf("%d", &tipoTiquete);
            if (tipoTiquete < 1 || tipoTiquete > 2) {
                printf("   POR FAVOR INGRESE UNA OPCION VALIDA \n");
            }
        } while (tipoTiquete < 1 || tipoTiquete > 2);

        tipoTiqueteAux = tipoTiquete;

        // Cantidad de tiquetes
        do {
            printf("Cantidad de tiquetes a comprar ");
            scanf("%d", &cantidad);
            if (cantidad < 1) {
                printf("   POR FAVOR INGRESE UNA CANTIDAD VALIDA \n");
            }
        } while (cantidad < 1);

        // Precio segun tipo de tiquete
        if (tipoTiquete == 1) {
            montoUnitario = 6000;
        } else {
            montoUnitario = 12000;
        }

        // Calculos
        montoVenta = montoUnitario * cantidad;

        if (tipoCliente == 1) {
            descuento = montoVenta * 30 / 100;
        } else {
            descuento = 0;
        }

        subtotal = montoVenta - descuento;
        impuesto = subtotal * 13 / 100;
        totalPagar = subtotal + impuesto;

        // Mostrar resumen
        printf("\n--- FACTURA #%d ---\n", factura);
        printf("Cedula %d\n", cedula);

        if (tipoClienteAux == 1) {
            printf("Tipo Cliente Nino o Adulto Mayor\n");
        } else {
            printf("Tipo Cliente Adulto\n");
        }

        if (tipoTiqueteAux == 1) {
            printf("Tipo Tiquete Galeria\n");
        } else {
            printf("Tipo Tiquete Palco\n");
        }

        printf("Cantidad de Tiquetes %d\n", cantidad);
        printf("Precio Unitario %d colones\n", montoUnitario);
        printf("Monto Venta %d colones\n", montoVenta);
        printf("Descuento %d colones\n", descuento);
        printf("Subtotal %d colones\n", subtotal);
        printf("Impuesto (13 porciento) %d colones\n", impuesto);
        printf("TOTAL A PAGAR %d colones\n", totalPagar);

        // Estadisticas
        if (tipoTiquete == 1) {
            cantGaleria = cantGaleria + cantidad;
            acumGaleria = acumGaleria + totalPagar;
        } else {
            cantPalco = cantPalco + cantidad;
            acumPalco = acumPalco + totalPagar;
        }

        totalEntradas = totalEntradas + cantidad;
        acumGeneral = acumGeneral + totalPagar;
        totalVentas = totalVentas + 1;
        factura = factura + 1;

        // Continuar
        printf("\nDesea registrar otra venta  (1 = Si  0 = No) ");
        scanf("%d", &opcion);

    } while (opcion == 1);

    // Mostrar estadisticas finales
    printf("\n--- ESTADISTICAS FINALES ---\n");
    printf("Cantidad de entradas Galeria %d\n", cantGaleria);
    printf("Total recaudado por Galeria %d colones\n", acumGaleria);
    printf("Cantidad de entradas Palco %d\n", cantPalco);
    printf("Total recaudado por Palco %d colones\n", acumPalco);
    printf("Cantidad total de entradas %d\n", totalEntradas);
    printf("Total general recaudado %d colones\n", acumGeneral);

    if (totalVentas > 0) {
        printf("Promedio por venta %d colones\n", acumGeneral / totalVentas);
    } else {
        printf("No se registraron ventas\n");
    }

    return 0;
}

