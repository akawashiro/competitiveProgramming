//CF099div2Wallpaper
#include <stdio.h>
#include <algorithm>
using namespace std;
int rl[500],rw[500],rh[500],wl[500],ww[500],wp[500];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	scanf("%d%d%d",rl+i,rw+i,rh+i);
	scanf("%d",&m);
	for(int i=0;i<m;i++)	scanf("%d%d%d",wl+i,ww+i,wp+i);
	int ans=0;
	for(int i=0;i<n;i++){
		int c=100000000;
		for(int j=0;j<m;j++){
			int p=wl[j]/rh[i];
			if(p<=0)	continue;
			int d=(2*rl[i]+2*rw[i]+p*ww[j]-1)/(p*ww[j])*wp[j];
			c=min(c,d);
		}
		ans+=c;
	}
	printf("%d\n",ans);
	return 0;
}


