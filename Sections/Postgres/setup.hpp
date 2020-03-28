class PostgresSetup{
  void PostgresqlSetup(){
    char * sql;
    
    try {
      connection C("dbname = market user = postgres password = TEST hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
	cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
	cout << "Can't open database" << endl;
	return 1;
      } catch (const std::exception &e) {
	cerr << e.what() << std::endl;
	return 1;
      }
      
    }
  }
};
