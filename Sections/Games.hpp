#include "Postgres/setup.hpp"
#include "Postgres/tablesetup.hpp"

using namespace std;

class Games{
private:
  //Item Names,Product Year, Brand Name for Games section.
  string GameName, BrandName;
  int ProductYear, Price;

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
    ProductYear = NewProductYear;
  }
  int setPrice( int newPrice ){
    Price = newPrice;
  }
  int getPrice(){
    return Price;
  }
};

class PostgresProcess{
public:
  bool TestofPostgres(){

    PostgresSetup Setup;
    if( Setup.PostgresqlSetup() == 1 ){
      std::cout << "The Database couldn't open.";
      return 0;			// 0 mean false or unsuccesfull.
    }else{
      std::cout << "The Database opened. \nThe table creating...";
      GameTableInstall GameTable;
      if ( GameTable.GamesTableInstallation() != 1 ){
	std::cout << "The table created succesfully!";
	return 1;		// 1 mean true
      }else{
	return 0;		// 0 mean false
      }      
    }    
  }


  void InputforTable(string gamename, string brandname, int productyear){
    char * sql;
    sql = "INSERT INTO Market (PRODUCTNAME,PRICE,PRODUCTYEAR) VALUES ('Tomb Raider','25','1999');";
    int ProductYear = getProductYear();
    string BrandName = getBrandName();
    string GameName = getGameName();

    try {
      connection C("dbname = market user = postgres password = TEST hostaddr = 127.0.0.1 port = 5432");
      TestofPostgres();     
      if (C.is_open()) {
	work W(C);			// We need to return of C reference
	W.exec( sql );
	W.commit();
	std::cout << "Records created successfully" << std::endl;
	C.disconnect ();
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
	return 1; 
    }
  }
};
