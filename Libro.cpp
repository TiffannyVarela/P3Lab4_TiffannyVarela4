#include "Libro.h"
#include <iostream>
using namespace std;

Libro::Libro(){
	title="a";
	autor=" ";
	a_pub=" ";
	precio=0.0;
	estado=" ";
}

Libro::Libro(string title, string autor, string a_pub, double precio, string estado){
	this -> title=title;
	this -> autor=autor;
	this -> a_pub=a_pub;
	this -> precio=precio;
	this -> estado=estado;
}

string Libro::getTitle(){
	return title;
}

void Libro::setTitle(string title){
	title=title;
}

string Libro::getAutor(){
	return autor;
}

void Libro::setAutor(string autor){
	autor=autor;
}

string Libro::getA_pub(){
	return a_pub;
}

void Libro::setA_pub(string a_pub){
	a_pub=a_pub;
}

double Libro::getPrecio(){
	return precio;
}

void Libro::setPrecio(double precio){
	precio=precio;
}

string Libro::getEstado(){
	return estado;
}

void Libro::setEstado(string estado){
	estado=estado;
}

string Libro::toString(){
	if (title=="a")
	{
		cout<<"Posicion Vacia"<<endl;
	}
	else{
		cout<<"Titulo: "<<title<<endl
		<<"Autor: "<<autor<<endl
		<<"Anio de Publicacion: "<<a_pub<<endl
		<<"Precio: "<<precio<<endl
		<<"Estado: "<<estado<<endl;
	}
	return "";
}

Libro::~Libro(){
	cout<<"Libro Eliminado"<<endl;
}