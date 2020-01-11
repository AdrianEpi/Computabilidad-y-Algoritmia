/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 05 Expresiones Regulares     =
  =            Archivo:       ER2Tree.cpp                           =
  =            Autor:         Adrián Epifanio R.H                   =
  =            Fecha:         16/10/2019                            =
  =            Asignatura:    Computabilidad y Algoritmia           =
  =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/ER2Tree.hpp"
#define MAX_LENGTH 100
/*------------------------------------------------*/
/*===================================================================
=                           ER2Tree Functions                       =
===================================================================*/
ER2Tree::ER2Tree( string input, string output )
{
  char input_filename[MAX_LENGTH], output_filename[MAX_LENGTH];
  counter_ = 0;
  string temporal;
  ifstream input_;
  ofstream output_;
  strcpy(input_filename, input.c_str());
  strcpy(output_filename, output.c_str());
  input_.open(input_filename);
  if (input_.is_open())
  {
    output_.open(output_filename);
    if (output_.is_open())
    {
      output_ << "______________________________________________________" << endl << "Infix\t\t\tPostFix\t\tPrefix\t\tNodes" << endl << "______________________________________________________" << endl;
      while (!input_.eof())
      {
        getline(input_, temporal);
        infix_[counter_].Update(temporal, get_Alphabet());
        Write(output_);
        counter_++;
      }
      output_.close();
    }
    else
      cout << "Error, no se ha encontrado o no se ha podido crear el fichero de salida." << endl;
    input_.close();
  }
  else
    cout << "Error, no se ha encontrado el fichero de entrada." << endl;
}

void ER2Tree::Write( ostream& os ) const
{
  if (infix_[counter_].get_Charcounter()  <= 5)
    os << infix_[counter_].get_Infix() << "\t\t\t" << infix_[counter_].get_Postfix().get_Postfix() << "\t\t\t" << infix_[counter_].get_Prefix().get_Prefix() << "\t\t\t" << infix_[counter_].get_Charcounter() << endl;
  else if (infix_[counter_].get_Charcounter()  <= 10)
    os << infix_[counter_].get_Infix() << "\t" << infix_[counter_].get_Postfix().get_Postfix() << "\t\t" << infix_[counter_].get_Prefix().get_Prefix() << "\t\t" << infix_[counter_].get_Charcounter() << endl;
  else
  {
    cout << "AVISO: La entrada contiene expresiones muy largas como para que se vean correctamente.";
    os << infix_[counter_].get_Infix() << infix_[counter_].get_Postfix().get_Postfix() << infix_[counter_].get_Prefix().get_Prefix() << infix_[counter_].get_Charcounter() << endl;
  }
}
/*=================================================================*/
/*=======================  End of Functions  ======================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 16/10/2019
 *
 *
**/

