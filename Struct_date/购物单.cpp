#if 0;
#include <iostream>
using namespace std;
int main()
{

    double arr[50][2];
    int count = 0;
    for (int i = 0; i <50; i++)
    {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    double sum = 0;
    for (int i = 0; i < 50; i++)
    {
        sum = sum + (arr[i][0] * arr[i][1]);
    }
    cout << sum/100;
    return 0;
}
#endif