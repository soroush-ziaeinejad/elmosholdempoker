#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;
class scores{  
      public:
      bool royalFlush , straightFlush , fours ,full, flushz , straight , threes , two , one;
      };
class Cards{
      public:
      string suit ;
      string number;
      bool check_is;

      }; Cards cards[52]; 
class Players
{
      public:
             bool if_pay;
             int H_counter;
             int S_counter;
             int D_counter;
             int C_counter;
             int counternum[13];
             void initalizern(){
             for(int cou=0;cou<13;cou++){
             counternum[cou]=0;}}
             string FinalScore;
             scores score;
             string name;
             int money;
             int scoress;
             Cards my_card[2];
             Cards Fcards[7];
             bool is_in;
             int get_money;
};Players people[8];




class Board
{
      public:

      Board(){}
      Cards on_ground[5];
      bool firstt,secondt,thirdt;
      int pot;
       string numbers[13]; // 2 to "Ace" in each suits
       string  suits[4];  // 4 suits are "Clubs", "Diamonds", "Spades", "Hearts"
      void First_screen(){
      cout << "                            welcome to my POKER game!        "<<endl;
      cout << "                          creator:Soroush Ziaeinejad       "<<endl;
      cout << "         computer college of iran university of science and technology"<<endl;

          } // end of first screen
      void Distributor();
      void final_printer(){
           for (int qw=0;qw<8;qw++){
               cout << people[qw].name << " is " << people[qw].FinalScore<< endl;}}
};Board poker; 


class Check_Hands
{
      public:
              Check_Hands(){
                            }
                             bool royalFlush , straightFlush , fours ,full, flushz , straight , threes , two , one;
             void initalizer(){
            
             royalFlush = straightFlush= fours = full = flushz = straight = threes = two = one= false;} 
             Board number_counter;
             
             // royal flush checker
             void Royal_Flush(){
             for (int TT=0;TT<8;TT++){
             for (int RR=0;RR<7;RR++){
                    
             }  }}
             
             
             // Fours checker
             void Four(){
                  for (int fff=0;fff<8;fff++){
                      for (int ffff=0;ffff<13;ffff++){
                          if (people[fff].counternum[ffff]==4){
                             people[fff].score.fours=true;
                             people[fff].scoress=8;}}}}
                  
             // flush checker
             void Flush(){
             for (int TT=0;TT<8;TT++){
             for (int RR=0;RR<7;RR++){
             if (people[RR].C_counter>=5 || people[RR].H_counter>=5 || people[RR].S_counter>=5 || people[RR].D_counter>=5)
             people[RR].score.flushz = true;
             people[RR].scoress=6;}}}
             
             
             // straight checker
             void Straight(){
                  for (int ss=0;ss<9;ss++){
                  for (int SS=0;SS<8;SS++){
                  if (people[SS].counternum[ss]>=1 && people[SS].counternum[ss+1]>=1 && people[SS].counternum[ss+2]>=1 && people[SS].counternum[ss+3]>=1 && people[SS].counternum[ss+4]>=1)
                  people[SS].score.straight=true;
                  people[SS].scoress=5;}}
                  }
             
             // straight flush checker
             void Straight_Flush(){
             for (int sr=0;sr<8;sr++){
             if (people[sr].score.flushz==true && people[sr].score.straight==true){
             straightFlush=true;
             people[sr].scoress=9;}}}
             
             // Full House cheker
             void Full_House(){
             for (int FF=0;FF<8;FF++){
                 for (int ff=0;ff<13;ff++){
                     if (people[FF].counternum[ff]==3){
                        for (int TYx=0;TYx<13;TYx++){
                            if (people[FF].counternum[TYx]==2){
                               people[FF].score.full=true;
                               people[FF].scoress=7;}}}}}}
             
             
             // Three of a kind checker    
             void Three(){
             for (int th=0;th<8;th++){
                 for(int TH=0;TH<13;TH++){
                         if (people[th].counternum[TH]==3){
                            for (int TY=0;TY<13;TY++){
                                if (people[th].counternum[TY]!=2){
                                   people[th].score.threes=true;
                                   people[th].scoress=4;}}}}}}
             // Two pairs checker          
             void Two_Pairs(){
             for (int tha=0;tha<8;tha++){
                 for(int THa=0;THa<13;THa++){
                         if (people[tha].counternum[THa]==2){
                            for (int TYa=0;TYa<13;TYa++){
                                if (people[tha].counternum[TYa]==2 && TYa!=THa){
                                   people[tha].score.two=true;
                                   people[tha].scoress=3;}}}}}}
                                   
            // pair checker
             void Pair(){
            for (int thaa=0;thaa<8;thaa++){
                 for(int THaa=0;THaa<13;THaa++){
                         if (people[thaa].counternum[THaa]==2){
                            for (int TYaa=0;TYaa<13;TYaa++){
                                if ( TYaa!=THaa && people[thaa].counternum[TYaa]!=2){
                                   people[thaa].score.one=true;
                                   
                                   people[thaa].scoress=2;}}}}}}
      // check the scores function
      void Checker(){
           Royal_Flush();
           Straight_Flush();
           Four();
           Full_House();
           Flush();
           Straight();
           Three();
           Two_Pairs();
           Pair();}
           
           int max;
           void check_winner (){
                for (int ch=0;ch<8;ch++){
                    if (people[ch].scoress>=max){
                       max=ch;}}
                       cout << people[max].name<< " is winnnnnnnnnnnnner"<<endl;
                       cout << "Let's see the table..."<<endl;
                       for (int ta=0;ta<8;ta++){
                           cout << people[ta].name<<"'s score is: "<< people[ta].FinalScore<<endl;}
                           system("pause");}
                       
                    
           
      };Check_Hands Check_Hands;  
      
      
class Play
{
      public:
      int counter;
      int get_action;
      int base_money;
      int raise;
      void play(){
           if (counter==1)
           poker.firstt=true;
            if (counter==2){
           poker.firstt=false;
           poker.secondt=true;}
            if (counter==3){
           poker.secondt=false;
           poker.thirdt=true;
           Check_Hands.check_winner();}
           
           cout <<endl<<endl;
           for(int p=0;p<8;p++){
                   if (people[p].money<=0){
                   cout << people[p].name << " you are Eliminated!!";
                   }
                   if (people[p].is_in==false)
                   p++;
                   if (people[p].money>0 && people[p].is_in==true){
                   if (poker.firstt==true){
                   cout << "These are on ground cards:  ";
                   for (int as=0;as<3;as++){
                   cout << poker.on_ground[as].suit<<poker.on_ground[as].number<<"    ";}
                   cout << endl;}
                   if (poker.secondt==true){
                   cout << "These are on ground cards:   ";
                   for (int as=0;as<4;as++){
                   cout << poker.on_ground[as].suit<<poker.on_ground[as].number<<"    ";}
                   cout << endl;}
                   if (poker.thirdt==true){
                   cout << "These are on ground cards:  ";
                   for (int as=0;as<5;as++){
                   cout << poker.on_ground[as].suit<<poker.on_ground[as].number<<"    ";}
                   cout << endl;}
                   
                   cout <<"pot= "<<poker.pot<<endl;
                   cout<< "Well! " << people[p].name<< "! Your Turn..."<< endl;
                   cout << "These are your cards:  ";
                   for (int wq=0;wq<2;wq++){
                   cout<<people[p].my_card[wq].suit<<people[p].my_card[wq].number<<"   ";}
                   cout << "And this is your money: "<<people[p].money<< "$"<<endl<<"also base money is: "<<base_money<<endl;
                   cout<< "And other player' money: "<<endl;
                   for (int qwe=0;qwe<8;qwe++){
                       if (qwe != p){
                   cout << people[qwe].name<< ":  "<< people[qwe].money<< "$"<<endl;}}
                   cout << "These are your actions, choose one of them: "<<endl<<"1= FOLD       2= CALL     3= RAISE     4= ALL IN "<<endl;
                   cin >> get_action;
                   switch (get_action){
                   case 1:
                        people[p].is_in=false;
                        system("cls");
                        if (people[p].get_money<people[p+1].get_money){
                        counter++;
                       play();}
                        break;
                   case 2:
                        if (people[p].if_pay==false){
                        people[p].money-=base_money;}
                        else{
                        people[p].money-=raise;}
                        poker.pot+=base_money;
                        system("cls");
                        people[p].get_money+=base_money;
                        people[p].if_pay=true;
                        for (int asd=0;asd<7;asd++){
                        if (people[asd].get_money==people[asd+1].get_money){
                        counter++;
                        play();}}
                        break;
                   case 3:
                        cout << "How much do you want to add? ";
                        cin >> raise;
                        if (raise<base_money && raise+base_money<people[p].money){
                        cout <<"please check that you have enough money or no! be careful! raise at least as great as base money. base money is "<<base_money<<" now."<<endl;
                        cout << "How much do you want to add? ";
                        cin >> raise;}
                        people[p].money-=raise+base_money;
                        poker.pot+=raise+base_money;
                        base_money+=raise;
                        people[p].get_money+=base_money;
                        system("cls");
                        break;
                   case 4:
                        poker.pot+=people[p].money;
                        people[p].get_money+=people[p].money;
                        base_money+=people[p].money;
                        people[p].money=0;
                        system("cls");
                        for(int qa=0;qa<8;qa++)
                        if (people[qa].is_in==true){
                        if (people[0].get_money==people[1].get_money && people[1].get_money==people[2].get_money && people[2].get_money==people[3].get_money && people[3].get_money==people[4].get_money && people[4].get_money==people[5].get_money &&people[5].get_money==people[6].get_money && people[6].get_money==people[7].get_money){
                        if (poker.firstt!=true){
                        poker.firstt=true;}}
                        else if (poker.firstt==true){
                             poker.firstt=false;
                             poker.secondt=true;}}
                        
                        break;

                   default:
                           system("cls");
                           cout << "please enter a number between 1 and 4. try again";
                           p-=1;
                           cout << endl<<endl;}
                           play();}}
                  
                  /*if (counter==1)
                  goto f;
                  else if (counter==2)
                  goto s;
                  else if (counter==3)
                  goto t;
                  
                  f:
                  if (people[0].get_money==people[1].get_money && people[1].get_money==people[2].get_money && people[2].get_money==people[3].get_money && people[3].get_money==people[4].get_money && people[4].get_money==people[5].get_money &&people[5].get_money==people[6].get_money && people[6].get_money==people[7].get_money){
                  poker.firstt=true;
                  counter++;
                       play();}
                  s:
                  if (people[0].get_money==people[1].get_money && people[1].get_money==people[2].get_money && people[2].get_money==people[3].get_money && people[3].get_money==people[4].get_money && people[4].get_money==people[5].get_money &&people[5].get_money==people[6].get_money && people[6].get_money==people[7].get_money){
                  poker.firstt=false;
                  poker.secondt=true;
                  counter++;
                       play();}
                  t:
                  if (people[0].get_money==people[1].get_money && people[1].get_money==people[2].get_money && people[2].get_money==people[3].get_money && people[3].get_money==people[4].get_money && people[4].get_money==people[5].get_money &&people[5].get_money==people[6].get_money && people[6].get_money==people[7].get_money){
                  poker.secondt=false;
                  poker.thirdt=true;
                  counter++;
                       play();
                       }
                  else
                        play(); */       
                   }
      };Play play;
      
int main()
    {
          Check_Hands.max=people[0].scoress;
    play.counter=0;
    for (int is=0;is<8;is++){
        people[is].is_in=true;
        people[is].get_money=0;
        }
          poker.firstt=false;
          poker.secondt=false;
          poker.thirdt=false;
srand(time(NULL));
for (int cc=0;cc<52;cc++){
    cards[cc].check_is=true;}
play.base_money=100;
poker.First_screen();
cout << "please enter the name of players (must be 8) : "<<endl;
for (int q=0;q<8;q++){
cout<< "the name of player " <<q+1<< " is: ";
cin >> people[q].name;}
system("cls");
// initalizer for suit counter
for (int pp=0;pp<8;pp++){
people[pp].C_counter=0;
people[pp].H_counter=0;
people[pp].D_counter=0;
people[pp].S_counter=0;}

//other initalizers
for (int mm=0;mm<8;mm++){
    people[mm].money=5000;}


// pot, suits and numbers initalizer
    poker.pot=0;
    poker.suits[0]="H";
    //poker.suits[0].push_back("H");
    poker.suits[1]="S";
    poker.suits[2]="D";
    poker.suits[3]="C";
    poker.numbers[0]="2";
    poker.numbers[1]="3";
    poker.numbers[2]="4";
    poker.numbers[3]="5";
    poker.numbers[4]="6";
    poker.numbers[5]="7";
    poker.numbers[6]="8";
    poker.numbers[7]="9";
    poker.numbers[8]="10";
    poker.numbers[9]="J";
    poker.numbers[10]="Q";
    poker.numbers[11]="K";
    poker.numbers[12]="A";
 
//create all cards
for (int i=0;i<4;i++){
for (int j=0;j<13;j++){
cards[13*i+j].suit=poker.suits[i];
cards[13*i+j].number=poker.numbers[j];
}}        
// cards on ground:         
for(int firsttime=0;firsttime<5;firsttime++){
int first= rand()%52;
if (cards[first].check_is==true){
poker.on_ground[firsttime].number=cards[first].number;
poker.on_ground[firsttime].suit=cards[first].suit;
cards[first].check_is=false;}
else
firsttime-=1;
}        
// create each player's first 2cards
string movers[8];
string movern[8];
for (int co=0;co<8;co++){
for (int o=0;o<2;o++){
int second=rand()%52;
if (cards[second].check_is==true){
movers[co]= cards[second].suit;
movern[co] =cards[second].number;
people[co].my_card[o].suit=movers[co];
people[co].my_card[o].number=movern[co];
cards[second].check_is=false;
}
else{
     o-=1;}
     }}  
// create final hands 
for(int yy=0;yy<8;yy++){
for(int tt=0;tt<5;tt++){
people[yy].Fcards[tt].number=poker.on_ground[tt].number;
people[yy].Fcards[tt].suit=poker.on_ground[tt].suit;}}
string movers2[8];
string movern2[8];
for(int yyy=0;yyy<8;yyy++){
for (int uu=5;uu<7;uu++){
movers2[yyy]=people[yyy].my_card[uu-5].suit;
movern2[yyy]=people[yyy].my_card[uu-5].number;
people[yyy].Fcards[uu].number=movern2[yyy];
people[yyy].Fcards[uu].suit=movers2[yyy];}}

// initalize the siut counter and nember counter
Check_Hands.initalizer();
for (int pp=0;pp<8;pp++){
    people[pp].initalizern();}

// counting suits
for (int pc=0;pc<8;pc++){
for (int c=0;c<7;c++){
if (people[pc].Fcards[c].suit=="H")
people[pc].H_counter++ ;   
if (people[pc].Fcards[c].suit=="S")
people[pc].S_counter++;
if (people[pc].Fcards[c].suit=="C")
people[pc].C_counter++;
if (people[pc].Fcards[c].suit=="D")
people[pc].D_counter++;                   
}}

// counting numbers
for (int pc=0;pc<8;pc++){
for (int c=0;c<7;c++){
if (people[pc].Fcards[c].number=="A")
people[pc].counternum[12]++;
if (people[pc].Fcards[c].number=="2")
people[pc].counternum[0]++;
if (people[pc].Fcards[c].number=="3")
people[pc].counternum[1]++;
if (people[pc].Fcards[c].number=="4")
people[pc].counternum[2]++;    
if (people[pc].Fcards[c].number=="5")
people[pc].counternum[3]++; 
if (people[pc].Fcards[c].number=="6")
people[pc].counternum[4]++; 
if (people[pc].Fcards[c].number=="7")
people[pc].counternum[5]++; 
if (people[pc].Fcards[c].number=="8")
people[pc].counternum[6]++; 
if (people[pc].Fcards[c].number=="9")
people[pc].counternum[7]++; 
if (people[pc].Fcards[c].number=="10")
people[pc].counternum[8]++; 
if (people[pc].Fcards[c].number=="J")
people[pc].counternum[9]++; 
if (people[pc].Fcards[c].number=="Q")
people[pc].counternum[10]++; 
if (people[pc].Fcards[c].number=="K")
people[pc].counternum[11]++; 
}}


Check_Hands.Checker();

for(int zx=0;zx<8;zx++){
if (people[zx].score.royalFlush==true){
  people[zx].FinalScore="*** ROYAL FLUSH ***";}
 if (people[zx].score.straightFlush==true){
   people[zx].FinalScore="*** STRAIGHT FLUSH ***";}
 if (people[zx].score.fours==true){
   people[zx].FinalScore="*** FOUR OF A KIND ***";}
 if (people[zx].score.full==true){
   people[zx].FinalScore="*** FULL HOUSE ***";}
 if (people[zx].score.flushz==true){
   people[zx].FinalScore="*** FLUSH ***";}
 if (people[zx].score.straight==true){
   people[zx].FinalScore="*** STRAIGHT ***";}
 if (people[zx].score.threes==true){
   people[zx].FinalScore="*** THREE OF A KIND ***";}
 if (people[zx].score.two==true){
   people[zx].FinalScore="*** TWO PAIRS ***";}
 if (people[zx].score.one==true && people[zx].score.two==false){
   people[zx].FinalScore="*** PAIR ***";}
else{
     people[zx].FinalScore="*** HIGH CARD ***";
     people[zx].scoress=1;}}

play.play();


system("pause");
return 0;
}
