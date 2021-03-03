#include<bits/stdc++.h>
using namespace std;
string MWS(string a,string t)
{
	
	int mini=-1,minj=-1;
	int m=INT_MAX,i=0,j=0;
	unordered_map<char,int> map;
	for(int i=0;i<t.size();i++) map[t[i]]++;
	int count=map.size();
	while(j<a.size())
	{
		if(map.find(a[j])!=map.end())
		{
			map[a[j]]--;
			if(map[a[j]]==0)count--;
			
		}
		
		
		if(count==0){
			m=min(m,j-i+1);
			if(m==j-i+1){
				mini=i;minj=j;
			}
			while(map.find(a[i])==map.end()||map[a[i]]<0)
			{
				if(map.find(a[i])!=map.end()){
				map[a[i]]++;
				if(map[a[i]]==1)count++;	
				}
				i++;
			}
	
		}
		if(count==0){
			m=min(m,j-i+1);
			if(m==j-i+1){
				mini=i;minj=j;
			}
		} 
		j++;
	}
	if(mini!=-1)
	{
		a.erase(a.begin(),a.end()-(a.size()-mini));
		minj-=mini;
		a.erase(a.begin()+minj+1,a.end());
		
		return a;
	}
	return "";
}

