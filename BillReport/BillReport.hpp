#include "../Sections/Postgres/PostgresConnection.hpp"

class BillReport {
public:
  float show(){
	std::string listofSection [4];
	listofSection[0] = "games";
	listofSection[1] = "toys";
	listofSection[2] = "garden";
	listofSection[3] = "books";
 	float net = 0.00;
	 for( int i = 0; i < 3; i++ ){
		PostgresConnection record;
		net += record.getShow(listofSection[i]);
	      }
    	return net;
  }	    
};
