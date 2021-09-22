import java.util.Scanner;

public class RREF_Algorithm{
   public static void main(String[] args){
      Scanner s = new Scanner(System.in);
      
      int[][] A = {{2,1,1},
                      {0,3,0},
                      {3,1,2}};
                     
   }
   
   public void oneIfy(int[][] input, int column){
      for(int i = 0; i < input.length; i++){
         A[i][column] /= A[column][column];
      }
      return;
   }
}
