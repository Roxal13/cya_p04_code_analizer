// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Álvaro Romeo Franco
// Correo: alu0101679716@ull.edu.es
// Fecha: 17/09/2024
// Archivo main.cpp: programa main.
//		Crear ejecutable: g++ -o p04_analizer .\main.cpp  
// 		Contiene la función main del proyecto que analiza un código de entrada
//		y devuelve sus variables, bucles, comentarios, y su función main.
// Referencias:
// 		Enlaces de interés
//		https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
//
// Historial de revisiones
// 07/10/2024 - Creación (primera versión) del código, y opciones por defecto

#include "analizador_codigo.cc"

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

	// Leemos el fichero de entrada, y lo guardamos como string en contenido
	ifstream infile(filein);

	// Si no se puede abrir el fichero de entrada
	if (!infile.is_open())
	{
		cerr << "Error: No se puede abrir el archivo de entrada: " << filein << "\n";
		return 1;
	}
	// Leemos el fichero de salida
	ofstream outfile(fileout); // Archivo de salida

	// Si no se puede abrir el fichero de salida
	if (!outfile.is_open())
	{
		cerr << "Error: No se puede abrir el archivo de salida: " << fileout << "\n";
		return 1;
	}

	string contenido;

	// Se crea un iterador para recorrer el archivo de entrada
	infile.seekg(0, ios::end);
	contenido.reserve(infile.tellg());
	infile.seekg(0, ios::beg);

	// Asignamos el contenido del archivo en contenido
	contenido.assign((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());

	// Creamos el analizador
	AnalizadorCodigo analizador;
	
	// Analizamos el contenido pasado por entrada
	analizador.analizar(contenido);

	// Imprimimos los resultados obtenidos del fichero de entrada
	cout << "PROGRAM: " << fileout << endl;
	outfile << "PROGRAM: " << fileout << endl;
	// Ejecutamos la función que devuelve los resultados
	analizador.resultadoAnalisis(outfile);

	outfile.close(); // Cerramos el archivo de salida

	return 0;
}