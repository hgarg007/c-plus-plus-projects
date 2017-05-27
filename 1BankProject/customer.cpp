#include<string>
//#include<vector>
#include"customer.h"
//#include"account.h"
//#include"bank.h"
//#include<iostream>

int Customer:: tid=100;

Customer:: Customer() {}
Customer:: Customer(int id, std::string name, std::string phone) {
	this->id= id;
	this->name=name;
	this->phone=phone;
	
}
int Customer:: generateId() {
	return ++tid;
}

void Customer:: setName(std::string name) {
	this->name=name;
}
void Customer:: setPhone(std::string name) {
	this->phone=phone;
}