package com.company;

public class Main {

    public static void main(String[] args) {
        int droid_quantity = 4;
        Droid[] OOM = new Droid[droid_quantity];
        for (int i = 0; i < droid_quantity; i++) {
            OOM[i] = new Droid();
        }

        OOM[0].SetPower(true);
        OOM[0].AssignPersonalObjective(66);
        OOM[0].PersonalOrderExecution();
        Droid.AssignGeneralObjective(77);
        Droid.GeneralOrderExecution(OOM, true, 0, 2);
        Droid.GetStatus(OOM);
        OOM[1].SetPower(true);
        OOM[1].AssignPersonalObjective(66);
        Droid.GeneralOrderExecution(OOM, false, 0, 2);
        Droid.GetStatus(OOM);

        Droid.ClearCount();
        OOM = null;

        try {
            if (Droid.GetCount() != 0)
                throw new DroidsException("Old droid squad isn't deleted yet!");
        }
        catch(DroidsException ex) {
            System.out.println(ex.what());
        }

        int droid_quantity_i = 2;
        int droid_quantity_j = 3;

        Droid[][] OOP = new Droid[droid_quantity_i][droid_quantity_j];

        for (int i = 0; i < droid_quantity_i; i++) {
            for (int j = 0; j < droid_quantity_j; j++) {
                OOP[i][j] = new Droid();
            }
        }


        OOP[0][0].SetPower(true);
        OOP[0][1].SetPower(true);
        OOP[0][2].SetPower(true);
        OOP[1][0].SetPower(true);
        OOP[1][1].SetPower(true);


        Droid.GetStatus(OOP, droid_quantity_i, droid_quantity_j);
    }
}
