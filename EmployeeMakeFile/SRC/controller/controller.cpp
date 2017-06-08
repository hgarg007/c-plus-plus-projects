#include"controller.h"


using namespace std;

void Controller:: initiateAll(WonderlandModel &w,UI &u) {
	while(1) {
		u.displayMainMenu();
		int option=u.getInitiateOption();
		switch(option) {
			case 1:
					initiateAddEmp(w,u);
					break;
			case 2:
					initiateViewDetails(w,u);
					break;
			case 3:
					initiateUpdateDetails(w,u);
					break;
			case 4:
					initiateDeleteEmp(w,u);
					break;
			case 5:
					initiateManualBackupView(w,u);
					break;
			case 6:
					initiateSearchEmp(w,u);
					break;
			case 0:
					break;
			default:
					u.displayErrorOption();
					break;
		}
		if(option==0)
			break;
		
	}
}

void Controller:: initiateAddEmp(WonderlandModel &w,UI &u) {
	int temp= w.addEmp(u.getEmpDetails());
	if(temp!=-1)
		u.displayAddEmpSuccess(temp);
	else
		u.displayErrorEmpRepeat();
}

void Controller:: initiateDeleteEmp(WonderlandModel &w,UI &u) {
	Employee emp;
	
	int t=u.getId();
	if(w.isEmpIdExist(t)==1) {
		int x = w.viewEmpDetails(t,emp);
		if(x!=-1)
		u.displayEmpDetails(emp);
		int y=u.askConfirmation();
		if(y==1) {
				int x= w.deleteEmp(t);
				u.displayDeleteEmpSuccess();
		}
		else
			u.taskAborted();
				
	}
	else 
		u.displayErrorIdMismatch();
}

void Controller:: initiateManualBackupView(WonderlandModel &w,UI &u) {
	switch(u.getBackupOption()) {
		case 1:
				{
				int x=w.makeEmployeeBackup();
				u.displayBackupSuccess();
				break;
				}
		case 2:	
				{
				vector<Employee> y=w.getEmpBackupList();
				u.displayAllEmpDetails(y);
				break;
				}
		case 3:
				{
				vector<Employee> t=w.getEmpBackupListM();
				u.displayAllEmpDetails(t);
				break;
				} 
		case 4:
				{
				w.makeFileBackup();
				u.displayBackupSuccess();
				break;
				}
		case 5:
				{
				w.retrieveFile();
				u.displaySuccessRetrieve();
				break;
				}
	}
}


void Controller:: initiateUpdateDetails(WonderlandModel &w,UI &u) {
	Employee emp;
	int x=u.getId();
	if(w.isEmpIdExist(x)==1) {
		w.viewEmpDetails(x,emp);
		u.displayEmpDetails(emp);
		int y=u.askConfirmation();
		if(y==1) {
		w.updateEmpDetails(u.getUpdateDetails(),x);	
		u.displayUpdateSuccess();
		}
		else 
		u.taskAborted();
	}
	else
		u.displayErrorIdMismatch();
}

void Controller:: initiateViewDetails(WonderlandModel &w,UI &u) {
	Employee emp;
	switch(u.getViewOption()) {
		case 1: {
				int x = w.viewEmpDetails(u.getId(),emp);
				if(x!=-1)
				u.displayEmpDetails(emp);
				else
				u.displayErrorIdMismatch();
				break;
				}
		case 2: {
				u.displayAllEmpDetails(w.getEmpList());
				break;
				}
		case 3:
			u.displayAllEmpDetails(w.getEmpListName(u.getName()));
	}
}

void Controller:: initiateSearchEmp(WonderlandModel &w,UI &u) {
	
	Employee emp;
	int x=w.viewEmpDetailsBackup(u.getId(),emp);
	if(x!=-1)
		u.displayEmpDetails(emp);
	else
		u.displayErrorIdMismatch();
}
