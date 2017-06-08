#include "wonderland.h"

int WonderlandModel:: empId=1000;

WonderlandModel::WonderlandModel() {
}

void WonderlandModel:: addToVector(Employee emp) {
	empList.push_back(emp);
}

int WonderlandModel:: generateEmpId() {
	return ++empId;
}

int WonderlandModel:: isEmpIdExist(int empId) {
	
	for(int i=0; i<empList.size(); i++) {
		if(empId==empList[i].getEmpId())
			return i;	
	}
	return -1;
}

Employee WonderlandModel:: viewEmpDetails(int i) {
	return empList[i];
}

Employee WonderlandModel:: viewEmpDetailsBackup(int i) {
	return empListBackup[i];
}

vector<Employee> WonderlandModel:: getEmpList() {
	return empList;
}

int WonderlandModel:: addEmp(struct EmployeeStruct empStruct) {
	
	for(int i=0; i<empList.size(); i++) {
		if(empList[i].getEmpContactNumber()==empStruct.contactNumber)
			return -1;
	}
	int id= this->generateEmpId();
	Employee emp(id, empStruct.age, empStruct.gender, empStruct.name, empStruct.address,  empStruct.contactNumber, empStruct.designation);
	this->addToVector(emp);
	return id;
}

int WonderlandModel:: deleteEmp(int empId) {

	for(int i=0; i<empList.size(); i++) {
		if(empId==empList[i].getEmpId()) {
			empList.erase(empList.begin() + i);
			return 1;
		}
	}
	return -1;		
}

int WonderlandModel:: isEmpIdExistBackup(int empId) {
	for(int i=0; i<empListBackup.size(); i++) {
		if(empId==empListBackup[i].getEmpId())
			return i;	
	}
	return -1;
}

void  WonderlandModel:: makeEmployeeBackup() {
	empListBackup.clear();
	for(int i=0; i<empList.size(); i++) {
		empListBackup.push_back(empList[i]);
	}
}

vector<Employee> WonderlandModel:: getEmpBackupList() {
	return empListBackup;
}

int WonderlandModel:: updateEmpDetails(struct EmployeeStruct empStruct, int empId) {
	for(int i=0; i<empList.size(); i++) {
		if(empId==empList[i].getEmpId()) {
			if(empStruct.age!=-1)
				empList[i].setEmpAge(empStruct.age);
			if(empStruct.gender!='@')
				empList[i].setEmpGender(empStruct.gender);
			if(empStruct.name!="@")
				empList[i].setEmpName(empStruct.name);
			if(empStruct.address!="@")
				empList[i].setEmpAddress(empStruct.address);
			if(empStruct.contactNumber!="@")
				empList[i].setEmpContactNumber(empStruct.contactNumber);
			if(empStruct.designation!="@")
				empList[i].setEmpDesignation(empStruct.designation);
			return 1;
		}
	}
	return -1;
}
