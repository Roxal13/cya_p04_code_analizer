// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Álvaro Romeo Franco
// Correo: alu0101679716@ull.edu.es
// Fecha: 07/10/2024
// Archivo variable.h: declaración de variable.
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

#ifndef VARIABLE_H
#define VARIABLE_H

// La clase Estructura
class Variable
{
private:
  string tipo;          // "int" o "double"
  string nombre;        // Nombre de la variable
  int linea;            // Línea donde se declara
  string valor;  // Valor de lav ariable

public:
  // Constructor que crea la variable
  Variable(string tipo, string nombre, int linea, string valor);

  // Devolver la salida de la variable
  string salidaVariable();
};

#endif