
class Details{
public:
  show(){

  }
}

class Show: public PostgresConnection {
public:
  string * getDetails(string ProductName){
    string ProductYear = "SELECT PRODUCTYEAR FROM Games WHERE PRODUCTNAME = " + name;
    string BrandName = "SELECT BRANDNAME FROM Games WHERE PRODUCTNAME = " + name;
    string Price = "SELECT PRICE FROM Games WHERE PRODUCTNAME = " + name;

    try {
        W.exec( ProductName, ProductYear, BrandName, Price );
        W.commit();
        cout << "The sql command worked successfully!" <<  endl;
        C.disconnect ();
        }
      } catch (const  exception &e) {
        cerr << e.what() <<  endl;
        return 1;
      }
      std::cout << "/* message */" << '\n';
  }
};
