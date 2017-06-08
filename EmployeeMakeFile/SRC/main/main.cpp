#include"../ui/ui.h"
#include"../wonderland/wonderland.h"
#include"../controller/controller.h"

int main() {
	WonderlandModel w;
	UI u;
	Controller c;
	c.initiateAll(w,u);
	return 0;
}
