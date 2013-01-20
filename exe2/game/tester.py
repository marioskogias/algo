import os

count = raw_input()

for i in range(int(count)):
	print i+1
	os.system("./test < game/input"+str(i+1)+".txt")
	os.system("cat game/output"+str(i+1)+".txt")
