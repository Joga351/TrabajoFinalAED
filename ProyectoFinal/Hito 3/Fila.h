#pragma once

#include<iostream>
#include<vector>
#include"Lista.h"

using namespace System;
using namespace std;

template<typename T>
class Arrow {

public:
	Arrow() {}
	void a�adir_Fila(lista<T> *lista, T elemento) { //a�ade una nueva fila
		lista->Add_last(elemento);
	}
};