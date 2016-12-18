--------------------
1. Main File List
--------------------
proxy_server_server.cpp	Sever side defining services

client.cpp		Client side calling services defined by server

src/

cache.h			cache header

cache.cpp		cache implementation

fifo.cpp		FIFO policy implementation

max.cpp			Max policy implementation

random.cpp		Random policy implementation

script/

test1			List of url for experiment(task1)

test2			List of url for experiment (task2)

parsing.py		Generating test url list

result/			To store result of experiments


--------------------
2. To Compile
--------------------

$make

This will generate files :
	proxy_server
	proxy_client

--------------------
3. To Run Experiment
--------------------

**Experiemnts should run only when Server is running**

./run.sh FILE_NAME		// Runs both test1 and test2
./run1.sh FILE_NAME		// Runs only test1
./run2.sh FILE_NAME		// Runs only test2

FILE NAME
	file name to store experiment result (execution time, cache hit count)

These expeiment scripts will let the Client to pass test urls to Server, and receive the result of experiment back.



--------------------
4. To Run Server
--------------------

Usage : proxy_server [options] 

Options:
	-h		For available options or help
	-size 	<num> 	Cache size, 2**<num> bytes (Default: 20 for 1MB)
	-policy <num> 	Replacement policy (Default: 0):
			0: 	no cache
			1: 	random
			2: 	fifo
			3: 	max size

Example: ./proxy_server -h
	 ./proxy_server -size 21 -policy 2


--------------------
5. To Run Client
--------------------

Usage : proxy_client TEST_FILE

	TEST_FILE
		We have two test files, test1 and test2.

Example : ./proxy_client test1

















