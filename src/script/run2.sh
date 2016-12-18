#!/bin/bash
echo "Warming up caches ..."
./../proxy_client test2 > /dev/null
for ii in `seq 1 5`;
do
	echo $'\n================================================================'
	echo $'\nTesting RPC Proxy Server, test set 2, run' $ii $'\n'
	./../proxy_client test2 > ../../result/$1
done
echo $'\n================================================================'
