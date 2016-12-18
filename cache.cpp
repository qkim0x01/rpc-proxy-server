#include "cache.h"

Cache::Cache(size_t size){
  MaxSize = PolicyType ? size : 0;
  printf("Size of Cache %lu\n", size);
  TotalSize = 0;    
  NumEntry = 0;
  switch(PolicyType){
    case 0:
      policy = new RandomPolicy();
      printf("Replacement Policy - No Cache\n");
      break;
    case 1:
      policy = new RandomPolicy();
      printf("Replacement Policy - Random\n");
      break;
    case 2:
      policy = new FifoPolicy();
      printf("Replacement Policy - FIFO\n");
      break;
    case 3:
      policy = new MaxPolicy();
      printf("Replacement Policy - Max Size Eviction\n");
      break;
    default:
      policy = new RandomPolicy();
      printf("Replacement Policy - No Cache\n");
      break;
  }
//  policy = new MACRO_POLICY();
};

bool Cache::get(const std::string &url, web_req &req){
  if (PolicyType == 0) {return false;}
//  ReplacementPolicy* policy = new MACRO_POLICY();
  hash::const_iterator got = CacheMem.find (url);
  bool hit = got != CacheMem.end();
  if (hit){
    policy->update(url);
    req = got->second;
  }
  return hit;
};

void Cache::put(const std::string &url, web_req &req){
  if ((PolicyType == 0) || (req.size > MaxSize)) {return;}
  std::cout << url;
  printf(" Req size = %lu, Total Size = %lu, MaxSize = %lu\n", req.size, TotalSize, MaxSize);
	if (req.size == 0) {
    std::cout << url << " - empty request\n" << std::endl;
    return;
  }

	while((req.size + TotalSize) > MaxSize){
		std::string victim = policy->getURL();
		hash::const_iterator got = CacheMem.find (victim);
		TotalSize -= got->second.size;
    //std::cout << "Evicting " << victim << ", size " << got->second.size << ", timestamp " << got->second.ts << " usec" << std::endl;
		CacheMem.erase(victim);
	}
	CacheMem.emplace(url, req);
  TotalSize += req.size;
  policy->addURL(url, req);
};