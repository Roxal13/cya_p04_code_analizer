// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Álvaro Romeo Franco
// Correo: alu0101679716@ull.edu.es
// Fecha: 07/10/2024
// Archivo comentario.h: definición de comentario.
//
// Referencias:
// 		Enlaces de interés
//
// Historial de revisiones
// 07/10/2024 - Creación (primera versión) del código

#include "comentario.h"

// Constructor que crea el comentario de una línea
  Comentario::Comentario(string contenido, int inicio)
  {
    this->contenido = contenido;
    this->inicio = inicio;
  }

  // Constructor que crea el comentario multi-línea
  Comentario::Comentario(string contenido, int inicio, int fin)
  {
    this->contenido = contenido;
    this->inicio = inicio;
    this->fin = fin;
  }

  // Devolver la salida de la descripción
  string Comentario::salidaDescripcion()
  {
    return "DESCRIPTION:\n" + this->contenido;
  }

  // Devolver la salida del comentario
  string Comentario::salidaComentario()
  {
    return "[Line " + to_string(this->inicio) + (this->inicio == 1 ? "-" + to_string(this->fin) + "] DESCRIPTION" : "] " + this->contenido);
  }

  // Se obtiene el inicio
  int Comentario::getInicio()
  {
    return this->inicio;
  }