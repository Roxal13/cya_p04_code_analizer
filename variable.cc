// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Álvaro Romeo Franco
// Correo: alu0101679716@ull.edu.es
// Fecha: 07/10/2024
// Archivo variable.cc: definición de variable.
//
// Referencias:
// 		Enlaces de interés
//
// Historial de revisiones
// 07/10/2024 - Creación (primera versión) del código

#include "variable.h"

// Constructor de variable
Variable::Variable(string tipo, string nombre, int linea, string valor)
{
  this->tipo = tipo;
  this->nombre = nombre;
  this->linea = linea;
  this->valor = valor;
}


// Devuelve el formato a escribir en el archivo de salida
string Variable::salidaVariable()
{
  return "[Line " + to_string(this->linea) + "] " + (this->tipo == "int" ? "INT" : "DOUBLE") + ": " + this->nombre + (this->valor == "N/A" ? "" : " = " + this->valor);
}