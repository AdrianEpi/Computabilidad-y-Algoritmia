/*=========================================================================
===========================================================================
    =            Proyecto:      Práctica 2 Análisis de Texto          =
    =            Archivo:       analizador.cpp                             =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         27/09/2019                            =
    =            Asignatura:    Computabilidad y Algoritmia           =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <ctype.h>
#include <set>
#include <fstream>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "analizador.hpp"
#define MAX_LENGTH 30
/*------------------------------------------------*/
/*===================================================================
=                           Analizador Functions                    =
===================================================================*/
word::word()
{
  integer_ = 0;
  floating_ = 0;
  cadena_ = '\0';
}
word::word(string cadena)
{
  bool aux = false; //Para saber si es un número entero o flotante;
  int i = 30, integer;
  float floating;
  char sentinel[MAX_LENGTH];
  strcpy(sentinel, cadena.c_str());
  cout << sentinel[0] << endl;
  if (isdigit(sentinel[0]))
  {
    for (int k = 0; k < MAX_LENGTH; k++)
      if (sentinel[k] == '.')
        aux = true;
    if (aux)
    {
      floating = atof(sentinel);
      set_Floating(floating);
    }
    else
    {
      integer = atoi(sentinel);
      set_Integer(integer);
    }
  }
  else if ((sentinel[0] == '+') || (sentinel[0] == '-') || (sentinel[0] == '*') || (sentinel[0] == '/') || (sentinel[0] == '=') || (sentinel[0] == '<') || (sentinel[0] == '>') || (sentinel[0] == '!'))
  {
    set_Operator(sentinel[0]);
    if (sentinel[1] == '=')
      set_Operator2(sentinel[1]);
  }
  else if ((sentinel[0] == '(') || (sentinel[0] == ')') || (sentinel[0] == '[') || (sentinel[0] == ']') || (sentinel[0] == '.') || (sentinel[0] == '{') || (sentinel[0] == '}') || (sentinel[0] == ';') || (sentinel[0] == ','))
    set_Punctuation(sentinel[0]);
  else
    Reserved(cadena);
}

void word::Update(string cadena)
{
  bool aux = false; //Para saber si es un número entero o flotante;
  int i = 30, integer;
  float floating;
  char sentinel[MAX_LENGTH];
  strcpy(sentinel, cadena.c_str());

  if (isdigit(sentinel[0]))
  { 
    for (int k = 0; k < MAX_LENGTH; k++)
      if (sentinel[k] == '.')
        aux = true;
    if (aux)
    {
      floating = atof(sentinel);
      set_Floating(floating);
    }
    else
    {
      integer = atoi(sentinel);
      set_Integer(integer);
    }
  }
  else if ((sentinel[0] == '+') || (sentinel[0] == '-') || (sentinel[0] == '*') || (sentinel[0] == '/') || (sentinel[0] == '=') || (sentinel[0] == '<') || (sentinel[0] == '>') || (sentinel[0] == '!'))
  {
    set_Operator(sentinel[0]);
    if (sentinel[1] == '=')
      set_Operator2(sentinel[1]);
  }
  else if ((sentinel[0] == '(') || (sentinel[0] == ')') || (sentinel[0] == '[') || (sentinel[0] == ']') || (sentinel[0] == '.') || (sentinel[0] == '{') || (sentinel[0] == '}') || (sentinel[0] == ';') || (sentinel[0] == ','))
    set_Punctuation(sentinel[0]);
  else
  {
    if (Reserved(cadena))
      set_Cadena(cadena);
  }
}

bool word::Reserved(string cadena)
{
  char aux[MAX_LENGTH];
  strcpy(aux, cadena.c_str());
  for (int k = 0; aux[k] != '\0'; ++k)//Para pasar la cadena a mayúscula letra a letra
    aux[k] = toupper(aux[k]);
  string cadena_copy(aux); //Copia de la cadena pero con letras mayúsuclas
  std::set<std::string>::iterator it = reserved_l.find(cadena_copy); //Ciclo de búsqueda del set
  if (it != reserved_l.end())
  {
    set_Reserved(cadena_copy);
    reservada_=true;
    return true;
  }
  else
  {
    set_Cadena(cadena);
    reservada_ = false;
    return false;
  }
}

void word::Write(ostream& os, int mode) const
{
  if (mode == 0)
  {
    if (get_Integer() != 0)
      os << " INT " << get_Integer();
    else if (get_Floating() != 0.000)
      os << " FLOT " << get_Floating();
    else if (get_Operator() != '\0')
      if (get_Operator2() == '=')
        os << " OP " << get_Operator() << "=";
      else
        os << " OP " << get_Operator();
    else if (get_Punctuation() != '\0')
      os << " SIG " << get_Punctuation();
    else if (reservada_)
      os << " " << get_Reserved();
    else
      os << " PAL " << cadena_;
  }
  else 
  {
    if (get_Integer() != 0)
      os << " INT ";
    else if (get_Floating() != 0.000)
      os << " FLOT ";
    else if (get_Operator() != '\0')
      if (get_Operator2() == '=')
        os << " OP ";
      else
        os << " OP ";
    else if (get_Punctuation() != '\0')
      os << " SIG ";
    else if (reservada_)
      os << " " << get_Reserved();
    else
      os << " PAL ";
  }
}
/*=================================================================*/
/*=======================  End of Functions  ======================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 27/09/2019
 *
 *
**/

