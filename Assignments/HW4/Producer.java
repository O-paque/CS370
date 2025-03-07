package HW4;

import java.util.Random;

public class Producer implements Runnable {
    private final int TOTAL_EXECUTIONS = 10000;
    private CircularBuffer buffer;
    private Random random;
    private int elementsAdded;
    private double totalValue;

    Producer(CircularBuffer b){
        random = new Random();
        buffer = b;
        elementsAdded = 0;
        totalValue = 0;
    }
    public void produce() {
        double element =random.nextDouble() * 100;
        buffer.add(element);
        totalValue += element;
        elementsAdded++;
    }
    
    public void total(){
        System.out.println("Producer: Generated " + elementsAdded + " items, Cumulative value of " +
                            "generated items=" + totalValue);
    }

    public void run(){
        for (int i = 0; i < TOTAL_EXECUTIONS; i++){
            produce();

            if(elementsAdded % 100 == 0){
                total();
            }
        }
    }
}
