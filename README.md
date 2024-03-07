# webserver
- Totally unsafe and shouldn't be used for anything important
- This is a toy project i made to get a better understanding of the internals of a webserver such as [NGINX](https://nginx.org/en/) and [ASGI](https://asgi.readthedocs.io/en/latest/introduction.html) (used with [Uvicorn](https://www.uvicorn.org/))

## High level design
- The HTTP webserver will be a constantly running C++ program which does the following
- Uses kernel to set up a socket that acts as a queue for incoming network connections
  - Kernel listens to incoming network connections and places them on the queue (unless it is full)
- Processes network calls from the queue synchronously, one at a time
- Reads the HTTP message sent by the client ans sends a response acknowledging that the message was received

## Acceptance criteria
- When running the server, someone (e.g. my girlfriend) should be able to send me messages from their terminal (using CURL). They should receive a response saying the message was received
- Solution should have some basic tests - first time writing tests in C++
- Solution should have a MakeFile that enables project to be compiled and run locally
- Solution should have a DockerFile that enables project to be run easily, with Docker as the only prerequisite
  - My webserver will have minimal security considerations, so running it inside Docker is probably safer anyways

## Scripts
Compile and run (using Cmake)
- `make && ./http_webserver`
