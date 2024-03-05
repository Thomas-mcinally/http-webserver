#ifndef HTTP_WEBSERVER_H
#define HTTP_WEBSERVER_H

class HttpWebserver
{
	// want a private attribute: int input_socket_fd
	public:
		HttpWebserver(); // constructor
		~HttpWebserver(); // destructor
		void printGreeting();
		int startServer();
		int stopServer();
	private:
		int input_socket_fd;

};

#endif
