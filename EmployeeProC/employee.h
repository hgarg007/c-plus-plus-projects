#include<string>
using namespace std;

#ifndef Employee_H
#define Employee_H

class Employee {

	int id,age;
	char gender;
	string address,contactNumber,designation,name;
	
public:

	Employee();
	Employee(int ,int ,char ,string ,string ,string ,string );

	int getEmpId();
	string getEmpName();
	char getEmpGender();
	string getEmpAddress();
	int getEmpAge();
	string getEmpContactNumber();
	string getEmpDesignation();
	
	void setEmpContactNumber(string );
	void setEmpDesignation(string );
	void setEmpAge(int );
	void setEmpName(string );
	void setEmpId(int );
	void setEmpGender(char );
	void setEmpAddress(string );
};
#endif