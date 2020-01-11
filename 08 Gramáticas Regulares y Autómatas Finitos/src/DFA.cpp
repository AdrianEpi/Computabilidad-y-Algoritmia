/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         DFA.cpp                                                      =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         10/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     DFA class.
 *  \details   This class is used for saving the DFA data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.4
 *  \date      10/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------   FUNCTIONS DECLARATIONS   ----------*/
#include "../class/DFA.hpp"
/*------------------------------------------------*/
/**
 * @brief Constructor por defecto
 */
DFA::DFA() : alpha_(),
states_(),
states_num_(0),
acepted_states_(),
initial_state_(),
in_file_()
{}

/**
 * @brief Constructor parametrizado con un objeto de referencia
 * @param aux Contiene el estado con el que se DFA inicializar el nuevo objeto
 */
DFA::DFA (const DFA& aux) : alpha_(),
states_(),
states_num_(0),
acepted_states_(),
initial_state_(),
in_file_()
{
  alpha_ = aux.get_Alphabet();
  states_ = aux.get_States();
  states_num_ = aux.get_States_Num();
  acepted_states_ = aux.get_Acepted_States();
  initial_state_ = aux.get_Initial_State();
}

/**
 * @brief Destructor por defecto
 */
DFA::~DFA() {}

/**
 * @return Atributo alfabeto
 */
Alphabet DFA::get_Alphabet (void) const {
  return alpha_;
}

/**
 * @brief Funcion que se encarga de construir el DFA y se escribe en el fichero de salida
 * @param out_file Fichero en donde se escribira el DFA
 */
void DFA::set_DFA (string& out_file) {
  Read_File();
  drawDFA(out_file);
}

/**
 * @brief Funcion no empleada en esta practica
*/
void DFA::set_Alphabet (void) {
  string reconize = "/*";
  alpha_.Create(reconize);
}

/**
 * @return Atributo del conjunto de estados
 */
set <State> DFA::get_States (void) const {
  return states_;
}

/**
 * @brief Establece el atributo de estados
 */
void DFA::set_States (set <State>& aux_state) {
  states_ = aux_state;
}

/**
 * @return Atributo del numero de estados
 */
unsigned int DFA ::get_States_Num (void) const {
  return states_num_;
}

/**
 * @brief Establece el atributo numero de estados
 */
void DFA::set_States_Num (unsigned int n_states) {
  states_num_ = n_states;
}

/**
 * @return Atributo del estados de aceptacion
 */
set <State> DFA::get_Acepted_States (void) const {
  return acepted_states_;
}

/**
 * @brief Establece el atributo estados de aceptacion
 */
void DFA::set_Acepted_States (set <State>& acept_state) {
  acepted_states_ = acept_state;
}

/**
 * @return Atributo del estado inicial
 */
State DFA::get_Initial_State (void) const {
  return initial_state_;
}

/**
 * @brief Establece el atributo estado inicial
 */
void DFA::set_Initial_State (State initial_state) {
  initial_state_ = initial_state;
}

/**
 * @return Atributo del estado inicial
 */
string DFA::get_in_file (void) const {
  return in_file_;
}

/**
 * @brief Establece el atributo fichero de entrada que es el nombre del mismo
 */
void DFA::set_In_File (string& text) {
  in_file_ = text;
}

/**
 * @brief Se encarga de imprimir el conjunto de estados y toda la información a cerca de los mismos
 */
void DFA::Write_DFA (void) const {

  cout << "Numero de estados: " << states_num_ << "\n";
  cout << "Alfabeto: ";
  alpha_.Write();
  cout << "Estado inicial: ";
  initial_state_.Write();
  cout << endl;
  cout << "Conjunto de estados: " << "\n";

  set <State>::iterator it = states_.begin();
  for (; it != states_.end(); it++)
    it->Write();

  it = acepted_states_.begin();
  for (; it != acepted_states_.end(); it++)
    it->Write();
  cout << "\n\n";
}


/**
 * @brief Esta se encarga de tomar los datos del fichero de entrada y guardarlos en el atributo del objeto para posteriormente utilizarlos 
 */
void DFA::Read_File (void){

  ifstream file_in (in_file_, ios::in);

  if (file_in.fail()) {
    cout << "Error el documento que trata de abrir no es valido, porfavor introduzca uno que si lo sea y reintentelo."
         << "\n\n";
    exit(2);
  }
  else{

    string aux_string;

    do {
      getline(file_in, aux_string);
    } while (aux_string[0] == '/' && aux_string[1] == '/');

    int n_symbol = stoi(aux_string);
    aux_string = "";
    string aux_chain;

    for (int i = 0; i < n_symbol; i++) {
      file_in >> aux_string;
      aux_chain += aux_string;
    }
    alpha_.Create(aux_chain);

    int n_states;
    file_in >> n_states;
    aux_string = "";
    vector<State> aux_states;
    aux_states.resize(n_states);

    for (int i = 0; i < n_states; i++) {
      file_in >> aux_string;
      aux_states[i].set_Name(aux_string);
      aux_states[i].set_ID(i);
    }

    aux_string = "";
    file_in >> aux_string;
    for (int i = 0; i < aux_states.size(); i++)
      if (aux_states[i].get_Name() == aux_string)
        initial_state_ = aux_states[i];

    int n_final_states;
    file_in >> n_final_states;
    vector<State> aux_final_states;
    aux_final_states.resize(n_final_states);

    for (int i = 0; i < n_final_states; i++) {
      file_in >> aux_string;
      aux_final_states[i].set_Name(aux_string);
    }

    int n_transitions;
    aux_string = "";
    char symbol_transition;
    file_in >> n_transitions;

    for (int i = 0; i < n_transitions; i++) {
      file_in >> aux_string;
      for (int j = 0; j < aux_states.size(); j++) {
        if (aux_states[j].get_Name() == aux_string) {
          Transition aux_transition;
          file_in >> symbol_transition;
          aux_transition.set_Symbol(symbol_transition);
          file_in >> aux_string;
          for (int k = 0; k < aux_states.size(); k++) {
            if (aux_string == aux_states[k].get_Name())
              aux_transition.set_Next_State(aux_states[k].get_ID());
          }
          aux_states[j].set_Transition(aux_transition);
          break;
        }
      }
    }

    for (int i = 0; i < aux_states.size(); i++)
      for (int j = 0; j < aux_final_states.size(); j++)
        if (aux_states[i].get_Name() == aux_final_states[j].get_Name()) {
          aux_final_states[j] = aux_states[i];
          break;
        }
    for (int i = 0; i < aux_states.size(); i++)
      if (aux_states[i].get_Name() == initial_state_.get_Name()) {
        initial_state_ = aux_states[i];
        break;
      }
    for (int i = 0; i < aux_final_states.size(); i++)
      acepted_states_.insert(aux_final_states[i]);

    for(int i = 0; i < aux_states.size(); i++)
      states_.insert(aux_states[i]);
  }
}

/**
 * @brief Esta se encarga de imprimir en el fichero de salida en el formato requerido para que sea reconocible por el otro programa 
 * @param out_file Fichero de salida donde se escribira el DFA 
 */
void DFA::drawDFA(string& out_file_name) {

  ofstream out_file(out_file_name, ios::in);

  if (out_file.fail()) {
    cout << "Error el documento que trata de usar para guardar no es valido, porfavor introduzca uno que si lo sea."
         << "\n\n";
    exit(2);
  } else {

    out_file << "/* Universidad de La Laguna \n   Grado en Ingenieria Informatica\n   Computabilidad y Algoritmia\n";
    out_file << "   Fichero DOT de representacion de un DFA\n*/\n";
    out_file << "digraph DFA { \n  rankdir=LR;\n  size = \" 10, 4\" ; " << "\n";
    out_file << "  d2tstyleonly = true ;" << "\n";
    out_file << "  node [shape = none]; \" \" ;\n";
    out_file << "  node [ shape = doublecircle] ; ";
    for (State est : acepted_states_)
      out_file << "\"" << est.get_Name() << "\" ";
      out_file << ';' << "\n";
      out_file << "  node[shape = circle] ;" << "\n";
      out_file << "  \" \" -> \"" << initial_state_.get_Name() << '\"';
      for(State est:states_){   
        set <Transition> trans = est.get_Transitions();
        for(Transition transa: trans) {
          for(State sta: get_States())
            if (transa.get_Next_State() == sta.get_ID()) {
              out_file << "\n  \"" << est.get_Name() << "\" -> \"" << sta.get_Name() << "\" [ label=\" "
              << transa.get_Symbol() << "\" ] ;";
            }
        }
      }
      out_file << "\n }" << "\n";
  }
}