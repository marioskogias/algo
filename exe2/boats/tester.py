import os

count = raw_input()

for i in range(int(count)):
	print i+1
	os.system("./boat < boats/input"+str(i+1)+".txt")
	os.system("cat boats/output"+str(i+1)+".txt")
