/*!
 * @file doubleintdialog.h
 * @author Juan ASCENCIO
 * @version 1.0
 * @date Juillet 2013
 * @copyright INSA LYON
 * Creation date 2013-08-12T00:45:30
 */



#ifndef DOUBLEINTDIALOG_H
#define DOUBLEINTDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>

class DoubleIntDialog : public QDialog {
    Q_OBJECT
public:
    explicit DoubleIntDialog(QWidget *parent = 0, const QString& title = QString(""), const QString& label1 = QString(""), const double& value1 = 0, const double& minValue1 = 0, const double& maxValue1 = 0, const int& sp1 = 0, const QString& label2 = QString(""), const int& value2 = 0, const int& minValue2 = 0, const int& maxValue2 = 0, const int& sp2 = 0);
    void run (double& val1, int& val2, bool& ok);
    ~DoubleIntDialog();

private:
    QFormLayout* layout;
    QDoubleSpinBox* spin1;
    QSpinBox* spin2;
    QDialogButtonBox* buttonBox;

signals:
    
public slots:
    
};

#endif // DOUBLEINTDIALOG_H
