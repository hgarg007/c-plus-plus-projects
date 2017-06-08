#include"employee.h"
#include"empstruct.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;

#ifndef UI_H
#define UI_H

class UI {
 
	int validateViewOption(int);
	int validateId(int);
	int validateAge(int);
	int validateName(string);
	int validateAddress(string);
	int validateContactNumber(string);
	int validateDesignation(string );
	int validateGender(char);
	
public:
	int validateViewBackupOption(int );
	void takeEnter();
	void taskAborted();
	void displaySuccessRetrieve();
	int askConfirmation();
	void displaybackupsearchMesg();
	void displaydeleteMesg();
	void displayupdateMesg();
	int getInitiateOption();
	void displayMainMenu();
	int getId();
	void displayEmpDetails(Employee);
	void displayErrorId();
	void displayErrorIdMismatch();
	void displayAllEmpDetails(vector<Employee>);
	int getViewOption();
	void displayErrorOption();
	void displayEmpSearchBackupSuccess(Employee);
	struct EmployeeStruct getEmpDetails();
	void displayAddEmpSuccess(int);
	void displayErrorDetails();
	void displayErrorEmpRepeat();
	void displayDeleteEmpSuccess();
	struct EmployeeStruct getUpdateDetails();
	void displayUpdateSuccess();
	int getBackupOption();
	void displayBackupSuccess();
	void displayLimitExceeded();
	string getName();

};
#endif


