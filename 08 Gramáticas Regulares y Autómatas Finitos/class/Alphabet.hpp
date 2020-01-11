/*===============================================================================================
=================================================================================================
    =                                                                                       =
    =            Proyect:      Práctica 08 Gramáticas Regulares y Autómatas Finitos         =
    =            File:         alphabet.hpp                                                 =
    =            Author:       Adrián Epifanio Rodríguez Hernández                          =
    =            Date:         10/11/2019                                                   =
    =            Language:     C++                                                          =
    =            Email:        alu0101158280@ull.edu.es                                     =
    =                                                                                       =
==================================================================================================
================================================================================================*/
/*! 
 *  \brief     alphabet class.
 *  \details   This class is used for saving the alphabet data.
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
using namespace std;
/*------------------------------------------------*/
class Alphabet{

  private:

  set <char> alphabet_;

  public:
    // Constructor and Destructor
    Alphabet ();
    Alphabet (string&);
    Alphabet (const Alphabet&);
    ~Alphabet() {};

    // Getters
    const set<char>& get_Alphabet (void) const;

    // Functions
    void Create (string);
    int size (void) const;
    
    // Read and Write
    void Write (void) const;
    
    
    
  
};