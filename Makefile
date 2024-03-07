CXX=g++
CXXFLAGS=-I ./

all: debug release

debug:
	$(CXX) $(CXXFLAGS) -DDEBUG -o http_webserver_debug main.cpp http_webserver.cpp

release:
	$(CXX) $(CXXFLAGS) -o http_webserver main.cpp http_webserver.cpp

clean:
	rm -f http_webserver http_webserver_debug