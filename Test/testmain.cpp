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
#include "../BillReport/BillReport.hpp"
#include "../Details/Show.hpp"

using namespace std;


TEST(ShowTest,sectionconverter){
	Show shw;
	ASSERT_EQ("books",shw.sectionconverter(4));
}

TEST(Postgresql,Add_First_Record){
	PostgresConnection tes;
	ASSERT_FALSE(tes.setAdd("INSERT INTO games (PRODUCTNAME,BRANDNAME,PRICE,PRODUCTYEAR) VALUES ('Bloodborn','jens',23.3,1999);"));
}

TEST (billReport, power){
	BillReport rpt;
	ASSERT_EQ(2,rpt.power(2,1));
}

TEST (Billreport, power_with_base){
	BillReport rpt;
	ASSERT_EQ(16,rpt.power(4,2));

}

TEST (Convert_Float, String_to_float){
	BillReport rpt;
	float te = 2.12;
	ASSERT_EQ(te,rpt.converttofloat("2.12"));
}

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
