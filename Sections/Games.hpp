#include "Postgres/setup.hpp"
#include "Postgres/tablesetup.hpp"
#include <sstream>

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
  void setGameName( string NewGameName ){
    GameName = NewGameName;
  }
  string getBrandName(){
    return BrandName;
  }
  void setBrandName( string NewBrandName ){
    BrandName = NewBrandName;
  }
  int getProductYear(){
    return ProductYear;
  }
  void setProductYear( int NewProductYear ){
    ProductYear = NewProductYear;
  }
  void setPrice( int newPrice ){
    Price = newPrice;
  }
  int getPrice(){
    return Price;
  }

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


  bool InputforTable(string gamename, string brandname, int productyear, int price){
    string sql;
    int ProductYear = productyear;
    string BrandName = brandname;
    string GameName = gamename;
    int Price = price;

    sql = "INSERT INTO Market (PRODUCTNAME,BRANDNAME,PRICE,PRODUCTYEAR) VALUES ('" + GameName + "','" + BrandName  + "','" + InttoString(Price) + "','" + InttoString(ProductYear) +"');";
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
    return 0;
  }

  string InttoString(int number){
    ostringstream temp;
    temp << number;
    return temp.str();
  }
};
