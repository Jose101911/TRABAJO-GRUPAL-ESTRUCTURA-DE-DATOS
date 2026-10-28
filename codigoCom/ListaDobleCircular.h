/***********************************************************************
 * Module:  ListaDobleCircular.h
 * Author:  Lenovo
 * Modified: domingo, 25 de octubre de 2026 21:31:26
 * Purpose: Declaration of the class ListaDobleCircular
 ***********************************************************************/

#if !defined(__ListasDoblesEliminar_ListaDobleCircular_h)
#define __ListasDoblesEliminar_ListaDobleCircular_h


#include <Nodo.h>
#include<iostream>
using namespace std;

template<typename T>
class ListaDobleCircular
{

   private:
   Nodo<T>* cabeza;
   int tamanio;

public:
ListaDobleCircular();
   ~ListaDobleCircular();
   bool estaVacia();
   int getTamanio();
   Nodo<T>* getCabeza();
   void insertarAlFinal(T valor);
   void insertarAlInicio(T valor);
   Nodo<T>* buscar(T dato);
   void eliminar(T dato);
   void imprimir();
};

   template <typename T>
ListaDobleCircular<T>::ListaDobleCircular()
{
    cabeza = nullptr;
    tamanio = 0;
}
 
template <typename T>
ListaDobleCircular<T>::~ListaDobleCircular()
{
    while (!estaVacia())
    {
        eliminar(cabeza->getDato());
    }
}
 
template <typename T>
bool ListaDobleCircular<T>::estaVacia()
{
    return cabeza == nullptr;
}
 
template <typename T>
int ListaDobleCircular<T>::getTamanio()
{
    return tamanio;
}
 
template <typename T>
Nodo<T>* ListaDobleCircular<T>::getCabeza()
{
    return cabeza;
}
 
template <typename T>
void ListaDobleCircular<T>::insertarAlFinal(T valor)
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
 
template <typename T>
void ListaDobleCircular<T>::insertarAlInicio(T valor)
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
 
template <typename T>
Nodo<T>* ListaDobleCircular<T>::buscar(T dato)
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
 
template <typename T>
void ListaDobleCircular<T>::eliminar(T dato)
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
 
template <typename T>
void ListaDobleCircular<T>::imprimir()
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




#endif