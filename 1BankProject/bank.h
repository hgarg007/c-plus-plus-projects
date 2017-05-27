//#include<string>
#include<vector>
//#include"customer.h"
#include"account.h"
//#include<iostream>

#ifndef Bank_H
#define Bank_H

class Bank{
std::vector <Account> accounts;

public:
	Bank();
	void addAccount(Account *);
	int findBal(int );
};

#endif
