import java.util.Scanner;

class Main {

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int number = input.nextInt();
        String stones = input.nextLine();
        char[] arrStones = stones.toCharArray();
        System.out.println("hello");
        int remove = 0;
        int i;
        char toCompare = arrStones[0];
        for(i=0;i<number-1;i++)
        {
            if(toCompare == arrStones[i+1])
            {
                remove++;
            }
            else
            {
                toCompare = arrStones[i+1];
            }
        }
        System.out.println(remove);
    }

}
