#include "Usuario.h"
#include "Libro.h"
#include <iostream>
#include<cstdlib>
#include <string>
#include <array>
using namespace std;

int menuInic();
int menu();
int menuAdmin();
//inicialice un arreglo 
Usuario** inicializar(int);
//imprimir el contenido del arreglo
void printArray(Usuario**, int);
//libere la memoria del arreglo
void freeArray(Usuario**);
//leer el contenido
void readArray(Usuario**,int,int);

Libro** inicializarLibro(int);
//imprimir el contenido del arreglo
void printArrayLibro(Libro**, int);
//libere la memoria del arreglo
void freeArrayLibro(Libro**);
//leer el contenido
void readArrayLibro(Libro**,int,int);

Usuario* newUsuario();

Libro* newLibro();
void modLibro(Libro**,int);

void Ordenar(Libro**);


int main()
{
	int resp=-1;
	int resp_user=-1;
	int opc_menu=-1;
	int opc=-1;
	int cont_user=1;
	int cont_libro=0;
	int tam=10;
	int opc_user=-1;
	int posi=-6;
	Usuario** lista = inicializar(tam);
	Usuario* usuario;
	string user, pass; /*names;
	int edad;
	double dinero;*/
	usuario=new Usuario("n.duron","sybase","Nicolle Duron",20,1000.00);
	lista[0]=usuario;
	Libro** listaL = inicializarLibro(tam);
	Libro* libro;

	string title, autor, a_pub, estado;
	double precio;
	string titulo;
	Libro* book;
	int compra;

	int pos_mod=-1;
	do
	{
		readArray(lista,tam,cont_user);
		//printArray(lista,tam);
		//freeArray(lista);

		readArrayLibro(listaL,tam,cont_libro);
		//printArrayLibro(listaL,tam);
		//freeArrayLibro(listaL);
		switch(opc_menu=menuInic()){
			case 1:
				cout<<"Usuario: ";
				cin>>user;
				cout<<"Contrasenia: ";
				cin>>pass;
				opc=-1;
				if (user=="n.duron" && pass=="sybase")
				{
					//cout<<"Admin"<<endl;
					do
					{
						switch(opc=menuAdmin()){
							case 1:
								for (int i = 0; i < cont_libro; ++i)
								{
									if(listaL[i]->getAutor()==" "){
										posi=i;
									}
								}
								if (posi!=-6)
								{
									listaL[posi]=newLibro();	
								}
								else if(posi==-6){
									listaL[cont_libro]=newLibro();
									cont_libro++;
								}
								else{}

								printArrayLibro(listaL,tam);
								break;

							case 2:
								printArrayLibro(listaL,tam);
								cout<<"\nIngrese la Posicion a Modificar: ";
								cin>>pos_mod;
								//modLibro(&listaL[0],pos_mod);
								//
								//
								//
								
								for (int i = 0; i < 10; ++i)
								{
									listaL[pos_mod]=new Libro();
									if(i==pos_mod){
										cout<<"Titulo: ";
										getline(cin,title);
										getline(cin,title);
										cout<<"Autor: ";
										getline(cin,autor);
										getline(cin,autor);
										cout<<"Anio de publicacion: ";
										cin>>a_pub;
										cout<<"Precio: ";
										cin>>precio;
										cout<<"Estado: ";
										cin>>estado;
										while(precio<0){
											cout<<"Ingrese un Valor Valido"<<endl;
											cout<<"Precio: ";
											cin>>precio;
										}
										cout<<endl;
										libro = new Libro(title,autor,a_pub,precio,estado);
									}
								}
								listaL[pos_mod]=libro;
							printArrayLibro(listaL,tam);
								pos_mod=-1;
								break;

							case 3:
								printArrayLibro(listaL,tam);
								cout<<"\nIngrese la Posicion a Eliminar: ";
								cin>>pos_mod;
								listaL[pos_mod]=new Libro();
								printArrayLibro(listaL,tam);
								pos_mod=-1;
								break;

							case 4:
								freeArrayLibro(listaL);
								break;
						}
						cout<<"Desea volver al programa como Admin\n1.Si\n2.No"<<endl;
						cin>>resp_user;
					} while (resp_user!=2);
					resp_user=-1;
				}
				else{
					for (int i = 1; i < 10; i++)
					{
						if (user==lista[i] -> getUser() && pass==lista[i]->getPass())
						{
							do
							{
								switch(opc_user=menu()){
									case 1:
										printArrayLibro(listaL,tam);
										cout<<"\nIngrese la Posicion a Comprar: ";
										cin>>pos_mod;
										if (lista[i]->getDinero()<listaL[pos_mod]->getPrecio() || listaL[pos_mod]->getEstado()=="Vendido")
										{
											cout<<"No se puede comprar"<<endl;
										}
										else{
											cout<<"Comprado"<<endl;
										}
										break;

									case 2:
										cout<<"Ingrese el Autor: ";
										cin>>autor;
										for (int i = 0; i < 10; ++i)
										{
											if(listaL[i]->getAutor()==autor)
											{
												cout<<"Desea Comprarlo\n1.Si\n2.No"<<endl;
												cin>>compra;
												if (compra==1)
												{
													if (lista[i]->getDinero()<listaL[pos_mod]->getPrecio() || listaL[pos_mod]->getEstado()=="Vendido")
													{
														cout<<"No se puede comprar"<<endl;
													}
													else{
														cout<<"Comprado"<<endl;
													}
												}
											}
										}
										break;

									case 3:
										cout<<"Ingrese el Titulo: ";
										cin>>titulo;
										for (int i = 0; i < 10; ++i)
										{
											if(listaL[i]->getTitle()==titulo)
											{
												cout<<"Desea Comprarlo\n1.Si\n2.No"<<endl;
												cin>>compra;
												if (compra==1)
												{
													if (lista[i]->getDinero()<listaL[pos_mod]->getPrecio() || listaL[pos_mod]->getEstado()=="Vendido")
													{
														cout<<"No se puede comprar"<<endl;
													}
													else{
														cout<<"Comprado"<<endl;
													}
												}
											}
										}
										break;

									case 4:
										break;

									case 5:
										break;

									case 6:
										break;
								}
								cout<<"Desea volver al programa como Usuario\n1.Si\n2.No"<<endl;
								cin>>resp_user;
							} while (resp_user!=2);
							resp_user=-1;
						}
					}
				}
				break;

			case 2:
				lista[cont_user]=newUsuario();
				cont_user++;
				//printArray(lista,tam);
				break;

			case 3:
				break;
		}

		cout<<"Desea volver al programa \n1.Si\n2.No"<<endl;
		cin>>resp;
	} while (resp!=2);
	freeArray(lista);
	freeArrayLibro(listaL);//no me lo muestra
	delete usuario;
	return 0;
}

int menuInic(){//inicio metodo menu
    while(true){
        cout<<"Menu\n1.Ingresar\n2.Registrar"<<endl;
        cout<<"Ingrese una opcion: ";
        int opcion =0;
        cin>>opcion;
        if(opcion>=1 && opcion<= 2){
                return opcion;
        }
		else{
        	cout<<"La opcion elegida no es valida, ingrese una opcion entre 1 y 2"<<endl;
        }
 	}//end del while
        return 0;
}//fin metodo menu

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
		<<"4.- Borrar Registro de Libros"<<endl;
        cout<<"Ingrese una opcion: ";
        int opcion =0;
        cin>>opcion;
        if(opcion>=1 && opcion<= 4){
                return opcion;
        }
		else{
        	cout<<"La opcion elegida no es valida, ingrese una opcion entre 1 y 4"<<endl;
        }
 	}//end del while
        return 0;
}//fin metodo menu

Usuario** inicializar( int size){//inicio inicializar
	Usuario** retval = new Usuario*[size];
	return retval;
}//fin inicializar

void printArray (Usuario** array, int size){//inicio print array
	for(int i=0; i<size;i++){
		cout<<i<<": ";
		array[i]->toString();
	}
	cout<<endl;
}//fin print array

void freeArray(Usuario** array){//inicio free array
	if (array!=NULL){
		delete[] array;
	}
}//fin free array

void readArray(Usuario** array,int size, int pos){//inicio read array
	for(int i=pos; i<size;i++){
		array[i]= new Usuario();
	}
}//fin read array


Libro** inicializarLibro( int size){//inicio inicializar
	Libro** retval = new Libro*[size];
	return retval;
}//fin inicializar

void printArrayLibro (Libro** array, int size){//inicio print array
	for(int i=0; i<size;i++){
		cout<<i<<": ";
		array[i]->toString();
	}
	cout<<endl;
}//fin print array

void freeArrayLibro(Libro** array){//inicio free array
	if (array!=NULL){
		delete[] array;
	}
}//fin free array

void readArrayLibro(Libro** array,int size,int pos){//inicio read array
	for(int i=pos; i<size;i++){
		array[i]= new Libro();
	}
}//fin read array


Usuario* newUsuario(){
	string user, pass, names;
	int edad;
	double dinero;
	Usuario* usuario;
	cout<<"Usuario: ";
	cin>>user;
	cout<<"Contrasenia: ";
	cin>>pass;
	cout<<"Nombre: ";
	getline(cin,names);
	getline(cin,names);
	cout<<"Edad: ";
	cin>>edad;
	cout<<"Dinero: ";
	cin>>dinero;
	while(dinero<0){
		cout<<"Ingrese un Valor Valido"<<endl;
		cout<<"Dinero: ";
		cin>>dinero;
	}
	cout<<endl;
	usuario=new Usuario(user,pass,names,edad,dinero);
	return usuario;
}

Libro* newLibro(){
	string title, autor, a_pub, estado;
	double precio;
	Libro* libro;
	cout<<"Titulo: ";
	getline(cin,title);
	getline(cin,title);
	cout<<"Autor: ";
	getline(cin,autor);
	getline(cin,autor);
	cout<<"Anio de publicacion: ";
	cin>>a_pub;
	cout<<"Precio: ";
	cin>>precio;
	while(precio<0){
		cout<<"Ingrese un Valor Valido"<<endl;
		cout<<"Precio: ";
		cin>>precio;
	}
	cout<<endl;
	libro = new Libro(title,autor,a_pub,precio,"Disponible");
	return libro;
}

void modLibro(Libro** array,int pos){
	string title, autor, a_pub, estado;
	double precio;
	Libro* libro=array[pos];
	for (int i = 0; i < 10; ++i)
	{
		if(i==pos){
			cout<<"Titulo: ";
			getline(cin,title);
			getline(cin,title);
			cout<<"Autor: ";
			getline(cin,autor);
			getline(cin,autor);
			cout<<"Anio de publicacion: ";
			cin>>a_pub;
			cout<<"Precio: ";
			cin>>precio;
			cout<<"Estado: ";
			cin>>estado;
			while(precio<0){
				cout<<"Ingrese un Valor Valido"<<endl;
				cout<<"Precio: ";
				cin>>precio;
			}
			cout<<endl;
			libro->setTitle(title);
			//*(array[pos])->setAutor(autor);
			//*(array[pos])->setA_pub(a_pub);
			//*(array[pos])->setPrecio(precio);
			//*(array[pos])->setEstado(estado);
			//array[pos]=libro;
		}
	}
}

