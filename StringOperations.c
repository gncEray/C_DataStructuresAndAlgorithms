
//This program takes random numbers and uses them to create a random sentence.
//with using four 2D arrays.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	int i, k, word[6];
	char sentence[40];
	srand(time(0));	
	
	char article[5][10] = { "the ", "a ", "one ", "some ","any " },
	noun[5][10] = { "bicycle", "bird", "dog", "bus", "car" },
	verb[5][10] = { " drove", " jumped", " ran", " walked", " flew" },
	preposition[5][10] = { " to ", " from ", " over ", " under ", " on " };
	
	for(k=1; k<6; k++){
		
		for(i=0; i<6; i++){
		word[i] = rand() % 5;
		}
		
		strcpy(sentence, article[word[0]]); // I used strcpy here for making null the array
		strcat(sentence, noun[word[1]]);
		strcat(sentence, verb[word[2]]);
		strcat(sentence, preposition[word[3]]);
		strcat(sentence, article[word[4]]);
		strcat(sentence, noun[word[5]]);
		
	printf("Sentence %d: %s.\n", k, sentence);
	}

	return 0;
	
}
