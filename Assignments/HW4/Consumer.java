package HW4;

public class Consumer implements Runnable {
    private final int TOTAL_EXECUTIONS = 1000000;
    private CircularBuffer buffer;
    private int elementsReceived;
    private double totalValue;

    Consumer(CircularBuffer b) {
        buffer = b;
        elementsReceived = 0;
        totalValue = 0;
    }
    /**
     * Gets an element from the FIFO circular buffer that is shared with the Producer
     */
    public void consume() {
        double element = buffer.get();
        totalValue += element;
        elementsReceived++;
    }
    /**
     * Prints output to the terminal that matches the assignment example output
     */
    public void total(){
        System.out.println("Consumer: Consumed " + elementsReceived + " items, Cumulative value " +
                            "of consumed items=" + totalValue);
    }
    /**
     * Allows the Consumer to be ran on a separate Thread.
     */
    public void run(){
        for (int i = 0; i < TOTAL_EXECUTIONS; i++){
            consume();

            if(elementsReceived % 100000 == 0){
                total();
            }
        }
    }
}
