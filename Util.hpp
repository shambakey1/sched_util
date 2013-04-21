/* 
 * File:   Util.hpp
 * Author: root
 *
 * Created on September 19, 2012, 3:16 PM
 */

#ifndef UTIL_HPP
#define	UTIL_HPP

#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/metadata.h>
#include <examples.h>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <boost/math/common_factor_rt.hpp>
#include <algorithm>
#include <set>

using namespace std;

extern string total_comp[];    //Used for comparison against different distributions
extern bool initialized;        //If true, then database is already connected
struct task_por{                //Captures information about each portion of a task
    int por_type;               //0 for non-critical section. 1 otherwise
    double por_len;             //Length of this portion
    vector<double> por_obj;        //Objects access by this portion. -1 if non-critical section
    double mod_por_len;         //modified from por_len according to utilization
};
struct rt_task{
    //information about real-time task
    long double deadline;
    long double period;
    long double wcet;
    long double mod_wcet;
    vector<int> processors;
    vector<struct task_por> portions;
};
class ResLock{
public:
	int res_id;	//resource id
	int lock_id;	//lock id for the corresponding resource
	ResLock(){};
	ResLock(int);
	ResLock(int,int);
	bool operator<(const ResLock &);
};
extern int DATASET_ID;

extern int comp_dist(string s);                          //Checks required total transactions length distribution
extern void add_dataset(string data_set_host,string data_set,string user_name,string user_pass,double util_cap,string util_dist,double no_datasets,string total_dist,string max_dist,string min_dist,string n_obj,string n_obj_dist,double stm_inst,double rt_inst);       //Adds a number of datasets
extern void debug_getopt(string operation,string cm,double u,double run_time,double proc_num,double psi,
        string total_tx,string max_tx,string min_tx,string n_obj_dis,double n_obj,double n_dataset,
        string dataset,string dataset_host,string dataset_user,string dataset_pass);
extern vector<double> selectPeriod(int hyperperiod);   //Returns all available periods that are devisors of hyperperiod and lying between the specified period limits
extern double selectUtil(string util_dist,double stm_inst,double rt_inst,double period);     //Return utilization for current task
                        //min_ratio=min(wcet/period)=min(one read/write STM instruction time/period)
extern double selectTotalTx(string total_tx_dist,double stm_inst,double wcet);      //Returns selected total percentage of transactional length according to required distribution
                        //min_ratio is the minimum value for total_tx_dist perc=min(one read/write stm instruction time/wcet)
extern double selectMaxTx(string max_tx_dist,double total_tx,double stm_inst,double wcet);  //Returns selected max percentage of transactional length according to required distribution
extern double selectMinTx(string min_tx_dist,double max_tx,double stm_inst,double wcet);  //Returns selected min percentage of transactional length according to required distribution
extern vector<double> selectObj(string obj_dist,int total_no_obj,double por_len,double stm_inst);     //Return percentage of total objects
extern void initDB(string data_set_host,string data_set,string user_name,string user_pass);   //Initiates connection to DB
extern void endDB();    //Deletes connection to DB and deletes parameters
extern void addPortions(double total_tx,double max_tx,double min_tx,double wcet,string obj_dist,int total_no_obj,vector<struct task_por> *portions,double stm_inst,double rt_inst);    //Return vector of portion lengths for current task
extern vector<struct rt_task> readTaskSet(string data_set_host,string data_set,string user_name,string user_pass,int dataset_id,double sh_lev=1,int transitive=0);   //Reads tasks's information from a taskset file
extern vector<struct task_por> readTaskPor(int dataset_id,int task_no,double sh_lev=1,int transitive=0);           //Reads different portions of a single task
extern vector<double> extractObj(string objs);  //Creates a vector of objects from a CSV string
extern vector<int> extractDataSet(string data_set_host,string data_set,string user_name,string user_pass,double util_cap,string util_dist,string total_dist,double total_tx,string max_dist,double max_tx,string min_dist,double min_tx,double n_obj,string n_obj_dist); //return IDs for all datasets that meet requirements
extern int detHyperPeriod(double per,int threshold);    //Returns hyperperiod threshold
extern vector<int> extractProc(string proc);    //Extracts available processor for current task if not all
                                                //Note that "proc" values is "all" or CSV of processor numbers
extern void setResults(int dataset_id,vector<vector<vector<unsigned long long> > > total_result,string sync_alg,string sch,int cp_enable,double sh_lev,int transitive,int calibration);//stores results into database
                                                //Note that this function depends on the final result format produce by Sched_Test_App
                                                //which is in the form of "vector<vector<vector<unsigned long long> > >
extern void delAll();   //Remove all data in all tables. Useful in case of invalid inputs
extern int getSTM2WCET(double wcet,double stm_inst);    //gets ratio of one stm instruction relative to wcet.
                                                        //Used to determine minimum values for min_tx, max_tx and total_tx
extern int getSTM2Period(double period,double stm_inst);        //gets ratio of one stm instruction relative to period.
                                                                //Used to determine minimum value of wcet
extern void checkPortions(vector<struct task_por> *portions);        //Checks portions meet requirements
extern void count_dataset(string data_set_host,string data_set,string user_name,string user_pass,double util_cap,string util_dist,string total_dist,string max_dist,string min_dist,string n_obj,string n_obj_dist);    //return number of datasets meeting specified requirements
extern void fixDatasets(string data_set_host,string data_set,string user_name,string user_pass,double stm_inst,double rt_inst,int no_data_set); //If number of datasets for specific criteria are less than no_data_set, add additional data sets
extern void remTasks(string data_set_host,string data_set,string user_name,string user_pass);   //removes tasks that do not meet requirements
extern void fixNoTasks(string data_set_host,string data_set,string user_name,string user_pass); //fixes number of tasks in each dataset according to already existing number of tasks
extern void modifyPortions(string data_set_host,string data_set,string user_name,string user_pass,double stm_inst,double rt_inst,bool add); //Modifies portions not meeting requirements
extern void checkObjs(string data_set_host,string data_set,string user_name,string user_pass,double stm_inst,double rt_inst);   //checks that number of objects in each portion meets specified constraints
extern bool exists(int dataset_id);     //checks whether dataset with the specified id exists or not
extern int getUtilCap(string data_set_host,string data_set,string user_name,string user_pass,int dataset_id);
extern int calcHyperPeriod(string data_set_host,string data_set,string user_name,string user_pass,int dataset_id);      //calculates hyperperiod for a given taskset
extern vector<int> calcHyperPeriod(string data_set_host,string data_set,string user_name,string user_pass);     //calculates hyperperiod for all datasets
extern vector<double> findDevisors(int devidend,int low_limit, int hi_limit);      //Finds all devisors of devidend between low_lim and hi_limit
extern void removeErrPortions(string data_set_host,string data_set,string user_name,string user_pass);  //remove portions whose count is 1
extern vector<ResLock> getResLock(vector<vector<ResLock> > all_res_in);	//Return a vecotr of all resources and corresponding lock for each resource
extern vector<ResLock> getOMLPResLock(vector<struct rt_task>);	//Return a vecotr of all resources and corresponding lock for each resource in case of OMLP. The input is the set of all tasks
extern vector<ResLock> getRNLPResLock(vector<struct rt_task>);	//Return a vecotr of all resources and corresponding lock for each resource in case of RNLP. The input is the set of all tasks
extern set<int> getDisLocks(vector<ResLock>);	//Returns a set of distincit locks
extern set<int> getDisLockCS(vector<double> objs,vector<ResLock> allreslocks,string lock_pro);	//Returns set of distincit locks required for current cirtical section. 'allreslocks' is the vector containing all resources and corresponding locks
extern void modObjTx(string data_set_host,string data_set,string user_name,string user_pass,double stm_inst,double rt_inst,double sh_lev,bool transitive,bool update); //Assign objects to transactions in different patterns (i.e., introduces transitive retry,
																																						//Assign objects to transactions with maximum sharing level equal to sh_lev
																																						//The current implementation of object sharing assumes objects are accessed at equidistant points within each transaction.
																																						//object sharing starts at (1-sh_lev)*transactional length, and ends at the end of transaction)
																																						//if update is true, then objects that already exist are updated. Otherwise, already existing objects are left intact
extern void modObjTransitive(string data_set_host,string data_set,string user_name,string user_pass,int total_no_obj);	//Generate objects in a pattern that introduces transitive retry
#endif	/* UTIL_HPP */


