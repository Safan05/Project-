#pragma once
#include "RandGen.h"
#include"..\EarthForces\EarthArmy.h"
#include"..\Alien Forces\AlienArmy.h"
#include"..\Allied Forces\AlliedArmy.h"
#include"..\Game\KilledList.h"
class Game
{
private:
	int TS;  // the current time step
	char Filename[50],mode;  // the file name to load , and mode is for interacive or silent 
	int N, Prob;
	// to check when the ids has reached it's limit so it doesn't generate units again just attack
	bool GenAliensID;
	bool GenEarthID;	
	bool GenAlliesID;
	bool GenAllies;		// to check for the threshold of infection and return to false when there is no infected units
	int EP[4], AP[3], ER[6], AR[6],SR[6]; // Earth Probabilities , Alien Probabilities , Earth ranges , Alien ranges and Saver unit Ranges respectively
	int infection_prob;
	int SU_Threshold;
	RandGen G;	
	EarthArmy E;
	AlienArmy A;
	AlliedArmy S;
	KilledList K;
	int Kcount;
	int AvgDs[6]; //[0]Df, [1]Dd, [2]Db First three are for Earth,last three for alien    
	//implementation in units folder is for Df,where as    
	//the one inside Func.Enqueue Killed is for Dd and Db
public:
	Game();      // the game constructor which collects all the project together
	void LoadParameters(char FileName[]); // loading the parameters from the input file
	// Getters fot the armies and lists in the game , by reference to prevent copying it
	EarthArmy& GetEArmy();	
	AlienArmy& GetAArmy();
	AlliedArmy& GetSArmy();
	KilledList& GetKList();
	void Battle(); // responsible for making the armies attack each other
	bool BattleResult(char result[]); // return true when a result is achieved and returns the result in "result" char array
	int GetTS();	// getter for the current time step
	bool AddKilled(unit*&);
	void GenerateWarReport();
	void PrintAverageResults(ofstream& WR, bool IsE, int aliveE, double KilledE, int AliveA, double KilledA);	// used in generating war report to print the average results in the output file
	// setters for Earth and Aliens average Df,Db
	void SetEDf(int f);
	void SetADf(int f);
	void SetEDb(int d);
	void SetADb(int d);
	int getInfectionProb(); // getter for infection prob to be used in monster attack
	void Call_Generator();
	void InteractiveMode();
	void Interface();
	~Game();
};

