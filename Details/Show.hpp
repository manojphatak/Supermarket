class Show: public PostgresConnection {
public:
  string getDetails(string ProductName){
    string sql = "SELECT * FROM Games WHERE PRODUCTNAME = '" + ProductName + "'";

    try {
	    pqxx::connection C("dbname = supermarket user = employee password = test hostaddr = 127.0.0.1 port = 5432");
      if ( C.is_open() ) {
        std::cout << "Opened database successfully: " << C.dbname() << '\n';
      }
      pqxx::nontransaction N(C);
      pqxx::result R( N.exec( sql ));
      for (pqxx::result::const_iterator c = R.begin(); c != R.end(); c++) {
	cout << "PRODUCTNAME = " << c[1].as<string>() << endl;
	cout << "BRANDNAME = " << c[2].as<string>() << endl;
	cout << "PRICE = " << c[3].as<string>() << endl;
	cout << "PRODUCTYEAR = " << c[4].as<int>() << endl;
      }
      cout << "Operation done successfully" << endl;
      } catch (const  exception &e) {
        cerr << e.what() <<  endl;
        return "FAILED";
      }
      return "SUCCESS";
  }
};
