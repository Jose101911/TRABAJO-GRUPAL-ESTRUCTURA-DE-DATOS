/***********************************************************************
 * Module:  Persona.cpp
 * Author:  Lenovo
 * Modified: mi�rcoles, 28 de octubre de 2026 9:45:48
 * Purpose: Implementation of the class Persona
 ***********************************************************************/

#include "Persona.h"

std::string Persona::getNombre1(void) const
{
   return nombre1;
}
 
void Persona::setNombre1(std::string newNombre1)
{
   this->nombre1 = newNombre1;
}
 
std::string Persona::getNombre2(void) const
{
   return nombre2;
}
 
void Persona::setNombre2(std::string newNombre2)
{
   this->nombre2 = newNombre2;
}
 
std::string Persona::getApellido1(void) const
{
   return apellido1;
}
 
void Persona::setApellido1(std::string newApellido1)
{
   this->apellido1 = newApellido1;
}
 
std::string Persona::getApellido2(void) const
{
   return apellido2;
}
 
void Persona::setApellido2(std::string newApellido2)
{
   this->apellido2 = newApellido2;
}
 
std::string Persona::getCedula(void) const
{
   return cedula;
}
 
void Persona::setCedula(std::string newCedula)
{
   this->cedula = newCedula;
}
 
std::string Persona::getCorreo(void) const
{
   return correo;
}
 
void Persona::setCorreo(std::string newCorreo)
{
   this->correo = newCorreo;
}
 
Persona::Persona(std::string nombre1, std::string nombre2, std::string apellido1,
                 std::string apellido2, std::string cedula, std::string correo)
{
   this->nombre1 = nombre1;
   this->nombre2 = nombre2;
   this->apellido1 = apellido1;
   this->apellido2 = apellido2;
   this->cedula = cedula;
   this->correo = correo;
}
 
Persona::Persona()
{
}
 
bool Persona::operator==(const Persona& otra) const
{
   return cedula == otra.cedula;
}
 
std::ostream& operator<<(std::ostream& salida, const Persona& p)
{
   salida << p.getCedula() << " | " << p.getNombre1() << " ";
   if (!p.getNombre2().empty())
      salida << p.getNombre2() << " ";
   salida << p.getApellido1() << " " << p.getApellido2()
          << " | " << p.getCorreo() << "\n";
   return salida;
}