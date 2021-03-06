//CF099MushroomGnomes-2
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100000],h[100000],l[100000],r[100000],b[10000],z[10000];
int B[10010];
double dat[10010*4];
double prob(int a,int k,int l,int r){
	if(B[l]<=B[a]&&B[a]<B[r]){
		if(r-l<=1)	return dat[k];
		else		return dat[k]*max(prob(a,k*2+1,l,(l+r)/2),prob(a,k*2+2,(l+r)/2,r));
	}else{
		return 0;
	}
}
void mult(int a,int b,double x,int k,int l,int r){
	//printf("mult(a=%d b=%d x=%lf l=%d r=%d)\n",a,b,x,l,r);
	if(B[b]<=B[l]||B[r]<=B[a])	return;
	else if(B[a]<=B[l]&&B[r]<=B[b])	dat[k]*=x;
	else{
		mult(a,b,x,k*2+1,l,(l+r)/2);
		mult(a,b,x,k*2+2,(l+r)/2,r);
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)	scanf("%d%d%d%d",a+i,h+i,l+i,r+i);
	for(int i=0;i<m;i++){scanf("%d%d",b+i,z+i);B[i]=b[i];}
	B[m]=2000000000+1;B[m+1]=-(2000000000+1);
	sort(B,B+m+2);
	int nB=unique(B,B+m+2)-B;
	for(int i=0;i<10001*4;i++)	dat[i]=1.0;
	for(int i=0;i<n;i++){
		int ll=a[i]-h[i],rr=a[i]-1;
		int aa=lower_bound(B,B+nB,ll)-B,bb=upper_bound(B,B+nB,rr)-B;
		//printf("ll=%d rr=%d B[aa]=%d B[bb]=%d\n",ll,rr,B[aa],B[bb]);
		if(aa<bb)	mult(aa,bb,1.0-l[i]/100.0,0,0,nB-1);
		ll=a[i]+1,rr=a[i]+h[i];
		aa=lower_bound(B,B+nB,ll)-B,bb=upper_bound(B,B+nB,rr)-B;
		//printf("ll=%d rr=%d B[aa]=%d B[bb]=%d\n",ll,rr,B[aa],B[bb]);
		if(aa<bb)	mult(aa,bb,1.0-r[i]/100.0,0,0,nB-1);
	}
	double ans=0;
	for(int i=0;i<m;i++){
		int a=lower_bound(B,B+nB,b[i])-B;
		//printf("prob(%d,0,0,%d)=%lf\n",a,m+1,prob(a,0,0,m+1));
		ans+=prob(a,0,0,nB-1)*z[i];
	}
	printf("%lf\n",ans);
	return 0;
}

