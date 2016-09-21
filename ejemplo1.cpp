#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(boton, SIGNAL(clicked()), this, SLOT(doButton()) );
	
	temporizador= new QTimer(this);
	connect(temporizador, SIGNAL(timeout()),this, SLOT(tiempo()));
	temporizador->start();
	
}

ejemplo1::~ejemplo1()
{}

void ejemplo1::doButton()
{
	qDebug() << "click on button";
}

void ejemplo1::tiempo()
{
	lcdNumber->display(lcdNumber->value()+1);
}





