//CF099div1DigitsPermutations
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main(){
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	vector<int> num(10,0);
	int n=s.size();
	for(int i=0;i<n;i++)
		num[s[i]-'0']++;
	int rs=-1,rz=-1;
	for(int i=1;i<=5;i++)
		if(0<num[i]&&0<num[10-i]){
			if(i!=5)	num[i]--,num[10-i]--;
			else		num[i]--;
			int z=1;
			for(int j=0;j<5;j++)
				z+=min(num[j],num[9-j]);
			if(rz<z){
				rz=z;
				rs=i;
			}
			if(i!=5)	num[i]++,num[10-i]++;
			else		num[i]++;
		}
	if(rs==-1){
		cout<<s<<endl<<s<<endl;
		return 0;
	}
	string ans_1,ans_2;
	vector<int> n1=num,n2=num;
	int t=n1[0]-min(n1[0],n1[9]);
	ans_1+=string(t,'0');
	ans_2+=string(t,'0');
	n1[0]-=t,n2[0]-=t;
	ans_1+=(char)(rs+'0');
	ans_2+=(char)(10-rs+'0');
	n1[rs]--,n2[10-rs]--;
	for(int i=0;i<10;i++){
		int c=min(n1[i],n2[9-i]);
		ans_1+=string(c,i+'0');
		ans_2+=string(c,9-i+'0');
		n1[i]-=c,n2[9-i]-=c;
	}
	for(int i=0;i<10;i++){
		ans_1+=string(n1[i],i+'0');
		ans_2+=string(n2[i],i+'0');
	}
	reverse(ans_1.begin(),ans_1.end());
	reverse(ans_2.begin(),ans_2.end());
	cout<<ans_1<<endl<<ans_2<<endl;
	return 0;
}

