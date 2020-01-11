/*===================================================================================
=====================================================================================
		=                                                                           =
    =            Proyecto:      Práctica 07 La construcción de subconjuntos     =
		=            Archivo:       reader.cpp                                      =
		=            Autor:         Adrián Epifanio Rodríguez Hernández             =
		=            Fecha:         25/10/2019                                      =
		=            Asignatura:    Computabilidad y Algoritmia                     =
		=            Lenguaje:      C++                                             =
		=            Correo:        alu0101158280@ull.edu.es                        =
		=            Lugar:         Universidad De La Laguna                        =
		=                           Escuela Superior de Ingeniería y Tecnología     =
		=                                                                           =
=====================================================================================
===================================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <fstream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/reader.hpp"
/*------------------------------------------------*/
/*===================================================================
=                           Reader Functions                        =
===================================================================*/
// Costructor parametrizado, le llegan fichero de entrada y de salida
reader::reader(string& in, string& out) 
{
  input_ = in;
  output_ = out;
}

// Ejecuta el DFA y guarda los datos de salida en el fichero
void reader::RunProgram(void) 
{
  ofstream output_file = OpenFile();
  DFA dfa;
  dfa.set_InputFile(input_);
  dfa.set_DFA();
  dfa.WriteFileDFA(output_file);
}
// Funcion que sirve para abrir el fichero de salida
ofstream reader::OpenFile(void) 
{
  ofstream output_file (output_, ios::out);
  if (output_file.fail())
  {
    system("clear");
    cout << "Error en la creación del fichero de salida." << endl << endl;
    exit (1);
  }
  else
    return output_file;
}
/*=================================================================*/
/*=======================  End of Functions  ======================*/
/**
 *
 *
 *   Autor: Adrián Epifanio Rodríguez Hernández
 *   Correo: alu0101158280@ull.edu.es
 *   Fecha: 25/10/2019
 *
 *
**/

