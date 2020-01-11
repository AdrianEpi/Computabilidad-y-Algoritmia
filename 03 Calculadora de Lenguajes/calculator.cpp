/*=========================================================================
===========================================================================
    =            Proyecto:      Práctica 3 Calculadora de lenguages   =
    =            Archivo:       calculator.cpp                        =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         02/10/2019                            =
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
#include "calculator.hpp"
#define MAX_LENGTH 30
/*------------------------------------------------*/
/*===================================================================
=                         Calculator Functions                      =
===================================================================*/
set<string> calculator::Concatenacion(set<string> language_A, set<string> language_B)
{
  string tmp;
  char aux[MAX_LENGTH];
  for (set<string>::iterator it=language_A.begin(); it!=language_A.end(); ++it)
  {
    for (set<string>::iterator it2=language_B.begin(); it2!=language_B.end(); ++it2)
    {
      if (*it == "&")
        result_.insert(*it2);
      else if (*it2 == "&")
        result_.insert(*it);
      else
      {
        tmp = *it + *it2;
        result_.insert(tmp);
      }
    }
  }
  return result_;    
}

set<string> calculator::Union(set<string> language_A, set<string> language_B)
{
  for (set<string>::iterator it=language_A.begin(); it!=language_A.end(); ++it)
    result_.insert(*it);
  for (set<string>::iterator it2=language_B.begin(); it2!=language_B.end(); ++it2)
    result_.insert(*it2);
  return result_;
}

set<string> calculator::Interseccion(set<string> language_A, set<string> language_B)
{
  for (set<string>::iterator it=language_A.begin(); it!=language_A.end(); ++it)
  {
    for (set<string>::iterator it2=language_B.begin(); it2!=language_B.end(); ++it2)
      if (*it == *it2)
        result_.insert(*it);
  }
  return result_;    
}

set<string> calculator::Diferencia(set<string> language_A, set<string> language_B)
{
  bool aux = false;
  for (set<string>::iterator it=language_A.begin(); it!=language_A.end(); ++it)
  {
    for (set<string>::iterator it2=language_B.begin(); it2!=language_B.end(); ++it2)
      if (*it == *it2)
        aux = true;
    if (aux)
      aux = false;
    else
      result_.insert(*it);
  }
  return result_;    
}

bool calculator::Igualdad(set<string> language_A, set<string> language_B)
{
  bool aux = false;
  for (set<string>::iterator it=language_A.begin(); it!=language_A.end(); ++it)
  {
    for (set<string>::iterator it2=language_B.begin(); it2!=language_B.end(); ++it2)
      if (*it == *it2)
        aux = true;
    if (aux)
      aux = false;
    else
      return false;
  }
  for (set<string>::iterator it2=language_B.begin(); it2!=language_B.end(); ++it2)
  {
    for (set<string>::iterator it=language_A.begin(); it!=language_A.end(); ++it)
      if (*it == *it2)
        aux = true;
    if (aux)
      aux = false;
    else 
      return false;
  }
  return true;   
}

bool calculator::Sublenguajes(set<string> language_A, set<string> language_B)
{
  bool aux = true;
  for (set<string>::iterator it=language_A.begin(); it!=language_A.end(); ++it)
  {
    for (set<string>::iterator it2=language_B.begin(); it2!=language_B.end(); ++it2)
      if (*it != *it2)
        aux = false;
  }
  return aux; 
}

set<string> calculator::Inversa(set<string> language_A)
{
  string aux;
  int j;
  for (set<string>::iterator it=language_A.begin(); it!=language_A.end(); ++it)
  {
    aux = *it;
    char tmp[aux.size()], temp[aux.size()];
    strcpy(tmp, aux.c_str());
    j = 0;
    for (int i = aux.size()-1; i >= 0; i-- )
    {
      temp[j] = tmp[i];
      j++;
    }
    aux = temp;
    result_.insert(aux);
    for (int j = 0; j < aux.size(); j++)
    {
      aux[j] = '\0';
      tmp[j] = '\0';
    }
  }
  return result_;
}

string calculator::Potencia(set<string> language_A, const string iterator, int num)
{
  int exp = num - 1, sentinel;
  string aux, tmp;
  if (num == 0)
    return iterator;
  else
  {
    aux = iterator;
    for (set<string>::iterator it=language_A.begin(); it!=language_A.end(); ++it)
    {
      tmp = aux + *it;
      Potencia(language_A, tmp, exp);
      if (sizeof(tmp) >= (num * sizeof(*it)))
        result_.insert(tmp);
    }
  }
  return tmp;
}

string calculator::Cierre_Positivo(set<string> language_A, const string iterator, int num)
{
  if (iterator == "&")
    return iterator;
  int exp = num - 1;
  string aux, tmp;
  if (num == 0)
    return iterator;
  else
  {
    aux = iterator;
    for (set<string>::iterator it=language_A.begin(); it!=language_A.end(); ++it)
    {
      tmp = aux + *it;
      result_.insert(tmp);
      Cierre_Positivo(language_A, tmp, exp);
      result_.insert(tmp);
    }
  }
  return tmp;
}

void calculator::Cierre_Kleene(set<string> language_A, const string iterator, int num)
{
  result_.insert("&");
  Cierre_Positivo(language_A, iterator, num);
}

void calculator::Write(ostream& os) const
{
  os << "{";
  for (set<string>::iterator it=result_.begin(); it!=result_.end(); ++it)
  {
    if (it == result_.begin())
      os << ' ' << *it;
    else
        os << ", " << *it;
  }
  os << " }" << endl << endl;
}
/*=================================================================*/
/*=======================  End of Functions  ======================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 02/10/2019
 *
 *
**/