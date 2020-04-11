#include <sstream>
#include "../Sections/Games.hpp"
#include "../Sections/Toys.hpp"
#include "../Sections/Books.hpp"
#include "../Sections/Garden.hpp"

class AddRecords{
public:
	void menuforregulations(){
		int SectionNumber;
		cout << "1. Games" << endl;
		cout << "2. Toys" << endl;
		cout << "3. Books" << endl;
		cout << "4. Garden" << endl;
		cin >> SectionNumber;			// This part needs to validation. The number must be under 5
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

		}else if ( SectionNumber == 4 ){

		}
	}
};
