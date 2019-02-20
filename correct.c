#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

//the errors to print if it was incorrect
void errors()
{
	printf("<form action=\"game.cgi\">");
	printf("<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pManna, pGold);
	printf("<input type=\"hidden\" name=\"command\" value=\"11\">");
	printf("<input type=\"submit\" value=\"Try again\">");
	printf("</form>");
}

int main(void)
{
//read query, and parse values
	rRead();

	char *input;

	if (input = getenv("QUERY_STRING"))
	{
		char *tok;
		int mannaTaken;
		int goldTaken;
		char cmd[20];
		char buff[100];
		
		
		// parse the input string and store variable values
		strncpy(buff, input, 99);
		tok = strtok(buff, "&");
		sscanf(tok, "inventory=%d%%2C%d", &pManna, &pGold);
		tok = strtok(NULL, "&");
		sscanf(tok, "command=%s", cmd);
		tok = strtok(NULL, "&");
		sscanf(tok, "manna=%d", &mannaTaken);
		tok = strtok(NULL, "&");
		sscanf(tok, "gold=%d", &goldTaken);

		printf("Content-Type:text/html\n\n");

		//choosing the awards when correct(and what could go wrong with them)
		if (mannaTaken > rManna)
		{
			printf("The room doesn't have enough manna, so choose a lesser number please.<p>");
			errors();
		}
		else if (goldTaken> rGold)
		{
			printf("The room doesn't have enough gold, so choose a lesser number please.<p>");
			errors();
		}
		else if (mannaTaken + goldTaken > 5)
		{
			printf("You can't take more than 5 objects. It's simple math really.<p>");
			errors();
		}
		
		else
		{
			rManna = rManna - mannaTaken;
			rGold = rGold - goldTaken;
			pManna = pManna + mannaTaken;
			pGold = pGold + goldTaken;
			rWrite();
			printf("You chose to take %d manna and %d gold. You now have %d manna and %d gold<p>", mannaTaken, goldTaken, pManna, pGold);
			printf("<form action=\"room.cgi\">");
			printf("<input type=\"hidden\" name=\"inventory\" value=\"%d,%d\">", pManna, pGold);
			printf("<input type=\"hidden\" name=\"command\" value=\"REFRESH\">");
			printf("<input type=\"submit\" value=\"Go back to the room\">");
			printf("</form>");
		}
	}
	//if no query string was recieved
	else
	{	
		printf("We didn't get a QUERY_STRING. Did you not type anything? Try again.");
	}
}
