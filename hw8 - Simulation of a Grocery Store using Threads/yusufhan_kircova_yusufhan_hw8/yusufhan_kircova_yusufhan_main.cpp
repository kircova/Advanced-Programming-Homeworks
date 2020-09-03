#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <time.h>
#include <random>
#include"HW8DynIntQueue.h"
using namespace std;
//Hope this much globals are not "too" much :)
HW8DynIntQueue queue;
int totalNumberCustomers, threshold;
int arrivalTimeMin, arrivalTimeMax;
int checkoutTimeMin, checkoutTimeMax;
int queueSize = 0;
mutex myMutex, coutMutex;
int remainingCustomers;
int random_range(const int & min, const int & max) 
{ 
	static mt19937 generator(time(0)); 
	uniform_int_distribution<int> distribution(min, max); 
	return distribution(generator); 
}
void Cashier(int cashID)//Cashier function for both cashiers
{
	this_thread::sleep_for(chrono::seconds(random_range(checkoutTimeMin,checkoutTimeMax)));
	if(cashID == 1)//If statements this part is used to utilize the cashier 1 
	{
		while (remainingCustomers > 0 )//If there is a customer cashier 1 continues to work
		{
			myMutex.lock();//locks the mutex
			if(!queue.isEmpty())//Until the queue is empty
			{
				int customerID;
				queue.dequeue(customerID);
				remainingCustomers--;//Total number of customers as decreased

				myMutex.unlock();

				coutMutex.lock();
				time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
				struct tm *ptm = new struct tm;
				localtime_s(ptm, &tt);
				queueSize--;//Decremetning the queue size
				cout << "Cashier 1 started transaction with customer "<< customerID <<" (queue size is "<< queueSize << "):" << put_time(ptm,"%X") << endl;
				coutMutex.unlock();

				this_thread::sleep_for(chrono::seconds(random_range(checkoutTimeMin,checkoutTimeMax)));

				coutMutex.lock();
				tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
				localtime_s(ptm, &tt); 
				cout<< "Cashier 1 finished transaction with customer "<< customerID << " " << put_time(ptm,"%X") <<endl;
				coutMutex.unlock();
			}
			else
			{
				myMutex.unlock();
			}
		}
	}
	else//Cashier 2 work flow
	{
		while(remainingCustomers > 0)//Loop for the second cashier
		{
			myMutex.lock();
			if (threshold <= queue.getCurrentSize() && !queue.isEmpty())//If the thresh hold is smaller than the queue size cashier starts to work
			{	
				int customerID;
				queue.dequeue(customerID);

				remainingCustomers--;
				myMutex.unlock();

				coutMutex.lock();
				time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
				struct tm *ptm = new struct tm;
				localtime_s(ptm, &tt);
				queueSize--;//Decreases the queue size
				cout << "Cashier 2 started transaction with customer "<< customerID <<" (queue size is "<< queueSize << "):" << put_time(ptm,"%X") << endl;
				coutMutex.unlock();

				this_thread::sleep_for(chrono::seconds(random_range(checkoutTimeMin,checkoutTimeMax)));

				coutMutex.lock();
				tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
				localtime_s(ptm, &tt); 
				cout<< "Cashier 2 finished transaction with customer "<< customerID << " " << put_time(ptm,"%X") <<endl;
				coutMutex.unlock();
			}
			else
			{
				myMutex.unlock();
			}
		}
	}
}
void Customer()//Customer function
{
	for (int i = 1; i < totalNumberCustomers + 1; i++)//This loop goes on until every customer enters the queue
	{
		myMutex.lock();
		if(queueSize < totalNumberCustomers + 1)
		{
			int rnd = random_range(arrivalTimeMin,arrivalTimeMax);//wait time for each customer is calculated
			queue.enqueue(i);

			myMutex.unlock();

			coutMutex.lock();
			time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
			struct tm *ptm = new struct tm;
			localtime_s(ptm, &tt); 
			queueSize ++;
			cout << "New customer with ID " << i << " has arrived (queue size is "<< queueSize << "):" << put_time(ptm,"%X") << endl;
			coutMutex.unlock();
			this_thread::sleep_for(chrono::seconds(rnd));
		}
		else
		{
			myMutex.unlock();
			i--;
		}
	}
}
int main() 
{
	cout << "Please enter the total number of customers:";
	cin >> totalNumberCustomers;
	cout <<"Please enter the number of customers waiting in the queue to open the second cashier:";
	cin >> threshold;
	cout << "Please enter the inter-arrival time range between two customers:"<< endl;
	cout << "Min: "; 
	cin >> arrivalTimeMin;
	cout << "Max: ";
	cin >> arrivalTimeMax;
	cout << "Please enter the checkout time range of cashiers:"<< endl;
	cout << "Min: ";
	cin >> checkoutTimeMin;
	cout << "Max: ";
	cin >> checkoutTimeMax;

	remainingCustomers = totalNumberCustomers;//I used this variable as a iterator

	time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
	struct tm *ptm = new struct tm; 
	localtime_s(ptm, &tt); 
	cout << "Simulation starts at " << put_time(ptm,"%X") << endl;

	thread thr0(Customer);
	thread thr1(Cashier,1);
	thread thr2(Cashier,2);

	thr0.join();
	thr1.join();
	thr2.join();

	time_t tr = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
	struct tm *ptr = new struct tm; 
	localtime_s(ptr, &tr); 
	cout<< "End of the simulation ends: "<< put_time(ptr,"%X") <<endl;
	return 0;
}

