// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Álvaro Romeo Franco
// Correo: alu0101679716@ull.edu.es
// Fecha: 07/10/2024
// Archivo bucle.cc: definición de bucle.
//
// Referencias:
// 		Enlaces de interés
//
// Historial de revisiones
// 07/10/2024 - Creación (primera versión) del código

#include "bucle.h"

// Contructor de bucle
Bucle::Bucle(string tipo, int linea)
{
	this->tipo = tipo;
	this->linea = linea;
}

// Devuelve el formato a escribir en el archivo de salida
string Bucle::salidaBucle()
{
	return "[Line " + to_string(this->linea) + "] LOOP: " + this->tipo;
}