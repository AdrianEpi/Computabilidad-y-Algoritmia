/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         grammar.cpp                                                  =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         10/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     grammar class.
 *  \details   This class is used for saving the grammar data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.4
 *  \date      10/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */

/*----------    LIBRARIES DECLARATION   ----------*/
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <string>
/*------------------------------------------------*/

/*----------   FUNCTIONS DECLARATIONS   ----------*/
#include "../class/Grammar.hpp"
/*------------------------------------------------*/
/**
 * @brief Constructor por defecto
 */
Grammar::Grammar () :
V_(),
g_alphabet_(),
S_(),
P_()
{}

/**
 * @brief Constructor parametrizado con un objeto de referencia
 * @param aux Nfa pasado por refencia
 */
Grammar::Grammar (Grammar& aux) :
V_(),
g_alphabet_(),
S_(),
P_()
{
  V_ = aux.V_;
  g_alphabet_ = aux.g_alphabet_;
  S_ = aux.S_;
  P_ = aux.P_;
}

/**
 * @brief Costruye el NFA a traves del nombre de un fichero de entrada
 * @param in_file 
 */
Grammar::Grammar (string& in_file):
V_(),
g_alphabet_(),
S_(),
P_()
{
  //Modificacion(in_file);
  //string in_file2 = "../inputs/ficheroaux.nfa";
  Generate_Grammar(in_file);
}

/**
 * @brief Destructor por defecto
 */
Grammar::~Grammar () {}

/**
 * @brief Metodo que se encarga de convertir la gramatica actual en un NFA
 * @return NFA equivalente al la gramatica que tenemos 
 */
NFA Grammar::ConvertToNFA(void) {

  NFA aux_NFA;
  aux_NFA.set_Alphabet(g_alphabet_);
  vector <State> aux_states_NFA;
  vector <pair <char, Transition>> help_transition;
  State aux_state;
  int cont_iden = 0; 

  for (char est: V_) {   // Aquí se almacenan de manera temporal los estados que tenemos 
    string aux_name;
    aux_state.set_ID(cont_iden);
    aux_name = est;
    aux_state.set_Name(aux_name);
    aux_states_NFA.push_back (aux_state);
    cont_iden++;
  }
  aux_state.set_ID(cont_iden);  // A estos se le añade un estado terminal 
  aux_state.set_Name("f");
  aux_states_NFA.push_back(aux_state); 
  int f_iden = cont_iden;
  cont_iden++;
  int name = 1;
  for (char est: V_) {
    for (pair <char, vector <char> > est2: P_) {
      int next_trans = cont_iden;
      if (est == est2.first) {
        for (int i = 0; i < est2.second.size() - 1; i++)  // Identificar si no se trata de una gramatica lineal por la derecha
          if (est2.second[i] >= 'A' && est2.second[i] <= 'Z') {
            cout << " Error en el fichero, no es regular lineal por la derecha, por tanto no se puede calcular" << "\n\n";
            exit(2); 
          }
        if (est2.second.size() > 2) {    // Se encarga de crear los estados que no existen
          set <Transition> transitions;
          for (int i = 1; i < est2.second.size() - 1; i++) {
            stringstream ss;
            ss << name;
            string aux_name = ss.str();
            aux_state.set_Name(aux_name);
            aux_state.set_ID(cont_iden);
            Transition aux_trans;
            if ( i == est2.second.size() - 2) {
              aux_trans.set_Symbol(est2.second[i]);
              for (State est3: aux_states_NFA)
                if (est2.second[i+1] == est3.get_Name()[0]) 
                  aux_trans.set_Next_State(est3.get_ID());
            } else {
              aux_trans.set_Symbol(est2.second[i-1]);
              aux_trans.set_Next_State(cont_iden + 1);
            }
            transitions.insert(aux_trans);
            aux_state.set_All_Transitions(1, transitions);
            transitions.clear();
            aux_states_NFA.push_back(aux_state);
            cont_iden++;
            name++;
          }
        }
        if (est2.second.size() > 2) { // Para añadirle la transicion al conjunto con el symbolo de fuera
          Transition aux_transition;
          for (State est3: aux_states_NFA) 
            if (est3.get_Name()[0] == est2.first) {
              aux_transition.set_Symbol(est2.second[0]);
              aux_transition.set_Next_State(next_trans);
              pair <char, Transition> put;
              put.first = est2.first;
              put.second.set_Symbol(aux_transition.get_Symbol());
              put.second.set_Next_State(aux_transition.get_Next_State());
              help_transition.push_back(put);
            }
        }
        if (est2.second.size() == 2) {  // En el caso de que los symbolos que formen el conjunto sean dos              
          Transition aux_transition;
          if (est2.second[1] >= 'A' && est2.second[1] <= 'Z') {
            for (State est3: aux_states_NFA)
              if (est3.get_Name()[0] == est2.second[1]) {
                aux_transition.set_Symbol(est2.second[0]);
                aux_transition.set_Next_State(est3.get_ID());
                pair <char, Transition> put;
                put.first = est2.first;
                put.second.set_Symbol(aux_transition.get_Symbol());
                put.second.set_Next_State(aux_transition.get_Next_State());
                help_transition.push_back(put);
              }
          } else {
            aux_transition.set_Symbol(est2.second[0]);
            aux_transition.set_Next_State(f_iden);
            for (State est3: aux_states_NFA) 
              if (est3.get_Name()[0] == est) {
                pair <char, Transition> put;
                put.first = est2.first;
                put.second.set_Symbol(aux_transition.get_Symbol());
                put.second.set_Next_State(aux_transition.get_Next_State());
                help_transition.push_back(put);
              }
          }
        }
        if (est2.second.size() == 1) {       // Si solamente hay un symbolo 
          Transition aux_transition;
          if (est2.second[0] == '~' || est2.second[0] >= 'a' && est2.second[0] <= 'z') { // Si el siguiente symbolo es terminal
            aux_transition.set_Symbol(est2.second[0]);
            aux_transition.set_Next_State(f_iden);
            for(State est3: aux_states_NFA)
              if (est3.get_Name()[0] == est2.first) {
                pair <char, Transition> put;
                put.first = est2.first;
                put.second.set_Symbol(aux_transition.get_Symbol());
                put.second.set_Next_State(aux_transition.get_Next_State());
                help_transition.push_back(put);
              }
          } else if ( est2.second[0] >= 'A' && est2.second[0] <= 'Z') {  // Si el siguiente symbolo es no terminal
            for (State est3: aux_states_NFA)
              if (est3.get_Name()[0] == est2.second[0]) {
                aux_transition.set_Next_State(est3.get_ID());
                aux_transition.set_Symbol(est2.second[0]);
                pair <char, Transition> put;
                put.first = est2.first;
                put.second.set_Symbol(aux_transition.get_Symbol());
                put.second.set_Next_State(aux_transition.get_Next_State());
                help_transition.push_back(put);
              }
          } else {
            cout << " Error en el fichero hay algun caracter que no concuerda con ninguna transicion, por favor corrijalo." << "\n\n";
            exit(2);
          }
        }
      }
    }
  }

  for (int i = 0; i < aux_states_NFA.size(); i++) 
    for (int j = 0; j < help_transition.size(); j++) 
      if (aux_states_NFA[i].get_Name()[0] == help_transition[j].first) 
        aux_states_NFA[i].set_Transition(help_transition[j].second);

  set <State> states;
  State initial;
  State final;
  for (State est: aux_states_NFA) {
    if (est.get_Name()[0] == S_) {
      initial = est;
    }else if (est.get_ID() == f_iden) {
      final = est;
    }
    states.insert(est);
  }
  set <State> finals;
  finals.insert(final);
  aux_NFA.set_States(states);
  aux_NFA.set_Initial(initial);
  aux_NFA.set_acept(finals);
  return aux_NFA;
}

/**
 * @brief Imprime por pantalla los datos de la gramatica regular
 */
void Grammar::Write_Grammar (void) const {
  cout << "Conjunto de symbolos no terminales: ";
  for (char est: V_)
    cout << est;
  cout << "\n";
  cout << "Conjunto de symbolos terminales: ";
  g_alphabet_.Write();
  cout << "symbolo inicial: " << S_ << "\n";
  cout << "Conjunto de reglas: " << "\n";
  for (pair <char, vector <char>> est: P_) {
    cout << est.first << " -> ";
    for (char est2: est.second)
      cout << est2;
    cout << "\n";
  }
  cout << "\n\n";
}

/**
 * @brief Metodo que se encarga de leer de un fichero de entrada y detecta si la gramática es correcta o no y dice sus posibles fallos
 * @param in_file Cadena de caracteres que contiene el nombre del fichero de donde se leera la gramatica
 */
void Grammar::Generate_Grammar (string& in_file) {
  ifstream ifs (in_file, ios::in);
  if (ifs.fail()) {
    cout << "Error el documento que trata de abrir no es valido, por favor introuduzca uno que si lo sea y reintentelo." << "\n\n";
    exit(2);
  } else { 
    string aux_string;
  
    do {
      getline(ifs, aux_string);
    } while ((aux_string[0] == '/' && aux_string[1] == '/'));

    int n_symbol = stoi(aux_string);
    aux_string = "";
    string aux_chain;
    
    for (int i = 0; i < n_symbol; i++) {
      ifs >> aux_string;
      aux_chain += aux_string;
    }

    g_alphabet_.Create(aux_chain);

    int n_states;
    ifs >> n_states;
    aux_string = "";

    for (int i = 0; i < n_states; i++) {
      ifs >> aux_string;
      if (aux_string.size() != 1) {
        cout << " Alguno de los symbolos terminales V es incorrecto por cantidad de caracteres que posee, por favor corrijalo." << "\n\n";
        exit(2);
      }
      V_.insert(aux_string[0]);
    }

    aux_string = "";
    ifs >> aux_string;
    
    if(aux_string.size() != 1) {
      cout << " El symbolo inicial es incorrecto por cantidad de caracteres que posee, por favor corrijalo." << "\n\n";
      exit(2);
    }
    bool check = false;
    for (char est: V_)
      if (est == aux_string[0])
        check = true;
    
    if (check == true) {
      S_ = aux_string[0];
    } //else {
      //cout << " El symbolo inicial no pertenece al conjunto V, porfavor corrijalo." << "\n\n";
      //exit(2);
    //}

    int n_rules;
    ifs >> n_rules;
    char symbol_transition;
    string aux_check;
    check = false;
    for (char est: g_alphabet_.get_Alphabet())
      aux_check += est;
    for (char est: V_)
      aux_check += est;
    aux_string = "";

    for (int i = 0; i < n_rules; i++) {
      ifs >> aux_string; 
      if (aux_string.size() != 1) {
        cout << " El symbolo no terminal es incorrecto por cantidad de caracteres que posee, por favor corrijalo." << "\n\n";
        exit(2);  
      } else {
        symbol_transition = aux_string[0];
      }
      ifs >> aux_string;
      if (aux_string[0] == '-' && aux_string[1] == '>') 
        ifs >> aux_string;
      else {
        cout << " La forma de expresar la transicion no es la correcta, por favor corrijala." << "\n\n";
        exit(2);  
      }
      for (int j = 0; j < aux_string.size(); j++) {
        for (int k = 0; k < aux_check.size(); k++)
          if (aux_string[j] == aux_check[k] || aux_string == "~") {
            check = true;
            break;
          }
        if (check == false) {
          cout << " Alguno de los symbolos que se quieren emplear como transición no pertencen a el conjunto de simolos terminales o no terminales," << "\n";
          cout << " por favor corrijalo" << "\n\n";
        }
        check = false;
      }
    vector <char> aux_vector;
    for(char est: aux_string)
      aux_vector.push_back(est);
    
    pair <char, vector <char> >  aux_pair (symbol_transition, aux_vector);
    P_.insert(aux_pair);
    }

    aux_string = "";
    ifs >> aux_string;
    if (aux_string != "") {
      cout << "Error por introducir una cantidad invalida de elementos, por favor corrijalo para poder continuar. " << "\n\n";
      exit(2);
    }
  }
}

void Grammar::Modificacion(string& in_file)
{
  ifstream ifs;
  char alpha[in_file.size()];
  strcpy(alpha, in_file.c_str());
  ifs.open(alpha);
  
  if (ifs.fail()) {
    cout << "Error el documento que trata de abrir no es valido, por favor introuduzca uno que si lo sea y reintentelo." << "\n\n";
    exit(2);
  }
  ofstream ofs ("../inputs/ficheroaux.nfa");
  char name;
  string aux;
  while (!ifs.eof())
  {
    getline(ifs, aux);
    char sentinel[aux.size()];
    strcpy(sentinel, aux.c_str());
    name = sentinel[0];
    for (int i = 0; i < aux.size(); i++)
    {
      if (aux[i] == '|')
      {
        ofs << endl << name << " -> "; 
        for (int j = i; j < aux.size(); j++)
        {
          if (aux[j] == '|')
            break;
          else
            ofs << aux[j];
        }
      }
    }
  }
  ifs.close();
  ofs.close();
}