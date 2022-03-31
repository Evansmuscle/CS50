#include <stdio.h>

int main(int argc, char const *argv[])
{
    const char name[] = "";
    
    printf("Please tell us your name:\n");
    scanf("%s", &name);
    printf("Hello, %s\n", name);
    scanf("%s", &name);

    return 0;
}
