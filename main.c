#include <stdio.h>
#include <stdlib.h>

// wack attempt to replicate the stdlib atoi() function recursively
int recatoi(int val, char *str) 
{
    // send it; also cancel if string holds characters that aren't numbers
    if (*str == 0 || (int)*str < 48 || (int)*str > 57) {
        return val;
    }

    // take current value and add new decimal place of current char
    return recatoi(val * 10 + (*str - 48), str + sizeof(char)); 
        // this line worked from the get go, I know right
}

int main()
{
    int def_val, rec_val;
    char str[20];

    printf("Input number: ");
    scanf("%s", str);

    rec_val = recatoi(0, &str[0]);
    def_val = atoi(&str[0]);

    printf("STR value:                                       %s\n", str); 
    printf("INT value (from recursive function):             %d\n", rec_val);
    printf("INT value (from default function for reference): %d\n", def_val);

    return(0);
}
