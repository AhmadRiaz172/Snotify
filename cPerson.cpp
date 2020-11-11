#include "cPerson.h"

// Warning C26812 : Prefer 'enum class' over 'enum' (Enum.3)
#pragma warning( disable : 26812 )

cPerson::cPerson()
{
	// In here, set the default information
	this->gender = cPerson::RATHER_NOT_SAY_UNKNOWN;
	this->streetNumber = 0;
	this->age = -1;
	this->SIN = 0;

	// Generate unique Snotify ID
	this->m_Snotify_UniqueUserID = cPerson::m_NEXT_Snotify_UniqueUSerID;
	// Increment for next created user by a small random amount 
	const unsigned int MAX_ID_INCREEMNT = 11;
	cPerson::m_NEXT_Snotify_UniqueUSerID += (rand() % MAX_ID_INCREEMNT);
}

// The 1st Snotify user will have ID: 10,000,000
// static 
unsigned int cPerson::m_NEXT_Snotify_UniqueUSerID = 10000000;

cPerson::~cPerson()
{

}

std::string cPerson::getGenderAsString(void)
{
	switch (this->gender)
	{
	case cPerson::MALE:
		return "MALE";
		break;
	case cPerson::FEMALE:
		return "FEMALE";
		break;
	case cPerson::NON_BINARY:
		return "NON_BINARY";
		break;
	case cPerson::RATHER_NOT_SAY_UNKNOWN:
		return "RATHER_NOT_SAY_UNKNOWN";
		break;
		//	default:
		//		break;
	}

	// This should never happen
//	return "RATHER_NOT_SAY_UNKNOWN";
	return "OMG! CALL THE DEV TEAM!! SOMEONE SCREWED UP!!!";
}

unsigned int  cPerson::getSnotifyUniqueUserID(void) {
	return m_Snotify_UniqueUserID;
}

bool  cPerson :: AddSongToLibrary(cSong* sonng) {

	int s = musicLibrary.getSize();
	for (int i = 0; i < s; i++) {
		if (musicLibrary[i].song == sonng)
			return 0;
	}

	libraryNode newNode; 
	newNode.song = sonng;
	newNode.numberOfTimesPlayedByUser = 0;
	musicLibrary.Push(newNode);
	return 1;
}


void  cPerson::displaySongLibrary() {
	for (int i = 0; i < musicLibrary.getSize(); i++) {
		cout << musicLibrary[i].song->uniqueID <<"\t" <<musicLibrary[i].song->name << "\t" << musicLibrary[i].song->artist << "\t" << musicLibrary[i].song->numberOfTimesPlayed << "\t"
			<< musicLibrary[i].song->rating << "\t"
			<< musicLibrary[i].numberOfTimesPlayedByUser << endl;
	}
}


bool cPerson :: deleteSongFromLibrary(unsigned int SnotifySongID) {


	int i;
	int n = musicLibrary.getSize();
	for (i = 0; i < n; i++)
		if (musicLibrary[i].song->getUniqueID() == SnotifySongID)
			break;
	if (i != n) {
		musicLibrary.deleteAt(i);
		return 1;
	}
	
	
	return 0;
}
cSong *  cPerson::playSong(unsigned int SnotifySongID) {
	for (int i = 0; i < musicLibrary.getSize(); i++) {
		if (musicLibrary[i].song->getUniqueID() == SnotifySongID) {
			musicLibrary[i].song->numberOfTimesPlayed++;
			musicLibrary[i].incremet();
			return musicLibrary[i].song;
		}
	}

	return NULL;
}


cSong* cPerson:: findSong(unsigned int SnotifySongID) {

	for (int i = 0; i < musicLibrary.getSize(); i++) {
		if (musicLibrary[i].song->getUniqueID() == SnotifySongID)
			return musicLibrary[i].song;
	}
	return NULL;
}