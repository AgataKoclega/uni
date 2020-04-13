//
//  main.c
//  dicto
//
//  Created by Agata K on 08/01/2019.
//  Copyright © 2019 Agata K. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int s = 100;

int mycmp(const void *a, const void *b) /* this function teams two words with themselves*/
{
    
    return strcmp((char *) a, *(char **)b);
}

int fpeek(FILE *stream)/* fpeek checks the following character, but doesn't load it*/
{
    int c;
    
    c = fgetc(stream);
    ungetc(c, stream);
    
    return c;
}
int main()
{
    FILE*f;
    char file[100];
    printf("Give the path of the dictionary file: ");
    scanf("%s: ", file);
    f=fopen(file, "r"); /* it opens determined before file*/
    if (f == NULL)
    {
        printf("Problems opening the file\n");
        return 0;
    }
    int size;
    fscanf(f, "%d", &size); /* function reads in the number of words(pair of words-english and corresponding polish one) */
    
    char **eng = (char*)malloc(size * sizeof(char*));
    char **pol = (char*)malloc(size * sizeof(char*)); /* in this place there is created 2D array for words and their translations*/
    
    for(int i = 0; i < size; i++)
    {
        eng[i] = (char**)malloc(s * sizeof(char));
        pol[i] = (char**)malloc(s * sizeof(char));
    }
    for(int i = 0; i < size; i++) /*  in loop words are read in  english and in polish*/
    {
        fscanf(f, "%s", eng[i]);
        fscanf(f, "%s", pol[i]);
    }
    fclose(f);
    
    FILE*g; /* now we are opening the file we want to translate and next we create the file where translated text will be located*/
    char dictionary[100];
    printf("Give the  path of text file you want to translate: ");
    scanf("%s", dictionary);
    g=fopen (dictionary, "r");
    FILE*h;
    h=fopen("/Users/Agata/Desktop/focp/nie/dicto/dicto/result.txt", "w");
    if (g == NULL)
    {
        printf("Problems opening the file\n");
    }
    char word[s];
    char punctuation;
    int index;
    
    while(fscanf(g, "%s", word) != -1) /* individual words from source file are read in*/
    {
        if (ispunct(word[strlen(word) - 1])) /* if there is present a punctuation mark, it will be read in thanks to ispunct*/
        {
            punctuation = word[strlen(word) - 1];
            word[strlen(word) - 1] = 0;
        }
        else
            punctuation = ' ';
        char** pts = (char**)bsearch(word, eng, size, sizeof(char*), mycmp); /* bsearch is looking for the given word from the file we want to translate in the file with dictionary*/
        if (pts != NULL)
        {
            index = pts - eng; /* index determined the place, where the given word is in the dictionary*/
            fprintf(h, "%s", pol[index]);
       
    }
        else
            fprintf(h, "%s", word);
        if (punctuation == ' ') /* if space or comma is needed it will be added in this moment*/
            fprintf(h, "%c", punctuation);
        else
            fprintf(h,"%c ", punctuation);
        if (fpeek(g) == '\n')
            fprintf(h, "\n");
    }
    
    
    
    free(pol); /* deallocation*/
    free(eng);
    system("PAUSE");
    return 0;
}
