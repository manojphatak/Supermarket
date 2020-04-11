#include <pqxx/pqxx>
#include "tablesetup.hpp"


class PostgresSetup{
public:
  int PostgresqlSetup(){
	TableInstallForPostgres TableInstall;
	if ( CheckofExistedDatabase() == 1 ){
		TableInstall.ExistTableTest();
		//if ( TableInstall.ExistTableTest() == 0 ){
		//	std::cout << "The Tables existed before." << std::endl;
		//}
	}else{
		std::cout << "The database didn't exist!" << std::endl;
		std::cout << "You have to work this command in psql session:" << std::endl;
		std::cout << "create database supermarket" << std::endl; 
	}
	return 0;
  }

private:
  int CheckofExistedDatabase(){
	  string sql = "SELECT 1 FROM pg_database WHERE datname='supermarket'";
          try{
		  pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
        	if (C.is_open() ) {
          	std::cout << "Opened database successfully: " << C.dbname() << '\n';
        	}	
		pqxx::nontransaction N(C);
		pqxx::result R( N.exec( sql ));
	//for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
		//return c[0].as<int>();
		pqxx::result::const_iterator c = R.begin();
		  return c[0].as<int>();
  	  //}
      	  } catch ( const exception &e ) {
  		std::cerr << e.what() <<  std::endl;
  		return -3;
          }
	  return -2;
  } 
};
