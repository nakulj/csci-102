#include <iostream>
#include <vector>
#include <iomanip>
#include "TicketOrder.h"
#include "BadInput.h"

using namespace std;

int main() {
    cin.exceptions(iostream::failbit);
    vector<int> ticketTotals(5,0);
    vector<int> ticketSales(5,0);
    vector<TicketOrder> orders;
    TicketOrder temp;
    char ch;
    int n;
    int cat;
    int sum=0;
    cout<<"Categories:"<<endl;
    cout<<left<<setw(40)<<"A. Students without an activity card"<<"$"<<right<<setw(2)<<"2"<<endl;
    cout<<left<<setw(40)<<"B. Faculty and staff"                <<"$"<<right<<setw(2)<<"3"<<endl;
    cout<<left<<setw(40)<<"C. USC alumni"                       <<"$"<<right<<setw(2)<<"5"<<endl;
    cout<<left<<setw(40)<<"D. UCLA students and alumni"         <<"$"<<right<<setw(2)<<"20"<<endl;
    cout<<left<<setw(40)<<"E. Everyone else"                    <<"$"<<right<<setw(2)<<"10"<<endl;
    while(true) {
        cout<<"Enter the ticket category, or enter S to finish and process totals."<<endl;
        try {
            cin>>ch;
            if((ch<'A'||ch>'E') && ch!='S')
                throw BadInput(ch);
        }
        catch(ios::failure &ex) {
            cerr<<"Invalid input, please try again"<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        catch(BadInput &ex) {
            cerr<<ex.what()<<endl<<"Please try again"<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if(ch=='S') {
            cout<<"All transactions processed"<<endl;
            break;
        }
        cout<<"Enter the number of "<<ch<<" tickets to be purchased"<<endl;
        try {
            cin>>n;
            if(n<0) {
                throw BadInput(n);
            }
        }
        catch(ios::failure &ex) {
            cerr<<"Invalid input, please try again"<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        catch(BadInput &ex) {
            cerr<<ex.what()<<endl<<"Please try again"<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cat=(int)(ch-'A');
        temp= TicketOrder(n, cat);
        orders.push_back(temp);
        ticketTotals[cat]+= n;
        ticketSales[cat]+= n*(cat==0?2:(cat==1?3:(cat==2?5:(cat==3?20:10))));
        cout<<"----"<<endl;
    }
    for(int i=0;i<5;i++)
        sum+=ticketSales[i];
    cout<<"Summary of ticket sales"<<endl;
    cout<<left<<setw(20)<<"Student"     <<right<<setw(5)<<ticketTotals[0]<<"    $"<<right<<setw(5)<<ticketSales[0]<<".00"<<endl;
    cout<<left<<setw(20)<<"Faulty/Staff"<<right<<setw(5)<<ticketTotals[1]<<"    $"<<right<<setw(5)<<ticketSales[1]<<".00"<<endl;
    cout<<left<<setw(20)<<"Alumni"      <<right<<setw(5)<<ticketTotals[2]<<"    $"<<right<<setw(5)<<ticketSales[2]<<".00"<<endl;
    cout<<left<<setw(20)<<"UCLA people" <<right<<setw(5)<<ticketTotals[3]<<"    $"<<right<<setw(5)<<ticketSales[3]<<".00"<<endl;
    cout<<left<<setw(20)<<"Others"      <<right<<setw(5)<<ticketTotals[4]<<"    $"<<right<<setw(5)<<ticketSales[4]<<".00"<<endl;
    cout<<left<<setw(20)<<"Total"       <<"     "                        <<"    $"<<right<<setw(5)<<sum           <<".00"<<endl;
}