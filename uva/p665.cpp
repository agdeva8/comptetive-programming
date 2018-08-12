// from the hint of book else it turns out it is very complex problem.
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	int M=0;
	cin>>M;
	char space;
	for(int mitr=0;mitr<M;mitr++)
	{	
		int N=0,K=0;
		cin>>N>>K;
		bitset<100> falseCoins; //initiallising all coins as false coins;
		for(int i=0;i<N;i++)
			falseCoins.set(i);
		while(K>0)
		{
			int nLeftPan=0;
			cin>>nLeftPan;
			int nBothPans=2*nLeftPan;
			int coinsPans[nBothPans]={0};
			for(int i=0;i<nBothPans;i++)
				cin>>coinsPans[i];
			char symbol;
			cin>>symbol;
			if(symbol=='=')
				for(int i=0;i<nBothPans;i++)
					falseCoins.reset(coinsPans[i]-1);
			K-=1;
		}
		if(falseCoins.count() == 1)
		{
			int test_i=0;
			while(test_i<N && !falseCoins.test(test_i))
				test_i+=1;
			cout<<(test_i+1)<<"\n";
		}
		else
			cout<<0<<"\n";
		if(mitr<M-1)
			cout<<"\n";
	}
	return 0;
}