// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Álvaro Romeo Franco
// Correo: alu0101679716@ull.edu.es
// Fecha: 07/10/2024
// Archivo variable.h: definición de variable.
//
// Referencias:
// 		Enlaces de interés
//    https://www.youtube.com/watch?v=9K4N6MO_R1Y&t=764s
//
// Historial de revisiones
// 07/10/2024 - Creación (primera versión) del código

#include "analizador_codigo.h"

int AnalizadorCodigo::posicionLinea(string contenido, int posicion)
{
  return count(contenido.begin(), contenido.begin() + posicion, '\n') + 1;
}

int AnalizadorCodigo::contarLineas(string texto)
{
  return count(texto.begin(), texto.end(), '\n') + 1;
}

void AnalizadorCodigo::analizar(string contenido)
{
  // Buscamos los comentarios
  regex regexComm(R"((\/\*[\d\D]*\*\/)|(\/\/.*))");
  sregex_iterator currentComm(contenido.begin(), contenido.end(), regexComm);
  sregex_iterator lastComm;

  // Mientras no sea el último valor obtenido
  while (currentComm != lastComm)
  {
    smatch comm = *currentComm;

    string comm_contenido;
    int comm_inicio, comm_fin;

    // Si pertenece al primer grupo, es comentario multi-línea
    if (comm[1].matched)
    {
      // El contenido del comentario
      comm_contenido = comm.str(1);
      // Donde empieza el comentario
      comm_inicio = posicionLinea(contenido, comm.position());
      // Donde acaba el comentario
      comm_fin = contarLineas(comm_contenido);

      Comentario comentario(comm_contenido, comm_inicio, comm_fin);
      comentarios.push_back(comentario);
    }
    // Si pertenece al segundo grupo, es comentario de una línea
    else if (comm[2].matched)
    {
      // El contenido del comentario
      comm_contenido = comm.str(2);
      // Donde empieza el comentario
      comm_inicio = posicionLinea(contenido, comm.position());

      Comentario comentario(comm_contenido, comm_inicio);
      comentarios.push_back(comentario);
    }

    ++currentComm; // Seguimos iterando
  }

  // Buscamos las variables
  regex regexVar(R"([^\( ]\s*\b(int|double)\s+(\w+)(;|\s*=\s*(\d+(\.\d+)?)))");
  sregex_iterator currentVar(contenido.begin(), contenido.end(), regexVar);
  sregex_iterator lastVar;

  // Mientras no sea el último valor obtenido
  while (currentVar != lastVar)
  {
    smatch var = *currentVar;

    // El tipo de variable es el primer grupo capturado
    string var_tipo = var.str(1);
    // El nombre de la variable es el segundo grupo capturado
    string var_nombre = var.str(2);
    // El valor de la variable (si existe) es el cuarto grupo capturado
    string var_valor = var.str(4).empty() ? "N/A" : var.str(4);
    // Obtenemos el número de línea
    int var_linea = posicionLinea(contenido, var.position());
    // Se crea una variable
    Variable variable(var_tipo, var_nombre, var_linea, var_valor);
    variables.push_back(variable);

    ++currentVar; // Seguimos iterando
  }

  // Buscamos los bucles
  regex regexBucle(R"(\b(for|while)\s*\(.*\))");
  sregex_iterator currentBucle(contenido.begin(), contenido.end(), regexBucle);
  sregex_iterator lastBucle;

  // Mientras no sea el último bucle obtenido
  while (currentBucle != lastBucle)
  {
    smatch buc = *currentBucle;

    // El tipo de bucle es el primer grupo capturado
    string bucle_tipo = buc.str(1);
    // Obtenemos el número de línea
    int bucle_linea = posicionLinea(contenido, buc.position());
    // Se crea una variable
    Bucle bucle(bucle_tipo, bucle_linea);
    bucles.push_back(bucle);

    ++currentBucle; // Seguimos iterando
  }

    // Buscamos función principal
    regex regexMain(R"(\w+\s+main\(\)\s*\{[\d\D]*\})");
    sregex_iterator currentMain(contenido.begin(), contenido.end(), regexMain);
    sregex_iterator lastMain;

    // Mientras no sea el último main 
    while (currentMain != lastMain && this->existeMain == false)
    {
      // Si entra en el bucle, será porque hay un main
      this->existeMain = true;
      ++currentMain;
    }
}

// Metodo que imprime el resultado en el fichero como argumento
void AnalizadorCodigo::resultadoAnalisis(ofstream& outfile)
{  
  // Comprobamos que haya comentarios y si hay alguno inicial
  if (!this->comentarios.empty() && this->comentarios[0].getInicio() == 1)
  {
    // Se imprime por pantalla
    cout << comentarios[0].salidaDescripcion() << endl;
    // Se imprime en el archivo de salida
    outfile << comentarios[0].salidaDescripcion() << endl;
  }

  // Imprimimos las variables
  cout << "\nVARIABLES:\n";
  outfile << "\nVARIABLES:\n";
  for (Variable &var : this->variables)
  {
    string salidaVar = var.salidaVariable();
    cout << salidaVar << endl;
    outfile << salidaVar << endl;
  }

  // Imprimimos los bucles
  cout << "\nSTATEMENTS:\n";
  outfile << "\nSTATEMENTS:\n";
  for (Bucle &bucle : this->bucles)
  {
    string salidaBucle = bucle.salidaBucle();
    cout << salidaBucle << endl;
    outfile << salidaBucle << endl;
  }

  // Imprimimos si hay función principal o no
  cout << "\nMAIN:\n" << (this->existeMain == false ? "False" : "True") << endl;
  outfile << "\nMAIN:\n" << (this->existeMain == false ? "False" : "True") << endl;
  
  // Imprimimos los comentarios
  cout << "\nCOMMENTS:\n";
  outfile << "\nCOMMENTS:\n";
  for (Comentario &comentario : this->comentarios)
  {
    string salidaComentario = comentario.salidaComentario();
    cout << salidaComentario << endl;
    outfile << salidaComentario << endl;
  }
}
