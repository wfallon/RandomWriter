#include <iostream>
#include <string>

#include<fstream>


using namespace std;

string readFile(string textID)
{
    ifstream loadFile;
    srand(time(0));
    
    loadFile.open (textID, ifstream::in);
    
    string str = "";
    while (loadFile.good())
    {
        str = str + (char) loadFile.get();
        
    }
    str = str.substr(0, str.length() - 1);
    loadFile.close();
    return str;
}

void run(int seedlength, string textID, int characterlength)
{
    string str = readFile(textID);
    
    //finds random position
    int initPos = rand() % ((str.length()-seedlength)/2);
    initPos = initPos + (str.length()-seedlength)/4;
    
    string output = "";
    
    int currentPos = initPos;
    
    string current_str = str.substr(initPos, seedlength);
    
    
    for (int a = 0; a <characterlength; a++)
    {
        int occurances [128];
        
        int findPos = 0;
        
        while (str.find (current_str,findPos)!= -1)
        {
            int index = str.find (current_str,findPos);
            findPos = index + 1;
            char hold = str.at(findPos + seedlength -1);
            occurances [((int) hold)] ++;
        }
        
        int max = -1;
        int holder = 0;
        
        for(int i = 0; i < (sizeof(occurances)/sizeof(*occurances)); i++)
        {
            if(occurances[i] > max)
            {
                max = occurances[i];
                holder = i;
            }
        }
        output += (char) holder;
        currentPos++;
        current_str = str.substr(currentPos, seedlength);
        
        
        for(int i = 0; i < (sizeof(occurances)/sizeof(*occurances)); i++)
        {
            occurances[i] = 0;
        }
    }
    
    cout << output << endl;
}


int getSeedLength()
{
    int seedlength;
    cout << "Please enter a seed length: ";
    cin >> seedlength;
    
    if (seedlength > 100)
    {
        cout<<"\nLol less than 100 pls. We will use 8."<< endl;
        seedlength = 8;
        
    }
    
    while(seedlength == 1)
    {
        cout<<"Please enter a seed length that is not 1: ";
        cin >> seedlength;

    }
    return seedlength;
}

string getStory ()
{
    cout <<"\n1. The first letter from Mary Shelley's Frankenstein" << endl;
    cout <<"2. Shakespeare's Macbeth" << endl;
    
    cout << "\nPlease select the text you would like me to write from: ";
    int textNumber;
    cin >> textNumber;
    
    string textID = "frankenstein.txt";
    
    
    
    if (textNumber == 1)
    {
        textID = "frankenstein.txt";
    }
    
    if (textNumber == 2)
    {
        textID = "macbeth.txt";
    }
    return textID;
}

int getCharacterLength ()
{
    cout <<"\nHow many characters would you like me to write? Enter: ";
    int characterlength;
    cin >> characterlength;
    return characterlength;
}

int main()
{
    cout <<"Hello! Welcome to my randomwriter. Enjoy!\n" << endl;
    
    int seedlength = getSeedLength();
    
    string textID = getStory();
    
    int characterlength = getCharacterLength();
    cout <<""<< endl;
    
    run(seedlength, textID, characterlength);
    
}


    
  