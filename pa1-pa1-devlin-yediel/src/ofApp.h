#pragma once
#include "ofMain.h"
#include "Slot.h"
#include <map>
#include <vector>
#include <string>


class ofApp : public ofBaseApp{

	

	public:
		//Some OpenFrameworks must-have functions
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void updateBalanceDisplay();

		Slot slot;

		
	private:
		
		ofImage SlotBox1;
		ofImage SlotBox2;
		ofImage SlotBox3;

		ofImage Lemon;
		ofImage Apple;
		ofImage Cherry;

		ofTrueTypeFont TitleFont;
		ofTrueTypeFont BalanceFont;

		bool isTyping= false;
		bool BalanceEntered= false;
		bool BetEntered= false;
		string UserInput= "";

		ofSoundPlayer CasinoBackgroundMusic;


		
		
};