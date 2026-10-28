#include <fstream>
#include <cctype>
#include "GestorPersona.h"
 
using namespace std;
 
static const string DOMINIO = "@espe.edu.ec";   // cambia aqui el dominio
 
GestorPersonas::GestorPersonas()
{
}
 
string GestorPersonas::aMinuscula(string texto)
{
    for (size_t i = 0; i < texto.size(); i++)
        texto[i] = tolower((unsigned char)texto[i]);
    return texto;
}
 

string GestorPersonas::generarCorreo(string nombre1, string nombre2, string apellido1)
{
    string base;
    if (nombre2.empty())
        base = string(1, nombre1[0]) + "_" + apellido1;
    else
        base = string(1, nombre1[0]) + string(1, nombre2[0]) + apellido1;
 
    base = aMinuscula(base);
 
    string correo = base + DOMINIO;
    int contador = 0;
    while (correos.buscar(correo) != nullptr)
{
    contador++;
    correo = base + to_string(contador) + DOMINIO;
}
    return correo;
}
 
bool GestorPersonas::agregarPersona(string cedula, string nombre1, string nombre2,
                                    string apellido1, string apellido2, string& correo)
{
    Persona buscada;
    buscada.setCedula(cedula);
    if (lista.buscar(buscada) != nullptr)
        return false;
 
    correo = generarCorreo(nombre1, nombre2, apellido1);
    correos.insertarAlFinal(correo);         
    lista.insertarAlFinal(Persona(nombre1, nombre2, apellido1, apellido2, cedula, correo));
    return true;
}
 
void GestorPersonas::mostrar()
{
    lista.imprimir();
}
 

bool GestorPersonas::exportarTxt(string nombreArchivo)
{
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open())
        return false;
 
    Nodo<Persona>* cabeza = lista.getCabeza();
    if (cabeza != nullptr)
    {
        Nodo<Persona>* actual = cabeza;
        do
        {
            Persona p = actual->getDato();
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