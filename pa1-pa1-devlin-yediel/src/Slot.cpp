#include "Slot.h"


void Slot::spin(){

    srand(time(NULL));

    RandSlot1= rand() % 10 + 1;
    RandSlot2= rand() % 15 + 1;
    RandSlot3= rand() % 20 + 1;

    //Spins each queue of slots 
    for(int i= 0; i < RandSlot1; i++){
        string slot1= Slot1.front();
        Slot1.pop();
        Slot1.push(slot1);
    }

    for(int j= 0; j < RandSlot2; j++){
        string slot2= Slot2.front();
        Slot2.pop();
        Slot2.push(slot2);
    }

    for(int k= 0; k < RandSlot3; k++){
        string slot3= Slot3.front();
        Slot3.pop();
        Slot3.push(slot3);
    }  

}

void Slot::ShowMainSlot(){

    MainSlot.clear();

    MainSlot.push_back(Slot1.front());
    MainSlot.push_back(Slot2.front());
    MainSlot.push_back(Slot3.front());

}

void Slot::FillFruitcnt(vector<string> MainSlot){

    FruitCnt.clear();
    
    for(int b= 0; b < MainSlot.size(); b++){

        string fruit= MainSlot[b];

        if(FruitCnt.find(fruit) == FruitCnt.end()){

            FruitCnt[fruit]= 1;

        }

        else{

            FruitCnt[fruit]++;

        }


    }



}


//AREA FOR COUNT METHODS FOR FRUITS AMOUNT IN MAP

void Slot::FindFruitKeys(){

    for(auto it= FruitCnt.begin(); it != FruitCnt.end(); ++it){

        if(it->first == "LEMON"){
            setLemonCnt(it->second);
        }
        

        else if(it->first == "APPLE"){
            setAppleCnt(it->second);
        }

        else{
            setCherryCnt(it->second);
        }

    }


}

void Slot::DeterminePayout(){

    if(getLemonCnt() == 2){

        setBalance(getBalance() + (getBet() * .5));

    }

    else if(getAppleCnt() == 2){

        setBalance(getBalance() + (getBet() * 1.5));

    }

    else if(getCherryCnt() == 2){

        setBalance(getBalance() + (getBet() * 2.5));

    }

    else if(getLemonCnt() == 3){

        setBalance(getBalance() + (getBet() * 3));

    }

    else if(getAppleCnt() == 3){

        setBalance(getBalance() + (getBet() * 4.5));

    }

    else if(getCherryCnt() == 3){
        
        setBalance(getBalance() + (getBet() * 6));
    }

    setBalanceForDisplay(to_string(getBalance()));


    setWasSpun(true);
    

}

//Setters

void Slot::setWasSpun(bool WasSpun){this->WasSpun= WasSpun;}

void Slot::setLemonCnt(int LemonCnt){this->LemonCnt= LemonCnt;}

void Slot::setCherryCnt(int CherryCnt){this->CherryCnt= CherryCnt;}

void Slot::setAppleCnt(int AppleCnt){this->AppleCnt= AppleCnt;}

void Slot::setBalance(float Balance){this->Balance= Balance;}

void Slot::setBet(float Bet){this->Bet= Bet;}

void Slot::setBalanceForDisplay(string BalanceForDisplay){this->BalanceForDisplay= BalanceForDisplay;}

void Slot::setBetForDisplay(string BetForDisplay){this->BetForDisplay= BetForDisplay;}




