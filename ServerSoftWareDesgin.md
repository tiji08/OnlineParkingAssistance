Design Decisions for server
----------------------------

1. Thread pools : To span out the havy traffic accross cores, thread pools will help in catering to resource needs of the subscriber. 
    -> Max 10 threads
    -> Internal Message queues - Max 20 per thread

2. Conditional thread variables to wake up the threads when the event arrives
3. Distribution of work : Would require an algorithm to distribute the work without hogging thread resources and thread memory. Consistent hashing could be a solution
4. Need to handle failures : A response would be sent to subscriber if there is any failure in processing and also grace shutdown and clean up on interruption.
5. Need a rate limiter like leaky bucket or tocken bucket to limit the havy taffic of requests. It will also elp in dealing with DDOS attacks.
6. TCP stream socket for communication between publisher and subscribers. It should be a non-blocking socket.
7. Prevent data races and deadlock : Use of mutex or spinlocks for common resources accross threads
