#include <iostream>
using namespace std;
int main(){
	char key[100], text[100];
	int text_size, key_size;
	cout<<"Enter text_size and key_size\n";
	cin>>text_size>>key_size;

	if(text_size * text_size != key_size){
		cout<<"Invalid text_size and key_size combination\n";
		return 0;
	}
	
	cout<<"Enter the key and the text\n";
	cin>>key>>text;

	int cipherMat[text_size][text_size];
	int textVect[text_size];
	int cipherTextVect[text_size];
	int idx = 0;
	for(int i = 0; i<text_size; i++){
		for(int j = 0; j<text_size; j++){
			cipherMat[i][j] = key[idx++] - 'a';
		}
	}

	for(int i = 0; i<text_size; i++){
		textVect[i] = text[i]-'a';
	}

	for(int i = 0; i<text_size; i++){
		cipherTextVect[i] = 0;
		for(int j = 0; j<text_size; j++){
			cipherTextVect[i] += cipherMat[i][j] * textVect[j];
		}
		cipherTextVect[i] %= 26;
	}
	
	cout<<"Cipher text is\n";	
	for(int i = 0; i<text_size; i++)
		cout<<(char)(cipherTextVect[i] + 'a');
	
	cout<<endl;


}
