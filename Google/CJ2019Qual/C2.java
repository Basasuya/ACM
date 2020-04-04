import java.io.*;
import java.util.*;
import java.math.*;


public class Solution {
    Scanner in = new Scanner(new BufferedInputStream(System.in));
    PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    BigInteger seq[] = new BigInteger[105];
    BigInteger prime[] = new BigInteger[105];
    //    BigInteger num[] = new BigInteger[105];
    int lower_bound(BigInteger[] nums, int begin, int end, BigInteger value) {
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid].compareTo(value) == -1) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        return begin;
    }
    void solve() {
        int casNum;
        casNum = in.nextInt();
        for(int cas = 1; cas <= casNum; ++cas) {
            BigInteger n;
            int l;
            n = in.nextBigInteger(); l = in.nextInt();
            for(int i = 0; i < l; ++i) {
                seq[i] = in.nextBigInteger();
            }

            int pos = -1;
            for(int i = 1; i < l; ++i) {
                if(seq[i].equals(seq[i-1]) == false) {
                    prime[i] = seq[i].gcd(seq[i-1]);
                    pos = i;
                    break;
                }
            }

            for(int i = pos - 1; i >= 0; --i) {
                prime[i] = seq[i].divide(prime[i + 1]);
            }
            for(int i = pos + 1; i <= l; ++i) {
                prime[i] = seq[i-1].divide(prime[i-1]);
            }

            List<BigInteger> num=new ArrayList<>();
            for(int i = 0; i <= l; ++i) {
                num.add(prime[i]);
            }
            Set<BigInteger> uniqueGas = new HashSet<BigInteger>(num);
//            out.println(uniqueGas.size());
//            for(BigInteger i : uniqueGas) {
//                out.println(i);
//            }
            BigInteger[] result = uniqueGas.toArray(new BigInteger[0]);
            Arrays.sort(result, 0, uniqueGas.size());
            assert(uniqueGas.size() == 26);
            // printf("%d\n", (int)num.size());
            // for(int i = 0, len = num.size(); i < len; ++i) printf("%lld ", num[i]); printf("\n");
            out.printf("Case #%d: ", cas);

            for(int i = 0; i <= l; ++i) {
                int tt = lower_bound(result,0, uniqueGas.size(), prime[i]);
                out.printf("%c", tt + 'A');
            }
            out.printf("\n");
        }
        out.flush();
    }
    public static void main(String args[]) {
        new Solution ().solve();

    }
}