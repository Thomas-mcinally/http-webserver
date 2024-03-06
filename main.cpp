#include <stdio.h>
#include "http_webserver.h"

int main(){
	HttpWebserver webserver = HttpWebserver("0.0.0.0", 80);

	return 0;
}
