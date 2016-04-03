// Timothy Park

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 100
#define TSIZE 20
#define TCOUNT 10

char curline[LINESIZE];
char tokens[TCOUNT][TSIZE];
int tokensize; // int that holds actual size of each token

// break input line into tokens using strtok
void gettokens() { 
	char *p; // will contain the tokens
	p = strtok(curline, " "); // need to change preprocessor defnitions to this version

	tokensize = 0;
	while (p != NULL) // transfer p to tokens
	{
		strcpy(tokens[tokensize], p); // copies string into row in token
		//printf("next token is %s\n", p);
		p = strtok(NULL, " ");
		tokensize++;
	}
	free(p); // frees up p
}

void commandline() 
{ 
	while (1) // infinite loop that depends on quit
	{
		printf("> ");
		gets(curline); // reads in line
		gettokens(); // calls gettokens
		memset(curline, NULL, LINESIZE); // clears curline
		//printf("token is %s\n", tokens[0]);
		if (strcmp(tokens[0], "quit") == 0) // quit
		{
			printf("Bye!\n");
			break;
		}
		else if (strcmp(tokens[0], "sum") == 0) // sum
		{
			int sum = 0;
			for (int i = 0; i < TCOUNT; i++)
			{ 
				if (i > 0 && i < tokensize) // making sure only integer values are included
				{
					sum += atoi(tokens[i]); // atoi to get integer values
				}
				for (int j = 0; j < TSIZE; j++) // loop for clearing the 2D array
				{
					tokens[i][j] = NULL;
				}
			}
			printf("%d", sum);
			printf("\n");
		}
		else if (strcmp(tokens[0], "prod") == 0) // prod
		{
			int prod = 1;
			
			for (int i = 0; i < 10; i++)
			{
				if(i > 0 && i < tokensize) // making sure only integer values are included
				{ 

					prod *= atoi(tokens[i]);
					//printf("atoi is %d\n", atoi(tokens[i]));
				}
				
				for (int j = 0; j < TSIZE; j++) // clearing tokens
				{
					tokens[i][j] = NULL;
				}
			}
			printf("%d", prod);
			printf("\n");
		}
		else // error
		{
			printf("ERROR Sytem does not recognize this command\n");
		}
	}
}

void main(void) {
	commandline();
	system("pause");
}