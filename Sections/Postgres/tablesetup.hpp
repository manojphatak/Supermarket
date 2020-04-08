#include <pqxx/pqxx>

using namespace pqxx;

class TableInstallForPostgres {
public:
  int TableRecords(){
    std::string sql;
    try {
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
		std::cout << "Games Records created successfully" << std::endl;
		C.disconnect ();
	}
    } catch (const std::exception &e) {
    	std::cerr << e.what() << std::endl;
      	return 1;
    }
    
    try {
      sql = "CREATE TABLE Toys("			\
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
		std::cout << "Toys Records created successfully" << std::endl;
		C.disconnect ();
	}
    } catch (const std::exception &e) {
    	std::cerr << e.what() << std::endl;
      	return 1;
    }

    try {
      sql = "CREATE TABLE Garden("			\
	"ID SERIAL PRIMARY KEY     NOT NULL,"		\
	"PRODUCTNAME           CHAR(50)    NOT NULL,"	\
	"BRANDNAME        CHAR(50)    NOT NULL," 	\
	"SECTION	CHAR(50)	NOT NULL,"	\
	"PRICE        DOUBLE     NOT NULL);";
	connection C("dbname = market user = employee password = test hostaddr = 127.0.0.1 port = 5432");
  	if (C.is_open()) {
		work W(C);
		W.exec( sql );
		W.commit();
		std::cout << "Garden Records created successfully" << std::endl;
		C.disconnect ();
	}
    } catch (const std::exception &e) {
    	std::cerr << e.what() << std::endl;
      	return 1;
    }

    try {
      sql = "CREATE TABLE Books("			\
	"ID SERIAL PRIMARY KEY     NOT NULL,"		\
	"PRODUCTNAME           CHAR(50)    NOT NULL,"	\
	"BRANDNAME        CHAR(50)    NOT NULL,"		\
	"PRICE        DOUBLE     NOT NULL,"			\
	"ISBN	INT(30)	NOT NULL,"		\
	"PRODUCTYEAR            INT     NOT NULL);";
	connection C("dbname = market user = employee password = test hostaddr = 127.0.0.1 port = 5432");
  	if (C.is_open()) {
		work W(C);
		W.exec( sql );
		W.commit();
		std::cout << " Books Records created successfully" << std::endl;
		C.disconnect ();
	}
    } catch (const std::exception &e) {
    	std::cerr << e.what() << std::endl;
      	return 1;
    }
    return 0;
  }

  int ExistTableTest(){	  
	  std::string nameofsection[4] = {"Games","Books","Toys","Garden"};
	  for (int i=0;i>=3;i++){
    try {
	    std::string sql = "SELECT COUNT(*) FROM information_schema.tables WHERE table_name = '" + nameofsection[i]+ "';";			
	connection C("dbname = market user = employee password = test hostaddr = 127.0.0.1 port = 5432");
  	if (C.is_open()) {
		work W(C);
		W.exec( sql );
		W.commit();
		std::cout << nameofsection[i] + " Records created successfully" << std::endl;
		C.disconnect ();
		return 0;
	}
    } catch (const std::exception &e) {
    	std::cerr << e.what() << std::endl;
      	return 1;
    }	
  }
  }
};
