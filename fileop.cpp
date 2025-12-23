#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("file1_In.txt");
    ofstream fout("file1_out.txt");

    char ch;
    bool newWord = true;

    while (fin.get(ch))
    {
        if (newWord && ch >= 'a' && ch <= 'z')
            ch -= 32;

        newWord = (ch == ' ' || ch == '\n');
        fout.put(ch);
    }

    fin.close();
    fout.close();
    return 0;
}

