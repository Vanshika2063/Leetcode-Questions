import java.util.Scanner;

public class ArrangingCoins441 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        //int a = in.nextInt();
        System.out.println(arrangeCoins(2147483643));
    }
    static int arrangeCoins(int n) {
        int start = 1, end = n;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long coins = ((long) mid * (mid + 1)) / 2;
            if (coins == n)
                return mid;
            else if (coins < n)
                start = mid + 1;
            if (coins > n) {
                if (start == end)
                    return mid - 1;
                else
                    end = mid - 1;
            }
        }
        return end;
    }
}
