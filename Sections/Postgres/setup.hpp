class PostgresSetup{
public:
  int PostgresqlSetup(){
    try {
      connection C("dbname = market user = postgres password = TEST hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
	std::cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
	std::cout << "Can't open database" << endl;
	return 1;
      } catch (const std::exception &e) {
	std::cerr << e.what() << std::endl;
	return 1;
      }
      return 0;
    }
  }
};
