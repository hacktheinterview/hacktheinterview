unsigned int Solution::reverseBits(unsigned int n) {
	unsigned int count = sizeof(num) * 8 - 1;
	unsigned int reverse_num = num;

	num >>= 1;
	while(num) {
		reverse_num <<= 1;
		reverse_num |= num & 1;
		num >>= 1;
		count--;
	}
	reverse_num <<= count;
	return reverse_num;
}
