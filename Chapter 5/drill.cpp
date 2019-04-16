#include <std_lib_facilities.h>

int main()
{
    try
    {
        int i = 0;
        int j = 9;
        if (i = j)
            cout << i;
    }
    catch (exception &e)
    {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }
}
