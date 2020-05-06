#include "../Sections/Postgres/PostgresConnection.hpp"

class BillReport {
public:
	int  menuforsection(){
		int choice;
		cout << "1. games" << endl;
	        cout << "2. toys" << endl;
       		cout << "3. garden" << endl;
 		cout << "4. books" << endl;
		cout << "5. Total" << endl;
		while(choice > 0 && choice <= 5){
			cin >> choice;			// This area needs validation control.
		}
		return choice;		
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
		 double net;			// That will be convert to float for per record.
		 for( int i = 0; i < 4; i++ ){          // This section after the add the other sections.
			string temp = record.getShow(listofSection[i]);
			temp.erase(temp.begin());
			converttofloat(temp);
//			cout << net << endl;
//			net += strtof(temp.c_str(),0);
		      }
		    cout << net << endl;
  		}
	}	
	void converttofloat( string str ){
        float result= 0.0f;
        int len = str.length();
        int dotpos = 0;
        for (int n = 0; n < len; n++) {
        	if (str[n] == '.') {
                dotpos = len - n - 1;
            }
            else {
                result = result * 10 + (str[n]-'0');
            }
        }
        result /= power(10,dotpos);
        cout<<result;
    }
                
    int power(int n,int m){
        if(m==1)
            return n;
        else
            return n*(power(n,m-1));
        }
};
