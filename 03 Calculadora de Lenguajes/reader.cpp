/*=========================================================================
===========================================================================
    =            Proyecto:      Práctica 3 Calculadora de lenguages   =
    =            Archivo:       reader.cpp                            =
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
#include "reader.hpp"
#include "calculator.hpp"
#define MAX_LENGTH 15
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                             Reader Functions                      =
===================================================================*/
reader::reader(string filename)
{ 
  counter_ = 0;
  string character, character_copy;
  int k = 0;
  char aux[MAX_LENGTH], tmp[MAX_LENGTH], filename_[30];
  ifstream textfile;
  strcpy(filename_, filename.c_str());
  textfile.open(filename_);
  if (textfile.is_open())
  {
    while (!textfile.eof())
    {
      textfile >> character;
      strcpy(aux, character.c_str());
      for (int i = 0; i < character.size(); i++)
      {
        if (aux[i] == '{')
          counter_ = counter_ + 1;
        else if (aux[i] == ',')
        {
          string sentinel(tmp);
          alphabet_tmp[k].insert(sentinel);
        }
        else if (aux[i] == '}')
        {
          if (i - 1 < 0)
            alphabet_tmp[k].insert(character_copy);
          else
          {
            string sentinel(tmp);
            alphabet_tmp[k].insert(sentinel);
          }
          k++;
        }
        else
          tmp[i] = aux[i];
        character_copy = character;
      }
      for (int j = 0; j < MAX_LENGTH; j++)
      {
        aux[j] = '\0';
        tmp[j] = '\0';
      }
    };
    textfile.close();
  }
  else
    cout << "Error 404. File not found";
}

void reader::Erase()
{
  for (int k = 0; k < counter_; k++)
  {
    std::set<std::string>::iterator it[k] = alphabet_tmp[k].begin();
    std::set<std::string>::iterator it_end[k] = alphabet_tmp[k].end();
    alphabet_tmp[k].erase(it[k], it_end[k]);
  }
  counter_ = 0;
}

void reader::Update(string filename)
{
  Erase();
  string character;
  int k = 0;
  char aux[MAX_LENGTH], filename_[30];
  ifstream textfile;
  strcpy(filename_, character.c_str());
  textfile.open(filename_);
  if (textfile.is_open())
  {
    while (!textfile.eof())
    {
      textfile >> character;
      strcpy(aux, character.c_str());
      if (aux[0] == '{')
        counter_ =+ 1;
      else if (aux[0] == '}')
        k++;
      else
        alphabet_tmp[k].insert(character);
      for (int j = 0; j < MAX_LENGTH; j++)
        aux[j] = '\0';
    }
    textfile.close();
  }
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

