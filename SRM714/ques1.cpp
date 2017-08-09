#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
class RangeEncoding{
public:
  int minRanges(vector<int> arr){
    if(arr.size()==0){
      return 0;
    }
    int count = 1;
    int prev_val = arr[0];
    FOR(i,1,arr.size()){
      if(arr[i]>(prev_val+1)){
	count++;
      }
      prev_val = arr[i];
    }
    return count;
  }
};

int main(){
  RangeEncoding re;
  return 0;
}
