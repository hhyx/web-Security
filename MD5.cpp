#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int length = 0;     // N
unsigned int A = 0x67452301; // 初始化 
unsigned int B = 0xefcdab89;
unsigned int C = 0x98badcfe;
unsigned int D = 0x10325476;

const unsigned int T[]={
    0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,
    0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,0x698098d8,
    0x8b44f7af,0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,
    0xa679438e,0x49b40821,0xf61e2562,0xc040b340,0x265e5a51,
    0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
    0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,
    0xfcefa3f8,0x676f02d9,0x8d2a4c8a,0xfffa3942,0x8771f681,
    0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,0xf6bb4b60,
    0xbebfbc70,0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,
    0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,0xf4292244,
    0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,
    0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,
    0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};
        
const unsigned int s[]={
	7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22,
	5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20,
    4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,
	6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21};       


// 填充 分块 
unsigned int* padding(string str) {
	int L = (str.length()+8)/64+1;
	length = L*16;
	unsigned int *strByte = new unsigned int[length];
	for (unsigned int i = 0; i < length; i++)
        strByte[i]=0;
	
	for (int i = 0; i < str.length(); i++) {
		strByte[i/4] |= (str[i])<<((i%4)*8);
	} 
	strByte[str.length()/4] |= 0x80<<(((str.length()%4))*8);
	strByte[length-2] = str.length()*8;
	
	return strByte;
}

// 压缩函数
void compress(unsigned int MD[]) {
	unsigned int a = A;
    unsigned int b = B;
    unsigned int c = C;
    unsigned int d = D;
    unsigned int k, g;
    
    for (int i = 0; i < 64; i++) {
    	if (i < 16) {
    		g = ((b & c) | (~b & d));
    		k = i;
		} else if (i < 32) {
			g = ((b & d) | (c & ~d));
			k = (1+5*i)%16;
		} else if (i < 48) { 
			g = (b ^ c ^ d);
			k = (5+3*i)%16;
		} else {
			g = (c ^ (b | ~d));
			k = (7*i)%16;
		}
		unsigned int tem = d;
		d = c;
		c = b;
		b = b + ((a + g + MD[k] + T[i]) << s[i] | (a + g + MD[k] + T[i]) >> (32 - s[i]));
		a = tem;		
	}  
	
	A = A+a;
	B = B+b;
	C = C+c;
	D = D+d;
}

// 转换为16进制
string change(int a) {
	int b;
	string res = "";
	
	for (int i = 0; i < 4; i++) {
		char str1[2];		
		b = (a >> i*8) % 256 & 0xff;
		itoa(b, str1, 16);
		res += str1;
	} 
	return res;
} 

string MD5(string str) {
	unsigned int *strByte = padding(str);
	
	for (int i = 0; i < length/16; i++) {
		unsigned int tem[16];
		for (int j = 0; j < 16; j++) {
			tem[j] = strByte[i*16+j];
		}
		compress(tem);
	}
	
	return change(A) + change(B) + change(C) + change(D);
}

int main() {
	string str;
	cout << "input string: " ;
	cin >> str;
	string res = MD5(str);
	cout << "MD5: ";
	cout << res;	
	
	return 0;
} 
