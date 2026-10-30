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
#include <fstream>
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

   bool prepararPersona(T& persona);

   bool exportarTxt(string nombreArchivo);
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

if (!prepararPersona(valor))
    {
        cout << "[ERROR] La cedula " << valor.getCedula() << " ya esta registrada." << endl;
        return;
    }

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
     cout << "[OK] Persona agregada. Correo generado: " << valor.getCorreo() << endl;
}
 
template <typename T>
void ListaDobleCircular<T>::insertarAlInicio(T valor)
{
if (!prepararPersona(valor))
    {
        cout << "[ERROR] La cedula " << valor.getCedula() << " ya esta registrada." << endl;
        return;
    }

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
     cout << "[OK] Persona agregada. Correo generado: " << valor.getCorreo() << endl;
    
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
            
            if (actual->getSiguiente() == actual)
            {
                cabeza = nullptr;
            }
            else
            {
                
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
                actual->getSiguiente()->setAnterior(actual->getAnterior());
 
               
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

template <typename T>
bool ListaDobleCircular<T>::prepararPersona(T& persona)
{
    
    if (buscar(persona) != nullptr)
    {
        return false;
    }

    
    string nombre1   = persona.getNombre1();
    string nombre2   = persona.getNombre2();
    string apellido1 = persona.getApellido1();

    string base = "";
    base += nombre1[0];
    if (nombre2 == "")
        base += '_';
    else
        base += nombre2[0];
    base += apellido1;

    for (int i = 0; i < base.size(); i++)
    {
        if (base[i] >= 'A' && base[i] <= 'Z')
        {
            base[i] = base[i] + 32;
        }
    }

    
    string correo = base + "@espe.edu.ec";
    int contador = 0;
    bool repetido = true;

    while (repetido)
    {
        repetido = false;
        Nodo<T>* actual = cabeza;

        if (actual != nullptr)
        {
            do
            {
                if (actual->getDato().getCorreo() == correo)
                {
                    repetido = true;
                }
                actual = actual->getSiguiente();
            } while (actual != cabeza);
        }

        if (repetido)
        {
            contador++;
            string numero = "";
            int n = contador;
            while (n > 0)
            {
                char digito = '0' + (n % 10);
                numero = digito + numero;
                n = n / 10;
            }
            correo = base + numero + "@espe.edu.ec";
        }
    }

    persona.setCorreo(correo);
    return true;
}

template <typename T>
bool ListaDobleCircular<T>::exportarTxt(string nombreArchivo)
{
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open())
    {
        return false;
    }

    if (!estaVacia())
    {
        Nodo<T>* actual = cabeza;
        do
        {
            T p = actual->getDato();
            archivo << p.getCedula() << ";"
                    << p.getNombre1() << ";"
                    << p.getNombre2() << ";"
                    << p.getApellido1() << ";"
                    << p.getApellido2() << ";"
                    << p.getCorreo() << "\n";
            actual = actual->getSiguiente();
        } while (actual != cabeza);
    }

    archivo.close();
    return true;
}





#endif