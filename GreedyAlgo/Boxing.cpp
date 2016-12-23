#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define INF 10000000
using namespace std;
typedef vector<int> vi;
class Boxing{
private:
  int max_time;
  int get_vec_element(vi vec,int last_val);
public:
  Boxing();
  int maxCredit(vi a,vi b,vi c,vi d,vi e);
};
Boxing::Boxing(void){
  max_time = 180000;
}
int Boxing::get_vec_element(vi vec,int last_val){
  FOR(i,0,vec.size()-1){
    if (vec[i]>=last_val){
      return vec[i];
    }
  }
  return INF;
}
int compare(const void *a,const void *b){
  int a1 = *(int *)a;
  int a2 = *(int *)b;
  return (a1-a2);
}
int Boxing::maxCredit(vi a,vi b,vi c,vi d,vi e){
  int ret_val = 0;
  FOR(last_val,0,max_time-1){
    int val[5];
    val[0] = get_vec_element(a,last_val);
    val[1] = get_vec_element(b,last_val);
    val[2] = get_vec_element(c,last_val);
    val[3] = get_vec_element(d,last_val);
    val[4] = get_vec_element(e,last_val);
    qsort(val,5,sizeof(int),compare);
    if(val[2]<=(last_val+1000)){
      ret_val++;
      last_val = val[2];
    }
  }
  return ret_val;
}

int main(){
  Boxing box;
  int a[]= {1,2,3,4,5,6};
  int b[]= {1,2,3,4,5,6,7};
  int c[]= {1,2,3,4,5,6};
  int d[]= {0,1,2};
  int e[]= {1,2,3,4,5,6,7,8};
  vi av(a,a+sizeof(a)/sizeof(a[0]));
  vi bv(b,b+sizeof(b)/sizeof(b[0]));
  vi cv(c,c+sizeof(c)/sizeof(c[0]));
  vi dv(d,d+sizeof(d)/sizeof(d[0]));
  vi ev(e,e+sizeof(e)/sizeof(e[0]));
  int val = box.maxCredit(av,bv,cv,dv,ev);
  cout<<val<<endl;
  return 0;
}
