#include<bits/stdc++.h>
#include <chrono>
#include <sys/time.h>
using namespace std;

vector<int> initial_permutation;
vector<int> final_permutation;
vector<int> expansion_function;
vector<vector<vector<int>>> Sbox_substitution_tables;
vector<int> ffun_permutation_table;
vector<int> key_PC1;
vector<int> key_PC2;
vector<string> sub_keys;

int give_random_number(int l, int r, int p)
{
	srand(time(0)+p);
    int x = rand() % (r - l + 1) + l;
    return x;
}
void generate_permutation(vector<int> &permutation,int l,int r,int p)
{
	if (l > r)
        return;
    int n = give_random_number(l, r, p);
    permutation.push_back(n);
    generate_permutation(permutation,l, n - 1,p);
    generate_permutation(permutation,n + 1, r,p);	
}
vector<int> get_permutation(unordered_set<int> not_inc,int l,int r,int p)
{
	vector<int> ans,permutation;
	generate_permutation(permutation,l,r,p);
	for(auto i : permutation)
	{
		if(not_inc.find(i)==not_inc.end())
			ans.push_back(i);
	}
	return ans;
}
string hexadecimal_to_binary(string s)
{
	unordered_map<char,string> M = {{'0',"0000"},{'1',"0001"},{'2',"0010"},{'3',"0011"},
									{'4',"0100"},{'5',"0101"},{'6',"0110"},{'7',"0111"},
									{'8',"1000"},{'9',"1001"},{'A',"1010"},{'B',"1011"},
									{'C',"1100"},{'D',"1101"},{'E',"1110"},{'F',"1111"}};
	string ans;
	for(auto i : s)
		ans+=M[i];
	return ans;
}
string binary_to_hexadecimal(string s)
{
	unordered_map<string,string> M = {{"0000","0"},{"0001","1"},{"0010","2"},{"0011","3"},
									  {"0100","4"},{"0101","5"},{"0110","6"},{"0111","7"},
									  {"1000","8"},{"1001","9"},{"1010","A"},{"1011","B"},
									  {"1100","C"},{"1101","D"},{"1110","E"},{"1111","F"}};
	string ans;
	for(int i=0;i<s.length();i+=4)
		ans+=M[s.substr(i,4)];
	return ans;
}
string leftShift(string s,int n)
{
	string temp = s;
	for(int j=0;j<n;j++)
	{
		string s1;
		char t = temp[0];
		for(int i=1;i<temp.length();i++)
			s1.push_back(temp[i]);
		s1.push_back(t);
		temp = s1;
	}
	return temp;
}
string xorop(string s1,string s2)
{
	int n = s1.length();
	string ans;
	for(int i=0;i<n;i++)
	{
		if(s1[i]==s2[i])
			ans.push_back('0');
		else
			ans.push_back('1');
	}
	return ans;
}
string permute(string pt,vector<int> table)
{
	string ans;
	for(int i=0;i<table.size();i++)
		ans.push_back(pt[table[i]-1]);
	return ans;
}
void generate_subkey(string k)
{
	string temp = permute(k,key_PC1);
	for(int i=1;i<=16;i++)
	{
		string c,d;
		c = temp.substr(0,28);
		d = temp.substr(28,28);
		if(i==1||i==2||i==9||i==16)
		{
			c = leftShift(c,1);
			d = leftShift(d,1);
		}
		else
		{
			c = leftShift(c,2);
			d = leftShift(d,2);
		}
		temp = c+d;
		sub_keys.push_back(permute(temp,key_PC2));
	}
}
string SBox_substitution(string s)
{
	string ans="";
	unordered_map<string,int> row={{"00",0},{"01",1},{"10",2},{"11",3}};
	unordered_map<string,int> column={{"0000",0},{"0001",1},{"0010",2},{"0011",3},
									  {"0100",4},{"0101",5},{"0110",6},{"0111",7},
									  {"1000",8},{"1001",9},{"1010",10},{"1011",11},
									  {"1100",12},{"1101",13},{"1110",14},{"1111",16}};
	unordered_map<int,string> M = {{0,"0000"},{1,"0001"},{2,"0010"},{3,"0011"},
									{4,"0100"},{5,"0101"},{6,"0110"},{7,"0111"},
									{8,"1000"},{9,"1001"},{10,"1010"},{11,"1011"},
									{12,"1100"},{13,"1101"},{14,"1110"},{15,"1111"}};
	for(int i=0;i<8;i++)
	{
		string temp = s.substr(i*6,6);
		string temp1,temp2;
		temp1.push_back(s[0]);temp1.push_back(s[5]);
		temp2.push_back(s[1]);temp2.push_back(s[2]);temp2.push_back(s[3]);temp2.push_back(s[4]);
		ans.append(M[Sbox_substitution_tables[i][row[temp1]][column[temp2]]]);
	}
	return ans;
}
string encrypt(string pt)
{
	string ans;
	ans = permute(pt,initial_permutation);
	cout<<"\nInitial Permutation : "<<binary_to_hexadecimal(ans)<<endl;
	string l,r,temp;
	l = ans.substr(0,32);
	r = ans.substr(32,32);
	cout<<"\nL0 : "<<binary_to_hexadecimal(l)<<"   R0 : "<<binary_to_hexadecimal(r)<<endl;
	for(int i=0;i<16;i++)
	{
		temp = r;
		string f_comp=r;
		f_comp = permute(f_comp,expansion_function);
		f_comp = xorop(f_comp,sub_keys[i]);
		f_comp = SBox_substitution(f_comp);
		f_comp = permute(f_comp,ffun_permutation_table);
		r = xorop(l,f_comp);
		l=temp;
		cout<<"L"<<i+1<<" : "<<binary_to_hexadecimal(l)<<"   R"<<i+1<<" : "<<binary_to_hexadecimal(r)<<"   k"<<i+1<<" : "<<binary_to_hexadecimal(sub_keys[i])<<endl;
	}
	temp = r;
	r = l;
	l = temp;
	ans = l+r;
	ans = permute(ans,final_permutation);
	return ans;
}

int main() // here all the tables are generated using random permutations according to requirement
{

	// taking inputs
	string inp,key;
	cout<<"Enter the input string(16 bit) in hexadecimal form : ";
	cin>>inp;
	cout<<"Enter the key(16 bit) in hexadecimal form : ";
	cin>>key;
	
	// generating initial and final permutations
	initial_permutation = get_permutation({},1,64,0);
	final_permutation.resize(64);
	for(int i=0;i<64;i++)
		final_permutation[initial_permutation[i]-1]=i+1;
	
	// generating expansion_function
	expansion_function.push_back(32);
	int p=1;
	while(p<=32)
	{
		for(int j=0;j<4;j++)
			expansion_function.push_back(p++);
		expansion_function.push_back(p%32);
		expansion_function.push_back(p-1);
	}
	expansion_function.pop_back();
	
	// generating S box substitution tables
	for(int i=0;i<8;i++)
	{
		vector<vector<int>> V;
		for(int j=0;j<4;j++)
			V.push_back(get_permutation({},0,15,p++));
		Sbox_substitution_tables.push_back(V);
	}
	
	
	// generating f function permutation table
	ffun_permutation_table = get_permutation({},1,32,0);
	
	// generating key PC1 function
	key_PC1 = get_permutation({8,16,24,32,40,48,56,64},1,64,0);
	
	// generating key PC2 function
	key_PC2 = get_permutation({},1,56,0);
	for(int i=0;i<8;i++)
		key_PC2.pop_back();
	
	// converting the hexadecimal value to binary values
	string b_inp,b_key;
	b_inp = hexadecimal_to_binary(inp);
	b_key = hexadecimal_to_binary(key);
	
	// generating the 16 subkeys of size 48
	generate_subkey(b_key);
	
	cout<<"\nEncryption"<<endl;
	cout<<"------------------------------------------------------------------\n\n";
	string enc,b_enc;
	b_enc = encrypt(b_inp);
	enc = binary_to_hexadecimal(b_enc);
	
	
	cout<<"\n\nEncrypted Message in Binary Form : "<<b_enc<<endl;
	cout<<"\nEncrypted Message in Hexadecimal Form : "<<enc<<endl;
	
	cout<<"\nDecryption"<<endl;
	cout<<"------------------------------------------------------------------\n\n";
	string dec,b_dec;
	reverse(sub_keys.begin(),sub_keys.end());
	b_dec = encrypt(b_enc);
	dec = binary_to_hexadecimal(b_dec);
	
	cout<<"\n\nDecrypted Message in Binary Form : "<<b_dec<<endl;
	cout<<"\nDecrypted Message in Hexadecimal Form : "<<dec<<endl;
	
	return 0;
}
