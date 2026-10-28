/***********************************************************************
 * Module:  Persona.h
 * Author:  Lenovo
 * Modified: mi�rcoles, 28 de octubre de 2026 9:45:48
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__ListasDoblesEliminar_Persona_h)
#define __ListasDoblesEliminar_Persona_h

#include <string>
#include <iostream>

class Persona
{
public:
   std::string getNombre1(void) const;
   void setNombre1(std::string newNombre1);
   std::string getNombre2(void) const;
   void setNombre2(std::string newNombre2);
   std::string getApellido1(void) const;
   void setApellido1(std::string newApellido1);
   std::string getApellido2(void) const;
   void setApellido2(std::string newApellido2);
   std::string getCedula(void) const;
   void setCedula(std::string newCedula);
   std::string getCorreo(void) const;
   void setCorreo(std::string newCorreo);

   Persona(std::string nombre1, std::string nombre2, std::string apellido1,
           std::string apellido2, std::string cedula, std::string correo);
   Persona();

   
   bool operator==(const Persona& otra) const;

protected:
private:
   std::string nombre1;
   std::string nombre2;     
   std::string apellido1;
   std::string apellido2;
   std::string cedula;
   std::string correo;
};


std::ostream& operator<<(std::ostream& salida, const Persona& p);

#endif