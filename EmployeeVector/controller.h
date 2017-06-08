#include<string>
#include"ui.h"
#include"wonderland.h"

using namespace std;

#ifndef controller_H
#define controller_H

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