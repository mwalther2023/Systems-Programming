import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.rmi.UnknownHostException;

public class Node {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			int numThreads = 4;
			//int n = 100000;
//			int min = 10;
//			int  max = 100;
//			int[] arr = new int[max-min];
//			for(int i = 0; i<max-min; i++) {
//				arr[i] = i+min;
//			}
			
			System.out.println("About to call");
			Socket s = new Socket("localhost", 7000);
			System.out.println("Connected");
			
			ObjectOutputStream oos = new ObjectOutputStream(s.getOutputStream());
			ObjectInputStream ois = new ObjectInputStream(s.getInputStream());
			
			int start = (int) ois.readObject();
			int stop = (int) ois.readObject();
			int cnt = 0;
			for(int i = start; i<stop;i++) {
				if(isPrime(i)) {
					cnt++;
				}
			}
			
			System.out.println("Range: ("+start+", "+stop+") | Node Count: "+cnt);
			oos.writeObject(cnt);
			s.close();
		
		}
		catch(UnknownHostException e){
			e.printStackTrace();	
		}
		catch(IOException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
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
}
