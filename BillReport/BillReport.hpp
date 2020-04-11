#include "../Sections/Postgres/PostgresConnection.hpp"

class BillReport {
public:
	void menuforsection(){
		int choice;
		cout << "1. games" << endl;
	        cout << "2. toys" << endl;
       		cout << "3. garden" << endl;
 		cout << "4. books" << endl;
		cout << "5. Total" << endl;
		cin >> choice;			// This area needs validation control.
		show(choice);		
	}
	void show( int choice ){
		PostgresConnection record;
		if ( choice == 1 ){
			cout << record.getShow("games") << endl;
		}else if( choice == 2 ){
			cout << record.getShow("toys") << endl;
		}else if (choice == 3 ){
			cout << record.getShow("garden") << endl;
		}else if (choice == 4 ){
			cout << record.getShow("books") << endl;
		}else if( choice ==  5 ){
		std::string listofSection [4] = {"games", "toys", "garden", "books"};
 		float net = 0.00;
	 	for( int i = 0; i < 3; i++ ){
			net += record.getShow(listofSection[i]);
	      	}
    		cout << net << endl;
  		}
	}		
};
