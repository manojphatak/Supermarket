#include <pqxx/pqxx>

using namespace pqxx;

class GameTableInstall {
public:
  int GamesTableInstallation(){
    std::string sql;
    // std::string testforexisted;
    try {
      // testforexisted = "SELECT EXISTS (" \
      //   "SELECT 1" \
      //   "FROM information_schema.tables" \
      //   "WHERE table_schema = 'public'" \
      //   "AND table_name = 'Games');";

      sql = "CREATE TABLE Games("			\
	"ID SERIAL PRIMARY KEY     NOT NULL,"		\
	"PRODUCTNAME           CHAR(50)    NOT NULL,"	\
	"BRANDNAME        CHAR(50)    NOT NULL,"		\
	"PRICE        DOUBLE     NOT NULL,"			\
	"PRODUCTYEAR            INT     NOT NULL);";
  connection C("dbname = market user = employee password = test hostaddr = 127.0.0.1 port = 5432");
  if (C.is_open()) {
	    work W(C);

	       W.exec( sql );
	       W.commit();
	       std::cout << "Records created successfully" << std::endl;
         C.disconnect ();
}
  // if (C.is_open()) {
	//     work W(C);
  //     std::string zek = W.exec( testforexisted );
  //     if (  zek == 'NULL' ){
  //       std::cout << "the games table existed!";
  //       C.disconnect ();
  //     }else{
	//        W.exec( sql );
	//        W.commit();
	//        std::cout << "Records created successfully" << std::endl;
  //        C.disconnect ();
  //      }

    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      return 1;
    }
    return 0;
  }
};
