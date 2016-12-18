#include "cache.h"

void FifoPolicy::addURL(const std::string &url, web_req &req){
	URL_fifo_Struct new_url;
	new_url.url = url;
	new_url.ts = req.ts;
	url_queue.push(new_url);
};

std::string FifoPolicy::getURL(){
	URL_fifo_Struct url_st = url_queue.top();
	std::string url = url_st.url;
	url_queue.pop();
	return url;
};

/*
int main() {
	web_req hey;
	hey.url
	FifoPolicy *fifo = new FifoPolicy();

	fifo->addURL("google", hey);
}
*/