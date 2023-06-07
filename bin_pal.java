import java.io.*;

public class bin_pal {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        String bin = Integer.toBinaryString(n);

        String rev = new StringBuilder(bin).reverse().toString();

        if (bin.equals(rev)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }


    }
}