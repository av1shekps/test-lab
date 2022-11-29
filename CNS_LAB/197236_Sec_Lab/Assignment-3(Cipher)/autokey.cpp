#include <bits/stdc++.h>

using namespace std;

string encrypt(string input, char k)
{
    int n = input.size();
    string ak;
    ak += k;
    ak += input.substr(0, n-1);
    string ans;
    for(int i = 0;i < n;i++)
    {
        int sum = (input[i]- 'A' + ak[i] - 'A') % 26;
        ans += 'A' + sum;
    }
    return ans;
    
}

int main()
{
    cout<<"Enter input:"<<endl;
    string input;
    getline(cin, input);
    char k;
    cout<<"Enter key:"<<endl;
    cin>>k;
    string enciphered = encrypt(input, k);
    cout<<"After encryption: "<<enciphered<<endl;
    return 0;
}
