/*=========================================================================
===========================================================================
  =            Proyecto:      Práctica 04 Eliminador de comentarios =
  =            Archivo:       unComment.cpp                         =
  =            Autor:         Adrián Epifanio R.H                   =
  =            Fecha:         09/10/2019                            =
  =            Asignatura:    Computabilidad y Algoritmia           =
  =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/unComment.hpp"
#define MAX_LENGHT 100
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                           UnComment Functions                     =
===================================================================*/
unComment::unComment ( string file, string output_f )
{
  char filename[MAX_LENGHT], output_file[MAX_LENGHT];
  contador_ = 0;
  is_a_comment = false;
  string temporal_line, input_line;
  ifstream input;
  ofstream output;
  CreateStates();
  initial_state = estados_[0];
  actual_state.set_StateName(estados_[0].get_StateName());
  strcpy(filename, file.c_str());
  strcpy(output_file, output_f.c_str());
  input.open(filename);
  output.open(output_file);
  if (output.fail())
  {
    cout << "Error en el archivo de salida";
    exit(1);
  }
  if (input.is_open())
  {
    while (!input.eof())
    {
      getline(input, temporal_line);
      Write(output, Analizer(temporal_line));
      if (final_line = true)
        final_line = false;
    }
    input.close();
  }
  output.close();
  if (contador_ == 0)
    cout << "Comentarios cerrados correctamente" << endl;
  else
    cout << "Fallo en los comentarios, faltan por cerrar " << contador_-1 << " comentarios." << endl;
}

string unComment::Analizer ( string temporal_line )
{
  char aux[temporal_line.size()], tmp[temporal_line.size()];
  int d = 0;
  for (int k = 0; k < temporal_line.size(); k++)
    tmp[k] = '\0';
  strcpy(aux, temporal_line.c_str());
  for (int i = 0; i < temporal_line.size(); i++)
  {
    int sentinel;
    sentinel = actual_state.get_StateName();
    switch (sentinel)
    {
      case 0:
        if (aux[i] == estados_[0].get_Tran(0).get_Symbol())
        {
          actual_state.set_StateName(estados_[actual_state.get_StateName()].get_Tran(0).get_NextState());
          if ((aux[i+1] != estados_[0].get_Tran(0).get_Symbol()) && (aux[i+1] != estados_[0].get_Tran(1).get_Symbol()))
          {
            tmp[d] = aux[i];
            d++;
          }
        }
        else
        {
          tmp[d] = aux[i];
          d++;
        }
        break;

      case 1:
        if ((aux[i] == estados_[1].get_Tran(0).get_Symbol()) || (aux[i] == estados_[1].get_Tran(1).get_Symbol()))
        {
          if (aux[i] == estados_[1].get_Tran(0).get_Symbol())
            actual_state.set_StateName(estados_[actual_state.get_StateName()].get_Tran(0).get_NextState());
          else
          {
            actual_state.set_StateName(estados_[actual_state.get_StateName()].get_Tran(1).get_NextState());
            is_a_comment = true;
          }
        }
        else
        {
          actual_state.set_StateName(estados_[actual_state.get_StateName()].get_Tran(3).get_NextState());
          tmp[d] = aux[i];
          d++;
        }
        break;

      case 2:
        actual_state.set_StateName(estados_[actual_state.get_StateName()].get_Tran(2).get_NextState());
        if (is_a_comment == false)
        {
          final_line = true;
          string line_(tmp);
          return line_;
        }
        break;

      case 3:
        if ((aux[i] == estados_[3].get_Tran(1).get_Symbol()) && (contador_ == 0))
        {
          actual_state.set_StateName(estados_[actual_state.get_StateName()].get_Tran(1).get_NextState());
          contador_++;
        }
        else if ((aux[i] == estados_[3].get_Tran(0).get_Symbol()) && (aux[i+1] == estados_[3].get_Tran(1).get_Symbol()))
          contador_++;
        break;

      case 4:
        if (aux[i] == estados_[4].get_Tran(1).get_Symbol())
        {
          actual_state.set_StateName(estados_[actual_state.get_StateName()].get_Tran(1).get_NextState());
          tmp[d-1] = '\0';
        }
        else if (aux[i] == estados_[4].get_Tran(0).get_Symbol() && (contador_ == 0))
        {
          is_a_comment = false;
          contador_--;
          actual_state.set_StateName(estados_[actual_state.get_StateName()].get_Tran(0).get_NextState());
        }
        else if (aux[i] == estados_[4].get_Tran(0).get_Symbol() && (contador_ != 0))
        {
          is_a_comment = false;
          contador_--;
          actual_state.set_StateName(estados_[actual_state.get_StateName()].get_Tran(0).get_NextState());
        }
        else
          actual_state.set_StateName(estados_[actual_state.get_StateName()].get_Tran(3).get_NextState());
        break;
    }
  }
  string line(tmp);
  return line;
}

state unComment::SendToState ( int name, int num, transition trans)
{
  set<state>::iterator it;
  for (it = states_.begin(); it != states_.end(); it++)
  {
    state tmp_state = (*it);
    if(tmp_state.get_StateName() == name)
      return tmp_state;
  }
  return state();
}

void unComment::CreateStates()
{
  char dfa_name[MAX_LENGHT], temp[5], alpha, endline = '\n', other = '-';
  int initial;
  unsigned sentinel;
  string dfa = "./Inputs/dfa.txt", tmp;
  strcpy(dfa_name, dfa.c_str());
  ifstream input2;
  input2.open(dfa_name);
  if (input2.is_open())
  {
    input2 >> tmp;
    strcpy(temp, tmp.c_str());
    total_states = atoi(temp);
    input2 >> tmp;
    strcpy(temp, tmp.c_str());
    initial = atoi(temp);
    for (int i = 0; i < total_states; i++)
    {
      input2 >> tmp;
      strcpy(temp, tmp.c_str());
      sentinel = atoi(temp);
      estados_[i].set_StateName(sentinel);
      for (int j = 0; j < 4; j++)
      {
        input2 >> alpha >> sentinel;
        if (alpha == '-')
          estados_[i].set_Tran(j, endline, sentinel);
        else if (alpha == 'o')
          estados_[i].set_Tran(j, other, sentinel);
        else 
          estados_[i].set_Tran(j, alpha, sentinel);
      }
    }
    input2.close();
  }
  else 
  {
    cout << "Failed to open the DFA" << endl;
    exit(1);
  }
}

void unComment::Write(ostream& os, string input_line) const
{
  if (final_line == true)
  {
    os << input_line << endl;
  }
  else
  os << input_line;
}
/*=================================================================*/
/*=======================  End of Functions  ======================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 09/10/2019
 *
 *
**/

