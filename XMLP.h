/*
*
*	Parser di html che mette a diposizione una funzione di input per generare lo stato dal file xml
*   e diverse funzioni di output
* 	riferimento: https://it.wikipedia.org/wiki/XML
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	char* BufferPointer;
	uint32_t BufferSize;
} XMLStateType;

XMLStateType StateLoad( char* XMLPathInput );
XMLStateType StateKill( XMLStateType State );

char** OutputFilter( XMLStateType State, char* TagInput );					// funzione che dallo stato e dal tipo di tag cercato trova tutte le proprietà e contenuti

void main();
