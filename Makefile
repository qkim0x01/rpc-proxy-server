LIBS		:=-L/usr/local/lib -lthrift -lcurl

GEN_SRC 	:= proxy_server_constants.cpp proxy_server_types.cpp proxy.cpp max.cpp random.cpp fifo.cpp
GEN_OBJ 	:= $(patsubst %.cpp,%.o, $(GEN_SRC))

THRIFT_DIR 	:= /usr/local/include/thrift
BOOST_DIR 	:= /usr/local/include

INC 		:= -I$(THRIFT_DIR) -I$(BOOST_DIR)
CPP_OPTS 	:= -Wall -std=c++11 -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H $(INC) #-DMACRO_POLICY=$(POLICY)Policy
CPP_FLAGS	:= -Wall -std=c++11
#POLICY 		:= Max


.PHONY: all clean

all: proxy_server proxy_client

%.o: %.cpp
		$(CXX) ${CPP_FLAGS} -c $< -o $@

proxy_server: proxy_server.cpp $(GEN_OBJ) cache.cpp
	$(CXX) -std=c++11 $^ -o proxy_server ${LIBS}

proxy_client: client.o $(GEN_OBJ)
		$(CXX) $^ -o $@ ${LIBS}

clean:
		$(RM) *.o proxy_server proxy_client