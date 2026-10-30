/***********************************************************************
 * Module:  Nodo.h
 * Author:  Lenovo
 * Modified: martes, 27 de octubre de 2026 18:36:35
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__ListasDoblesEliminar_Nodo_h)
#define __ListasDoblesEliminar_Nodo_h
template <typename T>
class Nodo
{

private:
   T dato;
   Nodo<T>* siguiente;
   Nodo<T>* anterior;



public:
   Nodo(T dato){
       this->dato = dato;
    siguiente = nullptr;
    anterior = nullptr;
   }
   T getDato(void){
      return dato;
   }

   void setDato(T newDato){
      this->dato = dato;
   }
   Nodo<T>* getSiguiente(){return siguiente;}
   void setSiguiente(Nodo<T>* newSiguiente){

      this->siguiente = newSiguiente;
   }
   Nodo<T>* getAnterior(){


      return anterior;
   }
   void setAnterior(Nodo<T>* newAnterior){
      this->anterior = newAnterior;
   }





protected:



};

#endif