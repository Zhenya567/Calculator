#include "iviewmodel.h"

void IViewModel::onNumberSelected::response(){
    MainWindow m;
   // m.getsender();
    QPushButton *button=(QPushButton *) m.getsender();
        if(button->text()=="+" || button->text()=="-" || button->text()=="/" || button->text()=="*"){
            second=(button->text().toDouble());
        }
        else if(!(button->text()=="+" || button->text()=="-" || button->text()=="/" || button->text()=="*")){
            first=(button->text().toDouble());
        }
}
void IViewModel::onOperationSelected::response(){
    MainWindow m;
    QPushButton *button=(QPushButton *) m.getsender();
        if(button->text()=="+"){
            operations=(button->text());
        }
        else if(button->text()=="-"){
            operations=(button->text());
        }
        else if(button->text()=="/"){
            operations=(button->text());
        }
        else if(button->text()=="*"){
            operations=(button->text());
        }
}
void IViewModel::onEqSelected::response(){
    MainWindow m;
   // m.getsender();
    QPushButton *button=(QPushButton *) m.getsender();
        if(button->text()=="="){
            if(operations=="+"){
          first=first+second;
        }
            if(operations=="-"){
           first=first-second;
        }
            if(operations=="/"){
          first=first/second;
        }
                if(operations=="*"){
                    first=first+second;}
}
}
void IViewModel::setDelegate(IViewModelDelegate* delegate){
    this->delegate=delegate;
}
