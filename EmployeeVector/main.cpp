#include"ui.h"
#include"wonderland.h"
#include"controller.h"

int main() {
	WonderlandModel w;
	UI u;
	Controller c;
	c.initiateAll(w,u);
	return 0;
}