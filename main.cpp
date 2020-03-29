#include <iostream>
#include "BillReport.hpp"

using namespace std;

int main(){

  int itemno=0,menuselect=0;
  std::cout << "\t\t\tSuper Market Billing\t\t\t\n";
  std::cout << "1. Bill Report\n";
  std::cout << "2. Regulation of The Item\n";
  std::cout << "3. Show Item Details\n";
  std::cout << "4. Exit\nPlease Enter Required Option:";
  std::cin >> menuselect;
 
  switch(menuselect) {
  case 1:
    BillReport BillReportObj;
    BillReportObj.show();
    break;
  case 2:
    //Regulations();
    break;
  case 3:
    //ItemDetails();
    break;
  case 4:
    std::cout << "The program killed.";
    return 0;
  default:
    std::cout << "You didn't choose a number.";
  }
  
  return 0;
}
