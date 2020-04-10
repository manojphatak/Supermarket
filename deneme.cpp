/*
 * =====================================================================================
 *
 *       Filename:  deneme.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020-04-10 06:02:08 PM
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

void games(){
	cout << "games" << endl;
}

void books(){
	cout << "books" << endl;
}

void toys(){
	cout << "toys" << endl;
}

void garden(){
	cout << "garden" << endl;
}

int main(){
	std::string nameofsection[4] = {"games","books","toys","garden"};
	for ( int i = 0 ; i < 4 ; i++){
		nameofsection[i]();
	}
	return 0;
}

