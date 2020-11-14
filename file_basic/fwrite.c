#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person
{
	char name[20];
	int age;
};

static int write_to_file( void );
static int read_from_file( void );

int main( void )
{
	if ( write_to_file() ) {
		printf( "write fail\n" );	
		return -1;
	}
	if ( read_from_file() ) {
		printf( "read fail\n" );	
		return -1;
	}
	return 0;
}

static int write_to_file( void ) 
{
	FILE *fp;
	struct person kim = {
		.name = "Kim",
		.age = 20
	};
	struct person lee = {
		.name = "lee",
		.age = 30
	};

	if ( !( fp = fopen( "persons.txt", "w" ) ) ) {
		printf( "psersons.txt write faile" );
		return -1;
	}

	if ( fwrite( &kim, sizeof( struct person ), 1, fp ) != 1 ) {
		goto ERR;
	}
	if ( fwrite( &lee, sizeof( struct person ), 1, fp ) != 1 ) {
		goto ERR;
	}
	
	fclose( fp );
	return 0;

ERR:
	if ( fp ) {
		fclose( fp );
		goto EXIT;	
	}

EXIT:
	return -1;

}

static int read_from_file( void ) 
{
	FILE *fp;
	struct person persons[2];
	int i;

	if ( !( fp = fopen( "persons.txt", "r" ) ) ) {
		return -1;
	}

	if ( fread( persons, sizeof( struct person ), 2, fp ) != 2 ) {
		fclose( fp );	
		return -1;
	}

	fclose( fp );

	for ( i = 0; i < 2; i++ ) {
		printf( "name: %s, age: %d\n",
						persons[i].name,
						persons[i].age );	
	}
	return 0;
}
