#pragma once

#include<iostream>
#include<string>
using namespace std;
using namespace System;



class Alumno {

	string nombre, Apellido;
	int codigo, Edad;
	float Promedio;
	
public:
	Alumno(string nombre, string Apellido, int Edad, int codigo, float promedio) {
		this->nombre = nombre;
		this->Apellido = Apellido;
		this->Edad = Edad;
		this->codigo = codigo;
		this->Promedio = promedio;
	}

	string Get_Nombre() { return this->nombre; }
	string Get_Apellido() { return this->Apellido; }
	int Get_Codigo() { return this->codigo; }
	float Get_Promedio() { return this->Promedio; }
	int Get_Edad() { return this->Edad; }



	void imprimir(int n) {
		posicion(3, n);
		cout << nombre;
		posicion(13, n);
		cout << Apellido;
		posicion(26, n);
		cout << Edad;
		posicion(34, n);
		cout << codigo;
		posicion(49, n);
		cout << Promedio;
	}

private:

	void posicion(int x, int y) {
		Console::SetCursorPosition(x, y);
	}

};
