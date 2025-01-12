#include <stdio.h>
#include <stdlib.h>
#define STR_LEN 100
int str_len(char *s)
{
    int l=0;
    while(s[l]!='\0')
    {
        l++;
    }
    return l;
}
void custom_atoi(char *s) {
    int i = 0;
    int n = str_len(s);
    int number = 0;
    int sign = 1;
    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        number = number * 10 + (s[i] - '0');
        i++;
    }

    printf("Number is : %d",sign * number);
}

int main() {
    char *string=(char*)malloc(STR_LEN*sizeof(char));
    scanf("%s",string);
    custom_atoi(string);
    return 0;
}
