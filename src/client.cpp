#include <iostream>
#include <fstream>
#include <string>

#include "proxy.h"

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

//using namespace std;
using namespace proxy;

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

void testrun(char* filename, std::string url, proxyClient client){
	std::ifstream url_file;
	std::string result;

	url_file.open(filename);
	if (url_file.is_open()) {
		while (getline(url_file, url)) {
//			std::cout << url << " ++++++++++++++++++++++++++\n";
			client.httpget(result, url);
//			std::cout << result << std::endl;
		}
		url_file.close();
	}
}

int main(int argc, char** argv) {

	std::string url;
	
	char *filename;
	int64_t cache_hit;
  	int64_t requests;
  	double server_time, client_time = 0;
  	struct timeval t_start, t_end;

	shared_ptr<TTransport> socket(new TSocket("Yubuntu",9090));
	shared_ptr<TTransport> transport(new TBufferedTransport(socket));

	shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	proxyClient client(protocol);

	transport->open();

	filename = argv[1];

	//Cache warming
/*	printf("Warming up caches ...\n\n");
	testrun(filename, url, client);

	printf("Performing testing ... \n\n");
*/
	client.resetCounters();
	gettimeofday(&t_start, NULL);
	testrun(filename, url, client);
	gettimeofday(&t_end, NULL);

	client_time = (double)(t_end.tv_sec - t_start.tv_sec) + (double)(t_end.tv_usec - t_start.tv_usec)/1000000;

	cache_hit = client.getCacheHit();
	requests = client.getReqNum();
	server_time = client.getServerTime();

	printf("Server time - %f, Client time - %f\n", server_time, client_time);
	printf("%ld hits out of %ld requests\n", cache_hit, requests);
}
