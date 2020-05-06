/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: Works with that command : g++ -Wall -g -pthread testmain.cpp -lgtest_main  -lgtest -lpthread 
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
using namespace std;

// class MockBill: public BillReport{
// 	MOCK_METHOD(int, menuforsection,(),);
// }

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
