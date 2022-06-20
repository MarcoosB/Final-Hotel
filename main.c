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
    int servicio;
    int pensionComida;
    int estacionamiento;
} stServicios;

typedef struct
{
    char tipoPago[30];
    int cuotas;

}stMetodoPago;

typedef struct
{
    stCliente clienteReserva[10];
    stHabitacion habitacionReserva;
    stServicios serviciosReserva;
    stMetodoPago pagoReserva;
    int cantNoches;
    float precioTotal;
    char estado[30];
    int cantidadPersonas;
} stReserva;

void menu();
void cargarReserva(char archivoReserva[]);
int valorEstacionamiento(char c,stReserva A);
void mostrarArchivo(char archivoReserva[]);
stReserva cargarFamilia(stReserva A,int pos,int x,int y);
int valorDeServicios(char a,char b);
void validacion(char a,int x,int y);
int cargarTipoDeHabitacion(stReserva reserva, int *tipoHab);
int valorPension(char pension[]);
void cargarArchivoHabitaciones(char archivoHabitacion[]);
void mostrarDisponibles(char archivoHabitaciones[]);
void mostrarDoblesDisponibles(char archivoHabitaciones[]);
void mostrarTriplesDisponibles(char archivoHabitaciones[]);
void mostrarCuadruplesDisponibles(char archivoHabitaciones[]);
void mostrarSuitesDisponibles(char archivoHabitaciones[]);
void mostrarPorTipodeHabitaciones(char archivoHabitaciones[],char tipo[]);
void modificarDisponibilidad(char archivoHabitaciones[],int numHab);
stHabitacion cambioDisponibilidad(stHabitacion A);
int busquedaPosicionHab(char archivoHabitaciones[],int numHab);
int verificacionHabitacionDisponible(char archivoHabitaciones[],int numHab);
int verificarPorTipoHabitacion(int numHab,char tipoHab[]);
float tipoDePago(char tipo[],float total,int cuotas);
float precioTotal(stReserva A,int vHabitacion);
int busquedaPorDNI(char archivo[],int buscado);
void mostrarDeAUno(stReserva A);
int busquedaPorNombre(char archivo[],char buscado[]);
int busquedaPorHabitacion(char archivo[],int buscado);
int busquedaPorTipoHabitacion(char archivo[],char buscado[]);
void borrarRegistro(int bNumHab);
void mostrarOcupadas(char archivoHabitacion[]);
int cantidadRegistros(char archivo[]);
void ordenarArray(stReserva A[], int validos);
void ordenarPorHabitacion(char archivo[]);
int archivo_A_array(char archivo[],stReserva A[]);
void array_A_archivo(char archivo[],stReserva A[],int val);
int verificacionHuesped(char archivo[],int numHab,int huesped);
int busquedaHabitacionposicion(char archivo[],int numHab);
void modificarNombreHuesped(char archivo[],int numHab,int huesped);
void modificarEdadHuesped(char archivo[],int numHab,int huesped);
void modificarDocumento(char archivo[],int numHab,int huesped);
void modificarGymSpa(char archivo[],int numHab);

int main()
{
    FILE *archi=fopen("Habitaciones.bin","rb");
    if(archi==NULL)
        cargarArchivoHabitaciones("Habitaciones.bin");
    fclose(archi);
    menu();
    return 0;
}

void menu()
{

    int op,op2,op3,op4,op2a,op2a1,op2a2,op2c;
    int flag,cant,habit,huesped,bDNI,bNumHab;
    char bNombre[30], bTipoHab[30],seguro;
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
        printf("4 - Consulta de Reserva");
        gotoxy(8,14);
        printf("5 - Cancelar Reserva");
        gotoxy(8,16);
        printf("0 - Salir");
        gotoxy(8,20);
        printf("Ingrese una opcion: ");
        scanf("%d",&op);
        switch(op)
        {

        ///------------------------1) CARGAR RESERVA----------------------------///
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

        ///----------------------2) VER Y MODIFICAR RESERVAS--------------------------///
        case 2:
            do
            {
                cant = cantidadRegistros("Reservas.bin");
                system("cls");
                gotoxy(50,2);
                printf("HOTEL YAPEYU");
                gotoxy(68,6);
                printf("Cantidad de Reservas registradas: %d",cant);
                printf("\n");
                gotoxy(45,4);
                printf("Historial de Reservas");
                printf("\n");
                mostrarArchivo("Reservas.bin");
                gotoxy(68,8);
                printf("1 - Ordenar por numero de Habitacion");
                gotoxy(68,10);
                printf("2 - Modificar Reserva");
                gotoxy(68,12);
                printf("0 - Regresar");
                gotoxy(68,14);
                printf("Ingrese una opcion: ");
                fflush(stdin);
                scanf("%d",&op2);
                switch(op2)
                {
                ///----------------2)1.Ordenar---------------///
                case 1:
                    ordenarPorHabitacion("Reservas.bin");
                    break;
                ///----------------2)2.Modificar-------------///
                case 2:
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(68,6);
                    printf("Cantidad de Reservas registradas: %d",cant);
                    printf("\n");
                    gotoxy(45,4);
                    printf("Historial de Reservas");
                    printf("\n");
                    mostrarArchivo("Reservas.bin");

                    gotoxy(68,8);
                    printf("Ingrese numero de habitacion de la reserva a modificar: ");
                    scanf("%d",&habit);

                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(68,6);
                    printf("Cantidad de Reservas registradas: %d",cant);
                    flag = busquedaPorHabitacion("Reservas.bin",habit);
                    while(flag !=1)
                    {
                        gotoxy(68,8);
                        printf("Habitaciones Ocupadas: ");
                        gotoxy(68,10);
                        mostrarOcupadas("Habitaciones.bin");
                        gotoxy(68,12);
                        printf("La habitacion no se encuentra cargada...Ingrese otra habitacion: ");
                        scanf("%d",&habit);
                        flag = busquedaPorHabitacion("Reservas.bin",habit);
                    }

                    do{
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(45,4);
                    printf("Modificar Reserva Habitacion %d\n",habit);
                    flag = busquedaPorHabitacion("Reservas.bin",habit);
                    gotoxy(68,6);
                    printf("Cantidad de Reservas registradas: %d",cant);
                    gotoxy(68,8);
                    printf("1 - Modificar Huespedes");
                    gotoxy(68,10);
                    printf("2 - Modificar Servicios");
                    gotoxy(68,12);
                    printf("3 - Modificar Numero de Habitacion");
                    gotoxy(68,14);
                    printf("4 - Modificar Tipo de Habitacion");
                    gotoxy(68,16);
                    printf("0 - Regresar");
                    gotoxy(68,18);
                    printf("Ingrese una opcion: ");
                    scanf("%d",&op2a);
                    switch(op2a)
                    {
                        ///--------------2)2.[1]Modificar Huesped-----------------///
                    case 1:
                        system("cls");
                        gotoxy(50,2);
                        printf("HOTEL YAPEYU");
                        gotoxy(40,4);
                        printf("Modificando Reserva Habitacion %d\n",habit);
                        flag = busquedaPorHabitacion("Reservas.bin",habit);
                        gotoxy(68,6);
                        printf("Ingrese huesped a modificar: ");
                        scanf("%d",&huesped);
                        int flag = verificacionHuesped("Reservas.bin",habit,huesped);
                        while(flag==1)
                        {
                            gotoxy(68,7);
                            printf("ERROR, ingrese nuevamente el huesped a modificar: ");
                            scanf("%d",&huesped);
                            flag = verificacionHuesped("Reservas.bin",habit,huesped);
                        }
                        do{
                        system("cls");
                        gotoxy(50,2);
                        printf("HOTEL YAPEYU");
                        gotoxy(36,4);
                        printf("Modificando Huesped %d de la Habitacion %d\n",huesped,habit);
                        flag = busquedaPorHabitacion("Reservas.bin",habit);
                        gotoxy(68,6);
                        printf("Que desea modificar del huesped %d?",huesped);
                        gotoxy(68,8);
                        printf("1 - Nombre y Apellido");
                        gotoxy(68,10);
                        printf("2 - Edad");
                        gotoxy(68,12);
                        printf("3 - Documento");
                        gotoxy(68,14);
                        printf("0 - Regresar...");
                        gotoxy(68,16);
                        printf("Ingrese una opcion: ");
                        fflush(stdin);
                        scanf("%d",&op2a1);
                        switch(op2a1)
                        {
                             ///--------------2)2.[1,1]Modificar Nombre-----------------///
                        case 1:
                            system("cls");
                            gotoxy(50,2);
                            printf("HOTEL YAPEYU");
                            gotoxy(32,4);
                            printf("Modificando Nombre y Apellido del Huesped %d de la Habitacion %d\n",huesped,habit);
                            flag = busquedaPorHabitacion("Reservas.bin",habit);
                            modificarNombreHuesped("Reservas.bin",habit,huesped);
                            break;

                            ///--------------2)2.[1,2]Modificar Edad-----------------///
                        case 2:
                            system("cls");
                            gotoxy(50,2);
                            printf("HOTEL YAPEYU");
                            gotoxy(35,4);
                            printf("Modificando Edad del Huesped %d de la Habitacion %d\n",huesped,habit);
                            flag = busquedaPorHabitacion("Reservas.bin",habit);
                            modificarEdadHuesped("Reservas.bin",habit,huesped);
                            break;

                             ///--------------2)2.[1,3]Modificar DNI-----------------///
                        case 3:
                            system("cls");
                            gotoxy(50,2);
                            printf("HOTEL YAPEYU");
                            gotoxy(34,4);
                            printf("Modificando Documento del Huesped %d de la Habitacion %d\n",huesped,habit);
                            flag = busquedaPorHabitacion("Reservas.bin",habit);
                            modificarDocumento("Reservas.bin",habit,huesped);
                            break;
                            ///--------------2)2.[1,0]REGRESAR-----------------///
                        case 0:
                            break;
                        default:
                            gotoxy(68,20);
                            printf("La opcion ingresada no existe...");
                            gotoxy(68,22);
                            system("PAUSE");
                            break;
                        }
                    }while(op2a1!=0);
                        break;
                    ///-----------Modificar Servicios--------------///
                        case 2:
                            do{
                            system("cls");
                            gotoxy(50,2);
                            printf("HOTEL YAPEYU");
                            gotoxy(35,4);
                            printf("Modificar Servicios de la Reserva Habitacion %d\n",habit);
                            flag = busquedaPorHabitacion("Reservas.bin",habit);
                            gotoxy(68,6);
                            printf("Que servicio desea modificar?");
                            gotoxy(68,8);
                            printf("1 - Gym y Spa");
                            gotoxy(68,10);
                            printf("2 - Pension");
                            gotoxy(68,12);
                            printf("3 - Estacionamiento");
                            gotoxy(68,14);
                            printf("0 - Regresar...");
                            gotoxy(68,16);
                            printf("Ingrese una opcion: ");
                            scanf("%d",&op2a2);
                            switch(op2a2)
                            {
                            case 1:
                                system("cls");
                                gotoxy(50,2);
                                printf("HOTEL YAPEYU");
                                gotoxy(35,4);
                                printf("Modificar Gym y Spa de la Reserva Habitacion %d\n",habit);
                                flag = busquedaPorHabitacion("Reservas.bin",habit);
                                modificarGymSpa("Reservas.bin",habit);
                                break;
                            }
                            }while(op2a2!=0);
                            break;
                    }
                }while(op2a!=0);

                ///----------Regresar--------------///
                case 0:
                    break;
                }
            } while(op2!=0);
            break;

        ///--------------------3) MOSTRAR HABITACIONES DISPONIBLES----------------------------------///

        case 3:
            do
            {
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
                scanf("%d",&op3);
                switch(op3)
                {
                case 1:
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(44,4);
                    printf("Habitaciones Disponibles");
                    printf("\n");
                    mostrarDisponibles("Habitaciones.bin");
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
                    printf("Habitaciones Dobles:\n\n");
                    mostrarDoblesDisponibles("Habitaciones.bin");
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
                    mostrarTriplesDisponibles("Habitaciones.bin");
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
                    mostrarCuadruplesDisponibles("Habitaciones.bin");
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
                    mostrarSuitesDisponibles("Habitaciones.bin");
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
            }
            while(op3!=0);
            break;

        ///-------------------4) CONSULTAR RESERVA-----------------------------------///

        case 4:
            do
            {
                system("cls");
                gotoxy(50,2);
                printf("HOTEL YAPEYU");
                gotoxy(46,4);
                printf("Opciones de Busqueda");
                gotoxy(8,6);
                printf("1 - Busqueda por DNI");
                gotoxy(8,8);
                printf("2 - Busqueda por Nombre");
                gotoxy(8,10);
                printf("3 - Busqueda por Habitacion");
                gotoxy(8,12);
                printf("4 - Busqueda por Tipo de Habitacion");
                gotoxy(8,14);
                printf("0 - Regresar...");
                gotoxy(8,16);
                printf("Ingrese una opcion: ");
                scanf("%d",&op4);
                switch(op4)
                {
                case 1:
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(46,4);
                    printf("Busqueda por DNI");
                    gotoxy(8,6);
                    printf("Ingrese DNI a buscar: ");
                    scanf("%d",&bDNI);
                    flag = busquedaPorDNI("Reservas.bin",bDNI);
                    if(flag !=1)
                    {
                        gotoxy(8,8);
                        printf("El DNI buscado no se encuentra registrado en una reserva...");
                    }
                    printf("\n\n");
                    system("PAUSE");
                    break;
                case 2:
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(46,4);
                    printf("Busqueda por Nombre");
                    gotoxy(8,6);
                    printf("Ingrese Nombre y Apellido a buscar: ");
                    fflush(stdin);
                    gets(bNombre);
                    flag = busquedaPorNombre("Reservas.bin",bNombre);
                    if(flag !=1)
                    {
                        gotoxy(8,8);
                        printf("El Nombre y Apellido buscado no se encuentra registrado en una reserva...");
                    }
                    printf("\n\n");
                    system("PAUSE");
                    break;
                case 3:
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(40,4);
                    printf("Busqueda por Numero de Habitacion");
                    gotoxy(8,6);
                    printf("Ingrese numero de habitacion a buscar: ");
                    scanf("%d",&bNumHab);
                    flag = busquedaPorHabitacion("Reservas.bin",bNumHab);
                    if(flag !=1)
                    {
                        gotoxy(8,8);
                        printf("El numero de Habitacion no se encuentra registrada en una reserva...");
                    }
                    printf("\n\n");
                    system("PAUSE");
                    break;
                case 4:
                    system("cls");
                    gotoxy(50,2);
                    printf("HOTEL YAPEYU");
                    gotoxy(40,4);
                    printf("Busqueda por Tipo de Habitacion");
                    gotoxy(8,6);
                    printf("Ingrese tipo de habitacion a buscar: ");
                    fflush(stdin);
                    gets(bTipoHab);
                    flag = busquedaPorTipoHabitacion("Reservas.bin",bTipoHab);
                    if(flag !=1)
                    {
                        gotoxy(8,8);
                        printf("El tipo de Habitacion no se encuentra registrada en una reserva...");
                    }

                    printf("\n\n");
                    system("PAUSE");
                    break;
                case 0:
                    break;
                default:
                    printf("La opcion ingresada no existe...");
                    system("PAUSE");
                    break;
                }
            }
            while(op4!=0);
            break;

        ///---------------------5) CANCELAR RESERVA---------------------------------///

        case 5:
            system("cls");
            gotoxy(50,2);
            printf("HOTEL YAPEYU");
            gotoxy(47,4);
            printf("Cancelar Reserva");
            printf("\n\nHabitaciones Ocupadas: \n\n");
            mostrarOcupadas("Habitaciones.bin");
            gotoxy(8,9);
            printf("\nIngrese el numero de habitacion: ");
            scanf("%d", &bNumHab);
            flag = busquedaPorHabitacion("Reservas.bin",bNumHab);
            if(flag !=1)
            {
                gotoxy(8,10);
                printf("\nEl numero de Habitacion no se encuentra registrada en una reserva...");
            }
            else
            {
                printf("\nSeguro desea cancelar la reserva? Presione 's' o 'n': ");
                fflush(stdin);
                scanf("%c",&seguro);
            }

            if(seguro=='s'||seguro=='S')
            {
                borrarRegistro(bNumHab);
                printf("\nReserva cancelada exitosamente!");
            }
            else if(seguro=='n'||seguro=='N')
            {
                printf("\nUsted ha decidido no cancelar la reserva...");
            }
            getch();
            break;
        }
    }
    while(op!=0);
}

void cargarReserva(char archivoReserva[])
{
    stReserva reserva;
    fflush(stdin);
    FILE *archi = fopen(archivoReserva,"ab");
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

        while(reserva.cantidadPersonas>tipoHab)
        {
            gotoxy(8,10);
            printf("El maximo de personas para la habitacion es %d. Ingrese nuevamente: ",tipoHab);
            scanf("%d",&reserva.cantidadPersonas);
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

        reserva.serviciosReserva.pensionComida = valorPension(pension);

        char a,b,c;
        gotoxy(8,14);
        printf("Tipos de Servicios: ");

        gotoxy(10,15);
        printf("- GYM (s/n) : ");
        fflush(stdin);
        scanf("%c",&a);
        validacion(a,10,16);

        gotoxy(10,17);
        printf("- SPA (s/n) : ");
        fflush(stdin);
        scanf("%c",&b);
        validacion(b,10,18);

        gotoxy(10,19);
        printf("- Estacionamiento(s/n) :");
        fflush(stdin);
        scanf("%c",&c);
        validacion(c,10,20);


        reserva.serviciosReserva.estacionamiento = valorEstacionamiento(c,reserva);
        reserva.serviciosReserva.servicio = valorDeServicios(a,b);

        system("cls");
        gotoxy(50,2);
        printf("HOTEL YAPEYU");
        gotoxy(48,4);
        printf("RESERVA - CLIENTE");

        int x=8, y=7, num=1;
        for(int k=0; k<reserva.cantidadPersonas; k++)
        {
            printf("\nPersona %d de %d:",num,reserva.cantidadPersonas);
            reserva=cargarFamilia(reserva,k,x,y);
            y+=8;
            num++;
        }

        system("cls");
        gotoxy(50,2);
        printf("HOTEL YAPEYU");
        gotoxy(40,4);
        printf("RESERVA - HABITACIONES DISPONIBLES");

        gotoxy(8,8);
        printf("Habitaciones %s disponibles: \n",reserva.habitacionReserva.tipoHabitacion);
        mostrarPorTipodeHabitaciones("Habitaciones.bin",reserva.habitacionReserva.tipoHabitacion);

        printf("\n\nElija numero de habitacion a hospedar: ");
        scanf("%d",&reserva.habitacionReserva.numHabitacion);
        int veriDispo=1,veriTipo=1;

        do
        {
            veriDispo= verificacionHabitacionDisponible("Habitaciones.bin",reserva.habitacionReserva.numHabitacion);
            veriTipo = verificarPorTipoHabitacion(reserva.habitacionReserva.numHabitacion,reserva.habitacionReserva.tipoHabitacion);
            if(veriDispo!=1 || veriTipo!=1)
            {
                gotoxy(8,12);
                printf("Habitacion no disponible o no se encuentra dentro del tipo de habitacion '%s'... Elija nuevamente: ",reserva.habitacionReserva.tipoHabitacion);
                scanf("%d",&reserva.habitacionReserva.numHabitacion);
            }
        }
        while(veriDispo!=1 || veriTipo!=1);

        modificarDisponibilidad("Habitaciones.bin",reserva.habitacionReserva.numHabitacion);

        float total = precioTotal(reserva,vHabitacion);

        system("cls");
        gotoxy(50,2);
        printf("HOTEL YAPEYU");
        gotoxy(43,4);
        printf("RESERVA - RESUMEN DE PAGO ");
        gotoxy(10,8);
        printf("Valor de Habitacion por noche ($ %d)", vHabitacion);
        gotoxy(50,8);
        printf("$ %d",vHabitacion*reserva.cantNoches);
        gotoxy(10,10);
        printf("Valor de Servicios ");
        gotoxy(50,10);
        printf("$ %d",reserva.serviciosReserva.servicio);
        gotoxy(10,12);
        printf("Valor de Pension ");
        gotoxy(50,12);
        printf("$ %d",reserva.serviciosReserva.pensionComida);
        gotoxy(10,14);
        printf("Valor Estacionamiento por noche($ 25)");
        gotoxy(50,14);
        printf("$ %d",reserva.serviciosReserva.estacionamiento);
        gotoxy(10,16);
        printf("PRECIO TOTAL");
        gotoxy(10,16);
        printf("----------------------------------------------------");
        gotoxy(50,18);
        printf("$ %.2f",total);
        gotoxy(10,22);
        printf("Elija metodo de pago (Efectivo / Debito / Credito): ");
        fflush(stdin);
        gets(reserva.pagoReserva.tipoPago);

        float precioFinal;

        while(strcmpi(reserva.pagoReserva.tipoPago,"Efectivo")!=0 && strcmpi(reserva.pagoReserva.tipoPago,"Debito")!=0 && strcmpi(reserva.pagoReserva.tipoPago,"Credito")!=0)
        {
            gotoxy(10,21);
            printf("Metodo de Pago Inexistente! Por favor, ingrese nuevamente: ");
            fflush(stdin);
            gets(reserva.pagoReserva.tipoPago);
        }

        if(strcmpi(reserva.pagoReserva.tipoPago,"Credito")==0)
        {
            gotoxy(10,23);
            printf("Opciones de cuotas: ");
            gotoxy(10,25);
            printf("- 3  cuotas de $ %.2f  (15%% de recargo)",(total*1.15)/3);
            gotoxy(10,26);
            printf("- 6  cuotas de $ %.2f  (20%% de recargo)",(total*1.20)/6);
            gotoxy(10,27);
            printf("- 9  cuotas de $ %.2f  (25%% de recargo)",(total*1.25)/9);
            gotoxy(10,28);
            printf("- 12 cuotas de $ %.2f  (30%% de recargo)",(total*1.30)/12);
            gotoxy(10,30);
            printf("Seleccione cantidad de cuotas: ");
            scanf("%d",&reserva.pagoReserva.cuotas);
            while(reserva.pagoReserva.cuotas!=3 && reserva.pagoReserva.cuotas!=6 && reserva.pagoReserva.cuotas!=9 && reserva.pagoReserva.cuotas!=12)
            {
                gotoxy(10,31);
                printf("Error! Intente nuevamente: ");
                scanf("%d",&reserva.pagoReserva.cuotas);
            }
            gotoxy(10,33);
        }
        else
        {
            gotoxy(10,23);
        }

        precioFinal = tipoDePago(reserva.pagoReserva.tipoPago,total,reserva.pagoReserva.cuotas);

        printf("El Precio Final Total es: $%.2f",precioFinal);

        reserva.precioTotal = precioFinal;

        fwrite(&reserva,sizeof(stReserva),1,archi);
        fclose(archi);
    }
}

int valorEstacionamiento(char c,stReserva A)
{
    int v;
    if(c == 's'||c =='S')
    {
        v = 25 * A.cantNoches;
    }
    else
    {
        v=0;
    }
    return v;
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
            mostrarDeAUno(A);
            printf("\n");
        }

        fclose(archi);
    }
    else
    {
        printf("\n\nEl archivo no existe...");
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
    else if((a=='n'|| a=='N') && (b=='n' || b=='N'))
    {
        valor=0;
    }

    return valor;
}

void validacion(char a,int x,int y)
{
    while(a!='s'&& a!='S' && a!='n'&& a!='N')
    {
        gotoxy(x,y);
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

int valorPension(char pension[])
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
        for(num = 1; num <=55; num++)
        {
            if(num<=43 && num%2==1)
            {
                room.numHabitacion=num;
                strcpy(room.tipoHabitacion,"Doble");
                room.precioHabitacion= 250;
                room.disponibilidad='s';

            }
            else if(num<=44 && num%2==0)
            {
                room.numHabitacion=num;
                strcpy(room.tipoHabitacion,"Triple");
                room.precioHabitacion= 375;
                room.disponibilidad='s';

            }
            else if(num>=45 && num<=49)
            {
                room.numHabitacion=num;
                strcpy(room.tipoHabitacion,"Cuadruple");
                room.precioHabitacion= 500;
                room.disponibilidad='s';
            }
            else if(num>=50 && num<=55)
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
    int i=0;
    FILE *archi = fopen(archivoHabitaciones,"rb");
    if(archi!=NULL)
    {
        while(fread(&room,sizeof(stHabitacion),1,archi)>0)
        {
            if((room.numHabitacion<=43 && room.numHabitacion%2==1) && (room.disponibilidad=='s'||room.disponibilidad=='S'))
            {
                if(i>2)
                {
                    printf("\n");
                    i=0;
                }
                if(room.numHabitacion<10)
                {
                    printf("[ 0%d ]", room.numHabitacion);
                }
                else
                    printf("[ %d ]", room.numHabitacion);
                i++;
            }
        }
        fclose(archi);
    }
    else
    {
        printf("El archivo no existe...");
    }
}

void mostrarTriplesDisponibles(char archivoHabitaciones[])
{
    stHabitacion room;
    FILE *archi = fopen(archivoHabitaciones,"rb");
    int i=0;
    if(archi!=NULL)
    {
        while(fread(&room,sizeof(stHabitacion),1,archi)>0)
        {
            if((room.numHabitacion<=44 && room.numHabitacion%2==0) && (room.disponibilidad=='s'||room.disponibilidad=='S'))
            {
                if(i>2)
                {
                    printf("\n");
                    i=0;
                }
                if(room.numHabitacion<10)
                {
                    printf("[ 0%d ]", room.numHabitacion);
                }
                else
                    printf("[ %d ]", room.numHabitacion);
                i++;
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
                printf("[ %d ]",room.numHabitacion);
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
                printf("[ %d ]",room.numHabitacion);
            }
        }
        fclose(archi);
    }
}

void mostrarPorTipodeHabitaciones(char archivoHabitaciones[],char tipo[])
{
    stHabitacion room;
    FILE *archi = fopen(archivoHabitaciones,"rb");
    int i=0;
    if(archi!=NULL)
    {
        while(fread(&room,sizeof(stHabitacion),1,archi)>0)
        {
            if((room.disponibilidad=='s'||room.disponibilidad=='S') && strcmpi(room.tipoHabitacion,tipo)==0)
            {
                printf ("\n");
                printf("                    [ %d ]", room.numHabitacion);
                i=0;
                while(fread(&room,sizeof(stHabitacion),1,archi)>0 && i < 4)
                {
                    if((room.disponibilidad=='s'||room.disponibilidad=='S') && strcmpi(room.tipoHabitacion,tipo)==0)
                    {
                        printf("[ %d ]", room.numHabitacion);
                    }
                    i++;
                }

            }
        }
        fclose(archi);
    }
}

void modificarDisponibilidad(char archivoHabitaciones[],int numHab)
{
    stHabitacion A;
    int pos = busquedaPosicionHab(archivoHabitaciones,numHab);
    FILE *archi = fopen(archivoHabitaciones,"r+b");
    if(archi!=NULL)
    {
        fseek(archi,sizeof(stHabitacion)*(pos-1),SEEK_SET);
        fread(&A,sizeof(stHabitacion),1,archi);

        A = cambioDisponibilidad(A);

        fseek(archi,sizeof(stHabitacion)*(pos-1),SEEK_SET);
        fwrite(&A,sizeof(stHabitacion),1,archi);

        fclose(archi);
    }
}

stHabitacion cambioDisponibilidad(stHabitacion A)
{
    if(A.disponibilidad=='s'||A.disponibilidad=='S')
        A.disponibilidad='n';
    else if(A.disponibilidad=='n'||A.disponibilidad=='N')
        A.disponibilidad='s';
    return A;
}

int busquedaPosicionHab(char archivoHabitaciones[],int numHab)
{
    int pos,i=1;
    FILE *archi=fopen(archivoHabitaciones,"rb");
    stHabitacion A;
    if(archi!=NULL)
    {
        while(fread(&A,sizeof(stHabitacion),1,archi)>0)
        {
            if(A.numHabitacion==numHab)
            {
                pos=i;
            }
            i++;
        }
        fclose(archi);
    }
    else
    {
        printf("\nEl archivo no existe....");
    }
    return pos;
}

int verificacionHabitacionDisponible(char archivoHabitaciones[],int numHab)
{
    stHabitacion room;
    int estado=0;
    FILE *archi = fopen(archivoHabitaciones,"rb");
    if(archi!=NULL)
    {
        int pos = busquedaPosicionHab(archivoHabitaciones,numHab);
        fseek(archi,sizeof(stHabitacion)*(pos-1),SEEK_SET);
        fread(&room,sizeof(stHabitacion),1,archi);
        if(room.disponibilidad=='s'||room.disponibilidad=='S')
        {
            estado = 1;
        }
        fclose(archi);
    }
    return estado;
}

int verificarPorTipoHabitacion(int numHab,char tipoHab[])
{
    int estado = 0;
    if((numHab<=43 && numHab%2==1)&& strcmpi(tipoHab,"Doble")==0)
    {
        estado=1;
    }
    else if((numHab<=44 && numHab%2==0)&& strcmpi(tipoHab,"Triple")==0)
    {
        estado=1;
    }
    else if((numHab>=45 && numHab<=49)&& strcmpi(tipoHab,"Cuadruple")==0)
    {
        estado=1;
    }
    else if((numHab>=50 && numHab<=55)&& strcmpi(tipoHab,"Suite")==0)
    {
        estado=1;
    }

    return estado;
}

float tipoDePago(char tipo[],float total,int cuotas)
{
    float precio,precioCuota;
    if(strcmpi(tipo,"Credito")==0)
    {
        if(cuotas==3)
        {
            precioCuota=(total*1.15)/3;
            precio=precioCuota*3;
        }
        else if(cuotas==6)
        {
            precioCuota=(total*1.20)/6;
            precio=precioCuota*6;
        }
        else if(cuotas==9)
        {
            precioCuota=(total*1.25)/9;
            precio=precioCuota*9;
        }
        else if(cuotas==12)
        {
            precioCuota=(total*1.30)/12;
            precio=precioCuota*12;
        }
    }
    else
    {
        precio = total;
    }
    return precio;
}

float precioTotal(stReserva A,int vHabitacion)
{
    float total;

    total = A.serviciosReserva.servicio + (float)A.cantNoches*vHabitacion + A.serviciosReserva.pensionComida + A.serviciosReserva.estacionamiento;

    return total;
}

int busquedaPorDNI(char archivo[],int buscado)
{
    int flag =0;
    stReserva A;
    FILE *archi = fopen(archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&A,sizeof(stReserva),1,archi)>0)
        {
            for(int i=0; i<A.cantidadPersonas; i++)
            {
                if(A.clienteReserva[i].dni==buscado)
                {
                    mostrarDeAUno(A);
                    printf("\n");
                    flag = 1;
                }
            }
        }
        fclose(archi);
    }
    return flag;
}

void mostrarDeAUno(stReserva A)
{
    printf("\n---------------- Numero de Habitacion: %d ----------------",A.habitacionReserva.numHabitacion);

    for(int i=0; i<A.cantidadPersonas; i++)
    {
        printf("\nHuesped %d: ",i+1);
        printf("\n- Nombre y Apellido     : %s",A.clienteReserva[i].nombre);
        printf("\n- Documento             : %d",A.clienteReserva[i].dni);
        printf("\n- Edad                  : %d",A.clienteReserva[i].edad);
    }
    printf("\n             ----");
    printf("\n- Cantidad de Noches    : %d",A.cantNoches);
    if(A.serviciosReserva.pensionComida==50)
        printf("\n- Pension de Comida     : Media");
    else
        printf("\n- Pension de Comida     : Completa");

    if(A.serviciosReserva.servicio==100)
    {
        printf("\n- Servicios             : Gym y Spa");
    }
    else if(A.serviciosReserva.servicio==70)
    {
        printf("\n- Servicios             : Spa");
    }
    else if(A.serviciosReserva.servicio==50)
    {
        printf("\n- Servicios             : Gym");
    }
    else
    {
        printf("\n- Servicios             : No");
    }
    printf("\n- Tipo de Habitacion    : %s",A.habitacionReserva.tipoHabitacion);
    printf("\n- Cantidad de Personas  : %d",A.cantidadPersonas);
    printf("\n- Tipo de Pago          : %s",A.pagoReserva.tipoPago);
    if(strcmpi(A.pagoReserva.tipoPago,"Credito")==0)
    {
        printf("\n- Pago en %d Cuotas", A.pagoReserva.cuotas);
    }
    if(A.serviciosReserva.estacionamiento !=0)
    {
        printf("\n- Estacionamiento       : Si");
    }
    else
    {
        printf("\n- Estacionamieto        : No");
    }
    printf("\n- Precio Final          : %.2f",A.precioTotal);
}

int busquedaPorNombre(char archivo[],char buscado[])
{
    stReserva A;
    int flag = 0;
    FILE *archi = fopen(archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&A,sizeof(stReserva),1,archi)>0)
        {
            for(int i=0; i<A.cantidadPersonas; i++)
            {
                if(strcmpi(A.clienteReserva[i].nombre,buscado)==0)
                {
                    mostrarDeAUno(A);
                    printf("\n");
                    flag = 1;
                }
            }
        }
        fclose(archi);
    }
    return flag;
}

int busquedaPorHabitacion(char archivo[],int buscado)
{
    int flag;
    stReserva A;
    FILE*archi=fopen(archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&A,sizeof(stReserva),1,archi)>0)
        {
            if(A.habitacionReserva.numHabitacion == buscado)
            {
                mostrarDeAUno(A);
                printf("\n");
                flag = 1;
            }
        }
        fclose(archi);
    }
    return flag;
}

int busquedaPorTipoHabitacion(char archivo[],char buscado[])
{
    int flag=0;
    stReserva A;
    FILE *archi =fopen(archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&A,sizeof(stReserva),1,archi)>0)
        {
            if(strcmpi(A.habitacionReserva.tipoHabitacion,buscado)==0)
            {
                mostrarDeAUno(A);
                printf("\n");
                flag = 1;
            }
        }
        fclose(archi);
    }
    return flag;
}

void borrarRegistro(int bNumHab)
{
    FILE *archi = fopen("Reservas.bin","rb");
    if(archi==NULL)
        exit(1);
    stReserva A;

    FILE *nuevo = fopen("Reservas.tmp","ab");
    if(archi==NULL)
        exit(1);

    int existe=0;
    fread(&A,sizeof(stReserva),1,archi);
    while(!feof(archi))
    {
        if(bNumHab==A.habitacionReserva.numHabitacion)
        {
            printf("La reserva eliminada es de la habitacion: %d",A.habitacionReserva.numHabitacion);
            existe = 1;
        }
        else
        {
            fwrite(&A,sizeof(stReserva),1,nuevo);
        }
        fread(&A,sizeof(stReserva),1,archi);
    }

    if(existe==0)
    {
        printf("La habitacion no esta cargada...");
    }
    fclose(archi);
    fclose(nuevo);
    remove("Reservas.bin");
    rename("Reservas.tmp","Reservas.bin");
    modificarDisponibilidad("Habitaciones.bin",bNumHab);
}

void mostrarOcupadas(char archivoHabitacion[])
{
    stHabitacion room;
    FILE *archi =fopen(archivoHabitacion,"rb");
    if(archi!=NULL)
    {
        while(fread(&room,sizeof(stHabitacion),1,archi)>0)
        {
            if(room.disponibilidad=='N'||room.disponibilidad=='n')
            {
                printf("[ %d ]",room.numHabitacion);
            }
        }
        fclose(archi);
    }
}

int cantidadRegistros(char archivo[])
{
    int cant;
    FILE *archi = fopen(archivo,"rb");
    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        cant = ftell(archi)/sizeof(stReserva);
        fclose(archi);
    }
    return cant;
}

void ordenarArray(stReserva A[], int validos)
{
    int menor, i=0;
    stReserva aux;
    while (i < validos)
    {
        menor = i;
        for (int j=i+1; j < validos; j++)
        {
            if (A[menor].habitacionReserva.numHabitacion > A[j].habitacionReserva.numHabitacion)
            {

                menor = j;
            }
        }
        aux = A[i];
        A[i] = A[menor];
        A[menor] = aux;
        i++;
    }
}

void array_A_archivo(char archivo[],stReserva A[],int val)
{
    FILE *archi = fopen(archivo,"wb");
    stReserva aux;
    if(archi!=NULL)
    {
        for(int i=0; i<val; i++)
        {
            aux = A[i];
            fwrite(&aux,sizeof(stReserva),1,archi);
        }
        fclose(archi);
    }
}

int archivo_A_array(char archivo[],stReserva A[])
{
    FILE *archi = fopen(archivo,"rb");
    stReserva aux;
    int i=0;
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(stReserva),1,archi)>0)
        {
            A[i]=aux;
            i++;
        }
        fclose(archi);
    }
    return i;
}

void ordenarPorHabitacion(char archivo[])
{
    stReserva A[100];
    int val = archivo_A_array(archivo,A);
    ordenarArray(A,val);
    array_A_archivo(archivo,A,val);
}

int verificacionHuesped(char archivo[],int numHab,int huesped)
{
    int pos = busquedaHabitacionposicion(archivo,numHab);
    FILE *archi = fopen(archivo,"rb");
    int flag = 0;
    stReserva A;
    if(archi!=NULL)
    {
        fseek(archi,sizeof(stReserva)*(pos-1),0);
        fread(&A,sizeof(stReserva),1,archi);
        if(huesped<=0 || huesped>A.cantidadPersonas)
            flag = 1;
        else
            flag=0;
        fclose(archi);
    }
    return flag;
}

void modificarNombreHuesped(char archivo[],int numHab,int huesped)
{
    int i = (huesped - 1);
    int pos = busquedaHabitacionposicion(archivo,numHab);
    FILE *archi = fopen(archivo,"r+b");
    stReserva A;
    if(archi!=NULL)
    {
        fseek(archi,sizeof(stReserva)*(pos-1),SEEK_SET);
        fread(&A,sizeof(stReserva),1,archi);

        gotoxy(68,8);
        printf("Ingrese nuevo Nombre y Apellido: ");
        fflush(stdin);
        gets(A.clienteReserva[i].nombre);

        fseek(archi,sizeof(stReserva)*(pos-1),SEEK_SET);
        fwrite(&A,sizeof(stReserva),1,archi);
    }
    fclose(archi);
}

int busquedaHabitacionposicion(char archivo[],int numHab)
{
    stReserva A;
    int pos,i=1,flag=0;
    FILE *archi = fopen(archivo,"rb");
    if(archi!=NULL)
    {
        while((fread(&A,sizeof(stReserva),1,archi)>0) && flag ==0)
        {
            if(A.habitacionReserva.numHabitacion==numHab)
            {
                pos  = i;
                flag = 1;
            }
            i++;
        }
        fclose(archi);
    }
    return pos;
}

void modificarEdadHuesped(char archivo[],int numHab,int huesped)
{
    int i = (huesped - 1);
    int pos = busquedaHabitacionposicion(archivo,numHab);
    FILE *archi = fopen(archivo,"r+b");
    stReserva A;
    if(archi!=NULL)
    {
        fseek(archi,sizeof(stReserva)*(pos-1),SEEK_SET);
        fread(&A,sizeof(stReserva),1,archi);

        gotoxy(68,8);
        printf("Ingrese nueva Edad: ");
        scanf("%d",&A.clienteReserva[i].edad);

        fseek(archi,sizeof(stReserva)*(pos-1),SEEK_SET);
        fwrite(&A,sizeof(stReserva),1,archi);
    }
    fclose(archi);
}

void modificarDocumento(char archivo[],int numHab,int huesped)
{
    int i = (huesped - 1);
    int pos = busquedaHabitacionposicion(archivo,numHab);
    FILE *archi = fopen(archivo,"r+b");
    stReserva A;
    if(archi!=NULL)
    {
        fseek(archi,sizeof(stReserva)*(pos-1),SEEK_SET);
        fread(&A,sizeof(stReserva),1,archi);

        gotoxy(68,8);
        printf("Ingrese nuevo DNI: ");
        scanf("%d",&A.clienteReserva[i].dni);

        fseek(archi,sizeof(stReserva)*(pos-1),SEEK_SET);
        fwrite(&A,sizeof(stReserva),1,archi);
    }
    fclose(archi);
}

void modificarGymSpa(char archivo[],int numHab)
{
    int pos = busquedaHabitacionposicion(archivo,numHab);
    FILE *archi = fopen(archivo,"r+b");
    stReserva A;
    char a,b;
    if(archi!=NULL)
    {
        fseek(archi,sizeof(stReserva)*(pos-1),0);
        fread(&A,sizeof(stReserva),1,archi);

        gotoxy(68,8);
        printf("- Ingrese uso de Gym (s/n): ");
        fflush(stdin);
        scanf("%c",&a);
        validacion(a,68,9);
        gotoxy(68,10);
        printf("- Ingrese uso de Spa (s/n): ");
        fflush(stdin);
        scanf("%c",&b);
        validacion(a,68,10);

        A.serviciosReserva.servicio=valorDeServicios(a,b);

        fseek(archi,sizeof(stReserva)*(pos-1),0);
        fwrite(&A,sizeof(stReserva),1,archi);
        fclose(archi);
    }
}
