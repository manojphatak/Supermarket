/*
 * =====================================================================================
 *
 *       Filename:  Books.hpp
 *
 *    Description: Book section in market.
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

class Books : PostgresConnection{
public:

	void RemoveWithID(int IDnumber){
		string sql = "DELETE FROM books WHERE id = '" + InttoString(IDnumber) + "';";
		PostgresConnection PostgresConn;
       	        if ( PostgresConn.setAdd(sql) == 0 ){
       	          	std::cout << "The record added successfully!";
       	          }else{
       	          	std::cout << "Something Gone Wrong!";
       	        }
	}
	void RemoveWithName(string Name){
		string sql = "DELETE FROM books WHERE productname = '" + Name + "';";
		PostgresConnection PostgresConn;
       	        if ( PostgresConn.setAdd(sql) == 0 ){
       	          	std::cout << "The record added successfully!";
       	          }else{
       	          	std::cout << "Something Gone Wrong!";
       	        }
	}
	void add(){
    		string sql, ProductName, BrandName, ISBN;
       	        int ProductYear;
       	        float Price;
       	        std::cout << "Product Name: " << std::endl;
       	        std::cin >> ProductName;
       	        std::cout << "Brand Name: " << std::endl;
       	        std::cin >> BrandName;
       	        std::cout << "Price: (Sample 4.54)" << std::endl;
       	        std::cin >> Price;
       	        std::cout << "Product Year: " << std::endl;
       	        std::cin >> ProductYear;
       	        std::cout << "ISBN: " << std::endl;
       	        std::cin >> ISBN;
       	        sql = "INSERT INTO books (PRODUCTNAME,BRANDNAME,PRICE,ISBN,PRODUCTYEAR) VALUES ('" + ProductName + "','" + BrandName  + "','$" + InttoString(Price) + "','" + ISBN + "','" + InttoString(ProductYear) +"');";
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
