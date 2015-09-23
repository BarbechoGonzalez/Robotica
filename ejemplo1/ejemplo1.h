#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"
#include "myqtimer.h"

class ejemplo1 : public QWidget, public Ui_Counter
{
Q_OBJECT

public:
    ejemplo1();
    virtual ~ejemplo1();
    
public slots:
	void doButtonStop();
	void doButtonStart();
	void doIncrease();
private:
  MyQTimer clk;
  QMutex contol;
  
};
 

#endif // ejemplo1_H
