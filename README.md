![CI](https://github.com/rection/Supermarket/workflows/CI/badge.svg)

I am doing practise for improve myself on C++. This project purpose, the supermarket take register of the products. The products are seperate with the section. These sections are Games, Books, Toys and Groceries. 

The program using on management office so they can give input the system. The records holds in PostgreSQL. I used libpqxx library for PostgreSQL connection. 


## Installation:

The first necessary PostgreSQL-11 and libpqxx library for PostgreSQL connection. You can follow these instructions for install postgreSQL. You need to be apply this code for install the libpqxx library in Debian and Redhatsystems:

```
sudo apt install libpqxx-7.0 libpqxx-dev   ## For Debian
sudo dnf install libpqxx-7.0 libpqxx-dev   ## For Fedora or Centos 8
sudo yum install libpqxx-7.0 libpqxx-dev   ## For Centos 7 or before
```

If your package manager couldn't find this packages, You can install with cmake with [source code](https://github.com/jtv/libpqxx).

This packages in this repository *http://deb.debian.org/debian buster/main amd64.*

The Postgresql setup is like this:

```
create user employee with password test;
grant NOLOGIN, NOCREATEROLE, NOSUPERUSER on database "supermarket" to employee;
create database Supermarket owner employee;
```


You can compile right now. I used c++2a standarts. The g++/gcc should be up version of 8:

```
g++ main.cpp -std=c++2a -lpqxx -lpq -pthread
```

Also, you can build with cmake

```
mkdir build
cd build
cmake ..
make
./supermarket
```

## Table Structure in PostgreSQL

```
	          
	       /-------> Groceries      /------------\
	      /                        /  ProductName \
	     /-------> Games ----------   BrandName
Market -----/                          \  ProductYear /
            \                           \------------/
	     \-------> Books
	      \
               \--------> Toys

```

**This program for practices of Object Oriented Programming. I use Document Driven Development (DDD). This program has Inheritance, Polymorphism, Encapsulation, Access Specifiers, Class Methods, Function overloading and Exceptions examples.**


**If you want to use real life program, you can use cmake. That will be work faster than. You can find the cmake page in this [link](https://cmake.org/). Also, you need to fix bugs in SonarQube.**

# The Issues:

1. [+] All sql queries must be change for **Supermarket** database.
2. [+] The bill report should have strings. The function just return integer.
3. [+] Prices returned to Money data type.
4. [+] Tables and database need to check and create automaticly in program.
5. [+] Libpqxx install with new version. Also update the codes for new version. [pqxx-7.0.0]
6. [+] The bill report doesn't work.
7. [+] The other sections need to add in program.
8. [+] Regualtion items need to has remove and edit choices.
9. [+] The bill total calculation doesn't work as I want.
10. [+] The regulations section need to has remove section.
11. [-] Coverage test and stub test neccesary for Github Actions. [I don't know about Github Actions, I am working on.]
12. [+] Write tests and use github actions.
13. [+] The licence missing
