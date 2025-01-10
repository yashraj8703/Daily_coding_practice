#include <stdio.h>
void special_character_remover(char *input_str){
    int j = 0;
    for (int i = 0; input_str[i] != '\0'; i++)
    {
        if ((input_str[i] >= 'a' && input_str[i] <= 'z') || (input_str[i] >= 'A' && input_str[i] <= 'Z'))
        {
            input_str[j] = input_str[i]; 
            j++;                       
        }
    }
    input_str[j]='\0';
}
int main()
{
    char input_str[100];
    printf("Input the string : ");
    scanf("%s", input_str);
    special_character_remover(input_str);
    printf("After removing special characters from String : %s", input_str);
    return 0; 
}
