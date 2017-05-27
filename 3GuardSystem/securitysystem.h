#include <vector>
#include <string>
#include "sguard.h"
#include "schedule.h"

using namespace std;

#ifndef SecuritySystem_H
#define SecuritySystem_H

class SecuritySystem {

	std::vector<Sguard> sguards;
	std::vector<Schedule> scheduling;

public:
	SecuritySystem();
	void addSguard(Sguard *);
	void updateSguard(int, char, std::string);
	Sguard * displaySguard(int );
	int getNumberG();

	void addSchedule(Schedule *);
	void updateSchedule(int, char , int );
	Schedule * displaySchedule(int );
	int getNumberS();

	int validateName(string);
	int validatePhone(string);
	int validateAddress(string);
	int validateSid(int);
	int validateDay(int);
	
	
};

#endif
