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

using namespace std;


TEST()


int main(int argc, char **argv){
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
