/*Written by 

Prakhar Dev Gupta
IPG-2014-062


*/

#include<bits/stdc++.h>

using namespace std;
vector <pair <int,int> > payoff;
pair<int , int> temp;

int x,y,p,q;

string dominant_A(){
//	int x,y;
	x = payoff[0].first > payoff[2].first? 0:2;
	y= payoff[1].first > payoff[3].first? 1:3;
	
	if(x == 0 && y ==1) return "Confess";
	if(x==0 && y == 3) return "None";
	if(x==2 && y == 3) return "Deny";
	if(x==2 && y == 1) return "None";
	else return NULL;
}

string dominant_B(){
	p = payoff[0].second > payoff[1].second? 0: 1;
	q = payoff[2].second > payoff[3].second ? 2:3;
	
	if(p ==0 && q ==2) return "Confess";
	if(p==0 && q ==3) return "None";
	if(p == 1 && q==3) return "Deny";
	if(p==1 && q ==2) return "None";
	else return NULL;

}
string find_nash(){
	int freq[] = {0,0,0,0};
	freq[x]++;
	freq[y]++;
	freq[p]++;
	freq[q]++;
	//cout<<"bakchodi\n";
//	for(int i=0; i<4; i++) cout<<freq[i]<<" ";
//	cout<<endl;
	string ans;
	vector <string> v;
	if(freq[0]>1)
	v.push_back( " (Confess, Confess) ");
	if(freq[1]>1)
	v.push_back(" (Confess,Deny) ");
	if(freq[2]>1)
	v.push_back(" (Deny,Confess) ");
	if(freq[3]>1)
	v.push_back(" (Deny,Deny) ");
	
	if(!(v.size())) ans = "None";
	else
	for(int i=0; i< v.size(); i++){
		ans = ans+v[i];
	}
	return ans;
}

void display_matrix(){
	for(int i=0; i<payoff.size(); i++){
		if(i==2) cout<<"\n";
		cout<<payoff[i].first<<","<<payoff[i].second<<"   ";
		
		
	}
}

int main(){

	
	cout<<"When both confess?"<<endl;
	cin>>temp.first>>temp.second;
	payoff.push_back(temp);
	
	cout<<"Al confesses and Bill denies?"<<endl;
		cin>>temp.first>>temp.second;
		payoff.push_back(temp);
	
	cout<<"Al denies and Bill confesses?"<<endl;
		cin>>temp.first>>temp.second;
		payoff.push_back(temp);
	
	cout<<"Both Al and Bill denies?\n";
		cin>>temp.first>>temp.second;
		payoff.push_back(temp);
		
		fflush(stdin);
		cout<<"Payoff matrix is :\n\n";
		display_matrix();
		string A,B, Nash;
		
		A = dominant_A();
		B = dominant_B();
		/////cout<<"bakar"<<x<<y<<p<<q;
		cout<<"\nDominant strategy for Al is "<<A<<endl;
		cout<<"\nDominant strategy for Bill is "<<B<<endl;
		Nash = find_nash();
		
//		if(Nash != "")
		cout<<"\n\n\nNash equilibrium state(s): "<<Nash<<endl;
		
		
	
	return 0;
}
