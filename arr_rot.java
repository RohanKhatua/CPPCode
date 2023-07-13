import java.util.Scanner;

class ArrayRotate{

    static int[] leftRotate(int []a, int rotations){

        for (int j=0;j<rotations;j++) {
        int first = a[0];
        int n = a.length;
        for (int i=1;i<=n-1;i++){
            a[i-1] = a[i];
        }
        a[n-1] = first;
        }

        return a;
    }

    static void printArray(int[] a) {
        for (int i=0;i<a.length;i++){
            System.out.print(a[i]+" ");
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[]= new int[n];
        for (int i=0;i<n;i++){
            a[i]=sc.nextInt();            
        }
        int num_rotates = 2;
        int [] rotated = leftRotate(a, num_rotates);
        printArray(rotated);
    }
}