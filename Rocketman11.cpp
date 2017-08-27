#include<iostream>
#include<conio.h>
#include<windows.h>
#include"capsule.h"
#include<time.h>
using namespace std;
struct STONE
{
    int face;
    int p;
    int q;
};
struct ALIEN
{
    int behav;
    int type;
    int r;
    int s;
};
void level(int v=1)
{
    clear();
    switch(v)
    {
        case 1:setcolor(6);
               cout<<"LEVEL 1: DUSTY DAY";
               setcolor();
               cout<<"\n\n\tEvade the asteroids, move forward\n";
               cout<<"\tUse the slipspace at the bottom in dire circumstances\n";
               setcolor(6);
               cout<<"\n\nPress enter to start";
               cin.get();
               break;
        case 2:setcolor(6);
               cout<<"LEVEL 2: SPACE DANCE";
               setcolor();
               cout<<"\n\n\tEvade the asteroid trios\n";
               cout<<"\tWatch out for asteroid buildups\n";
               cout<<"\tUse the slipspace at the bottom in dire circumstances\n";
               setcolor(6);
               cout<<"\n\nPress enter to start";
               cin.get();
               break;
        case 3:setcolor(6);
               cout<<"LEVEL 3: CLOSING IN";
               setcolor();
               cout<<"\n\n\tEvade the asteroid hexos\n";
               cout<<"\tWatch out for asteroid buildups\n";
               cout<<"\tUse the slipspace at the bottom in dire circumstances\n";
               setcolor(6);
               cout<<"\n\nPress enter to start";
               cin.get();
               break;
        case 4:setcolor(6);
               cout<<"LEVEL 4: FIGHTBACK";
               setcolor();
               cout<<"\n\n\tEvade the asteroids as well as alien-ships\n";
               cout<<"\tWatch out for asteroid buildups\n";
               cout<<"\tWatch out for alien-ships' movements\n";
               cout<<"\tUse the slipspace cautiously\n";
               setcolor(6);
               cout<<"\n\nPress enter to start";
               cin.get();
               break;
        case 5:setcolor(6);
               cout<<"LEVEL 5: ALIEN WORLDS";
               setcolor();
               cout<<"\n\n\tRocketman has been upgraded\n";
               cout<<"\tRam into the asteroids to destroy them\n";
               cout<<"\tEvade all the alien planets and their buildups\n";
               cout<<"\tWatch out for alien formations and movements\n";
               cout<<"\tNow, only aliens can use the slipspace\n";
               setcolor(6);
               cout<<"\n\nPress enter to start";
               cin.get();
               break;
        default:setcolor(2);
                cout<<"\n\n\a\a YOU WIN!";
                setcolor(6);
                cout<<"\n\n\tTHANK YOU FOR COMPLETING ROCKETMAN!\n\n\t";
                setcolor();
               }
}
void showrocket()
{
    setcolor(6);
    cout<<"=";
    setcolor(4);
    cout<<char(16);
}
void showrocket2()
{
    setcolor(1);
    cout<<"=";
    setcolor();
    cout<<char(16);
}
void showalien(int y=5)
{
    setcolor(y);
    cout<<char(17);
}
void showstone(int w=3)
{
    setcolor(w);
    cout<<char(219);
}
void showland()
{
    setcolor(3);
    int i;
    for(i=0;i!=80;i++)
    cout<<char(127);
    setcolor();
    cout<<"\n\tUP: "<<char(30)<<" DOWN: "<<char(31)<<" STAY: "<<char(16);
}
void showcatas()
{
    setcolor(4);
    cout<<char(219);
}
int main()
{
    setop();

    srand(time(NULL));

    cout<<"CAPSULE CORP. 2013 presents...";
    Sleep(1000);
    setcolor(4);
    cout<<"\n\n\t\t\a\aROCKETMAN\n\n";
    setcolor();
    cout<<"A journey through cosmos with aliens in hot-pursuit!\n\n";
    visit(25,7);
    setcolor(3);
    cout<<"Developed by: Sarthi Chugh";
    visit(0,10);
    setcolor();
    system("pause");
    cout<<"\a";
    level(1);

    STONE X[40];
    int flag=0;
    int count=0;
    int j;
    int y=10;
    int m,n;
    int score=0;
    X[39].p=0;
    do
    {
        clear();
        for(j=0;j!=count;j++)
        {
            X[j].p--;
            if(X[j].p<=0){X[j].p=0;X[j].face=0;}
            visit(X[j].p,X[j].q);
            showstone(X[j].face);
            if((X[j].p==30)&&(X[j].q==y)){cout<<"\b";flag=3;showcatas();showcatas();}
            if((X[j].p==31)&&(X[j].q==y)){cout<<"\b";flag=3;showcatas();showcatas();}
        }
        if(flag==3){visit(2,23);setcolor(4);cout<<"\a\aYOU LOSE! ";Sleep(1000);flag=5;break;}
        if(flag==0)
        {
            m=(rand()%35)+32;
            n=rand()%20;
            X[count].p=m;
            X[count].q=n;
            X[count].face=3;
            visit(m,n);
            showstone(X[count].face);
            count++;
            flag=3;
            if(count==40){flag=0;}
            score+=10;
        }
        flag--;
        visit(0,20);
        showland();
        visit(50,21);
        setcolor(6);
        cout<<"SCORE: "<<score;
        visit(30,y);
        showrocket();
        if(X[39].p==29){visit(2,23);setcolor(2);cout<<"\aLEVEL CLEAR! LOADING NEXT LEVEL... ";Sleep(1000);break;}
        getch();
        getch();
        if(GetAsyncKeyState(VK_UP)){y--;}
        if(GetAsyncKeyState(VK_DOWN)){y++;}
        if(y==-1){y=0;}
        if(y==20){y=0;}
    }while(!0);

    setcolor();
    int loser=flag;
    if(loser!=5){level(2);}

    STONE Y[120];
    flag=count=0;
    Y[119].p=0;
    do
    {
        if(loser==5){break;}
        clear();
        for(j=0;j!=count;j++)
        {
            Y[j].p--;
            if(Y[j].p<=0){Y[j].p=0;Y[j].face=0;}
            visit(Y[j].p,Y[j].q);
            showstone(Y[j].face);
            if((Y[j].p==30)&&(Y[j].q==y)){cout<<"\b";flag=4;showcatas();showcatas();}
            if((Y[j].p==31)&&(Y[j].q==y)){cout<<"\b";flag=4;showcatas();showcatas();}
        }
        if(flag==4){visit(2,23);setcolor(4);cout<<"\a\aYOU LOSE! ";Sleep(1000);flag=5;break;}
        if(flag==0)
        {
            m=(rand()%35)+33;
            n=(rand()%16)+2;
            Y[count].p=m;
            Y[count].q=n;
            Y[count].face=3;
            visit(m,n);
            showstone(Y[count].face);
            count++;
            Y[count].p=m;
            Y[count].q=n-2;
            Y[count].face=3;
            visit(m,n-2);
            showstone(Y[count].face);
            count++;
            Y[count].p=m;
            Y[count].q=n+2;
            Y[count].face=3;
            visit(m,n+2);
            showstone(Y[count].face);
            count++;
            flag=4;
            if(count==120){flag=0;}
            score+=30;
        }
        flag--;
        visit(0,20);
        showland();
        visit(50,21);
        setcolor(6);
        cout<<"SCORE: "<<score;
        visit(30,y);
        showrocket();
        if(Y[119].p==29){visit(2,23);setcolor(2);cout<<"\aLEVEL CLEAR! LOADING NEXT LEVEL... ";Sleep(1000);break;}
        getch();
        getch();
        if(GetAsyncKeyState(VK_UP)){y--;}
        if(GetAsyncKeyState(VK_DOWN)){y++;}
        if(y==-1){y=0;}
        if(y==20){y=0;}
    }while(!0);

    setcolor();
    loser=loser>flag?loser:flag;
    if(loser!=5){level(3);}

    STONE Z[240];
    flag=count=0;
    Z[239].p=0;
    do
    {
        if(loser==5){break;}
        clear();
        for(j=0;j!=count;j++)
        {
            Z[j].p--;
            if(Z[j].p<=0){Z[j].p=0;Z[j].face=0;}
            visit(Z[j].p,Z[j].q);
            showstone(Z[j].face);
            if((Z[j].p==30)&&(Z[j].q==y)){cout<<"\b";flag=5;showcatas();showcatas();}
            if((Z[j].p==31)&&(Z[j].q==y)){cout<<"\b";flag=5;showcatas();showcatas();}
        }
        if(flag==5){visit(2,23);setcolor(4);cout<<"\a\aYOU LOSE! ";Sleep(1000);flag=5;break;}
        if(flag==0)
        {
            m=(rand()%35)+35;
            n=(rand()%13)+3;
            Z[count].p=m;
            Z[count].q=n;
            Z[count].face=3;
            visit(m,n);
            showstone(Z[count].face);
            count++;
            Z[count].p=m;
            Z[count].q=n-2;
            Z[count].face=3;
            visit(m,n-2);
            showstone(Z[count].face);
            count++;
            Z[count].p=m;
            Z[count].q=n-3;
            Z[count].face=3;
            visit(m,n-3);
            showstone(Z[count].face);
            count++;
            Z[count].p=m;
            Z[count].q=n+1;
            Z[count].face=3;
            visit(m,n+1);
            showstone(Z[count].face);
            count++;
            Z[count].p=m;
            Z[count].q=n+3;
            Z[count].face=3;
            visit(m,n+3);
            showstone(Z[count].face);
            count++;
            Z[count].p=m;
            Z[count].q=n+4;
            Z[count].face=3;
            visit(m,n+4);
            showstone(Z[count].face);
            count++;
            flag=5;
            if(count==240){flag=0;}
            score+=60;
        }
        flag--;
        visit(0,20);
        showland();
        visit(50,21);
        setcolor(6);
        cout<<"SCORE: "<<score;
        visit(30,y);
        showrocket();
        if(Z[239].p==29){visit(2,23);setcolor(2);cout<<"\aLEVEL CLEAR! LOADING NEXT LEVEL... ";Sleep(1000);break;}
        getch();
        getch();
        if(GetAsyncKeyState(VK_UP)){y--;}
        if(GetAsyncKeyState(VK_DOWN)){y++;}
        if(y==-1){y=0;}
        if(y==20){y=0;}
    }while(!0);

    setcolor();
    loser=loser>flag?loser:flag;
    if(loser!=5){level(4);}

    STONE B[80];
    ALIEN C[40];
    flag=count=0;
    int count2=0;
    B[79].p=0;
    int t,d,e;
    do
    {
        if(loser==5){break;}
        clear();
        for(j=0;j!=count;j++)
        {
            B[j].p--;
            if(B[j].p<=0){B[j].p=0;B[j].face=0;}
            visit(B[j].p,B[j].q);
            showstone(B[j].face);
            if((B[j].p==30)&&(B[j].q==y)){cout<<"\b";flag=4;showcatas();showcatas();}
            if((B[j].p==31)&&(B[j].q==y)){cout<<"\b";flag=4;showcatas();showcatas();}
        }
        for(j=0;j!=count2;j++)
        {
         C[j].r--;
         if(C[j].behav==1){C[j].s++;}
         if(C[j].behav==2){C[j].s--;}
         if(C[j].s==20){C[j].s=0;}
         if(C[j].s==-1){C[j].s=1;C[j].behav=1;}
         for(t=0;t!=count;t++){if((C[j].r==B[t].p)&&(C[j].s==B[t].q)){C[j].r=0;}}
         if(C[j].r<=0){C[j].r=0;C[j].type=0;}
         visit(C[j].r,C[j].s);
         showalien(C[j].type);
         if((C[j].r==30)&&(C[j].s==y)){cout<<"\b";flag=4;showcatas();showcatas();}
         if((C[j].r==31)&&(C[j].s==y)){cout<<"\b";flag=4;showcatas();showcatas();}
        }
        if(flag==4){visit(2,23);setcolor(4);cout<<"\a\aYOU LOSE! ";Sleep(1000);flag=5;break;}
        if(flag==0)
        {
            m=(rand()%35)+33;
            n=rand()%18;
            B[count].p=m;
            B[count].q=n;
            B[count].face=3;
            visit(m,n);
            showstone(B[count].face);
            count++;
            B[count].p=m;
            B[count].q=n+2;
            B[count].face=3;
            visit(m,n+2);
            showstone(B[count].face);
            count++;
            flag=4;
            if(count==80){flag=1;}
            score+=20;
        }
        if(flag==1)
        {
            d=(rand()%35)+34;
            e=rand()%20;
            C[count2].r=d;
            C[count2].s=e;
            C[count2].type=5;
            C[count2].behav=rand()%3;
            visit(d,e);
            showalien(C[count2].type);
            count2++;
            flag=1;
            if(count2==40){flag=0;}
            score+=80;
        }
        flag--;
        visit(0,20);
        showland();
        visit(50,21);
        setcolor(6);
        cout<<"SCORE: "<<score;
        visit(30,y);
        showrocket();
        if(B[79].p==29){visit(2,23);setcolor(2);cout<<"\aLEVEL CLEAR! LOADING NEXT LEVEL... ";Sleep(1000);break;}
        getch();
        getch();
        if(GetAsyncKeyState(VK_UP)){y--;}
        if(GetAsyncKeyState(VK_DOWN)){y++;}
        if(y==-1){y=0;}
        if(y==20){y=0;}
    }while(!0);

    setcolor();
    loser=loser>flag?loser:flag;
    if(loser!=5){level(5);}

    STONE F[40];
    ALIEN G[120];
    STONE H[200];
    int count3=0;
    flag=count=count2=0;
    H[199].p=0;
    do
    {
        if(loser==5){break;}
        clear();
        for(j=0;j!=count;j++)
        {
            F[j].p--;
            if((F[j].p==30)&&(F[j].q==y)){F[j].p=0;}
            if((F[j].p==31)&&(F[j].q==y)){F[j].p=0;}
            if(F[j].p<=0){F[j].p=0;F[j].face=0;}
            visit(F[j].p,F[j].q);
            showstone(F[j].face);
        }
        for(j=0;j!=count3;j++)
        {
            H[j].p--;
            if(H[j].p<=0){H[j].p=0;H[j].face=0;}
            visit(H[j].p,H[j].q);
            showstone(H[j].face);
            if((H[j].p==30)&&(H[j].q==y)){cout<<"\b";flag=5;showcatas();showcatas();}
            if((H[j].p==31)&&(H[j].q==y)){cout<<"\b";flag=5;showcatas();showcatas();}
        }
        for(j=0;j!=count2;j++)
        {
         G[j].r--;
         if(G[j].behav==1){G[j].s++;}
         if(G[j].behav==2){G[j].s--;}
         if(G[j].s==20){G[j].s=0;}
         if(G[j].s==-1){G[j].s=1;G[j].behav=1;}
         for(t=0;t!=count;t++){if((G[j].r==F[t].p)&&(G[j].s==F[t].q)){G[j].r=0;}}
         for(t=0;t!=count3;t++){if((G[j].r==H[t].p)&&(G[j].s==H[t].q)){G[j].r=0;}}
         if(G[j].r<=0){G[j].r=0;G[j].type=0;}
         visit(G[j].r,G[j].s);
         showalien(G[j].type);
         if((G[j].r==30)&&(G[j].s==y)){cout<<"\b";flag=5;showcatas();showcatas();}
         if((G[j].r==31)&&(G[j].s==y)){cout<<"\b";flag=5;showcatas();showcatas();}
        }
        if(flag==5){visit(2,23);setcolor(4);cout<<"\a\aYOU LOSE! ";Sleep(1000);flag=5;break;}
        if(flag==0)
        {
            m=(rand()%35)+33;
            n=rand()%20;
            F[count].p=m;
            F[count].q=n;
            F[count].face=3;
            visit(m,n);
            showstone(F[count].face);
            count++;
            flag=5;
            if(count==40){flag=3;}
            score+=10;
        }
        if(flag==3)
        {
            d=(rand()%35)+35;
            e=(rand()%16)+2;
            G[count2].r=d;
            G[count2].s=e;
            G[count2].type=5;
            G[count2].behav=rand()%3;
            visit(d,e);
            showalien(G[count2].type);
            count2++;
            G[count2].r=d+1;
            G[count2].s=e-2;
            G[count2].type=5;
            G[count2].behav=G[count2-1].behav;
            visit(d+1,e-2);
            showalien(G[count2].type);
            count2++;
            G[count2].r=d+1;
            G[count2].s=e+2;
            G[count2].type=5;
            G[count2].behav=G[count2-1].behav;
            visit(d+1,e+2);
            showalien(G[count2].type);
            count2++;
            flag=2;
            if(count2==120){flag=1;}
            score+=240;
        }
        if(flag==1)
        {
            m=(rand()%33)+37;
            n=(rand()%18)+1;
            H[count3].p=m;
            H[count3].q=n;
            H[count3].face=2;
            visit(m,n);
            showstone(H[count3].face);
            count3++;
            H[count3].p=m+1;
            H[count3].q=n-1;
            H[count3].face=2;
            visit(m+1,n-1);
            showstone(H[count3].face);
            count3++;
            H[count3].p=m+1;
            H[count3].q=n+1;
            H[count3].face=2;
            visit(m+1,n+1);
            showstone(H[count3].face);
            count3++;
            H[count3].p=m-1;
            H[count3].q=n-1;
            H[count3].face=2;
            visit(m-1,n-1);
            showstone(H[count3].face);
            count3++;
            H[count3].p=m-1;
            H[count3].q=n+1;
            H[count3].face=2;
            visit(m-1,n+1);
            showstone(H[count3].face);
            count3++;
            flag=1;
            if(count3==200){flag=0;}
            score+=50;
        }
        flag--;
        visit(0,20);
        showland();
        visit(50,21);
        setcolor(6);
        cout<<"SCORE: "<<score;
        visit(30,y);
        showrocket2();
        if(H[199].p==29){visit(2,23);setcolor(2);cout<<"\aLEVEL CLEAR! LOADING... ";Sleep(1000);break;}
        getch();
        getch();
        if(GetAsyncKeyState(VK_UP)){y--;}
        if(GetAsyncKeyState(VK_DOWN)){y++;}
        if(y==-1){y=0;}
        if(y==20){y=19;}
    }while(!0);

    setcolor();
    loser=loser>flag?loser:flag;
    if(loser!=5){level(0);}
    if(loser==5){visit(50,21);setcolor(6);cout<<"SCORE: "<<score;visit(14,23);setcolor();}

    system("pause");
    return 0;
}
