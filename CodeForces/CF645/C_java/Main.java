import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
    Scanner in = new Scanner(new BufferedInputStream(System.in));
    PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));


    BigInteger getVal(BigInteger y1, BigInteger x1) {
        BigInteger result = x1.multiply(x1.add(BigInteger.ONE))
                .divide(BigInteger.valueOf(2))
                .add(y1.multiply(x1.add(y1).subtract(BigInteger.ONE).add(x1))
                        .divide(BigInteger.valueOf(2)));

        out.println(result);
        return result;
    }

    BigInteger getSum(BigInteger x) {
        return x.multiply(x.multiply(x).add(BigInteger.valueOf(5))).divide(BigInteger.valueOf(6));
    }

    BigInteger getSumRange(BigInteger x, BigInteger start) {
        return getSum(x.add(start).subtract(BigInteger.ONE)).subtract(getSum(start.subtract(BigInteger.ONE)));
    }

    void solve() {
        int T = in.nextInt();
        while(true) {
            BigInteger x1 = in.nextBigInteger();
            BigInteger y1 = in.nextBigInteger();
            BigInteger x2 = in.nextBigInteger();
            BigInteger y2 = in.nextBigInteger();


            if(y1.equals(y2) || x1.equals(x2)) {
                out.println(1);
                continue;
            }

            BigInteger startRange = getSumRange(y2.subtract(y1) ,getVal(x1, y1.add(BigInteger.ONE)).subtract(getVal(x1, y1)));
            BigInteger endRange = getSumRange(x2.subtract(x1) ,getVal(x1.add(BigInteger.ONE), y2).subtract(getVal(x1, y2)));
            
            BigInteger _startRange = getSumRange(x2.subtract(x1) ,getVal(x1.add(BigInteger.ONE), y1).subtract(getVal(x1, y1)));
            BigInteger _endRange = getSumRange(y2.subtract(y1) ,getVal(x2, y1.add(BigInteger.ONE)).subtract(getVal(x2, y1)));
            
            out.println(startRange.toString() + " " + endRange.toString() + " " + _startRange.toString() + " " + _endRange.toString());

            out.println(_endRange.subtract(_startRange).add(startRange).subtract(endRange));
            T --;
            if(T == 0) break;
            out.flush();
        }
        out.flush();
    }


    public static void main(String args[]) {
        new Main().solve();
    }
}
