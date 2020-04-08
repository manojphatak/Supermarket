#include <pqxx/pqxx>
#include "tablesetup.hpp"

using namespace pqxx;
using namespace std;

class PostgresSetup{
public:
  int PostgresqlSetup(){
	TableInstallForPostgres TableInstall;
	if ( CheckofExistedDatabase() == 1 ){
		if ( TableInstall.ExistTableTest() == 0 ){
			std::cout << "The Tables existed before." << std::endl;
		}else{
			TableInstall.TableRecords();
		}
	}else{
		std::cout << "The database didn't exist!" << std::endl;
		std::cout << "You have to work this command in psql session:" << std::endl;
		std::cout << "create database Supermarket" << std::endl; 
	}
	return 0;
  }

private:
  bool CheckofExistedDatabase(){
	  string sql = "SELECT 1 FROM pg_database WHERE datname='Supermarket'";
          try{
        	connection C("dbname = market user = employee password = test hostaddr = 127.0.0.1 port = 5432");
        	if (C.is_open() ) {
          	std::cout << "Opened database successfully: " << C.dbname() << '\n';
        	}	
        	nontransaction N(C);
        	result R( N.exec( sql ));
  	  for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
  		return c[0].as<int>();
  	  }
        	C.disconnect ();
      	  } catch ( const exception &e ) {
  		std::cerr << e.what() <<  std::endl;
  		return 0;
          }
	  return 0;
  } 
};
