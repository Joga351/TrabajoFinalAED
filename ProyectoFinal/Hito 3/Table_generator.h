#pragma once

#include<iostream>
#include"Lista.h"
#include"Estudiante.h"
#include<functional>
#include<string>

using namespace System;
using namespace std;
 
class Tabla {
public:
	Tabla() {
	}

	
	void Imprimir_Table(int tamaño){
		generar_Celda(tamaño);
		Imprimir_cabecera();
	}
	
	void posicion(int x, int y) {
		Console::SetCursorPosition(x, y);
	}

	void generar_Celda(int n) {

	for (int k = 0; k < n + 1; k++) { //forman un conjunto de celdas, osea la tabla
		for (int c = 0; c < 5; c++) {

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 11; j++) {  //forman una celda
					if (i == 0 || i == 2) {
						posicion((11 * c) + j, (3 * k) + i);
						if (k == 0) {
							Console::ForegroundColor = ConsoleColor::Yellow; 
						}
						else {
							Console::ForegroundColor = ConsoleColor::White;
						}
						cout << "-";
					}
					else if (j == 0 || j == 10) {
						posicion((11 * c) + j, (3 * k) + i);
						if (k == 0) {
							Console::ForegroundColor = ConsoleColor::Yellow;
						}
						else {
							Console::ForegroundColor = ConsoleColor::White;
						}
						cout << "|";
					}
					else {
						posicion((11 * c) + j, (3 * k) + i);
						cout << " ";
					}

				}
				cout << endl;
			}

		}
	}
}

	void Imprimir_cabecera() {
		Console::ForegroundColor = ConsoleColor::Yellow;
		for (int i = 0; i < 5; i++)
		{
			posicion((i * 11) + 2, 1);
			switch (i)
			{
			case 0:
				cout << "NOMBRE";
				break;
			case 1:
				cout << "APELLIDO";
				break;
			case 2:
				cout << "EDAD";
				break;
			case 3:
				cout << "CODIGO";
				break;
			case 4:
				cout << "PROMEDIO";
				break;
			}
		}
	}

};
