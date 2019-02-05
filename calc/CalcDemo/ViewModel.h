#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include <QObject>
#include <QSharedPointer>
#include <QStringList>
#include "Calculator.h"

class ViewModel: public QObject
{
    Q_OBJECT

private:
    class State {
    public:
        State(ViewModel* parent);
        virtual ~State();
        virtual void onNumberSelected(QString numberChar) = 0;
        virtual void onOperationSelected(QString operationChar) = 0;
        virtual void onEqSelected() = 0;
        virtual void clear()=0;
        virtual void plus_minus()=0;
        virtual void percent()=0;
        virtual void dot()=0;
        virtual void backspace()=0;
        virtual QString formatLabel() = 0;

        ViewModel *parent() const;
        typedef QSharedPointer <State> Ptr;

    private:
        ViewModel* m_parent;
    };

public:
    explicit ViewModel(QObject* parent = nullptr);
    virtual ~ViewModel();

    Q_INVOKABLE void onNumberSelected(QString numberChar);
    Q_INVOKABLE void onOperationSelected(QString operationChar);
    Q_INVOKABLE void onEqSelected();
     Q_INVOKABLE void clear();
   Q_INVOKABLE void plus_minus();
    Q_INVOKABLE void percent();
    Q_INVOKABLE void dot();
    Q_INVOKABLE void backspace();
    State::Ptr state() const;
    void setState(const State::Ptr &state);

    Calculator &calculator();
    void sendUpdateLabel(QString label);

    Q_INVOKABLE QStringList operations();
signals:
    void updateLabel(QString labelText);

private:
    State::Ptr m_state;
    Calculator m_calculator;



    class InputFirstNumberState: public State
    {
    public:
        InputFirstNumberState(ViewModel* parent);
        void onNumberSelected(QString numberChar);
        void onOperationSelected(QString operationChar);
        void onEqSelected();
        void clear();
        void plus_minus();
        void percent();
        void dot();
        void backspace();
        QString formatLabel();

    private:
        QString m_firstValueBuffer;
        QString oper;

    };

    class InputSecondNumberState: public State
    {
    public:
        InputSecondNumberState(ViewModel* parent);
        void onNumberSelected(QString numberChar);
        void onOperationSelected(QString operationChar);
        void onEqSelected();
        void clear();
        void plus_minus();
        void percent();
        void dot();
        void backspace();

        QString formatLabel();
    private:
        QString m_secondValueBuffer;
        QString oper1;

    };

    class PrintResultState: public State
    {
    public:
        PrintResultState(ViewModel* parent);
        void onNumberSelected(QString numberChar);
        void onOperationSelected(QString operationChar);
        void onEqSelected();
        void clear();
        void plus_minus();
        void percent();
        void dot();
        void backspace();
        QString formatLabel();
    };
};

#endif // VIEWMODEL_H
