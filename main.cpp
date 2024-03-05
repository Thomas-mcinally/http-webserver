#include <stdio.h>
#include "http_webserver.h"

int main(){
	int timer = 0;
	while (timer < 5){
		HttpWebserver webserver = HttpWebserver();
		webserver.print_greeting();
		timer++;
	}	
}
