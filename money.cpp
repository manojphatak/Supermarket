/*
 * =====================================================================================
 *
 *       Filename:  money.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020-04-10 11:37:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Safa Bayar (rection), safa@safabayar.tech
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;


int main(){

	string moneys = "$1,412.00";
	moneys.erase(moneys.begin() ); 
	cout << moneys << endl;
	return 0;
}

