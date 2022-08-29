REQUIREMENTS:
============
Between driver and server
=========================
1) Client: sends subscription request
2) Server: Recieves and Searches for topic and confirms
3) Server: Allotes slot and  Replies with token (with detials), if it is available.
4) Client: confirms
 
 
Between operator and server:
============================
1) Operator: Sends the slots details
2) Server: Creates entry and sneds confirmation
 
Server Requirements:
====================
1) Runs TCP server, reads sub/pub and topic
2) 1 million parellel connections (0.1 million publishers/ 0.9 million subscribers)
3) Should publish the data to all subscribers
4) Scalable with load balancer
 
Dpendencies:
============
1) Need to have c++ compiler c++11
2) Install boot library "sudo apt-get install libboost-all-dev"

Coding requirements:
===================
1) Written in C++, using standard libraries (vectors, maps)
2) Using boost library (io,socket)

