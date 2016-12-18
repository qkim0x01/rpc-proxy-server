#include "cache.h"

void MaxPolicy::addURL(const std::string &url, web_req &req){
	URL_Max_Struct new_url;
	new_url.url = url;
	new_url.size = req.size;
	url_queue.push(new_url);
};

std::string MaxPolicy::getURL(){
	URL_Max_Struct url_st = url_queue.top();
	std::string url = url_st.url;
	url_queue.pop();
	return url;
};