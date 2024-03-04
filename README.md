# webserver
## High level design
- The HTTP webserver will be a constantly running C++ program which does the following
- Uses kernel to set up a socket, which is basically a queue of incoming network connections
  - Kernel listens to incoming network connections and places them on the queue (unless it is full)
- Processes network calls from the queue synchronously, one at a time
- Reads the HTTP message sent by the client and responds with a HTTP response unrelated to the input message

## Acceptance criteria
- When running the server, someone (e.g. my girlfriend) should be able to send me messages from their terminal (using CURL). They should receive a response saying the message was received
- Solution should have some basic tests - first time writing tests in C++
- Solution should have a MakeFile that enables project to be compiled and run locally
- Solution should have a DockerFile that enables project to be run easily, with Docker as the only prerequisite
  - My webserver will have minimal security considerations, so running it inside Docker is probably safer anyways


## Inspiration
- https://github.com/OsasAzamegbe/http-server
- https://osasazamegbe.medium.com/showing-building-an-http-server-from-scratch-in-c-2da7c0db6cb7
