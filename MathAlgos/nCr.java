
class Solution {
    import java.util.*;
	static int l[][] = new int[1001][1001];
    static void initialize()
	{

		l[0][0] = 1;
		for (int i = 1; i < 1001; i++) {
			l[i][0] = 1;
			for (int j = 1; j < i + 1; j++) {
				l[i][j] = (l[i - 1][j - 1] + l[i - 1][j]);
			}
		}
	}

	static int nCr(int n, int r)
	{
		return l[n][r];
	}
    
    public static void main(String[] args)
	{
		initialize();
        Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		int r = sc.nextInt();
		System.out.println(nCr(n, r));
	}
}