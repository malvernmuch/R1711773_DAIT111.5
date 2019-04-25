/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   customer.h
 * Author: R1711773
 *
 * Created on April 22, 2019, 2:27 AM
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include<fstream>
#include<cstring>
#include "customer.h"

using namespace std;



class Customer
{
        int customerReceiptNo;
        char fname[20];
        char lname[20];
        char add[25];
        char cn[20];
        char paymentStatus[20];


    public:
        Customer(){};
        Customer(char * f,char* l, char* a,char *c,char *p,int receiptNo);
         void GetCustomerDetails();
};
void WriteToFile(Customer customer);

void WriteToFile(Customer customer); 
void ReadFromFile(streamsize position);

void ReadRecordPosition(); 

void ReadFromFile(streamsize position);

#endif /* CUSTOMER_H */

