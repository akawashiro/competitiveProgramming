//CF103div2AnagramSearch
#include <string>
#include <iostream>
using namespace std;
int a[26],b[26];
int main(){
	string s,p;
	cin>>s>>p;
	int n=s.size(),m=p.size(),ans=0;
	if(n<m){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<m;i++){
		if(s[i]!='?')
			a[s[i]-'a']++;
		if(p[i]!='?')
			b[p[i]-'a']++;
	}
	for(int i=m-1;i<n;i++){
		int j;
		for(j=0;j<26;j++)
			if(b[j]<a[j])
				break;
		if(j==26)
			ans++;
		if(i<n-1){
			if(s[i+1]!='?')
				a[s[i+1]-'a']++;
			if(s[i+1-m]!='?')
				a[s[i+1-m]-'a']--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

