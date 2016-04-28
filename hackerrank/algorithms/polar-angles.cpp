#include<iostream>
#include<cmath>
#define PI 3.14159265
using namespace std;
double mabs(double j)
{
	if(j>0)
		return j;
	return -j;
}
void shell( double v[],double a[],double b[],int n)
{
	int gap, i, j;
	double temp,temp1,temp2;
	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j=i-gap; j>=0 && v[j]>=v[j+gap]; j-=gap)
			{
				if( (v[j]>v[j+gap]) ||( (v[j]==v[j+gap]) &&((a[j]*a[j]+b[j]*b[j])>(a[j+gap]*a[j+gap]+b[j+gap]*b[j+gap]))))		
				{		temp = v[j];
					v[j] = v[j+gap];
					v[j+gap] = temp;
					temp1 =a[j];
					a[j] = a[j+gap];
					a[j+gap] = temp1;
					temp2 = b[j];
					b[j] = b[j+gap];
					b[j+gap] = temp2;
				}
			}
}
int main()
{
	int n,i;
	cin>>n;
	double a[n],b[n];
	double v[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		if(b[i]==0)
		{
			if(a[i]<0)
				v[i]=PI;
			else
				v[i]=0;
		}
		else if(a[i]==0)
		{
			if(b[i]<0)
				v[i]=(3*PI)/(2.0);
			else
				v[i]=PI/(2.0);
		}
		else
		{
			v[i]=0.0;
			if(b[i]<0 && a[i]<0)
			{
				v[i]+=atan(mabs(b[i]/a[i]));
				//cout<<" org "<<v[i]<<endl;
				v[i]+=PI;
			//	cout<<" cnged "<<v[i]<<endl;
			}
			else if(a[i]<0)
			{
				v[i]+=PI;
				v[i]-=atan(mabs(b[i]/a[i]));
			}
			else if(b[i]<0)
			{
				v[i]-=atan(mabs(b[i]/a[i]));
				v[i]+=2*PI;
			}
			else
				v[i]+=atan(mabs(b[i]/a[i]));
		}
	}
	shell(v,a,b,n);
	for(i=0;i<n;i++)
		cout<<a[i]<<" "<<b[i]<<endl;
}
