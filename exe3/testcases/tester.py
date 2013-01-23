import os

count = raw_input()

for i in range(int(count)):
	print i+1
	os.system("./testcase < testcases/input"+str(i+1)+".txt")
	os.system("cat testcases/output"+str(i+1)+".txt")
