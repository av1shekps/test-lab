#include <bits/stdc++.h>

using namespace std;

string encrypt(string input, string key)
{
    int n = key.size();
    set<char> s(key.begin(), key.end());
    for(int i = 0;i < n;i++){
        if(key[i] >= 'a' && key[i] <= 'z'){
            key[i] = key[i] - 'a' + 65;
        }
    }
    int rows = n;
    map<char, int> m;
    vector<char> v(n);
    int cnt = 0;
    for(char c = 'A'; c <= 'Z';c++)
    {
        if(s.find(c) != s.end()){
            m[c] = cnt;
            v[cnt] = c;
            cnt++;
        }
    }
    map<char, vector<char>> columns;
    for(int i = 0;i < input.size();i++)
    {
        columns[key[i % n]].push_back(input[i]);
    }
    string ans;
    for(int i = 0;i < key.size();i++)
    {
        char p = v[i];
        vector<char> letters = columns[p];
        for(char c : letters){
            ans += c;
        }
    }
    return ans;
}

int main()
{
    cout<<"Enter input and key:"<<endl;
    string input, key;
    getline(cin, input);
    getline(cin, key);
    string enciphered = encrypt(input, key);
    cout<<"After encryption: "<<enciphered<<endl;
    return 0;
}

