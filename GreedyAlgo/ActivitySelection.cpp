#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef struct ACT{
  int start;
  int finish;
}act;
int compare(const void *a, const void *b){
  act *a1 = (act *)a;
  act *a2 = (act *)b;
  return ((*a1).finish - (*a2).finish);
}
void printMaxActivity(vector<act> activity){
  if(activity.size()>0){
    cout<<activity[0].start<<"-"<<activity[0].finish<<endl;
  }
  int last_activity = 0;
  FOR(i,1,activity.size()-1){
    if(activity[i].start >= activity[last_activity].finish){
      cout<<activity[i].start<<"-"<<activity[i].finish<<endl;
      last_activity = i;
    }
  }
}
  
int main(){
  vector<act> activity;
  act ex[6];
  ex[0].start = 1;ex[0].finish = 2;
  ex[1].start = 3;ex[1].finish = 4;
  ex[2].start = 0;ex[2].finish = 6;
  ex[3].start = 5;ex[3].finish = 7;
  ex[4].start = 8;ex[4].finish = 9;
  ex[5].start = 5;ex[5].finish = 9;
  FOR(i,0,5){
    activity.pb(ex[i]);
  }
  qsort(&activity[0],activity.size(),sizeof(act),compare);
  printMaxActivity(activity);
  return 0;
}
  
