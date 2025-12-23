#include <iostream>
#include <cstring>   // for strcat, strlen
using namespace std;

int main()
{
    char str1[50] = "Programming";
    const char str2[] = "is awesome.";

    // Ensure there is enough space before concatenation
    if (strlen(str1) + strlen(str2) + 1 < sizeof(str1))
    {
        strcat(str1, " ");
        strcat(str1, str2);
    }

    cout << str1;
    return 0;
}

