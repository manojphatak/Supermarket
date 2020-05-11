/*
 * =====================================================================================
 *
 *       Filename:  Add.hpp
 *
 *    Description: Add pages for new records.
 *        Command: g++ main.cpp -std=c++2a -lpqxx -lpq -lpthread -pthread 
 *
 *        Version:  1.0
 *        Created:  2020-04-10 01:35:52 AM
 *       Compiler:  g++
 *
 *         Author:  Safa Bayar (rection), safa@safabayar.tech
 *   Organization:
 *
 * =====================================================================================
 */

#include <sstream>
#include "../Sections/Games.hpp"
#include "../Sections/Toys.hpp"
#include "../Sections/Books.hpp"
#include "../Sections/Garden.hpp"

class AddRecords{
public:
	void menuforregulations(){
		int SectionNumber;
		std::cout << "--------------------------" << std::endl;
		std::cout << "Regualtion Items:" << std::endl;
		std::cout << "1. Games" << std::endl;
		std::cout << "2. Toys" << std::endl;
		std::cout << "3. Books" << std::endl;
		std::cout << "4. Garden" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> SectionNumber;			// This part needs to validation. The number must be under 5
		ForwardtoSections( SectionNumber );
	}
	void ForwardtoSections( int SectionNumber ){
		if ( SectionNumber == 1 ){
			Games games;
			games.add();	
		}else if ( SectionNumber == 2 ){
			Toys toys;
			toys.add();
		}else if ( SectionNumber == 3 ){
			Books books;
			books.add();
		}else if ( SectionNumber == 4 ){
			Garden garden;
			garden.add();
		}
	}
};
