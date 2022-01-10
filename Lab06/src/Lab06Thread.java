import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Lab06Thread implements Runnable{
	private int tnum;
	private int start;
	private int stop;
	private int[] arr;
	private int[] cnt;
	private ObjectInputStream ois;// = new ObjectInputStream(sock[i].getInputStream());
	private ObjectOutputStream oos;// = new ObjectOutputStream(sock[i].getOutputStream());
	public Lab06Thread(int i, int start, int stop, int[] a, int[] c, ObjectInputStream ois, ObjectOutputStream oos) {
		tnum = i;
		this.start = start;
		this.stop = stop;
		arr = a;
		this.cnt = c;
		this.ois = ois;
		this.oos = oos;
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
//		System.out.println("in thread: "+tnum+" ("+start+", "+stop+")");
//		int cnt = 0;
//		for(int i = start; i<stop;i++) {
//			if(isPrime(arr[i])) {
//				cnt[tnum]++;
//			}
//		}
		try {
			oos.writeObject(start);
			oos.writeObject(stop);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
//		oos.writeObject(arr);
		
		try {
			cnt[tnum] = (int) ois.readObject();
		} catch (ClassNotFoundException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
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
