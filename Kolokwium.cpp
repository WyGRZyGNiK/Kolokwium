#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	cout<<"Zadanie 1.2"<<endl;
	int a,b;
	cin>>a>>b;
	cout<<a%b<<endl;
	cout<<endl<<"Zadanie 2"<<endl;
	fstream plik;
	plik.open("dane.txt", ios::in);
	vector<double> w;
	double c;
	double minw=100000, maxw=-100000000, sum=0;
	
	while(plik>>c){
		w.push_back(c);
		if(c<minw) minw = c;
		if(c>maxw) maxw = c;
		sum+=c;
	}
	plik.close();
	plik.open("wyniki.txt", ios::out);
	
	cout<<"Zadanie 2.1"<<endl;
	for(double &e:w){//Zmodyfikowana petla
		cout << e << " ";
	}
	cout<<endl;
	cout<<w.size()<<endl;
	cout<<endl<<"Zadanie 2.2"<<endl;
	cout<<"Min: "<<minw<<"; Max: "<<maxw<<"; Srednia: "<<sum/w.size()<<endl;
	cout<<"Zadanie 2.3"<<endl;
	double d = (maxw-minw)/10;
	int count = 0;
	for(int i=0; i<10;i++){
		count = 0;
		for(int j=0;j<w.size();j++){
			if(w[j]>=minw+i*d && w[j]<minw+(i+1)*d){
				count++;
			}
			
		}
		if(i==9) count++;
		cout<<"Przedzial "<<i+1<<": "<<count<<endl;
		plik<<"Przedzial "<<i+1<<": "<<count<<endl;
	}
	plik.close();
	cout<<endl<<endl;
	cout<<"Zadanie 3.1"<<endl;
	cin>>a;
	char z='a';
	for(int i=0;i<a;i++){
		z='a';
		for(int j=0;j<a-i-1;j++){
			cout<<"  ";
		}
		for(int j=0;j<i*2+1;j++){
			cout<<z<<" ";
			z+=1;
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	cout<<"Zadanie 4.2"<<endl;
	string onp;
	cin>>onp;
	int x;
	stack<int> s;
	for(int i=0;i<onp.size();i++){
		if(onp[i]=='+'){
			x=s.top();
			s.pop();
			s.top()+=x;
		}
		else if(onp[i]=='-'){
			x=s.top();
			s.pop();
			s.top()-=x;
		}
		else if(onp[i]=='*'){
			x=s.top();
			s.pop();
			s.top()*=x;
		}
		else if(onp[i]=='/'){
			x=s.top();
			s.pop();
			s.top()/=x;
		}
		else{
			s.push(onp[i]-48);
		}
	}
	cout<<s.top();
	
	
	
	
	
	return 0;
}


