CXX=g++

all: http_webserver

http_webserver: main.cpp http_webserver.cpp
	$(CXX) -I ./ -o http_webserver main.cpp http_webserver.cpp

clean:
	rm -f http_webserver