class Show: public PostgresConnection {
public:

  int Menu(){
    int selection = 0;
    cout << "1. games" << endl;
	  cout << "2. toys" << endl;
    cout << "3. garden" << endl;
 		cout << "4. books" << endl;
    do{
      cout << "Your choice for details";
      cin >> selection;
    }while( selection < 1 | selection > 4);
    return selection;
  }

  void Details(int menuselection){
    string wantedsectionname = sectionconverter(menuselection);
    if( wantedsectionname == "books" ){
      vector <string> ColumnName = {"id", "productname", "brandname", "price", "isbn", "productyear"};
      for( string i : ColumnName ){
        cout << i << " : " + getRecordsofSection("books",i) << endl;
      }
    }else if ( wantedsectionname == "games"){
      vector <string> ColumnName = {"id", "productname", "brandname", "price", "productyear"};
      for( string i : ColumnName){
        cout << i << " : " + getRecordsofSection("games",i) << endl;
      }
    }else if ( wantedsectionname == "toys"){
      vector <string> ColumnName = {"id", "productname", "brandname", "price", "productyear"};
      for( string i : ColumnName){
        cout << i << " : " + getRecordsofSection("toys",i) << endl;
      }
    }else if ( wantedsectionname == "garden"){
      vector <string> ColumnName = {"id", "productname", "brandname", "section", "price"};
      for( string i : ColumnName){
        cout << i << " : " + getRecordsofSection("garden",i) << endl;
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
