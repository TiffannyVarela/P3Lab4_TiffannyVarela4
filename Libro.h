#include <typeinfo>
#include <string>
#ifndef LIBRO_H
#define LIBRO_H

class Libro
{
	private:
		string title, autor, a_pub, estado;
		double precio;
	public:
		Libro();
		Libro(string,string,string,double,string);

		string getTitle();
		void setTitle(string);

		string getAutor();
		void setAutor(string);

		string getA_pub();
		void setA_pub(string);

		double getPrecio();
		void setPrecio(double);

		string getEstado();
		void setEstado(string);

		~Libro();
	
};

#endif