#include <std_lib_facilities>

int main()
{
    int a, b, c;

    cin >> a >> b >> c;
}

int f(int x, int y, int z)
{
    int area1 = area(x, y);
}

int area(int length, int width)
{
    if (length <= 0 || width <= 0)
        error("non-positive area() argument");
    return length * width;
}
