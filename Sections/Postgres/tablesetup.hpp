#include <pqxx/pqxx> 

using namespace pqxx;

class GameTableInstall {
public:
  int GamesTableInstallation(){
    char * sql;
    try {
      sql = "CREATE TABLE Market("			\
	"ID INT PRIMARY KEY     NOT NULL,"		\
	"PRODUCTNAME           CHAR(50)    NOT NULL,"	\
	"ADDRESS        CHAR(50)    NOT NULL,"		\
	"PRICE        INT     NOT NULL"			\
	"PRODUCTYEAR            INT     NOT NULL);";
      
      work W(C);
      
      W.exec( sql );
      W.commit();
      std::cout << "Table created successfully" << endl;
      C.disconnect ();
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      return 1;
    }
    return 0;
  }
};
