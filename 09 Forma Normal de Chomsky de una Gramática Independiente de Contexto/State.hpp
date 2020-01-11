/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 09 Forma normal de Chomsky                          =
    =            File:         State.hpp                                                    =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         16/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     State class.
 *  \details   This class is used for saving the State data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.3
 *  \date      16/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------    LIBRARIES DECLARATION   ----------*/
#include <iostream>
#include <set>
#include <string>
/*------------------------------------------------*/

/*----------   FUNCTIONS DECLARATIONS   ----------*/
#pragma once
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
    State();
    State(const State&);
    ~State();

    // Getters
    unsigned int get_Transitions_Num(void) const;
    void set_Transitions_Num(unsigned int);
    unsigned int get_ID(void) const;
    void set_ID(unsigned int);
    string get_Name(void) const;
    void set_Name(string);
    set <Transition> get_Transitions(void) const;
    void set_all_transitions(unsigned int, set <Transition>&);
    void set_Transition(Transition);

    // Operators Overload
    State& operator =(const State&);
    bool operator !=(const State&) const;
    bool operator ==(const State&) const;
    bool operator <(const State&) const;

    // Read and Write
    void Write(void) const;
};