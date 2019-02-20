#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* resources="resources.csv";
int rManna=0;
int rGold=0;
int rOccupied=0;
int pManna=1;
int pGold=0;

//methods used in other classes

//copying the room.html for the refresh

const char* roomhtml=
"<html>"
"	<head>"
"		<title> Partition Room  </title>"
"	</head>"
""
"	<h1 align=\"center\"> Welcome to the partition room</h1>"
""
"	<body style=\"background-color:#d5d5ff\">"
"		<center><img src = \"https://s-media-cache-ak0.pinimg.com/originals/7b/5c/5a/7b5c5a974b308531bbd2cb747f5cc5b0.jpg\" border = 1></center> </br>"
""
""					
"<!-- FORM -->"
"<p align=\"center\">"
"   <p><h4 style =\"color:black;text-align:center;\">You may not be the Hero the World Deserves~</h4></p>"
"    <p><h4 style =\"color:black;text-align:center;\">But You can be the Hero the World Needs</h4></p>"
""
"	<form action=\"room.cgi\" style=\"display: inline\">"
"		<input type=\"hidden\" name=\"inventory\" value=\"1,0\"/>"
"		<input type=\"text\" name=\"command\"/>"
"		<input type=\"submit\" value=\"Submit\"/>"
"	</form>"
""
"<h5 style =\"color:black;text-align:center\">"
"    PLAY/EXIT/REFRESH/DROP n :"
"<br> <br> For every 2 gold you drop, you get 1 mana."
"</h5>"
"</p>"
""
""
"</br>"
"</br>"
"<!-- Direction -->"
"		<center><form action=\"http://cgi.cs.mcgill.ca/~jmonti4/project2/transporter.py\">"
"			<input type=\"submit\" value=\"North\"/>"
"			<input type=\"hidden\" name=\"inventory\" value=\"1,0\"/>"
"			<input type=\"hidden\" name=\"URL\" value=\"http://cs.mcgill.ca/~habdel16/room.html\"/>"
"		</form></center>"
""
""
""
"		<center><form action=\"http://cgi.cs.mcgill.ca/~jmonti4/project2/transporter.py\" style=\"display: inline;\">"
"			<input type=\"submit\" value=\"West\"/>"
"			<input type=\"hidden\" name=\"inventory\" value=\"1,0\"/>"
"			<input type=\"hidden\" name=\"URL\" value=\“http://cs.mcgill.ca/~habdel16/room.html\”/>"
"		</form>"
""
""
"		<!--You stand in a room. What do you do? -->"
"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"
""
"		<form action=\"http://cgi.cs.mcgill.ca/~jmonti4/project2/transporter.py\" style=\"display: inline;\">"
"			<input type=\"submit\" value=\"East\"/>"
"			<input type=\"hidden\" name=\"inventory\" value=\"1,0\"/>"
"			<input type=\"hidden\" name=\"URL\" value=\"http://cs.mcgill.ca/~habdel16/room.html\"/>"
"		</form></center></br>"
""
""
"		<center><form action=\"http://cgi.cs.mcgill.ca/~jmonti4/project2/transporter.py\" >"
"			<input type=\"submit\" value=\"South\"/>"
"			<input type=\"hidden\" name=\"inventory\" value=\"1,0\"/>"
"			<input type=\"hidden\" name=\"URL\" value=\"http://cs.mcgill.ca/~habdel16/room.html\"/>"
"		</form></center></br>"
"	</body>"
"</html>"
;


//a method that changes the letters to upper case
char *upper (char cmd[]){
	int l = strlen(cmd);
	for (int i = 0; i < l; i++){
		cmd[i] = toupper(cmd[i]);
	}
	
	char *up = cmd;

	return up;
}

//write to the csv
void rWrite(){
	FILE *f=fopen(resources, "w");
	fprintf(f, "%d,%d,%d", rManna, rGold, rOccupied);
	fclose(f);
}

//read from the csv and change room manna, gold and occupied status
void rRead(){
	FILE *f=fopen(resources, "r");
	fscanf(f, "%d,%d,%d", &rManna, &rGold, &rOccupied);
	fclose(f);
}



//drop: 
//if it failed, print that it failed, and refresh

void drop(int n){
	if (pGold < n){
		printf("You dont have that amount of gold to drop! It's simple math really.");
		printf("<form action=\"room.cgi\">");
		printf("<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\"/>", pManna, pGold);
		printf("<input type=\"hidden\" name=\"command\" value=\"REFRESH\">");
		printf("<input type=\"submit\" value=\"Back to the room\">");
		printf("</form>");
	}

//change the player and room gold/mana and edit inventory and refresh
	else{
		pGold=pGold - n;
		rGold=rGold + n;
		pManna = pManna + (n/2);
		rWrite();

		printf("%d gold was dropped and %d manna was gained!", n, (n/2));
		printf("<form action=\"room.cgi\">");
		printf("<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\"/>", pManna, pGold);
		printf("<input type=\"hidden\" name=\"command\" value=\"REFRESH\">");
		printf("<input type=\"submit\" value=\"Back to the room\">");
		printf("</form>");
	}
}



