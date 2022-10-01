import java.util.Scanner;

class Player
{
    static int age,total;
    static String name;
    static String type;
    static String role;
}

class CricketPlayer extends Player
{
    public int c = 0;

    void getData()
    {
        Scanner meet = new Scanner(System.in);

        System.out.print("Enter Player Name : ");
        name = meet.nextLine();

        System.out.print("Enter Player Age : ");
        age = meet.nextInt();

        System.out.print("Enter Player Type (Batsman or Bowler) : ");
        type = meet.next();

        if(type == "Bowler" || type == "bowler")
        {
            c++;
        }
     }

    void Bowler_Info()
    {
        if(c>0)
        {
            Scanner meet = new Scanner(System.in);

            System.out.print("Enter Bowler Player Type  (Fast / Spin / Medium) : ");
            role = meet.next();
        }

    }
}

class batsman extends CricketPlayer
{
    void getCar()
    {
        Scanner meet = new Scanner(System.in);

        System.out.print("Enter Player Carrer Total Match : ");
        total = meet.nextInt();

    }

    void print1()
    {
        System.out.println("Player Type : " + type);
        System.out.println("Carrer Total Match : " + total);
    }

}

class Bowler extends CricketPlayer
{

    void print()
    {
        System.out.println("Player Name : " + name);
        System.out.println("Player Age : " + age);

        if(c == 1)
  
