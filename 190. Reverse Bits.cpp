//方法一：按位计算
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t ret = 0;
		int time = 0;
		while(n > 0)
		{
			ret = ret<<1;
			ret += n & 1;
			n = n >> 1;
			++time;
		}
		return ret ? ret<<(32-time) : ret;
	}
};
/*
方法二：
for 8 bit binary number abcdefgh, the process is as follow:
abcdefgh -> efghabcd -> ghefcdab -> hgfedcba
*/
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		n = (n & 0x0000ffff)<<16 | (n & 0xffff0000)>>16;
		n = (n & 0x00ff00ff)<<8 | (n & 0xff00ff00)>>8;
		n = (n & 0x0f0f0f0f)<<4 | (n & 0xf0f0f0f0)>>4;
		n = (n & 0x33333333)<<2 | (n & 0xcccccccc)>>2;
		n = (n & 0x55555555)<<1 | (n & 0xaaaaaaaa)>>1;
		return n;
	}
};
