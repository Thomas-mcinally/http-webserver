#ifndef HTTP_WEBSERVER_H
#define HTTP_WEBSERVER_H

#include <string>
class HttpWebserver
{
	public:
		HttpWebserver(std::string ip_address, int port); // constructor
		~HttpWebserver(); // destructor

	private:
		int port;
		std::string ip_address;
		int input_socket_fd;
		int startServer();
		int stopServer();

};

#endif
