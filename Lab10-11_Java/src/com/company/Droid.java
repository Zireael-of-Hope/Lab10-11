package com.company;

public class Droid {
    private static int count;
    private static int general_order;
    private int personal_order;
    private int executing_order;
    private int id;
    private boolean isOnline;
    private boolean isGeneralOrderExecuting;

    public Droid() {
        id = count + 4577;
        count++;
        isOnline = false;
        personal_order = 0;
        executing_order = 0;
        isGeneralOrderExecuting = false;
    }

    public static void GetStatus(Droid[] OOM) {
        System.out.println("General Order: " + general_order + "\n");
        for (int i = 0; i < Droid.count; i++) {
            System.out.print("Droid " + OOM[i].id + " status: ");
            if (OOM[i].isOnline)
                System.out.print("Online ");
            else
                System.out.print("Offline");
            System.out.print(" | Executing order: " + OOM[i].executing_order);
            if (OOM[i].executing_order == 0)
                System.out.print(" ");
            System.out.println(" | Personal Order: " + OOM[i].personal_order);
        }
    }
    public static void GetStatus(Droid[][] OOM, int droid_quantity_i, int droid_quantity_j) {
        System.out.println("General Order: " + general_order + "\n");
        for (int i = 0; i < droid_quantity_i; i++) {
            System.out.println("Squad: " + (i + 1));
            for (int j = 0; j < droid_quantity_j; j++) {
                System.out.print("Droid " + OOM[i][j].id + " status: ");
                if (OOM[i][j].isOnline)
                    System.out.print("Online ");
                else
                    System.out.print("Offline");
                System.out.print(" | Executing order: " + OOM[i][j].executing_order);
                if (OOM[i][j].executing_order == 0)
                    System.out.print(" ");
                System.out.println(" | Personal Order: " + OOM[i][j].personal_order);
            }
        }
    }
    public static int GetCount() {
        return count;
    }

    public static void ClearCount() {
        count = 0;
    }

    public static boolean AssignGeneralObjective(int order_number) {
        if (order_number != 66 && order_number != 77 && order_number != 0)
            return false;
        else {
            Droid.general_order = order_number;
            return true;
        }
    }
    public static boolean GeneralOrderExecution(Droid[] OOM, boolean isExecuting, int fromIndex, int toIndex) {
        if (fromIndex < 0 || toIndex > count || fromIndex > count || toIndex < 0) {
            return false;
        }
        else {
            if (isExecuting)
                for (int i = fromIndex; i <= toIndex; i++)
                    OOM[i].executing_order = Droid.general_order;
            else
                for (int i = fromIndex; i <= toIndex; i++)
                    OOM[i].executing_order = OOM[i].personal_order;
            return true;
        }
    }
    public static int GetAssignedHGeneralObjective() {
        return general_order;
    }

    public boolean AssignPersonalObjective(int order_number) {
        if (order_number != 66 && order_number != 77 && order_number != 0)
            return false;
        else {
            personal_order = order_number;
            return true;
        }
    }
    public boolean PersonalOrderExecution() {
        if (isGeneralOrderExecuting)
            return false;
        else {
            executing_order = personal_order;
            return true;
        }
    }
    public int GetAssignedPersonalObjective() {
        return personal_order;
    }

    public int GetID() {
        return id;
    }
    public void SetPower(boolean isPowerON) {
        isOnline = isPowerON;
    }
    public boolean GetPowerStatus() {
        return isOnline;
    }
}
