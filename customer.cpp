/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   customer.cpp
 * Author: R1711773
 * 
 * Created on April 22, 2019, 2:27 AM
 */


#include <iostream>
#include<fstream>
#include<cstring>
#include "customer.h"
using namespace std;


       
       Customer::Customer(char * f,char* l, char* a,char *c,char *p,int receiptNo) {
        customerReceiptNo=receiptNo;
         strcpy(paymentStatus,p);
        strcpy(fname, f);
        strcpy(lname, l);
        strcpy(add, a);
        strcpy(cn, c);
    }
       void Customer::GetCustomerDetails() {
        cout<<"\n";
        cout << " Customer    name  is       :" <<fname<<"  "<<lname<< endl;
        cout << "Customer home  address   is  :    "<<add<<endl;
        cout << "Customer contact number is :  ..."<<cn<< endl;
         cout <<" Customer   receipt Number   ...." <<customerReceiptNo<<endl;
        cout << "Payment status    :    "<<paymentStatus<<endl;

}

void GetRecordDetails() {
    char opt;
    char ch;

    char fname[20],lname[20];
        char add[25];
        char cn[20];
     int customerReceiptNo;
        char paymentStatus[10];
    
do {

          cout<<"Enter  customer  name :    ";
            cin.getline(fname,20);
             cout<<"Enter  customer  Surname :    ";
            cin.getline(lname,20);
          cout<<"Enter contact no. of the customer :    ";
            cin.getline(cn,20);

            cout<<"Enter customer receipt no.  :   ";
            cin>>customerReceiptNo;


        Customer customer(fname,lname,add,cn,paymentStatus,customerReceiptNo);
        WriteToFile(customer);


        cout << "Another record <y-yes n-no>" << endl;
        opt = getchar();
        cin.ignore();

    } while (opt != 'n');


}
void WriteToFile(Customer customer) {

    ofstream outFile("customer", ios::app | ios::binary);
    outFile.write((char*) &customer, sizeof (customer));
    outFile.flush();

    if (outFile)
        cout << "\nRecord saved successfully" << endl;
    else
        cout << "Error saving file" << endl;

    outFile.close();

}

void ReadFromFile(streamsize position);

void ReadRecordPosition() {
    streamsize position;
    cout << "Enter the record number to retrieve...";
    cin>>position;
    ReadFromFile(position);
}

void ReadFromFile(streamsize position) {
    Customer customer;

    ifstream inFile("customer", ios::in | ios::binary);

    inFile.seekg(sizeof (customer)*(position - 1), ios::beg);
    inFile.read((char *) &customer, sizeof (customer));
    customer.GetCustomerDetails();
}