#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <pthread.h>

char validChars[62] = { '0','1','2','3','4','5',
                        '6','7','8','9','A','B',
                        'C','D','E','F','G',
                        'H','I','J','K','L',
                        'M','N','O','P','Q',
                        'R','S','T','U','V',
                        'W','X','Y','Z','a',
                        'b','c','d','e','f',
                        'g','h','i','j','k',
                        'l','m','n','o','p',
                        'q','r','s','t','u',
                        'v','w','x','y','z'};

char* crackedPassword=NULL;
    
char* getSalt( char *cryptPasswd){
    char* extractedSalt = malloc( sizeof(char)*2); //possible memory leaks...
    extractedSalt[0] = cryptPasswd[0];
    extractedSalt[1] = cryptPasswd[1];
    return extractedSalt;
}

void* crackRange( void* pointer){
    for( int index1=0; index1 < 62; index1++){
        for( int index2=0; index2<62; index2++){
            for( int index3=0; index3<62; index3++){
                printf("[[%s]]\n", crypt( "joseph", "jc" ));
                for( int index4=0; index4<62; index4++){}
            }
        }
    }
    return NULL;
    
}

/*
 * Find the plain-text password PASSWD of length PWLEN for the user USERNAME 
 * given the encrypted password CRYPTPASSWD.
 */
void crackSingle(char *username, char *cryptPasswd, int pwlen, char *passwd) { 
    printf("\n[%s]  [%s]  [%d]  [%s]\n", username, cryptPasswd, pwlen, passwd);
    char* salt = getSalt(cryptPasswd);
    printf("SALT=[%s]\n", salt);
    
    char* testCrypt;
    testCrypt = crypt( "joseph", salt );
    printf("TEST CRYPT= [%s]\n (testing array...[%c])\n", testCrypt, validChars[61]);
    pthread_t thread0;
    pthread_create( &thread0, NULL, crackRange, NULL);
    printf( "one path\n");
}

/*
 * Find the plain-text passwords PASSWDS of length PWLEN for the users found
 * in the old-style /etc/passwd format file at pathe FNAME.
 */
void crackMultiple(char *fname, int pwlen, char **passwds) { } 

/*
 * Find the plain-text passwords PASSWDS of length PWLEN for the users found
 * in the old-style /etc/passwd format file at pathe FNAME.
 */
void crackSpeedy(char *fname, int pwlen, char **passwds) { }

/*
 * Find the plain-text password PASSWD of length PWLEN for the user USERNAME 
 * given the encrypted password CRYPTPASSWD withoiut using more than MAXCPU
 * percent of any processor.
 */
void crackStealthy(char *username, char *cryptPasswd, int pwlen, char *passwd, int maxCpu) { }
