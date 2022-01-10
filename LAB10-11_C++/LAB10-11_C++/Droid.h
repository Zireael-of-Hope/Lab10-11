#pragma once
#include <iostream>
#include <string>
#include <Color.h>
using namespace std;

class Droid
{
private:
	static int count;
	static int general_order;
	int personal_order;
	int executing_order;
	string id;
	bool isOnline;
	bool isGeneralOrderExecuting;
	string* special_tools;
	int quantity_tools;
public:
	Droid();
	/*Droid(bool isOnline);
	Droid(bool isOnline, int personal_order, int executing_order, bool isGeneralOrderExecuting);
	Droid(const Droid& other);*/
	~Droid();

	static void GetStatus(Droid OOM[]);
	static void GetStatus(Droid* OOM[], int droid_quantity_i, const int droid_quantity_j);
	static int GetCount();

	static bool AssignGeneralObjective(int order_number);
	static bool GeneralOrderExecution(Droid OOM[], bool isExecuting, int fromIndex, int toIndex);
	static int GetAssignedHGeneralObjective();

	bool AssignPersonalObjective(int order_number);
	bool PersonalOrderExecution();
	int GetAssignedPersonalObjective();

	string GetID();
	void SetPower(bool isPowerON);
	bool GetPowerStatus();

	void AddSpeciallTool(string new_tool);
	bool DeleteSpeciallTool(string deleting_tool_name);
	void GetSpecialTools();

	static void AddDroid(Droid*& OOM, int& droid_quantity);

	Droid& operator= (const Droid& other);
};

