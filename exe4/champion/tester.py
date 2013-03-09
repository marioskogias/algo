import os

count = raw_input()

for i in range(int(count)):
	print i+1       
	os.system("./champion < football/in"+str(i+1)+".txt")
	os.system("cat football/out"+str(i+1)+".txt")
