
public class Lab04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//System.out.println(isPrime(11));
		int n = 90;
		int numThreads = 4;
		
		int[] arr = new int[n];
		for(int i = 0; i<n; i++) {
			arr[i] = i+10;
		}
		
		
		int[] cnt = new int[numThreads];
		Thread[] ths = new Thread[numThreads];
		for(int i = 0; i<numThreads; i++) {
			int start = (n/numThreads) * i;
			int stop = (n/numThreads) * (i+1);
			if(n%numThreads != 0 && i == (numThreads-1)) {
				stop += n%numThreads;
			}
			Lab04Thread va = new Lab04Thread(i ,start, stop, arr, cnt);
			Thread th = new Thread(va);
			ths[i] = th;
			th.start(); //fork
			
		}
		for(int i = 0; i<numThreads; i++) {
			try {
				ths[i].join();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		int out = 0;
		for(int i = 0; i<numThreads; i++) {
			out += cnt[i];
		}
		System.out.println(out);
		
//		long s = System.currentTimeMillis();
//		System.out.println(manyPrimes(arr));
//		long f = System.currentTimeMillis();
//		long time = f-s;
//		System.out.println(s+", "+f);
	}
	public static boolean isPrime(int n) {
		boolean b = true;
		double i = 2.0;
		while(i<n && b == true) {
			if(n%i == 0) {
				b = false;
			}
			i++;
		}
		return b;
	}
	public static int manyPrimes(int[] arr) {
		int cnt = 0;
		for(int i = 0; i<arr.length;i++) {
			if(isPrime(arr[i])) {
				cnt++;
			}
		}
		return cnt;
	}
}
