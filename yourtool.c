#include <stdio.h>
#include <stdlib.h>

#define INIT_STRING_SIZE 20

int mystrlen(char * str);

//!________________________________
//!read string from the standart input
//!memory needs to be freed after using pointer
//!________________________________
char * mygetline();

//!________________________________
//!find 'word' in 'string' and paste '*' after every 'word'
//!return result
//!________________________________
char * findandpaste(char * string, char * word);

char * mygetline()
{
	int capacity = INIT_STRING_SIZE;
	int size = 0;
	char symbol = 0;
	
	char * string = (char*)calloc(capacity, sizeof(char));
	
	symbol = getchar();
	for(; symbol != '\n' && symbol != '\0' ; ++size)
	{
		if(size >= capacity - 2)
		{
			capacity *= 2;
			string = (char*)realloc(string, capacity * sizeof(char)); 
		}
		
		string[size] = symbol;
		symbol = getchar();
	}
	
	string[size] = '\0';
	
	return string;
}

int mystrlen(char * str)
{
	int i = 0;
	
	for(; str[i] != '\0'; ++i)
	{
		
	}
	
	return i;
}

char * findandpaste(char * instring, char * word)
{
	int incounter = 0, outcounter = 0, wcounter = 0;
	int capacity = mystrlen(instring) + 1;
	
	char * outstring = (char*)calloc(capacity, sizeof(char));
	
	
	do
	{
		if(instring[incounter] == word[wcounter])
		{
			outstring[outcounter] = instring[incounter];
			
			++outcounter;
			++incounter;
			
			if(word[wcounter + 1] == '\0')
			{
				++capacity;
				outstring = (char*)realloc(outstring, capacity * sizeof(char));
				outstring[outcounter] = '*';
				++outcounter;
				wcounter = 0;
			}
			else
			{
				++wcounter;
			}
		}
		else
		{
			outstring[outcounter] = instring[incounter];
			wcounter = 0;
			
			++outcounter;
			++incounter;
		}
	}
	while(instring[incounter - 1] != '\0');
	
	return outstring;
}


int main(int argc, char * argv[])
{
	
	if(argc != 2)
	{
		printf("invalid amount of arguments\n");
		exit(0);
	}
	
	char * inputstr = 0;
	char * outputstr = 0;
	
	printf("write \"\\\" to stop tool\n");
	
	while(1)
	{
		inputstr = mygetline();
		outputstr = findandpaste(inputstr, argv[1]);
		
		if(inputstr[0] == '\\')
			break;
			
		printf("'%s'\n", outputstr);

		free(inputstr);
		free(outputstr);
	}
	
	free(inputstr);
	free(outputstr);
	
	return 0;
}

