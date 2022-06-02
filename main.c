#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>



typedef struct
{
   char nombre[30];
   int edad;
   int dni;

}stCliente;

typedef struct
{
   int numHabitacion;
   char tipoHabitacion[30];
   int precioHabitacion;
   char disponibilidad;

}stHabitacion;



typedef struct
{
    stCliente clienteReserva;
    stHabitacion habitacionReserva;
    int cantNoches;
    char tipoPago[30];
    int  servicio;
    int pensionComida;
    float precioTotal;
}stReserva;

int validacionServicio(char a,char b, stReserva reserva);

const int doble = 250;
const int triple = 375;
const int cuadruple = 500;
const int suite = 800;

int main()
{
    menu();

    return 0;
}

void menu()
{
    int op,op2;
    do{
    system("cls");
    gotoxy(50,2);
    printf("HOTEL YAPEYU");
    gotoxy(50,4);
    printf("ADMINISTRADOR");
    gotoxy(8,6);
    printf("1 - Ingresar una Nueva Reserva");
    gotoxy(8,8);
    printf("2 - Ver Reservas");
    gotoxy(8,10);
    printf("3 - Cancelar Reserva");
    gotoxy(8,12);
    printf("0 - SALIR");
    gotoxy(8,14);
    printf("Ingrese una opcion: ");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        do{
            system("cls");
            stReserva reserva;
            gotoxy(50,2);
            printf("HOTEL YAPEYU");
            gotoxy(44,4);
            printf("ADMINISTRADOR - RESERVA");
            gotoxy(8,6);
            cargarUnaReserva(reserva);
            getch();

        }while(op2!=0);
        break;
    }
    }while(op!=0);
}

void cargarUnaReserva(stReserva reserva)
{
    gotoxy(8,6);
    printf("Cantidad de Noches: ");
    scanf("%d",&reserva.cantNoches);

    gotoxy(8,8);
    int tipoHab;
    printf("Tipo de Habitacion (Doble / Triple / Cuadruple / Suite): ");
    fflush(stdin);
    scanf("%s",&reserva.habitacionReserva.tipoHabitacion);
    while(strcmpi(reserva.habitacionReserva.tipoHabitacion,"Doble")!=0 && strcmpi(reserva.habitacionReserva.tipoHabitacion,"Triple")!=0 && strcmpi(reserva.habitacionReserva.tipoHabitacion,"Cuadruple")!=0 && strcmpi(reserva.habitacionReserva.tipoHabitacion,"Suite")!=0 )
    {
        gotoxy(8,8);
        printf("El tipo no existe. Ingrese nuevamente: ");
        scanf("%s",&reserva.habitacionReserva.tipoHabitacion);
    }

    if(strcmpi(reserva.habitacionReserva.tipoHabitacion,"Doble")==0)
    {
        tipoHab = 2;
        reserva.habitacionReserva.precioHabitacion = doble;
    }
    if(strcmpi(reserva.habitacionReserva.tipoHabitacion,"Triple")==0)
    {
        tipoHab = 3;
        reserva.habitacionReserva.precioHabitacion = triple;
    }
    if(strcmpi(reserva.habitacionReserva.tipoHabitacion,"Cuadruple")==0)
    {
        tipoHab = 4;
        reserva.habitacionReserva.precioHabitacion = cuadruple;
    }
    if(strcmpi(reserva.habitacionReserva.tipoHabitacion,"Suite")==0)
    {
        tipoHab = 6;
        reserva.habitacionReserva.precioHabitacion = suite;
    }

    gotoxy(8,10);
    int cantPersonas;
    printf("Cantidad de Personas: ");
    scanf("%d",&cantPersonas);

    while(cantPersonas>tipoHab)
    {
        gotoxy(8,10);
        printf("El maximo de personas para la habitacion es %d. Ingrese nuevamente: ",tipoHab);
        scanf("%d",&cantPersonas);
    }

    gotoxy(8,12);
    char pension[30];
    printf("Tipo de Pension (Media / Completa): ");
    fflush(stdin);
    scanf("%s",&pension);
    while(strcmpi(pension,"Media")!=0 && strcmpi(pension,"Completa")!=0 )
    {
        gotoxy(8,12);
        printf("No existe. Ingrese nuevamente (Media / Completa): ");
        fflush(stdin);
        scanf("%s",&pension);
    }

    if(strcmpi(pension,"Media")==0)
    {
        reserva.pensionComida = 50;
    }
    if(strcmpi(pension,"Completa")==0)
    {
       reserva.pensionComida = 100;
    }

    char a,b;
    gotoxy(8,14);
    printf("Tipos de Servicios: ");

    gotoxy(10,15);
    printf("- GYM (s/n) : ");
    fflush(stdin);
    scanf("%c",&a);
    gotoxy(10,15);
    validacion(a);

    gotoxy(10,16);
    printf("- SPA (s/n) : ");
    fflush(stdin);
    scanf("%c",&b);
    gotoxy(10,16);
    validacion(b);

    int ab = validacionServicio(a,b,reserva);

    system("cls");
    gotoxy(50,2);
    printf("HOTEL YAPEYU");
    gotoxy(48,4);
    printf("RESERVA - CLIENTE");

    stCliente A[cantPersonas];
    cargaArreglo(A,cantPersonas);
    mostrarArreglo(A, cantPersonas);
    printf("\n\n--------------------ANASHEEEE");

}

void validacion(char a)
{
    while(a!='s'&& a!='S' && a!='n'&& a!='N')
    {

        printf("- No existe. Ingrese nuevamente (s/n): ");
        fflush(stdin);
        scanf("%c",&a);
    }
}


int validacionServicio(char a,char b, stReserva reserva)
{

    if((a=='s' || a=='S') && (b=='s' || b=='S'))
    {
        reserva.servicio= 75;
    }else if ((a=='s'|| a=='S') && (b=='n' || b=='N'))
    {
        reserva.servicio = 50;
    }else if((a=='n'|| a=='N') && (b=='s' || b=='S'))
    {
        reserva.servicio = 50;
    }else if((a=='n'|| a=='N')&& (b=='n' || b=='N'))
    {
        reserva.servicio=0;
    }

    return reserva.servicio;
}


void cargaArreglo(stCliente A[],int dim)
{
    int i=0;
    while(i<dim)
    {
        printf("\nNombre: ");
        fflush(stdin);
        gets(A[i].nombre);

        printf("\nEdad: ");
        scanf("%d",&A[i].edad);

        printf("\nDNI: ");
        scanf("%d",&A[i].dni);
        i++;
    }
}

void mostrarArreglo(stCliente A[],int dim)
{
    int i=0;
    while(i<dim)
    {
        printf("\n----------------------\n");
        printf("\nNombre: %s",A[i].nombre);
        printf("\nEDAD: %d",A[i].edad);
        printf("\nDNI: %d",A[i].dni);
        i++;
    }

}
