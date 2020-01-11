/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 05 Expresiones Regulares     =
  =            Archivo:       infix.cpp                           =
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
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/infix.hpp"
#define MAX_LENGHT 100
/*------------------------------------------------*/
/*===================================================================
=                           Infix Functions                       =
===================================================================*/
infix::infix( string string_, set<char> alphabet_)
{
  Update( string_, alphabet_);
}

void infix::set_Charcounter( string a )
{
  char tmp[a.size()];
  charcounter = 0;
  strcpy(tmp, a.c_str());
  for (int i = 0; i < a.size(); i++)
    if ((tmp[i] != '\0') && (tmp[i] != '(') && (tmp[i] != ')'))
      charcounter++;  
}

void infix::Update(string string_, set<char> alphabet_)
{
  int j = 0;
  char tmp[string_.size()], aux[MAX_LENGHT];
  strcpy(tmp, string_.c_str());
  for (int k = 0; k < MAX_LENGHT; k++)
    aux[k] = '\0';
  for (int i = 0; i < string_.size(); i++)
  {
    set<char>::iterator it = alphabet_.find(tmp[i]);
    if (it != alphabet_.end())
    {
      aux[j] = tmp[i];
      if (((isalpha(tmp[i])) && (isalpha(tmp[i+1]))) || ((tmp[i] == '*') && (tmp[i+1] != '\0')) || ((tmp[i] == ')') && (tmp[i+1] == '(')))
      {
        j++;
        aux[j] = '&';
      }
      j++;
    }
    /*else if (tmp[i] != '\n')
    {
      cout << "Error en el fichero de entrada, caracter no permitido." << endl;
      exit(1);
    }*/
  }
  string temporal(aux);
  set_Charcounter(temporal);
  set_Infix(temporal);
  postfix_.Update(temporal);
  prefix_.Update(temporal);
}

void infix::Write()
{
  cout << infix_ << endl;
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

