#include <stdio.h>
#include "http_webserver.h"

int main(){
	HttpWebserver webserver = HttpWebserver("0.0.0.0", 8020);
	webserver.startListen();

	return 0;
}
