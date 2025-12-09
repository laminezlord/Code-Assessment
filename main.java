import java.util.Scanner;

public class main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter USSD Code: ");
        String code = sc.nextLine();

        if (!code.equals("*123#")) {
            System.out.println("Invalid USSD Code");
            return;
        }

        System.out.println("\nWelcome to XYZ Network");
        System.out.println("1. Airtime Services");
        System.out.println("2. Data Services");
        System.out.println("3. Account Information");
        System.out.println("4. Exit");
        System.out.print("Select an option: ");
        int mainChoice = sc.nextInt();

        switch (mainChoice) {

            case 1:
                System.out.println("\nAirtime Services");
                System.out.println("1. Recharge Airtime");
                System.out.println("2. Borrow Airtime");
                System.out.println("3. Transfer Airtime");
                System.out.println("4. Back");
                System.out.print("Select: ");
                int air = sc.nextInt();

                switch (air) {
                    case 1: System.out.println("You selected Recharge Airtime"); break;
                    case 2: System.out.println("You selected Borrow Airtime"); break;
                    case 3: System.out.println("You selected Transfer Airtime"); break;
                    case 4: System.out.println("Returning to Main Menu..."); break;
                    default: System.out.println("Invalid Airtime Option");
                }
                break;

            case 2:
                System.out.println("\nData Services");
                System.out.println("1. Buy Data Plan");
                System.out.println("2. Check Data Balance");
                System.out.println("3. Get Data Bonus");
                System.out.println("4. Back");
                System.out.print("Select: ");
                int data = sc.nextInt();

                switch (data) {
                    case 1: System.out.println("You selected Buy Data Plan"); break;
                    case 2: System.out.println("You selected Check Data Balance"); break;
                    case 3: System.out.println("You selected Get Data Bonus"); break;
                    case 4: System.out.println("Returning to Main Menu..."); break;
                    default: System.out.println("Invalid Data Option");
                }
                break;

            case 3:
                System.out.println("\nAccount Information");
                System.out.println("1. Check Airtime Balance");
                System.out.println("2. Check Bonus Balance");
                System.out.println("3. View SIM Registration Status");
                System.out.println("4. Back");
                System.out.print("Select: ");
                int acc = sc.nextInt();

                switch (acc) {
                    case 1: System.out.println("You selected Check Airtime Balance"); break;
                    case 2: System.out.println("You selected Check Bonus Balance"); break;
                    case 3: System.out.println("You selected SIM Registration Status"); break;
                    case 4: System.out.println("Returning to Main Menu..."); break;
                    default: System.out.println("Invalid Account Option");
                }
                break;

            case 4:
                System.out.println("Exiting...");
                break;

            default:
                System.out.println("Invalid Main Menu Option");
        }
    }
}
