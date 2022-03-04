#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200

int findFirst(char *sentence, char *word)
{
	int i, len1 = strlen(sentence), len2 = strlen(word);
	char temp[SIZE];
	
	for(i=0; i <= len1-len2; i++){
		
		temp[0] = '\0';
		memmove(temp, sentence + i, len2);
		
		if(strcmp(word, temp) == 0)
		return i;
	}
	
	return -1;
}

void deleteFirst(char *sentence, char *word)
{
	int i, k=0, j, position, num, len1 = strlen(sentence), len2 = strlen(word);
	char first[SIZE], second[SIZE], last[SIZE];
	
	position = findFirst(sentence, word);
	
	if(position!=-1)
	{
		if(position==0)
		{
			for(i=len2+1; i<len1; i++)
			first[k++] = sentence[i];
			
			strcpy(sentence, first);
			sentence[len1-len2] = '\0';
		}
		else
		{	
			for(i=0; i<position; i++){
				first[i] = sentence[i];
			}
			
			for(i=position+len2; i<len1; i++){
				second[k++] = sentence[i];
			}
					
			strcpy(last, first);
			strcat(last, second);
			
			strcpy(sentence, last);
			sentence[len1-len2] = '\0';
		}
	}
}

void deleteFirst_word(char *sentence, char *word)
{
	int i, k, j=0, position, len1 = strlen(sentence), len2 = strlen(word);
	char first[SIZE], second[SIZE], last[SIZE];
	char temp[SIZE];
	k= len1-len2;
	
	position = -1;
	for(i=0; i <= len1-len2; i++){
		 
		temp[0] = '\0';
		memmove(temp, sentence + i, len2);
		
		if(strcmp(word, temp) == 0){
			if((i == 0 || sentence[i - 1] == ' ') && (i == k || sentence[i + len2] == ' '))
			position = i;
		}
	}
	
		
	if(position!=-1)
	{
		if(position==0)
		{
			for(i=len2+1; i<len1; i++)
			first[j++] = sentence[i];
			
			strcpy(sentence, first);
			sentence[len1-len2] = '\0';
		}
		else
		{	
			for(i=0; i<position; i++)
			first[i] = sentence[i];
			
			first[i] = '\0';
		
			for(i=position+len2+1; i<len1; i++)
			second[j++] = sentence[i];
		
			strcpy(last, first);
			strcat(last, second);
			
			strcpy(sentence, last);
			sentence[len1-len2-1] = '\0';
		}
	}
}

int main()
{
	int pos;
	char sentence1[SIZE], word1[SIZE];
	char sentence2[SIZE], word2[SIZE];
	char sentence3[SIZE], word3[SIZE];
	/*
	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence1);
	printf("\nEnter a string: ");
	scanf("%s", word1);
	
	pos = findFirst(sentence1, word1);
	if(pos!=-1)
	printf("\nThe first occurence of the string <%s> is %d", word1, pos);
	else
	printf("The sentence does NOT contain the string <%s>", word1);
	
// Part b) of Question 1
	
	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence2);
	printf("\nEnter a string: ");
	scanf("%s", word2);
	deleteFirst(sentence2, word2);
	printf("The new form of the sentence after deletion: %s", sentence2);*/
	
// Part c) of Question 1	

	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence3);
	printf("\nEnter a word: ");
	scanf("%s", word3);
	deleteFirst_word(sentence3, word3);
	printf("The new form of the sentence after deletion: %s", sentence3);
	
	return 0;
}
