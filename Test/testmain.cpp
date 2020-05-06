/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: Works with that command : g++ -std=c++2a -Wall -g -pthread testmain.cpp -lgtest_main  -lgtest -lpthread -lpqxx -lpq
 *
 *        Version:  1.0
 *        Created:  2020-04-19 10:09:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Safa Bayar (rection), safa@safabayar.tech
 *   Organization:
 *
 * =====================================================================================
 */

#include <gtest/gtest.h>
// #include <gmock/gmock.h>
// #include <pqxx/pqxx>
// #include "../BillReport/BillReport.hpp"
// #include "../main.cpp"
// #include "../Sections/Toys.hpp"
#include "../Sections/Postgres/PostgresConnection.hpp"
// #include "../Sections/Postgres/tablesetup.hpp"
// #include "../Sections/Postgres/setup.hpp"
// #include <string>
using namespace std;

// class MockBill: public BillReport{
	// MOCK_METHOD0(int, menuforsection,() )
// }

TEST(power,myCubeTest){
	PostgresConnection tes;
	ASSERT_TRUE(tes.Add("DELETE FROM toys WHERE productname = 1;"));
}

// TEST (BillReport, show){
// 	int choice = 5;
// 	ASSERT_LE(BillReport::menuforsection(),choice);
// }
TEST (SampleTest,SampleTestofThemain){
	ASSERT_TRUE( 1 == 1 );
}


int main(int argc, char **argv){
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
