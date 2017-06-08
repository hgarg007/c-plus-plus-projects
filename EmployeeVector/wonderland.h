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
	WonderlandModel();
	int isEmpIdExist(int );
	Employee viewEmpDetails(int );
	Employee viewEmpDetailsBackup(int );
	vector<Employee> getEmpList();
	int addEmp(struct EmployeeStruct);
	int deleteEmp(int );
	int isEmpIdExistBackup(int );
	void makeEmployeeBackup();
	vector<Employee> getEmpBackupList();
	int updateEmpDetails(struct EmployeeStruct, int );
	
	
	
};
#endif