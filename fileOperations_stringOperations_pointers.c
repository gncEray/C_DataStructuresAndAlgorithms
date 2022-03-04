#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40

void replacewith(char *sentence, char *word)
{
	int i, a, k, len1 = strlen(sentence), len2 = strlen(word);
	int pos[SIZE], position;
	char temp[SIZE], first[SIZE], second[SIZE];

	for(a=0; a <= len1-len2; a++)
	{
		temp[0] = '\0';
		memmove(temp, sentence + a, len2);
		
		if(strcmp(word, temp) == 0)
		{ 
			if((sentence[a + len2] == ' ' || sentence[a - 1] == ' ' || sentence[a+len2] == '\0'))
			{ 			
				position = a;
		
				if(position==0) 
				{
			    k = 0;
			    //	first[0] = '\0';
					for(i=len2; i<len1; i++)
					first[k++] = sentence[i];
			
					sentence[0] = '*';
					sentence[1] = '\0';
					strcat(sentence, first);
					sentence[len1-len2+1] = '\0';
				}
				else
				{	
					k=0;
				//	first[0] = '\0';
				//	second[0] = '\0';
					for(i=0; i<position; i++){ //takes before string part
						first[k++] = sentence[i];
					}
				
						first[i] = '*';
						first[i+1] = '\0';
								
					k = 0;
					for(i=position+len2; i<len1; i++){ // takes after string part
						second[k++] = sentence[i];
					}
			
					strcpy(sentence, first);
					strcat(sentence, second);
		
					sentence[len1-len2+1] = '\0'; //making null the last subcript
				}
			}
		}
	}
}

int main()
{
	int pos;
	char sentence[SIZE], word[20], oldtext[SIZE];
	
	printf("Enter a text: ");
	scanf("%[^\n]", sentence);	

	printf("Enter a string: ");
	scanf("%s", word);	

	strcpy(oldtext, sentence);
	replacewith(sentence, word); //calling the function
	printf("Old Text: %s\n", oldtext);
	printf("New Text: %s", sentence);
	
	return 0;
}
