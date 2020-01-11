/*===================================================================================
=====================================================================================
		=                                                                           =
    =            Proyecto:      Práctica 07 La construcción de subconjuntos     =
		=            Archivo:       alphabet.cpp                                    =
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
#include <iostream>
#include <sstream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/alphabet.hpp"
/*------------------------------------------------*/
/*===================================================================
=                           Alphabet Functions                      =
===================================================================*/
// Constructor parametrizado a partir de otro alfabeto
alphabet::alphabet(const alphabet& alphabet) 
{
  alphabet_ = alphabet.get_Alphabet();
}

// Crea un alfabeto de la cadena que le es pasada
alphabet::alphabet(string& string_) 
{	
  Create_Alphabet(string_);
}

// Imprime por pantalla el alfabeto del DFA
void alphabet::Alphabet_Write(void) const 
{
  int aux;    // Contador auxiliar para recorrer el set
  set<char>::iterator it = alphabet_.begin();
  cout << "{";
  for (; it != alphabet_.end(); it++)   //For especial de c++11
  {
    cout << *it;
    aux++;
    if (aux < Alphabet_Size())
      cout << ", ";
  }
  cout << "}" << endl;
}

// Extrae los caracteres de la cadena para añadirlos al alfabeto
void alphabet::Create_Alphabet (const string string_) 
{
  for (int i = 0; i < string_.size(); i++)
    alphabet_.insert(string_[i]);
}

// Devuelve el tamaño del alfabeto
int alphabet::Alphabet_Size (void) const 
{
  set<char>::iterator it = alphabet_.begin();
  int size;
  for (; it != alphabet_.end(); it++)
    size++;
  return size;
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

