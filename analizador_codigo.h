// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Álvaro Romeo Franco
// Correo: alu0101679716@ull.edu.es
// Fecha: 07/10/2024
// Archivo analizador_codigo.h: declaración de variable.
//
// Referencias:
// 		Enlaces de interés
//
// Historial de revisiones
// 07/10/2024 - Creación (primera versión) del código

#include <fstream>

#include "variable.cc"
#include "bucle.cc"
#include "comentario.cc"

#ifndef ANALIZADOR_CODIGO_H
#define ANALIZADOR_CODIGO_H

// La clase AnalizadorCodigo se encargará de analizar el archivo de entrada, así
// como escribir el resultado en el archivo de salida
class AnalizadorCodigo
{
private:
  vector<Variable> variables;
  vector<Bucle> bucles;
  vector<Comentario> comentarios;
  bool existeMain;


public:
  // Obtener posición de la línea
  int posicionLinea(string contenido, int posicion);

  // Contar lineas
  int contarLineas(string texto);

  // Función que analiza el texto del fichero
  void analizar(const string contenido);

  // Función que imprime el archivo de vuelta
  void resultadoAnalisis(ofstream& outfile);
};

#endif