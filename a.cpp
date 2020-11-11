#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
class cPerson
{
public:
	std::string first;
	std::string middle;
	std::string last;


	// enum inside the class "tightly coupled"
	enum eGenderType
	{
		MALE = 0,
		FEMALE,
		NON_BINARY,
		RATHER_NOT_SAY_UNKNOWN
	};

	eGenderType gender;
	std::string getGenderAsString(void){
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

	int age;		// default = -1;

	// These are in the format from the US census data: https://catalog.data.gov/dataset/street-names-37fec/resource/d655cc82-c98f-450a-b9bb-63521c870503
	//
	// Something like this: "MISSION BAY BLVD NORTH, MISSION BAY, BLVD, NORTH"
	// would be:
	//	- streetName = "MISSION BAY"
	//  - streetType = "BLVD"
	//  - streetDirection = "NORTH"	    Note: many streets don't have a streetDirection
	//                                        and "street direction" can be stuff like "RAMP", etc. 
	// 
	int streetNumber;		// default = 0 
	std::string streetName;
	std::string streetType;
	std::string streetDirection;

	std::string city;
	std::string province;
	char postalCode[6];		// Canadian postal codes are 6 characters

	unsigned int SIN;	// = 0
	//unsigned int SIN = 0;		// C++ 11

	unsigned int getSnotifyUniqueUserID(void);

	unsigned int m_Snotify_UniqueUserID;
	// 
	static unsigned int m_NEXT_Snotify_UniqueUSerID;
cPerson()
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
//unsigned int m_NEXT_Snotify_UniqueUSerID = 10000000;

 ~cPerson()
{

}	
};
class cPersonGenerator
{
public:
	cPerson p;
	cPersonGenerator();
	~cPersonGenerator();

	// This takes three files:
	// - One of the "Popular Baby Names" found here: https://www.ssa.gov/oact/babynames/limits.html
	//   (example: "yob2001.txt" which are babies born in the year 2001
	// - The "Names_2010Census.csv" file, from:
	//   "Frequently Occurring Surnames from the 2010 Census" from here:
	//   https://www.census.gov/topics/population/genealogy/data/2010_surnames.html
	// - The "Street_Names.csv" file, from:
	//   "Street Names (San Francisco)" from here: 
	//   https://catalog.data.gov/dataset/street-names-37fec/resource/d655cc82-c98f-450a-b9bb-63521c870503
	// Returns:
	// - true of successful
	// - false if there's any issue (can't find file, or whatever)
	//   If false, then the "errorString" (passed by reference) should be loaded with some sort of 
	//   description of what went wrong (file didn't open, parse issue, Skynet became self aware, etc.)
	//   Use your discretion (and creativity) for this. 
	bool LoadCensusFiles(
		std::string babyNameFile,
		std::string surnameFile,
		std::string streetNameFile,
		std::string& errorString){
		int num1=rand()%1000;
		int num2=rand()%1000;
		std::string firstname;	
		std::string middlename;	
		std::string lastname;	
		    int counter=0;

	std::ifstream file(babyNameFile.c_str());
	if (file.is_open()) {
	    std::string line;
	    while (std::getline(file, line)) {
    	if(counter==num1){
    		firstname=line;
    	}
    	if(counter==num2){
    		middlename=line;
    	}
    	counter++;
    	}
    	file.close();
	}	
	p.first=firstname;	
	p.middle=middlename;

	std::ifstream namesFile(surnameFile.c_str());
	if (!namesFile.is_open())
	{
		std::cout << "Didn't open file" << std::endl;
		return false;
	}
	std::string theLine;

	unsigned int lineCount = rand()%16000;
	counter=0;
	while (std::getline(namesFile, theLine))
	{
		std::stringstream ssLine(theLine);
		std::string token;
		unsigned int tokenCount = 0;
		while (std::getline(ssLine, token, ','))
		{
			if (tokenCount == 0)
			{
				//std::cout << token << std::endl;
				if(counter==lineCount){
					lastname=token;
				}
			}
			tokenCount++;
		}
		counter++;
	}
	p.last=lastname;
		int num3=rand()%1000;
	num3+=1;
	//std::string ;
	std::ifstream namesFile1(streetNameFile.c_str());
	if (!namesFile1.is_open())
	{
		std::cout << "Didn't open file" << std::endl;
		return false;
	}
	std::string theLine1,streetname,streettype;
	counter=0;
	while (std::getline(namesFile, theLine1))
	{
		std::stringstream ssLine(theLine1);
		std::string token;
		if(counter==num3){
		unsigned int tokenCount = 0;
		while (std::getline(ssLine, token, ','))
		{
				if(tokenCount==1){
					p.streetName=token;					
				}
				if(tokenCount==2){
					p.streetType=token;					
				}
				tokenCount++;
		}
		}
		counter++;	
	}
		std::cout<<p.first<<std::endl;
		std::cout<<p.middle<<std::endl;
		std::cout<<p.last<<std::endl;
		std::cout<<p.streetName<<std::endl;
		std::cout<<p.streetType<<std::endl;

	return true;

}

	unsigned int getNumberOfNamesLoaded(void);
	unsigned int getNumberOfSurnamesLoaded(void);
	unsigned int getNumberOfStreetsLoaded(void);

	// Randomly generates a person from the data
	// Returns 0, NULL, or nullptr if it can't do this. 
	void generateRandomPerson(void){
		std::string babyNameFile="yob1880.txt";
		std::string surnameFile="Names_2010Census.csv";
		std::string streetNameFile="Street_Names.csv";
		std::string errorString;
		srand(time(NULL));
		int num;
		num=rand()%30;
		num+=880;
		std::stringstream ss;  
	  	ss<<num;  
	  	std::string s;  
	  	ss>>s;
		babyNameFile[4]=s[0];
		babyNameFile[5]=s[1];
		babyNameFile[6]=s[2];
		LoadCensusFiles(babyNameFile,surnameFile,surnameFile,errorString);
	}
};

int main(){
	cPersonGenerator pg;
	pg.generateRandomPerson();
/*	srand(time(NULL));
	int num;
	num=rand()%30;
	num+=880;
	std::stringstream ss;  
  	ss<<num;  
  	std::string s;  
  	ss>>s;
		std::string babyNameFile="yob1880.txt";
  	std::cout<<s<<std::endl;  
  	std::cout<<s[0]<<std::endl;  
  	std::cout<<s[1]<<std::endl;  
  	std::cout<<s[2]<<std::endl;  
  	std::cout<<babyNameFile<<std::endl;  */
/*	int num3=rand()%1000;
	num3+=1;
	//std::string ;
	std::ifstream namesFile("Street_Names.csv");
	if (!namesFile.is_open())
	{
		std::cout << "Didn't open file" << std::endl;
		return false;
	}
	std::string theLine1,streetname,streettype;
	int counter=0;
	while (std::getline(namesFile, theLine1))
	{
		std::stringstream ssLine(theLine1);
		std::string token;
		if(counter==num3){
		unsigned int tokenCount = 0;
		while (std::getline(ssLine, token, ','))
		{
				if(tokenCount==1){
					std::cout << token <<" name";					
				}
				if(tokenCount==2){
					std::cout << token <<" type";					
				}
				tokenCount++;
		}
		std::cout<<std::endl;
		}
		counter++;	
	}*/
/*		int num1=rand()%1000;
		int num2=rand()%1000;
		std::string firstname;	
		std::string middlename;	
		    int counter=0;

std::ifstream file(babyNameFile.c_str());
if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
        // using printf() in all tests for consistency
        //std::cout<<line<<std::endl;
    	if(counter==num1){
    		firstname=line;
    	}
    	if(counter==num2){
    		middlename=line;
    	}
    	counter++;
    }
    file.close();
}	
        std::cout<<firstname<<std::endl;
        std::cout<<middlename<<std::endl;*/

	return 0;
}