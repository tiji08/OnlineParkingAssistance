

#include "graph.h"
#include "qstack.h"
#include "trie.h"
#include <boost/date_time/posix_time/posix_time.hpp>
/*
Endd application:
Using graph.c/graph.h
*/
int start_tcp_server(void);


int main()
{
    //1) Creating accounts//
    int id = init_trietree();
    if (id == -1) {
        printf("Not able to create tree\n");
        return -1;
    }

    add_account(id, "kamal");
    add_account(id, "kiran");
    add_account(id, "ricky");
    add_account(id, "rinku");
    add_account(id, "Dhanada");

    display_all_friends (id, "kamal");
    add_friend(id, "kamal", "kiran");
    add_friend(id, "kamal", "kiran");
    add_friend(id, "kamal", "kiran");
    add_friend(id, "kamal", "ricky");
    add_friend(id, "kamal", "rinku");
    add_friend(id, "kamal", "dhana");
    add_friend(id, "kamal", "dhana");

    add_account(id, "vamsi");
    add_friend(id, "vamsi","kamal");
    add_friend(id, "kamal","vamsi");

    suggest_friend(id, "vamsi");


    display_all_friends (id, "kamal");

    int result = start_tcp_server();
    if (result != 0) {
        return -1;
    }
    return 0;
}

