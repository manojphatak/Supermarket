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
#include "../BillReport/BillReport.hpp"
// #include "../Sections/Toys.hpp"
// #include "../Sections/Postgres/PostgresConnection.hpp"
// #include "../main.cpp"

using namespace std;

TEST(power,myCubeTest){
	PostgresConnection tes;
	ASSERT_TRUE(tes.Add("DELETE FROM toys WHERE productname = 1;"));
}

TEST (billReport, power){
	BillReport rpt;
	ASSERT_EQ(2,rpt.power(2,1));
	// ASSERT_EQ(4,rpt.power(4,2));
}


int main(int argc, char **argv){
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
