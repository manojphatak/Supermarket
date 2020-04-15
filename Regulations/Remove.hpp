/*
 * =====================================================================================
 *
 *       Filename:  Remove.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020-04-14 07:09:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Safa Bayar (rection), safa@safabayar.tech
 *   Organization:  
 *
 * =====================================================================================
 */

//#include "../Sections/Books.hpp"
//#include "../Sections/Games.hpp"
//#include "../Sections/Garden.hpp"
//#include "../Sections/Toys.hpp"

class RemoveTheRecord{
public:
	void MenuForSelectSection(){
		cout << "Sections list:" << endl;
		cout << "1. Games" << endl;
		cout << "2. Toys" << endl;
		cout << "3. Books" << endl;
		cout << "4. Garden" << endl;
		int SectionNumber;
		cin >> SectionNumber;
//		while (1){
//			if( cin.fail() || ( SectionNumber <= 4 && SectionNumber > 0 )){
//				cin.clear();
//				cin.ignore(numeric_limits<streamsize>::max(),'\n');
//				cout << "You didn't enter number. \n Your choices must be between 0 to 4." << endl;
//				cin >> SectionNumber;
//			}
//		}
		MenuForRemove(SectionNumber);
	}
private:	

	int InputForID(){		//This function necessary for take trust Integer input. 
		int IDnumber;
		do{
			cout << "Get ID number of record" << endl;
			cin >> IDnumber;
		} while( isdigit(IDnumber) );
		return IDnumber;
	}

	string InputForName(){
		string Name;
		do{
			cout << "Get ID number of record" << endl;
			cin >> Name;
		} while( isNumber(Name) );
		return Name;
	}

	void MenuForRemove(int SectionNumber){
		cout << "You need to select one way for delete a record:" << endl;
		cout << "1. Delete with ID number." << endl;
		cout << "2. Delete with the Name of record." << endl;
		int MethodSelection;
		cin >> MethodSelection;
		ForwardtoSections(SectionNumber,MethodSelection);
	}

	void ForwardtoSections( int SectionNumber, int MethodSelection ){
		if ( SectionNumber == 1 ){
			Games games;
			if ( MethodSelection == 1 ){
				int ID = InputForID();
				games.RemoveWithID(ID);	
			}else if ( MethodSelection == 2 ){
				string name = InputForName();
				games.RemoveWithName(name);
			}else{
				wcerr << "You didn't input in menu. So the program will close." << endl;
				exit(1);
			}
		}else if ( SectionNumber == 2 ){
			Toys toys;
			if ( MethodSelection == 1 ){
				int ID = InputForID();
				toys.RemoveWithID(ID);
			}else if ( MethodSelection == 2 ){
				string name = InputForName();
				toys.RemoveWithName(name);
			}else{
				wcerr << "You didn't input in menu. So the program will close." << endl;
				exit(1);
			}
		}else if ( SectionNumber == 3 ){
			Books books;
			if ( MethodSelection == 1 ){
				int ID = InputForID();
				books.RemoveWithID(ID);
			}else if ( MethodSelection == 2 ){
				string name = InputForName();
				books.RemoveWithName(name);
			}else{
				wcerr << "You didn't input in menu. So the program will close." << endl;
				exit(1);
			}
		}else if ( SectionNumber == 4 ){
			Garden garden;
			if ( MethodSelection == 1 ){
				int ID = InputForID();
				garden.RemoveWithID(ID);	
			}else if ( MethodSelection == 2 ){
				string name = InputForName();
				garden.RemoveWithName(name);
			}else{
				std::wcerr << "You didn't input in menu. So the program will close." << endl;
				exit(1);
			}
		}else{
			std::wcerr << "You didn't give acceptable input" << endl;
		}
	}
	bool isNumber(string s){
    		for (int i = 0; i < s.length(); i++)
        	if (isdigit(s[i]) == false)
            		return false;
	
    	return true;
	}
};	
