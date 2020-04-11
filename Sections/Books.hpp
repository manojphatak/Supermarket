class Books{
public:
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
