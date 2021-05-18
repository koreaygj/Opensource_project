#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
//Member class
char check_sg;
class Member
{
  char name[50];
  int student_number;
  int study_group;

public:
  void signup();
  int login() const;
  char check_sg() const;
  void show_sg() const;
};

void Member::signup()
{
  cout << "User name: " << endl;
  cin >> name;
  cout << "User student number: " << endl;
  cin >> student_number;
  cout << "Chose your study group [Put number ex) 1 -> Gruop A]:" << endl;
  cin >> study_group;
  cout << "welcom " << name << endl;
}

int Member::login() const
{
  return student_number;
}
char Member::check_sg() const
{
  char group_name;
  switch (study_group)
  {
  case 1:
    strcat(group_name, "Group A");
    break;
  }
}
void new_account();
void log_in();
void display_sg();
void display_as();
void regist_new();
void modify_as();
void delete_rd();

void Member::show_sg() const
{
  cout << "\n Your study group: " << study_group;
}

//assignment class
class assignment
{
  int study_group;
  char assginment[50];

public:
  void signup();
  void check_sg();
  void regist_new();
  void display_as();
  void modify();
};
void assignment::signup()
{
  cout << "\nEnter your study group again (to authorize): " << endl;
  cin >> study_group;
}
void assignment::check_sg()
{
}
void assignment::display_as()
{
  cout << "\n"
}
void assignment::regist_new()
{
  cout << "\ntEnter your study group assignment: " << endl;
  cin >> assginment;
}

int main()
{

  char ch;
  cout << setprecision(2);
  do
  {
    int num;

    system("cls");
    cout << "\n\n\n\tMENU";
    cout << "\n\n\t1.Creat new account";
    cout << "\n\n\t2.Cheak study group";
    cout << "\n\n\t3.Check all assginment";
    cout << "\n\n\t4.regist new assignment(with login)";
    cout << "\n\n\t5.Modify assignment record(with login)";
    cout << "\n\n\t6.Delet assginment record(with login)";
    cout << "\n\n\t7.Exit";
    cout << "\n\nChoice what you need (1/2/3/4/5/6/7)";
    cin >> ch;
    system("cls");
    switch (ch)
    {
    case '1':
      new_account();
      break;
    case '2':
      cout << "\n\n\tLog in: (press your student number)";
      cin >> num;
      log_in();
      display_sg();
      break;
    case '3':
      cout << "\n\n\tLog in: (press your student number)";
      cin >> num;
      log_in();
      display_as();
      break;
    case '4':
      cout << "\n\n\tLog in: (press your student number)";
      cin >> num;
      log_in();
      regist_new();
      break;
    case '5':
      cout << "\n\n\tLog in: (press your student number)";
      cin >> num;
      log_in();
      modify_as();
      break;
    case '6':
      cout << "\n\n\tLog in: (press your student number)";
      cin >> num;
      log_in();
      delete_rd();
      break;
    case '7':
      cout << "Exiting, have a good day";
      cout << endl;
      exit(0);
    }
  } while (ch != '6');
  return 0;
}

void new_account()
{
  Member mem;
  assignment hw;
  ofstream ofile;
  ofile.open("Member.dat", ios::binary | ios::app);
  mem.signup();
  hw.signup();
  ofile.write(reinterpret_cast<char *>(&mem), sizeof(Member));
  ofile.close();
  cout << "\n\nCompletly make new account";
  cin.ignore();
  cin.get();
}
void log_in(int num, char check_sg)
{
  Member mem;
  ifstream ifile;
  ifile.open("Member.dat", ios::binary);
  while (ifile.read(reinterpret_cast<char *>(&mem), sizeof(Member)))
  {
    if (num == mem.login())
    {
      cout << "Welcome " << endl;
      check_sg = mem.check_sg();
      break;
    }
    else if (num != mem.login())
    {
      cout << "You press wrong number or not registed number try again \n(if you want to stop this press 9)" << endl;
    }
  }
}

//check study group
void display_sg(int num)
{
  Member mem;
  ifstream iFile;
  iFile.open("Member.dat", ios::binary);
  if (!iFile)
  {
    cout << "File could not be opened ... Press any key to exit";
    cin.ignore();
    cin.get();
    return;
  }
  bool flag = false;
  while (iFile.read(reinterpret_cast<char *>(&mem), sizeof(Member)))
  {
    if (num == mem.login())
    {
      mem.show_sg();
      flag = true;
    }
  }
  iFile.close();
  if (flag == false)
    cout << "\n\nrecord does not exist";
  cin.ignore();
  cin.get();
}
//check assignment
void display_as(int num, char check_sg)
{
  Member mem;
  ifstream iFile;
  iFile.open("assignment.dat", ios::binary);
  if (!iFile)
  {
    cout << "File could not be open...press any key to exit";
    cin.ignore();
    cin.get();
    return;
  }
  bool flag = false;
  while (iFile.read(reinterpret_cast<char *>(&mem), sizeof(Member)))
  {
    if (num == mem.login())
    {
      cout << "\n Your study group: " << mem.check_sg();
      flag = true;
    }
  }
  iFile.close();
  if (flag == false)
    cout << "\n\nrecord dose not exist";
  cin.ignore();
  cin.get();
}

//regist the new assignment
void regist_new()
{
  Member mem;
  assignment hw;
  ofstream oFile;
  oFile.open("check_sg.dat", ios::binary | ios::app);

  hw.regist_new();
  oFile.write(reinterpret_cast<char *>(&mem), sizeof(Member));
  oFile.close();
  cout << "\n\nAssignment is registed successfully";
  cin.ignore();
  cin.get();
}
//modify registed assignment
void modify_as(int num)
{
  Member mem;
  assignment hw;
  bool found = false;
  fstream f1;
  f1.open("assignment.dat", ios::binary, ios::out, ios::in);
  if (!f1)
  {
    cout << "File could not be opened. Press any key to exit...";
    cin.ignore();
    cin.get();
    return;
  }
  while (!f1.eof() && found == false)
  {
    f1.read(reinterpret_cast<char *>(&mem), sizeof(Member));
    if (mem.login() == num)
    {
      hw.display_as();
      cout << "\n\nEnter new assginment details: " << endl;
      hw.regist_new();

      //delete registed assingment
      void
      delete_rd();
