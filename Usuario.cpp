#include "Usuario.h"
#include <iostream>
#include <string>
using std::string;
using namespace std;

Usuario::Usuario(){
	user="a";
	pass=" ";
	name=" ";
	edad=0;
	dinero=0.0;
}

Usuario::Usuario(string user, string pass, string name, int edad, double dinero){
	this -> user=user;
	this -> pass=pass;
	this -> name=name;
	this -> edad=edad;
	this -> dinero=dinero;
}

string Usuario::getUser(){
	return user;
}

void Usuario::setUSer(string user){
	user=user;
}

string Usuario::getPass(){
	return pass;
}

void Usuario::setPass(string pass){
	pass=pass;
}

string Usuario::getName(){
	return name;
}

void Usuario::setName(string name){
	name=name;
}

int Usuario::getEdad(){
	return edad;
}

void Usuario::setEdad(int edad){
	edad=edad;
}

double Usuario::getDinero(){
	return dinero;
}

void Usuario::setDinero(double dinero){
	dinero=dinero;
}

string Usuario::toString(){
	if (user=="a")
	{
		cout<<"Posicion Vacia"<<endl;
	}
	else{
		cout<<"Usuario: "<<user<<endl
		<<"Contrasenia: "<<pass<<endl
		<<"Nombre: "<<name<<endl
		<<"Edad: "<<edad<<endl
		<<"Dinero: "<<dinero<<endl;
		cout<<endl;
	}
	return "";
}

Usuario::~Usuario(){
	cout<<"Usuario Eliminado"<<endl;
}