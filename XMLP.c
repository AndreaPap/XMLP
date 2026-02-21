#include "XMLP.h"

char* StateLoad( char* XMLPathInput )
{
	char* State;
	
	FILE* File = fopen( XMLPathInput, "rb" );
	
	fseek( File, 0, SEEK_END );
	uint32_t BufferSize = ftell( File );
	
	rewind( File );
	State = malloc( BufferSize + 1 );						// l'heap non va perso come lo stack quando si esce dallo scope
	fread( State, 1, BufferSize, File );
	State[ BufferSize ] = '\0';
    fclose( File );
    
    return State;
}

char* StateKill( char* State )
{
	free( State );
	
	return State;
}

char* OutputFilter( char* State, char* TagInput )
{
	uint8_t InputTagSize = strlen( TagInput );
	
	char StartTag[ InputTagSize + 3 ];						// < all'inizio, spazio dopo e \0 finale
	memcpy( StartTag + 1, TagInput, InputTagSize );
	StartTag[ 0 ] = '<';
	StartTag[ InputTagSize + 1 ] = ' ';
	StartTag[ InputTagSize + 2 ] = '\0'; 
	
	char StopTag1[] = " />";
	
	char StopTag2[ InputTagSize + 4 ];
	memcpy( StopTag2 + 2, TagInput, InputTagSize );
	StopTag2[ 0 ] = '<';
	StopTag2[ 1 ] = '/';
	StopTag2[ InputTagSize + 2 ] = '>';
	StopTag2[ InputTagSize + 3 ] = '\0';
	
	for( uint32_t Cur0 = 0; Cur0 < strlen( State ) - strlen( StartTag ); Cur0 ++ )
	{
		if( memcmp( StartTag, State + Cur0, strlen( StartTag ) ) == 0 )
		{ 
			for( uint32_t Cur1 = Cur0; Cur1 < strlen( State ) - strlen( StopTag2 ); Cur1 ++ )
			{
				uint32_t Size = 0;
				if( memcmp( StopTag1, State + Cur1, strlen( StopTag1 ) ) == 0 ){ Size = Cur1 - Cur0 + strlen( StopTag1 ); }
				else if( memcmp( StopTag2, State + Cur1, strlen( StopTag2 ) ) == 0 ){ Size = Cur1 - Cur0 + strlen( StopTag2 ); }
				
				if( Size != 0 )
				{
					char Buffer[ Size + 1 ];
					memcpy( Buffer, State + Cur0 , Size );
					Buffer[ Size ] = '\0';
					printf( "%s\n", Buffer );
					
					break;
				}
			}
		}
	}
	
}

void main()
{
	char* State = StateLoad( "./test.xml" );
	//printf( "%s\n", State );
	OutputFilter( State, "Text" );
}
