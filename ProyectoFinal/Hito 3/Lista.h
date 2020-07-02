#pragma once
#include<functional>
using namespace std;

template<typename T, T NADA = 0>
class lista {
	struct Nodo{
		Nodo* Next;
		T elemento;

		Nodo(Nodo *Next, T elemento) {
			this->Next = Next;
			this->elemento = elemento;
		}
	};

	Nodo *Head;
	int tama�o;
public:
	lista(Nodo *Head=nullptr, int tama�o=0) {
		this->Head = Head;
		this->tama�o = tama�o;
	}

	~lista() {
		while (this->Head != nullptr) {
			Nodo *Aux = Head;
			Head = Head->Next;
			delete Aux;
		}
	}

	//-----------------------------Iterador-----------------------------

	class iterador {
		Nodo *aux;
		int pos;
	public:
		iterador(Nodo *aux, int pos) {
			this->aux = aux;
			this->pos = pos;
		}

		bool operator!=(iterador other) {
			return pos != other.pos;
		}

		int operator++() {
			aux = aux->Next;
			++pos;
			return 0;
		}

		T operator*() {
			return aux->elemento;
		}
	};

	iterador begin() {
		return iterador(Head, 0);
	}

	iterador end() {
		return iterador(nullptr, tama�o);
	}

	int Get_tama�o() { return this->tama�o; }
	bool Vacio() { return this->tama�o == 0; }



	//------------------------------A�adir------------------------------

	void Add_first(T elemento) {
		Head = new Nodo(Head, elemento);
		tama�o++;
	}

	void Add_Pos(int pos, T elemento) {
		if (pos<0 || pos>tama�o) {
			return;
		}
		else if (pos == 0) {
			Add_first(elemento);
		}
		else {
			Nodo *Aux = Head;
			for (int i = 1; i < pos; i++){
				Aux = Aux->Next;
			}
			Aux->Next = new Nodo(Aux->Next, elemento);
			tama�o++;
		}
	}

	void Add_last(T elemento) {
		Add_Pos(tama�o, elemento);
	}

	//-----------------------------Eliminar-----------------------------

	void erase_first() {
		if (tama�o>0){
			Nodo *Aux = Head;
			Head = Head->Next;
			delete Aux;
			tama�o--;
		}
	}

	void erase_pos(int pos) {
		if (pos<0 || pos>=tama�o){
			return;
		}
		else if (pos==0) {
			erase_first();
		}
		else {
			Nodo *Aux = Head;
			for (int i = 1; i < tama�o; i++)
			{
				Aux = Aux->Next;
			}
			Nodo *Aux2 = Aux->Next;
			Aux->Next = Aux2->Next;
			delete Aux2;
			tama�o--;
		}
	}

	void erase_last() {
		erase_pos(tama�o - 1);
	}

	//-----------------------------Retornar-----------------------------

	T Get_first() {
		Get_Pos(0);
	}

	T Get_Pos(int pos) {
		if (pos > 0 && pos < tama�o){
			Nodo *Aux = Head;
			for (int i = 0; i < pos; i++){
				Aux = Aux->Next;
			}
			return Aux->elemento;
		}
		return NADA;
	}

	T Get_Final() {
		Get_Pos(tama�o-1);
	}


	template<typename R>
	lista<T>* Find(function<R(T)> lam) {
		lista<T> *L = new lista<T>;
		Nodo* Aux = Head;
		int conta = 0;
		while (Aux != nullptr)
		{
			if (lam(Aux->elemento) == true) {
				L->Add_Pos(conta, Aux->elemento);
				conta++;
			}
			Aux = Aux->Next;
		}
		return L;
	}
};