/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
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

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
