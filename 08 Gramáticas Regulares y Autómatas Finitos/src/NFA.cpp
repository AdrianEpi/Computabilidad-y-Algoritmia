/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         NFA.cpp                                                      =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         10/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     NFA class.
 *  \details   This class is used for saving the NFA data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.4
 *  \date      10/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------   FUNCTIONS DECLARATIONS   ----------*/
#include "../class/NFA.hpp"
/*------------------------------------------------*/

/**
 * @brief Constructor por defecto
 */
NFA::NFA () :
alphabet_(),
states_(),
initial_(),
acept_(), 
states_num_()
{}

/**
 * @brief Constructor parametrizado con un objeto de referencia
 * @param aux Nfa pasado por refencia
 */
NFA::NFA (NFA& aux) :
alphabet_(),
states_(),
initial_(),
acept_(), 
states_num_()
{
  alphabet_ = aux.alphabet_;
  states_ = aux.states_;
  initial_ = aux.initial_;
  acept_ = aux.acept_;
  states_num_ = aux.states_num_;
}

/**
 * @brief Costruye el NFA a traves del nombre de un fichero de entrada
 * @param in_file 
 */
NFA::NFA (string& in_file):
alphabet_(),
states_(),
initial_(),
acept_(), 
states_num_()
{
  Generate_NFA(in_file);
}

/**
 * @brief Destructor por defecto
 */
NFA::~NFA () {}

/**
 * @brief Crea el nfa
 * @param in_file 
 */
void NFA::Generate_NFA (string& in_file) {

  ifstream ifs (in_file, ios::in);

  if (ifs.fail()) {
    cout << "Error el documento que trata de abrir no es valido, por favor introuduzca uno que si lo sea y reintentelo." << "\n\n";
    exit(2);
  } else {
  string aux_string;

    do {
      getline(ifs, aux_string);
    } while (aux_string[0] == '/' && aux_string[1] == '/');

    int n_symbol = stoi(aux_string);
    aux_string = "";
    string aux_chain;

    for (int i = 0; i < n_symbol + 1; i++) {
      ifs >> aux_string;
      aux_chain += aux_string;
    }
    if (aux_chain[0]!= '~') {
      cout << "El caracter ~, no se encuentra en primer lugar, por favor corrijalo. " << "\n\n";
      exit(2);
    }
    alphabet_.Create(aux_chain);

    int n_states;
    ifs >> n_states;
    aux_string = "";
    vector <State> aux_states;
    aux_states.resize(n_states);

    for (int i = 0; i < n_states; i++) {
      ifs >> aux_string;
      aux_states[i].set_Name(aux_string);
      aux_states[i].set_ID(i);
    }

    aux_string = "";
    ifs >> aux_string;
    for (int i = 0; i < aux_states.size(); i++)
      if (aux_states[i].get_Name() == aux_string)
        initial_ = aux_states[i];
    if (initial_.get_Name() == "") {
      cout << "El estado inicial que ha seleccionado no existe, por favor corrijalo. " << "\n\n";
      exit(2);
    }

    int n_final_states;
    ifs >> n_final_states;
    vector <State> aux_final_states;
    aux_final_states.resize(n_final_states);

    for (int i = 0; i < n_final_states; i++) {
      ifs >> aux_string;
      aux_final_states[i].set_Name(aux_string);
    }

    int aux_cont = 0;
    for (int i = 0; i < n_states; i++) 
      for (int j = 0; j < n_final_states; j++) 
        if (aux_states[i].get_Name() == aux_final_states[j].get_Name()) 
          aux_cont++;
    if (aux_cont != n_final_states) {
      cout << "Ha habido algun error con la declaracion de los estados de aceptacion, por favor corrijelo. " << "\n\n";
      exit(2);
    }
        
    int n_transitions;
    aux_string = "";
    char symbol_transition;
    ifs >> n_transitions;
    bool actual_exisist = false;
    bool symbol_exisist = false;
    bool next_exisist = false;

    for (int i = 0; i < n_transitions; i++) {
      ifs >> aux_string;
      for (int j = 0; j < aux_states.size(); j++) 
        if(aux_states[j].get_Name() == aux_string)   // Comprobar si el estado que quiere transitar existe
          actual_exisist = true;
        if (actual_exisist == false) {
          cout << "Uno de los de los estados declarado como inicial no existe, por favor corrijalo. " << "\n\n";
          exit(2);
        }
        actual_exisist = false;

      for (int j = 0; j < aux_states.size(); j++) {
        if (aux_states[j].get_Name() == aux_string) {
          Transition aux_transition;
          ifs >> symbol_transition;

          set <char>::iterator it = alphabet_.get_Alphabet().begin(); 
          for (; it != alphabet_.get_Alphabet().end(); it++) // Comprobar si el symbolo de entrada pertenece al alfabeto
            if (*it == symbol_transition)
              symbol_exisist = true;
          if (symbol_exisist == false) {
            cout << "Uno de los symbolos introducidos como transicion no esta declarado en el alfabeto, por favor corrijalo. " << "\n\n";
            exit(2);
          }
          symbol_exisist = false;
          aux_transition.set_Symbol(symbol_transition);

          ifs >> aux_string;
          for (int k = 0; k < aux_states.size(); k++) 
            if(aux_states[k].get_Name() == aux_string)  // Comprobar si el estado de transición existe
              next_exisist = true;
          if (next_exisist == false) {
            cout << "Uno de los de los estados declarado como transición no existe, por favor corrijalo. " << "\n\n";
            exit(2);
          }
          next_exisist = false;

          for (int k = 0; k < aux_states.size(); k++) {
            if (aux_string == aux_states[k].get_Name())
              aux_transition.set_Next_State(aux_states[k].get_ID());
          }
          aux_states[j].set_Transition(aux_transition);
          break;
        }
      }
    }
    
    aux_string = "";
    ifs >> aux_string;
    if (aux_string != "") {
      cout << "Error por introducir una cantidad invalida de elementos, por favor corrijalo para poder continuar. " << "\n\n";
      exit(2);
    }

    for (int i = 0; i < aux_states.size(); i++)
      for (int j = 0; j < aux_final_states.size(); j++)
        if (aux_states[i].get_Name() == aux_final_states[j].get_Name()) {
          aux_final_states[j] = aux_states[i];
          break;
        }
    for (int i = 0; i < aux_states.size(); i++)
      if (aux_states[i].get_Name() == initial_.get_Name()) {
        initial_ = aux_states[i];
        break;
      }
    for (int i = 0; i < aux_final_states.size(); i++)
      acept_.insert(aux_final_states[i]);

    for(int i = 0; i < aux_states.size(); i++)
      states_.insert(aux_states[i]);
  }
}

/**
 * @brief Se encarga de ejecutar el algorimo de epsilon clausura
 * @param state Contiene el conjunto de estados a los que se les aplica el epsilon clausura
 * @return Conjunto de estados
 */
set <State> NFA::EPSILON_Clausure (set<State>& state) {

  bool not_in = true;
  stack <State> aux_stack;
  for (State est: state)
    aux_stack.push(est);
  set <State> e_clau = state;
  while(!aux_stack.empty()) {
    State aux_state = aux_stack.top();
    aux_stack.pop();
    set <State> aux_states;

    for (Transition est: aux_state.get_Transitions()) 
      if (est.get_Symbol() == '~') 
        for (State est2: states_)
          if (est2.get_ID() == est.get_Next_State())
            aux_states.insert(est2);

    for (State est: aux_states) {
      for (State est2: e_clau) {
        if (est == est2) {
          not_in = false;
        }
      }
      if (not_in == true) {
        e_clau.insert(est);
        aux_stack.push(est);
      }
      not_in = true;
    }
  }
  return e_clau;
}

/**
 * @brief Contiene el algoritmo Move que es muy similar al epsilon clausura
 * @param state Contiene el conjunto de estados a los que se les aplica el epsilon clausura7
 * @param a symbolo de transición actual 
 * @return Conjunto de estados
 */
set <State> NFA::Move (set<State>& state, char a) {

  bool not_in = true;
  stack <State> aux_stack;
  for (State est: state)
    aux_stack.push(est);
  set <State> e_clau = state;
  while(!aux_stack.empty()) {
    State aux_state = aux_stack.top();
    aux_stack.pop();
    set <State> aux_states;

    for (Transition est: aux_state.get_Transitions()) 
      if (est.get_Symbol() == a) 
        for (State est2: states_)
          if (est2.get_ID() == est.get_Next_State())
            aux_states.insert(est2);

    for (State est: aux_states) {
      for (State est2: e_clau) {
        if (est == est2) {
          not_in = false;
        }
      }
      if (not_in == true) {
        e_clau.insert(est);
        aux_stack.push(est);
      }
      not_in = true;
    }
  }
  return e_clau;
}

/**
 * @brief Algoritmo de construccion de subconjuntos
 * @return DFA a partir del NFA
 */
DFA NFA::Build_DFA (void) {

  DFA aux_DFA;
  set <State> Mark_list;
  set <State> tranDFA;
  set <State> s0;
  s0.insert(initial_);
  set <State> q0 = EPSILON_Clausure(s0);
  Unmark(q0);
  set <State> DFA_states = q0;

  for (State t: DFA_states) {
    while (Is_In(t, DFA_states) && !Mark(t, Mark_list)) {
      Mark_list.insert(t);
      for (char a: alphabet_.get_Alphabet()) {
        set <State> aux_t;
        aux_t.insert(t);
        set <State> Move1 = Move(aux_t,a);
        set <State> h = EPSILON_Clausure(Move1);
        aux_t.clear();
        bool all_in = true;
        for (State est: h){
          if (!Is_In(est,DFA_states)) {
            all_in = false;
            break;
          }
        }
        if (all_in == false) {
          Unmark(h);
          for (State est: h)
            DFA_states.insert(est);
        }
      set <State> aux_trandfa = Move(h, a);
      aux_trandfa = EPSILON_Clausure(aux_trandfa);
      for (State est: aux_trandfa)
        tranDFA.insert(est);
      }
    }
  }
}

/**
 * @brief Metodo que se encarga de desmarcar los nodos posibles
 * @param aux Contiene el conjunto que queremos desmarcar
 */
void NFA::Unmark (set<State>& aux) {

  set <State> reverse_states;
  bool equal = false;

  for (State est: states_) {
    for (State est2: aux) 
      if (est == est2) 
        equal = true;
    if (equal == false)
      reverse_states.insert(est);
    equal = false;
  }
  aux.clear();
  aux = reverse_states;
}

/**
 * @brief Metodo que se encarga de ver si un conjunto de estados esta dentro de DFA States 
 * @param aux Estado para buscar dentro del conjunto
 * @param aux_set Conjunto en donde se va a buscar si el estdo esta dentro
 * @return Verdadero si esta dentro del conjunto de estados del DFA
 */
bool NFA::Is_In (State aux, set<State> aux_set) const {

  for(State est: aux_set)
    if (aux == est)
      return true;
  return false;
}

/**
 * @brief Metodo que se encarga de ver si un estado está dentro del conjunto de marcados
 * @param aux Estado para buscar dentro del conjunto
 * @param aux_set Conjunto en donde se va a buscar si el estdo esta dentro
 * @return Verdadero si esta dentro del conjunto de estados del DFA
 */
bool NFA::Mark (State aux, set<State> aux_set) const {

  for (State est: aux_set) 
    if(aux == est)
      return true;
  return false;
}

/**
 * @brief Metodo que se encarga de imprimir el NFA
 */
void NFA::Write_NFA (void) const {

  cout << "Numero de estados: " << states_.size() << "\n\n";
  cout << "Alfabeto: ";
  alphabet_.Write();
  cout << "\n";
  cout << "Estado inicial: ";
  initial_.Write();
  cout << "\n";
  cout << "Conjunto de estados finales: " << "\n";
  set <State>::iterator it = acept_.begin();
  for (; it != acept_.end(); it++)
    it->Write();
  cout << "\n";
  cout << "Conjunto de estados: " << "\n";
  it = states_.begin();
  for (; it != states_.end(); it++) {
    it->Write();
  cout << "\n";
  }
}

/**
 * @brief Metodo que se encarga de transformar el DFA en su propio fichero de salida
 * @param dfa DFA donde estan contenidos los datos que seran imprimidos en el fichero
 * @param file_out Fichero donde se imprimira la salida del DFA
 */
void NFA::WriteDFA (DFA dfa, string& file_out) {
  
  ofstream ofs (file_out, ios::in);

  if (ofs.fail()) {
    cout << "Error el documento que trata de usar para guardar no es valido, porfavor introduzca uno que si lo sea y reintentelo."
         << "\n\n";
    exit(2);
  } else {

    string aux_string;

    ofs << dfa.get_Alphabet().get_Alphabet().size() << "\n";
    for (char est: dfa.get_Alphabet().get_Alphabet()) {
      ofs << est << "\n";
    }

    ofs << dfa.get_States().size() << "\n";
    for (State est: dfa.get_States()) {
      ofs << est.get_Name() << "\n";
    }

    ofs << dfa.get_Initial_State().get_Name() << "\n";
    ofs << dfa.get_Acepted_States().size() << "\n";
    for (State est: dfa.get_Acepted_States()) {
      ofs << est.get_Name() << "\n";
    }

    int n_transition = 0;
    for (State est: dfa.get_States())
      for (Transition est2: est.get_Transitions())
        n_transition++;

    for (State est: dfa.get_States()) {
      ofs << est.get_Name();
      for (Transition est2: est.get_Transitions()) {
        ofs << est2.get_Symbol();
        for (State est3: dfa.get_States()) 
          if (est3.get_ID() == est2.get_Next_State())
            ofs << est3.get_Name();
      }
      ofs << "\n";
    }
  }
}

/**
 * @brief Metodo para obtener el atributo alfabeto
 * @return Devuelve el atributo alphabet_
 */
Alphabet NFA::get_Alphabet (void) const {
  return alphabet_;
}

/**
 * @brief  Establece el conjunto de symbolos del alfabeto
 * @param alphabet Contiene el conjunto de los symbolos del alfabeto
 */
void NFA::set_Alphabet (const Alphabet& alphabet) {
  alphabet_ = alphabet;
}

/**
 * @brief Metodo para obtener el atributo estados
 * @return Devuelve el atributo states_
 */
set <State> NFA::get_States (void) const {
  return states_;
}

/**
 * @brief Establece el conjunto de todos los estados
 * @param states Contiene el conjunto de todos los estados
 */
void NFA::set_States (const set <State>& states) {
  states_ = states;
}

/**
 * @brief Metodo para obtener el atributo estado inicial
 * @return Devuelve el atributo initial_
 */
State NFA::get_Initial (void) const {
  return initial_;
}

/**
 * @brief  Establece el estado inicial
 * @param initial Contiene el estado inicial a establecer
 */
void NFA::set_Initial (const State& initial) {
  initial_ = initial;
}

/**
 * @brief Metodo para obtener el atributo estados de aceptacion
 * @return Devuelve el atributo acept_
 */
set <State> NFA::get_Acepted (void) const {
  return acept_;
}

/**
 * @brief  Establece los estados de aceptacion
 * @param acept Contiene el conjunto de estados de aceptacion
 */
void NFA::set_acept (const set <State>& acept) {
  acept_ = acept;
}

/**
 * @brief Metodo para obtener el atributo numero de estados
 * @return Devuelve el atributo states_num_
 */
unsigned int NFA::get_States_Num (void) const {
  return states_num_;
}

/**
 * @brief Esta se encarga de imprimir en el fichero de salida en el formato requerido para que sea reconocible por el otro programa 
 * @param out_file Fichero de salida donde se escribira el NFA 
 */
void NFA::Create_NFA_file (string& out_file) const {

  ofstream os (out_file, ios::out);

  if (os.fail()) {
    cout << "Error el documento que trata de usar para guardar no es valido, por favor introduzca uno que si lo sea."
         << "\n\n";
    exit(2);
  } else {

  os << alphabet_.get_Alphabet().size() + 1 << "\n";
  os << '~' << "\n";
  for (char c: alphabet_.get_Alphabet())
	  os << c << "\n";
  os << states_.size() << "\n";
  for (State s: states_)
	  os << s.get_Name() << "\n";
  os << initial_.get_Name() << "\n";
  os << acept_.size() << "\n";
  for (State f: acept_)
    os << f.get_Name() << "\n";
  int n_transitions = 0;
  for (State est: states_)
    for (Transition est2: est.get_Transitions())
      n_transitions++;
  os << n_transitions << "\n";
  for (State est: states_)
    for (Transition t: est.get_Transitions()) {
      os << est.get_Name() << " " << t.get_Symbol() << " ";
        for (State est2: states_)
          if (est2.get_ID() == t.get_Next_State())
            os << est2.get_Name() << "\n";
    }
  }
}