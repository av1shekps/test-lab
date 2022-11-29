#include <iostream>
using namespace std;

int main(){
	string key, msg;
	cout<<"Enter key: ";
	cin>>key;
	cout<<"Enter msg: ";
	cin>>msg;
	int key_size = key.size();
	int msg_size = msg.size();
	
	string cipheredText = "";
	
	int i = 0, j = 0;
	for(; i<key_size && j<msg_size; i++, j++){
		cipheredText += (char)((key[i] - 'a' + msg[j] - 'a') % 26 + 'a');
	}

	if(i==key_size){
		i = 0;
		while(j<msg_size){
			cipheredText += (char)((msg[i] - 'a' + msg[j] - 'a') % 26 + 'a');
			i++;j++;
		}
	}

	cout<<"Ciphered text: "<<cipheredText<<endl;
	return 0;
}
