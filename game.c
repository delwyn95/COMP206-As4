#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "helper.h"

void correct(){
//Checks if room is depeted
	if(rManna == 0 && rGold == 0){
		printf("This room has no more resources.");
		
		printf("<form action=\"room.cgi\">");
		printf("<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pManna, pGold);
		printf("<input type=\"hidden\" name=\"command\" value=\"REFRESH\">");
		printf("<input type=\"submit\" value=\"Go back to entrance\">");
		printf("</form>");
	}
	else{
		printf("<html>");
		printf("<head>");
		printf("<title>Rewards</title>");
		printf("</head>");
		printf("<body style=\"text-align: center\">");	
		printf("<h1 style=\"color:#008000;\">Yes that's correct! Now we're one step closer to saving the world!.</h1><p>");
		printf("Room manna: %d<br>", rManna);
		printf("Room gold: %d<p>", rGold);
		printf("Choose your reward. No more than 5 total items!Enter 0 if you dont want that reward<br>");
		printf("<form action=\"correct.cgi\">");
		printf("<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\"/>", pManna, pGold);
		printf("<input type=\"hidden\" name=\"command\" value=\"11\">");
		printf("Manna: ");
		printf("<input type=\"text\" name=\"manna\"><br>");;
		printf("Gold: ");
		printf("<input type=\"text\" name=\"gold\"><br>");
		printf("<input type=\"submit\" value=\"Submit\">");
		printf("</form>");
		printf("</body>");
		printf("</html>");
	}
}
//Function will print a page to play again
void incorrect(){
	printf("<html>");
	printf("<body style=\"text-align: center\">");
	printf("<font color=\"blue\">Available commands:</font><br>");
	printf("<font color=\"blue\">- Type \"QUIT\" to quit the challenge</font><p>");
	printf("Rooms manna: %d<br>", rManna);
	printf("Rooms gold: %d<br>", rGold);
	printf("<img src=\"../room.jpg\" align=\"center\" alt=\"The Partition Room\">");
	printf("<p>");
	printf("<html>In this room resides a mathematician. He is about to find the equation that will save all of humanity, but he needs your help! Quick, how many partitions are there of the number 6? (enter number) <p>");
	printf("<form action=\"game.cgi\">");
	printf("<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pManna, pGold);
	printf("<input type=\"text\" name=\"command\"/>");
	printf("<input type=\"submit\" value=\"Submit\">");
	printf("</form>");
	printf("</body>");
	printf("</html>");	
}

int main(void){
	rRead(); //reads the file and sets Manna/Gold Value
	char *input;
	if(input = getenv("QUERY_STRING")){
		char buff[100];
		char cmd[20];
		char *tok;
		char *upr = upper(cmd);
		int n;
		
		//Takes the QUERY input in the the array value.
		strncpy(buff,input,99);
		tok = strtok(buff, "&");
		sscanf(tok,"inventory=%d%%2C%d",&pManna,&pGold);
		tok = strtok(NULL,"&");
		sscanf(tok,"command=%s",cmd);
		n=atoi(cmd); //sets  array into an int value (used to compare with answer).

		printf("Content-Type:text/html\n\n");
		
		if(n == 11){
			correct();
		}
		else if(strcmp(upr,"QUIT")==0){
			printf("<form action=\"room.cgi\">");
			printf("<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pManna, pGold);
			printf("<input type=\"hidden\" name=\"command\" value=\"REFRESH\">");
			printf("<input type=\"submit\" value=\"Go back to entrance\">");
			printf("</form>");
		}
		else if(n != 11){ //anything else but answer.
			printf("No no... This doesnt make sense!");
			printf(" This equation would destroy the world in that case, not save it.");
			printf(" Try again");
			incorrect();
		}
	}
	else{
		printf("No input was received, hurry up and try again!");
	}
}







