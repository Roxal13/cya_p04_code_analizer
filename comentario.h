// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Álvaro Romeo Franco
// Correo: alu0101679716@ull.edu.es
// Fecha: 07/10/2024
// Archivo comentario.h: declaración de comentario.
//
// Referencias:
// 		Enlaces de interés
//
// Historial de revisiones
// 07/10/2024 - Creación (primera versión) del código

#include <iostream>
#include <string>
#include <string>
#include <regex>

using namespace std;

#ifndef COMENTARIO_H
#define COMENTARIO_H

// La clase comentario
class Comentario
{
private:
  string contenido;
  int inicio;
  int fin;

public:
  // Constructor que crea el comentario de una línea
  Comentario(string contenido, int inicio);

  // Constructor que crea el comentario multi-línea
  Comentario(string contenido, int inicio, int fin);

  // Devolver la salida de la descripción
  string salidaDescripcion();

  // Devolver la salida del comentario
  string salidaComentario();

  // Se obtiene el inicio
  int getInicio();

  // Se obtiene el final
  int getFin();
};

#endif