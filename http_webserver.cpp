#include <stdio.h>
#include "http_webserver.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <sstream>

#define TCP_BUFFER_SIZE 10000

int HttpWebserver::startListen()
{
	// max 5 connections in queue
	if (listen(this->input_socket_fd, 5) == -1)
	{
		// listen failed
		return 1;
	}

	printf("Server listening on %s:%d\n", this->ip_address.c_str(), this->port);


	sockaddr_in input_socket_address = {
				.sin_family = AF_INET,
				.sin_port = htons(this->port),
				.sin_addr = {
					.s_addr = inet_addr(this->ip_address.c_str())
				}
			};
	unsigned long address_len = sizeof(input_socket_address);
	int bytesReceived;
	while (true)
	{
		printf("Waiting for connection...\n");

		this->cur_conn_socket_fd = accept(this->input_socket_fd, (sockaddr *)&input_socket_address, (socklen_t *)&address_len);

		char tcp_buffer[TCP_BUFFER_SIZE] = {0};
		bytesReceived = read(this->cur_conn_socket_fd, tcp_buffer, TCP_BUFFER_SIZE);
		if (bytesReceived == -1)
		{
			// read failed
			return 1;
		}

		printf("Received message from client: %s\n", tcp_buffer);

		std::string htmlFile = "<!DOCTYPE html><html lang=\"en\"><body><h1> HOME </h1><p> Hello from server! </p></body></html>";
        std::ostringstream ss;
        ss << "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " << htmlFile.size() << "\n\n"
           << htmlFile;
		std::string response = ss.str();

		int bytesSent;
		bytesSent = write(this->cur_conn_socket_fd, response.c_str(), response.size());
		if (bytesSent == -1)
		{
			// write failed
			return 1;
		}
		printf("Sent message to client\n");
		close(this->cur_conn_socket_fd);
	}

	return 0;
}

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
	this->ip_address = ip_address;
	this->port = port;
	this->startServer();
}

HttpWebserver::~HttpWebserver()
{
	this->stopServer();
}
