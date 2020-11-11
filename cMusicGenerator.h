#pragma once
#ifndef _cMusicGenerator_HG_
#define _cMusicGenerator_HG_

#include "cSong.h"
#include<fstream>
#include<string>
#include<sstream>
#include<time.h>
using namespace std;
class cMusicGenerator
{
public:

/*This function is reading all the Singers and their songs from given file */
	bool LoadMusicInformation(std::string musicFileName, std::string& errorString) {
		fstream handler;
		string completeLineFromHotStuff, songNameFromHotStuff, performerNameFromHotStuff;

		handler.open(musicFileName);
		if (handler.is_open())
		{
			while (getline(handler, completeLineFromHotStuff))
			{
				stringstream obj(completeLineFromHotStuff);
				getline(obj, songNameFromHotStuff, ',');
				getline(obj, songNameFromHotStuff, ',');
				getline(obj, songNameFromHotStuff, ',');
				songNameFromHotStuff[0] = '\0';
				getline(obj, songNameFromHotStuff, ',');
				getline(obj, performerNameFromHotStuff, ',');
				cout << "Performer Name = " << performerNameFromHotStuff << " Song name= " << songNameFromHotStuff << endl;
				songNameFromHotStuff[0] = performerNameFromHotStuff[0] = '\0';
			}
			handler.close();
		}
		else {
			cout << "Hot Stuff file is missing or unable to read it!" << endl;
			return false;
		}
		return true;
	}

	cSong* getRandomSong(void) {
		fstream handler;
		string completeLineFromHotStuff, songNameFromHotStuff, performerNameFromHotStuff;
		handler.open("Hot Stuff.csv");
		if (handler.is_open())
		{
		}

		srand(time(0));
		int number = rand() % 500;
		for (int i = 0; i < number; i++) {
			getline(handler, completeLineFromHotStuff);
		}
		stringstream obj(completeLineFromHotStuff);
		getline(obj, songNameFromHotStuff, ',');
		getline(obj, songNameFromHotStuff, ',');
		getline(obj, songNameFromHotStuff, ',');
		getline(obj, songNameFromHotStuff, ',');
		getline(obj, performerNameFromHotStuff, ',');
		cSong objS;
		objS.name = songNameFromHotStuff;
		objS.artist = performerNameFromHotStuff;
		//cout <<"song number = "<<number<< objS.artist << " " << objS.name << endl;
		handler.close();
		return &objS;
	}

	// Returns 0, NULL, or nullptr if no song is found
	// This must be an EXACT MATCH for what's in the billboard100 file. 
	// So case sensitive, etc. 

	cSong* findSong(std::string songName, std::string artist) {
		fstream handler;
		string completeLineFromHotStuff, songNameFromHotStuff, performerNameFromHotStuff, copy;
		bool found = false;
		handler.open("Hot Stuff.csv");
		if (handler.is_open()) {
			while (getline(handler, completeLineFromHotStuff)){
				stringstream obj(completeLineFromHotStuff);
				getline(obj, songNameFromHotStuff, ',');
				getline(obj, songNameFromHotStuff, ',');
				getline(obj, songNameFromHotStuff, ',');
				getline(obj, songNameFromHotStuff, ',');
				getline(obj, performerNameFromHotStuff, ',');
				if (performerNameFromHotStuff == artist && songNameFromHotStuff == songName) {
					found = true;
					handler.close();
					break;
				}
				else {
					songNameFromHotStuff[0] = performerNameFromHotStuff[0] = '\0';
					continue;
				}
			}
			if (found == true) {
				cSong objS;
				objS.name = songNameFromHotStuff;
				objS.artist = performerNameFromHotStuff;
				cout << "Song Present in PlayList" << endl;
				return &objS;
			}
			if (found == false) {
				cout << "Song not present in PlayList" << endl;
				return NULL;
			}
		}
		else {
			cout << "File not found!" << endl;
		}
		found = false;
	}
};

#endif
