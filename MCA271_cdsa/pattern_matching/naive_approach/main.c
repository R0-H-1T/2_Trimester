#include<stdio.h>

int length(char *text) {
    int count = 0;
    while (*text != '\0') {
        text++; count++;
    }
    return count;
}

void naive_pattern_matching(char *text, char *pattern) {
    int lengthText = length(text);
    int lengthPattern = length(pattern);
    // why lengthText-lengthPattern -> 
    // 
    if (lengthPattern <= lengthText) {
        for (int i=0; i<=lengthText-lengthPattern; i++) {
            int j;
            for (j=0; j<lengthPattern; j++) {
                if (text[i+j] != pattern[j]) {
                    break;
                }
            }
            if (j == lengthPattern) {
                    printf("\nMatched @ index: %d", i);
                }
        }
    }
}

int main() {
    char *text = "aabcdeaabfaab";
    char *pattern = "aab";    

    printf("Length: %d", length(text));
    naive_pattern_matching(text, pattern);
    return 0;

}