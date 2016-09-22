

#include "myqtimer.h"


MyQtimer::
{
	
}

void MyQtimer::start ( int period_ )
{
        period = period_;
        active = true;
        QThread::start();

}

void MyQtimer::stop()
{
        active=false;
}


void MyQtimer::run()
{
        while ( true ) {
                if ( active )
                        emit timeout();
                msleep ( period );
        }
}

MyQtimer::~MyQtimer()
{

}
