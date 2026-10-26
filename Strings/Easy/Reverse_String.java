import java.util.Scanner;

public class Reverse_String {
    public static void main(String[] args)
    {
        Scanner sc= new Scanner(System.in);
        if(!sc.hasNextLine())
        {
            sc.close();
            return;
        }

        char[] s=sc.nextLine().toCharArray(); // TC:O(n), SC:O(n)
        Solution sol = new Solution();
        sol.reverseString(s);
        System.out.println(new String(s));
        sc.close();
    }
}

class Solution {
    
    public void reverseString(char[] s) {
        // TC:O(n), SC:O(1)
        for(int i=0;i<s.length/2;i++) // TC:O(n/2)
        {
            char temp=s[i];
            s[i]=s[s.length-i-1];
            s[s.length-i-1]=temp;
        }
    }
}