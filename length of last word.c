#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int lengthstr = strlen(s);
    int len = 0;

    int i = lengthstr - 1;

    if(s[i] == ' '){
        while(s[i] == ' '){
            i--;
        } 
    }

    while(i > -1 && s[i] != ' '){
        len++;
        i--;
    }

    return len;
}

int main() {
    char str1[] = "Hello World";
    char str2[] = " n     f  ";
    char str3[] = "aaaaa";

    printf("Length of last word in \"%s\": %d\n", str1, lengthOfLastWord(str1));
    printf("Length of last word in \"%s\": %d\n", str2, lengthOfLastWord(str2));
    printf("Length of last word in \"%s\": %d\n", str3, lengthOfLastWord(str3));

    return 0;
}