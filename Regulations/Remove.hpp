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
		cout << "Sections list:" << endl;
		cout << "1. Games" << endl;
		cout << "2. Toys" << endl;
		cout << "3. Books" << endl;
		cout << "4. Garden" << endl;
		int SectionNumber;
		cin >> SectionNumber;
		MenuForRemove();
	}
private:	
	void MenuForRemove{
		cout << "You need to select one way for delete a record:" << endl;
		cout << "1. Delete with ID number." << endl;
		cout << "2. Delete with the Name of record." << endl;
		int MethodSelection;
		cin >> MethodSelection;
		ForwardtoSection(SectionNumber,MethodSelection);
	}

	void ForwardtoSections( int SectionNumber, int MethodSelection ){
		if ( SectionNumber == 1 ){
			Games games;
			if ( MethodSelection == 1 ){
				games.RemoveWithID();	
			}else if ( MethodSelection == 2 ){
				games.RemoveWithName();
			}else{
				werr << "You didn't input in menu. So the program will close." << endl;
				exit(1);
			}
		}else if ( SectionNumber == 2 ){
			Toys toys;
			if ( MethodSelection == 1 ){
				toys.RemoveWithID();
			}else if ( MethodSelection == 2 ){
				toys.RemoveWithName()
			}else{
				werr << "You didn't input in menu. So the program will close." << endl;
				exit(1);
			}
		}else if ( SectionNumber == 3 ){
			Books books;
			if ( MethodSelection == 1 ){
				books.RemoveWithID();
			}else if ( MethodSelection == 2 ){
				books.RemoveWithName()
			}else{
				werr << "You didn't input in menu. So the program will close." << endl;
				exit(1);
			}
		}else if ( SectionNumber == 4 ){
			Garden garden;
			if ( MethodSelection == 1 ){
				garden.RemoveWithID();	
			}else if ( MethodSelection == 2 ){
				garden.RemoveWithName();
			}else{
				werr << "You didn't input in menu. So the program will close." << endl;
				exit(1);
			}
		}else{
			werr << "You didn't give acceptable input" << endl;
		}
	}
};	
