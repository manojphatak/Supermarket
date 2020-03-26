#include "Sections/Games.cpp"
#include <iostream>
class BillReport {
public:
  void show(){
    Games Gamesobj;
    Gamesobj.setProductYear(5);
    std::cout << Gamesobj.getProductYear();
  }
}; 
