/* 
 * File:   TicketOrder.h
 * Author: Nakul
 *
 * Created on February 2, 2011, 12:49 PM
 */

#ifndef TICKETORDER_H
#define	TICKETORDER_H

class TicketOrder {
private:
    int num,
        cat;
public:
    int getNum();
    int getCat();
    TicketOrder(int n, int c);
    TicketOrder();
};


#endif	/* TICKETORDER_H */

