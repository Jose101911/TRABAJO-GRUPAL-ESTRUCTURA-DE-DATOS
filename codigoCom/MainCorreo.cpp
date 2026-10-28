#include <iostream>
#include "GestorPersona.h"

using namespace std;

int main()
{
    GestorPersonas gestor;
    string correoGenerado;

    cout << "=== SISTEMA DE GESTION DE PERSONAS ===" << endl << endl;

    
    cout << "--- Registrando Personas ---" << endl;
    
    
    if (gestor.agregarPersona("1712345678", "Juan", "Carlos", "Perez", "Gomez", correoGenerado)) {
        cout << "[OK] Persona agregada. Correo generado: " << correoGenerado << endl;
    } else {
        cout << "[ERROR] La cedula ya existe." << endl;
    }

    
    if (gestor.agregarPersona("1787654321", "Juan", "", "Perez", "Lopez", correoGenerado)) {
        cout << "[OK] Persona agregada. Correo generado: " << correoGenerado << endl;
    } else {
        cout << "[ERROR] La cedula ya existe." << endl;
    }

   
    if (gestor.agregarPersona("1755555555", "Maria", "Elena", "Torres", "Velasco", correoGenerado)) {
        cout << "[OK] Persona agregada. Correo generado: " << correoGenerado << endl;
    } else {
        cout << "[ERROR] La cedula ya existe." << endl;
    }

    
    if (gestor.agregarPersona("1712345678", "Pedro", "", "Perez", "Rios", correoGenerado)) {
        cout << "[OK] Persona agregada. Correo generado: " << correoGenerado << endl;
    } else {
        cout << "[ERROR] La cedula 1712345678 ya esta registrada." << endl;
    }

    cout << endl;

    
    cout << "--- Lista de Personas Registradas ---" << endl;
    gestor.mostrar();
    cout << endl;

   
    cout << "--- Exportando Datos ---" << endl;
    string nombreArchivo = "personas.txt";
    if (gestor.exportarTxt(nombreArchivo)) {
        cout << "[OK] Datos exportados correctamente a '" << nombreArchivo << "'." << endl;
    } else {
        cout << "[ERROR] No se pudo crear/escribir en el archivo." << endl;
    }

    return 0;
}