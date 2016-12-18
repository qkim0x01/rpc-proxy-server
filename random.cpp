#include "cache.h"

void RandomPolicy::addURL(const std::string &url, web_req &req){
	url_set.push_back(url);
};

std::string RandomPolicy::getURL(){
	int index = rand() % url_set.size();
	std::string url = url_set[index];
	url_set.erase(url_set.begin() + index);
	return url;
};