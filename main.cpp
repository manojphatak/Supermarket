#include <iostream>
#include <string>
#include <algorithm>
#include "BillReport/BillReport.hpp"
#include "Regulations/Add.hpp"
#include "Details/Show.hpp"
#include "Sections/Postgres/setup.hpp"

int main(){

  PostgresSetup setupoftables;
  if (setupoftables.PostgresqlSetup() != 0 ){
	  std::cout << "Bye" << std::endl;
	  exit(-1); 
  }

  int itemno=0,menuselect=0;
  std::cout << "\t\t\tSuper Market Billing\t\t\t\n";
  std::cout << "1. Bill Report\n";
  std::cout << "2. Regulation of The Item\n";
  std::cout << "3. Show Item Details\n";
  std::cout << "4. Exit\nPlease Enter Required Option:";
  std::cin >> menuselect;



  switch(menuselect) {
  case 1: {
    BillReport BillReportObj;
    std::cout << BillReportObj.show() << std::endl;
    break;
  }
  case 2: {
    std::cout << "1.Add the items";
    std::cin >> itemno;
    if ( itemno == 1 ){
      AddofRecord addgame;
      std::string YorN = "Y";
      while ( YorN == "Y" ){
        addgame.add();
        std::cout << "\nWill you add more gmae records? Y/N" << std::endl;
        std::cin >> YorN;
      }
    }
    break;
  }
  case 3:
  {
    string ProductName;
    Show show;
    std::cout << "You need to give name of the product name: ";
    std::cin >> ProductName;
    if ( show.getDetails(ProductName) == "SUCCESS" ){
      return 1;
    }else{
      return 0;
    }
    break;
  }
  case 4: {
    std::cout << "The program killed.";
    return 0;
  }
  default: {
    std::cout << "You didn't choose a number.";
  }
  }

  return 0;
}
