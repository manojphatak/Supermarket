#include "Postgres/setup.hpp"
#include "Postgres/tablesetup.hpp"

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

  bool TestofPostgres(){

    Postgresetup PostgresqlSetup;
    if( PostgresqlSetup.PostgresqlSetup == 1 ){
      cout << "The Database couldn't open.";
      return 0;			// 0 mean false or unsuccesfull.
    }else{
      echo "The Database opened. \nThe table creating...";
      TableInstallation GameTable;
      if ( GameTable != 1 ){
	cout << "The table created succesfully!";
	return 1;		// 1 mean true
      }else{
	return 0;		// 0 mean false
      }      
    }    
  }

  void inputtopostgres(){
    int ProductYear = getProductYear();
    string BrandName = getBrandName();
    string GameName = getGameName();

    TestofPostgres();    
  }

  void InputforTable(string gamename, string brandname, int productyear){
    char * sql;
    sql = "INSERT INTO Market (PRODUCTNAME,PRICE,PRODUCTYEAR) VALUES ('Tomb Raider','25','1999');";
    work W(C);			// We need to return of C reference
    W.exec( sql );
    W.commit();
    cout << "Records created successfully" << endl;
    C.disconnect ();
   } catch (const std::exception &e) {
    cerr << e.what() << std::endl;
    return 1; 
  }
};
