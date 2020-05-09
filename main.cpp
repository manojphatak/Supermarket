/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: Main page for application
 *        Command: g++ main.cpp -std=c++2a -lpqxx -lpq -lpthread -pthread 
 *
 *        Version:  1.0
 *        Created:  2020-04-10 01:35:52 AM
 *       Compiler:  g++
 *
 *         Author:  Safa Bayar (rection), safa@safabayar.tech
 *   Organization:
 *
 * =====================================================================================
 */


#include <iostream>
#include <string>
#include <algorithm>
#include "BillReport/BillReport.hpp"
#include "Regulations/Add.hpp"
#include "Regulations/Remove.hpp"
#include "Details/Show.hpp"
#include "Sections/Postgres/setup.hpp"


int main(){

  PostgresSetup setupoftables;
  if (setupoftables.PostgresqlSetup() != 0 ){
	  std::cout << "Bye" << std::endl;
	  exit(-1);
  }
  
  TableInstallForPostgres Tabletest;
  if (Tabletest.ExistTableTest() == 1){
    std::cout << "Table created succesfully." << std::endl; 
  }else{
    std::cout << "The tables didn't create." << std::endl;
  }

  int itemno=0,menuselect=0;
  std::cout << "\t\t\tSuper Market Billing\t\t\t\n";
  std::cout << "1. Bill Report\n";
  std::cout << "2. Regulation of The Item\n";
  std::cout << "3. Show Item Details\n";
  std::cout << "4. Exit\n";

  do{
    std::cout << "Please Enter Required Option: ";
    std::cin >> menuselect;
  }while( menuselect <= 0 | menuselect > 4 );


  switch(menuselect) {
  case 1: {
    BillReport BillReportObj;
    int choice = BillReportObj.menuforsection();
    BillReportObj.show(choice);
    break;
  }
  case 2: {
    std::cout << "1. Add the items." << std::endl;
    std::cout << "2. Remove the items." << std::endl;
    do{
      std::cout << "Your choice for regulations method: ";
      std::cin >> itemno;
    }while( itemno <= 0 | itemno >= 3 );

    if ( itemno == 1 ){
	AddRecords addgame;
      	std::string YorN = "Y";
      	while ( YorN == "Y" ){
        	addgame.menuforregulations();
        	std::cout << "\nWill you add more gmae records? Y/N" << std::endl;
        	std::cin >> YorN;
      	}
    }else if ( itemno == 2 ){
	    RemoveTheRecord deleterecords;
	    std::string YorN = "Y";
	    while ( YorN == "Y" ){
		    deleterecords.MenuForSelectSection();
		    std::cout << "\nWill you add more game records? Y/N" << std::endl;
        	    std::cin >> YorN;
	    }
    }
    break;
  }
  case 3:
  {
    std::string ProductName;
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
