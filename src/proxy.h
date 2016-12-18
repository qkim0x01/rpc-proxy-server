/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef proxy_H
#define proxy_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "proxy_server_types.h"

namespace proxy {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class proxyIf {
 public:
  virtual ~proxyIf() {}
  virtual void httpget(std::string& _return, const std::string& url) = 0;
  virtual void resetCounters() = 0;
  virtual int64_t getCacheHit() = 0;
  virtual int64_t getReqNum() = 0;
  virtual double getServerTime() = 0;
};

class proxyIfFactory {
 public:
  typedef proxyIf Handler;

  virtual ~proxyIfFactory() {}

  virtual proxyIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(proxyIf* /* handler */) = 0;
};

class proxyIfSingletonFactory : virtual public proxyIfFactory {
 public:
  proxyIfSingletonFactory(const boost::shared_ptr<proxyIf>& iface) : iface_(iface) {}
  virtual ~proxyIfSingletonFactory() {}

  virtual proxyIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(proxyIf* /* handler */) {}

 protected:
  boost::shared_ptr<proxyIf> iface_;
};

class proxyNull : virtual public proxyIf {
 public:
  virtual ~proxyNull() {}
  void httpget(std::string& /* _return */, const std::string& /* url */) {
    return;
  }
  void resetCounters() {
    return;
  }
  int64_t getCacheHit() {
    int64_t _return = 0;
    return _return;
  }
  int64_t getReqNum() {
    int64_t _return = 0;
    return _return;
  }
  double getServerTime() {
    double _return = (double)0;
    return _return;
  }
};

typedef struct _proxy_httpget_args__isset {
  _proxy_httpget_args__isset() : url(false) {}
  bool url :1;
} _proxy_httpget_args__isset;

class proxy_httpget_args {
 public:

  proxy_httpget_args(const proxy_httpget_args&);
  proxy_httpget_args& operator=(const proxy_httpget_args&);
  proxy_httpget_args() : url() {
  }

  virtual ~proxy_httpget_args() throw();
  std::string url;

  _proxy_httpget_args__isset __isset;

  void __set_url(const std::string& val);

  bool operator == (const proxy_httpget_args & rhs) const
  {
    if (!(url == rhs.url))
      return false;
    return true;
  }
  bool operator != (const proxy_httpget_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const proxy_httpget_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class proxy_httpget_pargs {
 public:


  virtual ~proxy_httpget_pargs() throw();
  const std::string* url;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _proxy_httpget_result__isset {
  _proxy_httpget_result__isset() : success(false) {}
  bool success :1;
} _proxy_httpget_result__isset;

class proxy_httpget_result {
 public:

  proxy_httpget_result(const proxy_httpget_result&);
  proxy_httpget_result& operator=(const proxy_httpget_result&);
  proxy_httpget_result() : success() {
  }

  virtual ~proxy_httpget_result() throw();
  std::string success;

  _proxy_httpget_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const proxy_httpget_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const proxy_httpget_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const proxy_httpget_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _proxy_httpget_presult__isset {
  _proxy_httpget_presult__isset() : success(false) {}
  bool success :1;
} _proxy_httpget_presult__isset;

class proxy_httpget_presult {
 public:


  virtual ~proxy_httpget_presult() throw();
  std::string* success;

  _proxy_httpget_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class proxy_resetCounters_args {
 public:

  proxy_resetCounters_args(const proxy_resetCounters_args&);
  proxy_resetCounters_args& operator=(const proxy_resetCounters_args&);
  proxy_resetCounters_args() {
  }

  virtual ~proxy_resetCounters_args() throw();

  bool operator == (const proxy_resetCounters_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const proxy_resetCounters_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const proxy_resetCounters_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class proxy_resetCounters_pargs {
 public:


  virtual ~proxy_resetCounters_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class proxy_resetCounters_result {
 public:

  proxy_resetCounters_result(const proxy_resetCounters_result&);
  proxy_resetCounters_result& operator=(const proxy_resetCounters_result&);
  proxy_resetCounters_result() {
  }

  virtual ~proxy_resetCounters_result() throw();

  bool operator == (const proxy_resetCounters_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const proxy_resetCounters_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const proxy_resetCounters_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class proxy_resetCounters_presult {
 public:


  virtual ~proxy_resetCounters_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class proxy_getCacheHit_args {
 public:

  proxy_getCacheHit_args(const proxy_getCacheHit_args&);
  proxy_getCacheHit_args& operator=(const proxy_getCacheHit_args&);
  proxy_getCacheHit_args() {
  }

  virtual ~proxy_getCacheHit_args() throw();

  bool operator == (const proxy_getCacheHit_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const proxy_getCacheHit_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const proxy_getCacheHit_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class proxy_getCacheHit_pargs {
 public:


  virtual ~proxy_getCacheHit_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _proxy_getCacheHit_result__isset {
  _proxy_getCacheHit_result__isset() : success(false) {}
  bool success :1;
} _proxy_getCacheHit_result__isset;

class proxy_getCacheHit_result {
 public:

  proxy_getCacheHit_result(const proxy_getCacheHit_result&);
  proxy_getCacheHit_result& operator=(const proxy_getCacheHit_result&);
  proxy_getCacheHit_result() : success(0) {
  }

  virtual ~proxy_getCacheHit_result() throw();
  int64_t success;

  _proxy_getCacheHit_result__isset __isset;

  void __set_success(const int64_t val);

  bool operator == (const proxy_getCacheHit_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const proxy_getCacheHit_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const proxy_getCacheHit_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _proxy_getCacheHit_presult__isset {
  _proxy_getCacheHit_presult__isset() : success(false) {}
  bool success :1;
} _proxy_getCacheHit_presult__isset;

class proxy_getCacheHit_presult {
 public:


  virtual ~proxy_getCacheHit_presult() throw();
  int64_t* success;

  _proxy_getCacheHit_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class proxy_getReqNum_args {
 public:

  proxy_getReqNum_args(const proxy_getReqNum_args&);
  proxy_getReqNum_args& operator=(const proxy_getReqNum_args&);
  proxy_getReqNum_args() {
  }

  virtual ~proxy_getReqNum_args() throw();

  bool operator == (const proxy_getReqNum_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const proxy_getReqNum_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const proxy_getReqNum_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class proxy_getReqNum_pargs {
 public:


  virtual ~proxy_getReqNum_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _proxy_getReqNum_result__isset {
  _proxy_getReqNum_result__isset() : success(false) {}
  bool success :1;
} _proxy_getReqNum_result__isset;

class proxy_getReqNum_result {
 public:

  proxy_getReqNum_result(const proxy_getReqNum_result&);
  proxy_getReqNum_result& operator=(const proxy_getReqNum_result&);
  proxy_getReqNum_result() : success(0) {
  }

  virtual ~proxy_getReqNum_result() throw();
  int64_t success;

  _proxy_getReqNum_result__isset __isset;

  void __set_success(const int64_t val);

  bool operator == (const proxy_getReqNum_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const proxy_getReqNum_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const proxy_getReqNum_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _proxy_getReqNum_presult__isset {
  _proxy_getReqNum_presult__isset() : success(false) {}
  bool success :1;
} _proxy_getReqNum_presult__isset;

class proxy_getReqNum_presult {
 public:


  virtual ~proxy_getReqNum_presult() throw();
  int64_t* success;

  _proxy_getReqNum_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class proxy_getServerTime_args {
 public:

  proxy_getServerTime_args(const proxy_getServerTime_args&);
  proxy_getServerTime_args& operator=(const proxy_getServerTime_args&);
  proxy_getServerTime_args() {
  }

  virtual ~proxy_getServerTime_args() throw();

  bool operator == (const proxy_getServerTime_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const proxy_getServerTime_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const proxy_getServerTime_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class proxy_getServerTime_pargs {
 public:


  virtual ~proxy_getServerTime_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _proxy_getServerTime_result__isset {
  _proxy_getServerTime_result__isset() : success(false) {}
  bool success :1;
} _proxy_getServerTime_result__isset;

class proxy_getServerTime_result {
 public:

  proxy_getServerTime_result(const proxy_getServerTime_result&);
  proxy_getServerTime_result& operator=(const proxy_getServerTime_result&);
  proxy_getServerTime_result() : success(0) {
  }

  virtual ~proxy_getServerTime_result() throw();
  double success;

  _proxy_getServerTime_result__isset __isset;

  void __set_success(const double val);

  bool operator == (const proxy_getServerTime_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const proxy_getServerTime_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const proxy_getServerTime_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _proxy_getServerTime_presult__isset {
  _proxy_getServerTime_presult__isset() : success(false) {}
  bool success :1;
} _proxy_getServerTime_presult__isset;

class proxy_getServerTime_presult {
 public:


  virtual ~proxy_getServerTime_presult() throw();
  double* success;

  _proxy_getServerTime_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class proxyClient : virtual public proxyIf {
 public:
  proxyClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  proxyClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void httpget(std::string& _return, const std::string& url);
  void send_httpget(const std::string& url);
  void recv_httpget(std::string& _return);
  void resetCounters();
  void send_resetCounters();
  void recv_resetCounters();
  int64_t getCacheHit();
  void send_getCacheHit();
  int64_t recv_getCacheHit();
  int64_t getReqNum();
  void send_getReqNum();
  int64_t recv_getReqNum();
  double getServerTime();
  void send_getServerTime();
  double recv_getServerTime();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class proxyProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<proxyIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (proxyProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_httpget(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_resetCounters(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getCacheHit(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getReqNum(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getServerTime(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  proxyProcessor(boost::shared_ptr<proxyIf> iface) :
    iface_(iface) {
    processMap_["httpget"] = &proxyProcessor::process_httpget;
    processMap_["resetCounters"] = &proxyProcessor::process_resetCounters;
    processMap_["getCacheHit"] = &proxyProcessor::process_getCacheHit;
    processMap_["getReqNum"] = &proxyProcessor::process_getReqNum;
    processMap_["getServerTime"] = &proxyProcessor::process_getServerTime;
  }

  virtual ~proxyProcessor() {}
};

class proxyProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  proxyProcessorFactory(const ::boost::shared_ptr< proxyIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< proxyIfFactory > handlerFactory_;
};

class proxyMultiface : virtual public proxyIf {
 public:
  proxyMultiface(std::vector<boost::shared_ptr<proxyIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~proxyMultiface() {}
 protected:
  std::vector<boost::shared_ptr<proxyIf> > ifaces_;
  proxyMultiface() {}
  void add(boost::shared_ptr<proxyIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void httpget(std::string& _return, const std::string& url) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->httpget(_return, url);
    }
    ifaces_[i]->httpget(_return, url);
    return;
  }

  void resetCounters() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->resetCounters();
    }
    ifaces_[i]->resetCounters();
  }

  int64_t getCacheHit() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getCacheHit();
    }
    return ifaces_[i]->getCacheHit();
  }

  int64_t getReqNum() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getReqNum();
    }
    return ifaces_[i]->getReqNum();
  }

  double getServerTime() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getServerTime();
    }
    return ifaces_[i]->getServerTime();
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class proxyConcurrentClient : virtual public proxyIf {
 public:
  proxyConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  proxyConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void httpget(std::string& _return, const std::string& url);
  int32_t send_httpget(const std::string& url);
  void recv_httpget(std::string& _return, const int32_t seqid);
  void resetCounters();
  int32_t send_resetCounters();
  void recv_resetCounters(const int32_t seqid);
  int64_t getCacheHit();
  int32_t send_getCacheHit();
  int64_t recv_getCacheHit(const int32_t seqid);
  int64_t getReqNum();
  int32_t send_getReqNum();
  int64_t recv_getReqNum(const int32_t seqid);
  double getServerTime();
  int32_t send_getServerTime();
  double recv_getServerTime(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif