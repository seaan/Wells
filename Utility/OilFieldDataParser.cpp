//====================================================================
// OilFieldDataParser.cpp
// Implementation file for the data parser.
// Author: Dr. Rick Coleman
// Date: January 2010
//====================================================================
#define _CRT_SECURE_NO_WARNINGS

#include "OilFieldDataParser.h"
#include <string.h>

//-----------------------------------
// Private constructor
//-----------------------------------
OilFieldDataParser::OilFieldDataParser()
{

	// Initialize everything
	m_iNumWells = 0;
	m_iNumSensors = 0;
	m_iNextWellNumber = 0;
	m_cpWellID = NULL;
}

//-----------------------------------
// Destructor
//-----------------------------------
OilFieldDataParser::~OilFieldDataParser()
{
	// Destroy all the char arrays
	for(int i=0; i<m_iNumWells; i++)
	{
		delete[] m_cpWellID[i];
	}

	// Now destroy the array of pointers
	delete[] m_cpWellID;
}

//-----------------------------------
// Get the singleton instance
//-----------------------------------
OilFieldDataParser *OilFieldDataParser::getInstance()
{
	static OilFieldDataParser *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new OilFieldDataParser();
	}
	return theInstance;
}

//-----------------------------------
// Open, read, and init the data
//-----------------------------------
void OilFieldDataParser::initDataFile(const char *fileName)
{
	char line[128];
	strcpy(m_sFileName, fileName);

	// Open the data file for reading
	inFile = new ifstream();				// Create an ifstream object
	inFile->open(fileName, fstream::in);	// Open it
	if(inFile->is_open())					// Make sure it is open
	{
		// Get the basic information
		while(getNextLine(line, 127))
		{
			if(strcmp(line, "<WELL>") == 0)
			{
				m_iNumWells++;	// Count all wells
			}
			else if(strcmp(line, "<SENSOR_TYPE>") == 0)
			{
				m_iNumSensors++;	// Count all sensors
			}
		}
		inFile->close();	// Close the file
		delete inFile;		// Destroy the ifstream object
	}
	else
	{
		cout << "Failed to open file\n";
		cout << "Program terminated.\n\n";
		exit(0);
	}

	// Create the array of pointers to char arrays holding the IDs
	//  of each well.  This is used to locate the well sensor counter
	//  in calls to getSensorData()
	m_cpWellID = new char*[m_iNumWells]; // create array of pointers to char

	for(int i=0; i< m_iNumWells; i++)
	{
		m_cpWellID[i] = NULL;
	}

	// Create a new inFile object and reopen the file
	inFile = new ifstream();
	inFile->open(fileName, fstream::in);
	int wellIdx = 0; // Keep up with the well index
	if(inFile->is_open())
	{
		// Get the basic information
		while(getNextLine(line, 127))
		{
			if(strcmp(line, "<WELL>") == 0)
			{ 
				getNextLine(line, 127); // Get the next line which is WELLID tag
				if(strcmp(line, "<WELLID>") == 0)
				{
					if(getNextLine(line, 127))// Get the next line with the well ID
					{
						// Create a char array and set m_cpWellID[wellIdx] pointing to it
						m_cpWellID[wellIdx] = new char[strlen(line) + 1]; 
						strcpy(m_cpWellID[wellIdx], line);// Save the well ID
						wellIdx++;
					}
				}
			}
		}
		inFile->close();	// Close the file
		delete inFile;		// Destroy the ifstream object
	}
	else
	{
		cout << "Failed to open file\n";
		cout << "Program terminated.\n\n";
		exit(0);
	}
}

//-----------------------------------
// Get the 0 terminated array of IDs
//-----------------------------------
char **OilFieldDataParser::getWellIDs()
{
	return m_cpWellID;
}

//-----------------------------------
// Get the number of wells
//-----------------------------------
int OilFieldDataParser::getWellCount()
{
	return m_iNumWells;
}

//--------------------------------------------------------------------------
// Get data on the next well
// Args:	*id - pointer to a character array to hold the well ID
//			*operator - pointer to a character array to hold operator name
//			*numSensors - pointer to an int to hold the number of sensors
//							on this well.  
//			***senTypes - pointer to pointer to an array of pointers to char 
//				arrays holding sensor _types.
//--------------------------------------------------------------------------
bool OilFieldDataParser::getWellData(char *id, char *opr, int *numSensors, char ***senTypes)
{
	int wNum = 0;
	char line[128];
	*numSensors = 0; // Init the count
	// Create an array of pointers for max number of sensors
	*senTypes = new char*[m_iNumSensors];

	// Reopen the file
	inFile = new ifstream();
	inFile->open(m_sFileName, fstream::in);
	if(inFile->is_open())
	{
		// Read to the the current well count
		while(getNextLine(line, 127))
		{
			if(strcmp(line, "<WELL>") == 0) // Got one
			{
				if(wNum == m_iNextWellNumber)
				{
					// Get data on this one
					while(getNextLine(line, 127))
					{
						// Get the ID
						if(strcmp(line, "<WELLID>") == 0)
						{
							if(getNextLine(line, 127))
							{
								strcpy(id, line); // Set the well ID
							}
							else
								return false; // Oops!
						}
						else if(strcmp(line, "<OPERATOR>") == 0)
						{
							if(getNextLine(line, 127))
							{
								strcpy(opr, line); // Set the operator name
							}
							else
								return false; // Oops!
						}
						else if(strcmp(line, "<SENSOR>") == 0)
						{
							getNextLine(line, 127); // Read sensor type
							// Create a char array for the next pointer to access
							(*senTypes)[*numSensors] = new char[strlen(line) + 1];
							// Copy the string into that array
							strcpy((*senTypes)[*numSensors], line);
							(*numSensors)++; // Increment the counter
						}
						else if(strcmp(line, "</WELL>") == 0)
						{
							m_iNextWellNumber++; // Increment for next call to this function
							inFile->close();
							delete inFile; // Delete the istream object not the file
							return true; // Got it
						}
					} // end while
				} // end if(wNum == nextWell)
				else
				{
					wNum++; // Check the next one
				}
			}
		}
		inFile->close();
		delete inFile; // Delete the istream object not the file
	} // end if file open
	return false; // If we get here we have got all the wells

}

//----------------------------------------------------------------------------------
// Get data on the next sensor
// Args:	type - Pointer to char array into which the Sensor type will be copied.
//			className - Pointer to char array into which the Sensor classification
//							will be copied.
//			displayName - Pointer to char array into which the name to display in
//							outputs will be copied.
//			min - Pointer to double into which the minimum reading for this sensor
//							will be copied.
//			minUdf - Pointer to bool which will be set to true if the minimum value
//							is undefined.
//			max - Pointer to double into which the maximum reading for this sensor
//							will be copied.
//			maxUdf - Pointer to bool which will be set to true if the maximum value
//							is undefined.
//			_step - Pointer to double into which the increment _step for this sensor's
//							readings will be copied.
//			units - Pointer to char array into which the name of the units this
//							sensor is measuring will be copied.
//			unitAbbrev - Pointer to char array into which the abbreviation for the
//							units this sensor is measuring will be copied.
//			dataGenAlg - Pointer to char array into which the name of the data
//							generation algorithm for this sensor will be copied.
//			linkSenType - Pointer to char array into which the name of the _link-to
//							sensor will be copied if appropriate.
//----------------------------------------------------------------------------------
bool OilFieldDataParser::getSensorData(char *type, char *className, 
		char *displayName, double *min, bool *minUdf, double *max, 
		bool *maxUdf, double *step, char *units, char *unitAbbrev, 
		char *dataGenAlg, char *linkSenType)
{
	char line[128];

	// Reopen the file
	inFile = new ifstream();
	inFile->open(m_sFileName, fstream::in);
	if(inFile->is_open())
	{
		// Search for the start of the sensors
		bool found = false;
		do
		{
			getNextLine(line, 127);
			if(strcmp(line, "<SENSORS>") == 0)
				found = true;
		}
		while(!found);

		// Find a sensor definition of this type
		while(getNextLine(line, 127))
		{
			if(strcmp(line, type) == 0) // found it
			{
				// Get data on this one
				while(getNextLine(line, 127))
				{
					if(strcmp(line, "<CLASS>") == 0)
					{
						if(getNextLine(line, 127))
						{
							strcpy(className, line); 
						}
						else
							return false; // Oops!
					}
					// Get the sensor display name
					else if(strcmp(line, "<DISPLAYNAME>") == 0)
					{
						if(getNextLine(line, 127))
						{
							strcpy(displayName, line); 
						}
						else
							return false; // Oops!
					}
					// Get the sensor minimum value
					else if(strcmp(line, "<MINVALUE>") == 0)
					{
						if(getNextLine(line, 127))
						{
							if(strcmp(line, "UNDEFINED") == 0)
							{
								*min = 0.0;
								*minUdf = true;
							}
							else
							{
								*min = atof(line); 
								*minUdf = false;
							}
						}
						else
							return false; // Oops!
					}
					// Get the sensor minimum value
					else if(strcmp(line, "<MAXVALUE>") == 0)
					{
						if(getNextLine(line, 127))
						{
							if(strcmp(line, "UNDEFINED") == 0)
							{
								*max = 0.0;
								*maxUdf = true;
							}
							else
							{
								*max = atof(line); 
								*maxUdf = false;
							}
						}
						else
							return false; // Oops!
					}
					// Get the sensor _step value
					else if(strcmp(line, "<STEPVALUE>") == 0)
					{
						if(getNextLine(line, 127))
						{
							if(strcmp(line, "UNDEFINED") == 0)
							{
								*step = 1.0;
							}
							else
							{
								*step = atof(line); 
							}
						}
						else
							return false; // Oops!
					}
					// Get the sensor units
					else if(strcmp(line, "<UNITS>") == 0)
					{
						if(getNextLine(line, 127))
						{
							strcpy(units, line); 
						}
						else
							return false; // Oops!
					}
					// Get the sensor units abbreviation
					else if(strcmp(line, "<UNITABBREVIATION>") == 0)
					{
						if(getNextLine(line, 127))
						{
							strcpy(unitAbbrev, line); 
						}
						else
							return false; // Oops!
					}
					// Get the data generation algorithm type
					else if(strcmp(line, "<DATAGENALGORITHM>") == 0)
					{
						if(getNextLine(line, 127))
						{
							strcpy(dataGenAlg, line); 
						}
						else
							return false; // Oops!
					}
					// Get the _link sensor type
					else if(strcmp(line, "<LINK_SENSOR>") == 0)
					{
						if(getNextLine(line, 127))
						{
							strcpy(linkSenType, line); 
						}
						else
							return false; // Oops!
					}
					else if(strcmp(line, "</SENSOR_TYPE>") == 0)
					{
						inFile->close();	// We're done
						delete inFile; // Delete the istream object not the file
						return true; // Got one
					}
				} // end while
			} // end if we found the sensor type
		}
		// Done looking so must not have found it
		inFile->close();
		delete inFile; // Delete the istream object not the file
	} // end if file open
	return false; // If we get here we didn't find the sensor type or failed to open file
}

//------------------------------------------------
// Function: getNextLine()
// Purpose: Reads lines from a file and places
//   them in buffer, removing any leading white
//   space.  Skips blank lines. Ignors comment
//   lines starting with <!-- and ending with -->
//   
// Args:  buffer -- char array to read line into.
//        n -- length of buffer.
// Returns: True if a line was successfully read,
//    false if the end of file was encountered.
// Notes: Function provided by instructor.
//------------------------------------------------
bool OilFieldDataParser::getNextLine(char *buffer, int n)
{
    bool    done = false;
	char    tempBuf[128];
	char	*temp;
    while(!done)
    {
        inFile->getline(tempBuf, n); // Read a line from the file

        if(inFile->good())          // If a line was successfully read check it
        {
           if(strlen(tempBuf) == 0)     // Skip any blank lines
               continue;
		   else if(strncmp(tempBuf, "<!--", 4) == 0) // Skip comment lines
			   continue;
           else done = true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(buffer, "");  // Clear the buffer array
            return false;        // Flag end of file
        }
    } // end while
	// Remove white space from end of string
	temp = &tempBuf[strlen(tempBuf)]; // point to closing \0
	temp--; // back up 1 space
	while(isspace(*temp))
	{
		*temp = '\0'; // Make it another NULL terminator
		temp--;  // Back up 1 char
	}
	// Remove white space from front of string
	temp = tempBuf;
	while(isspace(*temp)) temp++; // Skip leading white space
	// Copy remainder of string into the buffer
	strcpy(buffer, temp);
    return true;  // Flag a successful read
}

//------------------------------------------------
// For testing only
//------------------------------------------------
void OilFieldDataParser::printWellData()
{
	// Print information stored in m_cpWellID
	for(int i=0; i<m_iNumWells; i++)
		cout << m_cpWellID[i] << endl;
}




