/*****************************************************************
//
//  NAME:        Constantine Peros
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        February 25, 2021
//
//  FILE:        driver.c
//
//  DESCRIPTION:
//   The code to test and drive iofunctions.c
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include "pokemon.h"
#include "iofunctions.h"
#define SIZE 25

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   The main part of the program
//
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[]): array of arguments
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    struct pokemon pokedex[6];
    char file[SIZE];
    char charizard[SIZE];
    char pikachu[SIZE];
    char snorlax[SIZE];
    char nidorino[SIZE];

    int pokenum;
    int success;
    int charlvl;
    int pikalvl;
    int snorlvl;
    int nidolvl;
    int position;
 
    pokenum = 6;
    charlvl = 62;
    pikalvl = 6;
    snorlvl = 50;
    nidolvl = 18;
    position = 0;

    strcpy(file, "pokedex.txt");
    strcpy(charizard, "Charizard");
    strcpy(pikachu, "Pikachu");
    strcpy(snorlax, "Snorlax");
    strcpy(nidorino, "Nidorino");

    printf("Hello there!\nWelcome to the world of Pokémon!\n");
    printf("My name is Oak! People call me the Pokémon Prof!\n");
    printf("This world is inhabited by creatures called Pokémon!\n");
    printf("Lets start your Pokemon adventure by adding a few Pokémon to your pokedex\n");

    printf("A wild %s(lvl %d) appeared.\n", charizard, charlvl);
    printf("Adding to Pokedex array in Position %d...\n", position);
    strcpy(pokedex[position].name, charizard);
    pokedex[position].level = charlvl;
    
    printf("%s(lvl %d) successfully added to Pokedex array in Position %d\n", 
    pokedex[position].name, pokedex[position].level, position);
    position ++;

    printf("A wild %s(lvl %d) appeared.\n", pikachu, pikalvl);
    printf("Adding to Pokedex array in Position %d...\n", position);
    strcpy(pokedex[position].name, pikachu);
    pokedex[position].level = pikalvl;
    
    printf("%s(lvl %d) successfully added to Pokedex array in Position %d\n", 
    pokedex[position].name, pokedex[position].level, position);
    position ++;

    printf("A wild %s(lvl %d) appeared.\n", snorlax, snorlvl);
    printf("Adding to Pokedex array in Position %d...\n", position);
    strcpy(pokedex[position].name, snorlax);
    pokedex[position].level = snorlvl;
    
    printf("%s(lvl %d) successfully added to Pokedex array in Position %d\n", 
    pokedex[position].name, pokedex[position].level, position);
    position ++;

    printf("A wild %s(lvl %d) appeared.\n", nidorino, nidolvl);
    printf("Adding to Pokedex array in Position %d...\n", position);
    strcpy(pokedex[position].name, nidorino);
    pokedex[position].level = nidolvl;
    
    printf("%s(lvl %d) successfully added to Pokedex array in Position %d\n", 
    pokedex[position].name, pokedex[position].level, position);
    position ++;

    printf("Writing Pokedex array to filename %s\n", file);
    success = writefile(pokedex, pokenum, file);

    if (success == 0)
    {
        printf("Pokedex array successfully written to file\n");     
    }
    else
    {
        printf("Pokedex array unsuccessfully written to file\n");  
    }

    return success;

}
