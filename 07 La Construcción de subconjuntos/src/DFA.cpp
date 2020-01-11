/*===================================================================================
=====================================================================================
    =                                                                           =
    =            Proyecto:      Práctica 07 La construcción de subconjuntos     =
    =            Archivo:       DFA.cpp                                         =
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
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <string>
/*------------------------------------------------*/
/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "../class/DFA.hpp"
using namespace std;
/*------------------------------------------------*/
/*===================================================================
=                           DFA Functions                           =
===================================================================*/
// Constructor de copia
DFA::DFA (const DFA& aux)
{
  alphabet_ = aux.get_Alphabet();
  states_ = aux.get_States ();
  states_num = aux.get_StatesNum();
  acepted_states = aux.get_AcceptedStates();
  initial_state_ = aux.get_InitialState();
}

// Establece un DFA
void DFA::set_DFA (void) 
{
  ReadFile();
}

// Funcion que ayuda a realizar las trancisiones de un estado a su proximo
unsigned int DFA::NextTransition (state aux, char simbol) const 
{
  for (transition dato : aux.get_Trans())
    if (dato.get_Symbol() == simbol)
      return dato.get_NextState();
} 

// Funcion para añadir estados
void DFA::AddState (state aux) 
{
  states_.insert(aux);
}

// Se encarga de imprimir el conjunto de estados y toda la información a cerca de los mismos por pantalla
void DFA::WriteScreenDFA (void) const 
{
  cout << "Numero de estados: " << states_num << endl << "Alfabeto: ";
  alphabet_.Alphabet_Write();
  cout << "Estado inicial: ";
  initial_state_.StateWrite();
  cout << endl << "Conjunto de estados: " << endl;
  set<state>::iterator it = states_.begin();
  for (; it !=  states_.end(); it++)
    it -> StateWrite();
  it = acepted_states.begin();
  for (; it !=  acepted_states.end(); it++)
    it -> StateWrite();
  cout << endl << endl;
}

// Se encarga de encontrar un estado concreto a traves de su identificador
state DFA::FindState (unsigned int iden) const 
{
  set <state>::iterator it = states_.begin();
  for (; it !=  states_.end(); it++)
    if (it -> get_StateID() == iden)
      return *it;
}


void DFA::ReadFile (void) 
{
  ifstream file_in(input_file, ios::in);
  if (file_in.fail())
  {
    cout << "Error 404, fichero de entrada no encontrado." << endl << endl;
    exit(1);
  }
  else
  {
    string sentinel, aux_string; //Cadena auxiliar
    vector<state> aux_states, aux_accepted_states; //Vectores auxiliares de estados
    int n_final_states, n_transitions;  //Variables auxiliares
    char transition_symbol;

    do // Bucle para no leer los comentarios del encabezado
    {
      getline(file_in, sentinel);
    }while (sentinel[0] == '/' && sentinel[1] == '/');
    int symbol_num = stoi(sentinel); // Almacena el número de simbolos del alfabeto.
    symbol_num++; //Para que coja el simbolo ~ de las epsilon transiciones
    sentinel = ""; //Limpia la cadena auxiliar.
    for (int i = 0; i < symbol_num; i++)  //Almacena los símbolos del alfabeto en otra cadena auxiliar para crear el alfabeto.
    {
      file_in >>  sentinel;
      aux_string += sentinel;
    }
    alphabet_.Create_Alphabet(aux_string);
    file_in >> states_num; //Almacena la cantidad de estados del DFA en el atributo privado
    sentinel = "";
    aux_states.resize(states_num); //Resize del tamaño del vector auxiliar al numero total de estados
    for(int i = 0; i < states_num; i++) //Bucle para asignar los datos a los estados en el vector auxiliar
    {
      file_in >> sentinel;
      aux_states[i].set_StateName(sentinel);
      aux_states[i].set_StateID(i);
    }
    sentinel = "";
    file_in >> sentinel;
    for(int i = 0; i < aux_states.size(); i++) //Bucle para buscar y establecer el estado inicial
      if(aux_states[i].get_StateName() == sentinel)
        initial_state_ = aux_states[i];
    file_in >> n_final_states;
    aux_accepted_states.resize(n_final_states); //Resize del tamaño del vector auxiliar de aceptados al numero total de estados de aceptación
    for(int i = 0; i < n_final_states; i++) //Bucle para añadir los estados de transicion al conjunto
    {
      file_in >> sentinel;
      aux_accepted_states[i].set_StateName(sentinel);
    }
    sentinel = "";
    file_in >> n_transitions;
    for (int i = 0; i < n_transitions; i++)   //Bucle para asignar las transiciones a los estados
    {
      file_in >> sentinel;
      for (int j = 0; j < aux_states.size(); j++)
      {
        if (aux_states[j].get_StateName() == sentinel)
        {
          transition aux_transition;
          file_in >> transition_symbol;
          aux_transition.set_Symbol(transition_symbol);
          file_in >> sentinel;
          for (int k = 0; k < aux_states.size(); k++)
            if (sentinel == aux_states[k].get_StateName())
              aux_transition.set_NextState(aux_states[k].get_StateID());
          aux_states[j].set_Trans(aux_transition);
          break;
        }
      }
    }
    for (int i = 0; i < aux_states.size(); i++)   //Bucle para rellenar datos de estados de aceptacion copiando el original, antes solo los creamos y asignamos nombre
        for (int j = 0; j < aux_accepted_states.size(); j++)
          if (aux_states[i].get_StateName() == aux_accepted_states[j].get_StateName())
          {
            aux_accepted_states[j] = aux_states[i];
            break;
          }
      for (int i = 0; i < aux_states.size(); i++)   //Bucle para buscar y copiar el estado inicial del original
        if (aux_states[i].get_StateName() == initial_state_.get_StateName())
        {
          initial_state_ = aux_states[i];
          break;
        }
      for (int i = 0; i < aux_accepted_states.size(); i++)  //Introducimos desde el vector auxiliar de aceptados los estados al conjunto de estados de acpetacion del atributo privado
        acepted_states.insert(aux_accepted_states[i]);
      for(int i = 0; i < aux_states.size(); i++)    //Introducimos desde el vector auxiliar de estados los estados al conjunto de estados del atributo privado
        states_.insert(aux_states[i]);
  }
}

void DFA::WriteFileDFA(ofstream& out_file)
{
  out_file << "/* Universidad de La Laguna \n\tGrado en Ingenieria Informatica\n\tComputabilidad y Algoritmia\n\n" << "\tFichero DOT de representacion de un DFA\n\tLenguaje reconocido: Cadenas binarias que representan numeros enteros divisibles por 3 sin ceros por la izquierda\n\tER: 0|(1(01*0)*10*)+\n*/\n" << "digraph DFA { \n rankdir=LR;\n size = \" 10, 4\";\n d2tstyleonly = true;" << endl << " node [shape = none];" << "\" \";\n node[shape = circle];" << endl << " node [ shape =doublecircle] ; ";
  for (state est : acepted_states)    //for de c++11
    out_file << "\"" << est.get_StateName() << "\" ";
  out_file << ';' << endl;
  out_file << "\" \" -> \"" << initial_state_.get_StateName() << '\"';
  for(state est:states_)    //for de c++11
  {   
    set<transition> trans_=est.get_Trans();
    for(transition transit_: trans_)  //for de c++11
      for(state sta: get_States())  //for de c++11
        if (transit_.get_NextState()==sta.get_StateID())
          out_file << "\n\""<<est.get_StateName()<<"\" -> \"" << sta.get_StateName() << "\" [ label=\" " << transit_.get_Symbol()<<"\" ];";
  }
  out_file << endl << " }" << endl;
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


