#include<stdio.h>
#include<stdbool.h>

void swap(char *s, int leftIndex, int rightIndex){
    char auxiliary = s[leftIndex];
    s[leftIndex] = s[rightIndex];
    s[rightIndex] = auxiliary;
}

bool isVowel(char character){
    return character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' ||
        character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U';
}

char * reverseVowels(char * s){
    int leftIndex = 0;
    int rightIndex = strlen(s) - 1;
    while (leftIndex < rightIndex){
        if (!isVowel(s[leftIndex])){
            leftIndex++;
            continue;
        }
        if (!isVowel(s[rightIndex])){
            rightIndex--;
            continue;
        }
        swap(s, leftIndex, rightIndex);
        leftIndex++;
        rightIndex--;
    }
    return s;
}