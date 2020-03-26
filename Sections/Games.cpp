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

  void inputthepostgres()
};
