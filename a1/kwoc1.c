//Tim Rolston #V00920780
//Credits function "store_the_words" Michael Zastre

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EX 100
#define MAX_FILE 100
#define MAX_LINE_LEN 80
#define MAX_WORD_LEN 20
#define MAX_WORD 500


char *token;
char line[MAX_FILE][MAX_LINE_LEN];
char* line_tmp[MAX_FILE];
char excp[MAX_EX][MAX_WORD_LEN];
char words[MAX_WORD][MAX_WORD_LEN];
char *temp_word[MAX_WORD][MAX_WORD_LEN];
int  num_words = 0;


void store_the_words(char *the_line);
int count_lines(FILE *tmp_file);

int main(int argc, char *argv[]){


/*Needs test for argv input if < 3 print error
if -e is argv[1] then argv[2] must be exception and argv [3]
must be input file
if -e is argv[2] then argv[1] must be input file
*/

    int lines_count;
    int lines_e_count;
    FILE *fe;
    FILE *fp;
   

//opening exception file

    fe = fopen(argv[2], "r");
    if(fe == NULL){

	printf("Error opening file %s", argv[2]);
	return 1;
    }


    lines_e_count = count_lines(fe);

    fe = fopen(argv[2], "r");

    int i1;
    for(i1 = 0; i1 < lines_e_count; i1++){

	fgets(excp[i1], MAX_EX, fe);
	

    }


    fclose(fe);


//opening input file
    fp = fopen(argv[1], "r");
    if (fp == NULL){

        printf("Error opening file %s", argv[1]);
	return 1;
    }


//count lines for input file
    lines_count = count_lines(fp);
    //printf("%d" , lines_count);

    fp = fopen(argv[1], "r");

    int i;     

    for( i = 0; i < lines_count; i++){

	fgets(line[i], MAX_FILE, fp);
	store_the_words(line[i]);

	printf("\nThis line is: %s", line[i]);	
	//printf("\n%s", words[i]);
    }
/*
int x;
for(x = 0; x < num_words; x++){
printf("\n%s" , words[x]);
}
*/  



    fclose(fp);


//comparing arrays and remove
    printf("\n");
    int s;
    char *comp[MAX_FILE];
    //char str_blank = " ";
    int x, y, z;
    
    for(x = 0; x < lines_count; x++){
	
	s = 0;
	
	printf("\nThe word is:%s", words[x]);
	for( y = 0; y < lines_e_count; y++){
	 

	    if( strcmp( excp[y], words[x]) == 0){
		printf("\nHello");
		s = 1;	
		printf("\n%s", comp[z]);
		
		
	    }
	}
	    if( s == 0){
	        strcpy(comp[z], words[x]);
	        z++;
	    }
    }





/*print sorted words with line, line number and count ie
put sorted words through compare keywords function and get return value for
every line and print if value is > 0 and print with "*" if
#ofWordsAppeared is > 1 then move on to next word
*/

    return 0;

}


/*sort the words function ie 
use string compare (strcmp) and a nested for loop to compare if string
is > rest of strings and place into temp array to which the values are shuffled
over and the test runs again until all words sorted alphabetically
*/


/*compare keywords to find line numbers function ie
take input string and iterate through lines put through tokenize function
testing if same using strcmp, if found then finish searching line and return 
count of times tokenized to have line number value and return variable of
times loop was true (the amount of times the word appeared in the line)
*/


//tokenize function
/* Assuming that line != NULL */

void store_the_words(char *the_line)
{
    char buffer[MAX_FILE];
    char *t;

    strncpy(buffer, the_line, MAX_FILE);
    t = strtok(buffer, " ");
    while (t != NULL) {
        if (num_words >= MAX_WORD) {
            fprintf(stderr, "Too many words!\n");
            exit(1);    
        }
        strncpy(words[num_words], t, MAX_WORD_LEN);
        num_words++; 

        t = strtok(NULL, " ");
    }
}



//counting lines function
int count_lines(FILE *tmp_file){

    
    int count = 0;
    char temp;

    
    temp = getc(tmp_file);

    while( temp != EOF){

	if( temp == '\n'){

	    count = count + 1;

	}

	temp = getc(tmp_file);

    } 

    //fclose(tmp_file);
    return count;

}
