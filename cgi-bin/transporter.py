#!/usr/local/bin/python
import cgi
import string
import csv

#setting the inventory
form = cgi.FieldStorage()
inventory=form.getvalue('inventory')
if (form.getvalue("URL")):
	link=form.getvalue('URL')

if(form.getvalue("url")):
	link=form.getvalue('url')

playerValues = inventory.split(',')
pManna=int(playerValues[0])
pGold=int(playerValues[1])

#taking resources from csv file
f1=open('resources.csv', 'r+')
for row in csv.reader(f1)
	rManna=row[0]
	rGold=row[1]
	rOccupied=row[2]
f.close()

#if room is unoccupied
if rOccupied=='0':
	with open("resources.csv", "wb") as f2:
		write=csv.writer(f2)
		write.writerow([rManna,rGold,'0'])
	f2.close()
	print"Content-type:text/html\r\n\r\n"
	print'<html>'
	print'<form action="room.cgi" style="display: inline">'
	print'<inpit type="hidden" name="inventory" value=\"%d,%d\"/>' % (pManna, pGold)
	print'<input type="hidden" name="command" value="REFRESH">'
	print'<input type="submit" value="Go to room"/>'
	print'<object type="text/html" data="%s/cgi-bin/success.py">'
	print'</object>'

#if room is occupied
else:
	print"Content-type:text/html\r\n\r\n"
	print'<html>'
	print'<body>'
	print'<h1> Page Occupied. We will send you back. Try again later</h1>'
	print'<form action=\"%s\">' % link
	print'<input type \"hidden\" name=\"inventory\" value=\"%d,%d\">' % (pManna, pGold)
	print'<input type=\"hidden\" name=\"URL\" value=\"%s\">' % url
	print'<input type=\"submit\" value=\"Back to the last page\">'
	print'</form>'
	print'</body>'
	print'</html>'
