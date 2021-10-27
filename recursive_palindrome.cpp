#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool short
#define true 1
#define false 0
#define TAMLINHA 1000
#define NUMENTRADA 1000

bool isFim(char *s){
    return (strlen(s) >= 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M');
}

/*
*Recursively checks whether the input String matches a palindrome
*@param s input string
*@param i int counter to cycle through input string
*@return resp bool <true> if input string is a palindrome <false> if it's not
*/
bool isPalindromo(char *s, int i){
    bool resp;
    int j = strlen(s) - i - 2;
    if(i > ((int)strlen(s)/2)){
        resp = true;
    }else{
        if(s[i] != s[j]){
            resp = false;
        }else{
            resp = isPalindromo(s, i+1);
        }//fim if
    }//fim if

    return resp;
}

int main(){
    char entrada[NUMENTRADA][TAMLINHA];
    int numEntrada = 0;
    bool resp;

    //the input ends with the string 'FIM'
    do{
        fgets(entrada[numEntrada], TAMLINHA, stdin);
    }while(isFim(entrada[numEntrada++]) == false);
    numEntrada--;

    for(int i = 0; i < numEntrada; i++){
        resp = isPalindromo(entrada[i], 0);
        if(resp){
            printf("YES\n");
        }else{
            printf("NO\n");
        }//fim if
    }//fim for i
    return 0;
}
