#include "setup.hpp"
#include "tablesetup.hpp"
#include <pqxx/pqxx>

using namespace pqxx;

class PostgresConnection{
public:
  bool Add(std::string sql){
    try {
      connection C("dbname = market user = employee password = test hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open() && TestofPostgres() == 1) {
	work W(C);			// We need to return of C reference
	W.exec( sql );
	W.commit();
	std::cout << "The sql command worked successfully!" << std::endl;
	C.disconnect ();
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      return 1;
    }
    return 0;
  }

  bool TestofPostgres(){
    PostgresSetup Setup;
    if( Setup.PostgresqlSetup() == 1 ){
      std::cout << "The Database couldn't open.";
      return 0;			// 0 mean false or unsuccesfull.
    }else{
      std::cout << "The Database opened. \nThe table creating...\n";
      // GameTableInstall GameTable;
      // if ( GameTable.GamesTableInstallation() != 1 ){
	// std::cout << "The table created succesfully!";
	// return 1;		// 1 mean true
      // }else{
	return 1;		// 0 mean false
      // }
    }
  }


};
