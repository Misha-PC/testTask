#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool find(string str, string partStr){ /* поиск подстроки в строке*/
    int progress = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == partStr[progress])
            progress++;
        else
            progress = 0;
        if(progress == partStr.length())
            return true;
    }
    return false;
}

bool isEnter(char x){ /* для читабильности */
    return (int)x == 13? true : false;
}

int main(int argc, char *argv[]){
    ifstream log("src/log.txt"); 
    log.unsetf(ios_base::skipws); /* не скрывать пробелы и переносы строк */
    
    if(!log){
        cout << "file open error!" << endl;
        return 1;
    }

    char    symbol;

    string  currentString, 
            reference;

    reference = "C4 01 C1";

    if(argc > 1){
        reference = "";
        for(int i = 1; i < argc; i++){
            reference += argv[i];
            reference += + i != argc -1? " " : "";
        }
    }
    else reference = "C4 01 C1";


    // cout << "reference : " << reference << endl;
 

    while(log){   
        log  >>  symbol;
        if(isEnter(symbol)){
            if(find(currentString, reference))
                cout << currentString;
            currentString = "";
        }
        else{
            currentString += symbol;
        }
    }
    cout << endl;
}