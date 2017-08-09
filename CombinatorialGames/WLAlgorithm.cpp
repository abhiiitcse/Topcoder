#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
bool isWinning(int pos){
  vector<int> moves;
  if((pos-1)>=0){
    moves.push_back(pos-1);
  }
  if((pos-3)>=0){
    moves.push_back(pos-3);
  }
  if((pos-4)>=0){
    moves.push_back(pos-4);
  }
  if(moves.size()>0){
    FOR(i,0,moves.size()){
      if(!isWinning(moves[i])){
	return true;
      }
    }
  }
  return false;
}
  
int main(){
  cout<<isWinning(9)<<endl;
  return 0;
}
