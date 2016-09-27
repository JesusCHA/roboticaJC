#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(stop, SIGNAL(clicked()), this, SLOT(stopButton()) );
	connect(start, SIGNAL(clicked()), this, SLOT(startButton()) );
	connect(horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(barra()));
	
	temporizador = new MyQtimer();
	connect(temporizador, SIGNAL(timeout()),this, SLOT(tiempo()));
	
}

void ejemplo1::stopButton()
{
	temporizador->stop();
	qDebug() << "stop";
}

void ejemplo1::startButton()
{
	
	temporizador->start(1000-horizontalSlider->value());
	qDebug() << "start";
}

void ejemplo1::tiempo()
{
	lcdNumber->display(lcdNumber->value()+1);
}

void ejemplo1::barra()
{
	temporizador->start(1000-horizontalSlider->value());
}

ejemplo1::~ejemplo1()
{
	delete temporizador;
	temporizador = NULL;
}



