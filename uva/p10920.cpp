#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int sz;
	long p;
	cin>>sz>>p;
	while(sz!=0 && p!=0){
		int totalBoxes=(sz+1)/2;
		int boxNo=1; int line=1; int column=1;
		while(p>pow(boxNo,2)) boxNo+=2;
		long relP = p-pow(boxNo-2,2);
		if(boxNo==1){
			cout<<"Line = "<<sz/2+1<<", column = "<<sz/2+1<<".\n";
			cin>>sz>>p;
			continue;
		}
		int branchNo = (relP-1)/(boxNo-1);
		if(branchNo==0)
		{
			column = boxNo-relP;
			line = boxNo;
		}
		if(branchNo==1)
		{
			line = (boxNo-1)*2-relP+1;
			column = 1;
		}
		if(branchNo==2)
		{
			column = boxNo-((boxNo-1)*3-relP);
			line = 1;
		}
		if(branchNo==3)
		{
			column = boxNo;
			line = boxNo -((boxNo-1)*4-relP);
		}
		
		line += totalBoxes-(boxNo+1)/2;
		column += totalBoxes-(boxNo+1)/2;
		cout<<"Line = "<<line<<", column = "<<column<<".\n";
		cin>>sz>>p;
	}
}