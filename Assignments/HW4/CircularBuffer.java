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
     * @throws Exception If the buffer is full, an exception is thrown.
     */
    public synchronized void add(double d) {
        while (isFull()) {
            notify();
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
    }

    public synchronized double get() {
        while(isEmpty()){
            notify();
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
        return buffer[index];
    }

    public int getSize(){
        return entries;
    }

    public boolean isFull(){
        return entries >= buffer.length;
    }

    public boolean isEmpty(){
        return entries == 0;
    }

    @Override
    public String toString(){
        return "Total entries in buffer: " + entries;
    }

}
