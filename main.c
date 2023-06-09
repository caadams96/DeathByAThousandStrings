#include <stdio.h>
#include <string.h>
#include <malloc.h>

int StringLength(const char* strSource);
int WordCount(const char* strSource);
int lower(int c);
void* StringCopy(char* dest,const char *src);
void* StringReverse(char* dest,char *source);
int brutesearch(char *pattern, const char *string);
int CaseSensitiveCharacterSearch(const char* strSource, char chrLetterToFind);
int CaseInsensitiveCharacterSearch(const char* strSource, char chrLetterToFind);
void *StringConcatenate(char *dest, char *src);

char* StringUpperCase(char* dest, char* strSource);

int upper(int c);


int main() {
    char* string = "The big brown dog named Bernard, went on a walk";
    char* copy = malloc(100);
    char* reverse = malloc(100);//

    //Show string
    printf("%s\n",string);

    //PROB 1
    printf("Problem 1\n");

    printf("length of the string is: %d\n",StringLength(string));
    printf("\n");

    //prob 2
    printf("Problem 2\n");

    StringCopy(copy,string);
    printf("The copy of the string is : %s\n", copy );
    printf("\n");

    //prob3
    printf("Problem 3\n");

    char CharToFind = 'B';
    printf("Found %c at index: %d\n",CharToFind, CaseSensitiveCharacterSearch(string, CharToFind));
    printf("\n");

    //prop4
    printf("Problem 4\n");

    printf("Found %c at index: %d\n", CharToFind ,CaseInsensitiveCharacterSearch(string, CharToFind));
    printf("\n");

    //prob5
    printf("Problem 5\n");

    char* cpy = "Hello";
    printf("BEFORE: %s\n", cpy);
    cpy = StringConcatenate(cpy, " World!");
    printf("AFTER: %s\n", cpy);

    //prob 6
    printf("Problem 6\n");

    StringReverse(reverse,string);
    printf("Reverse of main string: %s\n", reverse);
    printf("\n");

    //prob 7
    printf("Problem 7\n");

    char* upper = malloc(StringLength(cpy));
    printf("UPPERCASE of previous string: %s\n", StringUpperCase(upper,cpy));
    printf("UPPERCASE of main string: %s\n", StringUpperCase(upper,string));
    printf("\n");

    //prob 8

    //prob 9
    printf("Problem 9\n");

    printf("WordCount: %d", WordCount(string));
    printf("\n");

    free(copy);
    free(reverse);
    return 0;
}
/********************************************************************************/

void *StringConcatenate(char *dest, char *src){
    int dest_length = StringLength(dest);
    int source_length = StringLength(src);
//    char cat_buffer[dest_length + source_length];
    char *cat_buffer = malloc(dest_length + source_length);
//    cat_buffer[0] = '\0';
    char *dest_pointer;
    char *source_pointer;
    int i;

    for(dest_pointer = &dest[0], i= 0; dest_pointer<&dest[dest_length]; ++dest_pointer, ++i ){
        cat_buffer[i] = *dest_pointer;
    }
    for(source_pointer = &src[0], i = dest_length; source_pointer < &src[source_length]; ++source_pointer, ++i ){
        cat_buffer[i] = *source_pointer;

    }
    dest = cat_buffer;
    return dest;

}
/********************************************************************************/

void* StringReverse(char *dest,  char *source) {
    size_t string_length = StringLength(source);
    char* strPointer = &source[string_length-1];
    char* d = dest;
    while (string_length--)
        *d++ = *strPointer--;
    return dest;
}
/********************************************************************************/

void* StringCopy(char* dest,const char *src){
    size_t len = StringLength(src);
    char *d = dest;
    const char *s = src;
    while (len--)
        *d++ = *s++;
    return dest;
}

/********************************************************************************/

int CaseSensitiveCharacterSearch(const char* strSource, char chrLetterToFind){
    char c[1];
    c[0] = chrLetterToFind;
    return brutesearch(c, strSource);
}
/********************************************************************************/

int CaseInsensitiveCharacterSearch(const char* strSource, char chrLetterToFind){
    char pattern_char[1];
    pattern_char[0] = (char)lower(chrLetterToFind);
    int len = StringLength(strSource);
    char* dest = malloc(StringLength(strSource));
    char *d = dest;
    const char *s = strSource;
    while (len--)
        *d++ = (char)lower(*s++);
    return brutesearch(pattern_char, dest);
}
/********************************************************************************/

char* StringUpperCase(char* dest, char* strSource){

    char *d = dest;
    const char *s = strSource;
    int len = StringLength(strSource);

    while (len--)
        *d++ = (char)upper(*s++);
    return dest;
}
/********************************************************************************/

int upper(int c){
    if( c >= 'Z' )
        return c - 32;
    else
        return c;
}
/********************************************************************************/

int lower(int c){
    if (c >= 'A' && c<= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
/********************************************************************************/
//**
int brutesearch(char *pattern, const char *string){
    int i, j , pattern_length = StringLength(pattern), string_length = StringLength(string);
    for(i = 0, j = 0; j < pattern_length && i < string_length; ++i, ++j){
        while(string[i] != pattern[j]){
            i -= j-1;
            j=0;
            if(i > string_length)//    char *dest = malloc(string_length);

                return -1;
        }
    }
    if (j == pattern_length)
        return i - pattern_length;
    else
        return i;
}
/********************************************************************************/
int WordCount(const char* strSource){
    //State Constants
    const int IN = 1; //In a word
    const int OUT = 0; //Not in a word
    //Variables
    int i, word_count, state;
    char current_char;
    //Set State To Out
    state = OUT;
    //Set Variables to zero
    i = word_count = 0;
    //Main Logic
    while(strSource[i] != '\0'){
        current_char = strSource[i];
        if(current_char == ' ' || current_char == '\n' || current_char == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++word_count;
        }
        ++i;
    }
    //return
    return word_count;
}
/********************************************************************************/
int StringLength(const char* strSource){
    int i;
    i = 0;
    while(strSource[i] != '\0')
        i++;
    return i;
}
/********************************************************************************/
