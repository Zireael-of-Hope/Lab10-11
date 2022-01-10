using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1011_CS
{
    internal class Droid
    {
        private static int count;
        private static int general_order;
        private int personal_order;
        private int executing_order;
        private int id;
        private bool isOnline;
        private bool isGeneralOrderExecuting;

        public Droid()
        {
            id = count + 4577;
            count++;
            isOnline = false;
            personal_order = 0;
            executing_order = 0;
            isGeneralOrderExecuting = false;
        }

        public static void GetStatus(Droid[] OOM)
        {
            Console.WriteLine("General Order: " + general_order + "\n");
            for (int i = 0; i < Droid.count; i++)
            {
                Console.Write("Droid " + OOM[i].id + " status: ");
                if (OOM[i].isOnline)
                    Console.Write("Online ");
            else
                    Console.Write("Offline");
                Console.Write(" | Executing order: " + OOM[i].executing_order);
                if (OOM[i].executing_order == 0)
                    Console.Write(" ");
                Console.WriteLine(" | Personal Order: " + OOM[i].personal_order);
            }
        }
        public static void GetStatus(Droid[,] OOM, int droid_quantity_i, int droid_quantity_j)
        {
            Console.WriteLine("General Order: " + general_order + "\n");
            for (int i = 0; i < droid_quantity_i; i++)
            {
                Console.WriteLine("Squad: " + (i + 1));
                for (int j = 0; j < droid_quantity_j; j++)
                {
                    Console.Write("Droid " + OOM[i,j].id + " status: ");
                    if (OOM[i,j].isOnline)
                        Console.Write("Online ");
                else
                        Console.Write("Offline");
                    Console.Write(" | Executing order: " + OOM[i,j].executing_order);
                    if (OOM[i,j].executing_order == 0)
                        Console.Write(" ");
                    Console.WriteLine(" | Personal Order: " + OOM[i,j].personal_order);
                }
            }
        }
        public static int GetCount()
        {
            return count;
        }

        public static void ClearCount()
        {
            count = 0;
        }

        public static bool AssignGeneralObjective(int order_number)
        {
            if (order_number != 66 && order_number != 77 && order_number != 0)
                return false;
            else
            {
                Droid.general_order = order_number;
                return true;
            }
        }
        public static bool GeneralOrderExecution(Droid[] OOM, bool isExecuting, int fromIndex, int toIndex)
        {
            if (fromIndex < 0 || toIndex > count || fromIndex > count || toIndex < 0)
            {
                return false;
            }
            else
            {
                if (isExecuting)
                    for (int i = fromIndex; i <= toIndex; i++)
                        OOM[i].executing_order = Droid.general_order;
                else
                    for (int i = fromIndex; i <= toIndex; i++)
                        OOM[i].executing_order = OOM[i].personal_order;
                return true;
            }
        }
        public static int GetAssignedHGeneralObjective()
        {
            return general_order;
        }

        public bool AssignPersonalObjective(int order_number)
        {
            if (order_number != 66 && order_number != 77 && order_number != 0)
                return false;
            else
            {
                personal_order = order_number;
                return true;
            }
        }
        public bool PersonalOrderExecution()
        {
            if (isGeneralOrderExecuting)
                return false;
            else
            {
                executing_order = personal_order;
                return true;
            }
        }
        public int GetAssignedPersonalObjective()
        {
            return personal_order;
        }

        public int GetID()
        {
            return id;
        }
        public void SetPower(bool isPowerON)
        {
            isOnline = isPowerON;
        }
        public bool GetPowerStatus()
        {
            return isOnline;
        }
    }
}
