class GameTableInstall {
  void GamesTableInstallation(){
    try {
      sql = "CREATE TABLE Market("			\
	"ID INT PRIMARY KEY     NOT NULL,"		\
	"PRODUCTNAME           CHAR(50)    NOT NULL,"	\
	"ADDRESS        CHAR(50)    NOT NULL,"		\
	"PRICE        INT     NOT NULL"			\
	"PRODUCTYEAR            INT     NOT NULL);";
      
      work W(C);
      
      W.exec( sql );
      W.commit();
      cout << "Table created successfully" << endl;
      C.disconnect ();
    } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;
    }
  }
};
