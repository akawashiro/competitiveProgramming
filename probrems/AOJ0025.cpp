#include <iostream>

using namespace std;

int main()
{
	int a[4],b[4];
	while(cin>>a[0]>>a[1]>>a[2]>>a[3])
	{
		cin>>b[0]>>b[1]>>b[2]>>b[3];
		int hit=0,blow=0;
		for(int i=0;i<4;i++)
			if(a[i]==b[i])
				hit++;
		for(int i=0;i<4;i++)
		{
			int j;
			for(j=0;j<4;j++)
				if(a[i]==b[j] && i!=j)
					break;
			if(j!=4)
				blow++;
		}
		cout<<hit<<" "<<blow<<endl;
	}
}

