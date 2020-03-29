#include <pqxx/pqxx> 

using namespace pqxx;

class GameTableInstall {
public:
  int GamesTableInstallation(){
    std::string sql;
    try {
      sql = "CREATE TABLE Games("			\
	"ID SERIAL PRIMARY KEY     NOT NULL,"		\
	"PRODUCTNAME           CHAR(50)    NOT NULL,"	\
	"BRANDNAME        CHAR(50)    NOT NULL,"		\
	"PRICE        INT     NOT NULL"			\
	"PRODUCTYEAR            INT     NOT NULL);";
      connection C("dbname = market user = postgres password = TEST hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
	work W(C);
	W.exec( sql );
	W.commit();
	std::cout << "Records created successfully" << std::endl;
	C.disconnect ();
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      return 1;
    }
    return 0;
  }
};
