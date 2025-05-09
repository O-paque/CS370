public class ProducerConsumer {
    public static void main(String[] args){

        CircularBuffer circleBuffer = new CircularBuffer();
        Thread producer = new Thread(new Producer(circleBuffer));
        Thread consumer = new Thread(new Consumer(circleBuffer));
        
        producer.start();
        consumer.start();

        try {
            producer.join();
            consumer.join();
        }
        catch (InterruptedException e){
            e.printStackTrace();
        }

        System.out.println("Exiting!");
    }
}