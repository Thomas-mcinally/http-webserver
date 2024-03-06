#include <stdio.h>
#include "http_webserver.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>


int HttpWebserver::startServer()
{
	{
		printf("Server started!\n");
		this->input_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (this->input_socket_fd == -1)
        {
			// socket creation failed
            return 1;
        }

		sockaddr_in input_socket_address = {
			.sin_family = AF_INET,
			.sin_port = htons(this->port),
			.sin_addr = {
				.s_addr = inet_addr(this->ip_address.c_str())
			}
		};
		if (bind(this->input_socket_fd, (sockaddr *)&input_socket_address, sizeof(input_socket_address)) == -1)
		{
			// bind failed
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

HttpWebserver::HttpWebserver(std::string ip_address, int port)
{
	this->startServer();
	this->ip_address = ip_address;
	this->port = port;
}
HttpWebserver::~HttpWebserver()
{
	this->stopServer();
}
