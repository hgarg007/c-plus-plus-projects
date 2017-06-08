#include "employee.h"

using namespace std;

Employee:: Employee() {
}

Employee ::Employee(int id,int age,char gender,string name,string address,string contactNumber, string designation){
	this->id=id;
	this->name=name;
	this->gender=gender;
	this->age=age;
	this->address=address;
	this->contactNumber=contactNumber;
	this->designation=designation; 
}

int Employee::getEmpId(){
	return id;
}

string Employee::getEmpAddress(){
	return address;
}


string Employee::getEmpDesignation(){
	return designation;
}


string Employee::getEmpName() {
	return name;
}



char Employee::getEmpGender() {
	return gender;
}


int Employee::getEmpAge() {
	return age;
}


string Employee::getEmpContactNumber() {
	return contactNumber;
}


void Employee::setEmpId(int id) {
	this->id=id;
}

void Employee::setEmpAddress(string address) {
	this->address=address;
}


void Employee::setEmpName(string name) {
	this->name=name;
}

void Employee::setEmpDesignation(string designation) {
	this->designation=designation;
}


void Employee::setEmpGender(char gender) {
	this->gender=gender;
}



void Employee::setEmpAge(int age) {
	this->age=age;
}


void Employee::setEmpContactNumber(string contactNumber) {
	this->contactNumber=contactNumber;
}
