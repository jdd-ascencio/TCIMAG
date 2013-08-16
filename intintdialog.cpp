/*!
 * @file intintdialog.cpp
 * @author Juan ASCENCIO
 * @version 1.0
 * @date Juillet 2013
 * @copyright INSA LYON
 * Creation date 2013-08-12T00:45:30
 */



#include "intintdialog.h"

IntIntDialog::IntIntDialog(QWidget *parent, const QString& title, const QString& label1, const int& value1, const int& minValue1, const int& maxValue1, const int& sp1, const QString& label2, const int& value2, const int& minValue2, const int& maxValue2, const int& sp2) : QDialog(parent) {
    spin1 = new QSpinBox(this);
    spin1->setMinimum(minValue1);
    spin1->setMaximum(maxValue1);
    spin1->setSingleStep(sp1);
    spin1->setValue(value1);

    spin2 = new QSpinBox(this);
    spin2->setMinimum(minValue2);
    spin2->setMaximum(maxValue2);
    spin2->setSingleStep(sp2);
    spin2->setValue(value2);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    layout = new QFormLayout(this);
    layout->addRow(new QLabel(label1, this), this->spin1);
    layout->addRow(new QLabel(label2, this), this->spin2);
    layout->addRow(buttonBox);

    this->setWindowFlags(Qt::Dialog | Qt::WindowTitleHint);
    this->setWindowTitle(title);
    this->setModal(true);
    this->setFixedSize(layout->totalMinimumSize());
}

IntIntDialog::~IntIntDialog() {
    delete spin1;
    delete spin2;
    delete buttonBox;
    delete layout;
}

void IntIntDialog::run(int& val1, int& val2, bool& ok) {
    if (this->exec() == QDialog::Accepted) {
        val1 = spin1->value();
        val2 = spin2->value();
        ok = true;
    } else {
        ok = false;
    }
}

