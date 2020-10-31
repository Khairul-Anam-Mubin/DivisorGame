/*****
**
**   WAR OF DIVISORS
**
**   AUTHOR :
**   Khairul Anam Mubin
**   Dept. of CSE,Intake : 38
**   Bangladesh University of Business and Technology
**
*****/

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void single_player();
void Multiplayer();
void vsmode();
void easy();
void medium();
void hard();
bool move_choice();
bool move_choice_hard();
bool move_choice_mul();
void gen_grid(int n,int x);
void show_grid(int n);
bool toss();
bool toss_mul();
bool rmv_pl1(int n);
bool rmv_pl2(int n);
void rmv_easy_pc(int n);
void rmv_hard_pc(int n);
int win(int n,int dd);
void sieve();

int a[10][10],prime[101];
int pl_choice,pc_choice,pc=0,pl=0,pl1,pl2,turn=0;
int pc_rm;
string pl1_name="Your",pl2_name="Computer";

void description()
{
    cout << "\n\t\t\t\tWAR OF DIVISORS\n\n\n";

    cout << "\t\t" << "     There is a Square Matrix or a Square Grid.\n";
    cout << "\t\t" << "  You have to choose your own numbers/Divisors and\n";
    cout << "\t\t" << "   you can only remove that numbers from the grid\n";
    cout << "\t\t" << " which is the multiple of your choosen number/divisor.\n";
    cout << "\t\t" << "If there is no multiple of your Numbers then Opponent win\n";
    cout << "\t\t" << "                    or Vice-Versa";

    cout << "\n\n\t\tHAVE A NICE JOURNEY TO TEASE YOUR INTELLIGENCE... :D :D\n\n\n";

    cout << "Press Any Key To Continue....";
    getch();
}

int main()
{
    srand(time(0));
    sieve();

    char zz,press;

    main:
    system("cls");
    description();
    system("cls");

    cout << "\n\t\t\tWAR OF DIVISORS\n\n\n";
    cout << "\n\nPress 1 for Multiplayer Battle.";
    cout << "\nPress 2 for Singleplayer Battle.";
    cout << "\n\n\n\t\tPress any key to exit....";
    zz = getch();

    if(zz=='1'){
    	system("cls");
    	Multiplayer();
        cout << "\n\nPress 1 for play again or press any key to exit... ";
        press=getch();
        if(press=='1'){
            goto main;
        }
        else{
            return 0;
        }
    }
    else if(zz=='2'){
        pl1_name="Your";
        pl2_name="Computer";
    	system("cls");
    	single_player();

    	cout << "\n\nPress 1 for play again or press any key to exit... ";
    	press=getch();
    	if(press=='1'){
    		goto main;
    	}
    	else{
    		return 0;
    	}
    }
    else{
        return 0;
    }

    return 0;
}
void Multiplayer()
{
    cout << "\n\t\t\tWAR OF DIVISORS\n\n\n";
    cout << "Input player 1 name : ";
    getline(cin,pl1_name);
    cout << "Input player 2 name : ";
    getline(cin,pl2_name);
    system("cls");
    vsmode();
}
void single_player()
{
    char choose;

    start:
    cout << "\n\t\t\tWAR OF DIVISORS\n\n\n";
    cout << "\n\nPress 1 for EASY..\nPress 2 for MEDIUM..\nPress 3 for HARD..\n\n";
    choose=getch();

    if(choose=='1')
        easy();
    else if(choose=='2')
        medium();
    else if(choose=='3')
        hard();
    else{
        system("cls");
        cout << "Wrong Choice!!\n";
        goto start;
    }
}
void easy()
{
    while(move_choice()){}
    while(toss()){}

    gen_grid(5,30);

    if(turn==1){
        while(1){
        	if(win(5,0)){
        		break;
        	}
            show_grid(5);

            while(rmv_pl1(5)){}
            if(win(5,1)){
            	break;
            }
            rmv_easy_pc(5);

        	system("cls");
        	cout << "\n\nYour pc remove " << pc_rm << " from the grid.\n\n";
        }
    }
    else{
        while(1){
            //show_grid(4);
            rmv_easy_pc(5);

            if(win(5,0)){
        		break;
        	}
            //system("cls");
            cout << "\n\nYour pc remove " << pc_rm << " from the grid.\n\n";
            show_grid(5);

            while(rmv_pl1(5)){}
            if(win(5,1)){
            	break;
           	}
            system("cls");
        }
    }
}
void medium()
{
    while(move_choice_hard()){}
    while(toss()){}

    gen_grid(6,50);

    if(turn==1){
        while(1){
        	if(win(6,0)){
        		break;
        	}
            show_grid(6);

            while(rmv_pl1(6)){}
            if(win(6,1)){
            	break;
            }
            rmv_easy_pc(6);

        	system("cls");
        	cout << "\n\nYour pc remove " << pc_rm << " from the grid.\n\n";
        }
    }
    else{
        while(1){
            //show_grid(4);
            rmv_easy_pc(6);

            if(win(6,0)){
        		break;
        	}
            //system("cls");
            cout << "\n\nYour pc remove " << pc_rm << " from the grid.\n\n";
            show_grid(6);

            while(rmv_pl1(6)){}
            if(win(6,1)){
            	break;
           	}
            system("cls");
        }
    }
}
void hard()
{
    while(move_choice_hard()){}
    while(toss()){}
    
    gen_grid(7,80);

    if(turn==1){
        while(1){
        	if(win(7,0)){
        		break;
        	}
            show_grid(7);

            while(rmv_pl1(7)){}
            if(win(7,1)){
            	break;
            }
            rmv_hard_pc(7);

        	system("cls");
        	cout << "\n\nYour pc remove " << pc_rm << " from the grid.\n\n";
        }
    }
    else{
        while(1){
            //show_grid(4);
            rmv_hard_pc(7);

            if(win(7,0)){
        		break;
        	}
            //system("cls");
            cout << "\n\nYour pc remove " << pc_rm << " from the grid.\n\n";
            show_grid(7);

            while(rmv_pl1(7)){}
            if(win(7,1)){
            	break;
           	}
            system("cls");
        }
    }
}
void vsmode()
{
    while(move_choice_mul()){};
    while(toss_mul()){};

    gen_grid(5,30);

    if(turn==1){
        while(true){
            if(win(5,0)){
                break;
            }
            show_grid(5);

            while(rmv_pl1(5)){}
            if(win(5,1)){
                break;
            }
            system("cls");
            show_grid(5);

            while(rmv_pl2(5)){};

            system("cls");
            //cout << "\n\nYour pc remove " << pc_rm << " from the grid.\n\n";
        }
    }
    else{
        while(1){
            show_grid(5);
            while(rmv_pl2(5)){};

            system("cls");
            if(win(5,0)){
                break;
            }
            //system("cls");
            //cout << "\n\nYour pc remove " << pc_rm << " from the grid.\n\n";
            show_grid(5);

            while(rmv_pl1(5)){}
            if(win(5,1)){
                break;
            }
            system("cls");
        }
    }
}

bool move_choice()
{
    cout << "\nEnter any digit from 3 to 9 : ";
    cin >> pl_choice;

    if(pl_choice < 3 || pl_choice >9 ){
        cout << "Wrong choice!Choose again.\n";
        return true;
    }
    cout << "\nYou choose : " << pl_choice << "\n\n";
    pc_choice=1;

    for(int i=0;(pl_choice==pc_choice) || (pc_choice < 3 || pc_choice > 8) ;i++){
        pc_choice=rand()%8+2;
    }
    cout << "Your Computer choose : " << pc_choice << "\n\n";
    return false;
}
bool move_choice_hard()
{
    cout << "\nEnter any digit from 3 to 9 : ";
    cin >> pl_choice;
    if(pl_choice < 3 || pl_choice >9 ){
        cout << "Wrong choice!Choose again.\n";
        return true;
    }
    cout << "\nYou choose : " << pl_choice << "\n\n";
    pc_choice=1;
    for(int i=0;pc_choice < 3 || pc_choice > 6 ;i++){
        pc_choice=rand()%8+2;
    }
    cout << "Your Computer choose : " << pc_choice << "\n\n";
    return false;
}
bool move_choice_mul()
{
    cout << "\n''" << pl1_name << "'' ";
    cout << "have to choose any digit from 3 to 9 : ";
    cin >> pl_choice;

    if(pl_choice < 3 || pl_choice >9 ){
        cout << "Wrong choice!Choose again.\n";
        return true;
    }
    cout << "\n''" << pl1_name;
    cout << "'' choose : " << pl_choice << "\n\n";

    cout << "\n''" << pl2_name << "'' ";
    cout << "have to choose any digit from 3 to 9 : ";
    cin >> pc_choice;

    if(pc_choice < 3 || pc_choice >9 ){
        cout << "Wrong choice!Choose again.\n";
        return true;
    }
    cout << "\n''" << pl2_name;
    cout << "'' choose : " << pc_choice << "\n\n";
    return false;
}


void gen_grid(int n,int x)
{
    int k,gg=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;){
            k=rand()%x+1;
            if(gg<=n*2){
            	if(k%pc_choice==0 || k%pl_choice==0){
            		a[i][j]=k;
                	j++;
                	gg++;
            	}
            }
            else{
            	if(prime[k]==0){
            		a[i][j]=k;
            		j++;
            	}
            }
        }
    }
}
void show_grid(int n)
{
    cout << "\n";
    for(int i=0;i<n;i++){
            cout << "\t";
        for(int j=0;j<n;j++){
            if(a[i][j]==0){
                cout << " \t";
            }
            else
            cout << a[i][j] << "\t";
        }
        cout << "\n";
        for(int x=0;x<(n*10);x++){
            cout << "_";
        }
        cout << "\n\n";
    }
    cout << pl1_name;
    cout << "'s' Number : " << pl_choice << "\t\t" << pl2_name << "'s Number : " << pc_choice << "\n";
}
bool toss()
{
    int rnd;
    char ch;
    cout << "You are going through a Toss!! Best of Luck.\n\n";
    cout << "Choose Head for 'H' or Tail for 'T'\n\n";
    ch = getch();

    if(toupper(ch)=='H' || toupper(ch)=='T'){
        rnd=1;
    }
    else{
        cout << "\n\nInvalid choice\n\nSelect Again!!!\n";
        return true;
    }
    if(rnd==rand()%2){
    	system("cls");
        cout << "\n\nCongrats!! You won the toss!\nMove Starts from you. :)\n\n";
        turn=1;
    }
    else{
        system("cls");
        cout << "\n\n:'( Sorry!! Computer won the first move.\n\n";
        turn=0;
    }
    return false;
}
bool toss_mul()
{
    int rnd;
    char ch;
    cout << "You are going through a Toss!! Best of Luck.\n\n";
    cout << "Choose Head for 'H' or Tail for 'T'\n\n";
    ch = getch();

    if(toupper(ch)=='H' || toupper(ch)=='T'){
        rnd=1;
    }
    else{
        cout << "\n\nInvalid choice\n\nSelect Again!!!\n";
        return true;
    }
    if(rnd==rand()%2){
        system("cls");
        cout << "\n\n" << pl1_name;
        cout << " won the toss!\nMove Starts from "<< pl1_name << "\n\n";
        turn=1;
    }
    else{
        system("cls");
        cout << "\n\n" << pl2_name;
        cout << " won the toss!\nMove Starts from "<< pl2_name << "\n\n";
        turn=0;
    }
    return false;
}

bool rmv_pl1(int n)
{
    int x,i,j,flag=0;

    cout << "\n\n" << pl1_name << "'s Turn..";
    cout << "\nEnter the value from the gird you want to remove : ";
    cin >> x;

    if(x%pl_choice!=0){
        cout << "\nWrong Choice!\n\nEnter the value from the grid which is the multiple of your divisor to remove.\n";
        return true;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j]==x){
                a[i][j]=0;
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    return  false;
}
bool rmv_pl2(int n)
{
    int x,i,j,flag=0;

    cout << "\n\n" << pl2_name << "'s Turn..";
    cout << "\nEnter the value from the gird you want to remove : ";
    cin >> x;

    if(x%pc_choice!=0){
        cout << "\nWrong Choice!\n\nEnter the value from the grid which is the multiple of your divisor to remove.\n";
        return true;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j]==x){
                a[i][j]=0;
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    return  false;
}
void rmv_easy_pc(int n)
{
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]%pc_choice==0 && a[i][j]){
                pc_rm=a[i][j];
                a[i][j]=0;
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
}
void rmv_hard_pc(int n)
{
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] && a[i][j]%pc_choice==0 && a[i][j]%pl_choice==0){
                pc_rm=a[i][j];
                a[i][j]=0;
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag==0){
    	rmv_easy_pc(n);
    }
}


int win(int n,int dd)
{
	int i,j,cntpl,cntpc;

	for(i=0,cntpl=0,cntpc=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j] && a[i][j]%pl_choice==0){
				cntpl++;
			}
			if(a[i][j] && a[i][j]%pc_choice==0){
				cntpc++;
			}
		}
	}
	//cout << cntpl << " " << cntpc << endl;
	if((cntpl==0 && cntpc) || (dd==1 && cntpl==0 && cntpc==0)){
		system("cls");
		show_grid(n);
		cout << "\n\n\t\t" << pl2_name <<" win the game!!\n\n";
		return 1;
	}
	else if((cntpc==0 && cntpl) || (dd==0 && cntpl==0 && cntpc==0)){
		system("cls");
		show_grid(n);
		cout << "\n\n\t\t" << pl1_name <<" win the game!!\n\n";
		return 2;
	}
	else {
		return 0;
	}
}

void sieve()
{
    int mx=100,sq;
    sq=sqrt(mx);

    for(int i=1;i<=100;i++){
        prime[i]=1;
    }
    for(int i=2;i<=sq;i++){
        if(prime[i]==1){
            for(int j=i*i;j<=mx;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=1;i<=9;i++){
        prime[i]=0;
    }
}
