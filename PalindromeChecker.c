#include <stdio.h>
#include <stdlib.h>
#define WORDLENGTH 50

int performPalindromeCheck(char* inputString , char* reverseString);
char* performReverse(char* inputString , char* reverseString);
int stringLength(char* inputString);

int main (void)
{
    char* inputString = malloc(sizeof(char) * WORDLENGTH);
    char* reverseString = malloc(sizeof(char) * WORDLENGTH);
    int palindromeSwitch = -1;
    printf("What string would you like to palindrome check?\n");
    scanf("%s" , inputString);
    reverseString = performReverse(inputString , reverseString);
    palindromeSwitch = performPalindromeCheck(inputString , reverseString); 

    if(palindromeSwitch == 1)
    {
        printf("%s is a palindrome!\n" , inputString);

    }
    else   
    {
        printf("%s is NOT a palindrome!\n" , inputString);

    }

    free(inputString);
    free(reverseString);
    return 0;
}


char* performReverse(char* inputString, char* reverseString)
{
    int stringCounter = stringLength(inputString);
    *(reverseString + stringCounter) = '\0';
    stringCounter--;
    int counter = 0;
    for(; *(counter + inputString) != '\0'; counter++ , stringCounter--)
    {

        *(reverseString + stringCounter) = *(inputString + counter); 
    }


    return reverseString;
}
int stringLength(char* inputString)
{
    int counter = 0;
    int stringCounter = 0;

    for(; *(counter + inputString) != '\0'; counter++)
    {
        stringCounter++;
    }

    return stringCounter;
}
int performPalindromeCheck(char* inputString , char* reverseString)
{
    int counter = 0;
    int secondCounter = 0;
    for(; *(counter + inputString) != '\0'; counter++ , secondCounter++)
        {
            
            if( *(counter + inputString ) != *(secondCounter + reverseString) )
                {

                    return 0;
                }
            
        }

    return 1;
}
