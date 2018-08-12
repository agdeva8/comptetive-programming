#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//taking the input
	int nStations; cin>>nStations;
	while(nStations>0)
	{
		int stationLoc[nStations] ={0};
		for(int i=0;i<nStations;i++) cin>>stationLoc[i];
		
		//sorting the locations ascending wise;
		sort(stationLoc,stationLoc+nStations);
		
		//finding whether we can run a car or not.
		//if the distance between the two charging stations exceeded by 200 then she cant go
		//and if the distrance between destination and the charging station 
		//is greater than 100 than also it is impossible to complete the journey
		//because it has to go and come back too.
		bool canReach=true;
		int currStation=0,nextStation=1;
		while(nextStation<nStations)
		{
			if((stationLoc[nextStation]-stationLoc[currStation])>200)
			{
				canReach=false;
				break;
			}
			nextStation += 1;
			currStation += 1;
		}
		if(nStations==1 || (1422-stationLoc[nStations-1])>100) canReach=false;
		if(canReach) cout<<"POSSIBLE\n";
		else 		 cout<<"IMPOSSIBLE\n";
		cin>>nStations;
	}
	return 0;
}