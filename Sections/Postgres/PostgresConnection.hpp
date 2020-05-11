/*
 * =====================================================================================
 *
 *       Filename:  PostgresConnection.hpp
 *
 *    Description: Contain postgresql connections.
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

#include <pqxx/pqxx>

using namespace std;


class PostgresConnection{
private:
  	bool Add ( string sql ){
    	try {
	    	pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
      	if ( C.is_open() ) {
	    	pqxx::work W(C);			// We need to return of C reference
			W.exec( sql );
			W.commit();
			std::cout << "The sql command worked successfully!" << std::endl;
      	}
    	} catch (const  exception &e) {
	    	std::cerr << e.what() <<  std::endl;
      		return 1;
    	}
    	return 0;
  	}

private:
	string ShowRecords(string SectionName, string columname, int ID){
		string sql = "SELECT "+ columname + " FROM " + SectionName + " WHERE id = '" + InttoString(ID) + "';";
    	try{
	   		pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
			pqxx::nontransaction N(C);
			pqxx::result R( N.exec( sql ));
			for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
				if( c[0].as<string>() == "NULL"){
					std::cout << "Hasn't any record.";
					return "0";
				}else{
					return c[0].as<string>();
				}
			}
    		} catch ( const exception &e ) {
				std::cerr << e.what() <<  std::endl;
				return "FAULT OF DATABASE!!";
    		}
    	return "Data not found.";
	}
	string ShowRecords(string SectionName, string columname, string Name){
		string sql = "SELECT "+ columname + " FROM " + SectionName + " WHERE productname = '" + Name + "';";
    	try{
	   		pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
			pqxx::nontransaction N(C);
			pqxx::result R( N.exec( sql ));
			for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
				if( c[0].as<string>() == "NULL"){
					std::cout << "Hasn't any record.";
					return "0";
				}else{
					return c[0].as<string>();
				}
			}
    		} catch ( const exception &e ) {
				std::cerr << e.what() <<  std::endl;
				return "FAULT OF DATABASE!!";
    		}
    	return "Data not found.";
	}

private:
  	string BillReportShow ( string nameofsection ){
	    string sql = "SELECT SUM(PRICE) FROM " + nameofsection + ";";
    	try{
	   		pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
			pqxx::nontransaction N(C);
			pqxx::result R( N.exec( sql ));
			for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
				if( c[0].as<string>() == "NULL"){
					std::cout << "Hasn't any record.";
					return "0";
				}else{
					return c[0].as<string>();
				}
			}
    		} catch ( const exception &e ) {
				std::cerr << e.what() <<  std::endl;
				return "FAULT OF DATABASE!!";
    		}
    	return "Worked Successfully!!";
	}

	string InttoString(int number){
       	        ostringstream temp;
       	        temp << number;
       	        return temp.str();
		}

public:
  	string getShow( string nameofsection ){
		return BillReportShow(nameofsection);
  }

	bool setAdd( string sql ){
		return Add( sql ); 
	}
	
	string getRecordsofSection (string SectionName , string ColumnName, int ID ){
		return ShowRecords( SectionName, ColumnName, ID );
	}

	string getRecordsofSection (string SectionName , string ColumnName ,string productname ){
		return ShowRecords( SectionName, ColumnName, productname );
	}
};
