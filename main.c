#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

const int doble = 250;
const int triple = 375;
const int cuadruple = 500;
const int suite = 800;

typedef struct
{
    char nombre[30];
    int edad;
    int dni;
} stCliente;

typedef struct
{
    int numHabitacion;
    char tipoHabitacion[30];
    int precioHabitacion;
    char disponibilidad;

} stHabitacion;

typedef struct
{
    stCliente clienteReserva[10];
    stHabitacion habitacionReserva;
    int cantNoches;
    char tipoPago[30];
    int  servicio;
    int pensionComida;
    float precioTotal;
    char estado[30];
    int cantidadPersonas;
} stReserva;

int main()
{
    cargarArchivoHabitaciones("HabitacionesDisponibles.bin");
    menu();
    return 0;
}

stReserva cargarFamilia(stReserva A,int pos,int x,int y);
int valorDeServicios(char a,char b);

void menu()
{
    int op,op2,op3;
    stReserva reserva;
    do
    {
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
        printf("3 - Ver Habitaciones Disponibles");
        gotoxy(8,12);
        printf("4 - Cancelar Reserva");
        gotoxy(8,14);
        printf("0 - SALIR");
        gotoxy(8,16);
        printf("Ingrese una opcion: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            system("cls");
            gotoxy(50,2);
            printf("HOTEL YAPEYU");
            gotoxy(44,4);
            printf("ADMINISTRADOR - RESERVA");
            cargarReserva("Reservas.bin");
            printf("\n");
            system("PAUSE");
            break;
        case 2:
            system("cls");
            gotoxy(50,2);
            printf("HOTEL YAPEYU");
            gotoxy(47,4);
            printf("Historial de Reservas");
            mostrarArchivo("Reservas.bin");
            printf("\n");
            system("PAUSE");
            break;
        case 3:
            do{
                system("cls");
                gotoxy(50,2);
                printf("HOTEL YAPEYU");
                gotoxy(44,4);
                printf("Habitaciones Disponibles");
                gotoxy(8,6);
                printf("1 - Mostrar todas las Habitaciones disponibles");
                gotoxy(8,8);
                printf("2 - Mostrar solo Dobles disponibles");
                gotoxy(8,10);
                printf("3 - Mostrar solo Triples disponibles");
                gotoxy(8,12);
                printf("4 - Mostrar solo Cuadruples disponibles");
                gotoxy(8,14);
                printf("5 - Mostrar solo Suites disponibles");
                gotoxy(8,16);
                printf("0 - Regresar...");
                gotoxy(8,18);
                printf("Elige una opcion: ");
                scanf("%d",&op2);
                switch(op2)
                {
                case 1:
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(44,4);
                    printf("Habitaciones Disponibles");
                    printf("\n");
                    mostrarDisponibles("HabitacionesDisponibles.bin");
                    printf("\n\n");
                    system("PAUSE");
                    break;
                case 2:
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(40,4);
                    printf("Habitaciones Dobles Disponibles");
                    printf("\n");
                    printf("\n\nHabitaciones Dobles: \n\n");
                    mostrarDoblesDisponibles("HabitacionesDisponibles.bin");
                    printf("\n\n");
                    system("PAUSE");
                    break;
                case 3:
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(40,4);
                    printf("Habitaciones Triples Disponibles");
                    printf("\n");
                    printf("\n\nHabitaciones Triples: \n\n");
                    mostrarTriplesDisponibles("HabitacionesDisponibles.bin");
                    printf("\n\n");
                    system("PAUSE");
                    break;
                case 4:
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(40,4);
                    printf("Habitaciones Cuadruples Disponibles");
                    printf("\n");
                    printf("\n\nHabitaciones Cuadruples: \n\n");
                    mostrarCuadruplesDisponibles("HabitacionesDisponibles.bin");
                    printf("\n\n");
                    system("PAUSE");
                    break;
                case 5:
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(40,4);
                    printf("Habitaciones Suites Disponibles");
                    printf("\n");
                    printf("\n\nHabitaciones Suites: \n\n");
                    mostrarSuitesDisponibles("HabitacionesDisponibles.bin");
                    printf("\n\n");
                    system("PAUSE");
                    break;
                case 0:
                    break;
                default:
                    printf("\nLa opcion ingresada no existe...");
                    printf("\n\n");
                    system("PAUSE");
                    break;
                }
            }while(op2!=0);
            break;
        }
    }
    while(op!=0);
}

void cargarReserva(char archivoReserva[])
{
    stReserva reserva;
    FILE *archi = fopen(archivoReserva,"wb");
    if(archi!=NULL)
    {
        gotoxy(8,6);
        printf("Cantidad de Noches: ");
        scanf("%d",&reserva.cantNoches);

        gotoxy(8,8);
        printf("Tipo de Habitacion (Doble / Triple / Cuadruple / Suite): ");
        fflush(stdin);
        gets(reserva.habitacionReserva.tipoHabitacion);

        while(strcmpi(reserva.habitacionReserva.tipoHabitacion,"Doble")!=0 && strcmpi(reserva.habitacionReserva.tipoHabitacion,"Triple")!=0 && strcmpi(reserva.habitacionReserva.tipoHabitacion,"Cuadruple")!=0 && strcmpi(reserva.habitacionReserva.tipoHabitacion,"Suite")!=0 )
        {
            gotoxy(8,9);
            printf("El tipo no existe. Ingrese nuevamente: ");
            fflush(stdin);
            gets(reserva.habitacionReserva.tipoHabitacion);
        }

        int tipoHab;
        int vHabitacion = cargarTipoDeHabitacion(reserva,&tipoHab);

        gotoxy(8,10);
        int cantPersonas;
        printf("Cantidad de Personas: ");
        scanf("%d",&reserva.cantidadPersonas);

        validacionPersonasPorHabitacion(reserva.cantidadPersonas,tipoHab);

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

        reserva.pensionComida = valorPension(pension);

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

        reserva.servicio = valorDeServicios(a,b);

        system("cls");
        gotoxy(50,2);
        printf("HOTEL YAPEYU");
        gotoxy(48,4);
        printf("RESERVA - CLIENTE");

        int x=8, y=7, num=1;
        for(int k=0;k<reserva.cantidadPersonas;k++)
        {
        printf("\nPersona %d de %d:",num,reserva.cantidadPersonas);
        reserva=cargarFamilia(reserva,k,x,y);
        y+=8;
        num++;
        }
        fwrite(&reserva,sizeof(stReserva),1,archi);

        system("cls");
        gotoxy(50,2);
        printf("HOTEL YAPEYU");
        gotoxy(40,4);
        printf("RESERVA - HABITACIONES DISPONIBLES");
        gotoxy(8,8);
        printf("Habitaciones %s disponibles: \n",reserva.habitacionReserva.tipoHabitacion);
        mostrarPorTipodeHabitaciones("HabitacionesDisponibles.bin",reserva.habitacionReserva.tipoHabitacion);
        gotoxy(8,12);
        printf("\n\nElija Habitacion a hospedar: ");
        scanf("%d",&reserva.habitacionReserva.numHabitacion);
        //pasar_a_NoDisponible("HabitacionesDisponibles.bin",reserva.habitacionReserva.numHabitacion,"HabitacionesOcupadas.bin");
        fwrite(&reserva,sizeof(stReserva),1,archi);
        fclose(archi);
    }
}

void mostrarArchivo(char archivoReserva[])
{
    stReserva A;
    int num=1;
    int i;
    FILE * archi = fopen(archivoReserva,"rb");
    if(archi!=NULL)
    {
        while(fread(&A,sizeof(stReserva),1,archi)>0)
        {
            printf("\n---------------- Registro %d ----------------",num++);

            for(int i=0;i<A.cantidadPersonas;i++)
            {
            printf("\nHuesped %d: ",i+1);
            printf("\n- Nombre y Apellido     : %s",A.clienteReserva[i].nombre);
            printf("\n- Documento             : %d",A.clienteReserva[i].dni);
            printf("\n- Edad                  : %d",A.clienteReserva[i].edad);
            }
            printf("\n             ----");
            printf("\n- Cantidad de Noches    : %d",A.cantNoches);
            if(A.pensionComida==50)
                printf("\n- Pension de Comida     : Media");
            else
                printf("\n- Pension de Comida     : Completa");

            if(A.servicio==100)
            {
                printf("\n- Servicios             : Gym y Spa");
            }
            else if(A.servicio==70)
            {
                printf("\n- Servicios             : Spa");
            }
            else if(A.servicio==50)
            {
                printf("\n- Servicios             : Gym");
            }
            else
            {
                printf("\n- Servicios             : No");
            }
            printf("\n- Tipo de Habitacion    : %s",A.habitacionReserva.tipoHabitacion);
            printf("\n- Cantidad de Personas  : %d",A.cantidadPersonas);
            printf("\n");
        }
        fclose(archi);
    }
}

stReserva cargarFamilia(stReserva A,int pos,int x,int y)
{
    gotoxy(x,y);
    printf("- Nombre y Apellido: ");
    fflush(stdin);
    gets(A.clienteReserva[pos].nombre);

    gotoxy(x,y+2);
    printf("- Edad: ");
    scanf("%d",&A.clienteReserva[pos].edad);

    gotoxy(x,y+4);
    printf("- Documento: ");
    scanf("%d",&A.clienteReserva[pos].dni);
    return A;
}

int valorDeServicios(char a,char b)
{
    int valor;

    if((a=='s' || a=='S') && (b=='s' || b=='S'))
    {
        valor= 100;
    }
    else if ((a=='s'|| a=='S') && (b=='n' || b=='N'))
    {
        valor = 50;
    }
    else if((a=='n'|| a=='N') && (b=='s' || b=='S'))
    {
        valor = 70;
    }
    else if((a=='n'|| a=='N')&& (b=='n' || b=='N'))
    {
        valor=0;
    }

    return valor;
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

int cargarTipoDeHabitacion(stReserva reserva, int *tipoHab)
{
    if(strcmpi(reserva.habitacionReserva.tipoHabitacion,"Doble")==0)
    {
        *tipoHab = 2;
        reserva.habitacionReserva.precioHabitacion = doble;
    }
    if(strcmpi(reserva.habitacionReserva.tipoHabitacion,"Triple")==0)
    {
        *tipoHab = 3;
        reserva.habitacionReserva.precioHabitacion = triple;
    }
    if(strcmpi(reserva.habitacionReserva.tipoHabitacion,"Cuadruple")==0)
    {
        *tipoHab = 4;
        reserva.habitacionReserva.precioHabitacion = cuadruple;
    }
    if(strcmpi(reserva.habitacionReserva.tipoHabitacion,"Suite")==0)
    {
        *tipoHab = 6;
        reserva.habitacionReserva.precioHabitacion = suite;
    }

    return reserva.habitacionReserva.precioHabitacion;
}

void validacionPersonasPorHabitacion(int cantPersonas, int tipoHab)
{
    while(cantPersonas>tipoHab)
    {
        gotoxy(8,10);
        printf("El maximo de personas para la habitacion es %d. Ingrese nuevamente: ",tipoHab);
        scanf("%d",&cantPersonas);
    }
}

int valorPension(char pension[30])
{
    int valor;
    if(strcmpi(pension,"Media")==0)
    {
        valor = 50;
    }
    if(strcmpi(pension,"Completa")==0)
    {
        valor = 100;
    }
    return valor;
}

void cargarArchivoHabitaciones(char archivoHabitacion[])
{
    stHabitacion room;
    int num;
    FILE *archi=fopen(archivoHabitacion,"wb");
    if(archi!=NULL)
    {
        for(num = 1;num <=55;num++)
        {
            if(num<=43 && num%2==1)
            {
                room.numHabitacion=num;
                strcpy(room.tipoHabitacion,"Doble");
                room.precioHabitacion= 250;
                room.disponibilidad='s';

            }else if(num<=44 && num%2==0)
            {
                room.numHabitacion=num;
                strcpy(room.tipoHabitacion,"Triple");
                room.precioHabitacion= 375;
                room.disponibilidad='s';

            }else if(num>=45 && num<=49)
            {
                room.numHabitacion=num;
                strcpy(room.tipoHabitacion,"Cuadruple");
                room.precioHabitacion= 500;
                room.disponibilidad='s';
            }else if(num>=50 && num<=55)
            {
                room.numHabitacion=num;
                strcpy(room.tipoHabitacion,"Suite");
                room.precioHabitacion= 800;
                room.disponibilidad='s';
            }
            fwrite(&room,sizeof(stHabitacion),1,archi);
        }
        fclose(archi);
    }
}

void mostrarDisponibles(char archivoHabitaciones[])
{
    printf("\nHabitaciones Dobles: \n");
    mostrarDoblesDisponibles(archivoHabitaciones);
    printf("\n\nHabitaciones Triples: \n");
    mostrarTriplesDisponibles(archivoHabitaciones);
    printf("\n\nHabitaciones Cuadruples: \n");
    mostrarCuadruplesDisponibles(archivoHabitaciones);
    printf("\n\nHabitaciones Suites: \n");
    mostrarSuitesDisponibles(archivoHabitaciones);
}

void mostrarDoblesDisponibles(char archivoHabitaciones[])
{
    stHabitacion room;
    FILE *archi = fopen(archivoHabitaciones,"rb");
    if(archi!=NULL)
    {
        while(fread(&room,sizeof(stHabitacion),1,archi)>0)
        {
            if((room.numHabitacion<=43 && room.numHabitacion%2==1) && (room.disponibilidad=='s'||room.disponibilidad=='S'))
            {
                printf(" %d |",room.numHabitacion);
            }
        }
        fclose(archi);
    }else{
    printf("El archivo no existe...");
    }
}

void mostrarTriplesDisponibles(char archivoHabitaciones[])
{
    stHabitacion room;
    FILE *archi = fopen(archivoHabitaciones,"rb");
    if(archi!=NULL)
    {
        while(fread(&room,sizeof(stHabitacion),1,archi)>0)
        {
            if((room.numHabitacion<=44 && room.numHabitacion%2==0) && (room.disponibilidad=='s'||room.disponibilidad=='S'))
            {
                printf(" %d |",room.numHabitacion);
            }
        }
        fclose(archi);
    }
}

void mostrarCuadruplesDisponibles(char archivoHabitaciones[])
{
    stHabitacion room;
    FILE *archi = fopen(archivoHabitaciones,"rb");
    if(archi!=NULL)
    {
        while(fread(&room,sizeof(stHabitacion),1,archi)>0)
        {
            if((room.numHabitacion>=45 && room.numHabitacion<=49) && (room.disponibilidad=='s'||room.disponibilidad=='S'))
            {
                printf(" %d |",room.numHabitacion);
            }
        }
        fclose(archi);
    }
}

void mostrarSuitesDisponibles(char archivoHabitaciones[])
{
    stHabitacion room;
    FILE *archi = fopen(archivoHabitaciones,"rb");
    if(archi!=NULL)
    {
        while(fread(&room,sizeof(stHabitacion),1,archi)>0)
        {
            if((room.numHabitacion>=50 && room.numHabitacion<=55) && (room.disponibilidad=='s'||room.disponibilidad=='S'))
            {
                printf(" %d |",room.numHabitacion);
            }
        }
        fclose(archi);
    }
}

void mostrarPorTipodeHabitaciones(char archivoHabitaciones[],char tipo[])
{
    stHabitacion room;
    FILE *archi = fopen(archivoHabitaciones,"rb");
    if(archi!=NULL)
    {
        while(fread(&room,sizeof(stHabitacion),1,archi)>0)
        {
            if((room.disponibilidad=='s'||room.disponibilidad=='S') && strcmpi(room.tipoHabitacion,tipo)==0)
            {
                printf(" %d |", room.numHabitacion);
            }
        }
        fclose(archi);
    }
}

/*void pasar_a_NoDisponible(char archivoHabitaciones[],int num,char archivoHabOcupas[]) ///EN PROCESO....
{
    stHabitacion room,aux;
    FILE *archi=fopen(archivoHabitaciones,"r+b");
    if(archi!=NULL)
    {
        while(fread(&room,sizeof(stHabitacion),1,archi)>0)
        {
            if(room.numHabitacion==num)
            {
                room.disponibilidad='n';
                fwrite(&room,sizeof(stHabitacion),1,archi);
                aux = room;
            }
        }
        fclose(archi);
    }

    FILE *archi2=fopen(archivoHabOcupas,"wb");
    if(archi2!=NULL)
    {
        aux;
        fwrite(&aux,sizeof(stHabitacion),1,archi2);
        fclose(archi2);
    }
}*/
