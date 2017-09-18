#include<string>
#include<fstream>
using namespace std;

void appendAtAtAt(string file) {
    ofstream outputFile;
    outputFile.open(file,  std::ios_base::app);
    outputFile<<"\n@@@";
    outputFile.close();
}
bool checkFileExists(string file) {
    ifstream inputFile;
    inputFile.open(file);
    bool result=false;
    if(inputFile)
        result=true;
    inputFile.close();
    return result;
}
