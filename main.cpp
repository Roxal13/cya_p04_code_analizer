// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Álvaro Romeo Franco
// Correo: alu0101679716@ull.edu.es
// Fecha: 17/09/2024
// Archivo cya-P02-strings.cc: programa cliente.
// 		Contiene la función main del proyecto que usa las clases X e Y
// 		para ... (indicar brevemente el objetivo)
// Referencias:
// 		Enlaces de interés
//
// Historial de revisiones
// 22/09/2024 - Creación (primera versión) del código, y opciones por defecto
// 23/09/2024 - Lectura de ficheros, y finalización de menú
// 24/09/2024 - Finalización de la práctica y escritura de fichero

#include <fstream>

#include "estructura.cpp"

// Función que asimila el comportamiento de comandos en Unix, para dar más
// información sobre el uso correcto del programa.
void defaultMessage()
{
    cout << "Modo de empleo: ./p04_code_analizer filein.cc fileout.txt\n";
    cout << "Pruebe './p04_code_analizer --help' para mas informacion. \n";
}

// Función para mostrar ayuda al usuario con el formato de los archivos
void mostrarAyuda()
{
    cout << "El fichero de entrada será un fichero de código C++ sintácticamente correcto, y por la salida obtendrá la estructura del fichero de entrada: variables declaradas, bucles utilizados, comentarios inlcuidos así como indicación de la existencia o no de un programa principal.";
}

int main(int argc, char *argv[])
{
    // Si solo se pasa un argumento y es "--help"
    if (argc == 2 && string(argv[1]) == "--help")
    {
        mostrarAyuda(); // Llamar a la función para mostrar la ayuda
        return 0;
    }

    // Si no se proporcionan los parámetros correctos
    if (argc != 3)
    {
        defaultMessage(); // Llamar a la función cuando no hay caracteres
        return 1;
    }

    // Obtener los argumentos de línea de comandos
    string filein = argv[1];  // Primer archivo de entrada
    string fileout = argv[2]; // Segundo archivo de entrada

    // Leemos el fichero de entrada
    ifstream infile; // Archivo de entrada
    infile.open(filein);
    // Si no se puede abrir el fichero de entrada
    if (!infile.is_open())
    {
        cerr << "Error: No se puede abrir el archivo de entrada: " << filein << "\n";
    }
    else
    {
        string linea;
        while (getline(infile, linea))
        {
            // Obtenemos los valores separados por espacios de la línea
            istringstream stream_linea(linea);
            // Creamos los strings cadena y alfabeto
            string string_cad, string_alf;

            // Leemos las dos primeras palabras
            if (stream_linea >> string_cad >> string_alf)
            {
                
            }
            else
            {
                cout << "Linea con formato incorrecto.\n";
            }
        }
    }

    ofstream outfile(fileout); // Archivo de salida
    // Si no se puede abrir el fichero de salida
    if (!outfile.is_open())
    {
        cerr << "Error: No se puede abrir el archivo de salida: " << fileout << "\n";
    }
    else
    {
    }

    outfile.close(); // Cerramos el archivo de salida

    return 0;
}