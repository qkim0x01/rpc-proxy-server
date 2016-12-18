import random

fobj = open("output.log")

url_list = []
size_list = []

url_list.append("START")
size_list.append(0)

found = 0
for line in fobj :
	token = line.split('|')
	if token[0] == "SIZE" :
		curr_size = token[3]
		curr_url = token[1]
		list_len = len(url_list)
		for i in xrange(0, len(url_list)) :
			if int(size_list[i]) < int(curr_size) and found == 0:
				found = 1
				url_list.insert(i, curr_url)
				size_list.insert(i, curr_size)
		found = 0
A_size = []
A_url = []
B_size = []
B_url = []
C_size = []
C_url = []
D_size = []
D_url = []
E_size = []
E_url = []

for i in xrange(0, len(url_list)) :
	if int(size_list[i]) > 100000 :
		A_url.append(url_list[i])
		A_size.append(size_list[i])
	elif int(size_list[i]) > 50000 :
		B_url.append(url_list[i])
		B_size.append(size_list[i])
	elif int(size_list[i]) > 10000 :
		C_url.append(url_list[i])
		C_size.append(size_list[i])
	elif int(size_list[i]) > 1000 :
		D_url.append(url_list[i])
		D_size.append(size_list[i])
	else:
		E_url.append(url_list[i])
		E_size.append(size_list[i])

def print_list(pa_list):
	for i in xrange(0, len(pa_list)) :
		print "%s" %(pa_list[i])

def print_all(pa_list, pa_size):
	for i in xrange(0, len(pa_list)) :
		print "%s | %s" %(pa_list[i], pa_size[i])

def print_random(pa_list, pa_size, number):
	size = len(pa_list)
	found_list = []
	found_size = []
	found = 0
	tmp = 0
	for i in xrange(0, number):
		index = random.randint(0,size-1)
		tmp = pa_list[index]
		tmp_size = pa_size[index]
		for j in xrange(0, len(found_list)) :
			if tmp == found_list[j] :
				found = 1
		if found == 0:
			found_list.append(tmp)
			found_size.append(tmp_size)
	print_list(found_list)
	#print_all(found_list, found_size)
		
		
		


number = 5
#D C D E D C D E 
print_list(D_url)
print_random(C_url, C_size, number)
print_list(D_url)
print_random(E_url, E_size, number)
print_list(D_url)
print_random(C_url, C_size, number)
print_list(D_url)
print_random(E_url, E_size, number)

	

			
			

			
	
