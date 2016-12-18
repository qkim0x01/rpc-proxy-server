#include <string>
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <vector>
#include <unordered_map>
#include <queue> 

#ifndef CACHE_H
#define CACHE_H

extern int PolicyType;

//page Structure
typedef struct {
  	std::string page;
  	size_t size;
  	unsigned long long ts;
} web_req;

typedef struct URL_Max_Struct {
  std::string url;
  size_t size;

  bool operator<(const URL_Max_Struct &url_ii) const
    {
        return size < url_ii.size;
    }
} URL_Max_Struct;

typedef struct URL_fifo_Struct {
  std::string url;
  unsigned long long ts;

  bool operator<(const URL_fifo_Struct &url_ii) const
    {
        return ts > url_ii.ts;
    }
} URL_fifo_Struct;

typedef std::unordered_map<std::string, web_req> hash;

class ReplacementPolicy{
  public:
    virtual void update(const std::string &url) = 0;
    virtual void addURL(const std::string &url, web_req &req) = 0;
    virtual std::string getURL() = 0;

    virtual ~ReplacementPolicy(){};
};

class RandomPolicy : public ReplacementPolicy{
  private:
    std::vector<std::string> url_set;

  public:
    RandomPolicy(){};
    ~RandomPolicy(){};

    void update(const std::string &url){};
    void addURL(const std::string &url, web_req &req);
    std::string getURL();
};

class MaxPolicy : public ReplacementPolicy{
  private:
    std::priority_queue<URL_Max_Struct> url_queue;

  public:
    MaxPolicy(){};
    ~MaxPolicy(){};

    void update(const std::string &url){};
    void addURL(const std::string &url, web_req &req);
    std::string getURL();
};

class FifoPolicy : public ReplacementPolicy{
  private:
    std::priority_queue<URL_fifo_Struct> url_queue;

  public:
    FifoPolicy(){};
    ~FifoPolicy(){};

    void update(const std::string &url){};
    void addURL(const std::string &url, web_req &req);
    std::string getURL();
};

class Cache {
 	private:
    size_t MaxSize;
    size_t TotalSize;
    size_t NumEntry;
    hash CacheMem;
    ReplacementPolicy* policy;

	public:
		explicit Cache(size_t size = 1 << 20);
    ~Cache(){
      delete policy;
    };

  	bool get(const std::string &url, web_req &req);
  	void put(const std::string &url, web_req &req);
};

#endif