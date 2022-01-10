import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Head {
//	private static int[] arr;
//	private static int numThreads;
//	private static int n;
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int nodeNum = 4;
		int min = 10;
		int  max = 100;
		int[] arr = new int[max-min];
		for(int i = 0; i<max-min; i++) {
			arr[i] = i+min;
		}
		try {
			ServerSocket ss = new ServerSocket(7000);
			Socket[] sock = new Socket[nodeNum];
			while(true) {
				for(int i = 0; i<nodeNum; i++) {
					System.out.println("Waiting for a call");
					sock[i] = ss.accept(); // Blocking
					System.out.println("Accepted");
				}
				int numThreads = 4;
				int n = max - min;
				int[] cnt = new int[numThreads];
				Thread[] ths = new Thread[numThreads];
				for(int i = 0; i<numThreads; i++) {
					ObjectInputStream ois = new ObjectInputStream(sock[i].getInputStream());
					ObjectOutputStream oos = new ObjectOutputStream(sock[i].getOutputStream());
					int start = (n/numThreads) * i + min;
					int stop = (n/numThreads) * (i+1) + min;
					if(n%numThreads != 0 && i == (numThreads-1)) {
						stop += n%numThreads;
					}

					Lab06Thread va = new Lab06Thread(i ,start, stop, arr, cnt, ois, oos);
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
				System.out.println("Total Count: "+out);
				
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
//		catch (ClassNotFoundException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
	}
}
