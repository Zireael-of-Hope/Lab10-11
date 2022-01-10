#include "Droid.h"

int Droid::count = 0;
int Droid::general_order = 0;

Droid::Droid()
{
	id = "OOM-" + to_string(count + 4577);
	count++;
	isOnline = false;
	personal_order = 0;
	executing_order = 0;
	isGeneralOrderExecuting = false;
	quantity_tools = 0;
	special_tools = nullptr;
}

//Droid::Droid(bool isOnline)
//{
//	id = "OOM-" + to_string(count + 4577);
//	count++;
//	this->isOnline = isOnline;
//	personal_order = 0;
//	executing_order = 0;
//	isGeneralOrderExecuting = false;
//}
//
//Droid::Droid(bool isOnline, int personal_order, int executing_order, bool isGeneralOrderExecuting)
//{
//	id = "OOM-" + to_string(count + 4577);
//	count++;
//	this->isOnline = isOnline;
//	this->personal_order = personal_order;
//	this->executing_order = executing_order;
//	this->isGeneralOrderExecuting = isGeneralOrderExecuting;
//}
//
//Droid::Droid(const Droid& other)
//{
//	id = other.id;
//	count++;
//	isOnline = other.isOnline;
//	personal_order = other.personal_order;
//	executing_order = other.executing_order;
//	isGeneralOrderExecuting = other.isGeneralOrderExecuting;
//	quantity_tools = other.quantity_tools;
//	if (other.special_tools == nullptr)
//		special_tools = nullptr;
//	else {
//		special_tools = new string[quantity_tools];
//		for (int i = 0; i < quantity_tools; i++)
//			special_tools[i] = other.special_tools[i];
//	}
//}

Droid::~Droid()
{
	if (special_tools != nullptr)
		delete[] special_tools;
	count--;
}

void Droid::GetStatus(Droid OOM[])
{
	cout << "General Order: " << general_order << "\n" << endl;
	for (int i = 0; i < Droid::count; i++) {
		if (OOM[i].isOnline)
			SetColor(2, 0);
		else SetColor(4, 0);
		cout << "Droid " << OOM[i].id << " status: ";
		if (OOM[i].isOnline)
			cout << "Online ";
		else
			cout << "Offline";
		cout << " | Executing order: " << OOM[i].executing_order;
		if (OOM[i].executing_order == 0)
			cout << " ";
		cout << " | Personal Order: " << OOM[i].personal_order;
		if (OOM[i].personal_order == 0)
			cout << " ";
		cout << " Special Tools: ";
		if (OOM[i].quantity_tools == 0)
			cout << "none";
		else
			for (int j = 0; j < OOM[i].quantity_tools; j++) {
				cout << OOM[i].special_tools[j] << " ";
			}
		cout << endl;
	}
	SetColor(15, 0);
}

void Droid::GetStatus(Droid* OOM[], int droid_quantity_i, const int droid_quantity_j)
{
	cout << "General Order: " << general_order << "\n" << endl;

	for (int i = 0; i < droid_quantity_i; i++) {
		SetColor(15, 0);
		cout << "Squad: " << i+1 << endl;
			for (int j = 0; j < droid_quantity_j; j++) {
				if (OOM[i][j].isOnline)
					SetColor(2, 0);
				else SetColor(4, 0);
				cout << "  Droid " << OOM[i][j].id << " status: ";
				if (OOM[i][j].isOnline)
					cout << "Online ";
				else
					cout << "Offline";
				cout << " | Executing order: " << OOM[i][j].executing_order;
				if (OOM[i][j].executing_order == 0)
					cout << " ";
				cout << " | Personal Order: " << OOM[i][j].personal_order;
				if (OOM[i][j].personal_order == 0)
					cout << " ";
				cout << " Special Tools: ";
				if (OOM[i][j].quantity_tools == 0)
					cout << "none";
				else
					for (int k = 0; k < OOM[i][j].quantity_tools; k++) {
						cout << OOM[i][j].special_tools[k] << " ";
					}
				cout << endl;
			}
	}
	SetColor(15, 0);
}

int Droid::GetCount()
{
	return count;
}

bool Droid::AssignGeneralObjective(int order_number)
{
	if (order_number != 66 && order_number != 77 && order_number != 0)
		return false;
	else {
		Droid::general_order = order_number;
		return true;
	}
}

bool Droid::GeneralOrderExecution(Droid OOM[], bool isExecuting, int fromIndex, int toIndex)
{
	if (fromIndex < 0 || toIndex > count || fromIndex > count || toIndex < 0) {
		return false;
	}
	else {
		if (isExecuting)
			for (int i = fromIndex; i <= toIndex; i++)
				OOM[i].executing_order = Droid::general_order;
		else
			for (int i = fromIndex; i <= toIndex; i++)
				OOM[i].executing_order = OOM[i].personal_order;
		return true;
	}
}

int Droid::GetAssignedHGeneralObjective()
{
	return general_order;
}

bool Droid::AssignPersonalObjective(int order_number)
{
	if (order_number != 66 && order_number != 77 && order_number != 0)
		return false;
	else {
		personal_order = order_number;
		return true;
	}
}

string Droid::GetID()
{
	return id;
}

void Droid::SetPower(bool isPowerON)
{
	isOnline = isPowerON;
}

bool Droid::GetPowerStatus()
{
	return isOnline;
}

void Droid::AddSpeciallTool(string new_tool)
{
	int i;
	string* new_special_tools = new string[quantity_tools + 1];
	for (i = 0; i < quantity_tools; i++)
		new_special_tools[i] = special_tools[i];
	new_special_tools[quantity_tools] = new_tool;
	delete[] special_tools;
	special_tools = new_special_tools;
	quantity_tools++;
}

bool Droid::DeleteSpeciallTool(string deleting_tool_name)
{
	int i;
	bool is_tool_found = false;
	string* new_special_tools;

	for (i = 0; i < quantity_tools; i++) {
		if (special_tools[i] == deleting_tool_name) {
			for (i; i < quantity_tools - 1; i++)
				special_tools[i] = special_tools[i + 1];
			new_special_tools = new string[quantity_tools - 1];
			for (i = 0; i < quantity_tools - 1; i++)
				new_special_tools[quantity_tools - 1] = special_tools[i];
			delete[] special_tools;
			special_tools = new_special_tools;
			quantity_tools--;
			return true;
			break;
		}
	}
	return false;
}

void Droid::GetSpecialTools()
{
	if (quantity_tools != 0) {
		cout << "Droid's special tools: " << endl;
		for (int i = 0; i < quantity_tools; i++) {
			cout << "  " << special_tools[i] << endl;
		}
	}
	else {
		cout << "Droid doest have any tools." << endl;
	}
}

void Droid::AddDroid(Droid*& OOM, int& droid_quantity)
{
	int i;
	Droid* new_OOM = new Droid[droid_quantity + 1];
	new_OOM[droid_quantity].id = new_OOM[0].id;
	for (i = 0; i < droid_quantity; i++)
		new_OOM[i] = OOM[i];
	delete[] OOM;
	OOM = new_OOM;
	droid_quantity++;
}

Droid& Droid::operator=(const Droid& other)
{
	id = other.id;
	isOnline = other.isOnline;
	personal_order = other.personal_order;
	executing_order = other.executing_order;
	isGeneralOrderExecuting = other.isGeneralOrderExecuting;
	quantity_tools = other.quantity_tools;
	if (other.special_tools == nullptr)
		special_tools = nullptr;
	else {
		special_tools = new string[quantity_tools];
		for (int i = 0; i < quantity_tools; i++)
			special_tools[i] = other.special_tools[i];
	}
	return *this;
}

bool Droid::PersonalOrderExecution()
{
	if (isGeneralOrderExecuting)
		return false;
	else {
		executing_order = personal_order;
		return true;
	}
}

int Droid::GetAssignedPersonalObjective()
{
	return personal_order;
}