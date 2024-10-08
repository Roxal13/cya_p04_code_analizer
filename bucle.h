// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Álvaro Romeo Franco
// Correo: alu0101679716@ull.edu.es
// Fecha: 07/10/2024
// Archivo bucle.h: declaración de bucle.
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

#ifndef BUCLE_H
#define BUCLE_H

// La clase Bucle
class Bucle
{
private:
  string tipo; // "for" o "while"
  int linea;   // Línea donde se encuentra el bucle
  

public:
  // Constructor que crea el bucle
  Bucle(string tipo, int linea);  

  // Devolver la salida del bucle
  string salidaBucle();
};

#endif