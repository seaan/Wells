/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Sensor.cpp
*   Author: Sean Widmier
*   Desc: An oil rigs simulation that logs and updates various sensors.
*   Date: Date file was submitted to the instructor
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "stdafx.h"
#include "Sensor.h"

/**
 * Constructs Sensor object, ises arguments to set member variables.
 * @param
 */
Sensor::Sensor(SensorConfig *sensor_data) {
    this->_config = sensor_data;

    this->_value = this->_config->_init_value;
    this->_last_value = this->_config->_init_value;
    this->_enabled = true; // starts out true, user will enable/disable
}

/**
 * Destructor for sensor.
 */
Sensor::~Sensor() {
    delete _config;
}

/**
 * Generates a random number for _value and sets it.
 */
void Sensor::update() {
    this->_value = this->_config->_gen->generate(_config->_min, _config->_max, _config->_step, this->_value, this->_link);
}

/**
 * Sets enabled or disabled status for sensor status monitoring.
 * @param e new enabled state for the sensor
 */
void Sensor::setEnabled(bool e) {
    this->_enabled = e;
}

/**
 * Accessor for enabled or disabled status for sensor status monitoring.
 * @return boolean indicating enabled status
 */
bool Sensor::getEnabled() {
    return this->_enabled;
}

/**
 * Accessor for display name of sensor.
 * @return sensor display name
 */
char *Sensor::getDisplayName() {
    return this->_config->_display_name;
}

/**
 * Accessor for sensor unit abbreviation.
 * @return sensor unit abbreviation
 */
char *Sensor::getAbbrev() {
    return this->_config->_abbrev;
}

/**
 * Acccessor for sensor type.
 * @return sensor type
 */
char *Sensor::getType() {
    return this->_config->_type;
}

/**
 * Accessor for sensor value.
 * @return sensor value
 */
double Sensor::getValue() {
    return this->_value;
}

/**
 *
 * @return
 */
char *Sensor::getLinkInfo() {
    return this->_config->_link_info;
}

/**
 *
 * @param link
 */
void Sensor::setLink(Sensor *link) {
    this->_link = link;
}

/**
 *
 * @return
 */
bool Sensor::valueChanged() {
    return this->_last_value != this->_value;
}

//-----------------------------------------
// Draw the sensor
//-----------------------------------------
void Sensor::drawSensor(CDC *cdc, int ulx, int uly, int lrx, int lry)
{
	CBrush *oldBrush = NULL;
	CRect textRect;
	char line[32];
	int rVal;

	if(this->_enabled)
	{
		CBrush bgBrush, fgBrush;
		bgBrush.CreateSolidBrush(RGB(0,0,0));	// Create brush from predefined background color
		fgBrush.CreateSolidBrush(RGB(0,0,0));	// Create brush from predefined foreground color
		
		// Erase what was there
		oldBrush = (CBrush *)cdc->SelectObject(&bgBrush);
		cdc->Rectangle(ulx, uly, lrx, lry);
		// Print the sensor name at the top
		cdc->SetBkColor(RGB(0,0,0)); // Set text background
		cdc->SetTextColor(RGB(255,255,255)); // Set text color
		textRect.left = ulx;
		textRect.right = lrx;
		textRect.top = uly + 5;
		textRect.bottom = uly + 20;
		// Draw text args: name, -1 means compute length from char array in arg 1,
		//                 rect is rectangle to draw in, DT_CENTER means center in the rect
		cdc->DrawText(this->_config->_display_name, -1, textRect, DT_CENTER);
		// Print the sensor abbreviation at the bottom
		textRect.top = lry - 20;
		textRect.bottom = textRect.top + 20;
		cdc->DrawText(this->_config->_abbrev, -1, textRect, DT_CENTER);
		// Center the current reading text
		textRect.top = uly + ((lry - uly) / 2) - 10;
		textRect.bottom = textRect.top + 20;
		sprintf(line, "%.1f", this->_value);
		cdc->DrawText(line, -1, textRect, DT_CENTER);
		// Clean up before exiting
		cdc->SelectObject(oldBrush);
		bgBrush.DeleteObject();	// Destroy the brush
		fgBrush.DeleteObject();	// Destroy the brush
	}
	else
	{
		// if this one is not monitored then just draw a white rectangle
		oldBrush = (CBrush *)cdc->SelectStockObject(WHITE_BRUSH);
		cdc->Rectangle(ulx, uly, lrx, lry);
		// Clean up before exiting
		cdc->SelectObject(oldBrush);
	}
}

