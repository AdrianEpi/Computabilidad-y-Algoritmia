/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 09 Forma normal de Chomsky                          =
    =            File:         DFA.hpp                                                      =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         16/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     DFA class.
 *  \details   This class is used for saving the DFA data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.3
 *  \date      16/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------    LIBRARIES DECLARATION   ----------*/
#include <utility>
#include <iostream>
#include <fstream>
#include <vector>
/*------------------------------------------------*/

/*----------   FUNCTIONS DECLARATIONS   ----------*/
#pragma once
#include "Alphabet.hpp"
#include "State.hpp"
using namespace std;
/*------------------------------------------------*/

class DFA {

  private:
    Alphabet alpha_;
    set <State> states_;
    unsigned int States_num; 
    set <State> acepted_states_;
    State  initial_state_;
    string in_file_;

  public:
    // Constructor and Destructor
    DFA();
    DFA(const DFA&);
    ~DFA();

    // Getters and Setters
    void set_DFA(string&);
    Alphabet get_Alphabet(void) const;
    void set_Alphabet(void);
    set <State> get_States(void) const;
    void set_States(set <State>&);
    unsigned int get_States_Num(void) const;
    void set_States_Num(unsigned int);
    set <State> get_Acepteded_States(void) const;
    void set_Acepteded_States(set <State>&);
    State get_Initial_State(void) const;
    void set_Initial_State(State);
    string get_Input_File(void) const;
    void set_Input_File(string&);

    // Functions
    void DrawDFA(string&);

    // Read and Write   
    void Write_DFA(void) const;
    void Read_File(void);
    
};
