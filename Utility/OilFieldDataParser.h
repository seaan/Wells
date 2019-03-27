//====================================================================
// OilFieldDataParser.h
// Interface file for the data parser for program 2.
// Author: Dr. Rick Coleman
// Date: December 2009
//====================================================================
#ifndef OILFIELDDATAPARSER_H
#define OILFIELDDATAPARSER_H

#include <fstream>
#include <iostream>

using namespace std;

class OilFieldDataParser
{
	private:
		ifstream	*inFile;				// Oilfield data definition file
		int			m_iNumWells;			// Number of wells in the data file
		int			m_iNumSensors;			// Number of sensor _types
		int			m_iNextWellNumber;		// Index of the next well to read
		char		**m_cpWellID;			// Pointer to array of pointers to
											//  char arrays holding well IDs
		int			*m_ipNextSensorNumber;	// Pointer to array of ints counting
											//  sensors for each well
		char        m_sFileName[128];		// Data file
		OilFieldDataParser();				// Private constructor

	public:
		~OilFieldDataParser();				// Destructor
		static OilFieldDataParser *getInstance();	// Get the singleton instance
		void initDataFile(const char *fileName);
		int getWellCount();
		char **getWellIDs();				// Get the NULL terminated array of IDs
		bool getWellData(char *id, char *opr, 
			int *numSensors, char ***senTypes);
		bool getSensorData(char *type,
			char *className, char *displayName, double *min, bool *minUdf, 
			double *max, bool *maxUdf, double *step, char *units, char *unitAbbrev, 
			char *dataGenAlg, char *linkSenType);
		void printWellData(); // For testing only
	private:
		bool getNextLine(char *buffer, int n);

};
#endif