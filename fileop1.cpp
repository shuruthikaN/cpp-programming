#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
    ifstream fin("file1_In.txt");
    ofstream fout("file1_out.txt");

    if (!fin || !fout)
    {
        cerr << "Error opening file\n";
        return 1;
    }

    string line;

    while (getline(fin, line))
    {
        bool newWord = true;

        for (char &ch : line)
        {
            if (newWord && isalpha(static_cast<unsigned char>(ch)))
                ch = toupper(static_cast<unsigned char>(ch));

            newWord = (ch == ' ' || ch == '\t');
        }

        fout << line << '\n';
    }

    return 0;
}

