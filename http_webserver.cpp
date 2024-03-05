#include <stdio.h>
#include "http_webserver.h"
#include <sys/socket.h>
#include <unistd.h>


void HttpWebserver::printGreeting()
{
	printf("hello!\n");
}

int HttpWebserver::startServer()
{
	{
		printf("Server started!\n");
		// assign value to private attribute input_socket_fd
		this->input_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (this->input_socket_fd == -1)
        {
			// socket creation failed
            return 1;
        }
		return 0;
    }
    
}

int HttpWebserver::stopServer()
{
	close(this->input_socket_fd);
	printf("Server stopped!\n");
	return 0;
}

HttpWebserver::HttpWebserver()
{
	this->startServer();
}
HttpWebserver::~HttpWebserver()
{
	this->stopServer();
}