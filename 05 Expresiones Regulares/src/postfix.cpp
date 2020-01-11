/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 05 Expresiones Regulares     =
  =            Archivo:       postfix.cpp                           =
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
#include "../class/postfix.hpp"
/*------------------------------------------------*/
/*===================================================================
=                           Postfix Functions                       =
===================================================================*/
postfix::postfix( string a )
{
  Update(a);
}

void postfix::Update( string a )
{
  char sentinela[a.size()], temporal[a.size()];
  strcpy(sentinela, a.c_str());
  EmptyStacks();
  counter_=0;
  parentesis = false;
  for (int i = 0; i < a.size()+1; i++)
  {
    if (isalpha(sentinela[i]))
      aux.push(sentinela[i]);
    else if (sentinela[i] != '\0')
    {
      if (operator_aux.empty())
        operator_aux.push(sentinela[i]);
      else
      {
        if (parentesis == false)
        {
          if ((get_Priority(operator_aux.top()) > get_Priority(sentinela[i])) || (get_Priority(sentinela[i]) == 4))
            operator_aux.push(sentinela[i]);
          else if ((get_Priority(operator_aux.top()) == get_Priority(sentinela[i])) && (get_Priority(sentinela[i]) != 0))
            aux.push(sentinela[i]);
          else
          {
            while (get_Priority(operator_aux.top()) < get_Priority(sentinela[i]))
            {
              aux.push(operator_aux.top());
              operator_aux.pop();
            }
            operator_aux.push(sentinela[i]);
          }
        }
        else
        {
          if ((get_Priority(operator_aux.top()) > get_Priority(sentinela[i])) && (get_Priority(sentinela[i]) != 0))
            operator_aux.push(sentinela[i]);
          else if ((get_Priority(operator_aux.top()) == get_Priority(sentinela[i])) && (get_Priority(sentinela[i]) != 0))
            aux.push(sentinela[i]);
          else
          {
            while ((get_Priority(operator_aux.top()) < get_Priority(sentinela[i])) || (get_Priority(operator_aux.top()) != 4))
            {
              aux.push(operator_aux.top());
              operator_aux.pop();
            }
            if (get_Priority(sentinela[i]) == 0)
              operator_aux.pop();
            else
              operator_aux.push(sentinela[i]);
          } 
        }
      }
      if (get_Priority(sentinela[i]) == 4)
      {
        parentesis = true;
        counter_++;
      }
      else if (get_Priority(sentinela[i]) == 0)
      {
        counter_--;
        if (counter_ == 0)
          parentesis = false;
      }
    }
  }
  while (!operator_aux.empty())
  {
    aux.push(operator_aux.top());
    operator_aux.pop();
  }
  for (int j = CharacterCounter(a)-1; j >= 0; j--)
  {
    temporal[j] = aux.top();
    aux.pop();
  }
  temporal[CharacterCounter(a)] = '\0';
  string dummy(temporal);
  set_Postfix(dummy);
}

void postfix::EmptyStacks()
{
  if (!aux.empty())
    while (!aux.empty())
      aux.pop();
  if (!operator_aux.empty())
    while (!operator_aux.empty())
      operator_aux.pop();
}

int postfix::get_Priority(char aux)
{
  if (aux == '*')
    return 1;
  else if (aux == '&')
    return 2;
  else if (aux == '|')
    return 3;
  else if (aux == '(')
    return 4;
  else if (aux == ')')
    return 0;
  else if (operator_aux.empty())
    return 6;
  else
  {
    cout << " Fallo en el sistema de prioridades." << endl;
    exit(1);
  }
}

void postfix::ShowStack( int i )
{
  if (i == 1)
  {
    if (aux.empty())
      cout << "Pila auxiliar vacía" << endl;
    else
      while (!aux.empty()) 
        { 
          cout << '\t' << aux.top(); 
          aux.pop(); 
        } 
  }
  else if (i == 2)
  {
    if (operator_aux.empty())
      cout << "Pila de operadores vacía" << endl;
    else
      while (!operator_aux.empty()) 
        { 
          cout << '\t' << operator_aux.top(); 
          operator_aux.pop(); 
        } 
  }
  else
    cout << "Pila incorrecta o corrupta" << endl;
}

int postfix::CharacterCounter( string a )
{
  char tmp[a.size()];
  int aux = 0;
  strcpy(tmp, a.c_str());
  for (int i = 0; i < a.size(); i++)
    if ((tmp[i] != '\0') && (tmp[i] != '(') && (tmp[i] != ')'))
      aux++;
  return aux;
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

