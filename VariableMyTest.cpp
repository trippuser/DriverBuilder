#pragma once
#include "VariableBase.h"
class VariableMyTest
	: public VariableBase<float>
{
public:
	VariableMyTest(ProtocolManager * protocolManager) : VariableBase<float>(protocolManager){
		this->variableInfo.name = "VariableMyTest";
		this->variableInfo.dataType = DataType::FLOAT;
		this->variableInfo.oid = NULL;
		this->variableInfo.purpose = NULL;
		this->variableInfo.quickStatus = 0;
		this->variableInfo.lineNumber = 0;
		this->variableInfo.suffix = NULL;
		this->variableInfo.defaultGauge = 0;
		this->variableInfo.logTolerance = 0;
		this->variableInfo.dependentVariables = new vector<string>();
	};
	~VariableMyTest() {};


protected:
	float formula(byte * value) {return (float)B2UI(REV(value)) / TABLE(B2UI(REV(value)), 1, "99|1,999|10,9999|100,99999|1000");}
	void unknownFormula(byte * value) { variableInfo.flags.hasUnknownFormula = (false);}
	void minValueFormula() { this->variableInfo.flags.hasMin = (false);}
	void maxValueFormula() {this->variableInfo.flags.hasMax = (false);}
	void displayTextFormula() {variableInfo.displayText = (false);};
	void displayMeterFormula() {variableInfo.displayMeter = (false);}
	void displayLogFormula() { variableInfo.displayLog = (false); }
	void displaySNMPFormula() { variableInfo.displaySNMP = (false); }
	void scaleMinimumFormula(){this->variableInfo.flags.hasScaleMinimum = (false);}
	void normalHighFormula() {this->variableInfo.flags.hasNormalHigh = (false);}
	void criticalLowFormula() {this->variableInfo.flags.hasCriticalLow = (false);}
	void criticalHighFormula() {this->variableInfo.flags.hasCriticalHigh = (false);}
	void normalLowFormula() { this->variableInfo.flags.hasNormalLow = (false);}
	void scaleMaximumFormula() {this->variableInfo.flags.hasScaleMaximum = (false);}
	void masterFormula(byte *masterData, float value) {this->variableInfo.flags.isMasterVaribale = (false); NULL}
};

