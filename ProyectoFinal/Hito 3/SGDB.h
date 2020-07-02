#pragma once
//Clase controladora
#include"Columna.h"
#include"Fila.h"
#include"Table_generator.h"
#include<iostream>
#include"Estudiante.h"

using namespace std;
using namespace System;

bool reto() {
	char L;
	do {
		Console::SetCursorPosition(70, 0);
		Console::ForegroundColor = ConsoleColor::White;
		cout << "Retorno (presione s): "; cin >> L;
	} while (toupper(L) != 'S');

	if (toupper(L) == 'S') {
		system("cls");
		return true;
	}
	return false;
}

class Motor {
	Tabla *T;
	Column *C;
	Arrow<Alumno*> *F;
	lista<Alumno*> *Datos;
	int n;
	bool existe;
public:

	Motor() {
		T = new Tabla();
		C = new Column(T);
		F = new Arrow<Alumno*>;
		this->Datos = new lista<Alumno*>;
		n = 4;
		existe = false;
	}
	~Motor() {
		for (auto *A : *Datos) {
			delete A;
		}
		delete Datos, T, C;
	}

	void Menu() {
		int num, num1;
		I:
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "+                           TABLE MAKER                           +" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "+                                                                 +" << endl;
		cout << "+ 1) Ver tabla                                                    +" << endl;
		cout << "+ 2) Añadir Fila                                                  +" << endl;
		cout << "+ 3) Seleccionar datos por columna                                +" << endl;
		cout << "+ 4) Filtrado                                                     +" << endl;
		cout << "+ 5) Salir                                                        +" << endl;
		cout << "+                                                                 +" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "¿Que desea hacer?: "; cin >> num;
		system("cls");

		switch (num)
		{
		  case 1:
			 
			  if (existe == false){
				  do
				  {
					  cout << "Escoja tabla (1: predefinida, 2: nueva tabla): "; cin >> num1;
				  } while (!(num1 >= 1 && num1 <= 2));
				  system("cls");
				  if (num1 == 1) {
					  Generar_Datos();
					  existe = true;
				  }
				  else if (num1 == 2) {
					  cout << "¿Cuantas filas va a añadir?: "; cin >> num1;
					  system("cls");
					  for (int i = 0; i < num1; i++) {
						  Datos->Add_Pos(i, Registrar());
					  }
					  existe = true;
				  }
			  }

			  T->Imprimir_Table(Datos->Get_tamaño());
			  Imprimir_Datos();
			 
			  if (reto()==true) {
				  goto I;
			  }
			break;
		  case 2:
			  
			  F->añadir_Fila(Datos, Registrar());
			  system("cls");
			  goto I;
			  break;
		  case 3:
			  if (existe == true) {
				  C->Tabla_Seleccion(Datos);
			  }
			  else {
				  cout << "NO EXISTE TABLA" << endl;
			  }
			 
			  if (reto() == true) {
				  goto I;
			  }
			  break;
		  case 4:
			  if (existe == true) {
				  C->Tabla_Filtrada(Datos);
			  }
			  else {
				  cout << "NO EXISTE TABLA" << endl;
			  }
			 
			 
			  if (reto() == true) {
				  goto I;
			  }
				 
			  break;
		}
	}

private:

	void Imprimir_Datos() {

		for (auto A : *Datos) {

			A->imprimir(n);
			n = n + 3;
		}
		n = 4;
	}


	void Generar_Datos() { //Datos predefinidos de prueba
		Datos->Add_Pos(0, new Alumno("Diego", "Castro", 19, 201817039, 20));
		Datos->Add_Pos(1, new Alumno("Josue", "Huerta", 19, 201834745, 15.6));
		Datos->Add_Pos(2, new Alumno("Camilo", "Hurtado", 20, 201722069, 12.3));
		Datos->Add_Pos(3, new Alumno("Ricardo", "Mayta", 25, 201522439, 15));
		Datos->Add_Pos(4, new Alumno("Valeri", "Mesa", 16, 201911031, 11.9));
	}

	Alumno* Registrar() {
		string sentencia, Name, apellido;
		bool es_apellido = false;
		int edad, codigo;
		float nota;
		cin.ignore();
		cout << "ingrese nombre: "; getline(cin, sentencia);
		cout << "ingrese codigo (9 numeros): "; cin >> codigo;
		cout << "ingrese edad: "; cin >> edad;
		cout << "ingrese Promedio: "; cin >> nota;
		for (char c : sentencia) {

			if (c != ' ' && es_apellido != true) {
				Name = Name + c;

			}
			else {
				es_apellido = true;
				if (c != ' ') { apellido = apellido + c; }
			}

		}
		system("cls");
		return new Alumno(Name, apellido, edad, codigo, nota);
	}
};
