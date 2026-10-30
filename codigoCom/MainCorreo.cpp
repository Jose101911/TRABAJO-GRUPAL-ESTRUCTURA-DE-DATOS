#include <iostream>
#include"Persona.h"
#include"ListaDobleCircular.h"

using namespace std;

int main()
{
    
   ListaDobleCircular<Persona> lista;
    cout << "=== SISTEMA DE GESTION DE PERSONAS ===" << endl << endl;

    
    cout << "--- Registrando Personas ---" << endl;
    
     Persona p1("Juan",  "Carlos", "Perez",  "Gomez",   "1712345678", ""); 
     Persona p2("Juan",  "",       "Perez",  "Lopez",   "1787654321", ""); 
     Persona p3("Maria", "Elena",  "Torres", "Velasco", "1755555555", ""); 
     Persona p4("Pedro", "",       "Perez",  "Rios",    "1712345678", ""); 

lista.insertarAlFinal(p1);
lista.insertarAlFinal(p2);
lista.insertarAlFinal(p3);
lista.insertarAlFinal(p4); 
    

    cout << "\n--- Lista de Personas ---" << endl;
    lista.imprimir();

    
       
    cout << "--- Exportando Datos ---" << endl;
    string nombreArchivo = "personas.txt";
    if (lista.exportarTxt(nombreArchivo)) {
        cout << "[OK] Datos exportados correctamente a '" << nombreArchivo << "'." << endl;
    } else {
        cout << "[ERROR] No se pudo crear/escribir en el archivo." << endl;
    }

    return 0;
}