import os

count = raw_input()

for i in range(int(count)):
	print i+1	
	os.system("./kiosk < kiosks/input"+str(i+1)+".txt")
	os.system("cat kiosks/output"+str(i+1)+".txt")