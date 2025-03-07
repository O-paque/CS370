package HW4;

public class Consumer implements Runnable {
    private final int TOTAL_EXECUTIONS = 10000;
    private CircularBuffer buffer;
    private int elementsReceived;
    private double totalValue;

    Consumer(CircularBuffer b) {
        buffer = b;
        elementsReceived = 0;
        totalValue = 0;
    }

    public void consume() {
        double element = buffer.get();
        totalValue += element;
        elementsReceived++;
    }

    public void total(){
        System.out.println("Consumer: Consumed " + elementsReceived + " items, Cumulative value " +
                            "of consumed items=" + totalValue);
    }

    public void run(){
        for (int i = 0; i < TOTAL_EXECUTIONS; i++){
            consume();

            if(elementsReceived % 100 == 0){
                total();
            }
        }
    }
}
