#include <typeinfo>
#include <string>
using std::string;
#ifndef USUARIO_H
#define USUARIO_H

class Usuario
{
	private:
		string user,pass,name;
		int edad;
		double dinero;
	public:
		Usuario();
		Usuario(string, string, string, int, double);

		string getUser();
		void setUSer(string);

		string getPass();
		void setPass(string);

		string getName();
		void setName(string);

		int getEdad();
		void setEdad(int);

		double getDinero();
		void setDinero(double);

		string toString();

		~Usuario();
	
};

#endif