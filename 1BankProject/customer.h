#include<string>
//#include<vector>
//#include"customer.h"
//#include"account.h"
//#include"bank.h"
//#include<iostream>

#ifndef Customer_H
#define Customer_H

class Customer {
int id;
std::string name;
std::string phone;
static int tid;

public:
	Customer();
	Customer(int, std::string, std::string);
	static int generateId();
	
	void setName(std::string);
	void setPhone(std::string);
	
	
	
};

#endif
