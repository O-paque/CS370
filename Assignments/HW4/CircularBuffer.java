package HW4;

public class CircularBuffer {
    private double[] buffer;
    private int head;
    private int tail;
    private int entries;

    CircularBuffer(){
        buffer = new double[1000];
        head = 0;
        tail = -1;
        entries = 0;
    }
    /**
     * Adds a number to the buffer while implementing the circular property.
     * @param d The number to be added to the buffer.
     */
    public synchronized void add(double d) {
        while (entries == buffer.length) {
            try{
                wait();
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        int index = (tail + 1) % buffer.length;
        buffer[index] = d;
        tail++;
        entries++;

        notify();
    }
    /**
     * Gets the oldest entry in the buffer using the current head index to keep the buffer FIFO. 
     * @return 
     */
    public synchronized double get() {
        while(entries == 0){
            try{
                wait();
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        int index = head % buffer.length;

        head++;
        entries--;

        notify();
        return buffer[index];
    }
}
