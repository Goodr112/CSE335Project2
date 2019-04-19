#ifndef RESPONSIVEBUTTON_H
#define RESPONSIVEBUTTON_H

#include <QObject>
#include <QPushButton>

class ResponsiveButton : public QPushButton
{
    Q_OBJECT
public:
    ResponsiveButton(QWidget* qw):QPushButton(qw){}

signals:
    void iChanged(QObject*);

public slots:
    void myStateChanged();
};

#endif // RESPONSIVEBUTTON_H
