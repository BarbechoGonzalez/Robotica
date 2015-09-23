#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(button_stop, SIGNAL(clicked()), this, SLOT(doButtonStop()));
	connect(button_start, SIGNAL(clicked()), this, SLOT(doButtonStart()));
	connect(&clk, SIGNAL(senal()), this, SLOT(doIncrease()));
	connect(slider, SIGNAL(sliderMoved(int)), &clk, SLOT(setseg(int)));
	connect(slider, SIGNAL(sliderMoved(int)), lcdslider, SLOT(display(int)));
	clk.setseg(slider->value());
	clk.start();
	
}

ejemplo1::~ejemplo1()
{}

void ejemplo1::doButtonStop()
{
  clk.terminate();
}
void ejemplo1::doButtonStart()
{
  clk.start();
}

void ejemplo1::doIncrease()
{
  static int cont=0;  
  lcdNumber->display(cont++);
}






