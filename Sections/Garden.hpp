class Garden{
public:
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
