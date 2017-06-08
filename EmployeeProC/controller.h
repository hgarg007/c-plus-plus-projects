
#include<string>
#include"ui.h"
#include"wonderland.h"

using namespace std;

#ifndef Controller_H
#define Controller_H

class Controller {

public:
	void initiateAll(WonderlandModel &,UI &);
	void initiateAddEmp(WonderlandModel &,UI &);
	void initiateDeleteEmp(WonderlandModel &,UI &);
	void initiateManualBackupView(WonderlandModel &,UI &);
	void initiateViewDetails(WonderlandModel &,UI &);
	void initiateUpdateDetails(WonderlandModel &,UI &);
	void initiateSearchEmp(WonderlandModel &,UI &);
};
#endif
