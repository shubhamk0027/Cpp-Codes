int gcd(int a, int b){
	int rem;
	while(b){
		rem=a%b;
		a=b;
		b=rem;
	}
	return a;
}

void EE(int a, int b, int& x, int& y){
    if(a%b == 0){x=0,y=1;return;}
    EE(b,a%b,x,y);int t = x;x = y;y = t - y*(a/b);
}

int EEGCD(int a, int b, int& x, int& y){
    if(a%b == 0){
		x=0,y=1;
		return b;
	}
    int d=EEGCD(b,a%b,x,y);
	int t = x;
	x = y;
	y = t - y*(a/b);
	return d;
}

/* TIME COMPLEXITY
At each recursive step, gcd will cut one of the arguments in half (at most). To see this, look at these two cases:
	If b >= a/2 then on the next step you'll have a' = b and b' < a/2 since the % operation will remove b or more from a.
	If b < a/2 then on the next step you'll have a' = b and b' < a/2 since the % operation can return at most b - 1.
So on each recursive step, gcd will cut one of the arguments in half (at most). This is O(log(N)) steps where N is the max of the initial a and b.
*/

struct EEreturn{
    long long u,v,d;
    EEreturn(long long U, long long V, long long D){
        u=U,v=V,d=D;
    }
};

EEreturn EE(long long a, long long b){
    if(b==0) return EEreturn(1,0,a);
    EEreturn aux = EE(b,a%b);
    long long v = aux.u - (a/b)*aux.v;
    return EEreturn(aux.v,v,aux.d);
}
long long modInverse(int a, int n){
    EEreturn aux = EE(a,n);
    return ((aux.u / aux.d) % n + n) % n;
}

