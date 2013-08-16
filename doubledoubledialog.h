/*!
 * @file doubledoubledialog.h
 * @author Juan ASCENCIO
 * @version 1.0
 * @date Juillet 2013
 * @copyright INSA LYON
 * Creation date 2013-08-12T00:45:30
 */



#ifndef DOUBLEDOUBLEDIALOG_H
#define DOUBLEDOUBLEDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QDoubleSpinBox>

class DoubleDoubleDialog : public QDialog {
    Q_OBJECT
public:
    explicit DoubleDoubleDialog(QWidget *parent = 0, const QString& title = QString(""), const QString& label1 = QString(""), const double& value1 = 0, const double& minValue1 = 0, const double& maxValue1 = 0, const int& sp1 = 0, const QString& label2 = QString(""), const double& value2 = 0, const double& minValue2 = 0, const double& maxValue2 = 0, const int& sp2 = 0);
    void run (double& val1, double& val2, bool& ok);
    ~DoubleDoubleDialog();

private:
    QFormLayout* layout;
    QDoubleSpinBox* spin1;
    QDoubleSpinBox* spin2;
    QDialogButtonBox* buttonBox;

signals:

public slots:

};

#endif // DOUBLEDOUBLEDIALOG_H
