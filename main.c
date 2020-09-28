#include <stdio.h>

// wack attempt to replicate the stdlib atoi() function recursively
int recatoi(int val, char *str) 
{
    // send it boi
    if (*str == 0)
        return val;

    // cancel if string holds characters that aren't numbers
    if ((int)*str < 48 || (int)*str > 57) {
        return 0;
    }

    // take current value and add new decimal place of current char
    return recatoi(val * 10 + (*str - 48), str + sizeof(char)); 
        // this line worked from the get go, im a professional you know
}

int main()
{
    int val;
    char str[20];

    printf("Input number: ");
    scanf("%s", str);

    val = recatoi(0, &str[0]);

    printf("String value = %s, INT value = %d\n", str, val);

    return(0);
}
