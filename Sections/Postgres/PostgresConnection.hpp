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
	string ShowRecords(string SectionName, string columname){
		string sql = "SELECT "+ columname + " FROM " + SectionName + ";";
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
    	return "Empty data.";
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

public:
  	string getShow( string nameofsection ){
		return BillReportShow(nameofsection);
  }

	bool setAdd( string sql ){
		return Add( sql ); 
	}
	
	string getRecordsofSection (string SectionName , string ColumnName ){
		return ShowRecords( SectionName, ColumnName );
	}
};
