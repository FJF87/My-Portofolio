import java.util.Scanner;;

public class problemGenerator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testCase = input.nextInt();

        for(int i = 0; i < testCase; i++){
            int problemBank = input.nextInt();
            int match = input.nextInt();
            String problemString = input.next();
            int[] amountProblemHave = {0, 0, 0, 0, 0, 0, 0};

            for(int j = 0; j  < problemString.length(); j++) {
                if (problemString.charAt(j) == 'A') {
                    amountProblemHave[0]++;
                } else if (problemString.charAt(j) == 'B') {
                    amountProblemHave[1]++;
                } else if (problemString.charAt(j) == 'C') {
                    amountProblemHave[2]++;
                } else if (problemString.charAt(j) == 'D') {
                    amountProblemHave[3]++;
                } else if (problemString.charAt(j) == 'E') {
                    amountProblemHave[4]++;
                } else if (problemString.charAt(j) == 'F') {
                    amountProblemHave[5]++;
                } else if (problemString.charAt(j) == 'G') {
                    amountProblemHave[6]++;
                }
            }

            int problemToBeAdded = 0;
            for (int k : amountProblemHave) {
                if (k < match) {
                    problemToBeAdded += (match - k);
                }
            }
            System.out.println(problemToBeAdded);
        }
    }
}
