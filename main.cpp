#include <stdio.h>
#include "http_webserver.h"

int main(){
	HttpWebserver webserver = HttpWebserver("127.0.0.1", 80);
	webserver.startListen();

	return 0;
}
