//#include<string>
//#include<vector>
#include"customer.h"
//#include"bank.h"
//#include<iostream>

//class Customer;
#ifndef Account_H
#define Account_H

class Account {
Customer *c;
int accno;
int bal;
static int taccno;

public:
	Account();
	Account(Customer *, int);
	static int generateAccNo();
	void addBal(int);
	
	int getAccNo();
	int getBal();
};
#endif

