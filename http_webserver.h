#ifndef HTTP_WEBSERVER_H
#define HTTP_WEBSERVER_H

class HttpWebserver
{
	// want a private attribute: int input_socket_fd
	public:
		HttpWebserver(); // constructor
		~HttpWebserver(); // destructor

	private:
		int input_socket_fd;
		int startServer();
		int stopServer();

};

#endif
