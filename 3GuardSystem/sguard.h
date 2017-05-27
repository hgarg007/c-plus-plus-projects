#include<string>

#ifndef Sguard_H
#define Sguard_H 

class Sguard {

static int tid;
int sid;
std::string sname,sphone,saddress;


public:
	Sguard();
	Sguard(int,std::string,std::string,std::string);
	static int generateSid();
	void setSname(std::string);
	void setSphone(std::string);
	void setSaddress(std::string);
	int getSid();
	std::string getSname();
	std::string getSphone();
	std::string getSaddress();
   
};

#endif