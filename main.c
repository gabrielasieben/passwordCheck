#include <stdio.h>
#include <string.h> 
#include <ctype.h>

int passwordCheck(char password[]){

    int score = 0;
    int length = strlen(password);

    // possibilities of input 

    int upperLetter = 0;   // Großbuchstaben
    int lowerLetter = 0;   // Kleinbuchstaben
    int symbol = 0;        //Sonderzeichen
    int digit = 0;         // Nummern
    int repeated = 0;      // Wiederholungen
    
    // evaluate the length  
    if (length < 5){
        score -= 2;
    } else if(length < 8){
        score -= 1;
    } else if(length >= 12){
        score += 2;
    } else {
        score += 1;
    }
    
    // if object was used, changed to true
      for (int i = 0; i < length; i++) {
        if(i + 1 < length && password[i] == password[i+1]){
            repeated = 1;
        }

        if (isupper(password[i])) upperLetter = 1;
        else if (islower(password[i])) lowerLetter = 1;
        else if (isdigit(password[i])) digit = 1;
        else symbol = 1;
    }
     
    // evaluate type of object
    if(repeated) score -= 1;
    if (upperLetter) score += 1;
    if (lowerLetter) score += 1;
    if (digit) score += 1;
    if (symbol) score += 2;


    return score;
}

int main(){
    char password[100];

    printf("Enter a password: ");
    //input of only 99 objects
    scanf("%99s", password);

    int score = passwordCheck(password);

    printf("Your score is: %d\n", score);

    

    return 0;
}