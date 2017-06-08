#include "employee.h"
#include "empstruct.h"
#include<vector>
using namespace std;

#ifndef WonderlandModel_H
#define WonderlandModel_H

class WonderlandModel {

	vector<Employee> empList;
	vector<Employee> empListBackup;
	static int empId;

	void addToVector(Employee );
	int generateEmpId();
	
public:
	string myStripe(char *);
	void makeFileBackup();
	void retrieveFile();
	int openConnection();
	WonderlandModel();
	int isEmpIdExist(int );
	int viewEmpDetails(int ,Employee &);
	int viewEmpDetailsBackup(int ,Employee & );
	vector<Employee> getEmpList();
	vector<Employee> getEmpListName(string);
	int addEmp(struct EmployeeStruct);
	int deleteEmp(int );
	int isEmpIdExistBackup(int );
	int	makeEmployeeBackup();
	vector<Employee> getEmpBackupList();
	vector<Employee> getEmpBackupListM();
	int updateEmpDetails(struct EmployeeStruct, int );
	
	
	
};
#endif