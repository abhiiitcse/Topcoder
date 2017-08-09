#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MOD 65536
#define MAXN 250000
using namespace std;
class FloatingMedian{
private:
  int tree[MOD+2];
  int vec[MAXN+2];
public:
  /**
   * Constructor
   */
  FloatingMedian(){
    FOR(i,0,MOD+2)
      tree[i] = 0;
  }
  void update(int idx, int val){
    while(idx<=MOD){
      tree[idx] += val;
      if(idx == 0)
	break;
      idx += (idx & -idx);
    }
  }
  long sumOfMedians(int seed, int mul, int add, int N, int K){
    FOR(i,0,N){
      int val=0;
      if(i==0){
	val = seed;
      }else{
	val = (vec[i-1]*mul + add)%MOD;
      }
      vec[i] = val;
      update(vec[i]+1,1);
    }
    FOR(i,0,N){
      cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    
    return 1L;
  }
};
int main(){
  FloatingMedian fm;
  int seed, mul, add, N, K;
  cin>>seed>>mul>>add>>N>>K;
  cout<<fm.sumOfMedians(seed,mul,add,N,K)<<endl;
  
  return 0;
}
