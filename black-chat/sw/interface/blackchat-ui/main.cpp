#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <SerialStream.h>

using namespace std;
using namespace LibSerial;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    char next_char[100];

    SerialStream mySerialStream;

    mySerialStream.Open( "/dev/ttyUSB0" );
    mySerialStream.SetBaudRate(SerialStreamBuf::BAUD_9600);
    mySerialStream.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
    mySerialStream.SetParity(SerialStreamBuf::PARITY_NONE);
    mySerialStream.SetNumOfStopBits(1);
    mySerialStream.SetFlowControl(SerialStreamBuf::FLOW_CONTROL_NONE);

    mySerialStream.SetVTime(1);
    mySerialStream.SetVMin(100);

    usleep(10000);

    mySerialStream << "new line signifies command" << endl;
    mySerialStream.read(next_char, 100);

    cout << next_char;

    mySerialStream.Close();

    return a.exec();
}
