#include <pqxx/pqxx> 


using namespace std;
using namespace pqxx;

class Games{
private:
  //Item Names,Product Year, Brand Name for Games section.
  string GameName, BrandName;
  int ProductYear;
public:
  
  string getGameName(){
    return GameName;
  }
  string setGameName( string NewGameName ){
    GameName = NewGameName;
  }
  string getBrandName(){
    return BrandName;
  }
  string setBrandName( string NewBrandName ){
    BrandName = NewBrandName;
  }
  int getProductYear(){
    return ProductYear;
  }
  int setProductYear( int NewProductYear ){
    ProductYear = x;
  }

  void PostgresqlSetup(){
    try {
      connection C("dbname = testdb user = postgres password = TEST \
      hostaddr = 127.0.0.1 port = 5432");
      if (C.is_open()) {
	cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
	cout << "Can't open database" << endl;
	return 1;
      }
      C.disconnect ();
    } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;
    }
  }
};
