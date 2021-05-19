#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
//hello
using namespace std;
//Member class
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
  int m_group;
};

void Member::signup()
{
  cout << "User name: " << endl;
  cin >> name;
  cout << "User student number: " << endl;
  cin >> student_number;
  cout << "Chose your study group [Put number ex) 1 -> Gruop A, Maximum is 5]:" << endl;
  cin >> study_group;
  cout << "welcome " << name << endl;
}

int Member::login() const
{
  return student_number;
}
char Member::check_sg() const
{
  char group_name[100];
  switch (study_group)
  {
  case 1:
    strncpy(group_name, "Group A", sizeof("Group A"));
    break;
  case 2:
    strncpy(group_name, "Gruop B", sizeof("Gruop B"));
    break;
  case 3:
    strncpy(group_name, "Group C", sizeof("Group C"));
    break;
  case 4:
    strncpy(group_name, "Group D", sizeof("Group D"));
    break;
  case 5:
    strncpy(group_name, "Group E", sizeof("Group E"));
    break;
  }
  cout << "\nYour study goup name: " << group_name;
}

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
  int m_sg;
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
  //cout << ;
  //cout << "\nYour group assginment: "<< assginment;
}
void assignment::regist_new()
{
  cout << "\ntEnter your study group assignment: " << endl;
  cin >> assginment;
}

void new_account();
void log_in(int n);
void display_sg(int n);
void display_as(int n);
void regist_new();
void modify_as(int n);
void delete_rd(int n);
void delete_as(int n);

int main()
{

  int i_sg;
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
    cout << "\n\n\t6.Delete Member record(with login)";
    cout << "\n\n\t7.Delete assignment record(with login)";
    cout << "\n\n\t8.Exit";
    cout << "\n\nChoice what you need (1/2/3/4/5/6/7/8)";
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
      log_in(num);
      display_sg(num);
      break;
    case '3':
      cout << "\n\n\tLog in: (press your student number)";
      cin >> num;
      log_in(num);
      display_as(num);
      break;
    case '4':
      cout << "\n\n\tLog in: (press your student number)";
      cin >> num;
      log_in(num);
      regist_new();
      break;
    case '5':
      cout << "\n\n\tLog in: (press your student number)";
      cin >> num;
      log_in(num);
      modify_as(num);
      break;
    case '6':
      cout << "\n\n\tLog in: (press your student number)";
      cin >> num;
      log_in(num);
      delete_rd(num);
      break;
    case '7':
      cout << "\n\n\tLog in: (press your student number)";
      cin >> num;
      log_in(num);
      delete_as(num);
      break;
    case '8':
      cout << "Exiting, have a good day";
      exit(0);
    }
  } while (ch != '8');
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
void log_in(int n)
{
  Member mem;
  assignment hw;
  ifstream ifile;
  ifile.open("Member.dat", ios::binary);
  if (!ifile)
  {
    cout << "File could not be opened... Press any key to exit" << endl;
    cin.ignore();
    cin.get();
    return;
  }
  while (ifile.read(reinterpret_cast<char *>(&mem), sizeof(Member)))
  {
    if (n == mem.login())
    {
      cout << "Welcome " << mem.m_group << endl;
      hw.m_sg = mem.check_sg();
      break;
    }
    else if (n != mem.login())
    {
      cout << "You press wrong number or not registed number try again \n"
           << endl;
      break;
    }
  }
}

//check study group
void display_sg(int n)
{
  Member mem;
  ifstream iFile;
  iFile.open("Member.dat", ios::binary);
  if (!iFile)
  {
    cout << "File could not be opened ... Press any key to exit" << endl;
    cin.ignore();
    cin.get();
    return;
  }
  bool flag = false;
  while (iFile.read(reinterpret_cast<char *>(&mem), sizeof(Member)))
  {
    if (n == mem.login())
    {
      //mem.show_sg();
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
void display_as(int n)
{
  Member mem;
  ifstream iFile;
  iFile.open("assignment.dat", ios::binary);
  if (!iFile)
  {
    cout << "File could not be open...press any key to exit" << endl;
    cin.ignore();
    cin.get();
    return;
  }
  bool flag = false;
  while (iFile.read(reinterpret_cast<char *>(&mem), sizeof(Member)))
  {
    if (n == mem.login())
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
  switch (hw.m_sg)
  {
  case 1:
    oFile.open("Group_A.dat", ios::binary | ios::app);
    hw.regist_new();
    oFile.write(reinterpret_cast<char *>(&mem), sizeof(Member));
    oFile.close();
    break;
  case 2:
    oFile.open("Group_B.dat", ios::binary | ios::app);
    hw.regist_new();
    oFile.write(reinterpret_cast<char *>(&mem), sizeof(Member));
    oFile.close();
    break;
  case 3:
    oFile.open("Group_C.dat", ios::binary | ios::app);
    hw.regist_new();
    oFile.write(reinterpret_cast<char *>(&mem), sizeof(Member));
    oFile.close();
    break;
  case 4:
    oFile.open("Group_D.dat", ios::binary | ios::app);
    hw.regist_new();
    oFile.write(reinterpret_cast<char *>(&mem), sizeof(Member));
    oFile.close();
    break;
  case 5:
    oFile.open("Group_E.dat", ios::binary | ios::app);
    hw.regist_new();
    oFile.write(reinterpret_cast<char *>(&mem), sizeof(Member));
    oFile.close();
    break;
  default:
    cout << "\n\nAssignment is registed successfully" << endl;
    cin.ignore();
    cin.get();
    break;
  }
}
//modify registed assignment
void modify_as(int n)
{
  Member mem;
  assignment hw;
  bool found = false;
  fstream f1;
  switch (hw.m_sg)
  {
  case 1:
    f1.open("Group_A.dat", ios::binary | ios::app);
    break;
  case 2:
    f1.open("Group_B", ios::binary | ios::app);
    break;
  case 3:
    f1.open("Group_C", ios::binary | ios::app);
    break;
  case 4:
    f1.open("Group_D", ios::binary | ios::app);
    break;
  case 5:
    f1.open("Group_E", ios::binary | ios::app);
    break;
  }
  if (!f1)
  {
    cout << "File could not be opened. Press any key to exit..." << endl;
    cin.ignore();
    cin.get();
    return;
  }
  while (!f1.eof() && found == false)
  {
    f1.read(reinterpret_cast<char *>(&hw), sizeof(assignment));
    if (mem.login() == n)
    {
      display_as(n);
      cout << "\n\nEnter new assginment details: " << endl;
      hw.regist_new();
    }
  }
}
//delete student data
void delete_rd(int n)
{
  Member mem;
  ifstream iFile;
  iFile.open("Member.dat", ios::binary);
  if (!iFile)
  {
    cout << "File could not be opened... Press any Key to exit..." << endl;
    cin.ignore();
    cin.get();
    return;
  }
  ofstream oFile;
  oFile.open("Temp.dat", ios::out);
  iFile.seekg(0, ios::beg);
  while (iFile.read(reinterpret_cast<char *>(&mem), sizeof(Member)))
  {
    if (mem.login() != n)
    {
      oFile.write(reinterpret_cast<char *>(&mem), sizeof(Member));
    }
  }
  oFile.close();
  iFile.close();
  remove("Member.dat");
  rename("Temp_mem.dat", "Member.dat");
  cout << "\n\n\tRecord Deleted ..";
  cin.ignore();
  cin.get();
}
//delete assginment data
void delete_as(int n)
{
  ifstream iFile;
  assignment hw;

  ofstream oFile;
  oFile.open("Temp_as.dat", ios::out);
  iFile.seekg(0, ios::beg);
  while (iFile.read(reinterpret_cast<char *>(&hw), sizeof(assignment)))
  {
    if (hw.m_sg != n)
    {
      oFile.write(reinterpret_cast<char *>(&hw), sizeof(assignment));
    }
    switch (hw.m_sg)
    {
    case 1:
      iFile.open("Group_A.dat", ios::binary);
      oFile.close();
      iFile.close();
      remove("Group A.dat");
      rename("Temp_as.dat", "Gruop_A.dat");
      break;
    case 2:
      iFile.open("Group_B.dat", ios::binary);
      oFile.close();
      iFile.close();
      remove("Group B.dat");
      rename("Temp_as.dat", "Gruop_B.dat");
      break;
    case 3:
      iFile.open("Group_C.dat", ios::binary);
      oFile.close();
      iFile.close();
      remove("Group_C.dat");
      rename("Temp_as.dat", "Gruop_C.dat");
      break;
    case 4:
      iFile.open("Group_D.dat", ios::binary);
      oFile.close();
      iFile.close();
      remove("Group_D.dat");
      rename("Temp_as.dat", "Gruop_D.dat");
      break;
    case 5:
      iFile.open("Group_E.dat", ios::binary);
      oFile.close();
      iFile.close();
      remove("Group_E.dat");
      rename("Temp_as.dat", "Gruop_E.dat");
      break;
    }
    cout << "\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
  }
}
