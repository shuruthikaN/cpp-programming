#include <iostream>
using namespace std;

int main()
{
    char str1[50] = "Programming";
    char str2[] = "is awesome.";

    int i = 0, j = 0;
    while (str1[i] != '\0') i++;
    str1[i++] = ' ';
    while (str2[j] != '\0')
        str1[i++] = str2[j++];
    str1[i] = '\0';

    cout << str1;
    return 0;
}

