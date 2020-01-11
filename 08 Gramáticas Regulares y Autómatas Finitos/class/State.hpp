/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         state.hpp                                                    =
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
/*----------    LIBRARIES DECLARATION   ----------*/
#pragma once
#include <iostream>
#include <set>
#include <string>
/*------------------------------------------------*/

/*----------   FUNCTIONS DECLARATIONS   ----------*/
#include "Transition.hpp"
/*------------------------------------------------*/
class State {   

  private:

  unsigned int transition_num_;
  unsigned int ID_;
  string name_;
  set <Transition> transitions_;

  public:
    // Constructor and Destructor
    State ();
    State (const State&);
    ~State ();

    // Setters
    void set_Transition_Num (unsigned int);
    void set_ID (unsigned int);
    void set_Name (string);
    void set_All_Transitions (unsigned int, set <Transition>&);
    void set_Transition(Transition);

    // Getters
    unsigned int get_Transition_Num (void) const;
    unsigned int get_ID (void) const;
    string get_Name (void) const;
    set <Transition> get_Transitions (void) const;

    // Operators Overload
    State& operator = (const State&);
    bool operator != (const State&) const;
    bool operator == (const State&) const;
    bool operator < (const State&) const;

    // Read and Write
    void Write (void) const;

};