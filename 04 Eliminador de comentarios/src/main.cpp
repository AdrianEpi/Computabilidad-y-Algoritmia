/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 3 Calculadora de lenguajes   =
  =            Archivo:       main.cpp                              =
  =            Autor:         Adrián Epifanio R.H                   =
  =            Fecha:         09/10/2019                            =
  =            Asignatura:    Computabilidad y Algoritmia           =
  =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/element.hpp"
#include "../class/unComment.hpp"
#include "../class/state.hpp"
#include "../class/transition.hpp"
/*------------------------------------------------*/
/*===================================================================
=                            MAIN PROGRAM                           =
===================================================================*/
int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "ERROR entrada erronea...\n Por favor escriba como primer argumento el nombre de fichero de texto de entrada y como segundo argumento el nombre del fichero de texto de salida." << endl << endl << "Un ejemplo sería:\n ./prueba entrada.cpp salida.txt " << endl << endl;
    exit(1);
  }
	string input_file;
	input_file = argv[1];
  string output_file;
  output_file = argv[2];
	unComment coment(input_file, output_file);
}
/*=================================================================*/
/*========================= End of Main  =========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 09/10/2019
 *
 *
**/

