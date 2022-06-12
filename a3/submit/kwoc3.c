/*Tim Rolston #V00920780
 * kwoc3.c
 *
 * Starter file provided to students for Assignment #3, SENG 265,
 * Spring 2020
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "emalloc.h"
#include "listy.h"


#undef DEBUG
//#define DEBUG 1



//function to get line number of input file
int line_num(char *input_file){


    int line_count = 0;
    char c;

    FILE *fp;
    fp = fopen(input_file, "r");
    if(fp == NULL){

        printf("Error opening file %s", input_file);
        exit(1);
    }

    for(c = getc(fp); c != EOF; c = getc(fp)){

        if(c == '\n'){

            line_count++;

        }
    }

    fclose(fp);

    return line_count;
}



//function to read input file lines into an array
void read_file(char *input_file, int line_count, char **line_array){

    const int max_line_len = 100;
    int i;
    FILE *f;
    f = fopen(input_file, "r");
    if(f == NULL){

        printf("Error opening file %s", input_file);
        exit(1);
    }
    //printf("\nhere");
    for(i = 0; i < line_count; i++){

        line_array[i] = (char *)emalloc(max_line_len * sizeof(char));

        fgets( line_array[i], max_line_len-1, f);

        strtok(line_array[i], "\n");
    }

    fclose(f);
}



//function to read lines from exception file into array
void read_file_e(char *e_file, int line_count, char **e_array){

    const int max_line_len = 100;
    int i;
    FILE *fe;
    fe = fopen(e_file, "r");
    if(fe == NULL){

        printf("Error opening file %s", e_file);
        exit(1);
    }
    //printf("\nhere");
    for(i = 0; i < line_count; i++){

        e_array[i] = (char *)emalloc(max_line_len * sizeof(char));

        fgets( e_array[i], max_line_len-1, fe);
        //printf("\n The line is: %s", line_array[i]);
        strtok(e_array[i], "\n");
        int j;

        //make words lowercase
        for(j = 0; e_array[i][j]; j++){

            e_array[i][j] = tolower(e_array[i][j]);
        }
    }
    fclose(fe);
}



//function used specifically to create array of lines for printing
void read_file_line(char *input_file, int line_count, char **line_array_temp){

    const int max_line_len = 100;
    int i;
    FILE *fl;
    fl = fopen(input_file, "r");
    if(fl == NULL){

        printf("Error opening file %s", input_file);
        exit(1);
    }
    //printf("\nhere");
    for(i = 0; i < line_count; i++){

        line_array_temp[i] = (char*)emalloc(max_line_len * sizeof(char));
        fgets( line_array_temp[i], max_line_len-1, fl);
        strtok(line_array_temp[i], "\n");
    }

    fclose(fl);
}



//given function
void print_word(node_t *node, void *arg)
{
    char *format = (char *)arg;
    printf(format, node->text);
}



//function to help compare and remove exceptions and input file
int word_compare(node_t *list, int line_count, char** exception_array){

    int i;

    for(i = 0; i < line_count; i++){
        //printf("\nCOMPARE: %s", list->text);
        //printf(" WITH: %s", exception_array[i]);
        if( strcmp(list->text, exception_array[i]) == 0 ){

            return 1;
        }
    }

    return 0;
}



//unused function
void remove_node(node_t *current, node_t *previous){

    node_t *temp = NULL;

    if(current->next == NULL){

        temp = current;
        current = NULL;
        free(temp);

    }

    temp = current;
    previous->next = current->next;
    current = current->next;
    previous = previous->next;
    free(temp);
}



//function to remove duplicates from input linked list
void delete_duplicates(node_t *head){

    node_t *current = head, *prev = head, *compare = head, *temp = NULL;

    current = current->next;
    while(compare != NULL){

        while(current != NULL && strcmp(current->text, compare->text) != 0){

            prev = current;
            current = current->next;

        }
        if(current == NULL){

            compare = compare->next;

            if(compare != NULL){

                current = compare->next;
                prev = compare;
            }
        }

        else if(strcmp(current->text, compare->text) == 0){
            //printf("\nDELETING... %s WITH... %s", compare->text, current->text);
            prev->next = current->next;
            temp = current;
            current = current->next;
            free(temp);
        }
    }
}



//function for sorting input linked list in alphabetical order
void alpha_sort(node_t *head){

    node_t *current = head, *prev = head, *compare = head;

    const int max_keyword_len = 40;

    current = current->next;
    while(compare != NULL){

        prev = compare;
        current = compare->next;
        while(current != NULL && strcmp(prev->text, current->text) < 0){

            prev = current;
            current = current->next;
        }

        if(current == NULL){

            break;
        }

        else if(strcmp(prev->text, current->text) > 0){
        //printf("\n\nSWAPPING: %s WITH: %s\n\n", prev->text, current->text);
        char *temp = (char *)emalloc(sizeof(char) * max_keyword_len);
        strcpy(temp, current->text);
        strcpy(current->text, prev->text);
        strcpy(prev->text, temp);
        free(temp);
        }
    }
}



//function for printing format
void print_format(node_t *head, int line_count , int spaces, char *input_file ){

    int i, j, x, num;
    node_t * keyword = head;
    char *temp = NULL, *word = NULL;
    char **line_list_temp = (char **)emalloc(sizeof(char*) * line_count);
    read_file_line(input_file, line_count, line_list_temp);

    while(keyword != NULL){

        char **line_list = (char **)emalloc(sizeof(char*) * line_count);
        read_file(input_file, line_count, line_list);

        for(i = 0; i < line_count; i++){

            num = 0;
            temp = strtok(line_list[i], " ");

            while(temp){

                for(j = 0; temp[j]; j++){

                    temp[j] = tolower(temp[j]);

                }

                if( strcmp( keyword->text, temp) == 0){

                    num++;
                    temp = strtok(NULL, " ");

                }

                else{
                    temp = strtok(NULL, " ");
                }
            }

            node_t *p = new_node(keyword->text);
            word = p->text;
            for(x = 0; x < strlen(word); x++){
                word[x] = toupper(word[x]);

            }

            if(num == 1){

                printf("%-*s%s (%d)\n", spaces, word, line_list_temp[i], i+1);

            }
            else if(num > 1){

                printf("%-*s%s (%d*)\n", spaces, word, line_list_temp[i], i+1);

            }
            free(p);
        }

        for(i = 0; i < line_count; i++){

            free(line_list[i]);
        }
        free(line_list);
        keyword = keyword->next;
    }

    for(i = 0; i < line_count; i++){
        free(line_list_temp[i]);
    }

    free(line_list_temp);
}



//function to find longest keyword of input linked list
int longest_word(node_t *head){

    int count, num_of_spaces;
    node_t* temp = head;
    char *word;
    const int max_keyword_len = 40;

    while(temp != NULL){

        word = (char *)emalloc(sizeof(char) * max_keyword_len);
        strcpy(word, temp->text);
        count = strlen(word);
        free(word);

        if(count > num_of_spaces){

          num_of_spaces = count;
        }

        temp = temp->next;
    }

    return num_of_spaces + 2;
}

#ifdef DEBUG

/*
 * Just showing the use of the linked-list routines.
 */

void _demo() {
printf("DEBUG: in _demo\n");
    char *words_german[] = {"Der", "Kater", "mit", "Hut."};
    int   words_german_len = 4;

    char *words_english[] = {"The", "cat", "in", "the", "hat."};
    int   words_english_len = 5;

    node_t *temp_node = NULL;
    node_t *head = NULL;

    int i;

    /* Add the words in German, at the front. */
    for (i = 0; i < words_german_len; i++) {
        temp_node = new_node(words_german[i]);
        head = add_front(head, temp_node);
    }

    /* Add the words in English, at the end. */
    for (i = 0; i < words_english_len; i++) {
        temp_node = new_node(words_english[i]);
        head = add_end(head, temp_node);
    }

    /* Print the list of words. */

    apply(head, print_word, "--> %s\n");

    /* Free up the memory. This is done rather deliberately
     * and manually.  Asserts are liberally used here as they
     * express state that *must* be true if all of the code is
     * correctly working.
     */

    temp_node = head;
    while (temp_node != NULL) {
        assert(temp_node != NULL);
        head = remove_front(head);
        free(temp_node);
        temp_node = head;
    }

    assert(head == NULL);
}

#endif


/*I struggled a bit with doing pointers to char ** arrays and returning them properly so
my function decomposition is somewhat weak*/
int main(int argc, char *argv[])
{
    char *exception_file = NULL;
    char *input_file = NULL;
    int i;
    int input_line_count, exception_line_count, num_of_spaces;

    for (i = 1; i < argc; i++) {

/* UPDATE: 13-March-2020. The inequality in the line below
 * needs to be changed from < to <= in order for it to
 * work correctly.
        if (strcmp(argv[i], "-e") == 0 && i+i < argc) {
*/
        if (strcmp(argv[i], "-e") == 0 && i+i <= argc) {
            exception_file = argv[++i];


        } else {
            input_file = argv[i];
        }
    }

    //open files, count lines and read them into an array
    input_line_count = line_num(input_file);
    exception_line_count = line_num(exception_file);

    //allocate space for arrays with respect to their # of lines
    char **line_list = (char **)emalloc(sizeof(char*) * input_line_count);
    char **exception_list = (char **)emalloc(sizeof(char *) * exception_line_count);

    //get input array full of lines from input file
    read_file(input_file, input_line_count, line_list);

    //get an exception array full of lines from exception file
    read_file_e(exception_file, exception_line_count, exception_list);

    /*code to turn lines in array into lowercase words and add into linked list
    (does not follow proper function decomposition)*/
    node_t *words_head = NULL;
    node_t *temp_node = NULL;
    char *temp;
    int words = 0;

    for(i = 0; i < input_line_count; i++){

        temp = strtok(line_list[i], " ");
        if(temp[0] == '\n'){
             continue;
       }

        while(temp){

            int j;

            for(j = 0; temp[j]; j++){

                temp[j] = tolower(temp[j]);
            }

            temp_node = new_node(temp);
            words_head = add_front(words_head, temp_node);
            words++;
            temp = strtok(NULL, " ");
        }
    }

//deallocate input lines array
    for(i = 0; i < input_line_count; i++){
        free(line_list[i]);
    }
    free(line_list);

    /*code to compare and remove exceptions from words linked list
    (does not follow proper function decomposition)*/
    node_t *p = words_head;
    p = words_head;
    node_t *p_prev = words_head;
    while(p != NULL){

        int t = -1;

        t = word_compare(p, exception_line_count, exception_list);

        if(t == 1){

            words--;

            if(p == words_head){

                node_t *t = words_head;
                words_head = remove_front(words_head);
                p = words_head;
                p_prev = words_head;
                free(t);
            }

            else{

                if(p->next == NULL){

                    node_t *t = p;
                    p = NULL;
                    p_prev->next = NULL;
                    free(t);
                }
                else{

                    node_t *t = p;
                    p_prev->next = p->next;
                    p = p->next;
                    free(t);
                }
            }
        }

        else{

            p_prev = p;
            p = p->next;
        }
    }

//deallocate exception array
    for(i = 0; i < exception_line_count; i++){
        free(exception_list[i]);
    }
    free(exception_list);

    //deleting duplicate words in keywords list
    delete_duplicates(words_head);

    //sorting keywords in alphabetical order
    alpha_sort(words_head);

    //to find longest word for print formatting
    num_of_spaces = longest_word(words_head);

    //to print in proper format
    print_format(words_head, input_line_count, num_of_spaces, input_file);

//deallocate the linked list
    temp_node = words_head;
    while (temp_node != NULL) {
        assert(temp_node != NULL);
        words_head = remove_front(words_head);
        free(temp_node);
        temp_node = words_head;
    }

/*
 * Showing some simple usage of the linked-list routines.
 */

#ifdef DEBUG
    _demo();
#endif

    exit(0);
}
