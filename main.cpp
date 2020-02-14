#include "Usuario.h"
#include "Libro.h"
#include <iosstream>
#include <string>
using namespace std;

int menu();
int menuAdmin();
//inicialice un arreglo 
Usuario** inicializar(int);
//imprimir el contenido del arreglo
void printArray(Usuario**, int);
//libere la memoria del arreglo
void freeArray(Usuario**);
//leer el contenido
void readArray(Usuario**,int);

int main(int argc, char const *argv[])
{
	int resp=-1;
	int opc=-1;
	int tam=10;
	Usuario** lista = inicializar(tam);
	Usuario* usuario;
	string user, pass, names;
	int edad;
	double dinero;
	usuario=new Usuario("n.duron","sybase","Nicolle Duron",20,1000.00);
	lista[0]=usuario;
	do
	{

	} while (resp!=2);

	return 0;
}

int menu(){//inicio metodo menu
    while(true){
        cout<<"MENU"<<endl
        <<"1.- Comprar Libro"<<endl
        <<"2.- Buscar por Autor"<<endl
		<<"3.- Buscar por Titulo"<<endl
		<<"4.- Agregar Dinero a Mi Cuenta"<<endl
		<<"5.- Restablecer Contrasenia"<<endl
		<<"6.- Borrar Cuenta"<<endl;
        cout<<"Ingrese una opcion: ";
        int opcion =0;
        cin>>opcion;
        if(opcion>=1 && opcion<= 6){
                return opcion;
        }
		else{
        	cout<<"La opcion elegida no es valida, ingrese una opcion entre 1 y 6"<<endl;
        }
 	}//end del while
        return 0;
}//fin metodo menu


int menuAdmin(){//inicio metodo menu
    while(true){
        cout<<"MENU"<<endl
        <<"1.- Agregar Libro"<<endl
        <<"2.- Modificar Libro"<<endl
		<<"3.- Eliminar Libro"<<endl
		<<"4.- Borrar Registro de Libros"<<endl
		<<"5.- Listar"<<endl;
        cout<<"Ingrese una opcion: ";
        int opcion =0;
        cin>>opcion;
        if(opcion>=1 && opcion<= 5){
                return opcion;
        }
		else{
        	cout<<"La opcion elegida no es valida, ingrese una opcion entre 1 y 5"<<endl;
        }
 	}//end del while
        return 0;
}//fin metodo menu