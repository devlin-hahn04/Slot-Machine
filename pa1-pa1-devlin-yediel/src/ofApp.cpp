#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//Loads each individual slot image
	SlotBox1.load("images/SlotBox.png");
	SlotBox2.load("images/SlotBox.png");
	SlotBox3.load("images/SlotBox.png");

	//Loads fonts used 
	TitleFont.load("Font/Font8Bit.ttf", 50);
	BalanceFont.load("Font/Font8Bit.ttf", 18);

	//Loads fruit images and resizes each
	Apple.load("images/Apple.png");
	Apple.resize(ofGetWidth()/2, ofGetHeight()/2);

	Lemon.load("images/Lemon.png");
	Lemon.resize(ofGetWidth()/3, ofGetHeight()/3);

	Cherry.load("images/Cherry.png");
	Cherry.resize(ofGetWidth()/3, ofGetHeight()/3);

	//Loads music 
	CasinoBackgroundMusic.load("sounds/LuigiCasinoMusic.mp3");
	CasinoBackgroundMusic.setLoop(true);
	CasinoBackgroundMusic.play();


	//Generates an initial spin 
	slot.spin();
	slot.ShowMainSlot();


	
}
//--------------------------------------------------------------
void ofApp::update(){

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Create the background
    ofBackground(0,0,128);

	TitleFont.drawString("Lucky Slots", ofGetWidth()*1/8, ofGetHeight()*1/5);

	BalanceFont.drawString("Current Balance:", ofGetWidth()/8, ofGetHeight()-550);
	BalanceFont.drawString("Current Bet: ", ofGetWidth()-400, ofGetHeight()-550);

	SlotBox1.draw(ofGetWidth()*1/14, ofGetHeight()*1/3);
	SlotBox2.draw(ofGetWidth()*1/3, ofGetHeight()*1/3);
	SlotBox3.draw(ofGetWidth() - SlotBox2.getWidth() - 80, ofGetHeight()*1/3);

	//Drawing Lemon in any slots its in
	if(slot.MainSlot[0] == "LEMON"){Lemon.draw(ofGetWidth() * 1 / 14 + (SlotBox1.getWidth() - Lemon.getWidth()) / 2, ofGetHeight() * 1 / 3 + (SlotBox1.getHeight() - Lemon.getHeight()) / 2);}
	if(slot.MainSlot[1] == "LEMON"){Lemon.draw(ofGetWidth() * 1 / 3 + (SlotBox2.getWidth() - Lemon.getWidth()) / 2, ofGetHeight() * 1 / 3 + (SlotBox2.getHeight() - Lemon.getHeight()) / 2);}	
	if(slot.MainSlot[2] == "LEMON"){Lemon.draw(ofGetWidth() - SlotBox3.getWidth() - 80 + (SlotBox3.getWidth() - Lemon.getWidth()) / 2, ofGetHeight() * 1 / 3 + (SlotBox3.getHeight() - Lemon.getHeight()) / 2);}

	//Drawing Apple in any slots its in
	if(slot.MainSlot[0] == "APPLE"){Apple.draw(ofGetWidth() * 1 / 14 + (SlotBox1.getWidth() - Apple.getWidth()) / 2, ofGetHeight() * 1 / 3 + (SlotBox1.getHeight() - Apple.getHeight()) / 2);}
	if(slot.MainSlot[1] == "APPLE"){Apple.draw(ofGetWidth() * 1 / 3 + (SlotBox2.getWidth() - Apple.getWidth()) / 2, ofGetHeight() * 1 / 3 + (SlotBox2.getHeight() - Apple.getHeight()) / 2);}	
	if(slot.MainSlot[2] == "APPLE"){Apple.draw(ofGetWidth() - SlotBox3.getWidth() - 80 + (SlotBox3.getWidth() - Apple.getWidth()) / 2, ofGetHeight() * 1 / 3 + (SlotBox3.getHeight() - Apple.getHeight()) / 2);}

	//Drawing Cherry in any slots its in
	if(slot.MainSlot[0] == "CHERRY"){Cherry.draw(ofGetWidth() * 1 / 14 + (SlotBox1.getWidth() - Cherry.getWidth()) / 2, ofGetHeight() * 1 / 3 + (SlotBox1.getHeight() - Cherry.getHeight()) / 2);}
	if(slot.MainSlot[1] == "CHERRY"){Cherry.draw(ofGetWidth() * 1 / 3 + (SlotBox2.getWidth() - Cherry.getWidth()) / 2, ofGetHeight() * 1 / 3 + (SlotBox2.getHeight() - Cherry.getHeight()) / 2);}	
	if(slot.MainSlot[2] == "CHERRY"){Cherry.draw(ofGetWidth() - SlotBox3.getWidth() - 80 + (SlotBox3.getWidth() - Cherry.getWidth()) / 2, ofGetHeight() * 1 / 3 + (SlotBox3.getHeight() - Cherry.getHeight()) / 2);}

	//Logic to obtain balance
	ofSetColor(255);
	if(BalanceEntered == false){
		BalanceFont.drawString("Enter Balance:$", (ofGetWidth()/3)-20, ofGetHeight()-150);
	}

	if(isTyping){
		ofSetColor(255);
		BalanceFont.drawString(UserInput, (ofGetWidth()/3)-20, ofGetHeight()-130);


	}

	//Logic to obtain bet
	ofSetColor(255);
	if(BalanceEntered == true && BetEntered == false){
		BalanceFont.drawString("Enter Bet:$", (ofGetWidth()/3)-20, ofGetHeight()-150);
	}

	if(isTyping && BalanceEntered == true){
		ofSetColor(255);
		BalanceFont.drawString(UserInput, (ofGetWidth()/3)-20, ofGetHeight()-130);

	}


	//Draws current balance on screen
	if((!isTyping && BalanceEntered == true && BetEntered == true) || slot.getWasSpun() == true){
		
		BalanceFont.drawString(slot.BalanceForDisplay, ofGetWidth()/8, ofGetHeight()-520);
		BalanceFont.drawString(slot.BetForDisplay, ofGetWidth()-400, ofGetHeight()-520);
	
	}	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if(isTyping && BalanceEntered == false){
        // If the pressed key is a printable character
        if(isprint(key)){
            // Append the character to the userInput string
            UserInput += (char)key;
        } 
        // Handle backspace
        else if(key == OF_KEY_BACKSPACE && slot.BalanceForDisplay.length() > 0){
            UserInput.pop_back(); // Remove the last character
        }

		else if(key == OF_KEY_RETURN){
			isTyping= false;
			BalanceEntered= true;
			slot.BalanceForDisplay= UserInput;
			UserInput.clear();
		}
    }

	if(isTyping && BalanceEntered == true && BetEntered == false){
        // If the pressed key is a printable character
        if(isprint(key)){
            // Append the character to the userInput string
        	UserInput += (char)key;
        } 
        // Handle backspace
        else if(key == OF_KEY_BACKSPACE && slot.BetForDisplay.length() > 0){
            UserInput.pop_back(); // Remove the last character
        }

		else if(key == OF_KEY_RETURN){
			isTyping= false;
			BetEntered= true;

			slot.setWasSpun(false);

			slot.BetForDisplay= UserInput;

			slot.setBalance(stof(slot.getBalanceForDisplay()) - stof(slot.getBetForDisplay()));
			slot.setBalanceForDisplay(to_string(slot.getBalance()));

			UserInput.clear();
		}
    }

	if(key == 's' && BalanceEntered == true && BetEntered == true){

		slot.setBalance(stof(slot.getBalanceForDisplay()));
		slot.setBet(stof(slot.getBetForDisplay()));


		slot.spin();
		slot.ShowMainSlot();

		BetEntered= false;

		slot.FillFruitcnt(slot.MainSlot);
		slot.FindFruitKeys();
		slot.DeterminePayout();

	}





}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int mouseX, int mouseY ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------

void ofApp::mousePressed(int x, int y, int button){
	
	// Check if the mouse is clicked within the area where the user enters the balance
    if(x >= (ofGetWidth()/3)-20 && x <= (ofGetWidth()/3)+180 && y >= ofGetHeight()-150 && y <= ofGetHeight()-130){
        isTyping = true; // Start typing
    }


}

//--------------------------------------------------------------

void ofApp::updateBalanceDisplay() {
    BalanceFont.drawString(slot.BalanceForDisplay, ofGetWidth()/8, ofGetHeight()-520);
    BalanceFont.drawString(slot.BetForDisplay, ofGetWidth()-400, ofGetHeight()-520);
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
//--------------------------------------------------------------

