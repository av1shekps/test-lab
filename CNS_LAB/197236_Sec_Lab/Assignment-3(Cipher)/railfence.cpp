#include <bits/stdc++.h>

using namespace std;

string encrypt(string input, int k)
{
    map<int, vector<char>> rows;
    int dir = 0;
    int row = 0;
    for(int i = 0;i < input.size();i++)
    {
        rows[row % k].push_back(input[i]);
        if(dir == 0)
        {
            row++;
            if(row == k)
            {
                dir = 1;
                row = row - 2;
            }
        }
        else
        {
            row--;
            if(row == -1)
            {
                dir = 0;
                row = row + 2;
            }
        }
    }
    string ans;
    for(int i = 0;i < k;i++)
    {
        vector<char> letters = rows[i];
        for(char c: letters)
        ans += c;
    }
    return ans;
}

int main()
{
    cout<<"Enter input:"<<endl;
    string input;
    getline(cin, input);
    int k;
    cout<<"Enter key:"<<endl;
    cin>>k;
    string enciphered = encrypt(input, k);
    cout<<"After encryption: "<<enciphered<<endl;
    return 0;
}
