/*===================================================================================
=====================================================================================
	=                                                                           =
	=            Proyecto:      Práctica 12 Algoritmos Voraces (Greedy)         =
	=            Archivo:       MoneyChanger.hpp                                =
	=            Autor:         Adrián Epifanio Rodríguez Hernández             =
	=            Fecha:         12/12/2019                                      =
	=            Asignatura:    Computabilidad y Algoritmia                     =
	=            Lenguaje:      C++                                             =
	=            Correo:        alu0101158280@ull.edu.es                        =
	=            Lugar:         Universidad De La Laguna                        =
	=                           Escuela Superior de Ingeniería y Tecnología     =
	=                                                                           =
=====================================================================================
===================================================================================*/
/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <iostream>
#include <vector>
/*------------------------------------------------*/

/*===================================================================
=                         MoneyChanger Class                        =
===================================================================*/

/**
 * @brief      This class describes the money changer.
 */
class MoneyChanger
{
	private:

		int money_;
		std::vector<int> possible_candidates_;
		std::vector<int> result_vector_;
		std::vector<int> ammount_vector_;


	public:
		// Constructors & Destructor
		MoneyChanger(){};
		MoneyChanger( double money );
		~MoneyChanger(){};

		// Getters
		std::vector<int> get_Ammount_Vector( void ) { return ammount_vector_; }
		std::vector<int> get_Result_Vector( void ) { return result_vector_; }
		std::vector<int> get_Possible_Candidates( void ) { return possible_candidates_; }
		
		// Setters
		void set_Ammount_Vector( std::vector<int> a ) { ammount_vector_ = a; }
		void set_Result_Vector( std::vector<int> a ) { result_vector_ = a; }
		void set_Possible_Candidates( std::vector<int> a ) { possible_candidates_ = a; }

		// Functions
		void Write( void );
		double get_Calculated( void );


	private:
		int Candidate_Selector( int &new_money, int &position );
		void Generate_Possible_Candidates();

};
/*=================================================================*/
/*========================= End of Class  =========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio Rodríguez Hernández
 *   Correo: alu0101158280@ull.edu.es
 *   Fecha: 12/12/2019
 *
 *
**/


