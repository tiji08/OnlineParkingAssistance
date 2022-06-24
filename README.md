REQUIREMENTS:
============
Between driver and server
1) Client: sends request
2) Server: Recieves and Searches for parking place details
3) Server: Allotes slot and  Replies with token (with detials), if it is available.
4) Client: confirms
 
 
Between operator and server
1) Operator: Sends the slots details
2) Server: Creates entry and sneds confirmation
 
Server:
1) Run TCP server
2) 1000 parellel conns (threads)
3) Persistency (file write, read periodically) 
4) Distributed 
 

Written in C++:

#define PARKING_NAME_MAX 100
enum TS_STATUS {
    SUCCESS = 0,
    FAILURE = 1,
    INV_IN = 2,
    SYS_ERR = 3 
}
 
struct st_parking_data {
    char parking_name[PARKING_NAME_MAX];
    int floors; //Number of floors 2
    int slots_per_floor; // slots per floor 100
    int *slots; //Need to allocate dynamically
};
 
TS_STATUS quesry_for_slot(const char *shop_name);
TS_STATUS feed_parking_details(struct st_parking_data *data);
