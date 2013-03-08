import os

count = raw_input()

for i in range(int(count)):
	print i+1	
	os.system("./dijkstra < racing/in"+str(i+1)+".txt")
	os.system("cat racing/out"+str(i+1)+".txt")
