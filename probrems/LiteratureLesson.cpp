//CF099LiteratureLesson
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;
int isVowel(int c){
	return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
int main(){
	int n,k;
	cin>>n>>k;
	set<string> se;
	string ans="a";
	int aabb=1,abab=1,abba=1;
	for(int l=0;l<n;l++){
		vector<string> vs(4);
		for(int i=0;i<4;i++){
			cin>>vs[i];
			int j,c;
			for(c=0,j=vs[i].size()-1;c<k&&0<=j;j--)
				if(isVowel(vs[i][j]))
					c++;
			if(c==k)	vs[i]=vs[i].substr(j+1);
			else{ 	cout<<"NO"<<endl;	return 0;	}
		}
		if(vs[0]!=vs[1]||vs[2]!=vs[3])aabb=0;
		if(vs[0]!=vs[2]||vs[1]!=vs[3])abab=0;
		if(vs[0]!=vs[3]||vs[1]!=vs[2])abba=0;
	}
	if(aabb&&abab)cout<<"aaaa"<<endl;
	else if(aabb)cout<<"aabb"<<endl;
	else if(abab)cout<<"abab"<<endl;
	else if(abba)cout<<"abba"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

