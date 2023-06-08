/* actualizar una serie de cuentas de clientes (sistema de facturación simplificado) */
/* mantener las cuentas de clientes como un array externo de estructuras */

#include <stdio.h>

void leerEntrada (int i);
void escribirSalida(int i);

struct fecha{
    int mes;
    int dia;
    int anio;
};

struct cuenta
{
    char nombre[80];
    char calle[80];
    char ciudad[80];
    int num_cuenta;
    int tipo_cuenta;

    float anteriorSaldo;
    float nuevoSaldo;
    float pago;
    struct fecha ultimoPago;
    
}cliente[100];

int main(){

    int i,n;

    printf("SISTEMA DE FACTURACION DE CLIENTES\n\n");
    printf("¿Cuantos clientes hay?   ");
    scanf ( "%d", &n);

    for(i =0; i < n; ++i){
        leerEntrada(i);

        if(cliente[i].pago > 0)
        cliente[i].tipo_cuenta = (cliente[i].pago < 0.1 * cliente[i].anteriorSaldo) ? 'R'   : 'A';
        else
        cliente[i].tipo_cuenta = (cliente [i].anteriorSaldo > 0) ? 'D' :  'A';
        cliente[i].nuevoSaldo = cliente[i].anteriorSaldo - cliente[i].pago;
    }


    for(i = 0; i < n; ++i) escribirSalida(i);
}
void leerEntrada(int i){

    printf("\nCliente n° %d\n", i + 1);
    printf("    Nombre: ");
    scanf(" %[^\n]",cliente[i].nombre);
    printf("    Calle: ");
    scanf(" %[^\n]",cliente[i].calle);
    printf("    Ciudad: ");
    scanf(" %[^\n]",cliente[i].ciudad);
    printf("    NUmero de cuenta: ");
    scanf(" %d",&cliente[i].num_cuenta);
    printf("    Saldo Anterior: ");
    scanf(" %f",&cliente[i].anteriorSaldo);
    printf("    Pago actual: ");
    scanf(" %f",&cliente[i].pago);
    printf("    Fecha de pago (mm/dd/aaaa): ");
    scanf("%d/%d/%d", &cliente[i].ultimoPago.mes, & cliente[i].ultimoPago.dia, & cliente[i].ultimoPago.anio);

    return;

}
void escribirSalida(int i ){

    printf("\n Nombre: %s", cliente[i].nombre);
    printf("    Numero de cuenta:  %d\n", cliente[i].num_cuenta);

    printf("Calle:      %s\n", cliente[i].calle);
    printf("Ciudad:      %s\n\n", cliente[i].ciudad);
    printf("Saldo anterior:      %7.2f", cliente[i].anteriorSaldo);
    printf("        Pago actual:      %7.2f", cliente[i].pago);
    printf("        NUevo saldo:      %7.2f\n\n", cliente[i].nuevoSaldo);
    printf("Estado de la cuenta: ");

    switch(cliente[i].tipo_cuenta){

        case 'A':   printf("AL DIA \n\n");
        break;

        case 'R':   printf("ATRASADA\n\n");
        break;

        case 'D':   printf("DELINCUENTE\n\n");
        break;
    }
    return;
}


