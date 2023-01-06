#include <stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include <windows.h>
#include <time.h>
#include <iostream>

using namespace std;
void print( tm *ltm ){
    string now_time="";

    now_time += to_string( 1900 + ltm->tm_year );
    now_time+="ƒÍ";

    now_time += to_string(  1 + ltm->tm_mon );
    now_time+="‘¬";

    now_time += to_string(  ltm->tm_mday );
    now_time+="»’";

    now_time += to_string(  ltm->tm_hour );
    now_time+=":";

    now_time += to_string(  ltm->tm_min );
    now_time+="-";

    now_time += to_string(  ltm->tm_sec );
    now_time +="√Î";

    cout<<now_time<<endl;
}

string format(string temp){
    if( temp.size()==2 ){
        return temp;
    }else{
        return "0"+temp;
    }
}

string copy_file(){
    string cmd="XCOPY E:\\[PC∂À]SCNET(x23.01.01.2)\\Worlds\\World";
    string sentence = "E:\\Backup_datas";
    time_t now = time(0);
    tm *ltm = localtime(&now);

    sentence+="\\"; sentence+=format( to_string( 1 + ltm->tm_mon ) );
    sentence+="\\"; sentence+=format( to_string( ltm->tm_mday ) );
    sentence+="\\"; sentence+=format( to_string( ltm->tm_hour ) );
    sentence+="\\"; sentence+=format( to_string( ltm->tm_min ) );
    sentence+="_"; sentence+=format( to_string( ltm->tm_sec ) );
    sentence+="\\"; sentence+="World";

    //cout<<sentence<<endl;
    cmd += " "; cmd += sentence;
    cmd += " "; cmd += "/e/i";
    //cout<<cmd;
    system(cmd.c_str());
    print( ltm );
    return sentence;
}

//delete_datas();

int main( int argc,char argv[] ){

    copy_file();
    int cnt = 0;
    while(1){
        Sleep(1000*60*5);
        copy_file();
    }
    return 0;
}
