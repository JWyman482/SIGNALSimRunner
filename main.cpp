#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Functions:
readIn
*/

bool readIn(const string& path, string& file)
// temp will not be emptied; may stack on file.
{
  string temp = "";
  ifstream input(path);
  if (!input.is_open())
  {
    cout << "Unable to open " << path << endl;
    return false;
  }
  while (getline(input, temp)) 
    file += temp + "\n";
  //cout << file;
  input.close();
  return true;
}

bool attribChange(string& file, const string& attrib, const string& change)
{
  size_t len = 0;
  if (attrib == "/e:") len = 1;
  if (attrib == "/h:") len = 12;

  size_t pos = file.find(attrib);
  if (pos != string::npos) file.replace(pos + attrib.length(), len, change);
  else
  {
    cout << "Attribute data not found.\n";
    return false;
  }
  //cout << file;
  return true;
}

bool sendOut(const string& path, const string& file)
{
  ofstream output(path);
  if (!output.is_open())
  {
    cout << "Unable to open/create text.txt\n";
    return false;
  }
  output << file;
  output.close();
  return true;
}


int main(int argc, char* argv[])
{
  //int args = argc;
  string file, answer1, answer2, attrib, path2;
  string exercise = "1";
  string server = "10.54.220.92";
  //string path = "C:/Signal/";
  string path = "Basic.ini";
  path2 = path;


  while(argc > 1)
  {
    //**************** First command-line Argument = Display
    string temp = argv[1];
    if (temp == "BASIC") path = "Basic.ini";
    else if (temp == "PILOT") path = "Pilot.ini";
    else if (temp == "ARTS") { path = "DEDEM.ini"; path2 = "CommonArts.ini"; }
    //else if (temp == "STARS") {path = "fslthing.ini"; path2 = "starsthing.ini";}

    //**************** Second command-line Argument = Exercise
    if (argv[2] != nullptr) exercise = argv[2];
    else break;

    //**************** Third command-line Argument = Charter Location
    if (argv[3] != nullptr)
    {
      temp = argv[3];
      if (temp == "1") server = "10.54.220.92";
      else if (temp == "2") server = "10.54.220.95";
      else if (temp == "3") server = "10.54.220.99";
      else if (temp == "4") server = "10.54.220.93";
      else if (temp == "5") server = "localhost   ";
    }
    else break;
    break;
  }

  if (!readIn(path, file)) return 1;
  if (!attribChange(file, "/e:", exercise)) return 1;
  if (!attribChange(file, "/h:", server)) return 1; 
  if (!sendOut(path, file)) return 1;
}