
public class Lab04Thread implements Runnable{
	private int tnum;
	private int start;
	private int stop;
	private int[] arr;
	private int[] cnt;
	public Lab04Thread(int i, int start, int stop, int[] a, int[] c) {
		tnum = i;
		this.start = start;
		this.stop = stop;
		arr = a;
		this.cnt = c;
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
//		System.out.println("in thread: "+tnum+" ("+start+", "+stop+")");
//		int cnt = 0;
		for(int i = start; i<stop;i++) {
			if(isPrime(arr[i])) {
				cnt[tnum]++;
			}
		}
		System.out.println("in thread: "+tnum+" ("+start+", "+stop+"): "+cnt[tnum]);
	}
	public boolean isPrime(int n) {
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

}
