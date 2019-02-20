#!/usr/local/bin/python
import csv
#open resources and change the last number from 1 to 0
f=open('resources.csv', 'rw')
read=csv.reader(f)
for row in read:
	rManna=row[0]
	rGold=row[1]
	rOccupied=row[2]
f.close()

with open("resources.csv", "wb") as f2:
	write=csv.writer(f2)
	write.wroterow([rManna, rGold, '0'])	
f2.close()
print "Content-type: text/html\n\n"
print("<html\n<\html>\n")
