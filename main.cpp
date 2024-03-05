#include <stdio.h>
#include "http_webserver.h"

int main(){
	int timer = 0;
	HttpWebserver webserver = HttpWebserver();
	while (timer < 5){
		webserver.printGreeting();
		timer++;
	}

	return 0;
}
