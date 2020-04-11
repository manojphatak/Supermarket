#include <pqxx/pqxx>

using namespace std;

class PostgresConnection{
public:

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
  string Show ( string nameofsection ){

      string sql = "SELECT SUM(PRICE) FROM " + nameofsection;
      string::size_type sz;
      try{
	      pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
      	if (C.is_open() ) {
        	std::cout << "Opened database successfully: " << C.dbname() << '\n';
      	}	
	pqxx::nontransaction N(C);
	pqxx::result R( N.exec( sql ));
	for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
		return c[0].as<string>();
	}
    	} catch ( const exception &e ) {
		std::cerr << e.what() <<  std::endl;
		return "FAULT OF DATABASE!!";
      	}
      return "Worked Successfully!!";
  }

public:
  string getShow( string nameofsection ){
	  return Show(nameofsection);
  }
};
