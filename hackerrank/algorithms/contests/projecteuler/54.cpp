#include <iostream>
#include<stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
int result=0;
bool checkcolor(int dizi[2][5]) ;
bool checkcolor(int dizi[2][5]) {
 for(int i=0;i<4;i++) {
  if(dizi[1][i]!=dizi[1][i+1]) {
   return 0;

  }
 }
   return 1;
}
int checknumbers(int dizi[2][5]) ;
int isstraight(int dizi[2][5]);
int isstraight(int dizi[2][5]) {
 int counter=0,c;
 
 for(int i=0;i<3;i++) {
  if(dizi[0][i]==dizi[0][i+1]) {
   counter++;
   c=dizi[0][i];
  }
 }
 if(counter==3) {
  return 400+c;                     //means Four of a Kind: Four cards of the same value.
 }


 if((dizi[0][4]-dizi[0][3]) == 1 && (dizi[0][3]-dizi[0][2]) == 1 &&  (dizi[0][2]-dizi[0][1]) == 1 &&  (dizi[0][1]-dizi[0][0]) == 1 && dizi[0][4] == 14) {
  
  return 3;           //2 means that it can be royal flush,it is straight and finish as A

 }


 if(dizi[0][4]-dizi[0][3] == 1 && dizi[0][3]-dizi[0][2] == 1 &&  dizi[0][2]-dizi[0][1] == 1 &&  dizi[0][1]-dizi[0][0] == 1) {
  
  return 150+dizi[0][4];           //1 means straight

 }



 if(dizi[0][0]==dizi[0][1] && dizi[0][2]==dizi[0][3] && dizi[0][3]==dizi[0][4]) {
  
  return 300+dizi[0][4];           //this means there is full house

 }




 return 0;       // 0 means no straight
 
}

int checknumbers(int dizi[2][5]) {
int c;
 for(int i=0;i<4;i++) {
  for(int k=0;k<4;k++) {
   if(dizi[0][k]>dizi[0][k+1]) {
    c = dizi[0][k] ;
    dizi[0][k] =dizi[0][k+1] ;
    dizi[0][k+1] = c;
   }
 }
 }
 

 if(isstraight(dizi)==3 && checkcolor(dizi)==1) {                  //royal flush
  return 500;
 }
 if(isstraight(dizi)==1 && checkcolor(dizi)==1) {                    //straight flush
  return 450+dizi[0][4];
 }


 if(isstraight(dizi)<415 && isstraight(dizi) > 400) {                  // Four cards of the same value.
  return isstraight(dizi);
 }
 if(isstraight(dizi)<315 && isstraight(dizi) > 300) {                  // house
  return isstraight(dizi);
 }

 if(checkcolor(dizi) == 1) {            //flush   

  return 200;        

 }
 if(isstraight(dizi)<165 && isstraight(dizi)>150) {                    //straight
  return isstraight(dizi);
 }

 for(int i=0;i<3;i++) {                                           //three of a kind
  if(dizi[0][i] == dizi[0][i+1] && dizi[0][i+1] == dizi[0][i+2]) {

   return 100+dizi[0][i];

  }
 }
 int a=0,b=0;
  for(int i=0;i<4;i++) {                   //two pair
   for(int k=i+1;k<5;k++) {
    if(dizi[0][i] == dizi[0][k]) {
     if(a==0) {
      a=dizi[0][i];
     }else {
      b=dizi[0][i];
     }

    }


   }
  }
  if(a!=0 && b!=0) {
   return 50+b;
  }

  for(int i=0;i<4;i++) {                   //one pair
   for(int k=i+1;k<5;k++) {
    if(dizi[0][i] == dizi[0][k]) {
     return 30+dizi[0][i];
    }
   }
  }




  return dizi[0][4];         //high card


}

void make(string line) {
 int dizi[2][5];

 for(int i=0,n=0;i<14;i+=3,n++) {
  if(line[i]=='T')
  dizi[0][n]=10;
  else if(line[i]=='J')
  dizi[0][n]=11;
   else if(line[i]=='Q')
  dizi[0][n]=12;
   else if(line[i]=='K')
  dizi[0][n]=13;
    else if(line[i]=='A')
  dizi[0][n]=14;
    else {
     dizi[0][n]=line[i]-48;

    }
  if(line[i+1]=='C')
  dizi[1][n]=0;
   if(line[i+1]=='S')
  dizi[1][n]=1;
    if(line[i+1]=='H')
  dizi[1][n]=2;
     if(line[i+1]=='D')
  dizi[1][n]=3;
  }


int handone=checknumbers(dizi);




 for(int i=15,n=0;i<29;i+=3,n++) {
   if(line[i]=='T')
  dizi[0][n]=10;
  else if(line[i]=='J')
  dizi[0][n]=11;
   else if(line[i]=='Q')
  dizi[0][n]=12;
   else if(line[i]=='K')
  dizi[0][n]=13;
    else if(line[i]=='A')
  dizi[0][n]=14;
    else {
     dizi[0][n]=line[i]-48;

    }
  if(line[i+1]=='C')
  dizi[1][n]=0;
   if(line[i+1]=='S')
  dizi[1][n]=1;
    if(line[i+1]=='H')
  dizi[1][n]=2;
     if(line[i+1]=='D')
  dizi[1][n]=3;
  
 }
 
   if(handone>checknumbers(dizi)) {
   cout<<"Player 1"<<endl;
}
else cout<<"Player 2"<<endl;

 
}
int main() {
string line;
int efe;
cin>>efe;
getchar();
    while ( efe-- )
    {
      getline (cin,line);
     make(line);
    }
return 0;
}
