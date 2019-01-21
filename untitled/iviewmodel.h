#ifndef IVIEWMODEL_H
#define IVIEWMODEL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QString>
#include "iviewmodelstate.h"
//#include "iviewmodeldelegate.h"
class IViewModelDelegate;
class IViewModel:public QMainWindow
{
 struct State
        {
            virtual void response() = 0;
        };
 struct onNumberSelected:public State{ void response();};
 struct onOperationSelected:public State{void response();};
 struct onEqSelected:public State {void response();};

 State *state;
 static double first,second;
 static QString operations;
 IViewModelDelegate* delegate;
public:
 IViewModel() : state(new onNumberSelected()) {}
    virtual ~IViewModel(){}
 void Number(){
  return state->response();
 }
 void Operations(){
   delete state;
   state=new onOperationSelected;
 }
void Calculator(){
 delete state;
 state=new onEqSelected;
}
virtual void setDelegate(IViewModelDelegate* delegate) = 0;

};

#endif // IVIEWMODEL_H
