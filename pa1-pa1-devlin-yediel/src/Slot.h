#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>


using namespace std;

class ofApp;

class Slot{

    public:

        int jackpot= 100;

        float Balance= 0;
        float Bet= 0;

        string BalanceForDisplay= "";
        string BetForDisplay= "";

        bool WasSpun= false;

        //Count for each fruit in main slot
        int LemonCnt= 0;
        int CherryCnt= 0;
        int AppleCnt= 0;

        //Random number to stop at for spinning
        int RandSlot1;
        int RandSlot2;
        int RandSlot3;

        //Quees for each slot
        queue<string> Slot1;
        queue<string> Slot2;
        queue<string> Slot3;

        //Main Slot to display
        vector<string> MainSlot;

        //Map with the counts of each fruit in MainSlot
        map<string, int> FruitCnt;

        
        //Initialize SLot queues 
        Slot(){

            Slot1.push("APPLE");
            Slot1.push("CHERRY");
            Slot1.push("LEMON");

            Slot2.push("APPLE");
            Slot2.push("CHERRY");
            Slot2.push("LEMON");

            Slot3.push("APPLE");
            Slot3.push("CHERRY");
            Slot3.push("LEMON");

        }


        //Methods
        void spin();

        void ShowMainSlot();

        void FillFruitcnt(vector<string> MainSlot);

        void FindFruitKeys();

        void DeterminePayout();

        //Setters
        void setWasSpun(bool WasSpun);

        void setLemonCnt(int LemonCnt);

        void setCherryCnt( int CherryCnt);

        void setAppleCnt(int AppleCnt);

        void setBalance(float Balance);

        void setBet(float Bet);

        void setBalanceForDisplay(string BalanceForDisplay);

        void setBetForDisplay(string BetForDisplay);


        //Getters

        bool getWasSpun(){return WasSpun;}

        int getLemonCnt(){return LemonCnt;}

        int getCherryCnt(){return CherryCnt;}

        int getAppleCnt(){return AppleCnt;}  

        float getBalance(){return Balance;}      

        float getBet(){return Bet;}

        string getBalanceForDisplay(){return BalanceForDisplay;}

        string getBetForDisplay(){return BetForDisplay;}




};
