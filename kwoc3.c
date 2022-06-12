/*
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
//void to_words(int, char **, node_t);

//function to get line number of input file
int line_num(char *input_file){


    int line_count = 0;
    char c;

    FILE *fp;
    fp = fopen(input_file, "r");
    if(fp == NULL){

        printf("Error opening file %s", *input_file);
        exit(1);
    }

    for(c = getc(fp); c != EOF; c = getc(fp)){

        if(c == '\n'){

            line_count++;

        }
    }

    fclose(fp);
    //printf("\nthe line count is %d", line_count);
    return line_count;
}



/*char * read_file(char *input_file){

    const int max_line_len = 100;
    char *return_array = (char *)emalloc(sizeof(char) * max_line_len);

    FILE *f;
    f = fopen(input_file, "r");
    if(f == NULL){

        printf("Error opening file %s", *input_file);
        exit(1);
    }

    while(fgets( return_array, max_line_len, f)){

        return_array[strlen(return_array)-1] = '0';
        to_words(return_array);

    }

}

char ** to_words(char *line){

    char *temp;
    char** words

    temp = strtok(line, " ");
    while(temp){



    }

} */


//function to make char array of lines from input file
void read_file(char *input_file, int line_count, char **line_array){

    const int max_line_len = 100;
    //char temp_array[max_line_len];
    int i;

    FILE *f;
    f = fopen(input_file, "r");
    if(f == NULL){

        printf("Error opening file %s", *input_file);
        exit(1);
    }

    //printf("\nhere");
    for(i = 0; i < line_count; i++){

        line_array[i] = (char *)emalloc(max_line_len * sizeof(char));

        fgets( line_array[i], max_line_len-1, f);

        strtok(line_array[i], "\n");

        //printf("\nThe line is: %s", line_array[i]);

        /*int j;

        for (j = strlen(line_array[i]) - 1; j >= 0 && line_array[i][j] == '\n'; j--){

            line_array[i][j+1]='\0';

        }*/


    /*while(fgets(temp_array, max_line_len, f)){
        temp_array[strlen(temp_array) - 1] = '\0';
        printf("\n this stuff  %s", temp_array);
        printf("\n the size: %d", sizeof(char) * strlen(temp_array));
        line_array[i] = (char *)emalloc(sizeof(char) * max_line_len);
        strcpy(line_array[i], temp_array);
        i++;
        printf("Eye!");*/
    }

    fclose(f);

}



void read_file_e(char *e_file, int line_count, char **e_array){

    const int max_line_len = 100;
    //char temp_array[max_line_len];
    int i;

    FILE *fe;
    fe = fopen(e_file, "r");
    if(fe == NULL){

        printf("Error opening file %s", *e_file);
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

void read_file_line(char *input_file, int line_count, char **line_array_temp){

    const int max_line_len = 100;
    //char temp_array[max_line_len];
    int i;

    FILE *fl;
    fl = fopen(input_file, "r");
    if(fl == NULL){

        printf("Error opening file %s", *input_file);
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


/*void to_words(int line_count, char** line_array, node_t *words_head){
    printf("\n %d", line_count);

    node_t *temp_node = NULL;
    char *temp;
    int i;

    for(i = 0; i < line_count; i++){
        printf("\nTHE LINE IS: %s", line_array[i]);
        temp = strtok(line_array[i], " ");

        while(temp){

            printf("\ngoing in: %s", temp);
            temp_node = new_node(temp);
            ///printf("\nhii");
            words_head = add_front(words_head, temp_node);
            printf("\ncoming out: %s", words_head);
            temp = strtok(NULL, " ");

        }

    }
    node_t *p = words_head;
    while(p != NULL){

        printf("\nyeyeyeye %s", p->text);
        p = p->next;

    }

}*/


void print_word(node_t *node, void *arg)
{
    char *format = (char *)arg;
    printf(format, node->text);
}


//function to compare and remove exceptions and input file
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


//function to sort and remove dupes from list
void delete_duplicates(node_t *head){

    node_t *current = head, *prev = head, *compare = head, *temp = NULL;

    node_t *d = head;
    while(d != NULL){
      d = d->next;
    }

    current = current->next;
    while(compare != NULL){
        //printf("\nTO COMPARE1: %s", compare->text);
        //printf(", WITH: %s", current->text);

//this might need to change
        //prev = compare;
        while(current != NULL && strcmp(current->text, compare->text) != 0){

            prev = current;
            current = current->next;
            //printf(", ALSO WITH: %s", current->text);

        }

        if(current == NULL){

            compare = compare->next;
            //printf("\nTO COMPARE: %s", compare->text);
            if(compare != NULL){

                current = compare->next;
                prev = compare;

            }
        }

        else if(strcmp(current->text, compare->text) == 0){

            //printf("\nDELETING... %s WITH... %s", compare->text, current->text);

            prev->next = current->next;
            //printf("\n  %s", prev->next->text);
            temp = current;
            current = current->next;
            //printf("\nDELETE %s", temp->text );
            free(temp);

        }
    }
}



/*void alpha_sort(node_t *head){

    node_t *current, *p;
    const int max_keyword_len = 40;


    p = head;
    current = head;
    if(current){

        while(current && current->next){

            if(strcmp(current->text, current->next->text) > 0){

                char *temp = (char *)emalloc(sizeof(char) * max_keyword_len);
                strcpy(temp, current->text);
                strcpy(current->text, current->next->text);
                strcpy(current->next->text, temp);

            }

            current = current->next;

        }
    }
}*/

void alpha_sort(node_t *head){

  node_t *current = head, *prev = head, *compare = head;

  const int max_keyword_len = 40;

  current = current->next;
  while(compare != NULL){

      //printf("\nCompare---> %s, Compare Next---> %s", compare->text, compare->next->text);
      prev = compare;
      current = compare->next;
      //printf("\nCOMPARING: %s WITH: %s", prev->text, current->text);
      while(current != NULL && strcmp(prev->text, current->text) < 0){

          prev = current;
          current = current->next;
          //printf("\n ALSO COMPARING: %s WITH: %s", prev->text, current->text);

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
    //char **line_list = (char **)emalloc(sizeof(char) * line_count);
    //read_file(input_file, line_count, line_list);

    char **line_list_temp = (char **)emalloc(sizeof(char*) * line_count);
    read_file_line(input_file, line_count, line_list_temp);

    //printf("\nKeyword: %s", keyword);
    while(keyword != NULL){


        //printf("\nhere::");
        //printf("\nKEYWORD: %s", keyword->text);

        char **line_list = (char **)emalloc(sizeof(char*) * line_count);
        read_file(input_file, line_count, line_list);
        //printf("\nELLLLLO NINNYOOOO");
        for(i = 0; i < line_count; i++){

            num = 0;

            //printf("\nhere2::");
            temp = strtok(line_list[i], " ");

            while(temp){
                //printf("\nhere3:: COMPARING %s", temp);
                for(j = 0; temp[j]; j++){

                    temp[j] = tolower(temp[j]);

                }
                //printf("\n Compare %s: With %s::", keyword->text, temp);
                if( strcmp( keyword->text, temp) == 0){
                    //printf("\nhere4::");

                    /*node_t *p = new_node(keyword->text);
                    //printf("\nTEMP NODE %s", p->text);
                    word = p->text;
                    for(x = 0; x < strlen(word); x++){
                        word[x] = toupper(word[x]);

                    }*/
                    num++;
                    temp = strtok(NULL, " ");

                    //printf("\nhere5::");
                    //printf("\nhere::6");
                    //printf("\n%s: ", line_list_temp[i]);
                    //printf("\n%-10s%s (%d)", word, line_list_temp[i], i+1);
                    //printf("%s (%d)", line_list_temp[i], i+1);
                    //free(p);

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
                //printf("\nhihihihihi");

                printf("\n%-*s%s (%d)", spaces, word, line_list_temp[i], i+1);

            }
            else if(num > 1){

                printf("\n%-*s%s (%d*)", spaces, word, line_list_temp[i], i+1);

            }
            free(p);
        }
        //printf("\nfreeTheLINES");

        for(i = 0; i < line_count; i++){

            free(line_list[i]);
        }
        free(line_list);
        //printf("\nELLLLOOOO NINNNYOOOOOOO %s", keyword->next->text);
        keyword = keyword->next;
    }

    for(i = 0; i < line_count; i++){
        free(line_list_temp[i]);
    }
    free(line_list_temp);

}


//function to find longest keyword
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


    read_file(input_file, input_line_count, line_list);

    //char **exception_list = (char **)emalloc(sizeof(char) * exception_line_count);
    read_file_e(exception_file, exception_line_count, exception_list);


    /*for(i = 0; i < input_line_count; i++){
        printf("\n the lines: %s", line_list[i]);
    }*/
    /*for(i = 0; i < exception_line_count; i++){
        printf("\n the exceptions: %s", exception_list[i]);
    }*/

    node_t *words_head = NULL;
    node_t *temp_node = NULL;
    char *temp;
    int words = 0;

    for(i = 0; i < input_line_count; i++){
        //printf("\nTHE LINE IS: %s", line_list[i]);

        temp = strtok(line_list[i], " ");

        if(temp[0] == '\n'){
            continue;
        }

        while(temp){
          //printf("\nELLLLOOOalkgjjhzdfkjlh %s", temp);

            int j;

            for(j = 0; temp[j]; j++){

                temp[j] = tolower(temp[j]);

            }
            //printf("\ngoing in: %s", temp);
            temp_node = new_node(temp);
            //printf("\nTHE NODE IS NOW %s",temp_node->text);
            words_head = add_front(words_head, temp_node);
            //printf("\nTHE NODE IS NEIGH %s",words_head->text);
            words++;
            //printf("\ncoming out: %s", words_head);
            temp = strtok(NULL, " ");

        }

    }

    for(i = 0; i < input_line_count; i++){
        free(line_list[i]);
    }
    free(line_list);


    node_t *p = words_head;
    /*while(p != NULL){

        printf("\nFor mah Llist: %s", p->text);
        //printf("uh ho");
        p = p->next;
    }*/


    p = words_head;
    node_t *p_prev = words_head;
    while(p != NULL){

        int t = -1;

        t = word_compare(p, exception_line_count, exception_list);
        //printf("\n%d", t);
        if(t == 1){

            words--;

            if(p == words_head){
                //printf("\nHere1");
                node_t *t = words_head;
                words_head = remove_front(words_head);
                p = words_head;
                p_prev = words_head;
                free(t);
            }
            else{
                //remove_node(p, p_prev);
                if(p->next == NULL){

                    node_t *t = p;
                    p = NULL;
                    p_prev->next = NULL;
                    free(t);
                }
                else{
                    //printf("\nHere2");
                    node_t *t = p;
                    p_prev->next = p->next;
                    p = p->next;
                    free(t);
                    //p_prev = p;
                    //p = p->next;
                }
            }
        }
        else{
            //printf("\nHere3");
            p_prev = p;
            p = p->next;
        }
    }

    //printf("\nHere");
    /*node_t* prin = words_head;
    while(prin != NULL){

        printf("\nFor mah Llist: %s", prin->text);
        //printf("uh ho");
        prin = prin->next;
    }*/

    for(i = 0; i < exception_line_count; i++){
        free(exception_list[i]);
    }
    free(exception_list);


    //deleting duplicate words in keywords list
    delete_duplicates(words_head);

    /*node_t *d = words_head;
    d = words_head;
    while(d != NULL){
        printf("\nByebYe Dupes: %s", d->text);
        d = d->next;
    }*/

    //sorting keywords in alphabetical order
    alpha_sort(words_head);

    //to find longest word for print formatting
    num_of_spaces = longest_word(words_head);
    //printf("\nSpaces: %d", num_of_spaces);

    /*node_t *d = words_head;
    d = words_head;
    while(d != NULL){
        printf("\nByebYe Dupes: %s", d->text);
        d = d->next;
    }*/


    print_format(words_head, input_line_count, num_of_spaces, input_file);

    temp_node = words_head;
    while (temp_node != NULL) {
        assert(temp_node != NULL);
        words_head = remove_front(words_head);
        free(temp_node);
        temp_node = words_head;
    }

    /*line_list = (char **)emalloc(sizeof(char) * input_line_count);
    read_file(input_file, input_line_count, line_list);


    for(i = 0; i < 100; i++){
        printf("\nLine before TOK: %s", line_list[i]);
        strtok(line_list[i], " ");
        printf("\nLine After: %s", line_list[i]);
    }*/




/*
 * Showing some simple usage of the linked-list routines.
 */

#ifdef DEBUG
    _demo();
#endif

    exit(0);
}
