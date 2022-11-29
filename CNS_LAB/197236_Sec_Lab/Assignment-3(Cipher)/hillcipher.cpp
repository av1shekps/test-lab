#include <bits/stdc++.h>

using namespace std;
void getKeyMatrix(string key, int keyMatrix[][3])
{
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}
string encrypt(string input, string key)
{
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);
    
    int inputVector[3][1];
 
    for (int i = 0; i < 3; i++)
        inputVector[i][0] = (input[i]) % 65;
    
    int cipherMatrix[3][1];
    
    int x, i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;
          
            for (x = 0; x < 3; x++)
            {
                cipherMatrix[i][j] +=
                     keyMatrix[i][x] * inputVector[x][j];
            }
         
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
    
    string CipherText;
 
    for (int i = 0; i < 3; i++)
        CipherText += cipherMatrix[i][0] + 65;

    return CipherText;
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

