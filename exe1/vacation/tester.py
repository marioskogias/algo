import os

count = raw_input()

for i in range(int(count)):
	print i+1	
	os.system("./vacation < winter-vac/input"+str(i+1)+".txt")
	os.system("cat winter-vac/output"+str(i+1)+".txt")
	