#include <pqxx/pqxx>

using namespace pqxx;

class PostgresSetup{
public:
  int PostgresqlSetup(){
    try {
      connection C("dbname = market user = employee password = test hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
	std::cout << "Opened database successfully: " << C.dbname() << std::endl;
      } else {
	std::cout << "Can't open database" << std::endl;
	return 1;
      }} catch (const std::exception &e) {
 std::cout << "DATABASE SETUP FAILED!";
  std::cerr << e.what() << std::endl;
	return 1;
      }
      return 0;
  }
};
