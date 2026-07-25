#include<iostream>
# include<cmath>
# include<string>
using namespace std; 

class clsPerson
{

private:
  string _Name;
  string _Phone;

public:

  clsPerson(string Name,string Phone)//parameterized
  {
    _Name = Name;
    _Phone = Phone;
  }

  void SetName(string Name)
  {
    _Name = Name;
  }

  string GetName()
  {
    return _Name;
  }

  void SetPhone(string Phone)
  {
    _Phone = Phone;
  }

  string GetPhone()
  {
    return _Phone;
  }

};
class clsPassenger :public clsPerson
{
private:
  string _PassportNumber;//encapsulation


public:

  clsPassenger(string PassportNumber,string Name,string Phone)//inithialization list
    :clsPerson(Name,Phone)
  {
    _PassportNumber = PassportNumber;
  }
  

  void SetPassportNumber(string PassportNumber)
  {
    _PassportNumber = PassportNumber;
  }

  string GetPassportNumber()
  {
    return _PassportNumber;
  }



  void PrintPassengerInfo()
  {
    cout << "\nPassenger Information\n";
    cout << "\nFullName:" << GetName();
    cout << "\nPhone" << GetPhone();
    cout << "\nPassport Number" <<GetPassportNumber();
  }

};
class clsFlight
{

private:

  string _From;
  string _To;
  string _Date;
  int _TotalSeats;
  int _ReservedSeats;
  double _Price;

public:
  clsFlight( string From, string To, string Date,double Price,int TotalSeats)
  {
    _From = From;
    _To = To;
    _Date = Date;
    _Price = Price;
    _TotalSeats = TotalSeats;
    _ReservedSeats = 0;
  }

  bool HasAvailableSeats()
  {
    return (_ReservedSeats < _TotalSeats);
  }

  void SetSource(string From)
  {
    _From = From;
  }

  string GetSource()
  {
    return _From;
  }

  void SetDestination(string To)
  {
    _To = To;
  }

  string GetDestination()
  {
    return _To;
  }

  bool ReserveSeat()
  {
    if (HasAvailableSeats())
    {
      _ReservedSeats++;
      return true;
    }

    return false;
  }

  void CancelSeat()
  {
    if (_ReservedSeats > 0)
    {
      _ReservedSeats--;
    }

  }

  void PrintFlightInfo()
  {

    cout << "\nFrom:" << _From << "To:" << _To;
    cout << "\nDate:" << _Date;
    cout << "\nPrice" << _Price;

  }

};

class clsTicket
{

private:

  clsPassenger _Passenger;
  clsFlight _Flight;

  string _SeatNumber;
  string _BookingDate;

public:

  clsTicket(clsPassenger Passenger,clsFlight Flight,string SeatNumber,string BookingDate)
    : _Passenger(Passenger),_Flight(Flight)
  {
    _SeatNumber = SeatNumber;
    _BookingDate = BookingDate;
  }


  void PrintTicket()
  {
    cout << "\n========== Ticket ==========\n";
    cout << "\nPassenger Name: "<< _Passenger.GetName();
    cout << "\nPassport Number: "<< _Passenger.GetPassportNumber();
    cout << "\nFrom: "<< _Flight.GetSource();
    cout << "\nTo: "<< _Flight.GetDestination();
    cout << "\nSeat Number: "<< _SeatNumber;
    cout << "\nBooking Date: "<< _BookingDate;
    cout << "\n============================\n";
  }

};

int main()
{
  clsPassenger Passenger1("A123456", "Yousef", "01201859087");

  clsFlight Flight1("Cairo","Dubai","10/5/2026",3500,100);

  if (Flight1.ReserveSeat())
  {
    clsTicket Ticket1(Passenger1,Flight1,"A5","8/5/2026");

    Ticket1.PrintTicket();
  }
  else
  {
    cout << "\nNo Available Seats\n";
  }


}