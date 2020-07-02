
#pragma once
#include<iostream>
#include"Lista.h"
#include<functional>
#include"Estudiante.h"
#include"Table_generator.h"
#include<string>
#include<vector>

using namespace System;
using namespace std;




class Column {

	vector<lista<Alumno*>*>col;
	Tabla *table;
	int n;
	bool existe_auxiliar;
public:
	Column(Tabla *table) {
		this->table = table;
		n = 4;
		existe_auxiliar = false;
	}

	void Tabla_Filtrada(lista<Alumno*> *Datos) { //Filtrar segundo estas 5 columnas
		I:
		int num,num2;
		char pri, ulti;
		int ini,fini,codi, eda, not;
		string nomb,number, aux;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "+                           COLUMNA                               +" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "+                                                                 +" << endl;
		cout << "+ 1) Nombre                                                       +" << endl;
		cout << "+ 2) Apellido                                                     +" << endl;
		cout << "+ 3) Codigo                                                       +" << endl;
		cout << "+ 4) Edad                                                         +" << endl;
		cout << "+ 5) Promedio                                                     +" << endl;
		cout << "+                                                                 +" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

		do
		{
			cout << "¿Que desea hacer?: "; cin >> num;
		} while (!(num>0 && num<6));
		system("cls");
		
		switch (num) //La funcion se llama aqui en este switch, falta completar
		{
		case 1:
			Filtrar();
			do
			{
				cout << "¿Que desea hacer?: "; cin >> num2;
			} while (!(num2>0 && num2<8));
			system("cls");
			
			if (num2 == 3)
			{
				cin.ignore();
				cout << "ingrese nombre: "; getline(cin, nomb);
				auto b = [&](Alumno *A) {return A->Get_Nombre() == nomb; };
				Imprimir_Datos(Datos, b);
				
			}
			else if (num2 == 4)
			{
				cout << "ingrese inicial: "; cin >> pri;
				auto b = [&](Alumno *A) {
					for (char letra : A->Get_Nombre()) {
					if (letra == toupper(pri))
					{
						return true;
					}
				}
				return false;
				};
				Imprimir_Datos(Datos, b);
				
			}
			else if (num2 == 5)
			{
				cout << "ingrese letra final: "; cin >> pri;
				auto b = [&](Alumno *A) {
					if (A->Get_Nombre()[A->Get_Nombre().size() - 1] == pri) { return true; }
					return false;
				};
				Imprimir_Datos(Datos, b);
				
			}
			else if (num2 == 6)
			{
				cin.ignore();
				cout << "ingrese nombre: "; getline(cin, nomb);
				auto b = [&](Alumno *A) {return A->Get_Nombre() == nomb; };
				Imprimir_Datos(Datos, b);
			}
			else if (num2 == 7)
			{
				cin.ignore();
				cout << "ingrese nombre: "; getline(cin, nomb);
				auto b = [&](Alumno *A) {return A->Get_Nombre() != nomb; };
				Imprimir_Datos(Datos, b);
			}
			table->Imprimir_cabecera();
			break;
	
		case 2:
			Filtrar();
			do
			{
				cout << "¿Que desea hacer?: "; cin >> num2;
			} while (!(num2>0 && num2<8));
			system("cls");

	        if (num2 == 3)
			{
				cin.ignore();
				cout << "ingrese nombre: "; getline(cin, nomb);
				auto b = [&](Alumno *A) {return A->Get_Nombre() == nomb; };
				Imprimir_Datos(Datos, b);
				
			}
			else if (num2 == 4)
			{
				cout << "ingrese incial: "; cin >> pri;
				auto b = [&](Alumno *A) {
					for (char letra : A->Get_Apellido()) {
						if (letra == toupper(pri))
						{
							return true;
						}
					}
					return false;
				};
				Imprimir_Datos(Datos, b);
				
			}
			else if (num2 == 5)
			{
				cout << "ingrese letra final: "; cin >> pri;
				auto b = [&](Alumno *A) {
					if (A->Get_Apellido()[A->Get_Apellido().size() - 1] == pri) { return true; }
					return false;
				};
				Imprimir_Datos(Datos, b);
				
			}
			else if (num2 == 6)
			{
				cin.ignore();
				cout << "ingrese Apellido: "; getline(cin, nomb);
				auto c = [&](Alumno *A) {return A->Get_Apellido() == nomb; };
				Imprimir_Datos(Datos, c);
			}
			else if (num2 == 7)
			{
				cin.ignore();
				cout << "ingrese Apellido: "; getline(cin, nomb);
				auto c = [&](Alumno *A) {return A->Get_Apellido() != nomb; };
				Imprimir_Datos(Datos, c);
			}
			table->Imprimir_cabecera();
			break;
		
		case 3:
			Filtrar();
			do
			{
				cout << "¿Que desea hacer?: "; cin >> num2;
			} while (!(num2>0 && num2<8));
			system("cls");

			if (num2 == 3)
			{
				cin.ignore();
				cout << "Ingrese codigo: "; getline(cin, number);

				auto d = [&](Alumno *A) {
					if (to_string(A->Get_Codigo()) == number) {
						return true;
					}
					return false;
				};
				Imprimir_Datos(Datos, d);
				
			}
			else if (num2 == 4)
			{
				cin.ignore();
				cout << "Ingrese numero: "; getline(cin, number);
				auto d = [&](Alumno *A) {
					if (to_string(A->Get_Codigo())[0] == number[0]) {
						return true;
					}
					return false;
				};
				Imprimir_Datos(Datos, d);
				
			}
			else if (num2 == 5)
			{
				cin.ignore();
				cout << "ingrese numero: "; getline(cin, number);
				auto b = [&](Alumno *A) {
					if (to_string(A->Get_Codigo())[to_string(A->Get_Codigo()).size() - 1] == number[0]) {
						return true;
					}
					return false;

				};
				Imprimir_Datos(Datos, b);
				
			}
			else if (num2 == 6)
			{
				cout << "Ingrese codigo: "; cin >> codi;
				auto g = [&](Alumno *A) {return  A->Get_Codigo() == codi; };
				Imprimir_Datos(Datos, g);
			}
			else if (num2 == 7)
			{
				cout << "Ingrese numero: "; cin >> codi;
				auto g = [&](Alumno *A) {return  A->Get_Codigo() != codi; };
				Imprimir_Datos(Datos, g);
			}
			
			table->Imprimir_cabecera();
			break;
		case 4:
			Filtrar();
			do
			{
				cout << "¿Que desea hacer?*: "; cin >> num2;
			} while (!(num2>0 && num2<8));
			system("cls");

			if (num2 == 3)
			{
				cin.ignore();
				cout << "Ingrese edad: "; getline(cin, number);
				
				auto d = [&](Alumno *A) {
					if (to_string(A->Get_Edad()) == number) {
						return true;
					}
					return false;
				};
				Imprimir_Datos(Datos, d);
				
			}
			else if (num2 == 4)
			{
				cin.ignore();
				cout << "Ingrese numero: "; getline(cin, number);
				auto d = [&](Alumno *A) {
					if (to_string(A->Get_Edad())[0] == number[0]) {
						return true;
					}
					return false;
				};
				Imprimir_Datos(Datos, d);
				
			}
			else if (num2 == 5)
			{
				cin.ignore();
				cout << "ingrese numero: "; getline(cin, number);
				auto b = [&](Alumno *A) {
					if (to_string(A->Get_Edad())[to_string(A->Get_Edad()).size()-1] == number[0]) {
						return true;
					}
					return false;
					
				};
				Imprimir_Datos(Datos, b);
				
			}
			else if (num2 == 6)
			{
				cout << "Ingrese edad: "; cin >> eda;
				auto d = [&](Alumno *A) {return  A->Get_Edad() == eda; };
				Imprimir_Datos(Datos, d);
			}
			else if (num2 == 7)
			{
				cout << "Ingrese edad: "; cin >> eda;
				auto d = [&](Alumno *A) {return  A->Get_Edad() != eda; };
				Imprimir_Datos(Datos, d);
			}
			
			table->Imprimir_cabecera();
			break;
		case 5:
			Filtrar();
			do
			{
				cout << "¿Que desea hacer?: "; cin >> num2;
			} while (!(num2>0 && num2<8));
			if (num2 == 3)
			{
				cout << "Ingrese nota: "; cin >> not;
				auto h = [&](Alumno *A) {return  A->Get_Promedio() == not; };
				Imprimir_Datos(Datos, h);
			}
			else if (num2 == 4)
			{
				cout << "ingrese inicial: "; cin >> ini;
				auto b = [&](Alumno *A) {

					{
						if (A->Get_Codigo() / 10 == ini)
						{
							return true;
						}
					}
					return false;
				};
				Imprimir_Datos(Datos, b);
			}
			else if (num2 == 5)
			{
				cout << "ingrese ultimo digito: "; cin >> fini;
				auto b = [&](Alumno *A) {

					{
						if (A->Get_Codigo() % 10 == fini)
						{
							return true;
						}
					}
					return false;
				};
				Imprimir_Datos(Datos, b);
			}
			else if (num2 == 6)
			{
				cout << "Ingrese nota: "; cin >> not;
				auto h = [&](Alumno *A) {return  A->Get_Promedio() == not; };
				Imprimir_Datos(Datos, h);
			}
			else if (num2 == 7)
			{
				cout << "Ingrese nota: "; cin >> not;
				auto h = [&](Alumno *A) {return  A->Get_Promedio() != not; };
				Imprimir_Datos(Datos, h);
			}
			
			table->Imprimir_cabecera();
			break;
		}
		
	}

	void Filtrar() { //Tabla_Filtrada llama a Filtrar dependiendo de cual columna eligio y muestra las siguientes opciones
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "+                           FILTROS                               +" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "+                                                                 +" << endl;
		cout << "+ 1) Mayor                                                        +" << endl;
		cout << "+ 2) Menor                                                        +" << endl;
		cout << "+ 3) Igual a                                                      +" << endl;
		cout << "+ 4) Inicia con                                                   +" << endl;
		cout << "+ 5) Finaliza con                                                 +" << endl;
		cout << "+ 6) Esta contenido en                                            +" << endl;
		cout << "+ 7) No esta contenido en                                         +" << endl;
		cout << "+                                                                 +" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		
	}

	void Tabla_Seleccion(lista<Alumno*> *Datos) { //Esta selecciona una comlumna en especifica y la filtra segun estos campos
	I:
		int num;
		vector<string> nom, ape;
		string sentencia, Name, apellido;
		bool es_apellido = false;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "+                           SELECCION                             +" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		
		if (existe_auxiliar != true) {
			do
			{
				cin.ignore();
				cout << "ingrese nombre de los alumnos que va a seleccionar: "; getline(cin, sentencia);
				if (sentencia != "x") {
					for (char c : sentencia) {

						if (c != ' ' && es_apellido != true) {
							Name = Name + c;

						}
						else {
							if (es_apellido != true) {
								nom.push_back(Name);
								Name.clear();
							}
							es_apellido = true;
							if (c != ' ') { apellido = apellido + c; }
						}

					}
					ape.push_back(apellido);
					apellido.clear();
					es_apellido = false;
				}
			} while (sentencia != "x");
			system("cls");
			auto f = [&](Alumno *A) {
				for (int i = 0; i < nom.size(); i++) {
					if (A->Get_Nombre() == nom.at(i)) {
						if (A->Get_Apellido() == ape.at(i)) {
							return true;
						}
					}
				}
				return false;
			};
			Tabla_auxiliar(Datos, f);
			existe_auxiliar = true;
		}
		
		cout << "¿Desea ver las tablas disponibles? (0: si, 1: no, 2: crear otra): "; cin >> num;
		system("cls");
		if (num == 0) {
			cout << "-----Hay " << col.size() << " disponibles-----" << endl;
			cout << endl;
			do
			{
				cout << "¿cual tabla desea mostrar?: "; cin >> num;
			} while (!(num>0));
			Impri(num);
		}
		else if (num == 2) {
			existe_auxiliar = false;
			goto I;
		}
	}

	private:

		void Tabla_auxiliar(lista<Alumno*> *Datos, function<bool(Alumno*)>key) {
			lista<Alumno*> *Aux = Datos->Find(key);
			col.push_back(Aux);
		}

		void Impri(int num) {
			lista<Alumno*> *Aux = col.at(num - 1);
			table->generar_Celda(Aux->Get_tamaño());
			if (Aux != nullptr) {
				for (auto A : *Aux) {
					A->imprimir(n);
					n = n + 3;
				}
			}
			else {
				cout << "NO SE ENCONTRARON RESULATOS" << endl;
			}
			n = 4;
			table->Imprimir_cabecera();
		}

		void Imprimir_Datos(lista<Alumno*> *Datos, function<bool(Alumno*)>key) { //Seleccion llama a este imprimir datos que imprime una lista auxiliar
			lista<Alumno*> *Aux = Datos->Find(key);
			table->generar_Celda(Aux->Get_tamaño());
			if (Aux != nullptr) {
				for (auto A : *Aux) {
					A->imprimir(n);
					n = n + 3;
				}
			}
			else {
				cout << "NO SE ENCONTRARON RESULATOS" << endl;
			}
			table->Imprimir_cabecera();
			n = 4;
		}

};


