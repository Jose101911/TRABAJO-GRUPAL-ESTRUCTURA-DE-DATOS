#include <string>
#include "ListaDobleCircular.h"
#include "Persona.h"
 
class GestorPersonas
{
public:
    GestorPersonas();
 
    
    bool agregarPersona(std::string cedula, std::string nombre1, std::string nombre2,
                        std::string apellido1, std::string apellido2, std::string& correo);
    void mostrar();
    bool exportarTxt(std::string nombreArchivo);
 
private:
    ListaDobleCircular<Persona> lista;          
    ListaDobleCircular<std::string> correos;    
 
    std::string aMinuscula(std::string texto);
    std::string generarCorreo(std::string nombre1, std::string nombre2, std::string apellido1);
};
 
