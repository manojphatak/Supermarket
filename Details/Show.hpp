/*
 * =====================================================================================
 *
 *       Filename:  Show.hpp
 *
 *    Description: show pages for all records.
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

class Show: public PostgresConnection {
public:

  void Menu(){
    int selection = 0;
    cout << "1. games" << endl;
	  cout << "2. toys" << endl;
    cout << "3. garden" << endl;
 		cout << "4. books" << endl;
    do{
      cout << "Your choice for details";
      cin >> selection;
    }while( selection < 1 | selection > 4);
    MethodChoice(selection);
  }

  void MethodChoice(int selection){
    int Method;
    cout << "1. Show with ID number." << endl;
    cout << "2. Show with productname." << endl;
    do{
      cout << "Your choice : ";
      cin >> Method;
    }while(Method < 1 | Method > 2);
    if ( Method == 1){
      IDShow(selection);
    }else if( Method == 2){
      ProductName(selection);
    }else{
      cerr << "Method Choice ERROR!" << endl;
    }
  }

  void IDShow(int selection){
    int IDnumber;
    cout << "ID number : " << endl;
    cin >>  IDnumber;     // Max Id number validation
    Details(selection, IDnumber);
  }

  void ProductName(int selection){
      string productname;
      do{
        cout << "Product Name : ";
        cin >> productname;   // Not found record validation
      }while(productname != "");
      Details(selection, productname);
  }

  void Details( int menuselection, string name ){
    string wantedsectionname = sectionconverter(menuselection);
    if( wantedsectionname == "books" ){
      vector <string> ColumnName = {"id", "productname", "brandname", "price", "isbn", "productyear"};
      for( string i : ColumnName ){
        cout << i << " : " + getRecordsofSection("books",i, name) << endl;
      }
    }else if ( wantedsectionname == "games"){
      vector <string> ColumnName = {"id", "productname", "brandname", "price", "productyear"};
      for( string i : ColumnName){
        cout << i << " : " + getRecordsofSection("games",i, name) << endl;
      }
    }else if ( wantedsectionname == "toys"){
      vector <string> ColumnName = {"id", "productname", "brandname", "price", "productyear"};
      for( string i : ColumnName){
        cout << i << " : " + getRecordsofSection("toys",i, name) << endl;
      }
    }else if ( wantedsectionname == "garden"){
      vector <string> ColumnName = {"id", "productname", "brandname", "section", "price"};
      for( string i : ColumnName){
        cout << i << " : " + getRecordsofSection("garden",i, name) << endl;
      }
    }else{
      cout << "Error! Section not found" << endl;
    }
  }
  void Details( int menuselection, int ID ){
    string wantedsectionname = sectionconverter(menuselection);
    if( wantedsectionname == "books" ){
      vector <string> ColumnName = {"id", "productname", "brandname", "price", "isbn", "productyear"};
      for( string i : ColumnName ){
        cout << i << " : " + getRecordsofSection("books",i, ID) << endl;
      }
    }else if ( wantedsectionname == "games"){
      vector <string> ColumnName = {"id", "productname", "brandname", "price", "productyear"};
      for( string i : ColumnName){
        cout << i << " : " + getRecordsofSection("games",i, ID) << endl;
      }
    }else if ( wantedsectionname == "toys"){
      vector <string> ColumnName = {"id", "productname", "brandname", "price", "productyear"};
      for( string i : ColumnName){
        cout << i << " : " + getRecordsofSection("toys",i, ID) << endl;
      }
    }else if ( wantedsectionname == "garden"){
      vector <string> ColumnName = {"id", "productname", "brandname", "section", "price"};
      for( string i : ColumnName){
        cout << i << " : " + getRecordsofSection("garden",i, ID) << endl;
      }
    }else{
      cout << "Error! Section not found" << endl;
    }
  }

  string sectionconverter(int menuno){
    if( menuno == 1 ){
      return "games";
    }else if( menuno == 2 ){
      return "toys";
    }else if( menuno == 3 ){
      return "garden";
    }else if( menuno == 4 ){
      return "books";
    }else{
      exit(0);
    }
  }

};
