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
   Nodo<T>* getSiguiente(void);
   void setSiguiente(Nodo<T>* newSiguiente);
   Nodo<T>* getAnterior(void);
   void setAnterior(Nodo<T>* newAnterior);





protected:



};

#endif