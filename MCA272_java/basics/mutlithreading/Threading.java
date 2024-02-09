public class Threading extends Thread {
    @Override
    public void run() {
        for(int i=0; i<4; i++) {
            Thread.sleep(1000);
            printf("%d", i+1);
        }
    }
}
