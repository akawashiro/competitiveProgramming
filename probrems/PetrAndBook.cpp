//CF099div2PetrAndBook
#include <stdio.h>
int w[7];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<7;i++)
		scanf("%d",w+i);
	for(int i=0;;i++){
		n-=w[i%7];
		if(n<=0){
			printf("%d\n",i%7+1);
			return 0;
		}
	}
	return 0;
}

