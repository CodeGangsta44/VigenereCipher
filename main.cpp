#include<iostream>

using namespace std;

string get_second_string(int len_of_mess, string ky){
   int len_of_key = ky.length();
   string sec_str;
   for (int counter = 0; counter < (len_of_mess/len_of_key); counter++){
     for(int i = 0; i < len_of_key; i++){
       sec_str.push_back(ky[i]);
     }
   }
   for (int i = 0; i < (len_of_mess % len_of_key); i++){
     sec_str.push_back(ky[i]);
   }
   return sec_str;
}

string get_encrypted_message(string first, string second){
  string result;
  for (int i = 0; i < first.length(); i++){
    if ((int)first[i] == 32) first[i] = '{';
    int new_index = (int)first[i] + ((int)second[i] - 97);
    if (new_index == 123) result.push_back((char) 32);
    else if (new_index <= 122) result.push_back((char)new_index);
    else result.push_back((char)(new_index - 27));
  }
  return result;
}

string get_decrypted_message(string first, string second){
  string result;
  for (int i = 0; i < first.length(); i++){
    int old_index = (int)first[i] - ((int)second[i] - 97);
    if (old_index == 96) result.push_back(' ');
    else if (old_index >= 97) result.push_back((char)old_index);
    else result.push_back((char)(old_index + 27));
  }
  return result;
}

void create_matrix(){
  char matrix[27][27];
  for (int i = 0; i < 27; i++){
    for (int j = 0; j < 27; j++){
      int new_index = i + j;
      if (new_index >= 27) new_index = new_index - 27;
      new_index = new_index + 97;
      if (new_index == 123) new_index = 32;
      matrix[i][j] = (char)(new_index);
    }
  }
  for (int i = 0; i < 27; i++){
    for (int j = 0; j < 27; j++){
      cout << matrix[i][j] << ' ';
    }
    cout << endl;
  }
}

int main(){
  cout<<"What do you want to do?"<<endl;
  cout<<"1 - create cyphered message"<<endl;
  cout<<"2 - create decyphered message"<<endl;
  char *answer = new (char);
  cin.getline(answer, 2);
  cout<<"Enter the message: ";
  char *mess = new (char);
  char *key = new (char);
  cin.getline(mess, 256);
  cout<<"Enter the key: ";
  cin.getline(key, 256);
  create_matrix();
  string double_str[2];
  double_str[0] = mess;
  int len = double_str[0].length();
  double_str[1] = get_second_string(len, key);
  cout<<"\n"<<double_str[0]<<endl<<double_str[1]<<endl<<"\n";
  delete mess, key;
  if (*answer == '1'){
    delete answer;
    string cyphered = get_encrypted_message(double_str[0], double_str[1]);
    cout<<"Your cyphered message is: "<<cyphered<<endl;
  }
  if (*answer == '2'){
    delete answer;
    string decyphered = get_decrypted_message(double_str[0], double_str[1]);
    cout<<"Your decyphered message is: "<<decyphered<<endl;
  }
}
