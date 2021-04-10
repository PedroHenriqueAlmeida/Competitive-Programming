#include <bits/stdc++.h>
using namespace std;

/**
 * This algorithm is used to calculate all prime numbers in a range.
 * Completixy: O((R−L+1)loglog(R)+R√loglogR−−√R)
 **/

class SieveEratosthenes {
	private:
		vector<int> primes;
		
		void compute(int l, int r) {
			int lim = sqrt(r);
			vector<bool> isPrime(r-l+1, true);
			isPrime[0] = l != 1;
			for(int i = 2; i <= lim; i++) {
				for(int j = max(i * i, (l+i-1)/i * i); j <= r; j+= i) {
					isPrime[j-l] = false;
				}
			}
			for(int i = 0; i < (int) isPrime.size(); i++) {
				if(isPrime[i]) {
					primes.push_back(i+l);
				}
			}
		}
		
	public:
		SieveEratosthenes(int l, int r) {
			primes = vector<int>();
			compute(l, r);
		}
		
		vector<int> getPrimes() {
			return primes;
		}
};
