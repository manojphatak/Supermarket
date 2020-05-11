/*
 * =====================================================================================
 *
 *       Filename:  Books.hpp
 *
 *    Description: Garden section in market.
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

class Garden{
public:
	void RemoveWithID(int ID){
		string sql = "DELETE FROM garden WHERE id = '" + InttoString(ID) + "';";
		PostgresConnection PostgresConn;
       	        if ( PostgresConn.setAdd(sql) == 0 ){
       	          	std::cout << "The record added successfully!";
       	          }else{
       	          	std::cout << "Something Gone Wrong!";
       	        }

	}
	void RemoveWithName(string Name){
		string sql = "DELETE FROM garden WHERE productname = '" + Name + "';";
		PostgresConnection PostgresConn;
       	        if ( PostgresConn.setAdd(sql) == 0 ){
       	          	std::cout << "The record added successfully!";
       	          }else{
       	          	std::cout << "Something Gone Wrong!";
       	        }
	}
	void add(){
    		string sql, ProductName, BrandName, Section;
       	        float Price;
       	        std::cout << "Product Name: " << std::endl;
       	        std::cin >> ProductName;
       	        std::cout << "Brand Name: " << std::endl;
       	        std::cin >> BrandName;
       	        std::cout << "Price: (Sample 4.54)" << std::endl;
       	        std::cin >> Price;
       	        std::cout << "Section :" << std::endl;
       	        std::cin >> Section;
       	        sql = "INSERT INTO garden (PRODUCTNAME,BRANDNAME,SECTION,PRICE) VALUES ('" + ProductName + "','" + BrandName  + "','" + Section + "','$" + InttoString(Price) + "');";
       	        PostgresConnection PostgresConn;
       	        if ( PostgresConn.setAdd(sql) == 0 ){
       	          	std::cout << "The record added successfully!";
       	          }else{
       	          	std::cout << "Something Gone Wrong!";
       	        }
    }
	string InttoString(int number){
       	        ostringstream temp;
       	        temp << number;
       	        return temp.str();
	}
};
