//
//  main.c
//  15 - K
//
//  Created by Erica Correa on 2/1/16.
//  Copyright © 2016 Turn to Tech. All rights reserved.
//

int stringLength (char string[]) {
    int length = 0;
    while (string[length] != 0) {
        length++;
    }
    return length;
}

char* delimiter[] = {",", ".", " ", "\t"};

int delimiter_size = sizeof(delimiter) / sizeof(delimiter[0]);

char indexCheck (char string[], int element) {
    int y = 0;
    
    for (int x = 0; x < delimiter_size; x++) {
        if (delimiter[x][y] == string[element]) {
            return 1;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    //printf("%c\n", *(delimiter[0]+1));
    
    char stringArray[] = "USA.      Canada\t Mexico,,,,, Bermuda Grenada, Belize";
    
    //function to find number of characters in largest word
    int max = 0;
    int letter_count = 0;
    
    for (int x = 0; x < stringLength(stringArray); x++) {
        for (int a = 0; a < delimiter_size; a++) {
            if (stringArray[x] == *delimiter[a] && stringArray[x + 1] == ' ') {
                
            }
            else if (stringArray[x] == *delimiter[a]) {
                letter_count = 0;
            }
            else {
                letter_count++;
                if (letter_count > max) {
                    max = letter_count;
                }
            }
        }
    }
    
    //function to find number of words
    int num_words = 0;
    
    for (int y = 0; y < stringLength(stringArray); y++) {
        for (int z = 0; z < delimiter_size; z++) {
            if (stringArray[y] == delimiter[z][0] && stringArray[y + 1] == ' ') {
                
            }
            else if (stringArray[y] == delimiter[z][0]) {
                num_words++;
            }
        }
    }
    
    char **newArray = (char**)malloc((num_words+1)*sizeof(char*));
    int word = 0;
    int character = 0;
    
    newArray[word]= malloc(max);
    
    //function to add letters of each word to the new array
    for (int string_index = 0; string_index <= stringLength(stringArray); string_index++) {
        if (indexCheck(stringArray, string_index) == 0) {
            newArray[word][character] = stringArray[string_index];
            character++;
        }
        else {
            for (int delimiter_index = 0; delimiter_index < delimiter_size; delimiter_index++) {
                if (stringArray[string_index] == *delimiter[delimiter_index] && stringArray[string_index + 1] == ' ') {
                }
                else if (stringArray[string_index] == *delimiter[delimiter_index]) {
                    newArray[word][character] = '\0';
                    word++;
                    newArray[word]= malloc(max);
                    character = 0;
                }
            }
        }
    }
    
    for (int array_word = 0; array_word <= num_words; array_word++) {
        printf("Country #%d is: %s\n", array_word + 1, newArray[array_word]);
    }
    
    return 0;
}
