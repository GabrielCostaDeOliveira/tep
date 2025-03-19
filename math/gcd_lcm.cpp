long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}

int lcd(int a, int b){
	return a*b/gcd(a, b);
}
