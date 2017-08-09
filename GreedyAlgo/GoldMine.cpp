#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef vector<vi > vvi;
class GoldMine {
private:
  string trim(string str); 
  vvi preprocess(vector <string>);
public:
  vector <int> getAllocation(vector <string>, int);
};
string GoldMine::trim(string str){
  size_t first = str.find_first_not_of(' ');
  if(string::npos == first){
    return str;
  }
  size_t last = str.find_last_not_of(' ');
  return str.substr(first,last-first+1);
}
vvi GoldMine::preprocess(vector <string> mines){
  vvi profit,profit1;
  vvi percentage;
  FOR(i,0,mines.size()-1){
    string str = mines[i];
    istringstream iss(str);
    string token;
    vi pInd;
    while(getline(iss,token,',')){
      int val;
      stringstream convert(trim(token));
      convert>>val;
      pInd.pb(val);
    }
    percentage.pb(pInd);
  }
  FOR(i,0,percentage.size()-1){
    vi indMiners;
    FOR(k,0,6){
      int sum = 0;
      FOR(j,0,percentage[i].size()-1){
	if(k<j){
	  sum += (percentage[i][j]*60*k);
	}else if(k==j){
	  sum += (percentage[i][j]*50*k);
	}else{
	  sum += ((percentage[i][j]*50*j) + (percentage[i][j]*(-20)*(k-j)));
	}
      }
      indMiners.pb(sum/100);
    }
    profit.pb(indMiners);
  }
  FOR(i,0,profit.size()-1){
    vi temp;
    temp.pb(profit[i][0]);
    temp.pb(profit[i][1]);
    FOR(j,2,6){
      temp.pb(profit[i][j] - profit[i][j-1]);
    }
    profit1.pb(temp);
  }
  return profit1;
}

vector <int> GoldMine::getAllocation(vector <string> mines, int miners) {
  vi minersAlloc(mines.size(),0);
  vvi indProfit = preprocess(mines);
  FOR(i,0,indProfit.size()-1){
    FOR(j,0,indProfit[i].size()-1){
      //cout<<indProfit[i][j]<<",";
    }
    //cout<<endl;
  }
  FOR(i,1,miners){
    int max_index =-1;
    int max_val = -100000;
    int max_num_miners = 0;
    FOR(j,0,indProfit.size()-1){
      if(minersAlloc[j] > max_num_miners){
	max_num_miners  = minersAlloc[j];
      }
      if(((indProfit[j][minersAlloc[j]+1])>max_val) && (minersAlloc[j]<6)){
	max_val = indProfit[j][minersAlloc[j]+1];
	max_index = j;
      }else if((indProfit[j][minersAlloc[j]+1]) == max_val){
	if(minersAlloc[j] < max_num_miners){
	  //max_index = j;
	}
      }
    }
    minersAlloc[max_index]++;
  }
  FOR(i,0,mines.size()-1){
    cout<<minersAlloc[i]<<endl;
  }
  return minersAlloc;
}
int main(){
  GoldMine gm;
  string str[] = { "050, 000, 000, 000, 000, 050, 000",
		   "050, 000, 000, 000, 000, 050, 000",
		   "050, 000, 000, 000, 000, 050, 000",
		   "050, 000, 000, 000, 000, 050, 000",
		   "050, 000, 000, 000, 000, 050, 000",
		   "050, 000, 000, 000, 000, 050, 000",
		   "050, 000, 000, 000, 000, 050, 000",
		   "050, 000, 000, 000, 000, 050, 000",
		   "050, 000, 000, 000, 000, 050, 000",
		   "050, 000, 000, 000, 000, 050, 000" };
  vector <string> mines(str,str+10);
  gm.getAllocation(mines,30);
  return 0;
}
