#include "Util.hpp"


sql::Driver *driver;
sql::Connection *con;
sql::Statement *stmt;

string total_comp[]={"ul","um","uh","bl","bm","bh"};
bool initialized=false; //indicates wether user has connected to DB or not
int DATASET_ID=0;

void initDB(string data_set_host,string data_set,string user_name,string user_pass){
    
    //Initiates connection to DB
    /* Create a connection */
    try{
        driver = get_driver_instance();
        con = driver->connect(data_set_host, user_name, user_pass);
        /* Connect to the MySQL test database */
        con->setSchema(data_set);
        initialized=true;
        srand(time(0));
    }
    catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in initDB():"<<e.what()<<endl;
    }
}

void endDB(){
    //Deletes connection to DB and deletes parameters
    try{
        delete stmt;
        delete con;
        initialized=false;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in endDB():"<<e.what()<<endl;
    }
}

int comp_dist(string s){
    //Checks required total transactions length distribution
    try{
        int siz=sizeof(total_comp)/sizeof(total_comp[0]);
        for(int i=0;i<siz;i++){
            if(!total_comp[i].compare(s)){
                //String exists. Return 1
                return 1;
            }
        }
        //String does not exist
        return 0;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in comp_dist():"<<e.what()<<endl;
    }
}

vector<double> selectPeriod(int hyperperiod){
    //Returns all available periods that are devisors of hyperperiod and lying between the specified
    //period limits
    try{
        
        int period[]={10000,100000}; //min and max period values in micro_sec
                                    //the next element is 0 or 1. 1 means the value is included in interval, 0 means the reverse
        return findDevisors(hyperperiod,period[0],period[1]);
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in selectPeriod():"<<e.what()<<endl;
    }
}

double selectUtil(string util_dist,double stm_inst,double rt_inst,double period){
    //Return utilization for current task. min_ratio is the minimum value for util percentage
    try{
        int min_ratio=(int)(rt_inst>stm_inst?ceil(rt_inst/period):ceil(stm_inst/period));        //min_ratio=min(wcet/period)|min(wcet)=max(one read/write stm instruction time,normal real_time instruction time)
        min_ratio=min_ratio<1?1:min_ratio;      //Just be sure min_ratio is not 0
        int ratio_int=(100-min_ratio)/3;
        int util_uniform_light[]={min_ratio,min_ratio+ratio_int};
        int util_uniform_medium[]={min_ratio+ratio_int,min_ratio+2*ratio_int};
        int util_uniform_heavy[]={min_ratio+2*ratio_int,100};
        int sel_util=1;       //Selected utilization, initialized at 1

        if(!util_dist.compare("ul")){
            //utilization is drawn from uniform light distribution
            do{
                sel_util=(rand()%(util_uniform_light[1]-util_uniform_light[0]))+util_uniform_light[0];
            }while(sel_util<min_ratio);
        }
        else if(!util_dist.compare("um")){
            //utilization is drawn from uniform medium distribution
            do{
                sel_util=(rand()%(util_uniform_medium[1]-util_uniform_medium[0]))+util_uniform_medium[0];
            }while(sel_util<min_ratio);
        }
        else if(!util_dist.compare("uh")){
            //utilization is drawn from uniform heavy distribution
            do{
                sel_util=(rand()%(util_uniform_heavy[1]-util_uniform_heavy[0]))+util_uniform_heavy[0];
            }while(sel_util<min_ratio);
        }
        return (double)sel_util/100.0;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in selectUtil():"<<e.what()<<endl;
    }
}

double selectTotalTx(string total_tx_dist,double stm_inst,double wcet){
    //Returns selected total percentage of transactional length according to required distribution
    //min_ratio is the minimum value for total_tx_dist perc=min(one read/write stm instruction time/wcet)
    try{
        int min_ratio=(int)ceil(stm_inst/wcet);
        min_ratio=min_ratio<1?1:min_ratio;      //Just be sure min_ratio is not 0
        int int_diff=(100-min_ratio)/3;
        int total_tx_uniform_light[]={min_ratio,min_ratio+int_diff};
        int total_tx_uniform_medium[]={min_ratio+int_diff,min_ratio+2*int_diff};
        int total_tx_uniform_heavy[]={min_ratio+2*int_diff,100};
        int sel_total=1;      //Selected total value, initialized at 1
        if(!total_tx_dist.compare("ul")){
            //utilization is drawn from uniform light distribution
            do{
                sel_total=(rand()%(total_tx_uniform_light[1]-total_tx_uniform_light[0]))+total_tx_uniform_light[0];
            }while(sel_total<min_ratio);
        }
        else if(!total_tx_dist.compare("um")){
            //utilization is drawn from uniform medium distribution
            do{
                sel_total=(rand()%(total_tx_uniform_medium[1]-total_tx_uniform_medium[0]))+total_tx_uniform_medium[0];
            }while(sel_total<min_ratio);
        }
        else if(!total_tx_dist.compare("uh")){
            //utilization is drawn from uniform heavy distribution
            do{
                sel_total=(rand()%(total_tx_uniform_heavy[1]-total_tx_uniform_heavy[0]))+total_tx_uniform_heavy[0];
            }while(sel_total<min_ratio);
        }
        return (double)sel_total/100.0;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Error in selectTotalTx():"<<e.what()<<endl;
    }
}

double selectMaxTx(string max_tx_dist,double total_tx,double stm_inst,double wcet){
    //Returns selected max percentage of transactional length according to required distribution
    try{
        int min_ratio=(int)ceil(stm_inst/wcet);  //min_ratio is the minimum value for max_tx_dist perc=min(one read/write stm instruction time/wcet)
        min_ratio=min_ratio<1?1:min_ratio;
        int tmp_int=(100-min_ratio)/3;
        int max_tx_uniform_light[]={min_ratio,min_ratio+tmp_int};
        int max_tx_uniform_medium[]={min_ratio+tmp_int,min_ratio+2*tmp_int};
        int max_tx_uniform_heavy[]={min_ratio+2*tmp_int,100};
        int sel_max=1;        //selected maximum value, initialized at 1
        int high_max_bound; //Holds the higher distribution boundary in following comparisons
        total_tx=(total_tx*100)+1;      //To enable comparison against different boundaries as given below
                                        //total_tx is incremented by 1 (after it is converted to integer)to enable max_tx to gain values
                                        //at most equal to total_tx
        if(!max_tx_dist.compare("ul")){
            //utilization is drawn from uniform light distribution
            if(total_tx<max_tx_uniform_light[0]){
                cout<<"Error: total_tx is lower than max_tx"<<endl;
                exit(0);
            }
            high_max_bound=total_tx>(max_tx_uniform_light[1]+1)?(max_tx_uniform_light[1]+1):total_tx;
            do{
                sel_max=(rand()%(high_max_bound-max_tx_uniform_light[0]))+max_tx_uniform_light[0];
            }while(sel_max<min_ratio);
        }
        else if(!max_tx_dist.compare("um")){
            //utilization is drawn from uniform medium distribution
            if(total_tx<max_tx_uniform_medium[0]){
                cout<<"Error: total_tx is lower than max_tx"<<endl;
                exit(0);
            }
            high_max_bound=total_tx>(max_tx_uniform_medium[1]+1)?(max_tx_uniform_medium[1]+1):total_tx;
            do{
                sel_max=(rand()%(high_max_bound-max_tx_uniform_medium[0]))+max_tx_uniform_medium[0];
            }while(sel_max<min_ratio);
        }
        else if(!max_tx_dist.compare("uh")){
            //utilization is drawn from uniform heavy distribution
            if(total_tx<max_tx_uniform_heavy[0]){
                cout<<"Error: total_tx is lower than max_tx"<<endl;
                exit(0);
            }
            high_max_bound=total_tx>(max_tx_uniform_heavy[1]+1)?(max_tx_uniform_heavy[1]+1):total_tx;
            do{
                sel_max=(rand()%(high_max_bound-max_tx_uniform_heavy[0]))+max_tx_uniform_heavy[0];
            }while(sel_max<min_ratio);
        }
        return (double)sel_max/100.0;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in selectMaxTx():"<<e.what()<<endl;
    }
}

double selectMinTx(string min_tx_dist,double max_tx,double stm_inst,double wcet){
    //Returns selected min percentage of transactional length according to required distribution
    try{
        int min_ratio=(int)ceil(stm_inst/wcet);  //min_ratio is the minimum value for min_tx_dist perc=min(one read/write stm instruction time/wcet)
        min_ratio=min_ratio<1?1:min_ratio;      //Just be sure min_ratio is not 0
        int tmp_int=(100-min_ratio)/3;
        int min_tx_uniform_light[]={min_ratio,min_ratio+tmp_int};
        int min_tx_uniform_medium[]={min_ratio+tmp_int,min_ratio+2*tmp_int};
        int min_tx_uniform_heavy[]={min_ratio+2*tmp_int,100};
        int sel_min=1;     //selected minimum value. Initialized at 1
        int high_min_bound; //To enable comparison against different distribution boundaries
        max_tx=(max_tx*100)+1;        //max_tx is incremented by 1 (after it is converted into integer) to enable min_tx to gain values
                                    //at most equal to max_tx
        if(!min_tx_dist.compare("ul")){
            //utilization is drawn from uniform light distribution
            if(max_tx<min_tx_uniform_light[0]){
                cout<<"Error: max_tx is lower than min_tx"<<endl;
                exit(0);
            }
            high_min_bound=max_tx>(min_tx_uniform_light[1]+1)?(min_tx_uniform_light[1]+1):max_tx;
            do{
                //This loop guarantees that min is never 0
                sel_min=(rand()%(high_min_bound-min_tx_uniform_light[0]))+min_tx_uniform_light[0];
            }while(sel_min<min_ratio);
        }
        else if(!min_tx_dist.compare("um")){
            //utilization is drawn from uniform medium distribution
            if(max_tx<min_tx_uniform_medium[0]){
                cout<<"Error: max_tx is lower than min_tx"<<endl;
                exit(0);
            }
            high_min_bound=max_tx>(min_tx_uniform_medium[1]+1)?(min_tx_uniform_medium[1]+1):max_tx;
            do{
                sel_min=(rand()%(high_min_bound-min_tx_uniform_medium[0]))+min_tx_uniform_medium[0];
            }while(sel_min<min_ratio);
        }
        else if(!min_tx_dist.compare("uh")){
            //utilization is drawn from uniform heavy distribution
            if(max_tx<min_tx_uniform_heavy[0]){
                cout<<"Error: max_tx is lower than min_tx"<<endl;
                exit(0);
            }
            high_min_bound=max_tx>(min_tx_uniform_heavy[1]+1)?(min_tx_uniform_heavy[1]+1):max_tx;
            do{
                sel_min=(rand()%(high_min_bound-min_tx_uniform_heavy[0]))+min_tx_uniform_heavy[0];
            }while(sel_min<min_ratio);
        }
        return (double)sel_min/100.0;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in selectMinTx():"<<e.what()<<endl;
    }
}

vector<double> selectObj(string obj_dist,int total_no_obj,double por_len,double stm_inst){
    //Return a vector of selected objects according to total number of objects and object distribution
    //Selected number of objects should fit in selected por_len. stm_inst is the time for one read/write stm instruction
    //por_len should be greater or equal to stm_inst*no_objects
    try{
        int max_no_obj=(int)floor(por_len/stm_inst);     //maximum number of objects to fit in current portion length
        if(max_no_obj==0){
            cout<<"############ Error:selectObj()-> maximum number of objects is 0 ############"<<endl;
            cout<<"por_len:"<<por_len<<", stm_inst:"<<stm_inst<<endl;
            exit(0);
        }
        int obj_uniform_light[]={0,30};
        int obj_uniform_medium[]={30,50};
        int obj_uniform_heavy[]={50,100};
        int sel_no_obj=1;   //selected total number of objects, initialized to one object
        int obj_indx;     //Index of selected object from vector of total objects
        vector<double> total_objs;     //List of all objects
        vector<double> sel_objs;       //Holds selected objects

        /* Initialize a list of all objects to select desired objects from it */
        for(int i=0;i<total_no_obj;i++){
            total_objs.push_back(i);
        }

        /* Generate vector of desired objects according to object distribution and total number of objects */
        if(!obj_dist.compare("ul")){
            //uniform light
            do{
                //This loop guarantees that total_no_obj in this case is never 0
                sel_no_obj=ceil(((rand()%(obj_uniform_light[1]-obj_uniform_light[0]))+obj_uniform_light[0])*total_no_obj/100);
            }while(sel_no_obj==0);
        }
        else if(!obj_dist.compare("um")){
            //uniform medium
            sel_no_obj=ceil(((rand()%(obj_uniform_medium[1]-obj_uniform_medium[0]))+obj_uniform_medium[0])*total_no_obj/100);
        }
        else if(!obj_dist.compare("uh")){
            //uniform heavy
            sel_no_obj=ceil(((rand()%(obj_uniform_heavy[1]-obj_uniform_heavy[0]))+obj_uniform_heavy[0])*total_no_obj/100);
        }
        sel_no_obj=sel_no_obj>max_no_obj?max_no_obj:sel_no_obj;
        for(int i=0;i<sel_no_obj;i++){
            obj_indx=rand()%(total_objs.size());
            sel_objs.push_back(total_objs[obj_indx]);
            total_objs.erase(total_objs.begin()+obj_indx);
        }
        return sel_objs;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in selectObj():"<<e.what()<<endl;
    }
}

void checkPortions(vector<struct task_por> *portions){
    //Currently, checks no two consecuitive portions are of the same type
    try{
        if(portions->size()<2){
            //No need to check
            return;
        }
        for(int i=0;i<(portions->size())-1;i++){
            if(portions->at(i).por_type==portions->at(i+1).por_type){
                /* Two consecuitive portions of the same type. Change it */
                portions->at(i).por_len+=portions->at(i+1).por_len;
                portions->at(i).mod_por_len=portions->at(i).por_len;
                if(portions->at(i).por_obj.size()<portions->at(i+1).por_obj.size()){
                    portions->at(i).por_obj=portions->at(i+1).por_obj;
                }
                portions->erase(portions->begin()+i+1);
                i--;        //keep the current element for next comparison
            }
        }
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in checkPortions():"<<e.what()<<endl;
    }
}

void addPortions(double total_tx,double max_tx,double min_tx,double wcet,string obj_dist,int total_no_obj,vector<struct task_por> *portions,double stm_inst,double rt_inst){
    try{
        double non_tx_sum=0;     //Accumulated length of non-critical sections
        double tx_sum=0;         //Accumulated length of critical sections
        int max_non_tx_no;       //Holds maximum number of non-critical sections
        int tx_indx;             //Current index of critical section
        int non_tx_indx;         //Current index of non-critical section
        int max_non_tx_indx;        //Maximum index of non-critical section
        if(portions==NULL){
            cout<<"Error: addPortions()->portions vector is null";
            exit(0);
        }
        if(!portions->empty()){
            portions->clear();  //Be sure that portions is empty
        }


        /* Initially, choose portion length for critical sections */
        if(total_tx==1){
            //The whole task is a transaction or not
            struct task_por tmp_por;
            tmp_por.por_type=1;
            tmp_por.por_len=wcet;
            tmp_por.mod_por_len=tmp_por.por_len;
            tmp_por.por_obj=selectObj(obj_dist,total_no_obj,tmp_por.mod_por_len,stm_inst);
            portions->push_back(tmp_por);
        }
        else if(total_tx==0){
            //Task does not contain any critical sections
            struct task_por tmp_por;
            tmp_por.por_type=0;
            tmp_por.por_len=wcet;
            tmp_por.mod_por_len=tmp_por.por_len;
            tmp_por.por_obj.push_back(-1);
            portions->push_back(tmp_por);
        }
        else{
            //Task contains both critical and non-critical sections
            /* NOTE THAT THIS MEHTOD OF GENERATING PORTIONS MAY BE MODIFIED LATER */
            /* PORTIONS ARE GENERATED AS FOLLOWS:
             * 1- ALL TRANSACTIONAL PORTIONS ARE PRODUCED.
             * 2- TASK STARTS WITH A TRANSACTIONAL PORTION.
             * 3- NUMBER OF NON-CRITICAL SECTIONS AT MOST EQUALS NUMBER OF CRITICAL SECTIONS.
             * POINTS 2 AND 3 CAN BE MODIFIED SUCH THAT THE FIRST PORTION IS RANDOMLY CHOSEN AS
             * A CRITICAL OR NON-CRITICAL SECTION, AND TOTAL NUMBER OF ONE TYPE OF PORTIONS CAN
             * MOSTLY INCREASE OVER THE OTHER TYPE BY 1 */

            /* Initially, generate all transactional portions */
            struct task_por tmp_por;
            tx_indx=0;
            do{
                tmp_por.por_type=1;
		if(max_tx==min_tx){
			tmp_por.por_len=min_tx*wcet;
		}
		else{
	                tmp_por.por_len=(fmod((double)rand(),(max_tx-min_tx)*100)/100.0+min_tx)*wcet;
		}
                if(tmp_por.por_len<stm_inst){
                    tmp_por.por_len=stm_inst;
                }
                tx_sum+=tmp_por.por_len;
                tmp_por.mod_por_len=tmp_por.por_len;
                tmp_por.por_obj.clear();
                tmp_por.por_obj=selectObj(obj_dist,total_no_obj,tmp_por.por_len,stm_inst);
                tx_indx++;
                portions->push_back(tmp_por);
            }while(tx_sum<=(wcet*total_tx) && wcet*total_tx-tx_sum>=stm_inst && tx_indx<=(int)floor((double)total_tx/min_tx));
            //remove the last portion that broke the loop. This happens only for the 1st and 3d conditions
	    if((tx_sum>(wcet*total_tx)) && (tx_indx>(int)floor((double)total_tx/min_tx))){
	            portions->erase((portions->end())-1);
	    }
            
            /* Now, generate non-critical sections */
            max_non_tx_no=portions->size()==1?1:portions->size()-1;  //Used to limit length of each non-critical section
                                                                   //If there's only 1 critical section,
                                                                   //then at most 1 non-critical section
            max_non_tx_indx=2*portions->size()-1;      //Maximum index of non-critical sections
            non_tx_indx=1;  //According to generation algorithm, non-critical sections start at index 1
            while(non_tx_indx<=max_non_tx_indx){
                tmp_por.por_type=0;
                tmp_por.por_obj.clear();
                tmp_por.por_obj.push_back(-1);
                if(non_tx_indx==max_non_tx_indx){
                    //Reached last non-critical section
                    tmp_por.por_len=wcet*(1-total_tx)-non_tx_sum;
                }
                else{
                    //Still more non-critical sections to add
                    /* The non-critical length divided over at most max_non_tx_no+1
                     But it is divided over max_non_tx_no because number of non-critical
                     sections can either be max_non_tx_no or max_non_tx_no+1 */
                    tmp_por.por_len=fmod((double)rand(),wcet*(1-total_tx)/max_non_tx_no);
                }
                //por_len cannot be lower than rt_inst
                if(tmp_por.por_len<rt_inst){
                    /* Check if selected length is less than rt_inst */
                    tmp_por.por_len=rt_inst;
                }
                non_tx_sum+=tmp_por.por_len;
                portions->insert(portions->begin()+non_tx_indx,tmp_por);
                non_tx_indx+=2;
            }
        }
        checkPortions(portions);
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in addPortions():"<<e.what()<<endl;
    }
}

void modifyPortions(string data_set_host,string data_set,string user_name,string user_pass,double stm_inst,double rt_inst,bool add){
    //Modifies portions not meeting requirements
    //If "add" is true, then function adds missed portions, otherwise, it fixes them
    try{
        if(!initialized){
            initDB(data_set_host,data_set,user_name,user_pass);
        }
        sql::ResultSet *dataset_res;
        sql::ResultSet *task_res;
        sql::ResultSet *por_res;
        stringstream ss;
        int dataset,task,total_no_obj,por_type,por_id;
        double total_tx,max_tx,min_tx,wcet,por_len,period;
        string obj_dist;
        stmt=con->createStatement();
        ss<<"select * from datasets";
		dataset_res=stmt->executeQuery(ss.str());
        while(dataset_res->next()){
            /**///cout<<"************ DATATSET "<<dataset_res->getInt("id")<<" ************"<<endl;
            dataset=dataset_res->getInt("id");
            /**///cout<<"dataset_id:"<<dataset<<endl;
            total_tx=dataset_res->getDouble("total_tx");
            /**///cout<<"total_tx:"<<total_tx<<endl;
            max_tx=dataset_res->getDouble("max_tx");
            /**///cout<<"max_tx:"<<max_tx<<endl;
            min_tx=dataset_res->getDouble("min_tx");
            /**///cout<<"min_tx:"<<min_tx<<endl;
            total_no_obj=atoi((dataset_res->getString("total_no_obj")).c_str());
            /**///cout<<"total_no_obj:"<<total_no_obj<<endl;
            obj_dist=dataset_res->getString("no_obj_tx_dis");
            /**///cout<<"obj_dist:"<<obj_dist<<endl;
            ss.str("");
            ss<<"select id, wcet, period from tasks where dataset="<<dataset;
            task_res=stmt->executeQuery(ss.str());
            while(task_res->next()){
                /**///cout<<"************* TASK "<<task_res->getInt("id")<<" ***************"<<endl;
                task=task_res->getInt("id");
                wcet=task_res->getDouble("wcet");
                period=task_res->getDouble("period");
                ss.str("");
                ss<<"select * from task_st where dataset="<<dataset<<" and task="<<task;
                por_res=stmt->executeQuery(ss.str());
                if(add && !(por_res->next())){
                    //There're no portions for the specified dataset and task
                    //Add portions for this dataset and task
                    /* Generate task structure for current task in task_st table */
                    /**/cout<<"dataset: "<<dataset<<", task: "<<task<<endl;
                    vector<struct task_por> portions;     //selected portion length for all portions of current task
                    addPortions(total_tx,max_tx,min_tx,wcet,obj_dist,total_no_obj,&portions,stm_inst,rt_inst);

                    /* Insert task structure for current task in task_st table */
                    for(int k=0;k<portions.size();k++){
                        stmt=con->createStatement();
                        ss.str("");
                        ss<<"INSERT INTO `test`.`task_st`(`dataset`,`task`,`id`,`por_type`,`por_len`,`objs`) VALUES(";
                        ss<<dataset<<","<<task<<","<<k<<","<<portions[k].por_type<<","<<portions[k].por_len;
                        // Insert list of objects for current portion
                        ss<<",'";
                        for(int h=0;h<portions[k].por_obj.size();h++){
                            ss<<portions[k].por_obj[h];
                            if(h!=portions[k].por_obj.size()-1){
                                ss<<",";
                            }
                            else{
                                ss<<"')";
                            }
                        }
                        stmt->execute(ss.str());
                    }
                }
                else if(!add){
                    //Found portions. Check them and modify if necessary
                    while(por_res->next()){
                        /**/cout<<"************ PORTION "<<por_res->getInt("id")<<" ************"<<endl;
                        por_id=por_res->getInt("id");
                        por_len=por_res->getDouble("por_len");
                        por_type=por_res->getInt("por_type");
                        if(por_type==0 && por_len<rt_inst){
                            ss.str("");
                            ss<<"update task_st set por_len="<<rt_inst<<" where dataset="<<dataset;
                            ss<<" and task="<<task<<" and id="<<por_id;
                            stmt->executeUpdate(ss.str());
                        }
                        else if(por_type==1 && ((por_len/wcet)<(min_tx-0.01) || (por_len/wcet)>(max_tx+0.01))){
                            //this task needs modification
                            vector<struct task_por> portions;
                            ss.str("");
                            ss<<"delete from task_st where dataset="<<dataset<<" and task="<<task;
                            stmt->executeUpdate(ss.str());
                            addPortions(total_tx,max_tx,min_tx,wcet,obj_dist,total_no_obj,&portions,stm_inst,rt_inst);
                            /* Insert task structure for current task in task_st table */
                            for(int k=0;k<portions.size();k++){
                                ss.str("");
                                ss<<"INSERT INTO `test`.`task_st`(`dataset`,`task`,`id`,`por_type`,`por_len`,`objs`) VALUES(";
                                ss<<dataset<<","<<task<<","<<k<<","<<portions[k].por_type<<","<<portions[k].por_len;
                                // Insert list of objects for current portion
                                ss<<",'";
                                for(int h=0;h<portions[k].por_obj.size();h++){
                                    ss<<portions[k].por_obj[h];
                                    if(h!=portions[k].por_obj.size()-1){
                                        ss<<",";
                                    }
                                    else{
                                        ss<<"')";
                                    }
                                }
                                stmt->execute(ss.str());
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in modifyPortions():"<<e.what()<<endl;
    }
}

void checkObjs(string data_set_host,string data_set,string user_name,string user_pass,double stm_inst,double rt_inst){
    //checks that number of objects in each portion meets specified constraints
    try{
        if(!initialized){
            initDB(data_set_host,data_set,user_name,user_pass);
        }
        sql::ResultSet *dataset_res;
        sql::ResultSet *task_res;
        sql::ResultSet *por_res;
        vector<double> objs;
        stringstream ss;
        int dataset,task,total_no_obj,por_type,por_id;
        double por_len;
        string obj_dist;
        stmt=con->createStatement();
        ss<<"select id, total_no_obj, no_obj_tx_dis from datasets where id>="<<14075;
        dataset_res=stmt->executeQuery(ss.str());
        while(dataset_res->next()){
            dataset=dataset_res->getInt("id");
            total_no_obj=atoi((dataset_res->getString("total_no_obj")).c_str());
            obj_dist=dataset_res->getString("no_obj_tx_dis");
            ss.str("");
            ss<<"select id from tasks where dataset="<<dataset;
            task_res=stmt->executeQuery(ss.str());
            while(task_res->next()){
                task=task_res->getInt("id");
                ss.str("");
                ss<<"select * from task_st where por_type=1 and dataset="<<dataset<<" and task="<<task;
                por_res=stmt->executeQuery(ss.str());
                while(por_res->next()){
                    por_id=por_res->getInt("id");
                    por_len=por_res->getDouble("por_len");
                    por_type=por_res->getInt("por_type");
                    objs=extractObj(por_res->getString("objs"));
                    if(stm_inst*objs.size()>por_len){
                        cout<<cout<<"DATASET:"<<dataset<<", TASK:"<<task<<", POR:"<<por_id<<", BIG:"<<(por_len*objs.size())<<endl;
                    }
                    else if(!obj_dist.compare("ul")){
                        if(!(objs.size()/total_no_obj<=0.3 || ceil(por_len/stm_inst)>objs.size())){
                            cout<<"DATASET:"<<dataset<<", TASK:"<<task<<", POR:"<<por_id<<", RATIO:"<<(objs.size()/total_no_obj)<<endl;
                        }
                    }
                    else if(!obj_dist.compare("um")){
                        if(!((objs.size()/total_no_obj>=0.3 && objs.size()/total_no_obj<=0.5) || ceil(por_len/stm_inst)>objs.size())){
                            cout<<"DATASET:"<<dataset<<", TASK:"<<task<<", POR:"<<por_id<<", RATIO:"<<(objs.size()/total_no_obj)<<endl;
                        }
                    }
                    else if(!obj_dist.compare("uh")){
                        if(!((objs.size()/total_no_obj>=0.5 && objs.size()/total_no_obj<=1) || ceil(por_len/stm_inst)>objs.size())){
                            cout<<"DATASET:"<<dataset<<", TASK:"<<task<<", POR:"<<por_id<<", RATIO:"<<(objs.size()/total_no_obj)<<endl;
                        }
                    }
                }
            }
        }
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in check_objs():"<<e.what()<<endl;
    }    
}

void add_dataset(string data_set_host,string data_set,string user_name,string user_pass,double util_cap,string util_dist,double no_datasets,string total_dist,string max_dist,string min_dist,string n_obj,string n_obj_dist,double stm_inst,double rt_inst){
    //Adds a number of datasets
    try{
        double util;    //selected util for current task
        double total_util;    //Accumulated utilization for tasks in current taskset
        double total_tx,max_tx,min_tx;  //transaction parameters
        double tmp_wcet;        //temporary selected wcet
        int dataset_id; //id for current generated dataset
        stringstream ss;        //required sql statement
        double sel_hyperperiod; //selected hyperperiod for current dataset
        sql::ResultSet *res;
        
        /* Initialize connection to DB and get the id of the last added dataset */
        if(!initialized){
            initDB(data_set_host,data_set,user_name,user_pass);
        }
        stmt=con->createStatement();
        res=stmt->executeQuery("SELECT MAX(id) FROM datasets");
        if(res->next()){
            //dataset already contains previous datasets
            dataset_id=res->getInt("MAX(id)");
        }
        else{
            //First dataset inserted into datasets table
            dataset_id=-1;
        }
        
        /* Create the required number of datasets */
        for(int i=0;i<no_datasets;i++){
            //loop until completing required number of tasksets for current util_cap
            total_util=0;       //Reset to 0 for each generation of a taskset
            dataset_id++;       //Increment dataset id
            //Parameters for new task
            vector<double> period,wcet,init_period;     //init_period holds all available deviosrs
                                                        //devisors for hyperperiod within period limits
            do{
                sel_hyperperiod=detHyperPeriod(0.1,10000000);
            }while((init_period=selectPeriod(sel_hyperperiod)).empty());
            
            while(total_util<util_cap){
                //loops through tasks of current taskset until reaching util_cap
                period.push_back(init_period[rand()%(init_period.size())]);
                util=selectUtil(util_dist,stm_inst,rt_inst,period.back());
                if(total_util+util>util_cap){
                    //Reached end of generated tasks
                    //util=util_cap-total_util;
                    period.erase(period.end()-1);
                    break;
                }
                tmp_wcet=util*(period.back());
                if(tmp_wcet<stm_inst || tmp_wcet<rt_inst){
                    /* wcet should be >= stm_inst */
                    if(wcet.empty()){
                        /* if wcet is empty, then modify tmp_wcet to max(rt_inst,stm_inst) and add push it into wcet */
                        /* if wect is not empty, just add tmp_wcet to the last element in wcet */
                        wcet.push_back(0);
                        tmp_wcet=rt_inst>stm_inst?rt_inst:stm_inst;
                    }
                    (wcet.back())+=tmp_wcet;
                    util=tmp_wcet/(period.back());
                    total_util+=util;
                    continue;
                }
                util=tmp_wcet/(period.back());
                total_util+=util;
                wcet.push_back(tmp_wcet);
                if(wcet.back()<stm_inst){
                    cout<<"Error:add_dataset()-> wcet is lower than stm_inst"<<endl;
                    cout<<"wcet:"<<wcet.back()<<", stm_inst:"<<stm_inst<<endl;
                    exit(0);
                }
            }
            total_tx=selectTotalTx(total_dist,stm_inst,wcet.back());
            max_tx=selectMaxTx(max_dist,total_tx,stm_inst,wcet.back());
            min_tx=selectMinTx(min_dist,max_tx,stm_inst,wcet.back());
            /* create SQL statement to insert new dataset into datasets table */
            ss.str("");
            ss<<"INSERT INTO `test`.`datasets` (`id`,`max_tx`,`max_tx_dis`,`min_tx`,`min_tx_dis`,";
            ss<<"`no_obj_tx_dis`,`no_tasks`,`total_no_obj`,`total_tx`,`total_tx_dis`,`u_cap`";
            ss<<",`u_i_dist`) VALUES("<<dataset_id<<","<<max_tx<<",'"<<max_dist<<"',"<<min_tx<<",'"<<min_dist<<"','";
            ss<<n_obj_dist<<"',"<<(period.size())<<",'"<<n_obj<<"',"<<total_tx<<",'"<<total_dist<<"',";
            ss<<util_cap<<",'"<<util_dist<<"')";

            stmt=con->createStatement();
            stmt->execute(ss.str());

            /* Insert tasks corresponding the created dataset into tasks table */
            for(int j=0;j<period.size();j++){
                stmt=con->createStatement();
                ss.str("");
                ss<<"INSERT INTO `test`.`tasks`(`dataset`,`id`,`deadline`,`period`,`wcet`)";
                ss<<" VALUES(";
                ss<<dataset_id<<","<<j<<","<<period[j]<<","<<period[j]<<","<<wcet[j]<<")";
                
                stmt->execute(ss.str());
                
                /* Generate task structure for current task in task_st table */
                vector<struct task_por> portions;     //selected portion length for all portions of current task
                addPortions(total_tx,max_tx,min_tx,wcet[j],n_obj_dist,atof(n_obj.data()),&portions,stm_inst,rt_inst);

                /* Insert task structure for current task in task_st table */
                for(int k=0;k<portions.size();k++){
                    stmt=con->createStatement();
                    ss.str("");
                    ss<<"INSERT INTO `test`.`task_st`(`dataset`,`task`,`id`,`por_type`,`por_len`,`objs`) VALUES(";
                    ss<<dataset_id<<","<<j<<","<<k<<","<<portions[k].por_type<<","<<portions[k].por_len;
                    // Insert list of objects for current portion
                    ss<<",'";
                    for(int h=0;h<portions[k].por_obj.size();h++){
                        ss<<portions[k].por_obj[h];
                        if(h!=portions[k].por_obj.size()-1){
                            ss<<",";
                        }
                        else{
                            ss<<"')";
                        }
                    }
                    stmt->execute(ss.str());
                }
            }
        }
        delete res;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception &e){
        cout<<"Exception in add_dataset():"<<e.what()<<endl;
    }    
}

void fixDatasets(string data_set_host,string data_set,string user_name,string user_pass,double stm_inst,double rt_inst,int no_data_set){
    //If number of datasets for specific criteria are less than no_data_set, add additional data sets
    try{
        if(!initialized){
            initDB(data_set_host,data_set,user_name,user_pass);
        }
        sql::ResultSet *mis_res;
        int no_datasets;
        string total_tx_dis,max_tx_dis,min_tx_dis,total_no_obj,no_obj_tx_dis,u_i_dist;
        double u_cap;
        stringstream ss;
        stmt=con->createStatement();
        ss<<"select total_tx_dis, max_tx_dis, min_tx_dis, total_no_obj, no_obj_tx_dis, u_cap, u_i_dist, count(*) from datasets group by total_tx_dis, max_tx_dis, min_tx_dis, total_no_obj, no_obj_tx_dis, u_cap, u_i_dist"<<endl;
        mis_res=stmt->executeQuery(ss.str());
        while(mis_res->next()){
            no_datasets=mis_res->getInt("count(*)");
            if(no_datasets<no_data_set){
                //add additional datasets with the same parameters
                total_tx_dis=mis_res->getString("total_tx_dis");
                max_tx_dis=mis_res->getString("max_tx_dis");
                min_tx_dis=mis_res->getString("min_tx_dis");
                total_no_obj=mis_res->getString("total_no_obj");
                no_obj_tx_dis=mis_res->getString("no_obj_tx_dis");
                u_cap=mis_res->getDouble("u_cap");
                u_i_dist=mis_res->getString("u_i_dist");
/* tmp step */cout<<"total:"<<total_tx_dis<<", max:"<<max_tx_dis<<", min:"<<min_tx_dis<<", no_obj:"<<total_no_obj<<", obj_dis:"<<no_obj_tx_dis<<", u_cap:"<<u_cap<<", u_i_dis:"<<u_i_dist<<endl;
                add_dataset(data_set_host,data_set,user_name,user_pass,u_cap,u_i_dist,no_data_set-no_datasets,
                        total_tx_dis,max_tx_dis,min_tx_dis,total_no_obj,no_obj_tx_dis,stm_inst,rt_inst);
            }
        }
        delete mis_res;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in fixDatasets():"<<e.what()<<endl;
    }
}

vector<double> extractObj(string objs){
    //Creates a vector of objects from a CSV string
    try{
        vector<double> ext_objs;
        int indx=0;
        int tmp_indx=0;
        vector<double> tmp_obj_no;
        while((indx=objs.find(",",indx))!=string::npos){
            ext_objs.push_back(atof((objs.substr(tmp_indx,indx-tmp_indx)).data()));
            tmp_indx=++indx;
        }
        ext_objs.push_back(atof((objs.substr(tmp_indx)).data()));
        return ext_objs;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in extractObj():"<<e.what()<<endl;
    }
}

vector<struct task_por> readTaskPor(int dataset_id,int task_no,double sh_lev,int transitive){
    //Reads different portions of a single task
    try{
        if(!initialized){
            cout<<"Error: Database is not connected."<<endl;
            exit(0);
        }
        stringstream ss;
        sql::ResultSet *por_res;
        vector<struct task_por> portions;   //resultant vector of tasks' portions
        struct task_por cur_por;            //current read portion of current task
        ss<<"select * from task_st where dataset="<<dataset_id<<" and task="<<task_no<<" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive;
        stmt=con->createStatement();
        por_res=stmt->executeQuery(ss.str());
        while(por_res->next()){
            cur_por.por_type=por_res->getInt("por_type");
            cur_por.por_len=por_res->getDouble("por_len");
            cur_por.mod_por_len=cur_por.por_len;
            cur_por.por_obj=extractObj(por_res->getString("objs"));
            portions.push_back(cur_por);
        }
        delete por_res;
        return portions;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in readTaskPor():"<<e.what()<<endl;
    }
}

vector<struct rt_task> readTaskSet(string data_set_host,string data_set,string user_name,string user_pass,int dataset_id,double sh_lev,int transitive){
    //Reads tasks's information from a specific taskset file
    try{
        if(!initialized){
            initDB(data_set_host,data_set,user_name,user_pass);
        }
        sql::ResultSet *task_res;
        struct rt_task cur_task;     //current task
        vector<struct rt_task> dataset_tasks;     //Resultant vector of tasks
        int task_id;        //id of current examined task
        stringstream ss;
        ss<<"select * from tasks where dataset="<<dataset_id;
        stmt=con->createStatement();
        task_res=stmt->executeQuery(ss.str());
        while(task_res->next()){
            //Traverse through tasks of current taskset
            cur_task.deadline=task_res->getDouble("deadline");
            cur_task.period=task_res->getDouble("period");
            cur_task.wcet=task_res->getDouble("wcet");
            cur_task.mod_wcet=cur_task.wcet;
            cur_task.processors=extractProc(task_res->getString("proc"));
            task_id=task_res->getInt("id");
            cur_task.portions=readTaskPor(dataset_id,task_id,sh_lev,transitive);

            dataset_tasks.push_back(cur_task);
        }
        delete task_res;
        return dataset_tasks;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception i nreadTaskSet():"<<e.what()<<endl;
    }
}

int getUtilCap(string data_set_host,string data_set,string user_name,string user_pass,int dataset_id){
    //Extracts utilization cap for specified dataset
    try{
        if(!initialized){
            initDB(data_set_host,data_set,user_name,user_pass);
        }
        stringstream ss;
        sql::ResultSet *util_res;
        stmt=con->createStatement();
        ss<<"select u_cap from datasets where id="<<dataset_id;
        util_res=stmt->executeQuery(ss.str());
	util_res->first();
        return util_res->getInt("u_cap");
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in getUtilCap():"<<e.what()<<endl;
    }
}

vector<int> extractDataSet(string data_set_host,string data_set,string user_name,string user_pass,double util_cap,string util_dist,string total_dist,double total_tx,string max_dist,double max_tx,string min_dist,double min_tx,double n_obj,string n_obj_dist){
    //Return IDs for all datasets that meet requirements
    //If total_tx,max_tx or min_tx is not -1, attach it to the requirements
    try{
        if(!initialized){
            initDB(data_set_host,data_set,user_name,user_pass);
        }
        sql::ResultSet *dataset_res;
        vector<int> dataset_ids;    //Resultant vector of datasets' ids
        stringstream ss;
        ss<<"select * from datasets where total_tx_dis='"<<total_dist;
        ss<<"' and max_tx_dis='"<<max_dist<<"' and min_tx_dis='"<<min_dist;
        ss<<"' and total_no_obj="<<n_obj<<" and no_obj_tx_dis='"<<n_obj_dist;
        ss<<"' and u_cap="<<util_cap<<" and u_i_dist='"<<util_dist<<"'";
        if(total_tx!=-1){
            ss<<" and total_tx="<<total_tx;
        }
        if(max_tx!=-1){
            ss<<" and max_tx="<<max_tx;
        }
        if(min_tx!=-1){
            ss<<" and min_tx="<<min_tx;
        }
        stmt=con->createStatement();
        dataset_res=stmt->executeQuery(ss.str());
        while(dataset_res->next()){
            dataset_ids.push_back(dataset_res->getInt("id"));
        }
        delete dataset_res;
        return dataset_ids;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in extractDataSet():"<<e.what()<<endl;
    }
}

bool exists(int dataset_id){
    //checks whether dataset with the specified id exists or not
    try{
        if(!initialized){
            cout<<"Error: Database is not connected"<<endl;
            exit(0);
        }
        stringstream ss;
        sql::ResultSet *data_res;
        ss<<"";
        stmt=con->createStatement();
        ss<<"select * from datasets where id="<<dataset_id;
        data_res=stmt->executeQuery(ss.str());
        if(data_res->next()){
            //dataset exists
            return true;
        }
        else{
            return false;
        }
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in exists():"<<e.what()<<endl;
    }
}

int detHyperPeriod(double per,int threshold){
    //threshold is maximum value for hyperperiod
    //per*threshold is minimum value for hyperperiod
    try{
        return (rand()%(int)(threshold*(1-per)))+(int)(threshold*per);
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in detHyperPeriod():"<<e.what()<<endl;
    }
}

int calcHyperPeriod(string data_set_host,string data_set,string user_name,string user_pass,int dataset_id){
    //calculates hyperperiod for a given taskset
    try{
        if(!initialized){
            initDB(data_set_host,data_set,user_name,user_pass);
        }
        stringstream ss;
        sql::ResultSet *task_res;
        ss<<"select period from tasks where dataset="<<dataset_id;
        stmt=con->createStatement();
        task_res=stmt->executeQuery(ss.str());
        int hyperperiod=1;
        while(task_res->next()){
            hyperperiod=boost::math::lcm(hyperperiod,(int)(task_res->getDouble("period")));
        }
        return hyperperiod;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in calcHyperPeriod():"<<e.what()<<endl;
    }
}

vector<int> calcHyperPeriod(string data_set_host,string data_set,string user_name,string user_pass){
    //calculates hyperperiod for all datasets
    try{
        if(!initialized){
            initDB(data_set_host,data_set,user_name,user_pass);
        }
        stringstream ss;
        sql::ResultSet *dataset_res;
        vector<int> hyperperiods;
        int dataset_id;
        ss<<"select id from datasets";
        stmt=con->createStatement();
        dataset_res=stmt->executeQuery(ss.str());
        while(dataset_res->next()){
            dataset_id=dataset_res->getInt("id");
            hyperperiods.push_back(calcHyperPeriod(data_set_host,data_set,user_name,user_pass,dataset_id));
        }
        return hyperperiods;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in calcHyeperPeriod() for all datasets:"<<e.what()<<endl;
    }
}

vector<int> extractProc(string proc){
    //Extracts available processor for current task if not all
    //Note that "proc" values is "all" or CSV of processor numbers
    try{
        vector<int> processors;   //Resultant vector of assigned processors
        if(!proc.compare("all") || proc.empty() || !proc.compare("NULL")){
            //Task can run on all processors
            processors.push_back(-1);
        }
        else{
            //Task can run only on specified processors
            int indx=0;
            int tmp_indx=0;
            while((indx=proc.find(",",indx))!=string::npos){
                processors.push_back(atoi((proc.substr(tmp_indx,indx-tmp_indx)).data()));
                tmp_indx=++indx;
            }
            processors.push_back(atoi((proc.substr(tmp_indx)).data()));
        }
	return processors;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in extractProc():"<<e.what()<<endl;
    }
}

void setResults(int dataset_id,vector<vector<vector<unsigned long long> > > total_result,string sync_alg,string sch,int cp_enable,double sh_lev,int transitive,int calibration){
    //stores results into database
    //Note that this function depends on the final result format produce by Sched_Test_App
    //which is in the form of "vector<vector<vector<unsigned long long> > >
    try{
        if(!initialized){
            cout<<"Error: database is not connected"<<endl;
            exit(0);
        }
        int task_id;        //Id of current task
        int exp_no;         //experiment number for current dataset. It is fixed for one run of all datasets
        int indx=0;         //Index of current result in total_result. It might differ from
                            //task_id, because the latter might start at some number other than 0
        sql::ResultSet *task_res;   //Holds tasks of current dataset
        sql::ResultSet *exp_res;
        stringstream ss;
        ss.str("");
        stmt=con->createStatement();
        ss<<"select max(exp_no) from sh_results where dataset="<<dataset_id;
        exp_res=stmt->executeQuery(ss.str());
        if(exp_res->next()){
            //results already contains data
            exp_no=(exp_res->getInt("max(exp_no)"))+1;
        }
        else{
            //no previous data in results table
            exp_no=0;
        }
        ss.str("");
        ss<<"select * from tasks where dataset="<<dataset_id;
        task_res=stmt->executeQuery(ss.str());
        while(task_res->next()){
            task_id=task_res->getInt("id");
            for(int k=0;k<total_result[indx][0].size();k++){
                ss.str("");
                ss<<"INSERT INTO `test`.`sh_results` (`instance`,`dataset`,`task`,`commit`,`abr_no`,`abr_dur`,";
                ss<<"`start`,`deadline`,`end`,`response`,`exp_no`,`sync`,`sch`,`cp_enable`,`obj_sh`,`obj_trns_retry`,`calibration`) VALUES(";
                ss<<total_result[indx][0][k]<<","<<dataset_id<<","<<task_id<<","<<total_result[indx][1][k]<<",";
                ss<<total_result[indx][2][k]<<","<<total_result[indx][3][k]<<","<<total_result[indx][4][k]<<",";
                ss<<total_result[indx][5][k]<<","<<total_result[indx][6][k]<<","<<total_result[indx][7][k]<<","<<exp_no<<",\""<<sync_alg<<"\",\""<<sch<<"\","<<cp_enable<<","<<sh_lev<<","<<transitive<<","<<calibration<<")";
                stmt->executeUpdate(ss.str());
            }
            indx++;
        }
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in setRestults():"<<e.what()<<endl;
    }
}

void delAll(){
    //Remove all data in all tables. Useful in case of invalid inputs
    try{
        stmt=con->createStatement();
        stringstream ss;
        ss.str("");
        ss<<"delete from task_st";
        stmt->executeUpdate(ss.str());
        ss.str("");
        ss<<"delete from tasks";
        stmt->executeUpdate(ss.str());
        ss.str("");
        ss<<"delete from datasets";
        stmt->executeUpdate(ss.str());
        delete stmt;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in delAll():"<<e.what()<<endl;
    }
}
/************************ DEBUG FUNCTIONS ****************************/
void debug_getopt(string operation,string cm,double u,double run_time,double proc_num,double psi,
        string total_tx,string max_tx,string min_tx,string n_obj_dis,double n_obj,double n_dataset,
        string dataset,string dataset_host,string dataset_user,string dataset_pass){
    //Check getopt_long operation
    try{
        cout<<"Operation: "<<operation<<endl;
        cout<<"CM: "<<cm<<endl;
        cout<<"Utilization cap: "<<u<<endl;
        cout<<"Hyper period: "<<run_time<<endl;
        cout<<"Number of processors: "<<proc_num<<endl;
        cout<<"Psi: "<<psi<<endl;
        cout<<"Total Tx distribution: "<<total_tx<<endl;
        cout<<"Maximum Tx distribution: "<<max_tx<<endl;
        cout<<"Minimum Tx distribution: "<<min_tx<<endl;
        cout<<"Number of objects distribution: "<<n_obj_dis<<endl;
        cout<<"Number of objects: "<<n_obj<<endl;
        cout<<"Number of data sets: "<<n_dataset<<endl;
        cout<<"Dataset name: "<<dataset<<endl;
        cout<<"Dataset Host: "<<dataset_host<<endl;
        cout<<"Dataset User: "<<dataset_user<<endl;
        cout<<"Dataset Password: "<<dataset_pass<<endl;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in debug_getopt():"<<e.what()<<endl;
    }    
}

void remTasks(string data_set_host,string data_set,string user_name,string user_pass){
    //removes tasks that do not meet requirements
    try{
        if(!initialized){
            initDB(data_set_host,data_set,user_name,user_pass);
        }
        sql::ResultSet *cnt_res;
        sql::ResultSet *task_res;
        double cal_u;      //calculated utilization
        stmt=con->createStatement();
        stringstream ss;
        ss<<"select tasks.dataset, tasks.id, datasets.u_i_dist, datasets.no_tasks, tasks.period, tasks.wcet from tasks";
        ss<<" join datasets on datasets.id=tasks.dataset order by tasks.dataset, tasks.id";
        cnt_res=stmt->executeQuery(ss.str());
        while(cnt_res->next()){
            cal_u=cnt_res->getDouble("wcet")/cnt_res->getDouble("period");
            if(!(cnt_res->getString("u_i_dist")).compare("ul")){
                //uniform light utilization distribution
                if(cal_u<=0.34){
                    //correct utilization
                }
                else{
                    ss.str("");
                    ss<<"delete from tasks where dataset="<<(cnt_res->getInt("dataset"));
                    ss<<" and id="<<(cnt_res->getInt("id"));
                    /**/cout<<ss.str()<<endl;
                    stmt->executeUpdate(ss.str());
                    ss.str("");
                    ss<<"delete from task_st where dataset="<<(cnt_res->getInt("dataset"));
                    ss<<" and id="<<(cnt_res->getInt("id"));
                    /**/cout<<ss.str()<<endl;
                    stmt->executeUpdate(ss.str());
                    ss.str("");
                    ss<<"select count(*) from tasks where dataset="<<(cnt_res->getInt("dataset"));
                    /**/cout<<ss.str()<<endl;
                    task_res=stmt->executeQuery(ss.str());
                    ss.str("");
                    ss<<"update datasets set no_tasks="<<(task_res->getInt("count(*)"));
                    ss<<" where id="<<(cnt_res->getInt("dataset"));
                    /**/cout<<ss.str()<<endl;
                    stmt->executeUpdate(ss.str());
                }
            }
            else if(!(cnt_res->getString("u_i_dist")).compare("um")){
                //uniform medium utilization distribution
                if(cal_u>=0.34 && cal_u<=0.67){
                    //correct utilization
                }
                else{
                    ss.str("");
                    ss<<"delete from tasks where dataset="<<(cnt_res->getInt("dataset"));
                    ss<<" and id="<<(cnt_res->getInt("id"));
                    /**/cout<<ss.str()<<endl;
                    stmt->executeUpdate(ss.str());
                    ss.str("");
                    ss<<"delete from task_st where dataset="<<(cnt_res->getInt("dataset"));
                    ss<<" and id="<<(cnt_res->getInt("id"));
                    /**/cout<<ss.str()<<endl;
                    stmt->executeUpdate(ss.str());
                    ss.str("");
                    ss<<"select count(*) from tasks where dataset="<<(cnt_res->getInt("dataset"));
                    /**/cout<<ss.str()<<endl;
                    task_res=stmt->executeQuery(ss.str());
                    ss.str("");
                    ss<<"update datasets set no_tasks="<<(task_res->getInt("count(*)"));
                    ss<<" where id="<<(cnt_res->getInt("dataset"));
                    /**/cout<<ss.str()<<endl;
                    stmt->executeUpdate(ss.str());
                }
            }
            else if(!(cnt_res->getString("u_i_dist")).compare("uh")){
                //uniform medium utilization distribution
                if(cal_u>=0.67){
                    //correct utilization
                }
                else{
                    ss.str("");
                    ss<<"delete from tasks where dataset="<<(cnt_res->getInt("dataset"));
                    ss<<" and id="<<(cnt_res->getInt("id"));
                    /**/cout<<ss.str()<<endl;
                    stmt->executeUpdate(ss.str());
                    ss.str("");
                    ss<<"delete from task_st where dataset="<<(cnt_res->getInt("dataset"));
                    ss<<" and id="<<(cnt_res->getInt("id"));
                    /**/cout<<ss.str()<<endl;
                    stmt->executeUpdate(ss.str());
                    ss.str("");
                    ss<<"select count(*) from tasks where dataset="<<(cnt_res->getInt("dataset"));
                    /**/cout<<ss.str()<<endl;
                    task_res=stmt->executeQuery(ss.str());
                    ss.str("");
                    ss<<"update datasets set no_tasks="<<(task_res->getInt("count(*)"));
                    ss<<" where id="<<(cnt_res->getInt("dataset"));
                    /**/cout<<ss.str()<<endl;
                    stmt->executeUpdate(ss.str());
                }
            }
        }
        delete cnt_res;
        delete task_res;
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in remTasks():"<<e.what()<<endl;
    }
}

void fixNoTasks(string data_set_host,string data_set,string user_name,string user_pass){
    //fixes number of tasks in each dataset according to already existing number of tasks
    try{
        if(!initialized){
        initDB(data_set_host,data_set,user_name,user_pass);
        }
        sql::ResultSet *task_res;
        sql::ResultSet *dataset_res;
        stmt=con->createStatement();
        stringstream ss;
        ss.str("");
        ss<<"select id from datasets";
        dataset_res=stmt->executeQuery(ss.str());
        while(dataset_res->next()){
            ss.str("");
            ss<<"select count(*) from tasks where dataset="<<(dataset_res->getInt("id"));
            task_res=stmt->executeQuery(ss.str());
            ss.str("");
            ss<<"update datasets set no_tasks="<<(task_res->getInt("count(*)"));
            ss<<" where id="<<(dataset_res->getInt("id"));
            stmt->executeUpdate(ss.str());
        }
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in fixNoTasks():"<<e.what()<<endl;
    }
}

vector<double> findDevisors(int devidend,int low_limit, int hi_limit){
    //Finds all devisors of devidend between low_lim and hi_limit
    vector<double> devisors;
    int deul;   //=devidend/devisor
    if(low_limit<=0){
        cout<<"low limit cannot be lower than 1"<<endl;
        low_limit=1;
    }
    if(low_limit<sqrt(devidend) && hi_limit>sqrt(devidend)){
        //in this case, no need to invesitgate further than sqrt(devidend) because duel gives complementary information
        for(int i=low_limit;i<=sqrt(devidend);i++){
            if(devidend%i==0){
                //found a devisor. store it and its devidend/i
                devisors.insert(devisors.begin()+floor(devisors.size()/2.0),(double)i);
                if((deul=devidend/i)<=hi_limit && deul!=i){
                    devisors.insert(devisors.begin()+ceil(devisors.size()/2.0),(double)deul);
                }
            }
        }
    }
    else{
        for(int i=low_limit;i<=hi_limit;i++){
            if(devidend%i==0){
                devisors.push_back((double)i);
            }
        }
    }
    return devisors;
}

void removeErrPortions(string data_set_host,string data_set,string user_name,string user_pass){
    //fixes number of tasks in each dataset according to already existing number of tasks
    try{
        if(!initialized){
        initDB(data_set_host,data_set,user_name,user_pass);
        }
        stringstream ss;
        int dataset_id, task_id;
        sql::ResultSet* errPor;
        ss<<"select dataset, task from task_st group by dataset, task having count(*)=1";
        stmt=con->createStatement();
        errPor=stmt->executeQuery(ss.str());
        while(errPor->next()){
            ss.str("");
            dataset_id=errPor->getInt("dataset");
            task_id=errPor->getInt("task");
	    cout<<"dataset:"<<dataset_id<<", task:"<<task_id<<endl;
            ss<<"delete from task_st where dataset="<<dataset_id<<" and task="<<task_id;
            stmt->execute(ss.str());
        }
    }
        catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
	The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
        cout << endl;
	cout << "# ERR: DbcException in " << __FILE__;
	cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	/* Use what(), getErrorCode() and getSQLState() */
	cout << "# ERR: " << e.what();
	cout << " (MySQL error code: " << e.getErrorCode();
	cout << ", SQLState: " << e.getSQLState() << " )" << endl;

	if (e.getErrorCode() == 1047) {
            /*
             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
          	*/
	    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
	}
            cout << "not ok 1 - examples/exceptions.cpp" << endl;
     }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in fixNoTasks():"<<e.what()<<endl;
    }
}

ResLock::ResLock(int res_in,int lock_in){
	res_id=res_in;
	lock_id=lock_in;
}

ResLock::ResLock(int res_in){
	res_id=res_in;
	lock_id=0;
}

bool ResLock::operator<(const ResLock &reslock_in){
	if(this->res_id<reslock_in.res_id){
		return true;
	}
	else{
		return false;
	}
}

bool resLockComp(const ResLock &reslock1,const ResLock &reslock2){
	if(reslock1.res_id<reslock2.res_id){
		return true;
	}
	return false;
}

vector<ResLock> getResLock(vector<vector<ResLock> > all_res_in){
	/*
	 * This function returns a vector of all resources used by all tasks in the task
	 * set, and the corresponding lock for each resource.
	 */

	/*
	 * Each vector in all_res_in is a set of objects accessed by the same transaction
	 * (Not necessarily the same task because there can be multiple transactions in the
	 * same task)
	 */

	vector<ResLock> final_res_lock;	//final vector of resources and corresponding locks
	vector<ResLock> tmp_final_res_lock;	//temporary vector to hold intermediate final result
	vector<ResLock> com_res_lock;	//common resources between two sets
	vector<ResLock>::iterator it;
	for(int i=0;i<(signed)all_res_in.size();i++){
		if(i==0){
			sort(all_res_in[0].begin(),all_res_in[0].end(),resLockComp);
			//First set of objects should all have a lock of 0
			for(int j=0;j<(signed)all_res_in[0].size();j++){
				all_res_in[0][j].lock_id=0;
			}
		}
		else{
			sort(all_res_in[i].begin(),all_res_in[i].end(),resLockComp);
			//compare current set of objects with previous sets
			for(int j=0;j<i;j++){
				if(all_res_in[i].size()>all_res_in[j].size()){
					com_res_lock.resize(all_res_in[i].size());
				}
				else{
					com_res_lock.resize(all_res_in[j].size());
				}
				it=set_intersection(all_res_in[i].begin(),all_res_in[i].end(),all_res_in[j].begin(),all_res_in[j].end(),com_res_lock.begin());
				com_res_lock.resize(it-com_res_lock.begin());
				if(!com_res_lock.empty()){
					/*
					 * current set has common objects with previous set. Assign the same
					 * lock for objects in both sets.
					 */
					for(int k=0;k<(signed)all_res_in[i].size();k++){
						all_res_in[i][k].lock_id=all_res_in[j][0].lock_id;
					}
					break;
				}
				else{
					/*
					 * Increase lock number of examined set of objects by 1 over current set
					 */
					for(int k=0;k<(signed)all_res_in[i].size();k++){
						all_res_in[i][k].lock_id=(all_res_in[j][0].lock_id)+1;
					}
				}
			}
		}
	}
	/*
	 * Now, unite all sets of objects with their corresponding locks in the final_res_lock
	 */
	if(all_res_in.size()==1){
		//In case there is only one task
		final_res_lock=all_res_in[0];
	}
	else{
		tmp_final_res_lock=all_res_in[0];
		for(int i=1;i<(signed)all_res_in.size();i++){
			final_res_lock.resize(tmp_final_res_lock.size()+all_res_in[i].size());
			it=set_union(all_res_in[i].begin(),all_res_in[i].end(),tmp_final_res_lock.begin(),tmp_final_res_lock.end(),final_res_lock.begin());
			final_res_lock.resize(it-final_res_lock.begin());
			tmp_final_res_lock=final_res_lock;
		}
	}
	//return the final vector
	return final_res_lock;
}

vector<ResLock> getOMLPResLock(vector<struct rt_task> total_tasks){
	/*
	 * Return a vecotr of all resources and corresponding lock for each resource in
	 * case of OMLP. The input is the set of all tasks. The function combines
	 * resources in each critical section in one vector. Each vector is added to the final
	 * vector that is passed to 'getResLock' function to specifiy locks for each resource
	 */
	vector<vector<ResLock> > reslock_total;
	vector<ResLock> reslock_cur;
	for(int i=0;i<total_tasks.size();i++){
		//Traverse through all tasks
		for(int j=0;j<total_tasks[i].portions.size();j++){
			//Traverse through all portions of the same task
			if(total_tasks[i].portions[j].por_type){
				//Consider only critical sections
				reslock_cur.clear();
				for(int k=0;k<total_tasks[i].portions[j].por_obj.size();k++){
					//Traverse through all objects in the current critical section
					reslock_cur.push_back(ResLock(total_tasks[i].portions[j].por_obj[k]));
				}
				reslock_total.push_back(reslock_cur);
			}
		}
	}
	return getResLock(reslock_total);
}

vector<ResLock> getRNLPResLock(vector<struct rt_task> total_tasks){
	/*
	 * Return a vecotr of all resources and corresponding lock for each resource in
	 * Return case of RNLP. The input is the set of all tasks. Current implementation of RNLP
	 * assigns distincit lock for each object. Each vector is added to the final
	 * vector that is passed to 'getResLock' function to specifiy locks for each resource
	 */
	vector<vector<ResLock> > reslock_total;
	vector<ResLock> reslock_cur;
	for(int i=0;i<total_tasks.size();i++){
		//Traverse through all tasks
		for(int j=0;j<total_tasks[i].portions.size();j++){
			//Traverse through all portions of the same task
			if(total_tasks[i].portions[j].por_type){
				//Consider only critical sections
				for(int k=0;k<total_tasks[i].portions[j].por_obj.size();k++){
					//Traverse through all objects in the current critical section
					reslock_cur.clear();
					reslock_cur.push_back(ResLock(total_tasks[i].portions[j].por_obj[k]));
					reslock_total.push_back(reslock_cur);
				}
			}
		}
	}
	return getResLock(reslock_total);
}

set<int> getDisLocks(vector<ResLock> allreslocks){
	/*
	 * Returns a set of distincit locks
	 */
	set<int> distlocks;
	for(int i=0;i<allreslocks.size();i++){
		distlocks.insert(allreslocks[i].lock_id);
	}
	return distlocks;
}

set<int> getDisLockCS(vector<double> objs,vector<ResLock> allreslocks,string lock_pro){
	/*
	 * Returns array of distincit locks required for current cirtical section. 'allreslocks' is the
	 * vector containing all resources and corresponding locks
	 */
	set<int> distlocks;
	if(!lock_pro.compare("OMLP")){
		/*
		 * In case of OMLP, all objects in the same critical section use the same lock. So it is
		 * enough to return the lock for the first object
		 */
		for(int i=0;i<(signed)objs.size();i++){
			for(int j=0;j<(signed)allreslocks.size();j++){
				if(allreslocks[j].res_id==(int)objs[i]){
					distlocks.insert(allreslocks[i].lock_id);
					return distlocks;
				}
			}
		}
	}
	else if(!lock_pro.compare("RNLP")){
		/*
		 * In this case (for the current implementation of RNLP), each object has its own lock
		 */
		for(int i=0;i<(signed)objs.size();i++){
			for(int j=0;j<(signed)allreslocks.size();j++){
				if(allreslocks[j].res_id==(int)objs[i]){
					distlocks.insert(allreslocks[i].lock_id);
					break;
				}
			}
		}
	}
	return distlocks;
}

void modObjSh(string data_set_host,string data_set,string user_name,string user_pass,double sh_lev,int total_no_obj){
	/*
	 * This function assumes there are recorded objects in case of sharing level = 100%
	 * Assign objects to transactions in a different pattern (i.e., Assign objects to transactions with maximum sharing level equal to sh_lev
	 * The current implementation of object sharing assumes objects are accessed at equidistant points within each transaction.
	 * object sharing starts at (1-sh_lev)*transactional length, and ends at the end of transaction)
	 * If update is true, then objects that already exist are updated. Otherwise, already existing objects are left intact
	 */
    try{
        if(!initialized){
            cout<<"Error: Database is not connected."<<endl;
            exit(0);
        }
        stringstream ss;
        sql::ResultSet *por_res;
        int por_id, task_id, dataset_id;
        double por_len;
        int total_no_sh_objs;	//Total number of all objects available for sharing
        int total_no_nsh_objs;	//Total number of all non shared objects available for sharing
        int sel_no_obj;			//number of objects in current transaction
        int sel_no_sh_obj;		//number of shared objects in current transaction
        int sel_no_nsh_obj;		//number of non-shared objects in current transaction
        int obj_indx;
        vector<double> nsh_total_objs;	//vector of non shared objects
        vector<double> sh_total_objs;	//vector of shared objects
		vector<double> sel_objs;       //Holds selected objects
		vector<double> tx_objs;			//objects assigned for current transaction

		/*
		 * Determine total number of shared and non-shared objects
		 */
		total_no_nsh_objs=(1-sh_lev)*total_no_obj;
		total_no_sh_objs=total_no_obj-total_no_nsh_objs;

		/* Initialize a list of all shared and non-shared objects to select desired objects from it */
		for(int i=0;i<total_no_nsh_objs;i++){
			nsh_total_objs.push_back(i);
		}
		for(int i=total_no_nsh_objs;i<total_no_obj;i++){
			sh_total_objs.push_back(i);
		}

		/*
		 * Insert new records for each portion with the new set of objects
		 */
        if(!data_set.compare("all")){
        	ss<<"select * from task_st where por_type=1 and obj_trns_retry=0 and obj_sh=1";
        }
        else{
        	ss<<"select * from task_st where dataset="<<data_set<<" and por_type=1 and obj_trns_retry=0 and obj_sh=1";
        }
        stmt=con->createStatement();
        por_res=stmt->executeQuery(ss.str());
        while(por_res->next()){
        	por_id=por_res->getInt("id");
        	task_id=por_res->getInt("task");
        	dataset_id=por_res->getInt("dataset");
            por_len=por_res->getDouble("por_len");
            sel_no_obj=(extractObj(por_res->getString("objs"))).size();
            sel_no_nsh_obj=(int)(sel_no_obj*(1-sh_lev));
            sel_no_sh_obj=sel_no_obj-sel_no_nsh_obj;
            sel_no_nsh_obj=total_no_nsh_objs>sel_no_nsh_obj?sel_no_nsh_obj:total_no_nsh_objs;	//current number of non-shared objects should not exceed total number of non-shared objects
            sel_no_sh_obj=total_no_sh_objs>sel_no_sh_obj?sel_no_sh_obj:total_no_sh_objs;	//current number of share objects should not exceed total number of shared objects
            vector<double> tmp_nsh_total_obj=nsh_total_objs;
            vector<double> tmp_sh_total_obj=sh_total_objs;
            for(int i=0;i<sel_no_nsh_obj;i++){
            	obj_indx=rand()%(tmp_nsh_total_obj.size());
            	tx_objs.push_back(tmp_nsh_total_obj[obj_indx]);
            	tmp_nsh_total_obj.erase(tmp_nsh_total_obj.begin()+obj_indx);
            }
            for(int i=0;i<sel_no_sh_obj;i++){
            	obj_indx=rand()%(tmp_sh_total_obj.size());
            	tx_objs.push_back(tmp_sh_total_obj[obj_indx]);
            	tmp_sh_total_obj.erase(tmp_sh_total_obj.begin()+obj_indx);
            }

            //Insert the new task portion
            stmt=con->createStatement();
			ss.str("");
			ss<<"INSERT INTO `test`.`task_st`(`dataset`,`task`,`id`,`por_type`,`por_len`,`obj_sh`,`objs`) VALUES(";
			ss<<dataset_id<<","<<task_id<<","<<por_id<<",1,"<<por_len<<","<<sh_lev;
			// Insert list of objects for current portion
			ss<<",'";
			for(int h=0;h<tx_objs.size();h++){
				ss<<tx_objs[h];
				if(h!=tx_objs.size()-1){
					ss<<",";
				}
				else{
					ss<<"')";
				}
			}
			stmt->execute(ss.str());

            //Clear tx_objs for the next task portion
            tx_objs.clear();
        }
        delete por_res;
    }
    catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
		The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
		cout << endl;
		cout << "# ERR: DbcException in " << __FILE__;
		cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
		/* Use what(), getErrorCode() and getSQLState() */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;

		if (e.getErrorCode() == 1047) {
				/*
				 Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
				Message: Unknown command
				*/
			cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
		}
				cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in readTaskPor():"<<e.what()<<endl;
    }
}

void modObjTransitive(string data_set_host,string data_set,string user_name,string user_pass,int total_no_obj){
	/*
	 * This function assumes there are recorded objects in case of non-transitive retry.
	 * Assign objects to transactions in a different pattern (i.e., pattern that introduces tansitive
	 * retry)
	 */
    try{
        if(!initialized){
            cout<<"Error: Database is not connected."<<endl;
            exit(0);
        }
        stringstream ss;
        sql::ResultSet *por_res;
        int por_id, task_id, dataset_id,prev_dataset_id,prev_task_id;
        double por_len;
        int sel_no_obj;			//number of objects in any transaction in current task
        int prev_sel_no_obj;	//number of objects in any transaction in previous task
        int sel_no_sh_obj;		//number of shared objects in current transaction
        vector<double> prev_task_objs;		//objects assigned to all transactions of previous task
		vector<double> task_objs;			//objects assigned for all transactions of current task

		prev_dataset_id=-1;	//Just for the start
		prev_task_id=-1;	//Just for the start

		/*
		 * Insert new records for each portion with the new set of objects
		 */
        if(!data_set.compare("all")){
        	ss<<"select * from task_st where por_type=1 and obj_trns_retry=0 and obj_sh=1";
        }
        else{
        	ss<<"select * from task_st where dataset="<<data_set<<" and por_type=1 and obj_trns_retry=0 and obj_sh=1";
        }
        stmt=con->createStatement();
        por_res=stmt->executeQuery(ss.str());
        while(por_res->next()){
        	task_objs.clear();	//Reset to receive the new set of objects
        	por_id=por_res->getInt("id");
        	task_id=por_res->getInt("task");
        	dataset_id=por_res->getInt("dataset");
            por_len=por_res->getDouble("por_len");
            sel_no_obj=(extractObj(por_res->getString("objs"))).size();
            if(dataset_id!=prev_dataset_id){
            	//It is a new dataset
            	prev_dataset_id=dataset_id;
            	if(task_id!=prev_task_id){
            		//It is a new task in a new dataset
            		prev_task_id=task_id;
            		for(int i=0;i<sel_no_obj;i++){
            			task_objs.push_back(i);
            		}
            		prev_task_objs=task_objs;
            	}
            	/*
            	 * Else case cannot exist beacuse this dataset is accessed for the first time
            	 */
            }
            else{
            	//Moving through tasks in the same dataset
            	if(task_id==prev_task_id){
            		//Moving through portions of the same task
            		task_objs=prev_task_objs;
            	}
            	else{
            		//Moving to a new task in the same dataset
            		prev_task_id=task_id;
            		prev_sel_no_obj=prev_task_objs.size();
            		sel_no_sh_obj=sel_no_obj>prev_sel_no_obj?prev_sel_no_obj/2:sel_no_obj/2;	//Number of objects to be shared between two consequitive tasks in the same dataset
            		//Insert shared objects from previous task into this task
            		for(int i=prev_sel_no_obj-sel_no_sh_obj;i<prev_sel_no_obj;i++){
            			task_objs.push_back(prev_task_objs[i]);
            		}
            		//Insert new objects into this task
            		for(int i=sel_no_sh_obj;i<sel_no_obj;i++){
            			task_objs.push_back(task_objs.back()+1);
            		}
            		//Update prev_task_objs
            		prev_task_objs=task_objs;
            	}
            }

            //Insert the new task portion
            stmt=con->createStatement();
			ss.str("");
			ss<<"INSERT INTO `test`.`task_st`(`dataset`,`task`,`id`,`por_type`,`por_len`,`obj_trns_retry`,`objs`) VALUES(";
			ss<<dataset_id<<","<<task_id<<","<<por_id<<",1,"<<por_len<<",1,";
			// Insert list of objects for current portion
			ss<<",'";
			for(int h=0;h<task_objs.size();h++){
				ss<<task_objs[h];
				if(h!=task_objs.size()-1){
					ss<<",";
				}
				else{
					ss<<"')";
				}
			}
			stmt->execute(ss.str());
        }
        delete por_res;
    }
    catch(sql::InvalidArgumentException &e) {
        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::MethodNotImplementedException &e){
        cout << "#\t Not implemented: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    catch (sql::SQLException &e){
        /*
		The MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)

                 sql::SQLException is the base class.
        */
		cout << endl;
		cout << "# ERR: DbcException in " << __FILE__;
		cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
		/* Use what(), getErrorCode() and getSQLState() */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;

		if (e.getErrorCode() == 1047) {
				/*
				 Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
				Message: Unknown command
				*/
			cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
		}
				cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch (std::runtime_error &e) {
        cout << endl;
        cout << "# ERR: runtime_error in " << __FILE__;
        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << "not ok 1 - examples/exceptions.cpp" << endl;
    }
    catch(exception e){
        cout<<"Exception in readTaskPor():"<<e.what()<<endl;
    }
}

void extract_task_rc_res(string data_set_host,string data_set,string user_name,string user_pass,double sh_lev,int transitive,int u_cap,string sch,int cp_enable,int dataset_in,int task_in){
	/*
	 * Extracts retry cost and response time for each job of each task of each dataset
	 * that correspond to a specific utilization with different synchronization techniques.
	 * Response time is extracted with: 1) without consideration for overhead of each CM
	 * compared to locking and lock-free. 2) with consideration for overhead of each CM compared
	 * to OMLP, RNLP, LOCK_FREE. Results can be specified for a specific dataset using datast_in
	 * parameter, or a specific task in a specific dataset (using task_in and dataset_in). Default is
	 * not to specify dataset, neither task
	 */
	try{
		if(!initialized){
			initDB(data_set_host,data_set,user_name,user_pass);
		}
		stringstream of_name("~/results/ds_");	//output file name
		stringstream gp_name("~/");	//gnuplot file name
		if(dataset_in!=-1){
			gp_name<<"d_"<<dataset_in<<"_";
		}
		if(task_in!=-1){
			gp_name<<"t_"<<task_in<<"_";
		}
		gp_name<<"u_cap_"<<u_cap<<"_sch_"<<sch<<"_trns_"<<transitive<<"_cp_"<<cp_enable<<"_sh_"<<sh_lev<<".gp";
		ofstream of_str;	//output file stream
		ofstream gp_str;	//output file for gnuplot
		bool go_on;	//condition to iterate through any of retrived results for different syncrhonization techniques
		bool ecm_con, ecm_oh_con, lcm_con, lcm_oh_con, pnf_con, pnf_oh_con, fblt_con, fblt_oh_con;	//conditions to iterate through retrived results for a specific synchronization technique
		sql::ResultSet *dataset_task, *ecm, *lcm, *pnf, *fblt, *omlp, *rnlp, *lf;
		sql::ResultSet *ecm_oh, *lcm_oh, *pnf_oh, *fblt_oh, *omlp_oh, *rnlp_oh, *lf_oh;
		int dataset, task_id;        //id of current examined task
		stringstream ss;

		//Initialize gnuplot file
		gp_str.open(gp_name.str().c_str());
		gp_str<<"set terminal push"<<endl;
		gp_str<<"set key top left"<<endl;
		gp_str<<"set terminal postscript eps enhanced lw 1"<<endl;
		gp_str<<"set style histogram cluster"<<endl;
		gp_str<<"set style data histogram"<<endl;
		gp_str<<"set style fill solid 1.0 border lt -2"<<endl;

		//Retrive result_set of datasets and tasks
		ss<<"select dataset, task from sh_results where";	//initial value
		if(dataset_in!=-1){
			ss<<" dataset="<<dataset_in<<" and";
		}
		if(task_in!=-1){
			ss<<" task="<<task_in<<" and";
		}
		ss<<" calibration=0 and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" and (select u_cap from datasets where datasets.id=sh_results.dataset)="<<u_cap<<" group by dataset, task";
		stmt=con->createStatement();
		stmt->setResultSetType(sql::ResultSet::CONCUR_READ_ONLY);
		stmt->setFetchSize(INT_MIN);
		dataset_task=stmt->executeQuery(ss.str());
		while(dataset_task->next()){
			go_on=false;	//initialized to false to be used when outputting results into files
			//Traverse through each task in each dataset in results
			dataset=dataset_task->getInt("dataset");
			task_id=dataset_task->getInt("task");
			//extract results when calibration=0
			ss.str("");
			if(!sch.compare("G_EDF")){
				ss<<"select * from sh_results where sync=\"ECM\" and calibration=0 and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			}
			else if(!sch.compare("G_RMA")){
				ss<<"select * from sh_results where sync=\"RCM\" and calibration=0 and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			}
			ecm=stmt->executeQuery(ss.str());	//includes results for ECM or RCM depending on scheduler
			ss.str("");
			ss<<"select * from sh_results where sync=\"LCM\" and calibration=0 and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			lcm=stmt->executeQuery(ss.str());
			ss.str("");
			ss<<"select * from sh_results where sync=\"PNF\" and calibration=0 and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			pnf=stmt->executeQuery(ss.str());
			ss.str("");
			ss<<"select * from sh_results where sync=\"FBLT\" and calibration=0 and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			fblt=stmt->executeQuery(ss.str());
			ss.str("");
			ss<<"select * from sh_results where sync=\"OMLP\" and calibration=0 and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			omlp=stmt->executeQuery(ss.str());
			ss.str("");
			ss<<"select * from sh_results where sync=\"RNLP\" and calibration=0 and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			rnlp=stmt->executeQuery(ss.str());
			ss.str("");
			ss<<"select * from sh_results where sync=\"LOCK_FREE\" and calibration=0 and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			lf=stmt->executeQuery(ss.str());

			//extract results when calibration=1
			ss.str("");
			if(!sch.compare("G_EDF")){
				ss<<"select * from sh_results where calibration=1 and sync=\"ECM\" and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			}
			else if(!sch.compare("G_RMA")){
				ss<<"select * from sh_results where calibration=1 and sync=\"RCM\" and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			}
			ecm_oh=stmt->executeQuery(ss.str());
			ss.str("");
			ss<<"select * from sh_results where calibration=1 and sync=\"LCM\" and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			lcm_oh=stmt->executeQuery(ss.str());
			ss.str("");
			ss<<"select * from sh_results where calibration=1 and sync=\"PNF\" and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			pnf_oh=stmt->executeQuery(ss.str());
			ss.str("");
			ss<<"select * from sh_results where calibration=1 and sync=\"FBLT\" and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			fblt_oh=stmt->executeQuery(ss.str());
			ss.str("");
			ss<<"select * from sh_results where calibration=1 and sync=\"OMLP\" and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			omlp_oh=stmt->executeQuery(ss.str());
			ss.str("");
			ss<<"select * from sh_results where calibration=1 and sync=\"RNLP\" and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			rnlp_oh=stmt->executeQuery(ss.str());
			ss.str("");
			ss<<"select * from sh_results where calibration=1 and sync=\"LOCK_FREE\" and dataset="<<dataset<<" and task="<<task_id<<" and sch=\""<<sch<<"\" and obj_sh="<<sh_lev<<" and obj_trns_retry="<<transitive<<" and cp_enable="<<cp_enable<<" group by dataset, task, instance";
			lf_oh=stmt->executeQuery(ss.str());

			//check each retrived resultset has the same number of records. If not, then print err and exit
			if(ecm->rowsCount()!=lcm->rowsCount() || ecm->rowsCount()!=pnf->rowsCount() ||
					ecm->rowsCount()!=fblt->rowsCount() || ecm->rowsCount()!=omlp->rowsCount() ||
					ecm->rowsCount()!=rnlp->rowsCount() || (lf->rowsCount()!=0 && ecm->rowsCount()!=lf->rowsCount()) ||
					ecm->rowsCount()!=ecm_oh->rowsCount() || ecm->rowsCount()!=lcm_oh->rowsCount() ||
					ecm->rowsCount()!=pnf_oh->rowsCount() || ecm->rowsCount()!=fblt_oh->rowsCount() ||
					(lf_oh->rowsCount()!=0 && ecm->rowsCount()!=lf_oh->rowsCount())
			){
				cout<<"number of jobs is not equal for dataset:"<<dataset<<" and task:"<<task_id<<endl;
				exit(0);
			}

			//create file to record results of current task and start new section in gnuplot file
			of_name.str("");
			of_name<<dataset<<"_t_"<<task_id<<"_sch_"<<sch<<"_trns_"<<transitive<<"_cp_"<<cp_enable<<"_sh_"<<sh_lev<<".dat";
			of_str.open(of_name.str().c_str());
			gp_str<<"# "<<of_name.str()<<endl<<endl;

			//record required results into outfile
			//if lock_free does not support current dataset, then do not include it in outfile
			of_str<<"#ecm\tlcm\tpnf\tfblt\tomlp\trnlp";
			if(lf->rowsCount()==0){
				of_str<<endl;
			}
			else{
				of_str<<"\tlf"<<endl;
			}

			//first section of output file for retry cost
			of_str<<"#first section for retry cost"<<endl;
			while(ecm->next()){
				//move other result sets to the next record
				lcm->next(); pnf->next(); fblt->next(); omlp->next(); rnlp->next(); lf->next();
				//Write retry cost into output file
				of_str<<ecm->getDouble("abr_dur")<<"\t"<<lcm->getDouble("abr_dur")<<"\t"<<
						pnf->getDouble("abr_dur")<<"\t"<<fblt->getDouble("abr_dur")<<"\t"<<
						omlp->getDouble("abr_dur")<<"\t"<<rnlp->getDouble("abr_dur");
				if(lf->rowsCount()==0){
					of_str<<endl;
				}
				else{
					of_str<<"\t"<<lf->getDouble("abr_dur")<<endl;
				}
			}
			of_str<<endl<<endl;

			//Reset all resultsets to the beforefirst to retrieve response time
			ecm->beforeFirst(); lcm->beforeFirst(); pnf->beforeFirst(); fblt->beforeFirst();
			omlp->beforeFirst(); rnlp->beforeFirst();
			if(lf->rowsCount()>0){
				lf->beforeFirst();
			}

			//second section of output file for response time without overhead
			of_str<<"#2nd section for response time without overhead"<<endl;
			while(ecm->next()){
				//move other result sets to the next record
				lcm->next(); pnf->next(); fblt->next(); omlp->next(); rnlp->next(); lf->next();

				of_str<<ecm->getDouble("response")<<"\t"<<lcm->getDouble("response")<<"\t"<<
						pnf->getDouble("response")<<"\t"<<fblt->getDouble("response")<<"\t"<<
						omlp->getDouble("response")<<"\t"<<rnlp->getDouble("response");
				if(lf->rowsCount()==0){
					of_str<<endl;
				}
				else{
					of_str<<"\t"<<lf->getDouble("response")<<endl;
				}
			}
			of_str<<endl<<endl;

			//Reset all resultsets to the beforefirst to retrieve response time
			ecm->beforeFirst(); lcm->beforeFirst(); pnf->beforeFirst(); fblt->beforeFirst();

			//Third section of output file for response time considering overhead compared to OMLP
			of_str<<"#3d section for response time considering overhead compared to OMLP"<<endl;
			double ecm_omlp;	//overhead of ecm(rcm) compared to omlp
			double lcm_omlp;	//overhead of lcm compared to omlp
			double pnf_omlp;	//overhead of pnf compared to omlp
			double fblt_omlp;	//overhead of fblt compared to omlp
			while(ecm->next()){
				//move other result_sets to the next record
				lcm->next(); pnf->next(); fblt->next(); ecm_oh->next();	lcm_oh->next();
				pnf_oh->next(); fblt_oh->next(); omlp_oh->next();
				//calculate additional overhead of each CM compared to OMLP
				ecm_omlp=ecm_oh->getDouble("response")-omlp_oh->getDouble("response");
				ecm_omlp=ecm_omlp>0?ecm_omlp:0;//because we calculate only additional overhead compared to OMLP
				lcm_omlp=lcm_oh->getDouble("response")-omlp_oh->getDouble("response");
				lcm_omlp=lcm_omlp>0?lcm_omlp:0;//because we calculate only additional overhead compared to OMLP
				pnf_omlp=pnf_oh->getDouble("response")-omlp_oh->getDouble("response");
				pnf_omlp=pnf_omlp>0?pnf_omlp:0;//because we calculate only additional overhead compared to OMLP
				fblt_omlp=fblt_oh->getDouble("response")-omlp_oh->getDouble("response");
				fblt_omlp=fblt_omlp>0?fblt_omlp:0;//because we calculate only additional overhead compared to OMLP
				//Write records into output file
				of_str<<(ecm->getDouble("response")-ecm_omlp)<<"\t"<<(lcm->getDouble("response")-lcm_omlp)<<"\t"<<
						(pnf->getDouble("response")-pnf_omlp)<<"\t"<<(fblt->getDouble("response")-fblt_omlp)<<"\t"<<
						"0"<<"\t"<<"0";
				if(lf->rowsCount()==0){
					of_str<<endl;
				}
				else{
					of_str<<"\t"<<"0"<<endl;
				}
			}
			of_str<<endl<<endl;

			//Reset all resultsets to the beforefirst to retrieve response time
			ecm->beforeFirst(); lcm->beforeFirst(); pnf->beforeFirst(); fblt->beforeFirst();
			ecm_oh->beforeFirst(); lcm_oh->beforeFirst(); pnf_oh->beforeFirst(); fblt_oh->beforeFirst();

			//Fourth section of output file for response time considering overhead compared to RNLP
			of_str<<"#4th section for response time considering overhead compared to RNLP"<<endl;
			double ecm_rnlp;	//overhead of ecm(rcm) compared to rnlp
			double lcm_rnlp;	//overhead of lcm compared to rnlp
			double pnf_rnlp;	//overhead of pnf compared to rnlp
			double fblt_rnlp;	//overhead of fblt compared to rnlp
			while(ecm->next()){
				//move other result_sets to the next record
				lcm->next(); pnf->next(); fblt->next(); ecm_oh->next();
				lcm_oh->next(); pnf_oh->next(); fblt_oh->next(); rnlp_oh->next();
				//calculate overhead of each CM compared to RNLP
				ecm_rnlp=ecm_oh->getDouble("response")-rnlp_oh->getDouble("response");
				ecm_rnlp=ecm_rnlp>0?ecm_rnlp:0;//because we calculate only additional overhead compared to RNLP
				lcm_rnlp=lcm_oh->getDouble("response")-rnlp_oh->getDouble("response");
				lcm_rnlp=lcm_rnlp>0?lcm_rnlp:0;//because we calculate only additional overhead compared to RNLP
				pnf_rnlp=pnf_oh->getDouble("response")-rnlp_oh->getDouble("response");
				pnf_rnlp=pnf_rnlp>0?pnf_rnlp:0;//because we calculate only additional overhead compared to RNLP
				fblt_rnlp=fblt_oh->getDouble("response")-rnlp_oh->getDouble("response");
				fblt_rnlp=fblt_rnlp>0?fblt_rnlp:0;//because we calculate only additional overhead compared to RNLP
				//Write records into output file
				of_str<<(ecm->getDouble("response")-ecm_rnlp)<<"\t"<<(lcm->getDouble("response")-lcm_rnlp)<<"\t"<<
						(pnf->getDouble("response")-pnf_rnlp)<<"\t"<<(fblt->getDouble("response")-fblt_rnlp)<<"\t"<<
						"0"<<"\t"<<"0";
				if(lf->rowsCount()==0){
					of_str<<endl;
				}
				else{
					of_str<<"\t"<<"0"<<endl;
				}
			}
			of_str<<endl<<endl;

			//Reset all resultsets to the beforefirst to retrieve response time
			ecm->beforeFirst(); lcm->beforeFirst(); pnf->beforeFirst(); fblt->beforeFirst();
			ecm_oh->beforeFirst(); lcm_oh->beforeFirst(); pnf_oh->beforeFirst(); fblt_oh->beforeFirst();

			//Fifth section of output file for response time considering overhead compared to LOCK_FREE
			//if LOCK_FREE is supported for current dataset
			if(lf->rowsCount()>0){
				of_str<<"#5th section for response time considering overhead compared to LOCK_FREE"<<endl;
				double ecm_lf;	//overhead of ecm(rcm) compared to LOCK_FREE
				double lcm_lf;	//overhead of lcm compared to LOCK_FREE
				double pnf_lf;	//overhead of pnf compared to LOCK_FREE
				double fblt_lf;	//overhead of fblt compared to LOCK_FREE
				while(ecm->next()){
					//move other result_sets to the next record
					lcm->next(); pnf->next(); fblt->next(); ecm_oh->next();
					lcm_oh->next(); pnf_oh->next(); fblt_oh->next(); lf_oh->next();
					//calculate overhead of each CM compared to LOCK_FREE
					ecm_lf=ecm_oh->getDouble("response")-lf_oh->getDouble("response");
					ecm_lf=ecm_lf>0?ecm_lf:0;//because we calculate only additional overhead compared to LOCK_FREE
					lcm_lf=lcm_oh->getDouble("response")-lf_oh->getDouble("response");
					lcm_lf=lcm_lf>0?lcm_lf:0;//because we calculate only additional overhead compared to LOCK_FREE
					pnf_lf=pnf_oh->getDouble("response")-lf_oh->getDouble("response");
					pnf_lf=pnf_lf>0?pnf_lf:0;//because we calculate only additional overhead compared to LOCK_FREE
					fblt_lf=fblt_oh->getDouble("response")-lf_oh->getDouble("response");
					fblt_lf=fblt_lf>0?fblt_lf:0;//because we calculate only additional overhead compared to LOCK_FREE
					//Write records into output file
					of_str<<(ecm->getDouble("response")-ecm_lf)<<"\t"<<(lcm->getDouble("response")-lcm_lf)<<"\t"<<
							(pnf->getDouble("response")-pnf_lf)<<"\t"<<(fblt->getDouble("response")-fblt_lf)<<"\t"<<
							""<<"\t"<<""<<"\t"<<""<<endl;
				}
				of_str<<endl<<endl;

				//Reset all resultsets to the beforefirst to retrieve response time
				ecm_oh->beforeFirst(); lcm_oh->beforeFirst(); pnf_oh->beforeFirst(); fblt_oh->beforeFirst();
				omlp_oh->beforeFirst(); rnlp_oh->beforeFirst(); lf_oh->beforeFirst();
			}

			//Sixth section of output file for response time considering calibration for all synchronization techniques
			of_str<<"#6th section for response time considering calibration for all synchronization techniques"<<endl;
			while(ecm_oh->next()){
				//move other result_sets to the next record
				ecm_oh->next(); lcm_oh->next(); pnf_oh->next(); fblt_oh->next();
				omlp_oh->next(); rnlp_oh->next(); lf_oh->next();
				//Write records into output file
				of_str<<ecm_oh->getDouble("response")<<"\t"<<lcm_oh->getDouble("response")<<"\t"<<
						pnf_oh->getDouble("response")<<"\t"<<fblt_oh->getDouble("response")<<"\t"<<
						omlp_oh->getDouble("response")<<"\t"<<rnlp_oh->getDouble("response");
				if(lf->rowsCount()==0){
					of_str<<endl;
				}
				else{
					of_str<<"\t"<<lf_oh->getDouble("response")<<endl;
				}
			}
			of_str<<endl<<endl;

			//close outfile
			of_str.close();

			//Extract relative deadline for current task to be plotted against responses of different synchronization techniques
			ecm->first();
			gp_str<<"f(x)="<<(ecm->getUInt64("deadline")-ecm->getUInt64("start"))<<endl;

			//Add plot commands
			gp_str<<"set output "<<(of_name.str())<<".eps"<<endl;
			if(lf->rowsCount()>0){
				gp_str<<"set multiplot layout 3,3 columnfirst"<<endl;
				gp_str<<"plot \""<<(of_name.str())<<"\", i 0 u 1:7"<<endl;
				gp_str<<"plot \""<<(of_name.str())<<"\", i 1 u 1:7, f(x) with lines"<<endl;
				gp_str<<"plot \""<<(of_name.str())<<"\", i 2 u 1:7, f(x) with lines"<<endl;
				gp_str<<"plot \""<<(of_name.str())<<"\", i 3 u 1:7, f(x) with lines"<<endl;
				gp_str<<"plot \""<<(of_name.str())<<"\", i 4 u 1:7, f(x) with lines"<<endl;
				gp_str<<"plot \""<<(of_name.str())<<"\", i 5 u 1:7"<<endl;
			}
			else{
				gp_str<<"set multiplot layout 3,3 columnfirst"<<endl;
				gp_str<<"plot \""<<(of_name.str())<<"\", i 0 u 1:6"<<endl;
				gp_str<<"plot \""<<(of_name.str())<<"\", i 1 u 1:6, f(x) with lines"<<endl;
				gp_str<<"plot \""<<(of_name.str())<<"\", i 2 u 1:6, f(x) with lines"<<endl;
				gp_str<<"plot \""<<(of_name.str())<<"\", i 3 u 1:6, f(x) with lines"<<endl;
				gp_str<<"plot \""<<(of_name.str())<<"\", i 4 u 1:6"<<endl;
			}
			gp_str<<"unset multiplot"<<endl;
			gp_str<<endl<<endl;
		}

		//Record last commands in gp file and close it
		gp_str<<"set output"<<endl;
		gp_str<<"set terminal pop"<<endl;
		gp_str.close();

		delete dataset_task;
		delete ecm;
		delete lcm;
		delete pnf;
		delete fblt;
		delete omlp;
		delete rnlp;
		delete lf;
		delete ecm_oh;
		delete lcm_oh;
		delete pnf_oh;
		delete fblt_oh;
		delete omlp_oh;
		delete rnlp_oh;
		delete lf_oh;
	}
	catch(sql::InvalidArgumentException &e) {
	        cout << "#\t Invalid Argument: " << e.what()<<" on line "<<__LINE__;
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	    }
	    catch (sql::MethodNotImplementedException &e){
	        cout << "#\t Not implemented: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	    }
	    catch (sql::SQLException &e){
	        /*
		The MySQL Connector/C++ throws three different exceptions:
			- sql::MethodNotImplementedException (derived from sql::SQLException)
			- sql::InvalidArgumentException (derived from sql::SQLException)
			- sql::SQLException (derived from std::runtime_error)

	                 sql::SQLException is the base class.
	        */
	        cout << endl;
		cout << "# ERR: DbcException in " << __FILE__;
		cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
		/* Use what(), getErrorCode() and getSQLState() */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;

		if (e.getErrorCode() == 1047) {
	            /*
	             Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
				Message: Unknown command
	          	*/
		    cout << "# ERR: Your server seems not to support PS at all because its MYSQL <4.1" << endl;
		}
	            cout << "not ok 1 - examples/exceptions.cpp" << endl;
	     }
	    catch (std::runtime_error &e) {
	        cout << endl;
	        cout << "# ERR: runtime_error in " << __FILE__;
	        cout << "(" << EXAMPLE_FUNCTION << ") on line " << __LINE__ << endl;
	        cout << "# ERR: " << e.what() << endl;
	        cout << "not ok 1 - examples/exceptions.cpp" << endl;
	    }
	    catch(exception e){
	        cout<<"Exception i nreadTaskSet():"<<e.what()<<endl;
	    }
}
/*
void dur(string data_set_host,string data_set,string user_name,string user_pass,int dataset_in,double sh_lev,int transitive,int u_cap,int cp_enable,string sch="all",int task_in=-1){
}
*/
void analyze_results(string data_set_host,string data_set,string user_name,string user_pass,int dataset_in,int task_in,double sh_lev,int transitive,int u_cap,int op_no,int cp_enable,string sch){
	/*
     * Analyzes results according to the specified op_no. u_cap is utilization
     * cap that accumulates a number of datasets
     */
	try{
		switch (op_no){
		case 1:
			extract_task_rc_res(data_set_host,data_set,user_name,user_pass,sh_lev,transitive,u_cap,sch,cp_enable,dataset_in,task_in);
			break;
		default:
			cout<<"Err: you entered invalid operation number of analyzing data"<<endl;
			exit(0);
		}
	}
	catch(exception e){
		cout<<"Exception in analyze_results():"<<e.what()<<endl;
	}
}
