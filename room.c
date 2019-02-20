#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "helper.h"

void main(int argc, char* argv[]){
	//read and write resources, setting room to occupied
	rRead();
	rOccupied = 1;
	rWrite();
	char *input;
	
	//getting the input query
	if(input = getenv("QUERY_STRING")){
		int i = 0;
		
		//initializing variables to use
		char buff[100];
		char cmd[20];
		char *tok;
		char *upr = upper(cmd);
		int n=0;
		
		//parsing the input query
		strncpy(buff,input,99);
		tok = strtok(buff,"&");
		sscanf(tok,"inventory=%d%%2C%d",&pManna,&pGold);
		tok = strtok(NULL,"&");
		sscanf(tok,"command=%s",cmd);
		
		printf("Content-Type:text/html\n\n");
		
		//processing win or lose events
		if(pGold >= 100){
			printf("<body style=\"background-color:black;text-align: center;\">");			
			printf("<align=\"center\" alt=\"You win! You have saved the world!\">");
			printf("</body>");
		}
		else if(pManna <= 0){
			printf("<body style=\"background-color:black;text-align: center;\">");		
			printf("<align=\"center\" alt=\"You lose!\">");
			printf("</body>");
		}
		//processing each command
		//play accesses our game.c file
		else if(strcmp(cmd,"PLAY")==0){
			printf("<html>");
			printf("<body style=\"text-align: center\">");
			
			printf("<font color=\"blue\">NOTE:If this is your first time playing, submit a blank form. </font><br><br>");
			
			printf("<font color=\"blue\">Available commands:</font><br>");
			printf("<font color=\"blue\">- Type \"QUIT\" to quit the challenge</font><p>");
			printf("Rooms manna: %d<br>", rManna);
			printf("Rooms gold: %d<br>", rGold);
			printf("<img src=\"../room.jpg\" align=\"center\" alt=\"The Partition Room\">");
			printf("<p>");
			printf("<html>In this room resides a mathematician. He is about to find the equation that will save all of humanity, but he needs your help! Quick, how many partitions are there of the number 6? (enter number) <p>");
			printf("<form action=\"game.cgi\">");
			printf("<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pManna, pGold);
			printf("<input type=\"text\" name=\"cmd\"/>");
			printf("<input type=\"submit\" value=\"Submit\">");
			printf("</form>");
			printf("</body>");
			printf("</html>");	
		}
		else if(strncmp(cmd,"DROP",4)==0){
			int position = 5;
			while(cmd[position] != '\0'){
				n = n*10+(cmd[position]-'0');
				position++;
			}
			//call drop helper to process the exchange
			drop(n);
		}
		//exit adds player resources to the room, and ends the game
		else if(strcmp(cmd,"EXIT")==0){
			rOccupied = 0;
			rManna = rManna + pManna;
			rGold = rGold + pGold;
			rWrite();
			printf("<body style=\"background-color:black;text-align: center;\">");			
			printf("<align=\"center\" alt=\"Sorry to see you go. Enjoy the end of the world!\">");
			printf("</body>");
		}
		//simply refresh the page with players resources untouched.
		else if(strcmp(cmd,"REFRESH")==0){
			printf(roomhtml, pManna, pGold, pManna, pGold, pManna, pGold, pManna, pGold, pManna, pGold);
		}
		//error messages if invalid inputs
		else{
			printf("That is not a valid command. Hurry up and go back!");
		}
	}
	//error messages if invalid input
	else{
		printf("No input was received, hurry up and try again!");
	}
}
	
			
				
			
			
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
