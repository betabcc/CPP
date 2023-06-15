#include <iostream>
using namespace std;

union UnionSayilar
{
    int s1;
    double s2;
    char c;
};

struct StructureSayilar
{
    int s1;
    double s2;
    char c;
};

int main()
{
    UnionSayilar us;
    StructureSayilar ss;
    us.s1 = 45;
    us.s2 = 34.35;
    ss.s1 = 56;
    ss.s2 = 345.45;
    cout << "UNION: " << sizeof(us) << endl;
    cout << "STRUCTURE: " << sizeof(ss) << endl;
    return 0;
}