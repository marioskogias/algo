import os

count = raw_input()

for i in range(int(count)):
	print i+1
	os.system("./headquarter < headquarters/input"+str(i+1)+".txt")
	os.system("cat headquarters/output"+str(i+1)+".txt")
