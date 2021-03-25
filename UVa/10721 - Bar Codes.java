import java.util.Scanner;

class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);       
        long bc[][][] = new long[51][51][51];

        for (int i = 0; i < 51; ++i) bc[0][0][i] = 1;

        for (int i = 1; i < 51; ++i) for (int j = 1; j < 51; ++j) for (int k = 1; k < 51; ++k) 
            for (int x = 1; x <= i && x <= k; ++x) bc[i][j][k] += bc[i - x][j - 1][k];

        int n, k, m;
        while (sc.hasNextInt())
        {
            n = sc.nextInt();
            k = sc.nextInt();
            m = sc.nextInt();
            System.out.println(bc[n][k][m]);
        } 
    }
}
