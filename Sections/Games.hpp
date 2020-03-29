
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
};
