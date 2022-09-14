import java.io.*;
import java.util.*;



class Solution {

    static int securitiesBuying(int z, ArrayList<Integer> security_value)
    {
        int no_of_stocks=0;
          // participants code here
        class Pair<T,Q>{
            public T first;
            public Q second;
            Pair(T first,Q second){
                this.first = first;
                this.second = second;
            }
        }
        int n = security_value.size();
        PriorityQueue<Pair<Integer,Integer>> pq = new
         PriorityQueue <>(n,
            new Comparator<Pair<Integer,Integer>>(){
                @Override
                public int compare(Pair<Integer,Integer> p1
                ,Pair<Integer,Integer> p2){
                    return p1.second - p2.second;
                }
           });
        for(int i = 0; i<n;i++){
            int data = security_value.get(i);
            pq.add(new Pair<Integer,Integer>(i+1,data));   
        }
        int each_day_stock = 0;//number of stock it is possible to buy with the amount of money and with no consideration on the stock limit
        int number_of_stock_bought_optimum = 0;;
        while(!pq.isEmpty()){
            Pair<Integer,Integer> top = new
             Pair<Integer,Integer>(pq.peek().first,pq.peek().second);
            //<quantity,price>
            each_day_stock = z / top.second;
            if(each_day_stock>top.first){
                z = z - top.first * top.second;
                no_of_stocks += top.first;
            }
            else{
                z = z - each_day_stock*top.second;//unimportant
                no_of_stocks += each_day_stock;
                break;
            }
            
            pq.remove();
        }

        return no_of_stocks;
    }
 

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int z = scanner.nextInt();
        scanner.nextLine();
        String str = scanner.nextLine();
        String[] price_str =str.split(" ");  
        ArrayList<Integer> security_value =new ArrayList<Integer>();
        for (String s: price_str){security_value.add(Integer.parseInt(s));}
        int no_of_stocks_purchased = securitiesBuying(z,security_value);
        System.out.println(no_of_stocks_purchased);

        
    }
}
