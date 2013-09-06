#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream in(argv[1], ifstream::in);
    if(!in.good()){
        cout << "Error opening file " << argv[1] << endl;
        exit(1);
    }
    ofstream output;
    output.open("tickets.txt");
    vector<int> ticketTotals(5,0);
    vector<int> ticketSales(5,0);
    char ch;
    int n;
    int cat;
    int sum=0;
    while(true) {
        in>>ch;
        if(ch<'A'||ch>'E'){
            if(ch=='S')
                break;
            cout<<"Improperly formatted input file"<<endl;
            in.close();
            output.close();
            exit(1);
        }
        in>>n;
        if(n<0) {
            cout<<"Improperly formatted input file"<<endl;
            in.close();
            output.close();
            exit(1);
        }
        while(in.get() != '\n');
        cat=(int)(ch-'A');
        ticketTotals[cat]+= n;
        ticketSales[cat]+= n*(cat==0?2:(cat==1?3:(cat==2?5:(cat==3?20:10))));
    }
    in.close();//No need to access input file anymore
    for(int i=0;i<5;i++)
        sum+=ticketSales[i];
    cout<<"writing file"<<endl;
    output<<"Summary of ticket sales"<<endl;
    output<<left<<setw(20)<<"Student"     <<right<<setw(5)<<ticketTotals[0]<<"    $"<<right<<setw(5)<<ticketSales[0]<<".00"<<endl;
    output<<left<<setw(20)<<"Faulty/Staff"<<right<<setw(5)<<ticketTotals[1]<<"    $"<<right<<setw(5)<<ticketSales[1]<<".00"<<endl;
    output<<left<<setw(20)<<"Alumni"      <<right<<setw(5)<<ticketTotals[2]<<"    $"<<right<<setw(5)<<ticketSales[2]<<".00"<<endl;
    output<<left<<setw(20)<<"UCLA people" <<right<<setw(5)<<ticketTotals[3]<<"    $"<<right<<setw(5)<<ticketSales[3]<<".00"<<endl;
    output<<left<<setw(20)<<"Others"      <<right<<setw(5)<<ticketTotals[4]<<"    $"<<right<<setw(5)<<ticketSales[4]<<".00"<<endl;
    output<<left<<setw(20)<<"Total"       <<"     "                        <<"    $"<<right<<setw(5)<<sum           <<".00"<<endl;
}
