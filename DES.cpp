#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <bitset>  
using namespace std;
 
 
int IP[64] = {
58, 50, 42, 34, 26, 18, 10, 2,
60, 52, 44, 36, 28, 20, 12, 4,
62, 54, 46, 38, 30, 22, 14, 6,
64, 56, 48, 40, 32, 24, 16, 8,
57, 49, 41, 33, 25, 17, 9 , 1,
59, 51, 43, 35, 27, 19, 11, 3,
61, 53, 45, 37, 29, 21, 13, 5,
63, 55, 47, 39, 31, 23, 15, 7
};
 
int IP_[64] = {
40, 8, 48, 16, 56, 24, 64, 32,
39, 7, 47, 15, 55, 23, 63, 31,
38, 6, 46, 14, 54, 22, 62, 30,
37, 5, 45, 13, 53, 21, 61, 29,
36, 4, 44, 12, 52, 20, 60, 28,
35, 3, 43, 11, 51, 19, 59, 27,
34, 2, 42, 10, 50, 18, 58, 26,
33, 1, 41, 9 , 49, 17, 57, 25
};

int E_[48] = {
32, 1 , 2 , 3 , 4 , 5,
4 , 5 , 6 , 7 , 8 , 9,
8 , 9 , 10, 11, 12, 13,
12, 13, 14, 15, 16, 17,
16, 17, 18, 19, 20, 21,
20, 21, 22, 23, 24, 25,
24, 25, 26, 27, 28, 29,
28, 29, 30, 31, 32, 1
};

int PC_1[56] = {
57, 49, 41, 33, 25, 17, 9,
1 , 58, 50, 42, 34, 26, 18,
10, 2 , 59, 51, 43, 35, 27,
19, 11, 3 , 60, 52, 44, 36,
63, 55, 47, 39, 31, 23, 15,
7 , 62, 54, 46, 38, 30, 22,
14, 6 , 61, 53, 45, 37, 29,
21, 13, 5 , 28, 20, 12, 4
};

int PC_2[48] = {
14, 17, 11, 24, 1 , 5,
3 , 28, 15, 6 , 21, 10,
23, 19, 12, 4 , 26, 8,
16, 7 , 27, 20, 13, 2,
41, 52, 31, 37, 47, 55,
30, 40, 51, 45, 33, 48,
44, 49, 39, 56, 34, 53,
46, 42, 50, 36, 29, 32
};
 
int S1_BOX[64] = {
14, 4 , 13, 1, 2 , 15, 11, 8 , 3 , 10, 6 , 12, 5 , 9 , 0, 7,
0 , 15, 7 , 4, 15, 2 , 13, 1 , 10, 6 , 12, 11, 9 , 5 , 3, 8,
4 , 1 , 14, 8, 13, 6 , 2 , 11, 15, 12, 9 , 7 , 3 , 10, 5, 0,
15, 12, 8 , 2, 4 , 9 , 1 , 7 , 5 , 11, 3 , 14, 10, 0 , 6, 13	
};
 
int S2_BOX[64] = {
15, 1 , 8 , 14, 6 , 11, 3 , 4 , 9 , 7, 2 , 13, 12, 0, 5 , 10,
3 , 13, 4 , 7 , 15, 2 , 8 , 14, 12, 0, 1 , 10, 6 , 9, 11, 5,
0 , 14, 7 , 11, 10, 4 , 13, 1 , 5 , 8, 12, 6 , 9 , 3, 2 , 15,
13, 8 , 10, 1 , 3 , 15, 4 , 2 , 11, 6, 7 , 12, 0 , 5, 14, 9	
};

int S3_BOX[64] = {
10, 0 , 9 , 14, 6, 3 , 15, 5 , 1 , 13, 12, 7 , 11, 4 , 2 , 8,
13, 7 , 0 , 9 , 3, 4 , 6 , 10, 2 , 8 , 5 , 14, 12, 11, 15, 1,
13, 6 , 4 , 9 , 8, 15, 3 , 0 , 11, 1 , 2 , 12, 5 , 10, 14, 7,
1 , 10, 13, 0 , 6, 9 , 8 , 7 , 4 , 15, 14, 3 , 11, 5 , 2 , 12
};

int S4_BOX[64] = {
7 , 13, 14, 3, 0 , 6 , 9 , 10, 1 , 2, 8, 5 , 11, 12, 4 , 15,
12, 8 , 11, 5, 6 , 15, 0 , 3 , 4 , 7, 2, 12, 1 , 10, 14, 9,
10, 6 , 9 , 0, 12, 11, 7 , 13, 15, 1, 3, 14, 5 , 2 , 8 , 4,
3 , 15, 0 , 6, 10, 1 , 13, 8 , 9 , 4, 5, 11, 12, 7 , 2 , 14	
}; 

int S5_BOX[64] = {
2 , 12, 4 , 1 , 7 , 10, 11, 6 , 8 , 5 , 3 , 15, 13, 0, 14, 9,
14, 11, 2 , 12, 4 , 7 , 13, 1 , 5 , 0 , 15, 10, 3 , 9, 8 , 6,
4 , 2 , 1 , 11, 10, 13, 7 , 8 , 15, 9 , 12, 5 , 6 , 3, 0 , 14,
11, 8 , 12, 7 , 1 , 14, 2 , 13, 6 , 15, 0 , 9 , 10, 4, 5 , 3
}; 

int S6_BOX[64] = {
12, 1 , 10, 15, 9, 2 , 6 , 8 , 0 , 13, 3 , 4 , 14, 7 , 5 , 11,
10, 15, 4 , 2 , 7, 12, 9 , 5 , 6 , 1 , 13, 14, 0 , 11, 3 , 8,
9 , 14, 15, 5 , 2, 8 , 12, 3 , 7 , 0 , 4 , 10, 1 , 13, 11, 6,
4 , 3 , 2 , 12, 9, 5 , 15, 10, 11, 14, 1 , 7 , 6 , 0 , 8 , 13
}; 

int S7_BOX[64] = {
4 , 11, 2 , 14, 15, 0, 8 , 13, 3 , 12, 9, 7 , 5 , 10, 6, 1,
13, 0 , 11, 7 , 4 , 9, 1 , 10, 14, 3 , 5, 12, 2 , 15, 8, 6,
1 , 4 , 11, 13, 12, 3, 7 , 14, 10, 15, 6, 8 , 0 , 5 , 9, 2,
6 , 11, 13, 8 , 1 , 4, 10, 7 , 9 , 5 , 0, 15, 14, 2 , 3, 12
}; 

int S8_BOX[64] = {
13, 2 , 8 , 4, 6 , 15, 11, 1 , 10, 9 , 3 , 14, 5 , 0 , 12, 7,
1 , 15, 13, 8, 10, 3 , 7 , 4 , 12, 5 , 6 , 11, 0 , 14, 9 , 2,
7 , 11, 4 , 1, 9 , 12, 14, 2 , 0 , 6 , 10, 13, 15, 3 , 5 , 8,
2 , 1 , 14, 7, 4 , 10, 8 , 13, 15, 12, 9 , 0 , 3 , 5 , 6 , 11
}; 
 
int P_[32] = {
16, 7 , 20, 21,
29, 12, 28, 17,
1 , 15, 23, 26,
5 , 18, 31, 10,
2 , 8 , 24, 14,
32, 27, 3 , 9,
19, 13, 30, 6,
22, 11, 4 , 25
};
 

int KEY[16][48];
 
void IntToBit(int num[], int length, bitset<64> &N) {
    for (int i = 0; i < length; i++) {
 		bitset<4> tem(num[i]);
 		N[4*i] = tem[3];
 		N[4*i+1] = tem[2];
 		N[4*i+2] = tem[1];
 		N[4*i+3] = tem[0];
	}
}

void StringToBit(string str, int length, bitset<64> &N) {
    for (int i = 0; i < length; i++) {
    	int ass = str[i];
 		bitset<8> tem(ass);
 		for (int j = 0; j < 8; j++) {
 			N[8*i+j] = tem[7-j];
		}
	
	}
}

string BitToString(int length, bitset<64> &N) {
	string str = "        ";
	for (int i = 0; i < length; i++) {
		int num = 0, n = 1;
		for (int j = 7; j >= 0; j--) {
			num += N[8*i+j] * n;
			n *= 2;
		}
		str[i] = num;
	}
	return str;
}
  
void IP_substitution(bitset<64> &M, bitset<64> &tem) {
	for (int i = 0; i < 64; i++) {
		tem[i] = M[IP[i]-1];
	} 
}

void E_expend(bitset<32> &R, bitset<48> &E_exp) {
	for (int i = 0; i < 48; i++) {
		E_exp[i] = R[E_[i]-1];
	}
}  

void P_substitution(bitset<32> &S, bitset<32> &P) {
	for (int i = 0; i < 32; i++) {
		P[i] = S[P_[i]-1];
	}	
}

void W_substitution(bitset<64> &C, bitset<32> &L, bitset<32> &R) {
	for (int i = 0; i < 32; i++) {
		C[i] = R[i];
		C[i+32] = L[i];
	}	
}

void IP__substitution(bitset<64> &C, bitset<64> &tem) {
	for (int i = 0; i < 64; i++) {
		C[i] = tem[IP_[i]-1];
	} 
}

bitset<32> Feistel(bitset<32> &R, bitset<48> &Ki) {
	bitset<48> E_exp;
	E_expend(R, E_exp);

	E_exp ^= Ki;
	
	bitset<32> S;
	
	int n[8], m[8], num[8]; 
	for (int i = 0; i < 8; i++) {
		n[i] = E_exp[6*i] * 2 + E_exp[6*i+5];
		m[i] = E_exp[6*i+1] * 8 + E_exp[6*i+2] * 4 + E_exp[6*i+3] * 2 + E_exp[6*i+4];	
	}
	
	num[0] = S1_BOX[n[0]*16 + m[0]];
	num[1] = S2_BOX[n[1]*16 + m[1]];
	num[2] = S3_BOX[n[2]*16 + m[2]];
	num[3] = S4_BOX[n[3]*16 + m[3]];
	num[4] = S5_BOX[n[4]*16 + m[4]];
	num[5] = S6_BOX[n[5]*16 + m[5]];
	num[6] = S7_BOX[n[6]*16 + m[6]];
	num[7] = S8_BOX[n[7]*16 + m[7]];
	
	for (int i = 0; i < 8; i++) {
 		bitset<4> tem(num[i]);
 		S[4*i] = tem[0];
 		S[4*i+1] = tem[1];
 		S[4*i+2] = tem[2];
 		S[4*i+3] = tem[3];
	}

	bitset<32> P;
	P_substitution(S, P);
		
	return P;
}

void Encrypt(bitset<64> &M, bitset<64> &K, bitset<64> &CC) {
	bitset<64> tem;
	bitset<32> L0;
	bitset<32> R0;
	bitset<32> L;
	bitset<32> R;
	
	IP_substitution(M, tem);
	 
	for (int i = 0; i < 32; i++) {
		L0[i] = tem[i];
		R0[i] = tem[i+32];
	}
	
	bitset<28> C0;
	bitset<28> D0;
	bitset<48> Ki;
	
	// PC-1 substitution
	for (int i = 0; i < 28; i++) {		
		C0[i] = K[PC_1[i]-1];
		D0[i] = K[PC_1[i+28]-1];
	}
	
	for (int i = 1; i <= 16; i++) {
		// LS 
		if (i == 1 || i == 2 || i == 9 || i == 16) {
			int t = C0[0];
			C0 >>= 1;
			C0[27] = t;
			
			t = D0[0];
			D0 <<= 1;
			D0[27] = t;	
		} else {
			int t1 = C0[0], t2 = C0[1];
			C0 <<= 2;
			C0[27] = t2;
			C0[26] = t1;
			
			t1 = D0[0];
			t2 = D0[1];
			D0 <<= 2;
			D0[27] = t2;
			D0[26] = t1;	
		}
		
		// PC-2
		for (int j = 0; j < 24; j++) {
			Ki[j] = C0[PC_2[j]-1];
			Ki[j+24] = D0[PC_2[j+24]-1-24]; 
		}   //K[i] 1-16
		

		for (int k = 0; k <48; k++) {
			KEY[i-1][k] = Ki[k];
		}
		
		L = R0;
		R = L0 ^ Feistel(R0, Ki);
		
		L0 = L;
		R0 = R;
	}
	
	W_substitution(tem, L0, R0);
	IP__substitution(CC, tem);	
}

void Decrypt(bitset<64> &M, bitset<64> &CC) {
	bitset<64> tem;
	bitset<32> L0;
	bitset<32> R0;
	bitset<32> L;
	bitset<32> R;
	bitset<48> Ki;
	
	IP_substitution(CC, tem);
	
	for (int i = 0; i < 32; i++) {
		L0[i] = tem[i];
		R0[i] = tem[i+32];
	}
	
	for (int i = 16; i > 0; i--) {
		
		for (int k = 0; k <48; k++) {
			Ki[k] = KEY[i-1][k];
		}
		
		L = R0;
		R = L0 ^ Feistel(R0, Ki);

		L0 = L;
		R0 = R;
	}
	W_substitution(tem, L0, R0);
	IP__substitution(M, tem);	
	
}

int main() {
	string str = "hello!"; 
	string res ;
	
	bitset<64> M;
	int key[16] = {1,3,3,4,5,7,7,9,9,11,11,12,13,15,15,1};
//	string s = "0001001100110100010101110111100110011011101111001101111111110001";//133457799BBCDFF1
	bitset<64> K; 
	bitset<64> C;
	
	cout << "start:  " << str << endl;
	
	IntToBit(key, 16, K);
	StringToBit(str, str.size(), M);
	
	cout << "start     M:  " ;
	for (int i = 0; i <64; i++)
		cout << M[i];
	cout << endl;
	
	cout << "Key       K:  ";
	for (int i = 0; i <64; i++)
		cout << K[i];
	cout << endl;
	
	Encrypt(M, K, C);
	cout << "Encrypt   C:  " ;
	for (int i = 0; i <64; i++)
		cout << C[i];
	cout << endl;

	Decrypt(M, C);
	cout << "Decrypt   M:  " ;
	for (int i = 0; i <64; i++)
		cout << M[i];
	cout << endl;

	cout << "result:  ";
	res = BitToString(str.size(), M);
	cout << res << endl;	
	
	return 0;
}
