class Toys{
public:
	void RemoveWithID(){

	}
	void RemoveWithName(){
	}
	void add(){
    		string sql, ProductName, BrandName;
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
       	        sql = "INSERT INTO toys (PRODUCTNAME,BRANDNAME,PRICE,PRODUCTYEAR) VALUES ('" + ProductName + "','" + BrandName  + "','$" + InttoString(Price) + "','" + InttoString(ProductYear) +"');";
       	        PostgresConnection PostgresConn;
       	        if ( PostgresConn.Add(sql) == 0 ){
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
