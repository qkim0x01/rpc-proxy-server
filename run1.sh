#!/bin/bash
echo "Warming up caches ..."
./proxy_client test1 > /dev/null
for ii in `seq 1 5`;
do
	echo $'\n================================================================'
	echo $'\nTesting RPC Proxy Server, test set 1, run' $ii $'\n'
	./proxy_client test1
done
echo $'\n================================================================'