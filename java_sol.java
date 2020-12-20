import java.io.*;
import java.util.*;

public class Main {
	static final Reader in = new Reader();
	static final PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		int t=in.nextInt();
//		int t=1;
		for(int i=1; i<=t; ++i)
			new Solver();
		out.close();
	}
	
	static class Solver {
		Solver() {
			int n=in.nextInt();
			int[] a = new int[n+1];
			Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
			for(int i=0; i<n; ++i) {
				a[i]=in.nextInt();
				mp.put(a[i], mp.getOrDefault(a[i], 0)+1);
			}
			int mn=Integer.MAX_VALUE;
			for(Map.Entry<Integer, Integer> entry : mp.entrySet())
				mn=Math.min(mn, entry.getValue());
			if(mn>1)
				out.println(-1);
			else {
				int id=0, prev=Integer.MAX_VALUE;
				for(int i=0; i<n; ++i)
					if(mp.get(a[i])==mn&&a[i]<prev) {
						id=i+1;
						prev=a[i];
					}
				out.println(id);
			}
		}
	}
	
	static class Reader {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String next() {
			while(st==null||!st.hasMoreTokens()) {
				try {
					st=new StringTokenizer(in.readLine());
				} catch(Exception e) {}
			}	
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
	
}
