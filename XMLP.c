#include "XMLP.h"

XMLStateType StateLoad( char* XMLPathInput )
{
	XMLStateType State;
	
	FILE* File = fopen( XMLPathInput, "rb" );
	
	fseek( File, 0, SEEK_END );
	State.BufferSize = ftell( File );
	
	rewind( File );
	State.BufferPointer = malloc( State.BufferSize );				// l'heap non va perso come lo stack quando si esce dallo scope
	fread( State.BufferPointer, 1, State.BufferSize, File );
    fclose( File );
    
    return State;
}

XMLStateType StateKill( XMLStateType State )
{
	free( State.BufferPointer );
	State.BufferSize = 0;
	
	return State;
}

void main()
{
	XMLStateType State = StateLoad( "./test.xml" );
	printf( "%s", State.BufferPointer );
}
