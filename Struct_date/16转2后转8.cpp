#if 0;
# include<iostream>
# include<string>
using namespace std;
int main()
{
    int n, i, k, len, flag, sum;
    string s, t;
    cin >> n;
    for (k = 0; k < n; k++)
    {
        cin >> s;
        t = "";//�ַ����ĳ�ʼ�� 
        for (i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case '0':t += "0000"; break;
            case '1':t += "0001"; break;
            case '2':t += "0010"; break;
            case '3':t += "0011"; break;
            case '4':t += "0100"; break;
            case '5':t += "0101"; break;
            case '6':t += "0110"; break;
            case '7':t += "0111"; break;
            case '8':t += "1000"; break;
            case '9':t += "1001"; break;
            case 'A':t += "1010"; break;
            case 'B':t += "1011"; break;
            case 'C':t += "1100"; break;
            case 'D':t += "1101"; break;
            case 'E':t += "1110"; break;
            case 'F':t += "1111"; break;
            }
        }
        len = t.length();
        if (len % 3 == 1)//16����ת����2���ƺ���0 
        {
            t = "00" + t;
        }
        else if (len % 3 == 2)
        {
            t = "0" + t;
        }
        flag = 0;
        for (i = 3; i <= t.length(); i += 3)
        {
            sum = (t[i - 3] - '0') * 4 + (t[i - 2] - '0') * 2 + t[i - 1] - '0';
            if (sum)//���Ƶ�һ�ε�ǰ����Ϊ0 
                flag = 1;
            if (flag)
                cout << sum;
        }
        cout << endl;
    }
    return 0;
}
#endif