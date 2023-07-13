import java.util.*;
class MajorityNumber {
    public static void main(String args[]){
        int a[] = {2,2,3,2,3,3,2,4,5,5,5,5,5,4,5,5,5,5,5,4};
        Arrays.sort(a);
        int running_number = a[0];
        
        int count = 0;
        int n = a.length;
        for (int i=0;i<n;i++){
            int current_number = a[i];
            if (running_number==current_number){
                count++;
            } else {
                if (count>n/2) {
                    System.out.print(running_number+" is the majority number");
                    break;
                }
                count = 1;
                running_number = current_number;
            }
        }
    }
}