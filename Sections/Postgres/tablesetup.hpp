#include <pqxx/pqxx>

//using namespace pqxx;

class TableInstallForPostgres {
public:
    std::string sql;
	void creategamestable(){
    try {
      sql = "CREATE TABLE games("			\
	"ID SERIAL PRIMARY KEY     NOT NULL,"		\
	"PRODUCTNAME           CHAR(50)    NOT NULL,"	\
	"BRANDNAME        CHAR(50)    NOT NULL,"		\
	"PRICE        MONEY     NOT NULL,"			\
	"PRODUCTYEAR            INT     NOT NULL); " \
	"INSERT INTO games VALUES ('1','TEST','TEST',0.00,2013); ";
      pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
	  if (C.is_open()) {
		  pqxx::work W(C);
		W.exec( sql );
		W.commit();
	}
    } catch (const std::exception &e) {
	    std::cerr << e.what() << std::endl;
	      exit(1);
    }
	}
   void createtoystable(){ 
    try {
      sql = "CREATE TABLE toys("			\
	"ID SERIAL PRIMARY KEY     NOT NULL,"		\
	"PRODUCTNAME           CHAR(50)    NOT NULL,"	\
	"BRANDNAME        CHAR(50)    NOT NULL,"		\
	"PRICE        MONEY     NOT NULL,"			\
	"PRODUCTYEAR            INT     NOT NULL); "	\
	"INSERT INTO toys VALUES ('1','TEST','TEST',0.00,2013); ";
      pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
	  if (C.is_open()) {
		  pqxx::work W(C);
		W.exec( sql );
		W.commit();
	}
    } catch (const std::exception &e) {
	    std::cerr << e.what() << std::endl;
	      exit(1);
    }
  }
    void creategardentable(){
    try {
      sql = "CREATE TABLE garden("			\
	"ID SERIAL PRIMARY KEY     NOT NULL,"		\
	"PRODUCTNAME           CHAR(50)    NOT NULL,"	\
	"BRANDNAME        CHAR(50)    NOT NULL," 	\
	"SECTION	CHAR(50)	NOT NULL,"	\
	"PRICE        MONEY     NOT NULL); "	\
	"INSERT INTO garden VALUES ('1','TEST','TEST','TEST',0.00);";
      pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
	  if (C.is_open()) {
		  pqxx::work W(C);
		W.exec( sql );
		W.commit();
	}
    } catch (const std::exception &e) {
	    std::cerr << e.what() << std::endl;
	      exit(1);
    }
  }
  void createbookstable(){
    try {
      sql = "CREATE TABLE books("			\
	"ID SERIAL PRIMARY KEY     NOT NULL,"		\
	"PRODUCTNAME           CHAR(50)    NOT NULL,"	\
	"BRANDNAME        CHAR(50)    NOT NULL,"		\
	"PRICE        MONEY     NOT NULL,"			\
	"ISBN	CHAR(30)	NOT NULL,"		\
	"PRODUCTYEAR            INT     NOT NULL); "	\
	"INSERT INTO games VALUES ('1','TEST','TEST',0.00,'050423454',2013);";
      pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
	  if (C.is_open()) {
		  pqxx::work W(C);
		W.exec( sql );
		W.commit();
	}
    } catch (const std::exception &e) {
	    std::cerr << e.what() << std::endl;
	      exit(1);
    }
  }

public:
  bool ExistTableTest(){	  
	  std::string nameofsection[4] = {"games","books","toys","garden"};
	  for (int i=0; i<4; i++){
		std::string sql = "SELECT COUNT(*) FROM information_schema.tables WHERE table_name = '" + nameofsection[i]+ "';";
          try{
		  pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
		  pqxx::nontransaction N(C);
		  pqxx::result R( N.exec( sql ));
  	  	for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
  			if ( 0 == c[0].as<int>() ){
				if ( nameofsection[i] == "games"){
					creategamestable();
				}else if(nameofsection[i] == "books"){
					createbookstable();
				}else if(nameofsection[i] == "toys"){
					createtoystable();
				}else if(nameofsection[i] == "garden"){
					creategardentable();
				}else{
					cout << "The Tables created before!" << endl;
					return 1;
				}
			}
  	  	}
      	  } catch ( const exception &e ) {
  		std::cerr << e.what() <<  std::endl;
		  return -1;
	  }
  	  }
	  return 1;
  }
};
