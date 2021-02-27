/*****************************************************************
//
//  NAME:        Constantine Peros
i//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        February 23 2021
//
//  FILE:        iofunctions.c
//
//  DESCRIPTION:
//   Reads and Writes a pokemon to a file
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include "pokemon.h"
#include "iofunctions.h"

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   readfile function will read the data from a 
//                 text file and store it in the array called by pokearray.
//                 by pokearray.
//
//  Parameters:     pokemon pokearray[ ] (struct) the array to store. 
//                  num (int*) the number associated with the end of array.
//                  filename[ ] (char) name of the file to read and write.   
//
//  Return values:  0 : success
//                 -1 : failure
//
****************************************************************/

int readfile( struct pokemon pokearray[ ], int* num, char filename[ ] )
{
    FILE *pokefile;
    int run;
    int count;
    int lvl;
    char text[25]; 

    pokefile = fopen(filename, "r");
    run = 1;
    count = 0;  

    if (pokefile == NULL)
    {
        run = -1;

    }
    while(run == 1)
    {
        if (count >= *num)
        {
            run = 0;
        }
        if (fgets(text, 25, pokefile) != NULL)
        {
        
            if ( sscanf(text, "%d", &lvl) != 1)
            {
                printf("Reading name\n");
                printf("%s\n", text);
                strcpy(pokearray[count].name, text);
                printf("entry %d in array in named %s\n", count, pokearray[count].name);
                count ++;
            }
            else
            {
                printf("reading level\n");
                printf("level from file is %s\n", text);
                pokearray[count].level = lvl;
                printf("Entry %d in array is level %d\n", count, pokearray[count].level);
            }
        }
        else
        {
            run = 0;
        }
    }
    fclose(pokefile);
    return run;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   readfile function will read the data from a 
//                 text file and store it in the array called by pokearray.
//                 by pokearray.
//
//  Parameters:     pokemon pokearray[ ] (struct) the array to store. 
//                  num (int*) the number associated with the end of array.
//                  filename[ ] (char) name of the file to read and write.   
//
//  Return values:  0 : success
//                 -1 : failure
//
****************************************************************/

int writefile( struct pokemon pokearray[ ], int num, char filename[ ] )
{
    FILE *pokefile;
    int count;
    int rVal;

    printf("starting writefile\n");
    pokefile = fopen(filename, "w");
    count = 0;
 
    if (pokefile != NULL)
    {
        while (count <= num)
        {
            fprintf(pokefile,"%d\n", pokearray[count].level); 
            fprintf(pokefile,"%s\n", pokearray[count].name);
            printf("Name written was %s\n", pokearray[count].name);
            count++;
            if(strcmp(pokearray[count].name, "") == 0)
            {
                printf("String name was NULL\n");
                count = num + 1;
            }
        }
        rVal = 0;
    }
    else
    {
        rVal = -1;
    }
    fclose(pokefile);
    return rVal;
}
