#include "TicketOrder.h"

int TicketOrder::getCat() {
    return cat;
}

int TicketOrder::getNum() {
    return num;
}

TicketOrder::TicketOrder(int n, int c) {
    num= n;
    cat= c;
}

TicketOrder::TicketOrder() {
    
}