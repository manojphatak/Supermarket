#include "../Sections/Games.hpp"
#include "../Sections/Postgres/PostgresConnection.hpp"
#include <sstream>

class Add{
public:
  void add(){
    string sql, GameName, BrandName;
    int ProductYear, Price;
    Games Gameobj;
    std::cout << "\nGame Name: " << std::endl;
    std::cin >> GameName;
    std::cout << "\nBrand Name: " << std::endl;
    std::cin >> BrandName;
    std::cout << "\nPrice: " << std::endl;
    std::cin >> Price;
    std::cout << "\nProduct Year: " << std::endl;
    std::cin >> ProductYear;
    sql = "INSERT INTO Market (PRODUCTNAME,BRANDNAME,PRICE,PRODUCTYEAR) VALUES ('" + GameName + "','" + BrandName  + "','" + InttoString(Price) + "','" + InttoString(ProductYear) +"');";
    PostgresConnection PostgresConn;
    if ( PostgresConn.Add(sql) == 0 ){
      std::cout << "The record added successfully!";
	}else{
      std::cout << "Something Gone Wrong!";
    }
  }
  string InttoString(int number){
    ostringstream temp;
    temp << number;
    return temp.str();
  }
};
