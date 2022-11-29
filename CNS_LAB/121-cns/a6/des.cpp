#include <bits/stdc++.h>
using namespace std;

string bin2hex(string s){
	unordered_map<string, string> mp;
	mp["0000"] = "0";
	mp["0001"] = "1";
	mp["0010"] = "2";
	mp["0011"] = "3";
	mp["0100"] = "4";
	mp["0101"] = "5";
	mp["0110"] = "6";
	mp["0111"] = "7";
	mp["1000"] = "8";
	mp["1001"] = "9";
	mp["1010"] = "A";
	mp["1011"] = "B";
	mp["1100"] = "C";
	mp["1101"] = "D";
	mp["1110"] = "E";
	mp["1111"] = "F";

	string ret = "";
	for(int i = 0; i<s.length(); i+=4){
		string key = "";
		key += s[i];
		key += s[i+1];
		key += s[i+2];
		key += s[i+3];
		ret += mp[key];
	}

	return ret;
}

string hex2bin(string s){
	unordered_map<char, string> mp;
	mp['0'] = "0000";
	mp['1'] = "0001";
	mp['2'] = "0010";
	mp['3'] = "0011";
	mp['4'] = "0100";
	mp['5'] = "0101";
	mp['6'] = "0110";
	mp['7'] = "0111";
	mp['8'] = "1000";
	mp['9'] = "1001";
	mp['A'] = "1010";
	mp['B'] = "1011";
	mp['C'] = "1100";
	mp['D'] = "1101";
	mp['E'] = "1110";
	mp['F'] = "1111";

	string ret = "";
	for(int i = 0; i<s.size(); i++){
		ret+=mp[s[i]];
	}

	return ret;	
}

string permute(string s, int sub[], int n){
	string ret = "";
	for(int i = 0; i<n; i++){
		ret += s[sub[i]-1];
	}
	
	return ret;	
}

string axorb(string a, string b){
	string ret = "";
	for(int i = 0; i<a.size(); i++){
		if(a[i] == b[i])
			ret += "1";
		else
			ret += "0";
	}

	return ret;
}


string shift_left(string s, int shifts){
	for(int i = 0; i<shifts; i++)
		for(int j = 0; j<s.size(); j++)
			s[j] = s[(j+1)%28];
	

	return s;
}

string des(string pt, string key, vector<string> rkb){
	int initial_per[64] = {
		58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 
		57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7
	};

	// first initial permutation of the plain text
	string ip_pt = permute(pt, initial_per, 64);

	// Split the pt into left and right halves
	string lpt = ip_pt.substr(0, 32);
	string rpt = ip_pt.substr(32, 32);

	// expansion d-box
	int dbox[] = {};

	// s-box
	int sbox[][] = {};

	// permutation table
	int per[] = {};

	for(int i = 0; i<16; i++){
		// first expand the right part
		string r_exp = permute(rpt, dbox, 48);

		// r_exp XOR rk[i]
		string r_xor = axorb(r_exp, rk[i]);

		// applying s-box
		string o = "";

		for(int i = 0; i<8; i++){
			int row = 2 * int(x[i*6] - '0') + int(x[i*6+5]-'0');
			int col = 8 * int(x[i*6+1] - '0') + 4 * int(x[i*6+2] - '0') + 2*int(x[i*6+3] - '0') + int(x[i*6+4] - '0');
			int val = sbox[i][row][col];
			op += char(val / 8 + '0');
	           	val = val % 8;
        	   	op += char(val / 4 + '0');
           		val = val % 4;
        		op += char(val / 2 + '0');
            		val = val % 2;
            		op += char(val + '0');
		}

		op = permute(op, per, 32);

		x = xor_(op, left);

       		left = x;


        	if (i != 15) {
            		swap(left, right);
        	}
        	cout << "R" << i << " " << bin2hex(left)
             		<< " " << bin2hex(right) << " " << rk[i]
             		<< endl;
		
		string final_ans = lpt + rpt;
		
		int final_per[] = {}

		string cipher = bin2hex(permute(final_ans, final_per, 64);

		return cipher;

}

int main(){
	string pt, key;
	// taking input 
	cin>>pt;
	cin>>key;		
	// we have taken only single block input as of now
	// convert the message to binary
	pt = hex2bin(pt);
	key = hex2bin(key);

	// perform des 
	string cipher = des(pt, key);


	return 0;
}
