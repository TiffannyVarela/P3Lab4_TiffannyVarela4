#include <typeinfo>
#include <string>
#ifndef LIBRO_H
#define LIBRO_H

class Libro
{
	private:
		string title, autor, a_pub, precio, estado;
	public:
		Libro();
		Libro(string,string,string,string,string);

		string getTitle();
		void setTitle(string);

		string getAutor();
		void setAutor(string);

		string getA_pub();
		void setA_pub(string);

		string getPrecio();
		void setPrecio(string);

		string getEstado();
		void setEstado(string);
		
		~Libro();
	
};

#endif