/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         transition.hpp                                               =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         10/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     transition class.
 *  \details   This class is used for saving the transition data.
 *  \author    Adrián Epifanio Rodríguez Hernández
 *  \version   1.4
 *  \date      10/11/2019 - Actual date
 *  \bug       Not bugs detected.
 *  \warning   Not warnings detected.
 *  \copyright GNU Public License.
 */
/*----------    LIBRARIES DECLARATION   ----------*/
#pragma onc
#include <iostream>
/*------------------------------------------------*/

/*----------   FUNCTIONS DECLARATIONS   ----------*/
using namespace std;
/*------------------------------------------------*/

class Transition {

  private:
    char symbol_;
    unsigned int next_state_; 

  public:
    // Constructor and Destructor
    Transition ();
    Transition (const Transition&);
    Transition (char a, unsigned int);
    ~Transition ();

    // Setters
    void set_Symbol (char);
    void set_Next_State(unsigned int); 
    // Getters
    char get_Symbol (void) const;
    unsigned int get_Next_State (void) const;

    // Operators Overload
    Transition operator = (const Transition);
    bool operator == (const Transition&)const;
    bool operator != (const Transition&) const;
    bool operator < (const Transition&) const;

    // Functions
    void Next_Transition(Transition&);

    // Read and Write
    void Write (void) const;

};
