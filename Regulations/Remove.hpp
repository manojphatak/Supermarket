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

class RemoveTheRecord{
public:
	void MenuForSelectSection(){
		std::cout << "Sections list:" << std::endl;
		std::cout << "1. Games" << std::endl;
		std::cout << "2. Toys" << std::endl;
		std::cout << "3. Books" << std::endl;
		std::cout << "4. Garden" << std::endl;
		int SectionNumber;
		std::cout << "Section choice: "; 
		std::cin >> SectionNumber;
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
			std::cout << "Get ID number of record" << std::endl;
			std::cin >> IDnumber;
		} while( isdigit(IDnumber) );
		return IDnumber;
	}

	std::string InputForName(){
		std::string Name;
		do{
			std::cout << "Get ID number of record" << std::endl;
			std::cin >> Name;
		} while( isNumber(Name) );
		return Name;
	}

	void MenuForRemove(int SectionNumber){
		std::cout << "You need to select one way for delete a record:" << std::endl;
		std::cout << "1. Delete with ID number." << std::endl;
		std::cout << "2. Delete with the Name of record." << std::endl;
		int MethodSelection;
		do{
			std::cout << "Your method choice: ";
			std::cin >> MethodSelection;
		}while(MethodSelection < 1 | MethodSelection > 2);
		ForwardtoSections(SectionNumber,MethodSelection);
	}

	void ForwardtoSections( int SectionNumber, int MethodSelection ){
		if ( SectionNumber == 1 ){
			Games games;
			if ( MethodSelection == 1 ){
				int ID = InputForID();
				games.RemoveWithID(ID);	
			}else if ( MethodSelection == 2 ){
				std::string name = InputForName();
				games.RemoveWithName(name);
			}else{
				std::wcerr << "You didn't input in menu. So the program will close." << std::endl;
				exit(1);
			}
		}else if ( SectionNumber == 2 ){
			Toys toys;
			if ( MethodSelection == 1 ){
				int ID = InputForID();
				toys.RemoveWithID(ID);
			}else if ( MethodSelection == 2 ){
				std::string name = InputForName();
				toys.RemoveWithName(name);
			}else{
				std::wcerr << "You didn't input in menu. So the program will close." << std::endl;
				exit(1);
			}
		}else if ( SectionNumber == 3 ){
			Books books;
			if ( MethodSelection == 1 ){
				int ID = InputForID();
				books.RemoveWithID(ID);
			}else if ( MethodSelection == 2 ){
				std::string name = InputForName();
				books.RemoveWithName(name);
			}else{
				std::wcerr << "You didn't input in menu. So the program will close." << std::endl;
				exit(1);
			}
		}else if ( SectionNumber == 4 ){
			Garden garden;
			if ( MethodSelection == 1 ){
				int ID = InputForID();
				garden.RemoveWithID(ID);	
			}else if ( MethodSelection == 2 ){
				std::string name = InputForName();
				garden.RemoveWithName(name);
			}else{
				std::wcerr << "You didn't input in menu. So the program will close." << std::endl;
				exit(1);
			}
		}else{
			std::wcerr << "You didn't give acceptable input" << std::endl;
		}
	}
	bool isNumber(std::string s){
    		for (int i = 0; i < s.length(); i++)
        	if (isdigit(s[i]) == false)
            		return false;
	
    	return true;
	}
};	
