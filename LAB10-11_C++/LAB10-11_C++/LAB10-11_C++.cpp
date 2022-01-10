#include <iostream>
#include <Droid.h>
#include <conio.h>
#include <Color.h>

int main()
{
    int droid_quantity = 4;
    Droid* OOM = new Droid[droid_quantity];

    OOM[0].SetPower(true);
    OOM[0].AssignPersonalObjective(66);
    OOM[0].PersonalOrderExecution();
    Droid::AssignGeneralObjective(77);
    Droid::GeneralOrderExecution(OOM, true, 0, 2);
    Droid::GetStatus(OOM);
    OOM[0].AddSpeciallTool("Bazooka");
    OOM[0].AddSpeciallTool("Blaster");
    OOM[1].AddSpeciallTool("Bazooka");
    OOM[2].AddSpeciallTool("Blaster");
    OOM[1].SetPower(true);
    OOM[1].AssignPersonalObjective(66);
    Droid::GeneralOrderExecution(OOM, false, 0, 2);
    Droid::AddDroid(OOM, droid_quantity);
    Droid::GetStatus(OOM);

    delete[] OOM;

    try {
        if (Droid::GetCount() != 0)
            throw exception("Old droid squad isn't deleted yet!");
    }
    catch(const exception& ex) {
        cout << ex.what();
    }

    int droid_quantity_i = 4;
    const int droid_quantity_j = 5;


    //Для двумерного массивы не доступен метод добавдения нового дроида
    Droid** OOP = new Droid * [droid_quantity_i];
    for (int i = 0; i < droid_quantity_i; i++) {
        OOP[i] = new Droid[droid_quantity_j];
    }

    OOP[0][0].AddSpeciallTool("Bazooka");
    OOP[0][0].AddSpeciallTool("Blaster");
    OOP[1][0].AddSpeciallTool("Bazooka");
    OOP[2][0].AddSpeciallTool("Blaster");
    OOP[0][1].SetPower(true);
    OOP[0][2].SetPower(true);
    OOP[1][1].SetPower(true);
    OOP[2][1].SetPower(true);
    OOP[3][1].SetPower(true);
    OOP[3][3].SetPower(true);

    Droid::GetStatus(OOP, droid_quantity_i, droid_quantity_j);
}