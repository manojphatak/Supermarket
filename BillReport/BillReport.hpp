#include "../Sections/Postgres/PostgresConnection.hpp"

class BillReport {
public:
  float show(){
	std::string listofSection [3];
//	listofSection[0] = "Games";
// 	listofSection[1] = "Toys";
 //	listofSection[2] = "Garden";
 //	listofSection[3] = "Books";
 	float net = 0.00;
 //	for( int i = 0; i <= 3; i++ ){
		PostgresConnection record;
		net += record.getShow("Games");
      	//}
    	return net;
 	}    
};
