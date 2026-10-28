/***********************************************************************
 * Module:  ListaDobleCircular.h
 * Author:  Lenovo
 * Modified: domingo, 25 de octubre de 2026 21:31:26
 * Purpose: Declaration of the class ListaDobleCircular
 ***********************************************************************/

#if !defined(__ListasDoblesEliminar_ListaDobleCircular_h)
#define __ListasDoblesEliminar_ListaDobleCircular_h


#include "Nodo.h"
#include<iostream>
using namespace std;

template<typename T>
class ListaDobleCircular
{

   private:
   Nodo<T>* cabeza;
   int tamanio;

public:

ListaDobleCircular()
{
    cabeza = nullptr;
    tamanio = 0;
}
 

~ListaDobleCircular()
{
    while (!estaVacia())
    {
        eliminar(cabeza->getDato());
    }
}
 
bool estaVacia()
{
    return cabeza == nullptr;
}
 
int getTamanio()
{
    return tamanio;
}
 
Nodo <T>* getCabeza()
{
    return cabeza;
}
 
void insertarAlFinal(T valor)
{
    Nodo<T>* nuevo = new Nodo<T>(valor);
 
    if (estaVacia())
    {
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
        cabeza = nuevo;
    }
    else
    {
        Nodo<T>* ultimo = cabeza->getAnterior();
 
        nuevo->setSiguiente(cabeza);
        nuevo->setAnterior(ultimo);
        ultimo->setSiguiente(nuevo);
        cabeza->setAnterior(nuevo);
    }
    tamanio++;
}
 
void insertarAlInicio(T valor)
{
    Nodo<T>* nuevo = new Nodo<T>(valor);
 
    if (estaVacia())
    {
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
    }
    else
    {
        Nodo<T>* ultimo = cabeza->getAnterior();
 
        nuevo->setSiguiente(cabeza);
        nuevo->setAnterior(ultimo);
        ultimo->setSiguiente(nuevo);
        cabeza->setAnterior(nuevo);
    }
    cabeza = nuevo;   // el nuevo nodo pasa a ser la cabeza
    tamanio++;
}
 

Nodo<T>*buscar(T dato)
{
    if (estaVacia())
    {
        return nullptr;
    }
 
    Nodo<T>* actual = cabeza;
 
    do
    {
        if (actual->getDato() == dato)
        {
            return actual;
        }
        actual = actual->getSiguiente();
    } while (actual != cabeza);
 
    return nullptr;
}
 
void eliminar(T dato)
{
    if (estaVacia())
    {
        cout << "La lista esta vacia" << endl;
        return;
    }
 
    Nodo<T>* actual = cabeza;
 
    do
    {
        if (actual->getDato() == dato)
        {
            // Caso 1: solo existe un nodo
            if (actual->getSiguiente() == actual)
            {
                cabeza = nullptr;
            }
            else
            {
                // Enlazar el anterior con el siguiente
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
                actual->getSiguiente()->setAnterior(actual->getAnterior());
 
                // Si se elimina la cabeza
                if (actual == cabeza)
                {
                    cabeza = actual->getSiguiente();
                }
            }
 
            delete actual;
            tamanio--;
            cout << "Elemento eliminado" << endl;
            return;
        }
 
        actual = actual->getSiguiente();
 
    } while (actual != cabeza);
 
    cout << "Elemento no encontrado" << endl;
}
 
void imprimir()
{
    if (estaVacia())
    {
        cout << "Lista vacia" << endl;
        return;
    }
 
    Nodo<T>* actual = cabeza;
 
    do
    {
        cout << actual->getDato() << " ";
        actual = actual->getSiguiente();
    } while (actual != cabeza);
 
    cout << endl;
}





};

#endif