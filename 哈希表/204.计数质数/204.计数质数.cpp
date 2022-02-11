#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int countPrimes(int n) {
//         int count=0;
//         for(int i=2;i<n;++i){
//             count+=isPrimes(i);
//         }
//         return count;
//     }
//
// private:
//     bool isPrimes(int n){
//         for(int i=2;i*i<=n;++i){
//             if(n%i==0) return false;
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     int countPrimes(int n) {
//         vector<int> isPrimes(n,1);
//         int count=0;
//         for(int i=2;i<n;++i){
//             if(isPrimes[i]){
//                 count++;
//                 if((long long)i*i<n){
//                     for(int j=i*i;j<n;j+=i){
//                         isPrimes[j]=0;
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> Primes;
        vector<int> isPrimes(n, 1);
        for (int i = 2; i < n; ++i)
        {
            if (isPrimes[i])
                Primes.push_back(i);
            for (int j = 0; j < Primes.size() && i * Primes[j] < n; ++j)
            {
                isPrimes[i * Primes[j]] = 0;
                if (i % Primes[j] == 0)
                    break;
            }
        }
        return Primes.size();
    }
};

int main()
{
    Solution ans;
    cout << "The quantities of prime are:"
         << ans.countPrimes(499979);
    return 1;
}