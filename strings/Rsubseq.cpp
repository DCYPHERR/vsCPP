// Return subseq of a string
#include <iostream>
#include <string>
using namespace std;

int subseq(string y, string op[]);

int subseq(string y, string op[])
{
    if (y.size() == 0)
    {
        op[0] = "";
        return 1;
    }

    string smallString = y.substr(1);

    int smallOutputsize = subseq(smallString, op);

    for (int i{0}; i < smallOutputsize; i++)
    {
        op[i + smallOutputsize] = y[0] + op[i];
    }
    return 2 * smallOutputsize;
}

int main()
{
    string y;
    cin >> y;

    string *op = new string[10000];
    int count = subseq(y, op);
    for (int i{0}; i < count; i++)
    {
        cout << op[i] << endl;
    }
    return 0;
}


// //#include <iostream>
// using namespace std;
// int main()
// {
// 	string smallOutputsize;


// 	return 0;
// }