import java.util.Random;

public class Producer implements Runnable {
    private final int TOTAL_EXECUTIONS = 1000000;
    private CircularBuffer buffer;
    private Random random;
    private int elementsAdded;
    private double bufferValueCounter;

    Producer(CircularBuffer b){
        random = new Random();
        buffer = b;
        elementsAdded = 0;
        bufferValueCounter = 0;
    }
    /**
     * Adds an element to the FIFO circular buffer that is shared with the Consumer
     */
    public void produce() {
        double element = random.nextDouble() * 100.0;
        buffer.add(element);
        bufferValueCounter += element;
        elementsAdded++;
    }
    /**
     * Prints output to the terminal that matches the assignment example output
     */
    public void total(){
        System.out.println("Producer: Generated " + elementsAdded + " items, Cumulative value of " +
                            "generated items=" + bufferValueCounter);
    }
    /**
     * Allows the Producer to be ran on a separate Thread.
     */
    @Override
    public void run(){
        for (int i = 0; i < TOTAL_EXECUTIONS; i++){
            produce();

            if(elementsAdded % 100000 == 0){
                total();
            }
        }
        System.out.println("Producer: Finished generating 1,000,000 items");
    }
}
