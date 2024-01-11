import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);

        int max=Integer.MIN_VALUE;
        int n=scanner.nextInt();
        int k=scanner.nextInt();
        int[] input = new int[n];

        for(int i=0;i<n;i++) input[i]=scanner.nextInt();

        for(int i=0;i<n-k+1;i++){
            int temp=0;
            for(int j=i;j<i+k;j++){
                temp+=input[j];
            }

            if(temp>max) max=temp;
        }

        System.out.println(max);
        scanner.close();
    }
}