using namespace std;

class BillReport {
public:
  double show(){
    char listofSection [4];

    listofSection[0] = "Games";
    listofSection[1] = "Toys";
    listofSection[2] = "Garden";
    listofSection[3] = "Books";
    for( int i = 0; i <= 3; i++ ){
      string sql[i] = "SELECT SUM(PRICE) FROM " + listofSection[i];
      try{
      connection C("dbname = market user = employee password = test hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open() && TestofPostgres() == 1) {
        std::cout << "Opened database successfully: " << C.dbname() << '\n';
      }
      nontransaction N(C);
      result R( N.exec( sql[i] ));
      for (result::const_iterator c = R.begin(); c != R.end(); c++) {
        cout << " Total Of = " + listofSection[i] + " : "<< c[0].as<string>() << endl;
      }
      cout << "Operation done successfully" << endl;
      C.disconnect ();
    } catch ( const exception &e ) {
      cerr << e.what() <<  endl;
      }
    }
    
    return BillReport;
  }
};
