#include<bits/stdc++.h>
using namespace std;

void upmove(int a[4][4]){
	int i,j,li,ri;
	for(j=0;j<4;j++){
		li=0,ri=j;

		for(i=1;i<4;i++){
			if(a[i][j]!=0)
			{
				if(a[i-1][j]==0 || a[i-1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[++li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li++;
			}
		}
	}
}

void downmove(int a[4][4]){
	int i,j,li,ri;
	for(j=0;j<4;j++){
		li=3,ri=j;

		for(i=2;i>=0;i--){
			if(a[i][j]!=0)
			{
				if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[--li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}
}

void leftmove(int a[4][4]){
	int i,j,li,ri;
	for(i=0;i<4;i++){
		li=i,ri=0;

		for(j=1;j<4;j++){
			if(a[i][j]!=0)
			{
				if(a[i][j-1]==0 || a[i][j-1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][++ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri++;
			}
		}
	}
}

void rightmove(int a[4][4]){

	int i,j,li,ri;
	for(i=0;i<4;i++){
		li=i,ri=3;

		for(j=2;j>=0;j--){
			if(a[i][j]!=0)
			{
				if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][--ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}

void addblock(int a[4][4]){
	int li,ri;
	srand(time(0));
	while(1){
		li=rand()%4;
		ri=rand()%4;

		if(a[li][ri]==0){
			a[li][ri]=pow(2,li%2 + 1);
			break;
		}
	}

}

void disp(int a[4][4])
{
	cout<<"\n\n\n\n\n\t\t\t\t<< 2048 GAME >>\n\n\t\t";
	cout<<"\n\t\tPress w: up, s: down, a: left, d: right, q: quit game ";
	cout<<"\n\n\n";
	
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";

		for(j=0;j<4;j++){
			if(a[i][j]==0){
				cout<<"|   ";
			}
			else{
				cout<<"| "<<a[i][j]<<" ";
			}
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t-----------------\n";
}

int check(int tmp[4][4],int a[4][4]){
	int fl=1,i,j;
	for(i=0;i<4;i++){
    	for(j=0;j<4;j++){
    		if(tmp[i][j]!=a[i][j]){
    			fl=0;
    			break;
			}
		}
	}
	return fl;
}

int checkover(int a[4][4]){
	int fl=0,gl=0,i,j;
	for(i=0;i<4;i++){
    	for(j=0;j<4;j++){
    		if(a[i][j]==0){
    			fl=1;
				break;	
			}
		}
	}	

	for(i=0;i<3;i++){
    	for(j=0;j<3;j++){
    		if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j]){
    			gl=1;
    			break;
			}
		}
	}		
	if(fl || gl){
		return 1;
	} 
	else{
		return 0;
	}
}

int main(){
	int i1,i2,i3,i4,i,j;
	int a[4][4]={0},tmp[4][4]={0};
	srand(time(0));
	i1=rand()%4;
	i2=rand()%4;

	while(1){
		i3=rand()%4;
		i4=rand()%4;
		if(i3!=i1 && i4!=i2) break;
	}
	a[i1][i2]=2;
	a[i3][i4]=2;
	disp(a);
	
	char ch;
	while (1){
    	for(i=0;i<4;i++){

    		for(j=0;j<4;j++){

    			tmp[i][j]=a[i][j];
				cin >> ch;
    	
				system("clear");
				if(ch=='w'){
					upmove(a);
				} 
				if(ch=='s'){
					downmove(a);
				} 
				if(ch=='a'){
					leftmove(a);
				} 
				if(ch=='d'){
					rightmove(a);
				} 
				if(ch=='q'){
					cout << "Game quitted successfully!! ";
					break;	
				} 
				
				if(!check(tmp,a))
					addblock(a);
				disp(a);
					
				if(!checkover(a))
				{
					cout<<"\n\n\t\t\tGAME OVER!!\n\n\n";
					break;
				}	
			}
		}
	}
	return 0;
}
