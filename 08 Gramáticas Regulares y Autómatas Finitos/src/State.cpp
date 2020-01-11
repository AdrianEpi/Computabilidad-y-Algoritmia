/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         state.cpp                                                    =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         10/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     state class.
 *  \details   This class is used for saving the state data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.4
 *  \date      10/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------   FUNCTIONS DECLARATIONS   ----------*/
#include "../class/State.hpp"
/*------------------------------------------------*/
/**
 * @brief Constructor por defecto
 */
State::State () :
transition_num_(0),
ID_(),
transitions_(),
name_()
{}

/**
 * @brief Constructor parametrizado con un objeto de referencia
 * @param aux Contiene el estado con el que se desea inicializar el nuevo objeto
 */
State::State (const State& aux) :
transition_num_(0),
ID_(),
transitions_(),
name_()
{
  transition_num_ = aux.get_Transition_Num();
  ID_ = aux.get_ID();
  transitions_ = aux.get_Transitions();
  name_= aux.get_Name();
}

/**
 * @brief Destructor por defecto
 */
State::~State () {}

/**
 * @return Atributo número de transiciones
 */
unsigned int State::get_Transition_Num (void) const {
  return transition_num_;
}

/**
 * @brief Establece el atributo numero de transiciones
 */
void State::set_Transition_Num (unsigned int n_transitions) {
  transition_num_ = n_transitions;
}
  
/**
 * @return Atributo identificador
 */
unsigned int State::get_ID (void) const {
  return ID_;
}

/**
 * @brief Establece el atributo identificador
 */ 
void State::set_ID (unsigned int identi) { 
  ID_ = identi;
}

/**
 * @return Atributo conjunto de transiciones
 */
set <Transition> State::get_Transitions (void) const {
  return transitions_;
}

/**
 * @return Atributo nombre (nombre del estado)
 */
string State::get_Name (void) const {
  return name_;
}

/**
 * @brief Establece el atributo nombre (nombre del estado)
 */
void State::set_Name (string name) {
  name_ = name;
}

/**
 * @brief Establece todas las tranciones y se establece tambien el numero que son
 * @param n_transition Contiene el numero de transiciones totales
 * @param transitions Contiene todas las transiciones posibles
 */
void State::set_All_Transitions (unsigned int n_transition, set <Transition>& transitions) {
  transition_num_ = n_transition;
  transitions_ = transitions;
}

/**
 * @brief Establece el atributo transicion
 */
void State::set_Transition(Transition aux) {
  transitions_.insert(aux);
  transition_num_++;
}

/**
 * @brief Saturacion del operador =
 * @note Útil para igualar dos objetos
 */
State& State::operator = (const State& state2) {

  transition_num_ = state2.get_Transition_Num();
  ID_ = state2.get_ID();
  transitions_ = state2.get_Transitions();
  name_ = state2.get_Name();
  return *this;
}

/**
 * @brief Saturacion del operador !=
 * @note Necesario para la creación de conjuntos
 */
bool State::operator != (const State& state2) const {

  if (ID_ == state2.get_ID()  && transition_num_ == state2.get_Transition_Num() && transitions_.size() == state2.get_Transitions().size())
    if (transitions_ == state2.get_Transitions())
      return false;
    else
      return true;
  else
    return true;
}

/**
 * @brief Saturacion del operador ==
 * @note Necesario para la creación de conjuntos
 */
bool State::operator == (const State& state2) const {

  if (ID_ == state2.get_ID() && transition_num_ == state2.get_Transition_Num() && transitions_.size() == state2.get_Transitions().size())
    if (transitions_ == state2.get_Transitions())
      return true;
    else
      return false;
  else
    return false;
}

/**
 * @brief Saturacion del operador <
 * @note Necesario para la creación de conjuntos
 */
bool State::operator < (const State& state2) const {

  if (ID_ < state2.get_ID())
    return true;
  else
    return false;
}

/**
 * @brief  Se encarga de mostrar el numero de transiciones del objeto estado, su identificador y el conjunto de trancisiones
 */
void State::Write (void) const {
 
  cout << "Identificador: " << name_ << "\n";
  cout << "Identificador numerico: "<< ID_ << "\n";
  cout << "Numero de transiciones: " << transition_num_ << "\n";
  set <Transition>::iterator it = transitions_.begin();
  for (; it !=  transitions_.end(); it++) {
    cout << " ";
    it -> Write();
  }   
}